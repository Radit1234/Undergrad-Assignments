#include<bits/stdc++.h>
using namespace std;
set<int> s;
deque<int> q;
int page[100] , data[100][100] = {-1} , counts = 0;

int main()
{
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n,r,value , frame , page_fault = 0 ,index ;
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
                page_fault++;
            }
        }
        else{
            if(!s.count(page[i]))
            {
                index = INT_MIN;
                for(auto x : s)
                {
                    int j;
                    for(j=i+1;j<r;j++)
                    {
                        if(x==page[j]){
                            if(index<j)
                                index = j,value = x ;
                            break;
                        }
                    }
                    if(j==r){
                        value = x ;
                        break;
                    }
                }
                //cout<<value<<" "<<index<<endl;
                s.erase(value);
                s.insert(page[i]);
                page_fault++;
            }

        }
        int k = 0;
        for(auto x : s){
            data[k++][counts] = x;
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
