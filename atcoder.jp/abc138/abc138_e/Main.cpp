#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    string s,t;
    cin >> s >> t;
    set<char> se;
    for(char c:s) se.insert(c);
    for(char c:t) if(se.count(c)==0) {
        cout << -1 << endl;
        return 0;
    }
    vector<vector<int>> v(26,vector<int> ());
    rep(i,(int)s.size()) v[s[i]-'a'].push_back(i+1);
    ll pre=0,cnt=0;
    rep(i,(int)t.size()) {
        auto it=upper_bound(all(v[t[i]-'a']),pre);
        if(it==v[t[i]-'a'].end()) {
            cnt++;
            pre=v[t[i]-'a'][0];
        } else pre=v[t[i]-'a'][it-v[t[i]-'a'].begin()]; 
    }
    cout << pre+cnt*(ll)s.size() << endl;
    return 0;
}