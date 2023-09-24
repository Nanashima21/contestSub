#include <bits/stdc++.h>
using namespace std;
#define INF ((1LL<<62)-(1LL<<31))
typedef long long ll;
typedef pair<ll,ll> pl;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int ddx[]={0,0,1,-1,1,-1,1,-1};
int ddy[]={1,-1,0,0,1,-1,-1,1};

const double Limit_time=1.75*CLOCKS_PER_SEC;

const int N = 50;
const int M = 100;
vector<vector<int> > color(N ,vector<int> (N));
vector<vector<bool> > isBorder(N, vector<bool> (N, false));
vector<vector<int> > neighbor_cnt;

bool isValidGrid(int y, int x) {
    if (y < 0 || y >= N || x < 0 || x >= N) return false;
    return true;
}

vector<vector<int> > cntNeighborColor(vector<vector<int> > &cur_color) {
    vector<set<int> > vs(M + 1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (cur_color[i][j] == 0) continue;
            for (int k = 0; k < 4; k++) {
                int ny = i + dy[k];
                int nx = j + dx[k];
                if (!isValidGrid(ny, nx)) {
                    vs[cur_color[i][j]].insert(0);
                    continue;
                }
                if (cur_color[i][j] == cur_color[ny][nx]) continue;
                vs[cur_color[i][j]].insert(cur_color[ny][nx]);
            }
        }
    }
    vector<vector<int> > ret(M + 1, vector<int> ());
    for (int i = 0; i <= M; i++) {
        for (auto u: vs[i]) {
            ret[i].push_back(u);
        }
    }
    return ret;
}

bool isConnected(vector<vector<int> > &cur_color) {
    vector<vector<bool> > watched(N, vector<bool> (N, false));
    vector<int> col_num;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (watched[i][j]) continue;
            if (cur_color[i][j] == 0) continue;
            col_num.push_back(cur_color[i][j]);
            queue<pair<int, int> > q;
            q.push(make_pair(i, j));
            while(!q.empty()) {
                int cy=q.front().first;
                int cx=q.front().second;
                q.pop();
                for(int k = 0; k < 4; k++) {
                    int ny = cy + dy[k];
                    int nx = cx + dx[k];
                    if (!isValidGrid(ny, nx)) continue;
                    if (watched[ny][nx]) continue;
                    if (cur_color[ny][nx] == cur_color[cy][cx]) {
                        watched[ny][nx] = true;
                        q.push(make_pair(ny, nx));
                    }
                }
            }
        }
    }
    return (int)col_num.size() == M;
}

bool isValid(vector<vector<int> > &cur_color) {
    auto updated_neighbor_cnt = cntNeighborColor(cur_color);
    if(updated_neighbor_cnt != neighbor_cnt) return false;
    return isConnected(cur_color);
}

vector<vector<int> > leveling(vector<vector<int> > cur_color) {
    vector<vector<int> > update_color = cur_color;
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            if (cur_color[i][j] == 0) continue;
            map<int, int> mp;
            for (int k = 0; k < 4; k++) {
                int ny = i + dy[k];
                int nx = j + dx[k];
                if(!isValidGrid(ny, nx)) {
                    //mp[0]++;
                    continue;
                }
                mp[update_color[ny][nx]]++;
            }
            if((int)mp.size() == 2 && mp[update_color[i][j]] == 1) {
                mp.erase(update_color[i][j]);
                if ((*mp.begin()).first != 0) update_color[i][j]=(*mp.begin()).first; 
            }
        }
    }
    cur_color = update_color;
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            if (cur_color[i][j] == 0) continue;
            map<int, int> mp;
            for (int k = 0; k < 4; k++) {
                int ny = i + dy[k];
                int nx = j + dx[k];
                if(!isValidGrid(ny, nx)) continue;
                mp[update_color[ny][nx]]++;
            }
            if((int)mp.size() == 3 && mp[update_color[i][j]] == 1 && rand() % 10 == 0) {
                int col = 0, idx = 0;
                for (auto u: mp) {
                    if (u.second > idx) {
                        idx = u.second;
                        col = u.first;
                    }
                }
                if (col != 0) update_color[i][j]=col; 
            }
        }
    }
    if(!isValid(update_color)) return cur_color;
    cur_color = update_color;
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            if (cur_color[i][j] == 0) continue;
            map<int, int> mp;
            for (int k = 0; k < 4; k++) {
                int ny = i + dy[k];
                int nx = j + dx[k];
                if(!isValidGrid(ny, nx)) continue;
                mp[update_color[ny][nx]]++;
            }
            if((int)mp.size() == 2 && mp[update_color[i][j]] == 2 && rand() % 20 == 0) {
                mp.erase(update_color[i][j]);
                if ((*mp.begin()).first != 0) update_color[i][j]=(*mp.begin()).first; 
            }
        }
    }
    if(!isValid(update_color)) return cur_color;
    return update_color;
}

