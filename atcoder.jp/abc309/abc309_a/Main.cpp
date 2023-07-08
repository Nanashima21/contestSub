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
    int a, b;
    cin >> a >> b;
    bool flag = false;
    if (a == 1 && b == 2)
        flag = true;
    if (a == 2 && b == 3)
        flag = true;
    if (a == 4 && b == 5)
        flag = true;
    if (a == 5 && b == 6)
        flag = true;
    if (a == 7 && b == 8)
        flag = true;
    if (a == 8 && b == 9)
        flag = true;
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}