# John Conwell

## Pandemic

### Description
This program simulates the spread of a virus through a population. The population is made up of individuals, who each have a status (healthy, infected, or immune). Initially, one individual is infected while the rest are healthy. The simulation takes place over multiple time steps. During each time step, individuals are put into random groups of sizes between 1 and [max group size] (specified at runtime). If a healthy individual is grouped with an infected individual, the healthy individual becomes infected. After a certain amount of time (specified by [immunity time] at runtime), infected individuals become immune, and can no longer become infected or spread infection.
### To Compile
Open a terminal in the same directory as the source code and use the command
```bash
$ make
```
to compile this program. This program compiles on Unix with gcc 7.4.0.
### To Execute
This project allows for multiple different flags to be specified at runtime. All flags are optional. Flags must have both the flag and the argument specified to be valid. The flags are as follows:

-i [immunity time]: The number of time steps it takes for an infected individual to become immune

-p [population size]: The size of the population being simulated

-g [max group size]: The maximum size individuals will be grouped into to spread a virus

### Output
The output of a simulation is a .csv file with the following format:
```
time,infected,immune,healthy
```
where infected, immune, and healthy correspond to the number of individuals in the population who have that status.
