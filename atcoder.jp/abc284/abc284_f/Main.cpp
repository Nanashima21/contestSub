#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a)  (a).begin(),(a).end()
#define rall(a)  (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

vector<int> z_algorithm(string S) {
    int c = 0, n = S.size();
    vector<int> Z(n, 0);
    for (int i = 1; i < n; i++) {
        int l = i - c;
        if (i + Z[l] < c + Z[c]) Z[i] = Z[l];
        else {
            int j = max(0, c + Z[c] - i);
            while (i + j < n && S[j] == S[i + j])j++;
            Z[i] = j;
            c = i;
        }
    }
    Z[0] = n;
    return Z;
}

int main() {
    ll n; string t;
    cin >> n >> t;
    string a=t.substr(0,n);
    string b=t.substr(n);
    reverse(all(b));
    string x=a+b;
    vector<int> zx=z_algorithm(x);
    zx.push_back(0);
    string y=b+a;
    vector<int> zy=z_algorithm(y);
    zy.push_back(0);
    for(int i=0;i<=n;i++) {
        if(zx[2*n-i]<i) continue;
        if(zy[n+i]<n-i) continue;
        cout << t.substr(0,i)+t.substr(n+i) << endl;
        cout << i << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0;
}