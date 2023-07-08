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
    ll n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>());
    rep(i, n - 1)
    {
        int p;
        cin >> p;
        g[p - 1].push_back(i + 1);
    }
    vector<int> cnt(n, 0);
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        cnt[a - 1] = max(cnt[a - 1], b + 1);
    }
    queue<int> que;
    que.push(0);
    while (!que.empty())
    {
        int cv = que.front();
        que.pop();
        for (auto nv : g[cv])
        {
            cnt[nv] = max(cnt[nv], cnt[cv] - 1);
            que.push(nv);
        }
    }
    ll ans = 0;
    rep(i, n)
    {
        if (cnt[i] > 0)
            ans++;
    }
    cout << ans << endl;
    return 0;
}