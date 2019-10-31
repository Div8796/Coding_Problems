//Evaluation of postfix expression
//Input: 2 3 1 * + 9 -
//Output: -4

#include<bits/stdc++.h>
#define FOR(i, a, b) for(int i=a; i<b; i++)

using namespace std;

int eval_postfix_expr(string str){
        stack<int> s;
        int len = str.length();
        int i=0;

        FOR(i, 0, len){
                if(isdigit(str[i]))
                        s.push(str[i]-'0');
                else{
                        int val1 = s.top();
                        s.pop();
                        int val2 = s.top();
                        s.pop();
                        switch(str[i]){
                                case '+': s.push(val2 + val1);
                                          break;

                                case '-': s.push(val2 - val1);
                                          break;

                                case '*': s.push(val2 * val1);
                                          break;

                                case '/': s.push(val2 / val1);
                                          break;
                        }
                }
        }
  return s.top();
}


int main(){
        string str;
        cin >> str;

        cout << eval_postfix_expr(str) << endl;
        return 0;
}
