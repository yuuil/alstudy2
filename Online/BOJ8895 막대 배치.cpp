/*
참고 https://www.weeklyps.com/entry/BOJ-8895-%EB%A7%89%EB%8C%80-%EB%B0%B0%EC%B9%98
높이가 1인 막대를 기준으로 생각하자
1) 높이가 1인 막대가 제일 왼쪽에 위치할 경우
-> 이 막대를 치우면 왼쪽에서 볼 수 있는 막대의 개수는 하나 줄어듦, 오른쪽에서 볼 수 있는 막대 개수 그대로.
=> n-1개의 막대, l-1개, r개 볼 수 있음
2) 높이가 1인 막대가 제일 오른쪽에 위치할 경우
-> 이 막대를 치우면 오른쪽에서 볼 수 있는 막대의 개수 하나 줄어듦, 왼쪽에서 볼 수 있는 막대 개수 그대로.
=> n-1개의 막대, l개, r-1개 볼 수 있음
3) 높이가 1인 막대가 2 ~ n-1 에 위치할 경우
-> 이 막대를 치워도 보이는 개수 그대로
=> n-1개의 막대, l개, r개 2 ~ n-1 번 반복하므로 (n-2)번 해당 경우 반복
따라서,
dp[n][l][r] = dp[n-1][l-1][r]+dp[n-1][l][r-1]+(n-2)*dp[n-1][l][r];
*/
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
int T,n,l,r;
ll dp[21][21][21];
int main() {
    dp[1][1][1]=1;
    for(int i=2; i<21; i++) {
        for(int j=1; j<=i; j++) {
            for(int k=1; k<=i; k++) {
                dp[i][j][k]=dp[i-1][j-1][k]+dp[i-1][j][k-1]+(i-2)*dp[i-1][j][k];
            }
        }
    }
    cin>>T;
    for(int t=0; t<T; t++) {
        cin>>n>>l>>r;
        cout<<dp[n][l][r]<<"\n";
    }
    return 0;
}