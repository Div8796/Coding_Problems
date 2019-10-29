int Solution::titleToNumber(string A) {
    int len = A.length();
    int col_num = 0;
    int char_to_int = 0;
    int j=0;
    for(int i=len-1; i>=0; i--){
        char_to_int = (A[i] % 65) + 1;
        // cout << char_to_int<<" ";
        col_num += char_to_int * pow(26, j);
        // cout << col_num <<endl;
        j++;
    }
    return col_num;
}

