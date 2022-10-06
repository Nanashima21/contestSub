#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll k;
    cin >> k;
    string s,t;
    cin >> s >> t;
    vector<ll> cnt(10,k);
    rep(i,4) cnt[s[i]-'0']--;
    rep(i,4) cnt[t[i]-'0']--;
    ll all=(9*k-8)*(9*k-9),cnt1=0;
    for(int i=1;i<=9;i++) {
        if(cnt[i]<1) continue;
        map<int,int> mp1;
        rep(j,10) mp1[j]=0;
        mp1[i]++;
        rep(j,4) mp1[s[j]-'0']++;
        ll score1=0;
        for(auto u:mp1) score1+=u.first*pow(10,u.second); 
        cnt[i]--;
        for(int j=1;j<=9;j++) {
            if(cnt[j]<1) continue;
            map<int,int> mp2;
            rep(l,10) mp2[l]=0;
            mp2[j]++;
            rep(l,4) mp2[t[l]-'0']++;
            ll score2=0;
            for(auto u:mp2) score2+=u.first*pow(10,u.second);
            if(score1>score2) cnt1+=(cnt[i]+1)*cnt[j];
        }
        cnt[i]++;
    }
    printf("%.10f\n",cnt1*1.0/all);
    return 0;
}