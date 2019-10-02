#include <iostream>

using namespace std;

int main(){
    int N; cin >> N;
    int f1 = 2, f2 = 8;
    int sum = 10;
    int fn = 34;
    while (fn < N){
        sum += fn;
        int temp = f2;
        f1 = f2;
        f2 = fn;
        fn = 4*f2 + f1;
    }
    cout << sum << endl;
    return 0;
}