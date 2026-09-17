class Solution {
    public int singleNumber(int[] nums) {
        int ans = 0;
        for(int bit = 0;bit<32;bit++){
            int count = 0;
            for(int i = 0;i<nums.length;i++){
                if(((nums[i]>>bit)&1)==1) count++;
            }
            if (count % 3 != 0) {
                ans = ans | (1 << bit);
            }
        }
        return ans;
    }
}