#include<iostream>
using namespace std;
const int N = 100010;
int idx; // 各个节点的编号，根节点编号为0
int son[N][26];//Trie 树本身
//cnt[x] 表示：以 编号为 x 为结尾的字符串的个数
int cnt[N];

int n;

void insert(string s){
    int p = 0;//指向根节点
    for(int i = 0; i < s.size(); i++){
        //将当前字符转换成数字（a->0, b->1,...）
        int u = s[i] - 'a';
        //如果数中不能走到当前字符
        //为当前字符创建新的节点，保存该字符
        if(!son[p][u])
            // 新节点编号为 idx + 1
            son[p][u] = ++idx;
        p = son[p][u];
    }
    //这个时候，p 等于字符串 s 的尾字符所对应的 idx
    //cnt[p] 保存的是字符串 s 出现的次数
    //故 cnt[p] ++
    cnt[p] ++;
}

int query(string s){
    int p = 0;//指向根节点
    for(int i = 0; i < s.size(); i++){
        //将当前字符转换成数字（a->0, b->1,...）
        int u = s[i] - 'a';
        //如果走不通了，即树中没有保存当前字符
        //则说明树中不存在该字符串
        if(!son[p][u]) 
            return 0;
        //指向下一个节点
        p = son[p][u];
    }
    //循环结束的时候，p 等于字符串 s 的尾字符所对应的 idx
    // cnt[p] 就是字符串 s 出现的次数
    return cnt[p];
}

int main(){
    cin >> n;
    string s;
    char q;
    while(n--){
        cin >> q >> s;
        if(q == 'I'){
            //插入操作
            insert(s);
        }
        else{
            //查询操作
            cout << query(s) << endl;
        }
    }
}