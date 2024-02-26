#include "header.h"
#include "1process.h"
#include "sortAlgorithms.h"

void menu(){
  int numProcesses;
  cout << "Enter the number of processes: ";
  cin >> numProcesses;
  //Ask the user for number of processes
  
  //Assign to a vector, the number of processes to be made.
  vector<Process> processList(numProcesses);

  //Ask the user for the arrival time and burst time for each process.
  for (int i = 0; i < numProcesses; ++i) {
      cout << "Enter details for process " << i + 1 << ":" << endl;
      cout << "  Priority: ";
      cin >> processList[i].pid;
      cout << "  Arrival time: ";
      cin >> processList[i].arrivalTime;
      cout << "  Burst time: ";
      cin >> processList[i].burstTime;
  }

  //Ask the user for the scheduling algorithm.
  int numChoice = 0;
  while(numChoice != 3){
  numChoice = 0;
  cout << "Which sorting algorithm would you like to use?" << endl;
  cout << "1.SJF (Non-Preemptive)" << endl;
  cout << "2.SRT (Preemptive)" << endl;
  cout << "3.Quit" << endl;
  cin >> numChoice;
  if(numChoice == 1){
    //Call the SJF function
    cout << "SJF Selected" << endl;
    SJF(processList, numProcesses);
  }
  if(numChoice == 2){
    //Call the SRT function
    cout << "SRT Selected" << endl;
    SRT(processList, numProcesses);
  }

  if(numChoice == 3){
    //Exit Program
    cout << "Quiting" << endl;
  }

  }

}
