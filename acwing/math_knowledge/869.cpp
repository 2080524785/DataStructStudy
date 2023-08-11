#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 110;

int main(){
    int n;
    cin>>n;
    int a;
    while(n--){
        cin>>a;
        vector<int> x;
        for(int i=1;i<=a/i;i++){
            if(a%i==0){
                x.push_back(i);
                if(i!=a/i) x.push_back(a/i);
            }
        }
        sort(x.begin(),x.end());
        for(auto i:x) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}