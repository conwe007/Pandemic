#include "individual.h"

// default constructor, sets default immunity time
Individual::Individual()
{
    is_infected = false;
    is_immune = false;
    infection_time = 0;
    immunity_time = IMMUNITY_TIME;
}

// sets custom immunity_time
Individual::Individual(args_t* args)
{
    is_infected = false;
    is_immune = false;
    infection_time = 0;
    immunity_time = args->immunity_time;
}

// if infected, increases infection_time by 1, return infection_time
int Individual::incrementInfectionTime()
{
    if(is_infected)
    {
        infection_time++;
    }
    
    return infection_time;
}

// if infection_time >= immunity_time, remove infection and become immune, return true if individual became immune, false otherwise
bool Individual::updateImmunity()
{
    if((is_immune == false) && (infection_time >= immunity_time))
    {
        is_infected = false;
        is_immune = true;
        infection_time = 0;

        return true;
    }

    return false;
}

// if not infected or immune, infect self, return true if individual was infected, false otherwise
bool Individual::infect()
{
    if(is_infected == false && is_immune == false)
    {
        is_infected = true;
        
        return true;
    }

    return false;
}

// returns is_infected
bool Individual::isInfected()
{
    return is_infected;
}

// returns is_immune
bool Individual::isImmune()
{
    return is_immune;
}