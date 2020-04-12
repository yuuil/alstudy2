#include <iostream>
#include <cstring>
using namespace std;
int N,M,K,dp[11][221][221];
int dfs(int idx, int pre, int r) {
    if(idx>N) return r==0;
    int &ret=dp[idx][pre][r];
    if(ret!=-1) return ret;
    ret=0;
    for(int i=pre; i<=M; i++) {
        if(i*(N-idx)<=r-i) ret+=dfs(idx+1,i,r-i);
    }
    return ret;
}
void seq(int idx, int pre, int r, int sum) {
    if(idx>N) return;
    for(int i=pre; i<=M; i++) {
        if(i*(N-idx)<=r-i) {
            int pivot = dfs(idx+1,i,r-i);
            if(sum>=pivot) sum-=pivot;
            else {
                cout<<i<<" ";
                return seq(idx+1,i,r-i,sum);
            }
        }
    }
}
int main() {
    cin>>N>>M>>K;
    memset(dp,-1,sizeof(dp));
    seq(1,1,M,K-1);
    return 0;
}