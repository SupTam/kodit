#include <iostream>

using namespace std;

int main () {
    int N;
    cin >> N;
    int f1 = 1;
    int f2 = 2;
    int fn = 3;
    int sum = 2;
    while (fn < N) {
        if (fn % 2 == 0) {
            sum += fn;
        }
        int temp = f2;
        f2 = fn;
        f1 = temp;
        fn = f1 + f2;
    }
    cout << sum << endl;
    return 0;
}