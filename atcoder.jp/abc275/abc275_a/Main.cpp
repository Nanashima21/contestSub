#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    vector<pl> p;
    rep(i,n) {
        cin >> h[i];
        p.push_back({h[i],i});
    }
    sort(rall(p));
    cout << p[0].second+1 << endl;
    return 0;
}