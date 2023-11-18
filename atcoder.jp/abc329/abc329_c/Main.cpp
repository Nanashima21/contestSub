#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

vector<pair<char,ll>> runlength(string s) {
    int x=s.size();
    vector<pair<char,ll>> res;
    char pre=s[0];
    ll cnt=1;
    for(int i=1;i<x;i++) {
        if(pre!=s[i]) {
            res.push_back({pre,cnt});
            pre=s[i]; cnt=1;
        } else cnt++;
    }
    res.push_back({pre,cnt});
    return res;
    //auto rl=runlength(s)
}

int main() {
    ll n; string s;
    cin >> n >> s;
    auto rl=runlength(s);
    ll cnt=0;
    map<char,ll> mp;
    for(auto u:rl) mp[u.first]=max(mp[u.first],u.second);
    for(auto u:mp) cnt+=u.second;
    cout << cnt << endl;
    return 0;
}