# WEEK8_1 파라메트릭 서치(2)

### 1939. 중량제한

- 파라메트릭 서치와 BFS를 동시에 사용해야 하는 문제

- 옮길 수 있는 물품들의 중량의 최댓값을 구하는 것이 목적이기 때문에 거리는 상관없다.

- 다리의 최대 무게를 최대값으로 설정해 이분탐색을 하며 시작노드에서 마지막노드를 탐색하면 high반환

- ```c++
  #include <iostream>
  #include <queue>
  #include <vector>
  #include <cstring>
  using namespace std;
  int n,m,target1,target2;
  long long low,high,mid;
  vector<pair<int, int> > v[10001];
  bool check[10001];
  bool bfs(int start){
      // 방문노드 초기화
  	memset(check,0,sizeof(check));
  	queue<int> q;
  	q.push(start);
  	check[start]=true;
  	while(!q.empty()){
  		int x=q.front();
  		q.pop();
          // 마지막 노드 탐색시 true 반환
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
  ```

  

### 느낀점

- 점점 어려워지고 있다.... 문제에서 하나의 접근방법을 요구하는 것이 아니라 여러 알고리즘이 응용되어 여러가지 변수를 고려해야 한다. 

