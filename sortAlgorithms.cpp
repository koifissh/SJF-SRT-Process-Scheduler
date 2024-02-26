#include "sortAlgorithms.h"

void computeStats(vector<Process>& processList, int sumturnAroundTime){
  //Loop through the process list
  for (int i = 0; i < processList.size(); i++)
    {
      //Output individual process stats
      cout << endl << "P" << i << ": PRIORITY, ARRIVAL, BURST, COMPLETION, TURNAROUND, WAITING" << endl;
      cout <<"\t\t" <<  processList[i].pid<<"\t\t"
        << processList[i].arrivalTime<<"\t\t"
        <<processList[i].burstTime<<"\t\t"
        <<processList[i].completionTime<<"\t\t"
        <<"\t"<<processList[i].turnAroundTime<<"\t\t"
        <<"\t\t"<<processList[i].waitingTime << endl;
    }

  //Output average turn around time
  cout<<"\nAverage Turn Around Time: " 
    << ((float)sumturnAroundTime/processList.size()) << endl;

}


void SRT(vector<Process>& processList, int numProcesses){
  //Keep track of first process in list
  bool isFirstProcess=true;

  //Keep track of the current Time
  int currentTime = 0;
  
  //Count the number of processes completed
  int completed = 0;

  //Keep track of sums
  int sumturnAroundTime=0;
  int sumWaitingTime=0;

  //Keep track of all burst times in the processList
  float burstTimes[numProcesses];

  for(int i = 0; i < numProcesses; i++){
    burstTimes[i]= processList[i].burstTime;
  }
  //Set isCompleted to false
  for(int i = 0; i < numProcesses; i++){
    processList[i].isCompleted = false;
  }

  //Loop until all processes are done executing
  while(completed!=numProcesses){
    //For each process completion, reset the mininum Process and burstTime of the list.
    int minIndex = -1;
    int minimum = INT_MAX;

    //Iterate through the list of processes
    for(int i = 0; i < numProcesses; i++) {
      //If process is not completed and arrival time is less than or equal to current time
      if(processList[i].arrivalTime <= currentTime && processList[i].isCompleted == false) {
        //If burst time is less than the current minimum
        if(burstTimes[i] < minimum) {
          //Update minimum
            minimum = burstTimes[i];
          //Declare the process with minimal burstTime as the minimum
            minIndex = i;
        }
        if(burstTimes[i] == minimum) {
         //Edge Case/Arbitration Rule: If two processes have the same burst time, consider priority first. Then declare the process with the first arrival time as the minimum if priorities are the same
          //Compare priorities
          if(processList[i].pid < processList[minIndex].pid) {
            minimum = burstTimes[i];
            minIndex = i;
          } 
          //If priorities are the same, compare arrival times
          else if(processList[i].pid == processList[minIndex].pid){
            if(processList[i].arrivalTime < processList[minIndex].arrivalTime){
              minimum = burstTimes[i];
              minIndex = i;
            }
          }
          //Compare arrival times
          else if (processList[i].arrivalTime < processList[minIndex].arrivalTime) {
              minimum = burstTimes[i];
              minIndex = i;
          }
              
        }
      }
    }
    //Update the current time if there are no processes to execute
    if(minIndex==-1){
        currentTime++;
    }
    //If there is a process to execute then update the times. 
    else{
      //If burstTime list is equal to the burstTime of the process, set the start time to current time
        if(burstTimes[minIndex] == processList[minIndex].burstTime){
          processList[minIndex].startTime = currentTime;
          isFirstProcess=false;
        }
      
    //Decrement the BurstTime of the process as it is being executed
        burstTimes[minIndex] -= 1;
    //Update the current time as the process is executed
        currentTime++; 
      //If the burst time is 0 which occurs when the process has finished, then record the process completion, turnaround, and waiting. Add those numbers to their appropriate sums and list the process as completed.
        if(burstTimes[minIndex] == 0){
          //Set completion time as the current time
            processList[minIndex].completionTime = currentTime;

          //Set turnaround time: completion time - arrival time
            processList[minIndex].turnAroundTime = processList[minIndex].completionTime - processList[minIndex].arrivalTime;

          //Set Waiting Time: turnaround time - burst time
            processList[minIndex].waitingTime= processList[minIndex].turnAroundTime - processList[minIndex].burstTime;
          
          //Update Sums
            sumturnAroundTime +=processList[minIndex].turnAroundTime;
            sumWaitingTime += processList[minIndex].waitingTime;
          //Iterate to indicate a process has completed
            completed++;
          //Set the process as completed so it does not reiterate through the same process
            processList[minIndex].isCompleted = true;     

        }
    }


  }

  //Output to console
  computeStats(processList, sumturnAroundTime);

}


void SJF(vector<Process>& processList, int numProcesses){
  //Keep track of processes in list
  bool isFirstProcess=true;
  //Keep track of sums
  int sumturnAroundTime=0;
  int sumWaitingTime=0;

  //Keep track of the current Time
  int currentTime = 0;
  
  //Keep track of processList size, and processes completed
  int completed = 0;

  //Set isCompleted to false
  for(int i = 0; i < numProcesses; i++){
    processList[i].isCompleted = false;
  }
  
  while(completed!=numProcesses){
    //For each process completion, reset the mininum Process and burstTime of the list.
    int minIndex = -1;
    int minimum = INT_MAX;

    //Find process with minimum burst time that hasn't been completed
    for(int i = 0; i < numProcesses; i++) {
      //If the arrival time is less than currenttime and the process is not completed, check to update the minimum
      if(processList[i].arrivalTime <= currentTime && processList[i].isCompleted == false) {
        //If the burst time is less than the current minimum, update minimum
        if(processList[i].burstTime < minimum) {
          minimum = processList[i].burstTime;
          minIndex = i;
        }
        //Arbitration Rule: If burstTime of the new process arrived is equal to the minimum, check the arrival time first. Since this is a non preemptive algorithm, arrival time is the priority.
        if(processList[i].burstTime == minimum) {
          //Compare arrival times
          if(processList[i].arrivalTime < processList[minIndex].arrivalTime) {
            //Update minimum/first to be executed
            minimum = processList[i].burstTime;
            minIndex = i;
          }
        }
      }
    }

    //INCREMENT the current time if there are no processes to execute
    if(minIndex==-1){
      currentTime++;
    } 
    //If there is a process to execute then update the times.
    else{
      processList[minIndex].startTime = currentTime;
        
      processList[minIndex].completionTime = 
        processList[minIndex].startTime + processList[minIndex].burstTime;

      processList[minIndex].turnAroundTime = 
        processList[minIndex].completionTime - processList[minIndex].arrivalTime;
        
      processList[minIndex].waitingTime = 
        processList[minIndex].turnAroundTime - processList[minIndex].burstTime;

    //Update Sums
      sumturnAroundTime +=processList[minIndex].turnAroundTime;
      sumWaitingTime += processList[minIndex].waitingTime;

      isFirstProcess = false; 
      //Iterate to indicate a process has completed
      completed++;
      //Set process completion to true to avoid reiterating through the same process
      processList[minIndex].isCompleted = true;
      //Set the current time to the completion time of the process
      currentTime = processList[minIndex].completionTime;
      }

  }

  //Output to console
  computeStats(processList, sumturnAroundTime);

}

