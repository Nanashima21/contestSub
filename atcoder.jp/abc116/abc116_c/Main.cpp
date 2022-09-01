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
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    int ma=h[0],ans=0;
    for(int i=1;i<n;i++) {
        if(ma>h[i]) {
            ans+=ma-h[i];
            ma=h[i];
        } else ma=max(ma,h[i]);
    }
    ans+=ma;
    cout << ans << endl;
    return 0;
}