// 2023年7月24日 19点28分
#include<iostream>
using namespace std;
const int N = 2e5+10;
int p[N];
int n,m;
int get(int x){
    if(x==p[x]) return x;
    return p[x] = get(p[x]);
}
void merge(int x,int y){
    p[get(x)] = get(y);
}
int main(){
    cin>>n>>m;
    for(int i=1;i<3*n;i++){
        p[i] = i;
    }
    int k,x,y,ans=0;
    for(int i=1;i<=m;i++){
        cin>>k>>x>>y;
        if(x>n || y>n) ans++;
        else if(k==1){
            if(get(x)==get(y+n)||get(x)==get(y+n+n)) ans++;
            else{
                merge(x,y);
                merge(x+n,y+n);
                merge(x+n+n,y+n+n);
            }
        }
        else{
            if(x==y||get(x)==get(y)||get(x)==get(y+n)) ans++;
            else{
                merge(x,y+n+n);
                merge(x+n,y);
                merge(x+n+n,y+n); // ABC构成食物链循环，a吃b，b吃c，那么c一定要吃a
            }
        }
    }
    cout<<ans;
}
