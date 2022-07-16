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
    cout << 2*n << endl;
    string s;
    rep(i,n/4) s+='4';
    if(n%4!=0) s+=to_string(n%4);
    reverse(all(s));
    cout << s << endl;
    return 0;
}