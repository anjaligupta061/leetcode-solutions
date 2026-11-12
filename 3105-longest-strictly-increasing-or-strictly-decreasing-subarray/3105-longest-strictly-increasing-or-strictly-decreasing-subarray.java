class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int mxlen = Integer.MIN_VALUE;
        int mnlen = Integer.MIN_VALUE;

        int len = 1;
        for(int i=0;i<nums.length-1;i++){
            if(nums[i] < nums[i+1]){
                len++;
                mxlen = Math.max(len, mxlen);
            }
            else{
                len = 1;
            }
        }

        len = 1;
        for(int i=0;i<nums.length-1;i++){
            if(nums[i] > nums[i+1]){
                len++;
                mnlen = Math.max(len, mnlen);
            }
            else{
                len = 1;
            }
        }

        if(mxlen == Integer.MIN_VALUE && mnlen == Integer.MIN_VALUE) return 1;
        return Math.max(mxlen, mnlen);
    }
}