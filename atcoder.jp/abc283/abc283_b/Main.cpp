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
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    int q;
    cin >> q;
    while(q--) {
        ll t,k,x;
        cin >> t >> k;
        k--;
        if(t==1) {
            cin >> x;
            a[k]=x;
        } else cout << a[k] << "\n";
    }
    return 0;
}