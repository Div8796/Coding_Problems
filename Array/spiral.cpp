vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    vector<int> sol;
    int n = A.size();
    int m = A[0].size();
    int top=0, bottom=n-1, left=0, right=m-1, dir=0;
    
    while(top<=bottom && left<=right){
        if(dir==0){
            for(int i=left; i<=right; i++)
                sol.push_back(A[top][i]);
            ++top;
            dir=1;
        }
        else if(dir==1){
            for(int i=top; i<=bottom; i++)
                sol.push_back(A[i][right]);
            --right;
            dir=2;
        }
        else if(dir==2){
            for(int i=right; i>=left; i--)
                sol.push_back(A[bottom][i]);
            --bottom;
            dir=3;
        }
        else if(dir==3){
            for(int i=bottom; i>=top; i--)
                sol.push_back(A[i][left]);
            ++left;
            dir=0;
        }
    }
    return sol;
}

