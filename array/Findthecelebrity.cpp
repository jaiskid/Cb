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
int getId(int arr[][1005], int n) {
	stack<int> s;
	for (int i = 0; i < n; i++)
		s.push(i);
	while (s.size() > 1) {
		int a = s.top();
		s.pop();
		int b = s.top();
		s.pop();
		if (arr[a][b] == 0)
			s.push(a);
		else
			s.push(b);
	}
	int x = s.top();
	s.pop();
	bool flag = true;
	for (int i = 0; i < n; i++) {
		if (i == x)
			continue;
		if (arr[x][i] == 1 || arr[i][x] == 0)
			flag = false;

	}
	if (!flag)
		return -1;
	return x;
}
int main() {
	fastIO
	int n;
	cin >> n;
	int arr[1005][1005];
	NF(arr, n, n);
	cout << getId(arr, n);
}