#include<iostream>
using namespace std;
void restack(int stack[], int fli){
    int temp = stack[fli];
    for(int i = fli; i > 0; i--){
        stack[i] = stack[i-1]; 
    }
    stack[0] = temp;
}
void push_shift(int stack[], int data, int max){
    for(int i = max; i > 0; i--){
        stack[i] = stack[i-1]; 
    }
    stack[0] = data;
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
            if(block[j] == ref[i]){
                hit = 1;
                restack(block, j);
            }
        }
        if(hit == 0){
            faults++;
            push_shift(block, ref[i], f);
        }
    }
    cout << "Faults: " << faults << endl;  
}