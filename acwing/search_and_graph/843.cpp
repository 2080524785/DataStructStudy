// 2023年8月1日18点20分
#include<iostream>
using namespace std;
int n;
const int N = 10;
int q[2*N],p[2*N],c[N],ans[N][N];

void dfs(int r){
    if(r>n){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(ans[i][j]!=0) cout<<"Q";
                else cout<<".";
            }
            cout<<endl;
        }
        cout<<endl;

    }
    for(int i=1;i<=n;i++){
        if(q[r+i-1]==0&&p[n-r+i]==0&&c[i]==0){
            q[r+i-1]++;
            p[n-r+i]++;
            c[i]++;
            ans[r][i]++;
            dfs(r+1);
            ans[r][i]--;
            q[r+i-1]--;
            p[n-r+i]--;
            c[i]--;
        }
    }
}
int main(){
    cin>>n;
    dfs(1);
    return 0;
}