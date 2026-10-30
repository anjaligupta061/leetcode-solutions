class Solution {
    public boolean isPalindrome(String s){
        int i = 0;
        int j = s.length()-1;
        while(i<=j){
            if(s.charAt(i) != s.charAt(j)){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    public String generateBinary(int x, int base){
        int b = base;
        int temp = x;
        String binary = "";
        while(temp > 0){
            int rem = temp % b;
            binary = rem + binary;
            temp /= b;
        }
        return binary;
    }
    public boolean isStrictlyPalindromic(int n) {
        for(int i=2;i<=n-2;i++){
            String str = generateBinary(n, i);
            if(!isPalindrome(str)) return false;
        }
        return true;
    }
}