#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    vector<string> s(10);
    rep(i,10) cin >> s[i];
    rep(j,10) {
        bool flag=false;
        rep(i,10) {
            if(!flag&&s[i][j]=='#') {
                flag=true;
                cout << i+1 << " ";
            }
            if(flag) {
                if(s[i][j]=='.') {
                    cout << i << endl;
                    break;
                } else if(i==9) {
                    cout << i+1 << endl;
                }
            } 
        }
        if(flag) break;
    }
    rep(i,10) {
        bool flag=false;
        rep(j,10) {
            if(!flag&&s[i][j]=='#') {
                flag=true;
                cout << j+1 << " ";
            }
            if(flag) {
                if(s[i][j]=='.') {
                    cout << j << endl;
                    break;
                } else if(j==9) {
                    cout << j+1 << endl;
                }
            } 
        }
        if(flag) break;
    }
    
    return 0;
}