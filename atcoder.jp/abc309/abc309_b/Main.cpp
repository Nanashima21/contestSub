#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define INF ((1LL << 62) - (1LL << 31))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
typedef long long ll;
typedef pair<ll, ll> pl;

int main()
{
    int n;
    cin >> n;
    vector<string> a(n);
    rep(i, n) cin >> a[i];
    cout << a[1][0];
    rep(i, n - 1) cout << a[0][i];
    cout << endl;
    for (int i = 1; i < n - 1; i++)
    {
        cout << a[i + 1][0];
        for (int j = 1; j < n - 1; j++)
        {
            cout << a[i][j];
        }
        cout << a[i - 1][n - 1];
        cout << endl;
    }
    rep(i, n - 1) cout << a[n - 1][i + 1];
    cout << a[n - 2][n - 1] << endl;
    return 0;
}