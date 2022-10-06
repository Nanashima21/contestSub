#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    int n;
    cin >> n;
    int cnt=0;
    vector<string> v(n);
    int l=0,r=n;
    while(true) {
        string in;
        if(cnt==0) {
            cout << l << endl;
            cin >> in;
            if(in[0]=='V') break;
            else v[l]=in;
        } else {
            cout << (r+l)/2 << endl;
            cin >> in;
            if(in[0]=='V') break;
            else v[(r+l)/2]=in;
            if(v[l]==v[(r+l)/2]) {
                if(((r+l)/2-l+1)%2==0) r=(r+l)/2;
                else l=(r+l)/2;
            } else {
                if(((r+l)/2-l+1)%2==0) l=(r+l)/2;
                else r=(r+l)/2;
            }
        }
        cnt++;
    }
    return 0;
}