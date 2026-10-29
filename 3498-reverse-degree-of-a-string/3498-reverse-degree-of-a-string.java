class Solution {
    public int reverseDegree(String s) {
        int n = s.length();
        if(s == "") return 0;
        
        int sum = 0;
        for(int i=0;i<n;i++){
            char ch = s.charAt(i);
            int value = (26 - (ch - 'a'));
            sum += (value * (i + 1));
        }
        return sum;
    }
}