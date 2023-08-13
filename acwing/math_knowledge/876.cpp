#include<iostream>
using namespace std;

typedef long long LL;

LL qmi(int a,int b,int c){
    LL res = 1;
    while(b){
        if(b&1) res = res*a%c;
        a = (LL) a*a%c;
        b>>=1;
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    while(n--){
        int a,p;
        cin>>a>>p;
        if(a%p==0) cout<<"impossible"<<endl;
        else cout<<qmi(a,p-2,p)<<endl;
    }
    return 0;
}