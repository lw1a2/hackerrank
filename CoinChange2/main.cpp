// https://www.hackerrank.com/challenges/coin-change/problem
// new problem description and inputting format
// 12-12-2017
#include <bits/stdc++.h>

using namespace std;

long getWaysImpl(long n, const vector<long> &c, int m, vector<vector<long> > &memo)
{
    if (n == 0) {
        // all memo[0][m] = 1
        return 1;
    }

    if (m < 0) {
        return 0;
    }

    if (memo[n][m]) {
        return memo[n][m];
    }

    int k = 0;
    while (n - k * c[m] >= 0) {
        memo[n][m] += getWaysImpl(n - k * c[m], c, m - 1, memo);
        ++k;
    }

    return memo[n][m];
}

// http://www.ideserve.co.in/learn/coin-change-problem-number-of-ways-to-make-change
long getWays(long n, const vector<long> &c){
    // Complete this function
    vector<long> v(c.size());
    // memo[n][m]: n: the number need to build, m: use 0..m kinds of coins to build
    // example: c = {1, 2, 3}, n = 4
    // memo[4][2] = (0 of 3 + use {1, 2} to build) = memo[4][1]
    // memo[4][2] += (1 of 3 + use {1, 2} to build) = memo[4 - 3][1] = memo[1][1]
    vector<vector<long> > memo(n + 1, v);

    return getWaysImpl(n, c, c.size() - 1, memo);
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<long> c(m);
    for(int c_i = 0; c_i < m; c_i++){
       cin >> c[c_i];
    }
    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
    long ways = getWays(n, c);
    cout << ways;
    return 0;
}

