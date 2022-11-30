#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

const ll mod=1000000007;

int main() {
    int n; string s;
    cin >> n >> s;
    set<string> se;
    rep(i,n) {
        string t;
        cin >> t;
        se.insert(t);
    }
    vector<ll> dp((int)s.size()+1,0);
    dp[0]=1;
    for(int i=1;i<=(int)s.size();i++) {
        for(int j=1;j<=i;j++) {
            if(se.find(s.substr(j-1,i-j+1))!=se.end()) dp[i]=(dp[i]+dp[j-1])%mod;
        }
    }
    
    cout << dp[(int)s.size()] << endl;
    return 0;
}