#include<bits/stdc++.h>
using namespace std;
string str_map[]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

int main(){

    string num;
    cin>>num;
    int n=0;
    for(int i=0;i<num.size();i++){
        n+=int(num[i]-'0');
    }
    string str_num =to_string(n);
    string str_r = "";
    for(int i=0;i<str_num.size();i++){
       str_r+=str_map[str_num[i]-'0'];
       if(i<str_num.size()-1){
            str_r+=" ";
        }
    }

    cout<<str_r<<endl;
    return 0;
}