#ifndef __POPULATION_H
#define __POPULATION_H

#include "arguments.h"
#include "constants.h"
#include "individual.h"
#include <cstdio>
#include <cstdlib>

class Population
{
    private:
        Individual* individuals;

        int size_population;
        int size_group_max; // maximum size of groups individuals in a population will form

        int num_infected;
        int num_immune;
        int num_healthy;

        int time;

    public:
        Population(); // default constructor
        Population(args_t* args); // begin with 1 infected individual and custom population size, max group size, and immunity time

        void incrementInfectionTimes(); // for each individual in population, if infected, increases infection_time by 1
        void updateImmunities(); // for each individual in population, if infection_time >= immunity_time, remove infection and become immune
        void incrementTime(); // increments time by 1

        void groupInfection(); // given random sequence, form groups between 1 and SIZE_GROUP_MAX and spread infection between those groups
        int* getRandomSequence(); // helper function, returns a random sequence of integers from 0 to SIZE_POPULATION

        int numInfected(); // return number of individuals who are infected
        int numImmune(); // return number of individuals who are immune
        int numHealthy(); // return number of individuals who are not infected or immune

        void writeStatsToFile(args_t* args); // writes stats to file specified by filename in the format time,num_infected,num_immune,num_healthy\n
        void printStats(); // prints population statistics
};

#endif