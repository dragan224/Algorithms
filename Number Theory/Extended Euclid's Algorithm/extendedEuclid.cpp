#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

pair<int, int> extendedEuclid(int r0, int r1) {
    int sprev = 1, tprev = 0;
    int scurr = 0, tcurr = 1;
    while (r1 != 0) {
        int rnew = r0 % r1;
        int q = r0 / r1;
        r0 = r1;
        r1 = rnew;
        int snew = sprev - scurr * q;
        int tnew = tprev - tcurr * q;
        sprev = scurr; tprev = tcurr;
        scurr = snew; tcurr = tnew;
    }
    return make_pair(sprev, tprev);
}

int main() {
    return 0;
}
