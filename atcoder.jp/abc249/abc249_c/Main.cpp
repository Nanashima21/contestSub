#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,k;
    cin >> n >> k;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    ll ans=0;
    rep(i,1<<n) {
        map<char,int> mp;
        rep(j,n) {
            if(i>>j&1) {
                for(char c:s[j]) mp[c]++;
            }
        }  
        ll cnt=0;
        for(auto u:mp) if(u.second==k) cnt++;
        ans=max(ans,cnt);
    }
    cout << ans << endl;
    return 0;
}

