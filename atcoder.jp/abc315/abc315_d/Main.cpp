#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    ll ans=h*w;
    vector<bool> flagh(h,false),flagw(w,false);
    
    vector<set<char>> sth(h),stw(w);
    vector<map<char,int>> mph(h),mpw(w);
    rep(i,h) rep(j,w) {
        sth[i].insert(s[i][j]);
        mph[i][s[i][j]]++;
    }
    rep(i,w) rep(j,h) {
        stw[i].insert(s[j][i]);
        mpw[i][s[j][i]]++;
    }
    
    queue<pair<int,int>> q;
    rep(i,h) if((int)sth[i].size()==1) {
        q.push({i,0});
        flagh[i]=true;
    }
    rep(i,w) if((int)stw[i].size()==1) {
        q.push({i,1});
        flagw[i]=true;
    }

    while(!q.empty()) {
        int p=q.front().first;
        int t=q.front().second;
        q.pop();
        if(t==0) {
            char c=*sth[p].begin();
            rep(i,w) {
                if(flagw[i]) continue;
                if(stw[i].find(c)==stw[i].end()) continue;
                mpw[i][c]--;
                if(mpw[i][c]==0) stw[i].erase(c);
                if((int)stw[i].size()==1) {
                    if(mpw[i][*stw[i].begin()]<2) continue;
                    q.push({i,1});
                    flagw[i]=true;
                }
            }
        } else {
            char c=*stw[p].begin();
            rep(i,h) {
                if(flagh[i]) continue;
                if(sth[i].find(c)==sth[i].end()) continue;
                mph[i][c]--;
                if(mph[i][c]==0) sth[i].erase(c);
                if((int)sth[i].size()==1) {
                    if(mph[i][*sth[i].begin()]<2) continue;
                    q.push({i,0});
                    flagh[i]=true;
                }
            }
        }
    } 

    rep(i,h) rep(j,w) if(flagh[i]||flagw[j]) ans--;
    cout << ans << endl;
    return 0;
}