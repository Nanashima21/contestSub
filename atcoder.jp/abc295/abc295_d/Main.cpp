#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    string s;
    cin >> s;
    int n=(int)s.size();
    map<string,ll> mp;
    mp["0000000000"]++;
    vector<ll> rxor(10,0);
    ll ans=0;
    for(int i=1;i<=n;i++) {
        string str;
        rxor[s[i-1]-'0']^=1;
        rep(j,10) str+=to_string(rxor[j]);
        ans+=mp[str];
        mp[str]++;
    }
    cout << ans << endl;
    return 0;
}