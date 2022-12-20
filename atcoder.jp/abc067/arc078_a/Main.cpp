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
    vector<ll> a(n);
    ll tot=0;
    rep(i,n) {
        cin >> a[i];
        tot+=a[i];
    }
    ll sum=a[0],ans=INF;
    for(int i=1;i<n;i++) {
        ans=min(ans,abs(tot-sum*2));
        sum+=a[i];
    }
    cout << ans << endl;
    return 0;
}