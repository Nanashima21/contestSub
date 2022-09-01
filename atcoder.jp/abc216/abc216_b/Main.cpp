#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n;
    cin >> n;
    set<pair<string,string>> se;
    bool flag=true;
    rep(i,n) {
        string s,t;
        cin >> s >> t;
        if(se.find({s,t})!=se.end()) flag=false;
        se.insert({s,t});
    }
    cout << (!flag ? "Yes" : "No") << endl;
    return 0;
}