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
    string s; ll k;
    cin >> s >> k;
    
    auto rl=runlength(s);
    ll cnt0=0,cnt1=0;
    if((int)rl.size()==1) {
        cout << (rl[0].second*k)/2 << endl;
        return 0; 
    }
    for(int i=1;i<(int)rl.size()-1;i++) cnt0+=rl[i].second/2;
    if(rl[0].first==rl.back().first) {
        cnt1+=(rl[0].second+rl.back().second)/2;
        cout << cnt0*k+cnt1*(k-1)+rl[0].second/2+rl.back().second/2 << endl;
    }
    else {
        cnt0+=rl[0].second/2+rl.back().second/2;
        cout << cnt0*k << endl;
    }
    return 0;
}