/*
참고 https://mapocodingpark.blogspot.com/2020/01/inu-2019-open-contest.html
두 오리 사이의 거리를 L이라 할 때, 각 오리는 2^(n-1) 만큼 뛰므로 L이 홀수이면 만날 수 없다.
A의 위치 < B의 위치라고 가정할 때,
1. A 왼 / B 왼 - 거리 유지
2. A 오 / B 오 - 거리 유지
3. A 오 / B 왼 - 거리 축소
4. A 왼 / B 오 - 거리 증가 => 고려 X

해당 일에 A,B가 점프할 수 있는지 체크
거리를 유지할 때 왼쪽으로 움직일 수 없으면 오른쪽으로 움직일 수 있는지 확인
*/

#include <iostream>
#define swap(a,b) {int t;t=a;a=b;b=t;}
using namespace std;
int ans,dist,N,A,B;
bool dfs(int d,int x,int y) {
    int j=1<<d;
    if(d>ans) return 1;
    if(dist&j) return dfs(d+1, x+j/2,y-j/2);
    else {
        if(x-j/2 > 0) if(dfs(d+1,x-j/2,y-j/2)) return 1;
        if(y+j/2 <= N) if(dfs(d+1,x+j/2,y+j/2)) return 1;
    }
    return 0;
}
int main() {
    cin>>N>>A>>B;
    if(A>B) swap(A,B);
    dist=B-A;
    int temp=B-A;
    if(dist&1) cout<<-1;
    else {
        while(temp) {temp/=2,ans++;}
        ans--;
        cout<<(dfs(1,A,B)?ans:-1);
    }
    return 0;
}