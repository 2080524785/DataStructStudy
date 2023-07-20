#include<iostream>

using namespace std;
const int N = 1e5;
int idx_start=-1,idx_end=-1,a[N];
int main(){
    int n;
    cin>>n;
    string s;
    int x;
    while(n--){
        cin>>s;
        if(s =="push"){
            cin>>x;
            a[++idx_end] = x;

        }else if(s=="pop"){
            idx_start++;
        
        }else if(s=="empty"){
            cout<<(idx_start!=idx_end?"NO":"YES")<<endl;

        }else if(s=="query"){
            cout<<a[idx_start+1]<<endl;
        }
    }

    return 0;
}