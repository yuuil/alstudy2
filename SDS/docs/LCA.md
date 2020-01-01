# LCA(Lowet Common Ancestor)

> 두 정점 u, v 에서 가장 가까운 공통 조상을 찾는 알고리즘.



#### 풀이과정

1. 두 정점의 깊이를 동일하게 맞춘다.
2. 부모를 따라가며 공통된 조상을 찾을 때까지 탐색.



LCA를 O(logN)만에 구하기 위해 각 정점의 깊이와 부모를 dfs를 통해 저장.

`ac[x][i]` 는 x의 2<sup>i</sup> 번째 조상을 의미.

- i =0, 노드 x의 부모.

```c++
int ancestor = ac[x][i-1]; //x의 2^i번째 조상
ac[x][i] = ac[ancestor][i-1];

/*
즉, ac[here][i] = ac[tmp][i-1]은
here의 2^i번째 조상은 tmp의 2^(i-1)번째 조상의 2^(i-1)번째 조상과 같다는 의미
예를들어 i = 3일때
here의 8번째 조상은 tmp(here의 4번째 조상)의 4번째 조상과 같다.
i =  4일때 here의 16번째 조상은 here의 8번째 조상(tmp)의 8번째와 같다.
*/
```

[LCA 참고](https://www.crocus.co.kr/660)

