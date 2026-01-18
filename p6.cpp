#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> p;
    UnionFind(int n) : p(n) { iota(p.begin(), p.end(), 0); }
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    void unite(int a, int b) { p[find(a)] = find(b); }
};

int main() {
    int N;
    cin >> N;
    vector<string> grid(N);
    for (int i = 0; i < N; i++) cin >> grid[i];

    // Assign IDs to all meaningful cells
    map<pair<int,int>, int> id;
    int idx = 0;
    vector<int> terminals;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char c = grid[i][j];
            if (c == '.' || c == '|' || c == '-' || c == '+') {
                id[{i,j}] = idx;
                if (c == '.') terminals.push_back(idx);
                idx++;
            }
        }
    }
    int n = idx;
    UnionFind uf(n);

    // Directions
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    // Merge junctions (+) with neighbors (0 resistance)
    for (auto &kv : id) {
        int i = kv.first.first, j = kv.first.second;
        int u = kv.second;
        if (grid[i][j] == '+') {
            for (int d = 0; d < 4; d++) {
                int ni = i + dx[d], nj = j + dy[d];
                if (id.count({ni,nj})) {
                    uf.unite(u, id[{ni,nj}]);
                }
            }
        }
    }

    // Build resistor edges (weight = 1)
    vector<tuple<int,int,double>> edges;
    for (auto &kv : id) {
        int i = kv.first.first, j = kv.first.second;
        int u = uf.find(kv.second);
        char c = grid[i][j];

        // horizontal movement
        if (c == '-' || c == '+' || c == '.') {
            for (int d : {0,1}) {
                int ni = i + dx[d], nj = j + dy[d];
                if (id.count({ni,nj})) {
                    int v = uf.find(id[{ni,nj}]);
                    if (u != v) edges.push_back({u,v,1.0});
                }
            }
        }
        // vertical movement
        if (c == '|' || c == '+' || c == '.') {
            for (int d : {2,3}) {
                int ni = i + dx[d], nj = j + dy[d];
                if (id.count({ni,nj})) {
                    int v = uf.find(id[{ni,nj}]);
                    if (u != v) edges.push_back({u,v,1.0});
                }
            }
        }
    }

    // Compress nodes after union-find
    map<int,int> remap;
    int newId = 0;
    for (int i = 0; i < n; i++) {
        int r = uf.find(i);
        if (!remap.count(r)) remap[r] = newId++;
    }
    int m = newId;

    int s = remap[uf.find(terminals[0])];
    int t = remap[uf.find(terminals[1])];

    // Build Laplacian matrix
    vector<vector<double>> L(m, vector<double>(m, 0));
    for (auto [u,v,w] : edges) {
        int a = remap[u], b = remap[v];
        double g = 1.0 / w; // conductance
        L[a][a] += g;
        L[b][b] += g;
        L[a][b] -= g;
        L[b][a] -= g;
    }

    // Remove t (ground node) from system
    int dim = m - 1;
    vector<vector<double>> A(dim, vector<double>(dim, 0));
    vector<double> b(dim, 0);

    for (int i = 0, row = 0; i < m; i++) {
        if (i == t) continue;
        for (int j = 0, col = 0; j < m; j++) {
            if (j == t) continue;
            A[row][col] = L[i][j];
            col++;
        }
        row++;
    }

    // Inject current: +1 at s, -1 at t
    if (s != t) b[s < t ? s : s-1] = 1;

    // Gaussian elimination
    for (int i = 0; i < dim; i++) {
        int piv = i;
        for (int j = i+1; j < dim; j++)
            if (fabs(A[j][i]) > fabs(A[piv][i])) piv = j;
        swap(A[i], A[piv]);
        swap(b[i], b[piv]);

        double div = A[i][i];
        for (int j = i; j < dim; j++) A[i][j] /= div;
        b[i] /= div;

        for (int j = 0; j < dim; j++) {
            if (j == i) continue;
            double factor = A[j][i];
            for (int k = i; k < dim; k++) A[j][k] -= factor * A[i][k];
            b[j] -= factor * b[i];
        }
    }

    vector<double> V(m, 0);
    for (int i = 0, row = 0; i < m; i++) {
        if (i == t) continue;
        V[i] = b[row++];
    }

    double Req = fabs(V[s] - V[t]);
    cout << (long long)round(Req) << "\n";
    return 0;
}
