#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n),b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    vector<pl> p;
    rep(i,n) p.push_back({a[i]-b[i],i});
    sort(all(p));
    ll cnt=0,idx=n-1;
    for(int i=0;i<n;i++) {
        if(p[i].first>=0) continue;
        cnt++;
        while(idx>i) {
            if(-p[i].first<=p[idx].first) {
                if(a[p[idx].second]-b[p[idx].second]==p[idx].first) cnt++;
                p[idx].first+=p[i].first;
                p[i].first=0;
                break;
            } else {
                if(a[p[idx].second]-b[p[idx].second]==p[idx].first) cnt++;
                p[i].first+=p[idx].first;
                p[idx].first=0;
                idx--;
            }
        }
        if(p[i].first<0) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << cnt << endl;
    return 0;
}