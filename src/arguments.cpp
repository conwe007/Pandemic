#include "arguments.h"

// create argument structure and initialize it with default values
args_t* initializeArgs()
{
    args_t* args = (args_t*)malloc(sizeof(args_t));

    args->immunity_time = IMMUNITY_TIME;

    args->size_population = SIZE_POPULATION;
    args->size_group_max = SIZE_GROUP_MAX;

    strcpy(args->filename, FILENAME);

    return args;
}

// parses command line input and populates argument structure
args_t* parseInput(args_t* args, int argc, char* argv[])
{
    // loop through each command line input
    for(int argi = 1; argi < argc; argi++)
    {
        // check for valid flag
		if(strcmp(argv[argi], "-i") && strcmp(argv[argi], "-p") && strcmp(argv[argi], "-g") && strcmp(argv[argi], "-f"))
		{
			fprintf(stderr, "error: incorrect flag: '%s'\n", argv[argi]);
			return NULL;
		}

        // immunity time flag
        if(!strcmp(argv[argi], "-i"))
        {
            args->immunity_time = atoi(argv[argi + 1]);

            if(args->immunity_time < 1)
            {
                fprintf(stderr, "error: incorrect argument for immunity time: %i\n", args->immunity_time);
                return NULL;
            }

            argi++;
        }

        // population size flag
        if(!strcmp(argv[argi], "-p"))
        {
            args->size_population = atoi(argv[argi + 1]);

            if(args->size_population < 1)
            {
                fprintf(stderr, "error: incorrect argument for population size: %i\n", args->size_population);
                return NULL;
            }

            argi++;
        }

        // max group size flag
        if(!strcmp(argv[argi], "-g"))
        {
            args->size_group_max = atoi(argv[argi + 1]);

            // max group size must be at least 2, otherwise no infection would ever spread
            if(args->size_group_max < 2)
            {
                fprintf(stderr, "error: incorrect argument for max group size: %i\n", args->size_group_max);
                return NULL;
            }

            argi++;
        }
    }

    // generate output filename
    snprintf(args->filename, SIZE_FILENAME, "stats_p%i_g%i_i%i.csv", args->size_population, args->size_group_max, args->immunity_time);

    return args;
}
