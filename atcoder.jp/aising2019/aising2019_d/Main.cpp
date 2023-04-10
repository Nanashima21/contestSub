#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,q;
    cin >> n >> q;
    vector<ll> a(n),tot(n+1,0),tot2(n+1,0);
    rep(i,n) cin >> a[i];
    rep(i,n) {
        tot[i+1]=tot[i]+a[i];
        tot2[i+1]=tot2[i]+a[i]*((n^i)&1);
    }
    while(q--) {
        ll x;
        cin >> x;
        int ok=1,ng=(n+1)/2+1;
        while(ng-ok>1) {
            int mid=(ok+ng)/2;
            int ok2=n-2,ng2=mid-3;
            while(ok2-ng2>1) {
                int mid2=(ok2+ng2)/2;
                if(x-a[mid2-mid+2]>a[mid2+1]-x) ng2=mid2;
                else ok2=mid2;
            }
            if(n-mid>ok2) ok=mid;
            else ng=mid;
        }
        cout << tot[n]-tot[n-ok]+tot2[n-ok*2+1] << '\n';
    }
    return 0;
}