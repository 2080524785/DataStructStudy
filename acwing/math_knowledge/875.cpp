#include<iostream>

using namespace std;

long long quick_pow(long long a,long long b,long long p){
    if(b==0) return 1;
    a%=p;
    long long res = quick_pow(a,b>>1,p);
    if(b&1) return res*res%p*a%p;
    return res*res%p;
}

int main(){
    int n;
    cin>>n;
    while(n--){
        int a,b,p;
        cin>>a>>b>>p;
        long long res = 1;
        
        cout<<quick_pow(a,b,p)<<endl;
    }
    return 0;
}