#include<iostream>
using namespace std;
int main(){
    int n, f, ref[30], assign[30], inUse[30] = {0}, ptr = 0, block[30], faults = 0, hit = 0;
    cout << "Enter length of ref. string and no. of frames: ";
    cin >> n >> f;
    cout << "Enter the ref string: ";
    for(int i = 0; i < n; i++) cin >> ref[i];
    for(int i=0;i<f;i++) block[i] = -1;
    for(int i = 0; i < n; i++){
        hit = 0;
        for(int j = 0; j<f;j++){
            if(block[j] == ref[i])
                hit = 1;
        }
        if(hit == 0){
            if(ptr == f) ptr = 0;
            faults++;
            block[ptr] = ref[i];
            ptr++;
        }
    }
    cout << "Faults: " << faults << endl;  
}