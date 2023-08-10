#include <iostream>
using namespace std;

int n, x;

int main()
{
    cin >> n;
    while (n--)
    {
        cin >> x;
        for (int i = 2; i <= x / i; i++)
        {
            if (x % i == 0)
            {
                int s = 0;
                while (x % i == 0)
                {
                    x = x / i;
                    s++;
                }
                cout << i << " " << s << endl;
            }
        }
        if (x > 1)
            cout << x << " " << 1 << endl;
        cout << endl;
    }
    return 0;
}