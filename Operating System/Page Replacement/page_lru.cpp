#include<bits/stdc++.h>
using namespace std;
set<int> s;
deque<int> q;
int page[100] , data[100][100] = {-1} , counts = 0;

int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n,r,value , frame , page_fault = 0 ,tail= -1;
    cin>>n>>r;
    for(int i=0;i<r;i++)
        cin>>page[i];
    cin>>frame;
    int qe[frame];
    memset(data,-1,sizeof(data));

    for(int i=0;i<r;i++)
    {
        cout<<page[i]<<"  ";
        if(s.size() < frame)
        {
            if(!s.count(page[i]))
            {
                s.insert(page[i]);
                qe[++tail] = page[i];
                page_fault++;
            }
        }
        else{
            if(!s.count(page[i]))
            {
                value = qe[0];
                s.erase(value);
                s.insert(page[i]);
                for(int j=1;j<frame;j++)
                    qe[j-1] = qe[j];
                qe[frame-1] = page[i];
                page_fault++;
            }
            else{
                value = INT_MAX;
                for(int j=0;j<frame;j++)
                {
                    if(page[i] == qe[j])
                        value = j;
                    if(j>value) qe[j-1] = qe[j];
                }
                qe[frame-1] = page[i];
            }
        }

        for(int k = 0;k<=tail;k++){
            data[k][counts] = qe[k];
        }

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
