//Find the sum of contiguous subarray within a one-dimensional array of numbers which has the largest sum.
//Input: -2 -3 4 -1 -2 1 5 -3
//Output: 7

#include<bits/stdc++.h>
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define PB push_back

using namespace std;

//Approach 1: Kadane's algorithm
int largest_sum_contd_subarray(vector<int> v, int n){
	int max_so_far = INT_MIN, max_ending_here=0;

	FOR(i, 0, n){
		max_ending_here += v[i];
		if(max_so_far < max_ending_here)
			max_so_far = max_ending_here;
		if(max_ending_here < 0)
			max_ending_here = 0;
	}
	return max_so_far;
}

int main(){
	int n=0, temp=0;
	vector<int> v;

	cin >> n;
	FOR(i, 0, n){
		cin >> temp;
		v.PB(temp);
	}

	cout << largest_sum_contd_subarray(v, n) << endl;
	return 0;
}
