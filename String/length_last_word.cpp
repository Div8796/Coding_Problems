class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        int i=len-1;
        string word;
        
        if(s == "\0")
            return 0;
        
        while(i>=0 && s[i]==' ')
            --i;
        
        while(i>=0 && isalpha(s[i])){
            word.push_back(s[i]);
            --i;
        }
        
        int count = word.length();
        return count;
    }
};
