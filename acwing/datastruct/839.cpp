// 2023年7月25日 21点30分
#include<iostream>
using namespace std;
const int N=10;
int p[N],h[N],ph[N];
int n,r=0,cnt=0;
void heap_swap(int a,int b){
    swap(ph[h[a]],ph[h[b]]);
    swap(p[a],p[b]);
    swap(h[a],h[b]);
}
void down(int i){
    int t = i;
    if(2*i<=r&&p[2*i]<p[i]) t = 2*i;
    if(2*i+1<=r&&p[t]>p[2*i+1]) t = 2*i+1;
    if(t!=i){
        heap_swap(t,i);
        down(t);
    }
}

void up(int i)
{
    while(i/2&&p[i/2]>p[i])
    {
        heap_swap(i/2,i);
        i/=2;
    }
}
void insert(int x){
    ph[++cnt] = ++r;
    h[r] = cnt;
    p[r] = x;
    up(r);
}
void del(){
    heap_swap(1,r);
    r--;
    down(1);
}
void del_num(int k){
    k = ph[k];
    heap_swap(k,r);
    r--;
    up(k);
    down(k);
    // swap(p[i],p[r]);
    // swap(h[i],h[r]);
    // r--;
    // upgrade(1);

}
void update(int k,int x){
    k = ph[k];
    p[k] = x;
    up(k);
    down(k);

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