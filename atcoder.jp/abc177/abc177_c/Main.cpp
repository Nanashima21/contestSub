#include<iostream>
#include<variant>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<climits>
#include<unordered_map>
#include<set>
#include<map>
using namespace std;

const long long mod=1000000007;

int main() {
    long long n;
    cin >> n;
    vector<long long >a(n);
    vector<long long >b(n);
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) {
            b[i] = a[i];
        }
        else {
            b[i] = (a[i] + b[i - 1]) % mod;
        }
    }
    long long ans = 0;
    for (long long i = 0; i < n-1; i++) {
        ans = (ans+(a[i] * (b[n - 1] - b[i]+mod)) % mod)%mod;
    }
    cout << ans % mod;
}