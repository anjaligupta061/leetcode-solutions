class Solution {
    public int minOperations(int[] nums, int k) {
        int n = nums.length;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }

        if(sum > k) return sum % k;
        else if(sum == k) return 0;
        else return sum;
    }
}