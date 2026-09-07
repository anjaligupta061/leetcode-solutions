class Solution {
public:
    string largestOddNumber(string s) {
        int idx = -1;
        for(int i = s.length()-1; i>=0;i--){
            if(s[i] % 2 == 1){
                idx = i;
                break;
            }
        }

        if(idx == -1) return "";
        //skip leading zeroes
        int i = 0;
        while(i < s.length() && s[i]=='0'){
            i++;
        }
        if(i > idx) return "";
        return s.substr(i, idx-i+1);
    }
};