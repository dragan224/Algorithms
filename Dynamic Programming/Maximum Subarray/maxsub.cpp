#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

//Divide and Conquer approach

int max(int a, int b, int c) {
    return max(max(a, b), c);
}

int midCrossing(int a[], int l, int m, int r) {
    int sum = a[m];
    int maxlsum = a[m];
    for (int i = m - 1; i >= l; i--) {
        sum += a[i];
        maxlsum = max(maxlsum, sum);
    }
    sum = a[m];
    int maxrsum = a[m];
    for (int i = m + 1; i <= r; i++) {
        sum += a[i];
        maxrsum = max(maxrsum, sum);
    }
    return maxrsum + maxlsum - a[m];
}

int solve(int a[], int l, int r) {
    if (l == r) return a[r];
    int m = (l + r) / 2;
    return max(solve(a, l, m),
               solve(a, m + 1, r),
               midCrossing(a, l, m, r));
}

//Dynamic Programming

int dp(int a[], int n) {
    int dpprev = a[0];
    int dpcurr = a[0];
    int answer = a[0];
    for (int i = 1; i < n; i++) {
        dpcurr = max(dpprev + a[i], a[i]);
        dpprev = dpcurr;
        answer = max(answer, dpcurr);
    }
    return answer;
}

int main() {
    return 0;
}
