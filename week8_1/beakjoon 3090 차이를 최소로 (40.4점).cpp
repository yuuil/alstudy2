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
