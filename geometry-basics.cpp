#include <bits/stdc++.h>

using namespace std;

// P as in point, C as in coordinate
typedef long long C;
typedef complex<C> P;
#define X real()
#define Y imag()

// use as a paremeter in sort()
bool point_compare(P &lhs, P &rhs) {
    return lhs.X == rhs.X ? lhs.Y < rhs.Y : lhs.X < rhs.X;
}

C cross2d(P a, P b) { return (conj(a)*b).Y; }
bool turnsRight(P a, P b) { return cross2d(a, b) < 0; }
bool pointIsLeftOfSegment(P p, P s1, P s2) { return cross2d(p-s1, p-s2) > 0; }
C distanceFromPointToSegment(P p, P s1, P s2) { return cross2d(s1-p, s2-p) / abs(s1-s2); }

// first and last vertex must be the same
// use i+1 mod n if that's not the case
double polygonArea(vector<P> &vertices) {
    double sum = 0;

    for (int i=0; i<vertices.size()-1; i++) {
        sum += cross2d(vertices[i], vertices[i+1]);
    }

    sum = abs(sum) / 2.0;

    return sum;
}

int main() {
    
    vector<P> points;
    points.push_back({3, 4});
    points.push_back({3, 1});
    points.push_back({0, 4});
    points.push_back({3, 4});

    polygonArea(points); // 4.5

    sort(points.begin(), points.end(), point_compare);
    // (0,4), (3,1), (3,4), (3,4)

    return 0;    
}