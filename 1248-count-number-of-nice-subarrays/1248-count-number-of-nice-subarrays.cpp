class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
    int atmost(vector<int>& nums, int k){
        int left = 0;
        int res = 0;
        for(int right=0;right<nums.size();right++){
            if(nums[right]%2!=0){
                k--;
            }
            while(k<0){
                if(nums[left]%2!=0){
                    k++;
                }
                left++;
            }
            res+=right-left+1;
        }
        return res;
    }
};