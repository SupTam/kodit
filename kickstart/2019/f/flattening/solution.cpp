#include<iostream>

using namespace std;

int main () {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int N,K;
        cin >> N >> K;
        int A[N];
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        int fix = 0;
        int change = 0;

        for (int i = 0; i < N -1; i++){
            if(A[i] != A[i+1]){
                change++;
            }
        }
        for(int i=0; i < N-1 && change > K; i++){
            if(A[i] != A[i+1]){
                fix++; change --;
                A[i+1] = A[i];
                i ++;
            }
        }

        cout << "Case #" << t+1 << ": " << fix << endl;
    }


    return 0;
}