#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,m;
    cin >> n >> m;
    if(m==0) {
        rep(i,n) cout << i+1 << " ";
        cout << endl;
        return 0;
    }
    vector<int> a(m);
    rep(i,m) cin >> a[i];
    vector<int> ans,v;
    int idx=0;
    for(int i=1;i<=n;i++) {
        if(a[idx]==i) {
            v.push_back(i);
            idx++;
        } else {
            ans.push_back(i);
            while((int)v.size()>0) {
                ans.push_back(v.back());
                v.pop_back();
            }
        }
    } 
    rep(i,(int)ans.size()) {
        if(i) cout << " ";
        cout << ans[i];
    } cout << endl;
    return 0;
}