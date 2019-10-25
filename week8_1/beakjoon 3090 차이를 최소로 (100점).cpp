#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;
typedef pair<int, p> pp;

long long n, t;
vector<int> v;

bool chk(int mid){
	long long cnt = 0;
	vector<int> arr;
	for(auto i : v) arr.push_back(i);

	for(int i=1; i<n; i++){
		if(arr[i-1]+mid < arr[i]){
			cnt += arr[i] - (arr[i-1] + mid);
			arr[i] = arr[i-1] + mid;
		}
		if(cnt > t) return false;
	}

	for(int i=n-1; i>0; i--){
		if(arr[i]+mid < arr[i-1]){
			cnt += arr[i-1] - (arr[i] + mid);
			arr[i-1] = arr[i] + mid;
		}
		if(cnt > t) return false;
	}
	return true;
}

void print(int mid){
	vector<int> arr;
	for(auto i : v) arr.push_back(i);

	for(int i=1; i<n; i++){
		if(arr[i-1]+mid < arr[i]){
			arr[i] = arr[i-1] + mid;
		}
	}

	for(int i=n-1; i>0; i--){
		if(arr[i]+mid < arr[i-1]){
			arr[i-1] = arr[i] + mid;
		}
	}

	for(auto i : arr) cout << i << " ";
}

int main(){
	cin >> n >> t;
	v.resize(n);
	int l = 0, r = 0;
	for(int i=0; i<n; i++) cin >> v[i], r = max(r, v[i]);
	int mid;
	for(int i=0; i<500; i++){
		mid = (l+r) >> 1;
		if(chk(mid)) r = mid;
		else l = mid;
	}
	print(r);
}
