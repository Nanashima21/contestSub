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
    ll n=(ll)s.size();
    ll ans=n*(n+1)/2;
    vector<vector<int>> cnt(n,vector<int> (26,0));
    cnt[0][s[0]-'a']++;
    for(int i=1;i<n;i++) {
        rep(j,26) {
            cnt[i][j]=cnt[i-1][j];
            if(j==s[i]-'a') cnt[i][j]++;
        }
    }
    rep(i,n) ans-=cnt[i][s[i]-'a'];
    cout << ans+1 << endl;
    /*
    set<string> se;
    rep(i,n) {
        for(int j=i+1;j<=n;j++) {
            cout << i << " " << j << " "; 
            string str;
            for(int k=0;k<i;k++) str+=s[k];
            for(int k=j-1;k>=i;k--) str+=s[k];
            for(int k=j;k<n;k++) str+=s[k];
            if(se.find(str)==se.end()) {
                cout << str << endl;
                se.insert(str);
            } else cout << "             " << str << endl;
            
        } cout << endl;
    }
    cout << se.size() << endl;*/
    return 0;
}