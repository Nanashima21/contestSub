#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,p,q,s;
    cin >> n >> p >> q >> s;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> rtot(n+1);
    rep(i,n) rtot[i+1]=a[i]+rtot[i];
    int l=0;
    for(int r=1;r<n+1;r++) {
        while(rtot[r]-rtot[l]>p+q+s) l++;
        if(rtot[r]-rtot[l]==p+q+s) {
            if(r-l>=2) {
                if(!binary_search(all(rtot),rtot[l]+p)) continue;
                if(!binary_search(all(rtot),rtot[r]-s)) continue;
                cout << "Yes" << endl;
                return 0;
            } 
        }
    }
    cout << "No" << endl;
    return 0;
}