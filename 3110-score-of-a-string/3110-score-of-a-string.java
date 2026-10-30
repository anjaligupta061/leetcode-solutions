class Solution {
    public int scoreOfString(String s) {
        int sum = 0;
        int n = s.length();

        for(int i=0;i<n-1;i++){
            char ch = s.charAt(i);
            char c = s.charAt(i+1);
            int a = ch;
            int b = c;
            sum += Math.abs(a-b);
        }
        return sum;
    }
}