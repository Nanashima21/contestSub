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
    ll n1, n2, m;
    cin >> n1 >> n2 >> m;
    vector<vector<int>> g1(n1, vector<int>());
    vector<vector<int>> g2(n2, vector<int>());
    rep(i, m)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (u >= n1)
        {
            u -= n1;
            v -= n1;
            g2[u].push_back(v);
            g2[v].push_back(u);
        }
        else
        {
            g1[u].push_back(v);
            g1[v].push_back(u);
        }
    }

    queue<int> que;
    vector<ll> dist1(n1, INF);
    dist1[0] = 0;
    que.push(0);
    while (!que.empty())
    {
        int cv = que.front();
        que.pop();
        for (auto nv : g1[cv])
        {
            if (dist1[nv] != INF)
                continue;
            dist1[nv] = dist1[cv] + 1;
            que.push(nv);
        }
    }
    vector<ll> dist2(n2, INF);
    dist2[n2 - 1] = 0;
    que.push(n2 - 1);
    while (!que.empty())
    {
        int cv = que.front();
        que.pop();
        for (auto nv : g2[cv])
        {
            if (dist2[nv] != INF)
                continue;
            dist2[nv] = dist2[cv] + 1;
            que.push(nv);
        }
    }
    cout << *max_element(all(dist1)) + *max_element(all(dist2)) + 1 << endl;
    return 0;
}