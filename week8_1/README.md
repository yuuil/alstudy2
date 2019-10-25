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



### 2585 경비행기 ★★

- 이 문제 역시 이분 탐색속에 최소거리를 구하는 BFS를 이용해 가능/불가능을 판별하여 최소값(low) 출력
- 해당 노드의 값을 저장할 큐와 **해당 노드의 상태일 때 경유한 지점의 수를 저장할 큐** 총 2개를 이용

- ```c++
  #include <iostream>
  #include <queue>
  #include <vector>
  #include <cstring>
   
  using namespace std;
  
  int n,k;
  //크기를 1001로하면 런타임에러 
  pair<int,int> v[1010];
  bool check[1010];
  int main(){
   	cin>>n>>k;
   	for(int i=1;i<=n;i++){
   		cin>>v[i].first>>v[i].second;
  	}
   	v[n+1]={10000,10000};
      //최대 길이 (0,0)과 (10000,10000)사이의 거리
   	int low=1,high=14144;
  	while(low<=high){
          //해당 노드의 값을 저장할 큐와 해당 노드의 상태일 때 경유한 지점의 수를 저장할 큐
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
  ```

  



### 느낀점

- 점점 어려워지고 있다.... 문제에서 하나의 접근방법을 요구하는 것이 아니라 여러 알고리즘이 응용되어 여러가지 변수를 고려해야 한다. 

  