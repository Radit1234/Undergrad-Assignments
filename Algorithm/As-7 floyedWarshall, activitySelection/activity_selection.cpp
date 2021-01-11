#include<bits/stdc++.h>
using namespace std;

struct activity{
    int num , start, finish;
};

bool operator<(activity a, activity b){
    return a.finish < b.finish;

}

void activitySelection(vector<activity> v){
    int n = v.size();
    sort(v.begin(), v.end());
    int k = 0;
    cout<<v[k].num<<"\t";

    for(int i=1; i<n; i++){
        if(v[i].start >= v[k].finish){
            cout<<v[i].num<<"\t";
            k=i;
        }
    }

}

int main(){
    vector<activity> v;
    int a,b;
    for(int i=0; i<6; i++){
        activity temp;
        temp.num = i;
        cin>>temp.start>>temp.finish;
        v.push_back(temp);
    }

    activitySelection(v);
}
