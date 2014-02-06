#include <iostream>
using namespace std;

int GCD(int a, int b) {
    if (b == 0) return a;
    return GCD(b, a%b);
}

int interativeGCD(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int LCM(int a, int b) {
    return (a / GCD(a, b)) * b;
}

int main() {
    return 0;
}
