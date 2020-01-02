// 2. SJF Non Pre-Emptive 
#include<iostream>
using namespace std;
void sortBurst(int a[], int n)
{
    for (int i = 0; i < n; i++)
        for (int k = i + 1; k < n; k++)
            if (a[i] > a[k]){
                int temp = a[i];
                a[i] = a[k];
                a[k] = temp;
            }
}
int main(){
    int processID[10], burstTime[10], runTime[10] = {0}, n, i;
    float avg = 0, avgw = 0;
    cout << "Total number of processes: ";
    cin >> n;
    cout << "Burst Times for each process: ";
    for(i=0;i<n;i++) cin >> burstTime[i];
    sortBurst(burstTime, n);
    for(i=0;i<n;i++){
        runTime[i+1] = runTime[i] + burstTime[i];
        cout << runTime[i] << "\t\t\t" << runTime[i+1] << endl;
        avg += runTime[i];
        avgw += runTime[i+1];
    }
    cout << "Wait Time \t Turnaround Time"; 
    cout << "\nAverage Waiting Time: " << avg/(float)n << endl;   
    cout << "Average Turn Around Time: " << avgw/(float)n << endl;  
}