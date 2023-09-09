#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    vector<int> v(9),idx;
    rep(i,9) {
        cin >> v[i];
        idx.push_back(i);
    }
    ll cnt=0,all=0;
    do {
        all++;
        bool flag=false;
        vector<vector<bool>> check(3,vector<bool> (3,false));
        rep(i,9) {
            int y=idx[i]/3,x=idx[i]%3;
            set<int> se1,se2,se3,se4;
            int cnt1=0,cnt2=0,cnt3=0,cnt4=0;
            rep(j,3) if(check[y][j]) {
                se1.insert(v[3*y+j]); cnt1++;
            }
            rep(j,3) if(check[j][x]) {
                se2.insert(v[3*j+x]); cnt2++;
            }
            rep(j,3) if(check[j][j]) {
                se3.insert(v[3*j+j]); cnt3++;
            }
            rep(j,3) if(check[2-j][j]) {
                se4.insert(v[3*(2-j)+j]); cnt4++;
            }
            if(cnt1==2&&(int)se1.size()==1) flag=true;
            if(cnt2==2&&(int)se2.size()==1) flag=true;
            if(cnt3==2&&(int)se3.size()==1) flag=true;
            if(cnt4==2&&(int)se4.size()==1) flag=true;
            check[y][x]=true;
        }
        if(flag) continue;
        cnt++;
    } while(next_permutation(all(idx)));
    double ans=cnt/(1.0*all);
    printf("%.10f\n",ans);
    return 0;  
}