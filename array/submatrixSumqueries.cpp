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
void process(int mat[][1005] , int m, int n, int aux[][1005]) {
	for (int i = 0; i < n; i++)
		aux[0][i] = mat[0][i];
	//do column wise sum
	for (int i = 1; i < m; i++) {
		for (int j = 0; j < n; j++) {
			aux[i][j] = mat[i][j] + aux[i - 1][j];
		}
	}
	//do a row wise sum
	for (int i = 0; i < m; i++) {
		for (int j = 1; j < n; j++) {
			aux[i][j] += aux[i][j - 1];
		}
	}
}
int sumQuery(int aux[][1005], int tli, int tlj, int rbi, int rbj) {
	//result is now sum of elements between
	int res = aux[rbi][rbj];
	if (tli > 0)
		res = res - aux[tli - 1][rbj];
	if (tlj > 0 )
		res = res - aux[rbi][tlj - 1];
	if (tli > 0 and tlj > 0)
		res = res + aux[tli - 1][tlj - 1];
	return res;
}
int main() {
	fastIO
	int m, n;
	cin >> m >> n;
	int mat[1005][1005];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	int aux[1005][1005];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			aux[i][j] = 0;
		}
	}
	process(mat, m, n, aux);
	cout << endl;
	PNF(aux, m, n);
	int tli, tlj, rbi, rbj;
	cin >> tli >> tlj >> rbi >> rbj;
	cout << sumQuery(aux, tli, tlj, rbi, rbj);
}