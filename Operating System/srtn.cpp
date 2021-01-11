#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
ifstream inf("input.txt");
vector<int> times , ps;
struct process{
    int id;
    int arrivaltime;
    int cputime;
}processes[MAX];


int main()
{
    int timer = 0 , n , current , next , total = 0 , s_time = INT_MAX , ptime = 0;
    inf>>n;
    for(int i=0; i<n;i++)
    {
        processes[i].id = i+1;
        inf>>processes[i].arrivaltime>>processes[i].cputime;
        total += processes[i].cputime;

        if(s_time > processes[i].arrivaltime) s_time = processes[i].arrivaltime , current = i;
    }
    times.push_back(0);
    for(int t = 1;t<=total; )
    {
        //cout<<t<<" "<<current+1<<endl;
        processes[current].cputime--;
        s_time = INT_MAX;
        t++;
        for(int i=0;i<n;i++)
        {
            if(processes[i].cputime>0 && processes[i].arrivaltime <=t && s_time > processes[i].cputime) s_time = processes[i].cputime , next = i;
        }
        if(current != next) ps.push_back(current+1) , times.push_back(t-1) , current = next;
    }
    ps.push_back(current+1);
    times.push_back(total);

    int tsize = times.size();
    for(int i=0;i<tsize;i++){
        if(i==tsize-1) cout<<times[i]<<endl;
        else cout<<times[i]<<"------";
    }
    //cout<<"-";
    for(int i=0;i<ps.size();i++){
        if(i==0) cout<<"---P"<<ps[i]<<"---";
        else cout<<"--P"<<ps[i]<<"---";
    }


    return 0;
}

