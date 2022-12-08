#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    string s,t,r;
    cin >> s >> t >> r;
    int x=(int)s.size();
    vector<int> vs(26),vt(26),vr(26);
    rep(i,x) {
        vs[s[i]-'A']++;
        vt[t[i]-'A']++;
        vr[r[i]-'A']++;
    }
    bool flag=true;
    int cnts=0,cntt=0;
    rep(i,26) {
        if(vr[i]>0) {
            if(vs[i]+vt[i]<vr[i]) flag=false;
            if(vs[i]<vt[i]&&vs[i]<vr[i]) {
                int sub=vr[i]-vs[i];
                cntt+=sub;
                vr[i]-=sub; vt[i]-=sub;
            }
            if(vt[i]<vs[i]&&vt[i]<vr[i]) {
                int sub=vr[i]-vt[i];
                cnts+=sub;
                vr[i]-=sub; vs[i]-=sub;
            }
        }
    }
    rep(i,26) {
        if(vs[i]+vt[i]==vr[i]) {
            cntt+=vt[i];
            cnts+=vs[i];
        }
    }
    if(cnts>x/2||cntt>x/2) flag=false;
    cout << (flag ? "YES" : "NO") << endl;
    return 0;
}