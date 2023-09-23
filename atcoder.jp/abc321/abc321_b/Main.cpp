#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,x;
    cin >> n >> x;
    vector<ll> a(n-1);
    rep(i,n-1) cin >> a[i];
    rep(i,101) {
        vector<ll> na=a;
        na.push_back(i);
        sort(all(na));
        ll tot=0;
        for(int j=1;j<n-1;j++) tot+=na[j];
        if(tot>=x) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}