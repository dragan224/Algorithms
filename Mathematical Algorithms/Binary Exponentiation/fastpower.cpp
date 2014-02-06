#include <iostream>
using namespace std;

int naivePower(int a, int b, int mod) {
    int res = 1;
    for (int i = 1; i <= b; i++) {
        res = 1LL * res * a % mod;
    }
    return res;
}

int fastPower(int a, int b, int mod) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = 1LL * res * a % mod;
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    return 0;
}
