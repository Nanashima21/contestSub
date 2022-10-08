#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n+2);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<vector<int>> v(m+2,vector<int> ());
    for(int i=1;i<=n;i++) {
        if(a[i]>=n) continue;
        int st=0;
        if(a[i]<0) {
            st=(-a[i])/i+((-a[i])%i!=0);
            a[i]+=i*st;
        }
        while(a[i]<=n) {
            if(st<=m) {
                v[st].push_back(a[i]);
                a[i]+=i;
                st++;
            } else break;
        }
    }
    for(int i=1;i<=m;i++) {
        if((int)v[i].size()==0) cout << 0 << endl;
        else {
            sort(all(v[i]));
            v[i].erase(std::unique(v[i].begin(),v[i].end()),v[i].end());
            v[i].push_back(n+1);
            rep(j,(int)v[i].size()) {
                if(v[i][j]!=j) {
                    cout << j << endl;
                    break;
                }
            }
        }
    }
    return 0;
}