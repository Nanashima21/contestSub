#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n;
    cin >> n;
    vector<int> d(n),cnt(13,0);
    cnt[0]++;
    rep(i,n) {
        cin >> d[i];
        cnt[d[i]]++;
    }
    vector<int> vec;
    rep(i,13) {
        if((i==0||i==12)&&cnt[i]>1) {
            cout << 0 << endl;
            return 0;
        }
        if(cnt[i]>2) {
            cout << 0 << endl;
            return 0;
        }
        if(cnt[i]) vec.push_back(i);
    }
    int m=(int)vec.size();
    int ans=0;
    for(int bit=0;bit<(1<<m);bit++) {
        vector<int> cv;
        rep(i,m) {
            if(cnt[vec[i]]>1) {
                cv.push_back(vec[i]);
                cv.push_back(24-vec[i]);
                continue;
            }
            if(bit>>i&1) cv.push_back(vec[i]);
            else cv.push_back(24-vec[i]);
        }
        int mi=30;
        rep(i,(int)cv.size()) rep(j,i) {
            int x=cv[i],y=cv[j];
            mi=min(mi,min((y-x+24)%24,(x-y+24)%24));
        }
        ans=max(ans,mi);
    }
    cout << ans << endl;
    return 0;
}