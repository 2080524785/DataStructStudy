#include <iostream>
#include <unordered_map>

using namespace std;

const int mod = 1e9 + 7;

int main()
{
    int n, x;
    long long ans = 1;
    unordered_map<int, int> hash;
    cin >> n;
    while (n--)
    {
        cin >> x;
        for (int i = 2; i <= x / i; i++)
        {
            while (x % i == 0)
            {
                x /= i;
                hash[i]++;
            }
        }
        if (x > 1)
            hash[x]++;
    }
    for (auto i : hash)
        ans = ans * (i.second + 1) % mod;
    cout << ans;
    return 0;
}