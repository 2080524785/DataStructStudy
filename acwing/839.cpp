// 2023年7月25日 21点30分
#include<iostream>
using namespace std;
const int N=10;
int p[N],h[N],ph[N];
int n,r=0,cnt=0;

void upgrade(int i){
    int t = i;
    if(2*i<=r&&p[2*i]<p[i]) t = 2*i;
    if(2*i+1<=r&&p[t]>p[2*i+1]) t = 2*i+1;
    if(t!=i){
        swap(p[i],p[t]);
        swap(h[i],h[t]);
        // swap(ph[h[i]],ph[h[t]]);
        upgrade(t);
    }
}
void up(int i)
{
    while(i/2&&p[i/2]>p[i])
    {
        swap(p[i/2],p[i]);
        swap(h[i/2],h[i]);
        i/=2;
    }
}
void insert(int x){
    p[++r]=x;
    h[r]=++cnt;
    up(r);
    upgrade(1);
}
void del(){
    swap(p[1],p[r]);
    swap(h[1],h[r]);
    r--;
    upgrade(1);
}
void del_num(int k){
    int i=1;
    for(;i<=r;i++){
        if(h[i]==k) break;
    }
    if(i>r) return;
    for(;i<r;i++){
        p[i] = p[i+1];
        h[i] = h[i+1];
    }
    r--;
    // swap(p[i],p[r]);
    // swap(h[i],h[r]);
    // r--;
    // upgrade(1);

}
void update(int k,int x){
    int i=1;
    for(;i<=r;i++){
        if(h[i]==k) break;
    }
    if(i>r) return;
    p[i] = x;
}

int main(){
    cin>>n;
    while(n--){
        string s;
        int a,b;
        cin>>s;
        if(s=="I"){
            cin>>a;
            insert(a);
        }else if(s=="PM"){
            cout<<p[1]<<endl;
        }else if(s=="DM"){
            del();
        }else if(s=="D"){
            cin>>a;
            del_num(a);
        }else{
            cin>>a>>b;
            update(a,b);
        }
    }
}