#include<iostream>
using namespace std;

const int N = 1e2+10;
int f[N];
int main(){
    int n,m,t;
    cin>>n>>m;
    while(n--){
        int a,b,s;
        cin>>a>>b>>s;
        while(s--)
            for(int j=m;j>=a;j--)
                f[j] = max(f[j],f[j-a]+b);
    }
    cout<<f[m];
    return 0;
}