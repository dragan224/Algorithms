#include <cstdio>
using namespace std;

long long mulmod(long long A, long long B, long long P) {
    long long result = 0;
    while (A > 0) {
        if (A & 1) result = (result + B) % P;
        B = (B << 1) % P;
        A >>= 1;
    }
    return result;
}

int main() {
    long long A, B, P;
    scanf("%lld %lld %lld", &A, &B, &P);
    printf("%lld\n", mulmod(A, B, P));
    return 0;
}
