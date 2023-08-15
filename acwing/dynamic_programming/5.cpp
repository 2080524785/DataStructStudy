#include<iostream>
using namespace std;

const int N = 1e4+10;
int n,m;
int w[N],v[N],f[N];

int main(){

    cin>>n>>m;
    int cnt = 0;
    while(n--){
        int a,b,s;
        cin>>a>>b>>s;
        for(int k=1;k<=s;k*=2){
            cnt++;
            w[cnt] = a*k;
            v[cnt] = b*k;
            s-=k;
        }
        if(s>0){
            cnt++;
            w[cnt] = a*s;
            v[cnt] = b*s;
        }
    }
    n = cnt;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=w[i];j--){
            f[j] = max(f[j],f[j-w[i]]+v[i]);
        }
    }
    cout<<f[m];
    return 0;
}