// https://www.hackerrank.com/challenges/equal/problem
// This is not dynamic programming
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int make_equal(vector<int> &v) {
    int min = -1, ops = -1;

    for (int i = 0; i < v.size(); ++i) {
        if (min == -1 || min > v[i]) {
            min = v[i];
        }
    }

    for (int j = 0; j < 3; ++j) {
        int r = 0;
        for (int i = 0; i  < v.size(); ++i) {
            int m = v[i] - min + j;
            r += m / 5;
            r += (m % 5) / 2;
            r += (m % 5) % 2;
        }
        if (ops == -1 || ops > r) {
            ops = r;
        }
    }

    return ops;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int tc_n = 0, colleagues = 0;

    cin >> tc_n;
    for (int i = 0; i < tc_n; ++i) {
        cin >> colleagues;
        vector<int> v;
        for (int j = 0; j < colleagues; ++j) {
            int k = 0;
            cin >> k;
            v.push_back(k);
        }

        cout << make_equal(v) << endl;
    }

    return 0;
}

