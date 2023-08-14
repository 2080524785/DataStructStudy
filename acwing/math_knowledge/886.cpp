#include<iostream>
using namespace std;

typedef long long LL;

int quick_pow(int a,int b,int p){
    int res=1;
    while(b){
        if(b&1) res = (LL)res*a%p;
        a = (LL)a*a%p;
        b>>=1;
    }
    return res;
}
const int mod = 1e9+7,N = 1e5+10;
LL fac[N],infac[N];
int main(){
    int n ;
    cin>>n;
    fac[0]=infac[0] =1;
    for(int i=1;i<=1e5;i++){
        fac[i] = fac[i-1]*i%mod;
        infac[i] = (LL)infac[i-1]*quick_pow(i,mod-2,mod)%mod;
    }
    while(n--){
        int a,b;
        cin>>a>>b;
        cout<<(LL)fac[a]*infac[b]%mod*infac[a-b]%mod<<endl;
    }
}