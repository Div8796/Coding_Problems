#include<bits/stdc++.h>

#define FOREQ(i, a, b) for(int i=a; i<=b; i++)

using namespace std;

//Approach 1: Using recursion
int find_ways_rec(int m, int n, int x){
	if(x<1)
		return 0;
	if(n==1)
		return (x <= m);

	int no_of_ways=0;
	FOREQ(i, 1, m)
		no_of_ways += find_ways_rec(m, n-1, x-i);
	return no_of_ways;
}

//Approach 2: Using DP
int find_ways_dp(int m, int n, int x){
	int table[n+1][x+1];
	memset(table, 0, sizeof(table));

	for(int j=1; j<=m && j<=x; j++)
		table[1][j] = 1;

	FOREQ(i, 2, n)
		FOREQ(j, 1, x)
			for(int k=1; k<=m && k<j; k++)
				table[i][j] += table[i-1][j-k];

	return table[n][x];
}

int main(){
	int m=0, n=0, x=0;
	cin >> m >> n >> x;
	cout << find_ways_rec(m, n, x) << endl;
	cout << find_ways_dp(m, n, x) << endl;
	return 0;
}
