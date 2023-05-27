#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n; string s,t;
    cin >> n >> s >> t;
    bool flag=true;
    rep(i,n) {
        if(s[i]!=t[i]) {
            if(s[i]=='l'&&t[i]=='1') continue;
            if(s[i]=='1'&&t[i]=='l') continue;
            if(s[i]=='o'&&t[i]=='0') continue;
            if(s[i]=='0'&&t[i]=='o') continue;
            flag=false;
        }
    }
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}