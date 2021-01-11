#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

struct process{
    int name;
    int arrivalTime;
    int cpuTime;
    int waitingTime;
    int turnaroundTime;
} processes[MAX];

bool cmp(process a, process b)
{
    return a.arrivalTime < b.arrivalTime;
}

int main()
{
    int num_process, total_waitingTime = 0, total_turnaroundTime = 0;
    double avg_waitingTime, avg_turnaroundTime;
    cin>>num_process;

    for(int i=0;i<num_process;i++){
        processes[i].name = i+1;
        cin>>processes[i].arrivalTime >> processes[i].cpuTime;
    }

    sort(processes ,processes+num_process , cmp);

    processes[0].waitingTime = 0;
    processes[0].turnaroundTime = processes[0].waitingTime + processes[0].cpuTime;
    total_turnaroundTime = processes[0].turnaroundTime;
    for(int i=1;i<num_process;i++){
        processes[i].waitingTime = processes[i-1].turnaroundTime + processes[i-1].arrivalTime - processes[i].arrivalTime;
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].cpuTime;

        total_waitingTime += processes[i].waitingTime;
        total_turnaroundTime += processes[i].turnaroundTime;
    }

    avg_waitingTime = (double)total_waitingTime / num_process;
    avg_turnaroundTime = (double)total_turnaroundTime / num_process;

    //for(int i=0;i<num_process;i++)
        //cout<<processes[i].name<<" "<<processes[i].waitingTime<<" "<<processes[i].turnaroundTime<<endl;

    cout<<"average waiting time : "<<avg_waitingTime <<endl;
    cout<<"average turnaround time : "<<avg_turnaroundTime <<endl;

}
