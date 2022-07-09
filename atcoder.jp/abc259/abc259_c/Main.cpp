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
    string s,t;
    cin >> s >> t;
    auto rls=runlength(s);
    auto rlt=runlength(t);
    vector<pair<char,int>> v1,v2;
    for(auto u:rls) v1.push_back(u);
    for(auto u:rlt) v2.push_back(u);
    bool flag=true;
    if((int)v1.size()!=v2.size()) flag=false;
    rep(i,(int)v1.size()) {
        if(v1[i].first!=v2[i].first) flag=false;
        else {
            if(v1[i].second>v2[i].second) flag=false;
            if(v1[i].second==1&&v2[i].second>1) flag=false;
        }
    }
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}