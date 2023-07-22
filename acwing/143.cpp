// 最大异或对
// 寻找与输入整数最远的道路
#include<iostream>
using namespace std;

const int N = 1e5+10;
int q[N*31][2],idx=0;

void insert(int x){
    int p=0;
    for(int i=31;i>=0;i--){
        int s = x>>i&1;
        if(!q[p][s]) q[p][s]=++idx;
        p = q[p][s];
    }
}
int query(int x){
    int p=0,res =0;
    for(int i=31;i>=0;i--){
        int s = x>>i&1;
        if(!q[p][!s]){
            p = q[p][s];
            res = res*2 + s;
        }else{
            p = q[p][!s];
            res = res*2 + !s;
        }
    }
    return res^x;
}

int main(){
    int n;
    cin>>n;
    int x,max_num;
    while(n--){
        cin>>x;
        insert(x);
        max_num = max(max_num,query(x));
    }
    cout<<max_num;
    return 0;
}