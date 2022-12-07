#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll q,l;
    cin >> q >> l;
    vector<pl> st;
    ll tot=0;
    while(q--) {
        string s;
        cin >> s;
        if(s=="Push") {
            ll n,m;
            cin >> n >> m;
            st.push_back({m,n});
            tot+=n;
            if(tot>l) {
                cout << "FULL" << endl;
                return 0;
            }
        } else if(s=="Pop") {
            ll n;
            cin >> n;
            tot-=n;
            if(tot<0) {
                cout << "EMPTY" << endl;
                return 0;
            }
            while(n>0) {
                if(st.back().second>n) {
                    st.back().second-=n;
                    n=0;
                } else {
                    n-=st.back().second;
                    st.pop_back();
                }
            }
        } else if(s[0]=='T') {
            if((int)st.size()==0) {
                cout << "EMPTY" << endl;
                return 0;
            }
            cout << st.back().first << "\n";
        } else {
            cout << tot << "\n";
        }
    }
    cout << "SAFE" << endl;
    return 0;
}