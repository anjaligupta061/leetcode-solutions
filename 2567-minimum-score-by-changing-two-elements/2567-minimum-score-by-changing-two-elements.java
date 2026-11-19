class Solution {
    public int minimizeSum(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);

        if(n <= 3) return 0;

        return Math.min( nums[n-1] - nums[2], Math.min( nums[n-2] - nums[1], nums[n-3] - nums[0]));
    }
}