/*
dp[i][j][k] => 길이가 i이고, 마지막 수가 j이면서 합이 k인 수열의 개수
구해야 하는 수열의 번호가 현재까지 합쳐진 것보다 크다면 누적된 수열 개수 뺌
현재 채우는 수가 구해야 하는 수열의 번호보다 작다면 해당 수열을 이루는 수임
*/
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
        if(i*(N-idx)<=r-i) ret+=dfs(idx+1,i,r-i); //현재에서 i를 채우고 남은 합이 남은 길이를 i로 채우는 것보다 크거나 같으면 수열의 개수 추가
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