#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n; string s;
    cin >> n >> s;
    vector<ll> v;
    for(ll i=0;i*i<=pow(10,n);i++) {
        v.push_back(i*i);
    }
    ll ans=0;
    sort(all(s));
    for(auto u:v) {
        string str=to_string(u);
        int m=(int)str.size();
        rep(i,n-m) str+='0';
        sort(all(str));
        if(str==s) ans++;
    }
    cout << ans << endl;
    return 0;
}