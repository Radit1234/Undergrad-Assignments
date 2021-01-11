#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
ifstream inf("input.txt");

struct process{
    int name;
    int arrivalTime;
    int cpuTime;
    int waitingTime;
    int turnaroundTime;
} processes[MAX];

bool cmp(process a, process b)
{
    return a.arrivalTime < b.arrivalTime ;
}

bool cmp2(process a, process b)
{
    return a.cpuTime < b.cpuTime ;
}


int main()
{
    int num_process, total_waitingTime = 0, total_turnaroundTime = 0 , timer = 0;
    double avg_waitingTime, avg_turnaroundTime;
    inf>>num_process;

    for(int i=0;i<num_process;i++){
        processes[i].name = i+1;
        inf>>processes[i].arrivalTime >> processes[i].cpuTime;
    }

    sort(processes ,processes+num_process , cmp);
    for(int i=0;i<num_process;i++){
        //cout<<processes[i].name<<" "<<processes[i].arrivalTime<<" "<<processes[i].cpuTime<<endl;

        processes[i].waitingTime = 0;
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].cpuTime;

        total_waitingTime += processes[i].waitingTime;
        total_turnaroundTime += processes[i].turnaroundTime;

        vector<process> v;
        timer += processes[i].cpuTime;

        for(int j=i+1;j<num_process;j++)
        {
            if(processes[j].arrivalTime <= timer){
                v.push_back(processes[j]);
                timer += processes[j].cpuTime;
            }
        }
        sort(v.begin(),v.end(),cmp2);
        for(int k=0;k<v.size();k++)
        {
            processes[++i] = v[k];
            processes[i].waitingTime = processes[i-1].turnaroundTime + processes[i-1].arrivalTime - processes[i].arrivalTime;
            processes[i].turnaroundTime = processes[i].waitingTime + processes[i].cpuTime;

            total_waitingTime += processes[i].waitingTime;
            total_turnaroundTime += processes[i].turnaroundTime;
        }
    }
    avg_waitingTime = (double)total_waitingTime / num_process;
    avg_turnaroundTime = (double)total_turnaroundTime / num_process;

    for(int i=0;i<num_process;i++)
        cout<<processes[i].name<<" "<<processes[i].waitingTime<<" "<<processes[i].turnaroundTime<<endl;

    cout<<"average waiting time : "<<avg_waitingTime <<endl;
    cout<<"average turnaround time : "<<avg_turnaroundTime <<endl;
}
