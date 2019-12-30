#include <iostream>

using namespace std;

int N, M, num, cnt;
long long accum[10001];

int main() {
    cin>>N>>M;
    for(int i=1; i<=N; i++) {
        cin>>num;
        accum[i] += accum[i-1] + num;
        if(accum[i] == M) {
            cnt++;
        }
    }
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=i-1; j++) {
            if(accum[i] - accum[j] == M) {
                cnt++;
            }
        }
    }
    cout<<cnt<<"\n";
    return 0;
}
