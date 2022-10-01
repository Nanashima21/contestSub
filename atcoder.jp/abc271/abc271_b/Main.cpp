#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,q;
    cin >> n >> q;
    vector<int> l(n);
    vector<vector<ll>> a(n);
    rep(i,n) {
        cin >> l[i];
        rep(j,l[i]) {
            ll b;
            cin >> b;
            a[i].push_back(b);
        }
    }
    rep(i,q) {
        int s,t;
        cin >> s >> t;
        s--; t--;
        cout << a[s][t] << endl;
    }
    return 0;
}