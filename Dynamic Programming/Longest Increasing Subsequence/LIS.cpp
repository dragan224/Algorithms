#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <set>
using namespace std;

int greedyLIS(int a[], int n) {
    set<int> s;
    set<int>::iterator it;
    for (int i = 0; i < n; i++) {
        if (s.find(a[i]) != s.end()) continue;
        s.insert(a[i]);
        it = s.find(a[i]);
        it++;
        if (it != s.end()) s.erase(it);
    }
    return s.size();
}

int dpLIS(int a[], int n) {
    int* dp = new int[n];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--) {
            if (a[i] > a[j] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        ans = max(ans, dp[i]);
    }
    delete dp;
    return ans;
}

int main() {
    return 0;
}
