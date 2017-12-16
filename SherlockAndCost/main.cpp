// https://www.hackerrank.com/challenges/sherlock-and-cost/problem
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

int f(const vector<int> &B) {
    // from discution:
    // L(i) = max cost using first i items of array B, ending with 1 at i th position. {note: 1 is low so we use L to denote low}
    // H(i) = max cost for first i items of array B, ending in Bi at i th position. {note: Bi is higher of 1 or Bi thus use H to denote that}
    // F(i) = max cost for first i items regardless of ending.
    // L(i) = max (L(i-1),H(i-1)+|B(i-1) - 1|)
    // H(i) = max (H(i-1)+|B(i)-B(i-1)|,L(i-1)+|B(i) - 1|)
    // F(i) = max (L(i),H(i))
    vector<int> F(B.size());
    vector<int> H(B.size());
    vector<int> L(B.size());

    for (int i = 2; i < B.size(); ++i) {
        L[i] = max(L[i - 1], H[i - 1] + B[i - 1] - 1);
        H[i] = max(L[i - 1] + B[i] - 1, H[i - 1] + abs(B[i] - B[i - 1]));
        F[i] = max(L[i], H[i]);
    }

    return F[F.size() - 1];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T = 0;
    cin >> T;

    for (int i = 0 ; i < T; ++i) {
        int N = 0;
        cin >> N;
        vector<int> B(N + 1);
        for (int j = 1; j <= N; ++j) {
            cin >> B[j];
        }

        cout << f(B) << endl;
    }

    return 0;
}

