const double eps = 1e-9;
bool leq(double a, double b){return b-a >= -eps;}
bool le(double a, double b){return b-a > eps;}
bool eq(double a, double b){return fabs(a-b) <= eps;}

struct point{
    double x, y;
    int idx = -1;
    point(): x(0), y(0){}
    point(double x, double y): x(x), y(y){}
    point operator-(const point &p) const{return point(x - p.x, y - p.y);}
    point operator*(const int &k) const{return point(x * k, y * k);}
    bool operator<(const point &p) const{return le(x, p.x) || (eq(x, p.x)&& le(y, p.y));}
    bool operator==(const point &p) const{return eq(x, p.x) && eq(y, p.y);}
    double cross(const point &p) const{return x * p.y - y * p.x;}
};

istream &operator>>(istream &is, point &p){return is >> p.x >> p.y;}
ostream &operator<<(ostream &os, const point &p){return os << "(" << p.x << ", " << p.y << ")";}

vector<point> convexHull(vector<point> P) {
    sort(P.begin(), P.end());
    vector<point> L, U;
    for (int i = 0; i < P.size(); i++) {
        while (L.size() >= 2 && le((L[L.size() - 2] - P[i]).cross(L[L.size() - 1] - P[i]), 0)) {
            L.pop_back();
        }
        L.push_back(P[i]);
    }
    for (int i = P.size() - 1; i >= 0; i--) {
        while (U.size() >= 2 && le((U[U.size() - 2] - P[i]).cross(U[U.size() - 1] - P[i]), 0)) {
            U.pop_back();
        }
        U.push_back(P[i]);
    }
    L.pop_back();
    U.pop_back();
    L.insert(L.end(), U.begin(), U.end());
    return L;
}

bool pointInConvexHull(const vector<point> &poly, point p) {
    int n = poly.size();
    if(n < 3) return false;
    rep(i,0,n) {
        point a = poly[i], b = poly[(i+1) % n];
        double cp = (b - a).cross(p - a);
        if(!le(0, cp)) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    double h;
    cin >> n >> h;

    vector<point> islands(n);
    vector<double> time(n), heights(n);
    rep(i,0,n) {
        cin >> islands[i] >> heights[i];
        islands[i].idx = i;
        time[i] = max(0.0, h - heights[i]);
    }

    double l = 0.0, r = *max_element(all(time));
    point c;
    cin >> c;
    auto valid = [&](double t) {
        vector<point> aux;
        rep(i,0,n) {
            if(t >= time[i]) aux.pb(islands[i]);
        }
        if(aux.size() < 3) return false;
        aux = convexHull(aux);
        return pointInConvexHull(aux, c);
    };

    if(!valid(r)) {
        cout << -1 << endl;
        return 0;
    }

    for(int it=0; it<100; it++) {
        double m = (l + r) / 2.0;
        if(valid(m)) {
            r = m;
        }
        else {
            l = m;
        }
    }
    cout << fixed << setprecision(12) << r << endl;

    return 0;
}