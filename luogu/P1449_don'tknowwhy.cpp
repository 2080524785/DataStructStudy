#include<bits/stdc++.h>
#include <string>
#include <stack>
using namespace std;

int main() {
    string str;
    char s;
    double num=0;
    stack<double> c;
    cin >> str;
    for (char s : str) {
        if (s == '@') {
            break;
        }
        if (s != '.') {
            if (s >= '0' && s <= '9') {
                num = num * 10 + int(s-'0');
            }
            else {
                double j = c.top(); c.pop();
                double i = c.top(); c.pop();
                if (s == '+') {
                    c.push(i + j);
                }
                else if (s == '-') {
                    c.push(i - j);
                }
                else if (s == '*') {
                    c.push(i * j);
                }
                else if (s == '/') {
                    c.push(i / j);
                }
            }
        }
        else {
            c.push(num);
            num = 0;
        }
    }
    cout << c.top();
    return 0;
}