#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n;
    cin >> n;
    map<string,int> mp;
    rep(i,n) {
        string s;
        cin >> s;
        if(mp[s]==0) cout << s << endl;
        else cout << s << "(" << mp[s] << ")" << endl;
        mp[s]++;
    }
    return 0;
}