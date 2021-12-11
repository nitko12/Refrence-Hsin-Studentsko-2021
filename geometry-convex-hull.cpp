// points are sorted from left to right, hull is empty
void convexHull(vector<P> &points, vector<P> &hull) {
    int n=points.size();
    hull.push_back(points[0]);
    hull.push_back(points[1]);

    for(int i=2; i<n; i++) {
        while(hull.size() >= 2 && turnsRight(points[i]-hull[hull.size()-1], hull[hull.size()-1]-hull[hull.size()-2])) {
            hull.pop_back();
        }

        hull.push_back(points[i]);
    }

    hull.push_back(points[n-2]);

    for(int i=n-3; i>=0; i--) {
        while(hull.size() >= 2 && turnsRight(points[i]-hull[hull.size()-1], hull[hull.size()-1]-hull[hull.size()-2])) {
            hull.pop_back();
        }

        hull.push_back(points[i]);
    }
}