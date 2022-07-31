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
    ll cnt=0;
    rep(i,n) {
        cin >> a[i];
        a[i]--;
        if(a[i]==i) cnt++;
    }
    ll ans=cnt*(cnt-1)/2;
    cnt=0;
    rep(i,n) if(a[i]!=i&&a[a[i]]==i) cnt++;
    ans+=cnt/2;
    cout << ans << endl;
    return 0;
}