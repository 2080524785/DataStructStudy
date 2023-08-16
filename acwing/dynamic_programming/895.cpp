#include<iostream>
using namespace std;

const int N = 1010;

int n;
int w[N],f[N];

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>w[i];
    int mx = 1;
    for(int i=1;i<=n;i++){
        f[i] = 1;
        for(int j=1;j<i;j++){
            if(w[i]>w[j]) f[i] = max(f[i],f[j]+1);
        }
        mx = max(mx,f[i]);
    }
    cout<<mx<<endl;
    return 0;
}