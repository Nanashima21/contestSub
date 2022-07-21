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
    vector<int> v(26,0);
    rep(i,n) {
        string s;
        cin >> s;
        if(i==0) {
            for(char c:s) v[c-'a']++;
            continue;
        }
        vector<int> cnt(26,0);
        for(char c:s) cnt[c-'a']++;
        rep(i,26) v[i]=min(v[i],cnt[i]);
    }
    string ans;
    rep(i,26) rep(j,v[i]) ans+=char(i+'a');
    cout << ans << endl; 
    return 0;
}