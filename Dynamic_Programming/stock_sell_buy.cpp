//The cost of a stock on each day is given in an array.
//Find the max profit that you can make by buying and selling in those days.

#include<bits/stdc++.h>
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define PB push_back

using namespace std;

//Only one transaction is allowed
//Approach 1:
//TC: O(n) SC:O(1)
int max_allowed_transaction_1(vector<int> v, int n){
	int max_diff = v[1] - v[0];
	int min_ele = v[0];

	FOR(i, 1, n){
		int diff = v[i] - min_ele;
		if(diff > max_diff)
			max_diff = diff;
		if(min_ele > v[i])
			min_ele = v[i];
	}	
	return max_diff;
}

//Multiple transactions are allowed
//TC: O(n) SC:O(1)
int max_profit(vector<int> v, int n){
	int buy=0, sell=0, i=0, profit=0;
	
	if(n==1)
		return 0;
	while(i < n-1){
		while((i < n-1) && (v[i+1] <= v[i]))
			i++;
		if(i == n-1)
			break;
		buy = i++;

		while((i < n) && (v[i] >= v[i-1]))
			i++;
		sell = i-1;
		profit += (v[sell] - v[buy]);
	}
	return profit;
}

int main(){
	int n=0, temp=0, k=0;
	vector<int> v;

	cin >> n >> k;
	FOR(i, 0, n){
		cin >> temp;
		v.PB(temp);	
	}
	cout << max_allowed_transaction_1(v, n) << endl;
	cout << max_profit(v, n) << endl;
	cout << max_allowed_transaction_k(v, n) << endl;
	return 0;
}
