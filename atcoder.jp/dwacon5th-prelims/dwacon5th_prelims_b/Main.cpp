#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> tot(n+1,0);
    rep(i,n) tot[i+1]=tot[i]+a[i];
    vector<ll> vec;
    for(int l=0;l<n+1;l++) {
        for(int r=l+1;r<n+1;r++) {
            vec.push_back(tot[r]-tot[l]);
        }
    } 
    ll ans=0;
    for(int i=60;i>=0;i--) {
        ll bit=1LL<<i;
        vector<ll> tmp;
        for(auto u:vec) if(u&bit) tmp.push_back(u);
        if((int)tmp.size()<k) continue;
        ans+=bit;
        swap(vec,tmp);
    }
    cout << ans << endl;  
    return 0;
}