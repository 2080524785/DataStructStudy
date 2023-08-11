#include<iostream>
using namespace std;
const int N = 1e6+10;
int st[N],p[N],cnt=0;

int main(){
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        if(!st[i]) p[cnt++]=i;
        for(int j=0;p[j]<=n/i;j++){
            st[p[j]*i] = 1;
            if(i%p[j]==0) break;
        }

    }
    cout<<cnt;
    return 0;
}