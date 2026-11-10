class Solution {
    public int reverse(int n){
        int temp = n;
        int x = 0;
        while(temp > 0){
            int r = temp % 10;
            x = x*10+r;
            temp/=10;
        }
        return x;
    }
    public int mirrorDistance(int n) {
        int ans = Math.abs(n - reverse(n));
        return ans;
    }
}