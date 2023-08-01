#include<iostream>
#include<unordered_map>
#include<stack>

using namespace std;

//存储运算数 运算符
stack<int> num;
stack<char> op;
//建立映射来判断运算优先级
unordered_map<char, int> cmp = {
    {'+', 1}, {'-', 1} , {'*', 2}, {'/', 2}
};
//模拟一次算术操作
void eval(void){
    int b = num.top();  num.pop();
    int a = num.top();  num.pop();
    char opr = op.top();    op.pop();

    int x;
    if(opr == '+')  x = a + b;
    else if(opr == '-') x = a - b;
    else if(opr == '*') x= a * b;
    else    x = a / b;
    num.push(x);
}

int main(){
    ios::sync_with_stdio(false);
    string str;
    cin >> str;

    for(int i = 0; i < str.size(); i++){
        char c = str[i];
        //读入运算数
        if(isdigit(c)){
            int j = i, x = 0;
            while( j < str.size() && isdigit(str[j])){
                //j++ 迭代不能忘 
                x = x *  10 + str[j ++] - '0';
            }
            num.push(x);
            //由于每轮循环有i++,我们需要倒指向最后一个数字
            i = j - 1;
        }else if( c == '(' ){
            //标记一下，括号内数据
            op.push(c);
        }else if( c == ')' ){
            //括号的优先级，先算括号
            while( op.size() && op.top() != '(' )   eval();
            //左括号可以弹出
            op.pop();
        }else{
            //得先把乘除法算了再算加减
            //这里必须得带等于号 我们这题都是正整数计算
            // 0 - 5 + 3 
            //如果不算，上式会被错误计算成 -8
            while( op.size() && cmp[op.top()] >= cmp[c])    eval();
            //压入新运算符
            op.push(c);
        }
    }
    //清理低优先级操作
    while(op.size())    eval();
    cout << num.top() << endl;
    return 0;
}

