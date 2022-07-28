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
    if(pre=='0') res.push_back({'1',0}); 
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
    if(rl.back().first=='0') rl.push_back({'1',0});
    vector<ll> tot((int)rl.size()+1,0);
    rep(i,(int)rl.size()) tot[i+1]=rl[i].second+tot[i];
    ll ma=0,l=0,r=2*k+1;
    if((int)rl.size()==1) ma=rl[0].second;
    while(true) {
        if(r>=(int)tot.size()) {
            r=(int)tot.size()-1;
            ma=max(ma,tot[r]-tot[l]);
            break;
        }
        ma=max(ma,tot[r]-tot[l]);
        l+=2; r+=2;
    }
    cout << ma << endl;
    return 0;
}