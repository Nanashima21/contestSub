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
    vector<int> b,k,r;
    rep(i,(int)s.size()) {
        if(s[i]=='B') b.push_back(i);
        if(s[i]=='K') k.push_back(i);
        if(s[i]=='R') r.push_back(i);
    }
    bool flag=true;
    if(b[0]%2==b[1]%2) flag=false;
    if(k[0]<r[0]||r[1]<k[0]) flag=false;
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}