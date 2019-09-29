#include <iostream>

using namespace std;

int main(){
    int N, sum = 0;
    cin >> N;
    for (int i=0; i<N ; i++) {
        if (i%3 == 0 || i%5 == 0){
            sum += i;
        }
    }
    cout << sum << endl;
    return 0;
}
