#include<iostream>
#include<cstring>
using namespace std;

const int N  =510;
int g[N][N];
int d[N],pre[N];
bool st[N];
int n,m;

void prim(){
    memset(d,0x3f,sizeof(d));
    int res = 0;
    d[1] = 0;
    for(int i=0;i<n;i++){
        int t = -1;
        for(int j=1;j<=n;j++){
            if(!st[j]&&(t==-1||d[t]>d[j])){
                t = j;
            }
        }
        if(d[t]==0x3f3f3f3f){
            cout<<"impossible";
            return;
        }
        
        st[t]=1;
        res+=d[t];
        for(int i=1;i<=n;i++){
            if(d[i]>g[t][i]&&!st[i]){
                d[i] = g[t][i];
                pre[i] = t;
            }
        }
    }
    cout<<res;
}

int main(){
    memset(g,0x3f,sizeof(g));
    cin>>n>>m;
    while(m--){
        int a,b,w;
        cin>>a>>b>>w;
        g[a][b] = g[b][a] = min(g[a][b],w);
    }
    prim();
    return 0;
}