//You are in an infinite 2D grid where you can move in any of the 8 directions : (x,y) to (x+1, y), (x - 1, y), (x, y+1), (x, y-1), (x-1, y-1), (x+1,y+1), (x-1,y+1), (x+1,y-1). You are given a sequence of points and the order in which you need to cover the points. Give the minimum number of steps in which you can achieve it. You start from the first point.

//Input:  Given two integer arrays A and B, where A[i] is x coordinate and B[i] is y coordinate of ith point respectively.[(0, 0), (1, 1), (1, 2)]
//Output: 2


#include<bits/stdc++.h>
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define PB push_back

using namespace std;

int coverPoints(vector<int> A, vector<int> B){
	int dist = 0;
	int n = A.size();

	FOR(i, 0, n-1){
		int x = abs(A[i] - A[i+1]);
		int y = abs(B[i] - B[i+1]);
		dist += max(x, y);
	}
	return dist;
}

int main(){
	int n=0, temp=0;
	vector<int> A, B;
	
	cin >> n;
	FOR(i, 0, n){
		cin >> temp;
		A.PB(temp);
	};

	FOR(i, 0, n){
		cin >> temp;
		B.PB(temp);
	};

	cout << coverPoints(A, B) << endl;
	return 0;
}
