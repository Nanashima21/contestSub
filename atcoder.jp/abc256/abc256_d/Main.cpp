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
    vector<int> s(n),t(n);
    vector<pair<int,int>> p;
    rep(i,n) {
        cin >> s[i] >> t[i];
        p.push_back({s[i],t[i]});
    }
    sort(all(p));
    int idxa=0,idxb=1;
    int rmax=p[0].second;
    vector<int> l,r;
    l.push_back(p[0].first);
    if(n==1) {
        cout << s[0] << " " << t[0] << endl;
        return 0;
    }
    while(true) {
        if(rmax>=p[idxb].first) {
            rmax=max(rmax,p[idxb].second);
            idxb++;
            if(idxb==n) {
                r.push_back(rmax);
                break;
            }
        } else {
            r.push_back(rmax);
            idxa=idxb;
            if(idxa==n-1) {
                l.push_back(p[idxa].first);
                r.push_back(p[idxa].second);
                break;
            } else {
                l.push_back(p[idxa].first);
                rmax=p[idxa].second;
            }
        }
    }
    rep(i,(int)l.size()) cout << l[i] << " " << r[i] << endl;
    return 0;
}