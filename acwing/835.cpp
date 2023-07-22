// Trie 树
#include<iostream>
using namespace std;
const int N = 1e5+10;

int q[N][26],idx,cnt[N];
void fun_I(string c){
    int h=0;
    for(int i=0;i<c.size();i++){
        int x = c[i]-'a';
        if(q[h][x]==0){
            q[h][x] = ++idx;
        }
        h = q[h][x];
    }
    cnt[h]++;
}
int fun_Q(string c){
    int h=0;
    for(int i=0;i<c.size();i++){
        int x = c[i]-'a';
        if(q[h][x]==0){
            return 0;
        }
        h = q[h][x];
    }
    return cnt[h];
}
int main(){
    int n;
    cin>>n;
    char i;
    string x;
    while(n--){
        cin>>i>>x;
        if(i=='I'){
            fun_I(x);
        }else{
            cout<<fun_Q(x)<<endl;
        }

    }
    return 0;
}