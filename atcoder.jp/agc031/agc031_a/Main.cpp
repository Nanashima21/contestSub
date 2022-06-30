#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

const ll mod=1000000007;

int main() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    map<char,ll> mp;
    rep(i,n) mp[s[i]]++; 
    ll ans=1;
    for(auto u:mp) ans=(ans*(u.second+1))%mod;
    cout << (ans-1+mod)%mod << endl;
    return 0;
}