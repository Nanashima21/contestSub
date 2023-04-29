#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int h,w;
    cin >> h >> w;
    vector<string> s(h),t(h);
    rep(i,h) cin >> s[i];
    rep(i,h) cin >> t[i];
    vector<vector<char>> v(h*2,vector<char> (w*2));
    rep(i,h) rep(j,w) {
        v[i][j]=s[i][j];
        v[i+h][j]=s[i][j];
        v[i][j+w]=s[i][j];
        v[i+h][j+w]=s[i][j];
    }
    rep(i,h) rep(j,w) {
        bool flag=true;
        for(int x=i;x<i+h;x++) for(int y=j;y<j+w;y++) {
            if(v[x][y]!=t[x-i][y-j]) flag=false;
        }
        if(flag) {
            cout << "Yes" << endl;
            return 0;
        }
    } 
    cout << "No" << endl;
    return 0;
}