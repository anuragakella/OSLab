#include<iostream>
#include <iterator>
#include <map>
using namespace std;
class Resource{
    public:
    char name;
    bool inUse;
};
class Process{
    public:
    int pid;
    char *registers;
    char *memoryLocations;
    char *storageLocations;
    bool running;
    void init(int reg, int mem, int store){
        running = false;
        registers = new char[reg];
        memoryLocations = new char[mem];
        storageLocations = new char[store];
        cout << "What Resources does this process use: " << endl;
        cout << "Registers: ";
        for(int i = 0;i<reg;i++){
            cin >> registers[i];
        }
        cout << "Memory Locations: ";
        for(int i = 0;i<mem;i++){
            int temp;
            cin >> hex >> temp;
            memoryLocations[i] = (char)temp;
        }
        cout << "Storage: ";
        for(int i = 0;i<store;i++){
            cin >> storageLocations[i];
        }
        cout << "##############" << endl;
    }
};
int main(){
    int n, r, m, s, rp, mp, sp;
    char chr = 'A', chm = 'A', chs = 'A';
    map<char, Resource> total_reg, total_mem, total_store;
    Process *procs;
    cout << "Enter no. of Processes: ";
    cin >> n;
    cout << "Enter total no. of Registers: ";
    cin >> r;
    cout << "Enter total no. of Memory Locations: ";
    cin >> m;
    cout << "Enter total no. of Storage Locations: ";
    cin >> s;
    procs = new Process[n];
    cout << "-------------------------------------------------------------" << endl;
    cout << "Available System Resources: " << endl;
    cout << "Registers: ";
    for(int i = 0;i<r;i++){
        total_reg[chr].name = chr;
        total_reg[chr].inUse = false;
        cout << total_reg[chr].name << " ";
        chr++;
    }
    cout << endl << "Memory Locations: ";
    for(int i = 0;i<m;i++){
        total_mem[chm].name = chm;
        total_mem[chm].inUse = false;
        cout << "0x" << hex << (int)total_mem[chm].name << " ";
        chm++;
    }
    cout << endl << "Storage Locations: ";
    for(int i = 0;i<s;i++){
        total_store[chs].name = chs;
        total_store[chs].inUse = false;
        cout << total_store[chs].name << " ";
        chs++;
    }
    cout << endl << "-------------------------------------------------------------" << endl << endl;
    for(int i=0;i<n;i++){
        cout << "Process P" << i << ":" << endl;
        cout << "Enter no. of Registers, Mem Locations, Storage Locations: ";
        cin >> rp >> mp >> sp;
        procs[i].init(rp, mp, sp);
    }
    cout << endl << endl << "Checking Resource Availability..." << endl << endl;
    cout << "-------" << endl;
    char ch = 'A';
    for(int i=0;i<n;i++){
        for(int k=0;k<rp;k++){
            if(procs[i].registers[k] == total_reg[procs[i].registers[k]].name){
                if(total_reg[procs[i].registers[k]].inUse == false){
                    //cout << "Process P" << i << " was allowed to use register " << total_reg[procs[i].registers[k]].name << endl;
                    total_reg[procs[i].registers[k]].inUse = true;
                    procs[i].running = true;
                }
                else if(total_reg[procs[i].registers[k]].inUse = true){
                    cout << total_reg[procs[i].registers[k]].name << " [Register] is in Use. Process P" << i <<" will be held until the resource is unlocked." << endl;
                    procs[i].running = false;
                }
            } 
            else {
                cout << procs[i].registers[k] << " - Resource not available. Did you enter a proper name? [names are case-sensitive].";
                procs[i].running = false;
                goto stopProcess;
            }

        }
        for(int k=0;k<mp;k++){
            if(procs[i].memoryLocations[k] == total_mem[procs[i].memoryLocations[k]].name){
                if(total_mem[procs[i].memoryLocations[k]].inUse == false){
                    //cout << "Process P" << i << " was allowed to use Memory Location " << total_mem[procs[i].memoryLocations[k]].name << endl;
                    total_mem[procs[i].memoryLocations[k]].inUse = true;
                    procs[i].running = true;
                }
                else if(total_mem[procs[i].memoryLocations[k]].inUse = true){
                    cout << " 0x" << hex << (int)total_mem[procs[i].memoryLocations[k]].name << " [Memory Location] is in Use. Process P" << i <<" will be held until the resource is unlocked." << endl;
                    procs[i].running = false;
                }
            } 
            else {
                cout << procs[i].memoryLocations[k] << " - Resource not available. Did you enter a proper name? [names are case-sensitive].";
                procs[i].running = false;
                goto stopProcess;                
            }

        }
        for(int k=0;k<sp;k++){
            if(procs[i].storageLocations[k] == total_store[procs[i].storageLocations[k]].name){
                if(total_store[procs[i].storageLocations[k]].inUse == false){
                    //cout << "Process P" << i << " was allowed to use Disk Location " << total_store[procs[i].storageLocations[k]].name << endl;
                    total_store[procs[i].storageLocations[k]].inUse = true;
                    procs[i].running = true;
                }
                else if(total_store[procs[i].storageLocations[k]].inUse = true){
                    cout << total_store[procs[i].storageLocations[k]].name << " [Storage Location] is in Use. Process P" << i <<" will be held until the resource is unlocked." << endl;
                    procs[i].running = false;
                }
            } 
            else {
                cout << procs[i].storageLocations[k] << " - Resource not available. Did you enter a proper name? [names are case-sensitive].";
                procs[i].running = false;
                goto stopProcess;
            }

        }
        stopProcess:
        cout << endl;
        if(procs[i].running == true){
            cout << "The requested resources were free." << endl << endl;
            cout << " --> Process P" << i << " is now running." << endl;
        }
        else
        cout << " --> Process P" << i << " couldn't start." << endl;
        cout << endl;
    }
    }

