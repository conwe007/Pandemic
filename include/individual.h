#ifndef __INDIVIDUAL_H
#define __INDIVIDUAL_H

#include "arguments.h"
#include "constants.h"

class Individual
{
    private:
        bool is_infected;
        bool is_immune;
        int infection_time; // amount of time individual has been infected
        int immunity_time; // amount of time individual must be infected before becoming immune

    public:
        Individual(); // default constructor
        Individual(args_t* args); // sets custom is_infected

        int incrementInfectionTime(); // if infected, increases infection_time by 1, return infection_time
        bool updateImmunity(); // if infection_time >= immunity_time, remove infection and become immune, return true if individual became immune, false otherwise
        bool infect(); // if not infected or immune, infect self, return true if individual was infected, false otherwise

        bool isInfected(); // returns is_infected
        bool isImmune(); // returns is_immune
};

#endif