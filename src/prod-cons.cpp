#include<iostream>
#include<stack>
using namespace std;
void printStack(stack <int> s){
    while (!s.empty()) 
    { 
        cout << s.top() << '\t' ; 
        s.pop(); 
    } 
    cout << '\n'; 
}
int main(){
    stack <int> stk;
    char cho;
    int bufferSize, tmp;
    cout << "[Press 'q' to quit]" << endl;
    cout << "Enter buffer size: ";
    cin >> bufferSize;
    while(cho != 'q'){
        cout << "Produdce or Consume(p/c): ";
        cin >> cho;
        if(cho == 'p'){
            if(stk.size() < bufferSize){
            cout << "Data: ";
            cin >> tmp;
            stk.push(tmp);
            printStack(stk);
            cout << "updated." << endl;
        } 
        else {
            cout << "Buffer Full." << endl;
         
        }
    
        } else if(!stk.empty() && cho == 'c'){
            stk.pop();
            printStack(stk);
            cout << "updated." << endl;
        } else if(stk.size() == 0 && cho=='c')
        {
            cout << "Buffer Empty." << endl;
        }
    }
}
