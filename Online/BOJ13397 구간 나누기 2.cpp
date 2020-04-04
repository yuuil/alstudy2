#include <iostream>

using namespace std;
int N,M,arr[5001];

bool divide(int score) {
    int cnt = 1, l, h;
    l = h = arr[0];
    for(int i=1; i<N; i++) {
        l = min(l, arr[i]), h = max(h, arr[i]);
        if(h - l > score) {
            cnt++;
            l = h = arr[i];
        }
    }
    return cnt <= M;
}

int main() {
    cin>>N>>M;
    int l = 0, r = 1e4;
    for(int i=0; i<N; i++) {
        cin>>arr[i];
    }
    while(l <= r) {
        int mid = (l+r)/2;
        if(divide(mid)) r = mid-1;
        else l = mid+1;
    }
    cout<<l<<"\n";
    return 0;
}