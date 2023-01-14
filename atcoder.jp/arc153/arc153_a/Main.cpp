#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int main() {
    ll n;
    cin >> n;
    vector<ll> v;
    for(int i=1;i<10;i++) {
        queue<ll> q;
        q.push(i);
        while(!q.empty()) {
            ll num=q.front();
            q.pop();
            string s=to_string(num);
            int x=(int)s.size();
            if(x==9) v.push_back(num);
            else if(x==1||x==5) {
                ll y=num*10+num%10;
                q.push(y);
            } else if(x==8) {
                ll y=num*10+num%100/10;
                q.push(y);
            } else {
                for(int j=0;j<10;j++) {
                    ll y=num*10+j;
                    q.push(y);
                }
            }
        }
    }
    sort(all(v));
    cout << v[n-1] << endl;
    return 0;
}