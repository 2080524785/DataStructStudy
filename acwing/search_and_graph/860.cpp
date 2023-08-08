#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e5+10;
int e[2*N],h[N],ne[2*N],idx;
int n,m,color[N];
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
bool dfs(int u,int c){
    color[u] = c;
    for(int i=h[u];i!=-1;i=ne[i]){
        int k = e[i];
        if(!color[k]){
            if(!dfs(k,1-c)) return false;
        }
        else if(color[k]&&color[k]!=1-c) return false;
    }
    return true;
}
int main(){
    memset(h,-1,sizeof(h));
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        add(a,b),add(b,a);
    }
    for(int i=1;i<=n;i++){
        if(!color[i]){
            if(!dfs(i,0)){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}