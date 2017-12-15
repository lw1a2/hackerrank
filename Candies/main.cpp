// https://www.hackerrank.com/challenges/candies

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long f(const vector<int>& v) {
    // m[i]表示值为i的人所组成的数组。
    // m[i][j]表示此数组中第j个人在v里的下标
    vector<vector<int> > m(100001);
    for (int k = 0; k < v.size(); ++k) {
        m[v[k]].push_back(k);
    }

    // 糖果数组
    vector<long> s(v.size(), 1);
    for (int i = 0; i < m.size(); ++i) {
        for (int j = 0; j < m[i].size(); ++j) {
            int k = m[i][j];
            // cout << v[k] << endl;
            if (k > 0) {
                // 左侧有人
                if (v[k - 1] > v[k]) {
                    // 左侧比当前表现好
                    if (s[k - 1] <= s[k]) {
                        // 左侧的糖果数没有当前的好
                        s[k - 1] = s[k] + 1;
                    }
                }
            }

            if (k < v.size() - 1) {
                // 右侧有人
                if (v[k + 1] > v[k]) {
                    // 右侧比当前表现好
                    if (s[k + 1] <= s[k]) {
                        // 右侧的糖果数没有当前的好
                        s[k + 1] = s[k] + 1;
                    }
                }
            }
        }
    }

    long r = 0;
    for (int i = 0; i < s.size(); ++i) {
        r += s[i];
    }

    return r;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int n;
    cin >> n;

    vector<int> v;
    for (int j = 0; j < n; ++j) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    cout << f(v) << endl;

    return 0;
}
