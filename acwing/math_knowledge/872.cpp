#include<iostream>
using namespace std;

int main(){
    int n,a,b;
    cin>>n;
    while(n--){
        cin>>a>>b;
        
        while(a%b!=0){
            int c=a%b;
            a = b;
            b=c;
        }
        cout<<b<<endl;
    }
}