#include<stdio.h>
int main(){
    int processID[10], burstTime[10], runTime[10] = {0}, n, i;
    printf("Total number of processes: ");
    scanf("%d", &n);
    printf("Burst Times for each process: ");
    for(i=0;i<n;i++){
        scanf("%d", &burstTime[i]);
        runTime[i+1] = runTime[i] + burstTime[i];
        printf("\n%d \t\t\t %d", runTime[i], runTime[i+1]);
    }
    printf("\nWait Time \t Turnaround Time");    
}