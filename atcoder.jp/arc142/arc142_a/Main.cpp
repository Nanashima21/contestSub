#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

ll f(string s) {
    ll res=0;
    reverse(all(s));
    rep(i,(int)s.size()) {
        res=res*10+(s[i]-'0');
    }
    return res;
}

int main() {
    ll n; string k;
    cin >> n >> k;
    string s=k;
    reverse(all(s));
    ll a=f(k),b=f(s);
    if(k.back()=='0') {
        cout << 0 << endl;
        return 0;
    } 
    bool flag=true;
    if(b>a) flag=false;
    if(!flag) {
        cout << 0 << endl;
        return 0;
    }
    string t=to_string(a);
    string r=to_string(b);
    set<ll> se;
    ll p10=1;
    rep(i,18-(int)t.size()) {
        if(a*p10<=n) se.insert(a*p10);
        if(b*p10<=n) se.insert(b*p10);
        p10*=10;
    }
    vector<ll> v;
    for(auto u:se) v.push_back(u);
    cout << upper_bound(all(v),n)-v.begin() << endl;
    return 0;
}