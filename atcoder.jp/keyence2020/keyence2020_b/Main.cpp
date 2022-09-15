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
    vector<ll> x(n),l(n);
    vector<pl> p;
    rep(i,n) {
        cin >> x[i] >> l[i];
        p.push_back({x[i]-l[i],x[i]+l[i]});
    }
    sort(rall(p));
    int cnt=1;
    ll lst=p[0].first;
    for(int i=1;i<n;i++) {
        if(lst>=p[i].second) {
            lst=p[i].first;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}