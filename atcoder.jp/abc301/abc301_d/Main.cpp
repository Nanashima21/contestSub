#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    string s; ll n;
    cin >> s >> n;
    string t;
    reverse(all(s));
    ll m=(ll)s.size();
    ll tot=0;
    rep(i,m) if(s[i]=='1') tot+=1LL<<i;
    if(tot>n) {
        cout << -1 << endl;
        return 0;
    } 
    reverse(all(s));
    rep(i,m) {
        if(s[i]=='?'&&tot+(1LL<<(m-i-1))<=n) tot+=(1LL<<(m-i-1));
    }
    cout << tot << endl;
    return 0;
}