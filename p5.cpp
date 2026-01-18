#include <bits/stdc++.h>
using namespace std;

struct Line {
    int x1, y1, x2, y2;
};

int gcd_int(int a, int b) {
    return b == 0 ? a : gcd_int(b, a % b);
}

// Count how many cells a line covers from (px,py) to one endpoint
int countCells(int px, int py, int x2, int y2) {
    int dx = abs(x2 - px);
    int dy = abs(y2 - py);
    return gcd_int(dx, dy);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<Line> lines(N);
    for (int i = 0; i < N; i++) {
        cin >> lines[i].x1 >> lines[i].y1 >> lines[i].x2 >> lines[i].y2;
    }
    int K;
    cin >> K;

    // Map intersection point -> set of line indices
    map<pair<int,int>, vector<int>> stars;

    // Find intersections
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            // Compute intersection of lines[i] and lines[j]
            // Simplified: since grid-aligned, only check lattice intersections
            // TODO: implement robust intersection check
        }
    }

    long long totalIntensity = 0;

    // For each candidate star
    for (auto &entry : stars) {
        auto pt = entry.first;
        auto &lst = entry.second;
        if ((int)lst.size() == K) {
            int px = pt.first, py = pt.second;
            vector<int> rays;
            for (int idx : lst) {
                Line L = lines[idx];
                if ((px == L.x1 && py == L.y1) || (px == L.x2 && py == L.y2)) {
                    // Case 1
                    if (px == L.x1 && py == L.y1)
                        rays.push_back(countCells(px, py, L.x2, L.y2));
                    else
                        rays.push_back(countCells(px, py, L.x1, L.y1));
                } else {
                    // Case 2 (two rays)
                    rays.push_back(countCells(px, py, L.x1, L.y1));
                    rays.push_back(countCells(px, py, L.x2, L.y2));
                }
            }
            totalIntensity += *min_element(rays.begin(), rays.end());
        }
    }

    cout << totalIntensity << "\n";
    return 0;
}
