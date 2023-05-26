#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double r1, r2, a, b, c;
    cout << "Enter r1: ";
    cin >> r1;
    cout << "\nr2: ";
    cin >> r2;
    cout << "\na: ";
    cin >> a;
    cout << "\nb: ";
    cin >> b;
    cout << "\nc: ";
    cin >> c;

    double min_dist = INFINITY, max_dist = -INFINITY;
    double x_min, y_min, x_max, y_max;

    for (double x = r1; x <= r2; x += 0.01) {
        double y = cos(3 * x) * pow(sin(x), 2);
        if (y < 0) { // point is in the lower half of the plane
            double dist = abs(a * x + b * y + c) / sqrt(pow(a, 2) + pow(b, 2));
            if (dist < min_dist) {
                min_dist = dist;
                x_min = x;
                y_min = y;
            }
            if (dist > max_dist) {
                max_dist = dist;
                x_max = x;
                y_max = y;
            }
        }
    }

    cout << "Least distant point: (" << x_min << ", " << y_min << ")" << endl;
    cout << "Distance to the line: " << min_dist << endl;
    cout << "Most distant point: (" << x_max << ", " << y_max << ")" << endl;
    cout << "Distance to the line: " << max_dist << endl;

    return 0;
}
