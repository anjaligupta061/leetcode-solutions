class Solution {
    public String longestCommonPrefix(String[] strs) {
        int n=strs.length;

        if(n==1) return strs[0];

        Arrays.sort(strs);
        String first = strs[0];
        String last=strs[n-1];
        String s="";
        for(int i=0;i<(Math.min(first.length(),last.length()));i++){
            if(first.charAt(i) == last.charAt(i)){
                s+=first.charAt(i);
            }
            else return s;
        }
        return s;
    }
}