#include<iostream>
using namespace std;
void sortBurst(int a[], int indx[], int n)
{
    for (int i = 0; i < n; i++)
        for (int k = i + 1; k < n; k++)
            if (a[i] > a[k]){
                int temp = a[i];
                a[i] = a[k];
                a[k] = temp;
                temp = indx[i];
                indx[i] = indx[k];
                indx[k] = temp;
            }
}
int main(){
    int n, m, blocks[10], prreq[10], bi[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, pi[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, assign[10], inUse[10] = {0}, flg = 0;
    cout << "Enter no of blocks and no. of processes: ";
    cin >> n >> m;
    cout << "Enter block sizes in the memory: ";
    for(int i = 0; i < n; i++) cin >> blocks[i];
    cout << "Enter block sizes for the processes: ";
    for(int i = 0; i < m; i++) { cin >> prreq[i]; assign[i] = -1; }
    sortBurst(blocks, bi, n);
    sortBurst(prreq, pi, m);
    for(int i = 0; i < m; i++){
        if(prreq[i] <= blocks[i]){
            assign[pi[i]] = bi[i];
        } else {
            for(int j = i; j < n; j++){
                if(prreq[i] <= blocks[j] && assign[pi[i]] == -1){
                assign[pi[i]] = bi[j];
                }
            }
        }
    }
    cout << "Process : Block - Assignments: " << endl;
    for(int i = 0; i < m; i++) cout << "P" << i << " : " << "B" << assign[i] << ", ";    
}