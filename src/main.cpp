#include "main.h"

int main(int argc, char* argv[])
{
    // ./executale_name [-i] [immunity time] [-p] [population size] [-g] [max group size]
    srand(time(NULL));

    args_t* args = initializeArgs();
    args = parseInput(args, argc, argv);
    
    simulate(args);    

    return 0;
}