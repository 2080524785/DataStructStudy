// 2023年8月1日19点51分
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n,m;
const int N=110,M=110;
int a[N][M],b[N][M];
typedef pair<int,int> PII;

void bfs(int x,int y){
    int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
    queue<PII> q;
    q.push({x,y});
    while(!q.empty()) {
        PII p = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int j=p.first+dx[i],k = p.second+dy[i];
            if(a[j][k]==0){
                a[j][k] = 1;
                b[j][k] = b[p.first][p.second]+1;
                q.push({j,k});
            }
        }
    }
    cout<<b[n][m];
}

int main(){
    memset(a, 1, sizeof(a));
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin>>a[i][j];
    }
    bfs(1,1);

}