vector<vector<int> > slicingRow(vector<vector<int> > cur_color) {
    vector<int> skip_idx;
    for (int i = 1; i < N; i++) {
        if (cur_color[i] == cur_color[i - 1]) skip_idx.push_back(i-1);
    }
    vector<vector<int> > update_color;
    for (int i = 0; i < N; i++) {
        if (binary_search(skip_idx.begin(),skip_idx.end(), i)) continue;
        update_color.push_back(cur_color[i]);
    }
    vector<int> zeros(N, 0);
    for (int i = 0; i < N - (int)skip_idx.size(); i++) {
        update_color.push_back(zeros);
    }
    if(!isValid(update_color)) return cur_color;
    return update_color;
}

vector<vector<int> > slicingCol(vector<vector<int> > cur_color) {
    vector<int> skip_idx;
    for (int i = 1; i < N; i++) {
        bool flag = true;
        for (int j = 0; j < N; j++) {
            if (cur_color[j][i] != cur_color[j][i - 1]) flag = false;
        }
        if (flag) skip_idx.push_back(i-1);
    }
    vector<vector<int> > update_color(N, vector<int> ());
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (binary_search(skip_idx.begin(),skip_idx.end(), j)) continue;
            update_color[i].push_back(cur_color[i][j]);
        }
        for (int j = 0; j < N - (int)skip_idx.size(); j++) {
            update_color[i].push_back(0);
        }
    }
    if(!isValid(update_color)) return cur_color;
    return update_color;
}

void output(vector<vector<int> > out) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(j) cout << " ";
            cout << out[i][j];
        }
        cout << endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    srand(time(NULL));
    int _n, _m;
    cin >> _n >> _m;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> color[i][j];
        }
    }

    neighbor_cnt = cntNeighborColor(color);

    // for (int i = 0 ; i <= M; i++) {
    //     cerr << i << ";";
    //     for (auto u : neighbor_cnt[i]) cerr << " " << u;
    //     cerr << endl;
    // }

    auto v = leveling(color);

    while(clock()<Limit_time) {
        v = leveling(v);
        v = slicingRow(v);
        v = slicingCol(v);
        output(v);
    }

    // for (int i = N - 1; i >= 0; i--) {
    //     for (int j = N - 1; j >= 0; j--) {
    //         if (v[i][j] == 0) continue;
    //         set<int> se;
    //         for (int k = 0; k < 8; k++) {
    //             int ny = i + ddy[k];
    //             int nx = j + ddx[k];
    //             if(!isValidGrid(ny, nx)) continue;
    //             se.insert(v[ny][nx]);
    //         }
    //         if((int)se.size() == 2) {
    //             if(*se.begin() != 0) continue; 
    //             if(*se.rbegin() != v[i][j]) continue;
    //             v[i][j] = 0;
    //         }
    //     }

    // }

    output(v);

    auto up_neighbor_cnt = cntNeighborColor(v);

    // for (int i = 0 ; i <= M; i++) {
    //     cerr << i << ";";
    //     for (auto u : up_neighbor_cnt[i]) cerr << " " << u;
    //     cerr << endl;
    // }

    if(up_neighbor_cnt != neighbor_cnt) output(color);
}
