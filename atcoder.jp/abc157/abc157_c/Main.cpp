#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> s(m);
    vector<char> c(m);
    rep(i,m) cin >> s[i] >> c[i];
    if(n==1) {
        bool flag=true;
        rep(i,m) if(c[i]!='0') flag=false;
        if(flag) {
            cout << 0 << endl;
            return 0;
        }
    }
    for(int i=pow(10,n-1);i<pow(10,n);i++) {
        string str=to_string(i);
        bool flag=true;
        rep(j,m) if(str[s[j]-1]!=c[j]) flag=false;
        if(flag) {
            cout << i << endl;
            return 0;
        }
    }  
    cout << -1 << endl;
    return 0;
}