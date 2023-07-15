#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

vector<pair<char,ll>> runlength(string s) {
    int x=s.size();
    vector<pair<char,ll>> res;
    char pre=s[0];
    ll cnt=1;
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
    int n; string s;
    cin >> n >> s;
    auto rl=runlength(s);
    int m=(int)rl.size();
    ll rtot=0;
    vector<ll> tot(m);
    rtot+=rl[0].second;
    if(rl[0].first=='0') tot[0]=rl[0].second*(rl[0].second-1)/2;
    else tot[0]=((rl[0].second+1)*(rl[0].second+1)/4);
    for(int i=1;i<m;i++) {
        tot[i]+=tot[i-1];
        if(rl[i].first=='0') {
            tot[i]+=rl[i].second*(rl[i].second-1)/2;
            tot[i]+=rtot*rl[i].second;
        } else {
            tot[i]+=((rl[i].second+1)*(rl[i].second+1)/4);
            tot[i]+=rl[i].second/2*(rtot-1);
            tot[i]+=(rl[i].second+1)/2;
        }
        rtot+=rl[i].second;
    }
    cout << tot.back() << endl;
    return 0;
}