#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int H,W,n,h,w;
    cin >> H >> W >> n >> h >> w;
    vector<vector<int>> a(H,vector<int> (W));
    vector<vector<vector<int>>> cnt(300,vector<vector<int>> (H,vector<int> (W,0)));
    rep(i,H) rep(j,W) {
        cin >> a[i][j];
        a[i][j]--;
        cnt[a[i][j]][i][j]++;
    }
    rep(k,300) {
        for(int i=0;i<H;i++) {
            for(int j=1;j<W;j++) {
                cnt[k][i][j]+=cnt[k][i][j-1];
            }
        }
        for(int i=0;i<W;i++) {
            for(int j=1;j<H;j++) {
                cnt[k][j][i]+=cnt[k][j-1][i];
            }
        }
    }
    for(int i=0;i<=H-h;i++) {
        for(int j=0;j<=W-w;j++) {
            int tot=0;
            rep(k,300) {
                int lu=0,ru=0,ld=0,rd=rd=cnt[k][i+h-1][j+w-1];
                if(i-1>=0&&j-1>=0) {
                    lu=cnt[k][i-1][j-1];
                    ru=cnt[k][i-1][j+w-1];
                    ld=cnt[k][i+h-1][j-1];
                } else if(i-1>=0) {
                    ru=cnt[k][i-1][j+w-1];
                } else if(j-1>=0) {
                    ld=cnt[k][i+h-1][j-1];
                } 
                if(lu-ru-ld+rd!=cnt[k][H-1][W-1]&&cnt[k][H-1][W-1]!=0) tot++;
            }
            if(j) cout << " ";
            cout << tot;
        } cout << endl;
    }
    return 0;
}