class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int left = 0;
        int cnt = 0;
        int minlen = 1e9;
        string ans = "";
        for(int right =0;right<n;right++){
            if(s[right]=='1'){
                cnt++;
            }
            while(cnt>k){
                if(s[left]=='1'){
                    cnt--;
                }
                left++;
            }
            if(cnt==k){
                while(s[left]=='0'){
                    left++;
                }
                string curr = s.substr(left, right-left+1);
                if(ans=="" || curr.length() < ans.length() || (curr.length()==ans.length() && curr<ans)){
                    ans = curr;
                }
            }
        }
        return ans;
    }
};