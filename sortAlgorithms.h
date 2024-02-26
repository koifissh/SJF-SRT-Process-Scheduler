#include "library.h"
#include "1process.h"

//Shortest Remaining Time First - Keeps track of two lists, an arrival list and burst time list. As the time increments, the burst time of processes will be decremented. When burst time/time remaining of an active process is equal to the burst time of a process that has just arrived. Priority will be considered first then arrival time.
void SRT(vector<Process>& processList, int numProcesses);

//Shortest Job First - Processes are sorted based on their arrival time an then burst time. The process with the shortest burst time will be executed first and executed until its burst time is 0.
void SJF(vector<Process>& processList, int numProcesses);


