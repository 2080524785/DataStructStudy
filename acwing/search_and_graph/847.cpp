#include<iostream>
#include<cstring>
#include <algorithm>
#include<queue>

using namespace std;
const int N = 1e5+10;
int h[N],e[N*2],ne[N*2],idx,d[N];
int n,m;
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
queue<int> q;

void bfs(){
    memset(d, -1, sizeof(d));
    d[1] = 0;
    q.push(1);
    while(q.size()){
        int t = q.front();
        q.pop();
        for(int i=h[t];i!=-1;i=ne[i]){
            int j = e[i];
            if(d[j]==-1){
                d[j] = d[t]+1;
                q.push(j);
            }
        }
    }
    cout<<d[n];

}

int main(){

    memset(h, -1, sizeof(h));
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        add(a,b);

    }
    
    bfs();

    return 0;
}