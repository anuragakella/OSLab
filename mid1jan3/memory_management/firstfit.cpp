#include<iostream>
using namespace std;
int main(){
    int n, m, blocks[10], prreq[10], assign[10], inUse[10] = {0}, flg = 0;
    cout << "Enter no of blocks and no. of processes: ";
    cin >> n >> m;
    cout << "Enter block sizes in the memory: ";
    for(int i = 0; i < n; i++) { cin >> blocks[i]; inUse[i] = -1; }
    cout << "Enter block sizes for the processes: ";
    for(int i = 0; i < m; i++) { cin >> prreq[i]; assign[i] = -1; }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(prreq[i] <= blocks[j] && inUse[j] == -1 && assign[i] == -1){
                assign[i] = j;
                inUse[j] = 1;
            }  else continue;
        }
    }
    cout << "Process : Block - Assignments: " << endl;
    for(int i = 0; i < m; i++) cout << "P" << i << " : " << "B" << assign[i] << ", ";    
}