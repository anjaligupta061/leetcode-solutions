class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();

        if(n<=1) return s;
        int start = 0;
        int maxlen = 1;

        for(int i = 0; i < n; i++){
            int left = i;
            int right = i;

            //odd length palindrome
            while(left >= 0 && right < n && s.charAt(left) == s.charAt(right)){
                int len = right - left + 1;

                if(len > maxlen){
                    maxlen = len;
                    start = left;
                }

                left--;
                right++;
            }

            //even length palindrome
            left = i;
            right = i+1;
            while(left >= 0 && right < n && s.charAt(left) == s.charAt(right)){
                int len = right - left + 1;

                if(len > maxlen){
                    maxlen = len;
                    start = left;
                }

                left--;
                right++;
            }
        }
        return s.substring(start, start + maxlen);
    }
}