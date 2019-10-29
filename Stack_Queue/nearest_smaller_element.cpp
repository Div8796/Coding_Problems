#define PB push_back

vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> prevSmaller;
    int len = A.size();
    stack<int> s;
    int flag = 0;
    
    prevSmaller.PB(-1);
    s.push(A[0]);
    
    for(int i=1; i<len; i++){
        flag =0;
        if(A[i] > s.top())
            prevSmaller.PB(s.top());
        else{
            s.pop();
            while(!s.empty()){
                if(A[i] > s.top()){
                    prevSmaller.PB(s.top());
                    flag = 1;
                    break;
                }
                s.pop();
            }
            if(flag==0)
                prevSmaller.PB(-1);
        }
        s.push(A[i]);
    }
    return prevSmaller;
}


vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> ans;
    ans.resize(A.size());

    stack<int> st;
    
    for (int i = 0; i < A.size(); i++) {
        while (!st.empty() && st.top() >= A[i]) st.pop();
        if (st.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = st.top();
        }
        st.push(A[i]);
    }
    return ans;
}
