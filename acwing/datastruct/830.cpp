#include<iostream>
#include<stack>

using namespace std;
const int N = 1e5+10;
int idx=-1,a[N];
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int x;
    while(n--){
        cin>>x;
        while(idx!=-1&&a[idx]>=x){
            idx--;
        }
        if(idx==-1){
            a[++idx]=x;
            cout<<"-1"<<" ";
        }else{
            cout<<a[idx]<<" ";
            a[++idx]=x;
        }
    }
    system("pause");
    return 0;
}