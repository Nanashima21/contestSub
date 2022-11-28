#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll h,w,m;
    cin >> h >> w >> m;
    vector<int> row(h),col(w);
    vector<pair<int,int>> p;
    rep(i,m) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        p.push_back({a,b});
        row[a]++;
        col[b]++;
    }
    sort(all(p));
    int mar=*max_element(all(row));
    int mac=*max_element(all(col));
    vector<int> vecr,vecc; 
    rep(i,h) if(mar==row[i]) vecr.push_back(i);
    rep(i,w) if(mac==col[i]) vecc.push_back(i);
    int ans=0;
    if(m<(ll)vecr.size()*(ll)vecc.size()) ans=mar+mac;
    else {
        for(int a:vecr) for(int b:vecc) {
            if(binary_search(all(p),make_pair(a,b))) ans=max(ans,mar+mac-1);
            else {
                ans=max(ans,mar+mac);
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}