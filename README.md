<center>  </center>

<p float="left">
  <p align="center"><img src="https://github.com/koifissh/SJF-SRT-Process-Scheduler/assets/112574689/4f75f7a6-f8b0-464b-b40d-c20507337b4a" width="362" />
  <img src="https://github.com/koifissh/SJF-SRT-Process-Scheduler/assets/112574689/0edf0f32-3f0f-4c7b-bcea-2420013bd35c" width="420" /> 
  
</p>

## Shortest Job First (SJF) & Shortest Remaining Time (SRT) Process Scheduler
Author: Daniel Huynh

## Statement
This information can be used to develop, understand, and implement two types of process schedulers (SJF and SRT). It takes arrival time, burst time, and priority as inputs into a user desired amount of process structs meant to imitate an actual process. The scheduler works by keeping track of a running time and determining the next shortest process within the list to execute. The determination is dependent on the rules and logic of the chosen scheduler.

## Usage
To use this program, follow these steps:

1. Ensure that you have the necessary header files and their appropriate cpp file. `header` and `sortAlgoirthm`
2. Run the `main.cpp` file.
3. The program will prompt you with the number of processes you'll want to insert and the individual details of each process.
   -   Priority ID: An arbitration rule that serves as the first tie breaker in the event burstTimes are equal in a preemptive algorithm
   -   Arrival Time: The time a process arrives on the queue
   -   Burst Time: The time a process takes to execute
   - SJF: This option calculates Turn Around Time based on the SJF (Non-Preemptive) method
   - SRT: This option calculates Turn Around Time based on the SRT (Preemptive) method
   - Quit
5. Follow the on-screen instructions and input the required information.
6. The program will provide the stats for each process and the appropriate calculation depending on the selected scheduler
7. Additionally, the program outputs the average turnaroundtime
   
## Additional Details
- The program reads process information from the user

## Limits
- Time limit didn't allow for a potential visual representation expansion via Gant Charts.
