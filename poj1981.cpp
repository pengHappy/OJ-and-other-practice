#include <cstdio>
#include <cmath>
#include <algorithm>
#include <stdio.h>
using namespace std;

#define MAX_N 300 + 16

typedef double p_type;

struct Point {
    p_type x, y;

    Point() {}

    Point(p_type x, p_type y) : x(x), y(y) {}
}ps[MAX_N];

struct PolarAngle {
    p_type angle;
    bool flag; //起点或终点

    const bool operator < (const PolarAngle &other) const{
        return this->angle < other.angle;
    }
}as[MAX_N];

inline p_type distance_of(const Point &P, const Point &Q) {
    return sqrt((P.x - Q.x)*(P.x - Q.x) + (P.y - Q.y)*(P.y - Q.y));
}

inline int solve(const int &n, const p_type &r) {
    int result = 1;
    for(int i = 0; i < n; i++) {
        int m = 0;
        double d;
        for (int j = 0; j < n; ++j) {
            if(j != i && (d = distance_of(ps[i], ps[j])) <= 2) {
                double phi = acos(d / 2.00);
                double theta = atan2(ps[j].y - ps[i].y, ps[j].x - ps[i].x);
                as[m].angle = theta - phi;  as[m++].flag = true;
                as[m].angle = theta + phi;  as[m++].flag = false;
            }
        }

        sort(as, as + m);

        for(int j = 0, sum = 1; j < m; j++) {
            if(as[j].flag)
                sum++;
            else
                sum--;
            result = max(result, sum);
        }
    }

    return result;
}

int main()
{
    int N;
    while(true) {
        scanf("%d", &N);
        if(N <= 0)
            break;

        for(int i = 0; i < N; i++) {
            scanf("%lf %lf", &ps[i].x, &ps[i].y);
        }

        printf("%d\n", solve(N, 1.0));
    }

    return 0;
}
//No. 90
