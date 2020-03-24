#ifndef __ARGUMENTS_H
#define __ARGUMENTS_H

#include "constants.h"
#include <cstdlib>
#include <cstdio>
#include <cstring>

// argument structure to determine simulation, population, and individual settings
typedef struct
{
    int immunity_time; // amount of time individual must be infected before becoming immune

    int size_population;
    int size_group_max;

    char filename[SIZE_FILENAME];
} args_t;

args_t* initializeArgs(); // create argument structure and initialize it with default values
args_t* parseInput(args_t* args, int argc, char* argv[]); // parses command line input and populates argument structure

#endif