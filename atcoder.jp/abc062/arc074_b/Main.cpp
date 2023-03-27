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
    vector<ll> v1(n),v2(n),v3(n);
    rep(i,n) cin >> v1[i];
    rep(i,n) cin >> v2[i];
    rep(i,n) cin >> v3[i];
    ll ltot=0;
    priority_queue<ll,vector<ll>,greater<ll>> pql;
    rep(i,n) {
        ltot+=v1[i];
        pql.push(v1[i]);
    }
    vector<ll> l(n+1);
    l[0]=ltot;
    rep(i,n) {
        if(pql.top()<v2[i]) {
            ltot=ltot-pql.top()+v2[i];
            pql.pop();
            pql.push(v2[i]);
        }
        l[i+1]=ltot;
    }

    ll rtot=0;
    priority_queue<ll,vector<ll>> pqr;
    rep(i,n) {
        rtot+=v3[i];
        pqr.push(v3[i]);
    }
    vector<ll> r(n+1);
    r[n]=rtot;
    for(int i=n-1;i>=0;i--) {
        if(pqr.top()>v2[i]) {
            rtot=rtot-pqr.top()+v2[i];
            pqr.pop();
            pqr.push(v2[i]);
        }
        r[i]=rtot;
    }

    /*
    rep(i,(int)l.size()) {
        if(i) cout << " ";
        cout << l[i];
    } cout << endl;
    rep(i,(int)r.size()) {
        if(i) cout << " ";
        cout << r[i];
    } cout << endl;
    */

    ll ans=-INF;
    rep(i,n+1) ans=max(ans,l[i]-r[i]);
    cout << ans << endl; 
    return 0; 
}