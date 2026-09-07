class Solution {
    public String largestOddNumber(String s) {
        int idx = -1;
        for(int i = s.length()-1; i>=0;i--){
            if((s.charAt(i)-'0') % 2 == 1){
                idx = i;
                break;
            }
        }

        if(idx == -1) return "";
        //skip leading zeroes
        int i = 0;
        while(i < s.length() && s.charAt(i)=='0'){
            i++;
        }
        if(i > idx) return "";
        return s.substring(i, idx+1);
    }
}