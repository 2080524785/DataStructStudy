#include<iostream>
using namespace std;
const int mod = 1e9+7;
long long f[2010][2010];
int main(){
    for(int i=0;i<=2000;i++){
        for(int j=0;j<=i;j++){
            if(!j) f[i][j] = 1;
            else f[i][j] = (f[i-1][j-1]+f[i-1][j])%mod; 
        }
    }
    int n;
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
        cout<<f[a][b]<<endl;
    }
    return 0;
}