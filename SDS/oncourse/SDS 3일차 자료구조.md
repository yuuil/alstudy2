# SDS 3일차 자료구조

> #### Kewords
>
> `스택`	 `큐`	`트리`	`최소/최대 힙`	`세그먼트 트리`	`유니온 파인드`	`그리디 알고리즘`	.etc



BOJ 10828 스택, BOJ 10845 큐, BOJ1927 최소 힙, BOJ1279 최대 힙은 c++의 STL 자체이므로 생략.

***



### [1991 트리 순회][1991 트리 순회]

- 탐색 방법에 따라 preorder(Root-L-R) / inoder(L-Root-R) / postorder (L-R-Root) 순으로 재귀.



***



### [2042 구간 합 구하기][2042 구간 합 구하기] , [1275 커피숍 2][1275 커피숍 2]

- 세그먼트 트리 구현.
- 기본적인 init / update / sum 3개의 함수 구현 필요.

```c++
long long init(long long* tree, long long* num, int node, int start, int end) {
	if(start == end) {
		return tree[node] = num[start];
	}
	return tree[node] = init(tree, num, node*2, start, (start+end)/2) + init(tree, num, node*2+1, (start+end)/2+1, end);
}

void update(long long* tree, int node, int start, int end, int idx, long long diff) {
	if(idx < start || idx > end) {
		return;
	}
	tree[node]+=diff;
	if(start != end) {
		update(tree, node*2, start, (start+end)/2, idx, diff);
		update(tree, node*2+1, (start+end)/2+1, end, idx, diff);
	}
}

long long sum(long long* tree, int node, int start, int end, int l, int r) {
	if(end < l || start > r) {
		return 0;
	}
	if(l <= start && end<= r) {
		return tree[node];
	}
	return sum(tree, node*2, start, (start+end)/2, l, r) + sum(tree, node*2+1, (start+end)/2+1, end, l, r);
}
```



***



### [6416 트리인가?][6416 트리인가?]

- 유니온 파인드를 이용해 노드가 여러 부모를 갖는지 판단.
- 그 외의 경우는 노드의 조상이 같은지 판단.



***



### [4358 생태학][4358 생태학]

- getline으로 한 줄씩 나무의 종을 입력받고, 맵 카운팅 증가.
- c++에서 소수점 n자리로 고정하기.

```c++
cout<<fixed;
cout.precision(n);
```



***



### [1655 가운데를 말해요][1655 가운데를 말해요]

- 최대 힙과 최소 힙을 동시에 사용해야 함.

  1. 최대 힙과 최소 힙의 크기가 같을 때
     - 최소 힙에 값 push.
  2. 최소 힙의 크기가 더 클 때
     - 최대 힙에 값 push.

  최대 힙의 top이 최소 힙의 top보다 크다면 두 값 swap.

  - 중간값을 기준으로 작은 값 중 최대가 최대 힙의 top, 큰 값 중 최소가 최소 힙의 top.

  최소 힙의 size가 더 크다면 최소 힙의 top, 같다면 최대 힙의 top 출력.



***



### [1202 보석 도둑][1202 보석 도둑]

- 보석 가치에 따라 내림차순 정렬되도록 우선순위 큐 사용.
- 가방의 무게는 같은 무게가 여러 개일 수 있고, 오름차순 정렬되어야 하므로 multiset 사용.
- 보석마다 보석보다 무게가 크거나 같은 가방을 lower_bound로 찾아서 보석을 가져갈 가방 매칭.



***



### [2243 사탕상자][2243 사탕상자]

- 처음에 사탕상자가 비어있으므로 세그먼트 트리를 초기화하는 init 함수는 필요 없음.
- K번째 사탕이 어느 사탕인지 알기 위한 query 함수 필요.

```c++
ll query(vector<ll> &tree, int node, int start, int end, int k) {
	if(start == end) {
		return start;
	}
	int mid = (start+end)/2;
	if(tree[node*2] >= k) return query(tree, node*2, start, mid, k);
	else return query(tree, node*2+1, mid+1, end, k-tree[node*2]);
}
```



***



### [3020 개똥벌레][3020 개똥벌레]

- 종유석과 석순의 누적 합을 배열에 저장.
- 개똥벌레가 날아가는 높이에 따라 파괴하는 장애물의 수를 벡터에 넣고 정렬.
  - 가장 적게 파괴하는 개수와 값이 같은 게 있다면 카운팅.



***



### [2094 강수량][2094 강수량]

- 구간 합 구하기와 달리 구간의 최대값을 저장.

1. Y, X 모두 주어진 경우
   - X.r <= Y.r
     1. Y, X 사이의 모든 구간 Z의 강수량이 주어지면서 Z.r < X.r 인 경우 "true"
     2. 모든 구간이 주어지지는 않았으나 주어진 Z에 대해 max(Z.r) < X.r인 경우 "maybe"
2. Y, X 모두 주어지지 않은 경우
   - Y, X 사이 구간의 Z의 최대값이 MAX가 아니면 "maybe"
3. Y만 주어진 경우 / X만 주어진 경우
   - Y, X 사이 구간의 Z의 최대값이 주어진 강수량보다 작다면 "maybe"
4. 그 외
   - "false"



***



[1991 트리 순회]: ./BOJ1991%20트리순회.cpp	"BOJ1991 트리 순회 소스 코드"
[2042 구간 합 구하기]: ./BOJ2042%20구간%20합%20구하기.cpp	"BOJ 2042 구간 합 구하기 소스 코드"
[6416 트리인가?]: ./BOJ6416%20트리인가%3F.cpp	"BOJ 6416 트리인가? 소스 코드"
[4358 생태학]: ./BOJ4358%20생태학.cpp	"BOJ 4358 생태학 소스 코드"
[1655 가운데를 말해요]: ./BOJ1655%20가운데를%20말해요.cpp	"BOJ 1655 가운데를 말해요 소스 코드"
[1202 보석 도둑]: ./BOJ1202%20보석%20도둑.cpp	"BOJ 1202 보석 도둑 소스 코드"
[2243 사탕상자]: ./BOJ2243%20사탕상자.cpp	"BOJ 2243 사탕상자 소스 코드"
[3020 개똥벌레]: ./BOJ3020%20개똥벌레.cpp	"BOJ 3020 개똥벌레 소스 코드"
[1275 커피숍 2]: ./BOJ1275%20커피숍2.cpp	"BOJ 1275 커피숍 2 소스 코드"
[2094 강수량]: ./BOJ2094%20강수량.cpp	"BOJ 2094 강수량 소스 코드"

