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
    vector<ll> a(7*n);
    rep(i,7*n) cin >> a[i];
    rep(i,n) {
        ll tot=0;
        for(int j=0;j<7;j++) tot+=a[i*7+j];
        if(i) cout << " ";
        cout << tot;
    }
    return 0;
}