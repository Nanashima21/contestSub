#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> v(n,vector<int> ());
    rep(i,m) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        v[a].push_back(b);
    }
    int ng=-1,cnt=0;
    rep(i,n) sort(all(v[i]));
    rep(i,n-1) {
        if(ng==-1) {
            if((int)v[i].size()==0) {
                cnt++;
                continue;
            } 
            ng=v[i][0];
        } 
        else if((int)v[i].size()!=0) ng=min(ng,v[i][0]);
        if(ng!=i+1) cnt++;
        else ng=-1;
    }
    cout << n-1-cnt << endl;
    return 0;
}