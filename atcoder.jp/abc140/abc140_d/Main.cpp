#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

vector<pair<char,int>> runlength(string s) {
    int x=s.size();
    vector<pair<char,int>> res;
    char pre=s[0];
    int cnt=1;
    for(int i=1;i<x;i++) {
        if(pre!=s[i]) {
            res.push_back({pre,cnt});
            pre=s[i]; cnt=1;
        } else cnt++;
    }
    res.push_back({pre,cnt});
    return res;
    //auto rl=runlength(s)
}

int main() {
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    auto rl=runlength(s);
    ll ans=-1;
    for(int i=0;i<=min(2*k,(int)rl.size()-1);i++) ans+=rl[i].second;
    for(int i=2*k+1;i<(int)rl.size();i++) ans+=rl[i].second-1;
    if((int)rl.size()==1) ans=n-1;
    cout << ans << endl;
    return 0;
}