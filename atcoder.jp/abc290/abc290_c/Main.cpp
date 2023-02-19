#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,k;
    cin >> n >> k; 
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> cnt(300300,0);
    rep(i,n) if(a[i]<300300) cnt[a[i]]++;
    ll ans=k;
    rep(i,300300) if(cnt[i]==0) ans=min(ans,1LL*i);
    cout << ans << endl; 
    return 0;
}