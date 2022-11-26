#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    string s,t;
    cin >> s >> t;
    bool flag=false;
    if(s==t) flag=true;
    rep(i,(int)s.size()-(int)t.size()+1) {
        if(s.substr(i,(int)t.size())==t) flag=true;
    }
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}