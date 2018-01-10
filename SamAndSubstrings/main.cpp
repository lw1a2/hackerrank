//https://www.hackerrank.com/challenges/sam-and-substrings
#include <bits/stdc++.h>

using namespace std;

unsigned long substrings(const string& balls) {
    // Complete this function
    if (balls.empty()) {
        return 0;
    }

    const unsigned long m = 1000000007;
    unsigned long r = 0;
    /*
     * example: balls = "972"
     * 0: 9
     * set v[0] = 9
     *
     * 1: 9 + 7 + 97 = v[0] + 7 + 97 = v[0] + 7 * 2 + 9 * 10 = v[0] + (balls[1] - '0') * 2 + v[0] * 10
     * set v[1] = (balls[1] - '0') * 2 + v[0] * 10
     *
     * 2: 9 + 7 + 2 + 97 + 72 + 972 = v[0] + v[1] + 2 + 72 + 972 = v[0] + v[1] + 2 * 3 + 70 + 970 = v[0] + v[1] + 2 * 3 + v[1] * 10 = v[0] + v[1] + (balls[2] - '0') * 3 + v[1] * 10
     * set v[2] = (balls[2] - '0') * 3 + v[1] * 10
     *
     * set v[i + 1] = v[i] * 10 + (balls[i + 1]  - '0') * (i + 2)
     */
    vector<unsigned long> v(balls.size());

    v[0] = balls[0] - '0';
    r = v[0];
    for (int i = 0; i < v.size() - 1; ++i) {
        v[i + 1] = v[i] * 10 + (balls[i + 1] - '0') * (i + 2);
        v[i + 1] %= m;
        r += v[i + 1];
        r %= m;
    }

    return r;
}

int main() {
    string balls;
    cin >> balls;
    int result = substrings(balls);
    cout << result << endl;
    return 0;
}
