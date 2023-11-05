#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
typedef long long ll;
typedef pair<ll,ll> pl;

int n,m;

const double Limit_time=1.95*CLOCKS_PER_SEC;

vector<pair<int,int> > solve(vector<vector<int> > b) {
    vector<pair<int,int> > ret;
    int cur = 1;
    while(true) {
        if(cur > n) break;
        int box_mount = -1, box_idx = -1;
        rep(i,m) rep(j,(int)b[i].size()) {
            if(b[i][j] == cur) {
                box_mount = i;
                box_idx = j;
            }
        } 
        int mount_idx = 0;
        for (int i = (int)b[box_mount].size() - 1; i > box_idx; i--) {
            if (mount_idx == box_mount) mount_idx=(mount_idx+1)%m;
            ret.push_back(make_pair(b[box_mount].back(), mount_idx+1));
            b[mount_idx].push_back(b[box_mount].back());
            b[box_mount].pop_back();
            mount_idx=(mount_idx+1)%m;
        }
        if(box_idx == (int)b[box_mount].size() - 1) {
            ret.push_back(make_pair(cur, 0));
            b[box_mount].pop_back();
            cur++;
        } 
    }  
    return ret;
}

vector<pair<int,int> > solve2(int &score,vector<vector<int> > b, int da, int dc, int rnd) {
    vector<pair<int,int> > ret;
    int cur = 1;
    while(true) {
        if(cur > n) break;
        int box_mount = -1, box_idx = -1;
        rep(i,m) rep(j,(int)b[i].size()) {
            if(b[i][j] == cur) {
                box_mount = i;
                box_idx = j;
            }
        } 

        // 移動先の山idx
        int mount_idx = 0;
        vector<pair<int,int> > vb; 
        rep(i,m) {
            if(i == box_mount) continue;
            if ((int)b[i].size()!=0) vb.push_back(make_pair(*min_element(all(b[i])), i));
            else vb.push_back(make_pair(2000, i));
        }
        sort(rall(vb));
        if (1) mount_idx = vb[0].second;
        else mount_idx = vb[1].second;

        int second_min = 300, sm_idx = 0;
        rep(i,(int)b[box_mount].size()) {
            if (b[box_mount][i] == cur) continue;
            if (b[box_mount][i] < second_min) {
                second_min = b[box_mount][i];
                sm_idx = i;
            }
        } 


        if (second_min - cur <= da) {
            if (sm_idx > box_idx && sm_idx - box_idx < dc) {
                if(sm_idx + 1 < (int)b[box_mount].size()) {
                    ret.push_back(make_pair(b[box_mount][sm_idx+1], mount_idx+1));
                    score++;
                }
                vector<int> tmp;
                for (int i = (int)b[box_mount].size() - 1; i > sm_idx; i--) {
                    tmp.push_back(b[box_mount].back());
                    b[box_mount].pop_back();
                }
                while(!tmp.empty()) {
                    b[mount_idx].push_back(tmp.back());
                    tmp.pop_back();
                    score++;
                }
            } 
        } 

        vector<pair<int,int> > vvb; 
        rep(i,m) {
            if(i == box_mount) continue;
            if ((int)b[i].size()!=0) vvb.push_back(make_pair(*min_element(all(b[i])), i));
            else vvb.push_back(make_pair(2000, i));
        }
        sort(rall(vvb));
        if (rand()%rnd) mount_idx = vvb[0].second;
        else mount_idx = vvb[1].second;

        if(box_idx + 1 < (int)b[box_mount].size()) {
            ret.push_back(make_pair(b[box_mount][box_idx+1], mount_idx+1));
            score++;
        }
        vector<int> tmp;
        for (int i = (int)b[box_mount].size() - 1; i > box_idx; i--) {
            tmp.push_back(b[box_mount].back());
            b[box_mount].pop_back();
        }
        while(!tmp.empty()) {
            b[mount_idx].push_back(tmp.back());
            tmp.pop_back();
            score++;
        }
        if(box_idx == (int)b[box_mount].size() - 1) {
            ret.push_back(make_pair(cur, 0));
            b[box_mount].pop_back();
            cur++;
        } 
    }  
    return ret;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    srand(time(NULL));
    cin >> n >> m;
    vector<vector<int> > b; 
    b.resize(m,vector<int> ());
    rep(i,m) rep(j,n/m) {
        int a;
        cin >> a;
        b[i].push_back(a);
    }
    int max_score = 0;
    vector<pair<int,int> > ans;
    for (int da=0;da<=100;da++) {
        for (int dc=0;dc<=100;dc++) {
            for (int rnd=4;rnd<=5;rnd++) {
                if(clock()>Limit_time) break;
                // for (int dd=0;dd<=20;dd++) {
                    int cur_score = 0;
                    vector<pair<int,int> > res = solve2(cur_score, b, da, dc, rnd);
                    cur_score = max(1, 10000-cur_score); 
                    if (max_score < cur_score) {
                        // cerr << cur_score << " " << da << " " << dc << " " << rnd << endl;
                        max_score = cur_score;
                        swap(ans,res);
                    } 
                // } 
            }
        }
    } 
    for(auto u:ans) cout << u.first << " " << u.second << endl;
    return 0;
}