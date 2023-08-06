#include<iostream>
#include<cstring>
using namespace std;
const int N = 510,M = 10010;
struct{
    int a;
    int b;
    int w;
}e[M];
int n,m,k;
int dist[N],backup[N];
void solution(){
    memset(dist,0x3f,sizeof (dist));
    dist[1] = 0;
    for(int i=1;i<=k;i++){
        memcpy(backup,dist,sizeof(dist));
        for(int j=1;j<=m;j++){
            int a = e[j].a,b=e[j].b,w=e[j].w;
            dist[b] = min(dist[b],backup[a]+w);

        }
    }
    if(dist[n]>=0x3f3f3f3f/2) cout<<"impossible";
    else cout<<dist[n];
}
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        e[i].a=a;e[i].b=b;e[i].w=c;
    }
    solution();
    return 0;
}