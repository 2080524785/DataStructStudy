// 2023年8月2日 13点13分
#include<iostream>
#include<queue>
#include<cstring>
#include <unordered_map>
using namespace std;
typedef pair<int,int> PII;
typedef pair<string,int> PSI;
queue<string> q;
unordered_map<string,int> h;
void bfs(string s){
    int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
    h[s]=0;
    q.push(s);
    while(!q.empty()){
        string t = q.front();
        q.pop();
        if(t == "12345678x"){
            cout<<h[t]<<endl;
            return;
        }
        int pos = t.find('x');
        int a = pos/3,b = pos%3;
        int dis = h[t];
        for(int i=0;i<4;i++){
            int x = a+dx[i],y= b+dy[i];
            if(x>=0&&x<=2&&y>=0&&y<=2){
                swap(t[pos],t[3*x+y]);
                if(h.find(t)==h.end()){
                    h[t] = dis+1;
                    q.push(t);
                }
                swap(t[pos],t[3*x+y]);
            }
        }

    }
    cout<<-1;
    return;

}

int main(){
    char c;
    string s="";
    for(int i=1;i<=9;i++){
        cin>>c;
        s+=c;
    }

    bfs(s);

}