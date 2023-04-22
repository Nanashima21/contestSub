#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
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
    int n; string s;
    cin >> n >> s;
    auto rl=runlength(s);
    if((int)rl.size()==1) cout << -1 << endl;
    else {
        int ma=0;
        rep(i,(int)rl.size()) {
            if(rl[i].first=='o') ma=max(ma,rl[i].second);
        }
        cout << ma << endl;
    }
    return 0;
}