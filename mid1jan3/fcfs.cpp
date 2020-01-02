// 1. First Come First Serve (FCFS) 
#include<iostream>
using namespace std;
int main(){
    int processID[10], burstTime[10], runTime[10] = {0}, n, i;
    float avg = 0, avgw = 0;
    cout << "Total number of processes: ";
    cin >> n;
    cout << "Burst Times for each process: ";
    for(i=0;i<n;i++){
        cin >> burstTime[i];
        runTime[i+1] = runTime[i] + burstTime[i];
        cout << runTime[i] << "\t\t\t" << runTime[i+1] << endl;
        avg += runTime[i];
        avgw += runTime[i+1];
    }
    cout << "Wait Time \t Turnaround Time"; 
    cout << "\nAverage Waiting Time: " << avg/(float)n << endl;   
    cout << "Average Turn Around Time: " << avgw/(float)n << endl;   
}