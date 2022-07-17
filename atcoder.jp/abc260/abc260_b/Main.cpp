#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,x,y,z;
    cin >> n >> x >> y >> z;
    vector<int> a(n),b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    vector<pair<int,int>> p,p2;
    rep(i,n) p.push_back({a[i],-i});
    sort(rall(p));
    for(int i=x;i<n;i++) {
        p2.push_back({b[-p[i].second],p[i].second});
        //cout << p[i].second << endl;
    }
    sort(rall(p2));
    vector<pair<int,int>> p3;
    for(int i=y;i<(int)p2.size();i++) {
        p3.push_back({a[-p2[i].second]+b[-p2[i].second],p2[i].second});
        //cout << p2[i].second << endl;
    }        
    sort(rall(p3));
    vector<bool> flag(n,false);
    for(int i=z;i<(int)p3.size();i++) {
        flag[-p3[i].second]=true;
        //cout << p3[i].second << endl;
    }
    rep(i,n) if(!flag[i]) cout << i+1 << endl;
    return 0;
}