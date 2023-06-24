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
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    bool flag=false;
    rep(i,n) rep(j,n) {
        if(i==j) continue;
        string str=s[i]+s[j];
        string rstr=str;
        reverse(all(rstr));
        if(str==rstr) flag=true;
    }
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}