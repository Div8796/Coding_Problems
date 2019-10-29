vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>> vec;
    vector<int> row;
    
    for(int i=0; i<A; i++){
        for(int j=0; j<=i; j++){
            if(j==0)
                row.push_back(1);
            else if(j==i)
                row.push_back(1);
            else{
                int temp = vec[i-1][j-1] + vec[i-1][j];
                row.push_back(temp);
            }    
        }
        vec.push_back(row);
        row.clear();
    }
    return vec;
}


##Better way to use 2-d vector
vector<vector<int> > Solution::generate(int A) {
    if (A == 0) { return {}; }
    vector<vector<int>> r(A);
    r[0].push_back(1);
    for (int i = 1; i < A; ++i) {
        r[i].push_back(1);
        for (int j = 1; j < i; ++j) {
            r[i].push_back(r[i-1][j] + r[i-1][j-1]);
        }
        r[i].push_back(1);
    }
    return r;
}
