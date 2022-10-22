#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n,x,y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<bool>> px((n+1)/2+1,vector<bool> (20020));
    vector<vector<bool>> py((n+1)/2+1,vector<bool> (20020));
    py[0][10000]=true;
    px[0][10000+a[0]]=true; 
    int xidx=0,yidx=0;
    for(int i=1;i<n;i++) {
        if(i%2==0) {
            for(int j=0;j<20020;j++) {
                if(px[xidx][j]) {
                    if(j+a[i]<20020) px[xidx+1][j+a[i]]=true;
                    if(j-a[i]>=0) px[xidx+1][j-a[i]]=true;
                }
            }
            xidx++;
        } else {
            for(int j=0;j<20020;j++) {
                if(py[yidx][j]) {
                    if(j+a[i]<20020) py[yidx+1][j+a[i]]=true;
                    if(j-a[i]>=0) py[yidx+1][j-a[i]]=true;
                }
            }
            yidx++;
        }
    }
    cout << (px[xidx][10000+x]&&py[yidx][10000+y] ? "Yes" : "No") << endl;
    return 0;
}