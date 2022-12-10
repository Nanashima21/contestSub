#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,t;
    cin >> n >> t;
    vector<ll> a(n);
    ll tot=0;
    rep(i,n) {
        cin >> a[i];
        tot+=a[i];
    }
    
    t%=tot;
    int idx=0;
    while(t>0) {
        if(t-a[idx]<=0) {
            cout << idx+1 << " " << t << endl;
            return 0;
        } else t-=a[idx];
        idx++;
    }
    return 0;
}