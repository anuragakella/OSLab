#include<iostream>
using namespace std;
int main(){
    int n, m, blocks[10], prreq[10], assign[10], flg = 0, max = 0, inUse[10];
    cout << "Enter no of blocks and no. of processes: ";
    cin >> n >> m;
    cout << "Enter block sizes in the memory: ";
    for(int i = 0; i < n; i++) { cin >> blocks[i]; inUse[i] = 0;}
    cout << "Enter block sizes for the processes: ";
    for(int i = 0; i < m; i++) { cin >> prreq[i]; assign[i] = -1; }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            max = -1;
            if(prreq[i] <= blocks[j]){
                if((blocks[j] - prreq[i]) > max){
                    if(inUse[j] == 1) continue;
                    else {
                        assign[i] = j;
                        max = blocks[j] - prreq[i];
                    }
                }
            }  else continue;
        }
        inUse[assign[i]] = 1;
    }
    cout << "Process : Block - Assignments: " << endl;
    for(int i = 0; i < m; i++) cout << "P" << i << " : " << "B" << assign[i] << ", ";    
}