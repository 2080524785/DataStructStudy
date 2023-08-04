#include<iostream>
#include<cstring>
#include <algorithm>

using namespace std;
const int N = 1e5+10;
int h[N],e[N*2],ne[N*2],idx,ans=N;
int n;
void add(int a,int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
bool stu[N];
int dfs(int u){
    int res = 0;
    stu[u] = 1;
    int sum =1;
    for(int i=h[u];i!=-1;i = ne[i]){
        int j = e[i];
        if(!stu[j]){
            int s = dfs(j);
            res = max(res,s);
            sum += s;
        }
    }

    res = max(res, n - sum);
    ans = min(res,ans);
    return sum;
}

int main(){

    memset(h, -1, sizeof(h));
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    dfs(1);
    cout<<ans;
    return 0;
}