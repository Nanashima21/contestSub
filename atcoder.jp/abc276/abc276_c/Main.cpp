#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n;
    cin >> n;
    vector<ll> p(n);
    rep(i,n) cin >> p[i];
    int idx=n-2;
    while(idx>=0) {
        if(p[idx]<p[idx+1]) idx--;
        else break;
    }
    vector<ll> ans,v;
    rep(i,n) {
        if(i<idx) ans.push_back(p[i]);
        else v.push_back(p[i]);
    }
    rep(i,(int)ans.size()) {
        if(i) cout << " ";
        cout << ans[i];
    } 
    sort(rall(v));
    ll b=0;
    rep(i,(int)v.size()) {
        if(p[idx]==v[i]) {
            if((int)ans.size()) cout << " ";
            cout << v[i+1];
            b=v[i+1];
        }
    }
    rep(i,(int)v.size()) {
        if(v[i]!=b) cout << " " << v[i];
    } cout << endl;
    return 0;
}