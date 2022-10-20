#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int h,w,k;
    cin >> h >> w >> k;
    vector<vector<int>> v(h,vector<int> (w,0));
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    int cnt=1;
    rep(i,h) rep(j,w) if(s[i][j]=='#') v[i][j]=cnt++;
    rep(i,h) {
        for(int j=1;j<w;j++) {
            if(v[i][j]==0&&v[i][j-1]!=0) v[i][j]=v[i][j-1];
        }
        for(int j=w-2;j>=0;j--) {
            if(v[i][j]==0&&v[i][j+1]!=0) v[i][j]=v[i][j+1];
        }
    }
    rep(i,w) {
        for(int j=1;j<h;j++) {
            if(v[j][i]==0&&v[j-1][i]!=0) v[j][i]=v[j-1][i];
        }
        for(int j=h-2;j>=0;j--) {
            if(v[j][i]==0&&v[j+1][i]!=0) v[j][i]=v[j+1][i];
        }
    }
    rep(i,h) {
        rep(j,w) {
            if(j) cout << " ";
            cout << v[i][j];
        }
        cout << endl;
    }
    return 0;
}