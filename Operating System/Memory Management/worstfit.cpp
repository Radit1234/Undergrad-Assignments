#include<bits/stdc++.h>
using namespace std;
int n,m;
int mh[100],mr[100];
int memory[100][100]; //memory hole and memory request

int main()
{
    freopen("input.txt","r",stdin);
    int external_fragment = 0 , pos , maxval , turn;
    bool exfrag ;
    cin>>n>>m;
    int count = 0;
    pos = m;
    for(int i=0;i<n;i++){
        cin>>mh[i];
    }

    for(int i=0;i<m;i++)
        cin>>mr[i];
    cout<<"-----------------------------------Worst Fit--------------------------------"<<endl<<endl;

    for(int i=0;i<m;i++)
    {
        bool exfrag = true;
        maxval = INT_MIN;
        for(int j=0;j<n;j++)
        {
            if(mh[j] >= mr[i] && maxval < mh[j])
                turn = j , maxval = mh[j] , exfrag = false;
        }
        if(exfrag){
            pos = i;
            for(int j=0;j<n;j++)
                external_fragment += mh[j];
            break;
        }
        else
        {
            mh[turn] -= mr[i];
            for(int j=0;j<n;j++)
                memory[j][count] = mh[j];
        }
        //cout<<"pos: "<<pos<<endl;
        count++;
    }

    for(int i=0;i<m;i++)
        cout<<mr[i]<<"\t";
    cout<<endl;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<pos;j++)
        {
            cout<<memory[i][j]<<"\t";
        }
        cout<<endl;
    }

    cout<<"external fragment: "<<external_fragment<<endl;

}

