//Inversion Count for an array indicates – how far (or close) the array is from being sorted. 
//If array is already sorted then inversion count is 0. 
//If array is sorted in reverse order that inversion count is the maximum.
//Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j
//Input: 2 4 1 3 5
//Output: 3

#include<bits/stdc++.h>
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define PB push_back

using namespace std;

//Approach 1: Basic approach
//TC: O(n^2)
int inv_count(vector<int> v, int n){
	int count = 0;
	FOR(i, 0, n)
		FOR(j, i+1, n)
			if(v[i] > v[j])
				count++;
	return count;
}

//Approach 2: Merge sort
int main(){
	int n=0, temp=0;
	vector<int> v;

	cin >> n;
	FOR(i, 0, n){
		cin >> temp;
		v.PB(temp);
	}
	cout<< inv_count(v, n) << endl;
	return 0;
}
