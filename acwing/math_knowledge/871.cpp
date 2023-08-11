#include <iostream>
#include <unordered_map>
using namespace std;

const int mod = 1e9 + 7;

int main()
{
    int n, x;
    long long res = 1;
    cin >> n;
    unordered_map<int, int> hash;
    while (n--)
    {
        cin >> x;
        for (int i = 2; i <= x / i; i++)
        {
            while (x % i == 0)
            {
                x=x/i;
                hash[i]++;
            }
        }
        if (x > 1)
            hash[x]++;
       
    }
    for (auto i : hash)
    {

        if (i.second)
        {
            long long ans = 1;
            int a = i.first;
            int b = i.second;
            while (b--)
            {
                ans = (ans * a + 1)%mod;
            }
            res =res* ans%mod;
        }
    }

    cout << res;
    return 0;
}