#include <iostream>

using namespace std;
int Sn(int n){
    return n*(n+1)/2;
}
int main(){
    int N, sum = 0;
    cin >> N;
    cout << 3*Sn(N/3) + 5*Sn(N/5) - 15*Sn(N/15) << endl;
    return 0;
}
