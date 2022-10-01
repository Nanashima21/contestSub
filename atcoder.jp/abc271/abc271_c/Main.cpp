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
    vector<ll> a(n);
    map<ll,int> mp;
    rep(i,n) {
        cin >> a[i];
        mp[a[i]]++;
        if(mp[a[i]]!=1) a[i]=INF; 
    }
    sort(all(a));
    int num=0;
    for(int i=1;i<=n+1;i++) {
        if(!binary_search(all(a),i)) {
            int it=upper_bound(all(a),i)-a.begin();
            if(a.size()-it>=2) {
                a.pop_back();
                a.pop_back();
            } else {
                cout << i-1 << endl;
                return 0;
            }
        } 
    }
    return 0;
}