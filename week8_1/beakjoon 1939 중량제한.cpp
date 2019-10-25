#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int n,m,target1,target2;
long long low,high,mid;
vector<pair<int, int> > v[100001];
bool check[100001];

bool bfs(int start){
	memset(check,0,sizeof(check));
	queue<int> q;
	q.push(start);
	check[start]=true;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		if(x==target2){
			return true;
		}
		for(int i=0;i<v[x].size();i++){
			if(mid<=v[x][i].second&&!check[v[x][i].first]){
				check[v[x][i].first]=true;
				q.push(v[x][i].first);
			}
		}
	}
	return false;
}

int main(){
	
	cin>>n>>m;
	
	for(int i=0;i<m;i++){
		int island1,island2,weight;
		cin>>island1>>island2>>weight;
		v[island1].push_back({island2,weight});
		v[island2].push_back({island1,weight});
		if(high<weight){
			high=weight;
		}
	}
	cin>>target1>>target2;
	while(low<=high){
		mid=(low+high)/2;
		if(bfs(target1)){
			low=mid+1;
		}else{
			high=mid-1;
		}
	}
	cout<<high;
}
