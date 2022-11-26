#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int h,w;
    cin >> h >> w;
    vector<string> s(h),t(h);
    rep(i,h) cin >> s[i];
    rep(i,h) cin >> t[i];
    vector<string> ns,nt;
    for(int i=0;i<w;i++) {
        string str;
        for(int j=0;j<h;j++) str+=s[j][i];
        ns.push_back(str);
    }
    for(int i=0;i<w;i++) {
        string str;
        for(int j=0;j<h;j++) str+=t[j][i];
        nt.push_back(str);
    }
    sort(all(ns));
    sort(all(nt));
    cout << (ns==nt ? "Yes" : "No") << endl;
    return 0;
}