// 2023年7月24日 22点02分
// 带权并查集
#include <iostream>
using namespace std;
const int N = 5e4+10;
int p[N],s[N];
int find(int x){
    if(p[x]==x) return x;
    int r = find(p[x]);
    s[x]+=s[p[x]];
    return p[x]=r;
}

int main(){
    int n,k;
    cin>>n>>k;
    int ans = 0;
    for(int i=1;i<=n;i++) p[i]=i;
    for(int i=1;i<=k;i++){
        int t,a,b;
        cin>>t>>a>>b;
        if(a>n||b>n) {
            ans++;
            continue;
        }else if(t==2&&a==b){
            ans++;
            continue;
        }else{
            int rel=t-1;
            int x=find(a),y=find(b);
            if(x==y){
                if((((s[a]-s[b])%3)+3)%3!=rel) ans++;
            }else{
                p[x]= y;
                s[x] = s[b]-s[a]+rel;
            }
        }
    }
    cout<<ans;
}