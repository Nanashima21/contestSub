#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> rtot(n+1);
    for(int i=1;i<=n;i++) rtot[i]=rtot[i-1]+a[i-1];  
    int l=0;
    ll tot=0;
    for(int i=0;i<m;i++) tot+=a[i]*(i+1);
    ll ma=tot;
    for(int r=m;r<n;r++) {
        tot-=rtot[r]-rtot[l++];
        tot+=a[r]*m;
        ma=max(ma,tot);
    }
    cout << ma << endl;
    return 0;
}