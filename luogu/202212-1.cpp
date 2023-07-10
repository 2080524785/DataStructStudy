#include<bits/stdc++.h>
#include <iomanip>
using namespace std;

int main() {
    double n, p;
    cin >> n >> p;
    double k = 0, a = 1;
    double sum = 0;
    for (int i = 0; i <= n; i++) {
        cin >> k;
        sum += double(k) / double(a);
        a = a * (1 + p);
    }
    cout<< setiosflags(ios::fixed) << setprecision(3) << sum << endl;
    return 0;
}