#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,p,q,r,s;
    cin >> n >> p >> q >> r >> s;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    p--; q--; r--; s--;
    rep(i,n) {
        if(i) cout << " ";
        if(p<=i&&i<=q) cout << a[r+i-p];
        else if(r<=i&&i<=s) cout << a[p+i-r];
        else cout << a[i];
    }
    cout << endl;
    return 0;
}
