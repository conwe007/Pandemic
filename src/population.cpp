#include "population.h"

// default constructor, begin with 1 infected individual and default population size and max group size
Population::Population()
{
    size_population = SIZE_POPULATION;
    size_group_max = SIZE_GROUP_MAX;

    individuals = (Individual*)malloc(sizeof(Individual) * size_population);

    for(int i = 0; i < size_population; i++)
    {
        individuals[i] = Individual();
    }

    // infect 1 seed individual
    individuals[0].infect();

    num_infected = 1;
    num_immune = 0;
    num_healthy = size_population - 1;

    time = 0;
}

// begin with 1 infected individual and custom population size, max group size, and immunity time
Population::Population(args_t* args)
{
    size_population = args->size_population;
    size_group_max = args->size_group_max;

    individuals = (Individual*)malloc(sizeof(Individual) * size_population);

    for(int i = 1; i < size_population; i++)
    {
        individuals[i] = Individual(args);
    }

    // infect 1 seed individual
    individuals[0].infect();

    size_group_max = size_group_max;

    num_infected = 1;
    num_immune = 0;
    num_healthy = size_population - 1;

    time = 0;
}

// for each individual in population, if infected, increases infection_time by 1
void Population::incrementInfectionTimes()
{
    for(int i = 0; i < size_population; i++)
    {
        individuals[i].incrementInfectionTime();
    }
}

// for each individual in population, if infection_time >= immunity_time, remove infection and become immune
void Population::updateImmunities()
{
    for(int i = 0; i < size_population; i++)
    {
        if(individuals[i].updateImmunity())
        {
            num_immune++;
            num_infected--;
        }
    }
}

// increments time by 1
void Population::incrementTime()
{
    time++;
}

// given random sequence, form groups between 1 and SIZE_GROUP_MAX and spread infection between those groups
void Population::groupInfection()
{
    int* sequence = getRandomSequence();
    int sequence_index = 0;

    int group_size = 0;
    
    // loop through random sequence and select groups of size 1 to SIZE_GROUP_MAX
    while(sequence_index < size_population - 1)
    {
        // if number of available individuals left is < SIZE_GROUP_MAX, form a group of size 1 to SIZE_POPULATION - sequence_index
        if(sequence_index + size_group_max < size_population)
        {
            group_size = (rand() % (size_group_max - 1)) + 1;
        } else
        {
            group_size = (rand() % (size_population - sequence_index - 1)) + 1;
        }

        // if any member of the group is infected, infect the whole group
        for(int i = sequence_index; i < sequence_index + group_size; i++)
        {
            if(individuals[sequence[i]].isInfected())
            {
                for(int j = sequence_index; j < sequence_index + group_size; j++)
                {
                    if(individuals[sequence[j]].infect())
                    {
                        num_infected++;
                        num_healthy--;
                    }
                }

                break;
            }
        }

        sequence_index += group_size;
    }

    free(sequence);
}

// helper function, returns a random sequence of integers from 0 to SIZE_POPULATION
int* Population::getRandomSequence()
{
    int* sequence = (int*)malloc(sizeof(int) * size_population);

    // initialize array with ordered sequence
    for(int i = 0; i < size_population; i++)
    {
        sequence[i] = i;
    }

    int r;
    int temp;

    for(int i = 0; i < size_population; i++)
    {
        r =  i + (rand() % (size_population - i));

        temp = sequence[i];
        sequence[i] = sequence[r];
        sequence[r] = temp;
    }

    return sequence;
}

// return number of individuals who are infected
int Population::numInfected()
{
    return num_infected;
}

// return number of individuals who are immune
int Population::numImmune()
{
    return num_immune;
}

// return number of individuals who are not infected or immune
int Population::numHealthy()
{
    return num_healthy;
}

// writes stats to file specified by filename in the format time,num_infected,num_immune,num_healthy,\n
void Population::writeStatsToFile(args_t* args)
{
    FILE* fp = fopen(args->filename, "a");

    fprintf(fp, "%i,%i,%i,%i,\n", time, num_infected, num_immune, num_healthy);

    fclose(fp);
}

// prints population statistics
void Population::printStats()
{
    printf("time: %i\n", time);
    printf("\tinfected: %i\n", num_infected);
    printf("\timmune: %i\n", num_immune);
    printf("\thealthy: %i\n", num_healthy);
}