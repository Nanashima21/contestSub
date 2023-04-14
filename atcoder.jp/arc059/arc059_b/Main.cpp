#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    string s;
    cin >> s;
    int n=(int)s.size();
    vector<vector<int>> idx(26,vector<int> ());
    rep(i,n) idx[s[i]-'a'].push_back(i);
    rep(i,26) {
        int l=0,r=(int)idx[i].size()-1;
        while(l<r) {
            int num=r-l+1;
            int len=idx[i][r]-idx[i][l]+1;
            if(num*2>len) {
                cout << idx[i][l]+1 << " " << idx[i][r]+1 << endl;
                return 0;
            }
            int subl=idx[i][l+1]-idx[i][l];
            int subr=idx[i][r]-idx[i][r-1];
            if(subl>=subr) l++;
            else r--;
        }
    }
    cout << -1 << " " << -1 << endl;
    return 0;
}