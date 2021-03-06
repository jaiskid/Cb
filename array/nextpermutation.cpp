#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define mp make_pair
#define pb push_back
#define fi first
#define si second
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define AS 200001
#define mod 1000000007
int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
		int n;
		cin >> n;
		int arr[n];
		F(arr, n);
		int dip = -1;
		int dipValue = -1;
		for (int i = n - 1; i >= 0; i--) {
			if (i > 0) {
				if (arr[i] > arr[i - 1]) {
					dip = i - 1;
					dipValue = arr[i - 1];
					break;
				}
			}
		}
		if (dip == -1) {
			for (int i = n - 1; i >= 0; i--) {
				cout << arr[i] << " ";
			}
			continue;
		}
		//finding just greater element than dp
		int temp = 0;
		int k = -1;
		for (int i = n - 1; i >= dip; i--) {
			if (arr[i] > dipValue) {
				temp = arr[i];
				k = i;
				break;
			}
		}
		arr[k] = dipValue;
		arr[dip] = temp;
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = n - 1; i > dip; i--) {
			pq.push(arr[i]);
		}
		for (int i = dip + 1; i < n; i++) {
			arr[i] = pq.top();
			pq.pop();
		}
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
	}
}