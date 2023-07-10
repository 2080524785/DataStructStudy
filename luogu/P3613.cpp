#include<bits/stdc++.h>
#include<vector>
#include<map>
using namespace std;
int n,q,o;

map<int,map<int,int>> good;
long long i,j,k;
int main(){
    cin>>n>>q;
    while(q--){
        cin>>o>>i>>j;
        if(o==1){
            cin>>k;
            good[i][j]=k;
        }else{
            cout<<good[i][j]<<endl;
        }
    }
    return 0;
}