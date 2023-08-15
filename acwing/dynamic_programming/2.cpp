#include<iostream>
using namespace std;

const int N=1e3+10;
int v[N],w[N],f[N];


int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        for(int j=m;j>=a;j--){
            f[j] = max(f[j],f[j-a]+b);
        }
    }
    cout<<f[m];
    return 0;
}