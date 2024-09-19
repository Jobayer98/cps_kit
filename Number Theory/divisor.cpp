#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define fraction cout << fixed << setprecision(5)
#define array_size(ar) (sizeof(ar) / sizeof(*(ar)))

// Constants
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;
const int mx = 2e5 + 123;

int cnt[mx];

// square root method time complexity is O(sqrt(n))
void square_root(int n)
{
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
            if (n / i != i)
                cnt[n] += 2;
            else
                cnt[n]++;
    }
}

// approach 2 -> time comlexit is O(ln(n))
void divisors(int i, int n)
{
    for (int j = i; j <= n; j += i)
    {
        cnt[j]++;
    }
}

int main()
{
    fastio;
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        // square_root(i);
        divisors(i, n);
    }

    for (int i = 1; i <= n; i++)
        cout << i << " " << cnt[i] << endl;

    return 0;
}