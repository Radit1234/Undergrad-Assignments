#include<bits/stdc++.h>
using namespace std;
set<int> s;
deque<int> q;
int page[100] , data[100][100] , counts = 0;

/*
void savequeue(queue<int> q)
{
    while(!q.empty()) data[i][counts] = q.front() , q.pop();
    counts++;
}
*/

int main()
{
    freopen("input.txt","r",stdin);
    int n,r,value , frame , page_fault = 0;
    cin>>n>>r;
    for(int i=0;i<r;i++)
        cin>>page[i];
    cin>>frame;
    memset(data,-1,sizeof(data));
    for(int i=0;i<r;i++)
    {
        cout<<page[i]<<"  ";
        if(s.size() < frame)
        {
            if(!s.count(page[i]))
            {
                s.insert(page[i]);
                q.push_front(page[i]);
                page_fault++;

            }
        }
        else{
            if(!s.count(page[i]))
            {
                value = q.back();
                s.erase(value);
                q.pop_back();

                s.insert(page[i]);
                q.push_front(page[i]);
                page_fault++;
            }
        }
        int k = 0;
        for(auto x: q)
            data[k++][counts] = x;
        counts++;
    }
    cout<<endl<<endl;
    for(int i=0;i<frame;i++)
    {
        for(int j=0;j<r;j++)
        {
            if(data[i][j] == -1) cout<<"   ";
            else
                cout<<data[i][j]<<"  ";
        }
        cout<<endl;
    }

    cout<<"page fault : "<<page_fault<<endl;
}
