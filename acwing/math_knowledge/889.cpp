#include <iostream>
using namespace std;

typedef long long LL;

int quick_pow(int a, int b, int p)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (LL)res * a % p;
        a = (LL)a * a % p;
        b >>= 1;
    }
    return res;
}
const int mod = 1e9 + 7, N = 2e5 + 10;
LL fac[N], infac[N];
int main()
{
    int n;
    cin >> n;
    int a=2*n,b=n;
    int res =1 ;
    for(int i=a;i>a-b;i--){
        res = (LL) res*i%mod;
    }
    for(int i=1;i<=b;i++){
        res = (LL)res*quick_pow(i,mod-2,mod)%mod;
    }
    res = (LL) res*quick_pow(n+1,mod-2,mod)% mod;
    cout<<res;
}