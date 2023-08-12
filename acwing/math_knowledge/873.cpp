#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;



int main(){
    int n;
    cin>>n;
    int x;
    while(n--){
        cin>>x;
        int ans=x;
        unordered_map<int,int> hash;
        if(x==1||x==2){
            cout<<1<<endl;
            continue;
        }
        for(int i=2;i<=x/i;i++){
            if(x%i==0){
                while(x%i==0){
                    x = x/i;
                }
                ans = ans/i*(i-1);        
            }
            
        }
        if(x>1) ans = ans/x*(x-1);
        cout<<ans<<endl;
    }
    return 0;
}