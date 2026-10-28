class Solution {
    public boolean isPalindrome(String s) {
        if(s == "") return true;
        StringBuilder res = new StringBuilder();
        for(int i = 0;i<s.length();i++){
            char ch = Character.toLowerCase(s.charAt(i));
            if(Character.isLetterOrDigit(ch)) res.append(ch);
        }
        int n = res.length();
        int i = 0;
        int j = n-1;
        while(i <= j){
            if(res.charAt(i) != res.charAt(j)) return false;
            i++;
            j--;
        }
        return true;
    }
}