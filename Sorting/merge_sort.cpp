#include<bits/stdc++.h>
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define PB push_back

using namespace std;

void merge(vector<int> &v, int l, int m, int r){
	int i, j, k;
	int n1 = m - l + 1;
        int n2 = r - m;
	int left_arr[n1], right_arr[n2];

	FOR(i, 0, n1)
		left_arr[i] = v[l + i];

	FOR(j, 0, n2)
		right_arr[j] = v[m + 1 + j];
	
	i=0;
	j=0;
	k=l;
	while(i<n1 && j<n2){
		if(left_arr[i] <= right_arr[j]){
			v[k] = left_arr[i];
			i++;
		}

		else{
			v[k] = right_arr[j];
			j++;
		}
		k++;
	//	cout<<v[k]<<" ";
	}

	while(i < n1){
		v[k] = left_arr[i];
		i++;
		k++;
	}
	
	while(j < n2){
		v[k] = right_arr[j];
		j++;
		k++;
	}
}


void merge_sort(vector<int> &v, int l, int r){
	if(r > l){
		int m = l + (r-l)/2;
		merge_sort(v, l, m);
		merge_sort(v, m+1, r);
		merge(v, l, m, r);
	}
}

void print(vector<int> v, int n){
	FOR(i, 0, n)
		cout << v[i] << " "; 
}


int main(){
	int n=0, temp=0;
	vector<int> v;

	cin >> n;
	
	FOR(i, 0, n){
		cin >> temp;
		v.PB(temp);
	}
	
	merge_sort(v, 0, n-1);
	print(v, n);
	return 0;
}
