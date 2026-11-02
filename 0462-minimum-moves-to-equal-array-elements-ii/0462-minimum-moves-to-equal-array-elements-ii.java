class Solution {
    public int minMoves2(int[] nums) {
        int n = nums.length;
        if(n==1) return 0;

        Arrays.sort(nums);
        int target = nums[n/2];

        int sum = 0;
        for(int i=0;i<n;i++){
            sum += Math.abs(nums[i] - target);
        }

        return sum;
    }
}