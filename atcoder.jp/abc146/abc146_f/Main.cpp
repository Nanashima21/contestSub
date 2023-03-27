#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,m; string s;
    cin >> n >> m >> s;
    vector<int> v;
    rep(i,n+1) if(s[i]=='0') v.push_back(i);
    int cur=n;
    bool flag=true;
    vector<int> ans;
    while(cur!=0) {
        auto it=lower_bound(all(v),cur-m);
        if(*it==cur) {
            flag=false;
            break;
        } else {
            ans.push_back(cur-*it);
            cur=*it;
        }
    }
    if(!flag) cout << -1 << endl;
    else {
        reverse(all(ans));
        rep(i,(int)ans.size()) {
            if(i) cout << " ";
            cout << ans[i];
        } cout << endl;
    }
    return 0;
}