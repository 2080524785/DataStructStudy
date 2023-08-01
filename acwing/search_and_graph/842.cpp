// 2023年8月1日13点38分
#include<iostream>
using namespace std;
const int N = 10;
int a[N],cnt=0,n,s[N];
void print(int x){
    if(x>n){
        for(int i=1;i<=n;i++){
            cout<< a[i]<<" ";
        }
        cout<<endl;
    }
    for(int i=1;i<=n;i++){
        if(!s[i]){
            a[x]=i;
            s[i]=1;
            print(x+1);
            s[i]=0;
        }
    }
}

int main(){
    cin>>n;
    print(1);
    return 0;
}