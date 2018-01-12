//https://www.hackerrank.com/challenges/fibonacci-modified/problem
#include <bits/stdc++.h>

using namespace std;

unsigned long fibonacciModified(int t1, int t2, int n) {
    // Complete this function
    vector<unsigned long> t(n);
    t[0] = t1;
    t[1] = t2;
    for (int i = 0; i < n - 2; ++i) {
        t[i + 2] = t[i] + pow(t[i + 1], 2);
    }

    return t[n - 1];
}

int main() {
    int t1;
    int t2;
    int n;
    cin >> t1 >> t2 >> n;
    unsigned long result = fibonacciModified(t1, t2, n);
    cout << result << endl;
    return 0;
}
