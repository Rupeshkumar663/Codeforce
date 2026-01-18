#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
    Point() {}
    Point(double _x, double _y) : x(_x), y(_y) {}
    Point operator+(const Point& o) const { return Point(x + o.x, y + o.y); }
    Point operator-(const Point& o) const { return Point(x - o.x, y - o.y); }
    Point operator*(double s) const { return Point(x * s, y * s); }
};

double dot(const Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }
double cross(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }

double areaPolygon(const vector<Point>& p) {
    int n = p.size();
    double s = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        s += cross(p[i], p[j]);
    }
    return fabs(s) * 0.5;
}

vector<Point> clipPolygon(const vector<Point>& poly, const Point& n, double c) {
    vector<Point> out;
    int m = poly.size();
    auto inside = [&](const Point& pt) { return dot(n, pt) >= c - 1e-10; };
    for (int i = 0; i < m; i++) {
        Point S = poly[i], E = poly[(i + 1) % m];
        bool inS = inside(S), inE = inside(E);
        if (inS && inE) out.push_back(E);
        else if (inS && !inE) {
            Point d = E - S;
            double t = (c - dot(n, S)) / dot(n, d);
            t = max(0.0, min(1.0, t));
            out.push_back(S + d * t);
        } else if (!inS && inE) {
            Point d = E - S;
            double t = (c - dot(n, S)) / dot(n, d);
            t = max(0.0, min(1.0, t));
            out.push_back(S + d * t);
            out.push_back(E);
        }
    }
    vector<Point> res;
    for (size_t i = 0; i < out.size(); i++)
        if (i == 0 || fabs(out[i].x - out[i-1].x) > 1e-9 || fabs(out[i].y - out[i-1].y) > 1e-9)
            res.push_back(out[i]);
    if (res.size() >= 2 && fabs(res.front().x - res.back().x) < 1e-9 && fabs(res.front().y - res.back().y) < 1e-9)
        res.pop_back();
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<Point> poly(N);
    for (int i = 0; i < N; i++) cin >> poly[i].x >> poly[i].y;
    double signedArea = 0;
    for (int i = 0; i < N; i++) {
        int j = (i + 1) % N;
        signedArea += cross(poly[i], poly[j]);
    }
    if (signedArea < 0) reverse(poly.begin(), poly.end());
    double Hmax = 1e9;
    for (int i = 0; i < N; i++) {
        int j = (i + 1) % N;
        double L = hypot(poly[j].x - poly[i].x, poly[j].y - poly[i].y);
        Hmax = min(Hmax, (L - 0.1) / 2.0);
    }
    if (Hmax < 0) Hmax = 0;
    int steps = floor(Hmax * 10 + 1e-9);
    struct Edge { Point A, B, n; double c; };
    vector<Edge> edges;
    for (int i = 0; i < N; i++) {
        int j = (i + 1) % N;
        Point A = poly[i], B = poly[j];
        Point e = B - A, n(-e.y, e.x);
        double len = hypot(n.x, n.y);
        if (len < 1e-15) continue;
        n = Point(n.x / len, n.y / len);
        edges.push_back({A, B, n, dot(n, A)});
    }
    double bestVol = 0;
    for (int k = 1; k <= steps; k++) {
        double H = k * 0.1;
        vector<Point> cur = poly;
        for (auto &ed : edges) {
            cur = clipPolygon(cur, ed.n, ed.c + H);
            if (cur.empty()) break;
        }
        if (cur.size() < 3) continue;
        bestVol = max(bestVol, areaPolygon(cur) * H);
    }
    cout << fixed << setprecision(2) << bestVol << "\n";
    return 0;
}
