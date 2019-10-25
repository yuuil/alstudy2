#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
 
using namespace std;

int n,k;
//크기를 1001로하면 런타임 에러난다 
pair<int,int> v[1010];
bool check[1010];
 
int main(){
 	
 	cin>>n>>k;
 	//v.push_back({0,0});
 	for(int i=1;i<=n;i++){
 		//int x,y;
 		//cin>>x>>y;
 		//v.push_back({x,y});
 		cin>>v[i].first>>v[i].second;
	}
	//v.push_back({10000,10000});
 	v[n+1]={10000,10000};
 	int low=1,high=14144;
	while(low<=high){
		queue<int> q,cq;
 		int fl=0,mid=(low+high)/2;
 		for(int i=1;i<=n+1;i++) check[i]=false;
		q.push(0),cq.push(0);
		check[0]=true;
		while(!q.empty()){
			int cur=q.front(),cnt=cq.front();
			q.pop(),cq.pop();
			if(cur==n+1){
				fl=1;
				break;
			}
			if(cnt==k+1){
				continue;
			}
			for(int i=1;i<=n+1;i++){
				if(!check[i] && mid*mid>(v[cur].first-v[i].first)*(v[cur].first-v[i].first)+(v[cur].second-v[i].second)*(v[cur].second-v[i].second)){
					check[i]=true;
					q.push(i);
					cq.push(cnt+1);
				}
			}
		}
		if(fl){
			high=mid-1;
		}else{
			low=mid+1;
		}
	}
 	cout<<low/10+!(!(low%10));
}
