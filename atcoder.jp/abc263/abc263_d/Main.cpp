#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,l,r;
    cin >> n >> l >> r;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> lv(n),rv(n),lmi(n),rmi(n);
    rep(i,n) {
        if(a[i]>=l) lmi[i]=l;
        else lmi[i]=a[i];
    }
    for(int i=n-1;i>=0;i--) {
        if(a[i]>=r) rmi[i]=r;
        else rmi[i]=a[i];
    }
    for(int i=1;i<n;i++) lmi[i]=min(lmi[i-1]+a[i],(i+1)*l);
    for(int i=n-2;i>=0;i--) rmi[i]=min(rmi[i+1]+a[i],(n-i)*r); 
    ll mi=min(lmi[n-1],rmi[0]);
    rep(i,n-1) mi=min(mi,lmi[i]+rmi[i+1]);
    cout << mi << endl;
    return 0;
}