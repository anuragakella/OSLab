#include <stdio.h>
void sortBurst(int a[], int n)
{
    int i, k, temp;
    for (i = 0; i < n; i++)
        for (k = i + 1; k < n; k++)
            if (a[i] > a[k]){
                temp = a[i];
                a[i] = a[k];
                a[k] = temp;
            }
}
int main(){
    int processID[10], burstTime[10], runTime[10] = {0}, n, i;
    printf("Total number of processes: ");
    scanf("%d", &n);
    printf("Burst Times for each process: ");
    for (i = 0; i < n; i++) scanf("%d", &burstTime[i]); 
    sortBurst(burstTime, n);
    for (i = 0; i < n; i++){
        runTime[i + 1] = runTime[i] + burstTime[i];
        printf("\n%d \t\t\t %d", runTime[i], runTime[i + 1]);
    }
    printf("\nWait Time \t Turnaround Time");
}