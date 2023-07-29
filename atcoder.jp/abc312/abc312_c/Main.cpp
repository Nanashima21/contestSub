#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n),b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    sort(all(a));
    sort(all(b));
    ll ng=0,ok=INF;
    while(ok-ng>1) {
        ll mid=(ng+ok)/2;
        int cnt1=0,cnt2=0;
        rep(i,n) if(a[i]<=mid) cnt1++;
        rep(j,m) if(b[j]>=mid) cnt2++;
        if(cnt1<cnt2) ng=mid;
        else ok=mid;
    }
    cout << ok << endl;
    return 0;
}