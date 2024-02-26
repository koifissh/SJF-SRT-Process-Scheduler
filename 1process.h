#pragma once
struct Process {
    //Initialized by the USER
    int pid;        // Process Priority
    int arrivalTime; // Arrival time
    int burstTime;  // Burst time

    int startTime; // startTime

    //Calculated by the algorithm
    int completionTime;  // Completion Time
    int turnAroundTime;  // Turnaround Time
    int waitingTime; // waiting Time

    //Check to see if process is finished
    bool isCompleted = false;
};



