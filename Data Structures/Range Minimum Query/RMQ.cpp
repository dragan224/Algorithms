#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int maxN = 100224;
const int maxLog = 18;

struct RMQ {
    int table[maxN][maxLog];
    void build(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            table[i][0] = arr[i];
        }
        for (int k = 1; k < maxLog; k++) {
            int step = 1 << k-1;
            for (int i = 0; i < n; i++) {
                table[i][k] = table[i][k - 1];
                if (i + step < n) {
                    table[i][k] = min(table[i][k], table[i + step][k - 1]);
                }
            }
        }
    }
    int query(int l, int r) {
        int k = log((double)(r - l)) / log(2.0) + 0.00000224;
        return min(table[l][k], table[r - (1 << k) + 1][k]);
    }
};

int main() {
    return 0;
}
