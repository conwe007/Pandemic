#include "simulation.h"

// simulates infection spread until all individuals are immune
void simulate(args_t* args)
{
    Population p = Population(args);

    // delete existing file named filename
    fopen(args->filename, "w");

    p.writeStatsToFile(args);

    while(p.numInfected() != 0)
    {
        p.groupInfection();
        p.incrementInfectionTimes();
        p.updateImmunities();
        p.incrementTime();
        p.writeStatsToFile(args);
    }
}

