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
    ll n, k;
    cin >> n >> k;
    map<ll, ll> mp;
    mp[1] = 0;
    rep(i, n)
    {
        ll a, b;
        cin >> a >> b;
        mp[a] += b;
    }
    vector<pl> p;
    for (auto u : mp)
        p.push_back({u.first, u.second});
    for (int i = (int)p.size() - 2; i >= 0; i--)
        p[i].second += p[i + 1].second;
    for (int i = 0; i < (int)p.size(); i++)
    {
        if (p[i].second <= k)
        {
            cout << p[i - 1].first + 1 << endl;
            return 0;
        }
    }
    cout << p.back().first + 1 << endl;
    return 0;
}