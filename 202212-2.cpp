#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int p[m],t[m];
    for(int i=0;i<m;i++){
        cin>>p[i];
    }
    for(int i=0;i<m;i++){
        cin>>t[i];
    }
    bool flag=false;
    for(int i=0;i<m;i++){
        int j=p[i];
        int time=1;
        while(j!=0){
            time+=t[j];
            j = p[j];
        }
        cout<<time<<" ";
        if(time+t[i]>n){
            flag=true;
        }
    }

    
    return 0;
}