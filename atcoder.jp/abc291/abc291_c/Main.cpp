#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n; string s;
    cin >> n >> s;
    set<pair<int,int>> se;
    int x=0,y=0;
    se.insert({0,0});
    rep(i,n) {
        if(s[i]=='L') x--;
        if(s[i]=='R') x++;
        if(s[i]=='U') y--;
        if(s[i]=='D') y++;
        if(se.find({x,y})!=se.end()) {
            cout << "Yes" << endl;
            return 0;
        } else se.insert({x,y});
    } cout << "No" << endl;
    return 0;
}