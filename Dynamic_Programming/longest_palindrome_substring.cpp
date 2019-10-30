//Given a string, find the longest substring which is palindrome.
//Input: geeks
//output: ee

#include<bits/stdc++.h>
#define FOR(i, a, b) for(int i=a; i<b; i++)

using namespace std;

void print_substring(string str, int start, int end){
	FOR(i, start, end+1){
		cout << str[i];
	}
	cout << endl;
}

//Approach 1: Using DP
int longest_palindrome_substring(string str){
	int len = str.length();
	bool table[len][len];
	int max_len = 1, start=0;

	memset(table, 0, sizeof(table));	
	
	//Substring of length 1
	FOR(i, 0, len)
		table[i][i] = true;

	//Substring of length 2
	FOR(i, 0, len-1){
		if(str[i] == str[i+1]){
			table[i][i+1] = true;
			start = i;
			max_len = 2;
		}
	}

	//Substring of length more than 2
	FOR(k, 3, len+1){
		FOR(i, 0, len-k+1){
			int j = i + k - 1;
			if(table[i+1][j-1] && str[i] == str[j]){
				table[i][j] = true;
				
				if(k > max_len){
					max_len = k;
					start = i;
				}
			}
		}
	}
	print_substring(str, start, start + max_len - 1);
	return max_len;
}
int main(){
	string str;
	cin >> str;
	cout << longest_palindrome_substring(str) << endl;
	return 0;
}
