#include<iostream>
using namespace std;
long long a,b,l,bin=1;
string ans;
int main() {
    cin>>a>>b;
    for(int i=0;(l|=bin)%b;bin*=2,i++) { //만들 수 있는 패턴의 길이 체크
        if(i == 60) {
            cout<<-1;
            return 0;
        }
    }
    a*=l/b; //약분이 되었다면 약분되기 전 값으로 만들어주기
    l=0; //패턴의 길이 체크
    while(bin) {
        if(++l>60) {
            cout<<-1;
            return 0;
        }
        if(a>=bin) {
            ans+="*";
            a-=bin;
        } else ans+="-";
        bin/=2;
    }
    cout<<ans;
    return 0;
}