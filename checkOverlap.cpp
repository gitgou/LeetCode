#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        float x_center = x1 + (x2 - x1) / 2.0;
        float y_center = y1 + (y2 - y1) / 2.0;
        vector<float> p = {abs(xCenter - x_center), abs(yCenter - y_center)};
        vector<float> q = {abs(x2 - x_center), abs(y2 - y_center)};

        vector<float> r = {max<float>((p[0] - q[0]), 0.0), max<float>((p[1] - q[1]), 0.0)};
        return sqrt(pow(r[0], 2) + pow(r[1], 2)) <= radius;
    }