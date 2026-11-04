class Solution {
    static final int mod = 1000000007;
    public long power(long x, long n){
        if(n==0) return 1;
        long half = power(x,n/2);
        long ans = (half * half) % mod;
        if(n%2==1){
            ans = (ans*x) % mod;
        }
        return ans;
    }
    public int countGoodNumbers(long n) {
        long even = (n+1)/2;
        long odd = n/2;

        long a = power(5,even);
        long b = power(4,odd);

        return(int)((a*b) % mod);
    }
}