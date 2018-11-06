#include <iostream>
using namespace std;
long solve(long n) {
    long have = 1;
    long nothave = 1;
    for (long i = 1; i < n; ++i) {
        long new_have = nothave;
        long new_nothave = have+nothave;
        have = new_have;
        nothave = new_nothave;
    }
    return have+nothave;
}
 
int main(void) {
    long n = 0;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}
