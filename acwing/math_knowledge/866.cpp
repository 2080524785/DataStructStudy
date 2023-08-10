#include<iostream>
using namespace std;
int n;

string prim(int x){
    bool k = 0;
    if(x==2||x==1) return (x-1)?"Yes":"No";
    for(int i=2;i<=x/i;i++){
        if(x%i==0) k=1; 
    }
    return k?"No":"Yes";
}

int main(){
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        cout<<prim(x)<<endl;
    }
    return 0;
}