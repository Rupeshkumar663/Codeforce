#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int E;
    if (!(cin >> E)) return 0;

    vector<pair<int,int>> a(E), b(E);
    unordered_map<long long, vector<int>> m;

    auto encode = [&](int x, int y) -> long long {
        if (x > y) swap(x, y);
        return (1LL * x << 32) | (unsigned int)y;
    };

    for (int i = 0; i < E; i++) {
        int x, y;
        cin >> x >> y;
        if (x > y) swap(x, y);
        a[i] = make_pair(x, y);
    }

    for (int i = 0; i < E; i++) {
        int x, y;
        cin >> x >> y;
        if (x > y) swap(x, y);
        b[i] = make_pair(x, y);
        m[encode(x, y)].push_back(i);
    }

    vector<int> p(E, -1);
    for (int i = 0; i < E; i++) {
        long long key = encode(a[i].first, a[i].second);
        if (m.find(key) == m.end() || m[key].empty()) {
            cout << -1;
            return 0;
        }
        p[i] = m[key].back();
        m[key].pop_back();
    }

    vector<int> vis(E, 0);
    int cycles = 0;

    for (int i = 0; i < E; i++) {
        if (!vis[i]) {
            int j = i;
            while (!vis[j]) {
                vis[j] = 1;
                j = p[j];
            }
            cycles++;
        }
    }

    cout << E - cycles;
    return 0;
}
