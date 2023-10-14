#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n; string t;
    cin >> n >> t;
    ll m=(int)t.size();
    vector<int> ans;
    rep(i,n) {
        string s;
        cin >> s;
        ll l=(int)s.size();
        if(abs(l-m)>1) continue;
        if(m==l) {
            int cnt=0;
            rep(j,m) if(t[j]!=s[j]) cnt++;
            if(cnt<2) ans.push_back(i+1);
        } else {
            int ll=0,rr=l;
            while(t[ll]==s[ll]) ll++;
            if(m<l) {
                while(t[rr-1]==s[rr]) rr--;
                if(ll>=rr) ans.push_back(i+1);
            } else {
                while(t[rr+1]==s[rr]) rr--;
                if(ll>rr) ans.push_back(i+1);
            }
            //cout << i+1<< " " << ll << " " << rr << endl;
        }
    }
    cout << (int)ans.size() << endl;
    rep(i,(int)ans.size()) {
        if(i) cout << " ";
        cout << ans[i];
    } cout << endl;
    return 0;
}