class Solution {
    public int minMoves(int[] arr) {
        int n = arr.length;
        if(n==1) return 0;
        int mn = Integer.MAX_VALUE;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += arr[i];
            mn = Math.min(mn, arr[i]);
        }
        return sum-(n*mn);
    }
}