#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int a,b;
    cin >> a >> b;
    vector<vector<char>> v(100,vector<char> (100));
    if(a<=b) {
        int cntw=1,cntb=1;
        if(a==1) cntb=0;
        rep(i,100) rep(j,100) v[i][j]='.';
        for(int i=0;i<99;i+=2) {
            if(cntw>=a) break;
            rep(j,100) {
                if(j%2==1) {
                    v[i][j]='#';
                    v[i+1][j]='#';
                    cntw++;
                    if(cntw>=a) break;
                } else v[i+1][j]='#';
            }
        }
        for(int i=99;i>=0;i-=2) {
            for(int j=0;j<100;j+=2) {
                v[i][j]='#';
                cntb++;
                if(cntb==b) break;
            }
            if(cntb==b) break;
        }
    } else {
        int cntw=1,cntb=1;
        if(b==1) cntw=0;
        rep(i,100) rep(j,100) v[i][j]='#';
        for(int i=0;i<99;i+=2) {
            if(cntb>=b) break;
            rep(j,100) {
                if(j%2==1) {
                    v[i][j]='.';
                    v[i+1][j]='.';
                    cntb++;
                    if(cntb>=b) break;
                } else v[i+1][j]='.';
            }
        }
        for(int i=99;i>=0;i-=2) {
            for(int j=0;j<100;j+=2) {
                v[i][j]='.';
                cntw++;
                if(cntw==a) break;
            }
            if(cntw==a) break;
        }
    } 
    cout << 100 << " " << 100 << endl;
    rep(i,100) {
        rep(j,100) cout << v[i][j];
        cout << endl;
    }
    return 0;
}