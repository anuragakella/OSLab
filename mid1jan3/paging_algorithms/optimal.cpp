#include<iostream>
using namespace std;
int replaceNext(int stack[], int slen, int refs[], int curpos, int rlen){
    int recent = -1, max = -1;
    int st2[10];
    for(int i = 0; i < slen; i++){
        for(int j = curpos; j<= rlen; j++){
            if(stack[i] == refs[j]){
                st2[i] = j;
                break;
            }  else st2[i] = 9999;
        }
    }
    for(int i = 0; i<slen;i++){
        if(st2[i] > max){
            max = st2[i];
            recent = i;
        } 
    }   
    return recent;
}
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
            faults++;
            if(block[ptr] == -1 && ptr < f){
                block[ptr] = ref[i];
                ptr++;
            } else block[replaceNext(block, f, ref, i+1, n-1)] = ref[i];
        }
    }
    cout << "Page Faults: " << faults << endl;  
}

