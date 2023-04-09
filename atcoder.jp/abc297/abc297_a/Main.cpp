#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,d;
    cin >> n >> d;
    vector<ll> t(n);
    rep(i,n) cin >> t[i];
    bool flag=false;
    for(int i=1;i<n;i++) {
        if(t[i]-t[i-1]<=d) {
            cout << t[i] << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}