#include <iostream>
#include <vector>
#include <map>
#include <numeric>

// Struct to represent a point
struct Point {
    int x, y;
    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

// Disjoint Set Union (DSU) implementation
struct DSU {
    std::vector<int> parent;
    int components;

    DSU(int n) {
        parent.resize(n);
        std::iota(parent.begin(), parent.end(), 0);
        components = n;
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            parent[root_j] = root_i;
            components--;
        }
    }
};

int main() {
    int N;
    std::cin >> N;

    std::map<Point, int> point_to_id;
    int next_id = 0;
    std::vector<std::pair<int, int>> edges;

    for (int i = 0; i < N; ++i) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;

        Point p1 = {x1, y1};
        Point p2 = {x2, y2};

        if (point_to_id.find(p1) == point_to_id.end()) {
            point_to_id[p1] = next_id++;
        }
        if (point_to_id.find(p2) == point_to_id.end()) {
            point_to_id[p2] = next_id++;
        }

        edges.push_back({point_to_id[p1], point_to_id[p2]});
    }

    int V = point_to_id.size();
    int E = N;

    DSU dsu(V);
    for (const auto& edge : edges) {
        dsu.unite(edge.first, edge.second);
    }

    int C = dsu.components;
    int closed_figures = E - V + C;

    std::cout << closed_figures << std::endl;

    return 0;
}