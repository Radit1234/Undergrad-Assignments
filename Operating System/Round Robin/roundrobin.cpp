
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
ifstream inf("input.txt");
ofstream ouf("output.txt");

struct process{
 int name;
 int arrivaltime;
 int cputime;
 bool inque;
}processes[MAX];

bool cmp(process a, process b)
{
  return a.arrivaltime < b.arrivaltime ;
}

int main()
{
  int numprocess, q , timer = 0 , currentprocess;
  inf>>numprocess>>q;
  queue<process> qe;

  for(int i=0;i<numprocess;i++)
  {
     processes[i].name = i+1;
     processes[i].inque = false;
     inf>>processes[i].arrivaltime>>processes[i].cputime;
  }

   sort(processes, processes+numprocess, cmp);
   qe.push(processes[0]);
   processes[0].inque = true;
   int ptime = 0;
   while(!qe.empty())
   {
       process x = qe.front();
       //cout<<x.name<<" "<<x.cputime<<endl;
       qe.pop();
       ptime = timer;

       for(int i=0;i<numprocess;i++){
                if(x.name==processes[i].name)
                {
                                if(q < processes[i].cputime) processes[i].cputime -= q , timer += q , currentprocess = i  ;
                                else   timer += processes[i].cputime , processes[i].cputime = 0 , currentprocess = -1 , processes[i].inque = false ;
                                //cout<<processes[i].name<<" "<<processes[i].cputime<<endl;
                                break;
                }
       }
       ouf<<ptime<<"--"<<x.name<<"--"<<timer<<endl;

       for(int i=0; i<numprocess; i++)
       {

            if(processes[i].cputime && processes[i].arrivaltime <= timer && !processes[i].inque && x.name!=processes[i].name)
                qe.push(processes[i]) ,  processes[i].inque = true;
       }
       if(currentprocess >= 0) qe.push(processes[currentprocess]) , processes[currentprocess].inque = true;
   }
}

