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
    vector<int> v;
    while(n>0) {
        v.push_back(n%10);
        n/=10;
    }
    vector<int> sv=v;
    sort(all(sv));
    bool flag=sv==v;
    rep(i,(int)sv.size()-1) if(sv[i]==sv[i+1]) flag=false;
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}