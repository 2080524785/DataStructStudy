// 2023年7月22日 21点18分
// 合并集合
#include<iostream>
using namespace std;
const int N = 1e5+10;
int p[N];

int find(int x){
    if(x!=p[x]) p[x] = find(p[x]);
    return p[x];
}
void merge(int a,int b){
    int pa = find(a),pb = find(b);
    if(pa!=pb){
        p[pa] = pb;
    }
}
void query(int a,int b){
    int pa = find(a),pb = find(b);
    cout<<(pa==pb?"Yes":"No")<<endl;
}

int main(){
    int n,m;
    cin>>n>>m;
    char c;
    int a,b;
    for(int i=1;i<=n;i++) p[i]=i;
    while(m--){
        cin>>c>>a>>b;
        if(c=='M'){
            merge(a,b);
        }else{
            query(a,b);
        }
    }
    return 0;
}