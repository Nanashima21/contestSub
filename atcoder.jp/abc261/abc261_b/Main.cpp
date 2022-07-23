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
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    bool flag=true;
    rep(i,n) rep(j,n) {
        if(i==j) continue;
        if(s[i][j]=='W'&&s[j][i]!='L') flag=false; 
        if(s[i][j]=='L'&&s[j][i]!='W') flag=false; 
        if(s[i][j]=='D'&&s[j][i]!='D') flag=false; 
    }
    cout << (flag ? "correct" : "incorrect") << endl;
    return 0;
}