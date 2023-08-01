//  2023年7月25日 13点46分 
// 堆排序 小顶堆

#include<iostream>
using namespace std;

const int N = 1e5+10;
int a[N];
int n,m;
int r; // 右边界
void down(int u){
    int t = u;
    if(2*u<=r&&a[2*u]<a[u]) t = 2*u; // > 为大顶堆
    if(2*u+1<=r&&a[2*u+1]<a[t]) t=2*u+1; // > 为大顶堆
    if(u!=t){
        swap(a[u],a[t]);
        down(t);
    }
}
int main(){
    
    cin>>n>>m;
    r = n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=n/2;i>=1;i--) down(i); // 编号从1开始时，n/2 必定为最后一个非叶节点
    while(m--){
        cout<<a[1]<<" ";
        swap(a[1],a[r]);
        r--;
        down(1);
    }
    return 0;
}