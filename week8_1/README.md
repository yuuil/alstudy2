# WEEK8_1 파라메트릭 서치(2)

### 1939. 중량제한 ★

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



### 3079. 입국심사

- 이분탐색을 이용해 최소의 입국시간을 출력하는 문제

- mid값을 기준으로 각 심사대에서 걸리는 시간만큼을 나누어 주어 총 인원을 구하고 그 인원이 입력받은 인원보다 같거나 클경우 결과값(result)를 갱신하고 high=mid-1로 설정후 다시 탐색. 그렇지 않다면 low=mid+1.

- ```c++
  #include<iostream>
  using namespace std;
  int n,m; 
  //범위를 보면 알 수 있듯이 int를 초과하기 때문에 long long으로 선언
  long long high,low,mid,sum,result,maxnum;
  int main() {
  	cin>>n>>m;
  	int arr[n];
  	for(int i=0;i<n;i++){
  		cin>>arr[i];
  		if(maxnum<arr[i]){
  			maxnum=arr[i];
  		}
  	}
  	high=maxnum*m;
  	result=high;
  	while(low<=high){
  		mid=(low+high)/2;
  		sum=0;
  		for(int i=0;i<n;i++){
              //mid값을 기준으로 각 심사대에서 걸리는 시간만큼을 나누어 주어 총 인원을 구한다.
  			sum+=mid/arr[i];
  		}
  		if(sum>=m){
  			result=min(result,mid);
  			high=mid-1;	
  		}else{
  			low=mid+1;
  		}
  	}
  	cout<<result;
  }
  ```



### 3090. 차이를 최소로 ★★

- 점수가 있는 서브 태스크문제로 인접한 수의 차이의 최댓값을 가장 작게 만든 배열을 출력해야함

- 배열을 아래에서 위로, 다시 위에서 아래로 총 2번의 순회를 통해 arr+mid값과 다음 또는 이전의 배열값과 비교하며 총 횟수인 T를 초과하는지의 유무로 low, high값을 갱신 (이런 접근방식을 전혀 생각하지 못했다...)

- ```c++
  #include <iostream>
  using namespace std;
  int arr[100005], BUF[100005];
  int n;
  int target;
  int go(int d)
  {
      for (int i = 0; i < n; ++i)
          BUF[i] = arr[i];
      int ans = 0;
      for (int i = 0; i < n - 1; ++i)
      {
          if (BUF[i + 1] > BUF[i] + d)
          {
              ans += BUF[i + 1] - (BUF[i] + d);
              BUF[i + 1] = BUF[i] + d;
          }
      }
      for (int i = n - 1; i > 0; --i)
      {
          if (BUF[i - 1] > BUF[i] + d)
          {
              ans += BUF[i - 1] - (BUF[i] + d);
              BUF[i - 1] = BUF[i] + d;
          }
      }
      if (ans <= target)
          return 1;
      else
          return 0;
  }
  int main(void)
  {	
  	int maxnum=0;
      for (int i = 0; i < 100005; i++)
          arr[i] = BUF[i] = 0;
      cin >> n >> target;
      for (int i = 0; i < n; ++i){
      	cin >> arr[i];
      	maxnum=max(maxnum,arr[i]);
  	}
          
      int low = 0, high = maxnum;
      int mid = (low + high) / 2;
      while (low < high){
          mid = (low + high) / 2;
          //target 안에 수정가능함
          if (go(mid))
              high = mid;
          //target 내에 수정불가능
          else
              low = mid + 1;
      }
      for (int i = 0; i<n; i++)
          cout << arr[i] << " ";
      cout << endl;
      return 0;
  }
  ```

- #### 참고 출처 : [섭 님의 블로그](http://blog.naver.com/PostView.nhn?blogId=zmfldlwl&logNo=221044141645&parentCategoryNo=&categoryNo=56&viewDate=&isShowPopularPosts=true&from=search)



### 느낀점

- 점점 어려워지고 있다.... 문제에서 하나의 접근방법을 요구하는 것이 아니라 여러 알고리즘이 응용되어 여러가지 변수를 고려해야 한다. 접근법을 이해했지만 익숙해지기 위해선 여러번 구현해봐야 할 것 같다.
- BFS를 이용해 현재 상태의 값을 저장 할 때 또 하나의 큐를 이용하여 저장하는 방법이 있다는 것을 배웠다. (**2585 경비행기**)
- **3090 차이를 최소로**문제는 구글링해서 정답을 봤지만 배열을 아래서부터 위로, 위에서부터 아래로 총 2번의 탐색을 통해 차이를 최소로 만든다는 부분이 이해하기 어려웠다. 서브태스크인 만큼 난이도가 제일 높았던 것 같고 이번 주차는 전체적으로 문제가 전부 어려워 문제당 3~4시간 이상 썼던것 같다. 그만큼 충분히 이해할 때까지 여러번 다시 구현해봐야겠다.