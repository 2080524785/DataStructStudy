// 2023年7月23日 18点18分
// 连通块中点的数量
#include<iostream>
using namespace std;
const int N = 1e5+10;
int p[N],size[N];
int n,m;
int find(int x){
    if(x!=p[x]) p[x] = find(p[x]);
    return p[x];
}
void merge(int a,int b){
    int pa = find(a),pb = find(b);
    if(pa!=pb){
        p[pa] = pb;
        size[pb]+=size[pa];
    }
}
void query(int a,int b){
    cout<<(find(a)==find(b)?"Yes":"No")<<endl;
}
void init(){
    for(int i=1;i<=n;i++) p[i]=i,size[i]=1;
}


int main(){
    
    cin>>n>>m;
    string c;
    int a,b;
    init();
    while(m--){
        cin>>c;
        if(c=="C"){
            cin>>a>>b;
            merge(a,b);
        }
        else if(c=="Q2"){
            cin>>a;
            cout<<size[find(a)];
        }
        else{
            cin>>a>>b;
            query(a,b);
        }
    }
    return 0;
}