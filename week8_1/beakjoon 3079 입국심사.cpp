#include<iostream>

using namespace std;

int n,m; 
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
