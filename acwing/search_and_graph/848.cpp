#include<iostream>
#include<cstring>
#include <algorithm>
#include<queue>

using namespace std;
const int N = 1e5+10;
int h[N],e[N],ne[N],idx,d[N];
int n,m,num=0;
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
    d[b]++;
}
int q[N],hh=0,tt=-1;

void topsort(){
    for(int i=1;i<=n;i++){
        if(d[i]==0){
            q[++tt]=i;
            num++;
        }
    }
    while(tt>=hh){
        int a = q[hh++];
        
        for(int i=h[a];i!=-1;i = ne[i]){
            int b = e[i];
            d[b]--;
            if(d[b]==0){
                q[++tt]  = b;
            }
        }
    }
    if(tt==n-1){
        for(int i=0;i<n;i++){
            cout<<q[i]<<" ";
        }
    }else{
        cout<<-1;
    }
    

}

int main(){

    memset(h, -1, sizeof(h));
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        add(a,b);

    }
    
    topsort();

    return 0;
}