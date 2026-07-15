class Solution {
public:
    int countstud(vector<int> &nums, int pages) {
        int stud = 1;
        int pagescnt = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (pagescnt + nums[i] <= pages) {
                pagescnt += nums[i];
            } else {
                stud++;
                pagescnt = nums[i];
            }
        }

        return stud;
    }

    int findPages(vector<int> &nums, int m) {

        int n = nums.size();

        if (m > n)
            return -1;

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int students = countstud(nums, mid);

            if (students > m)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low;
    }
    int splitArray(vector<int>& nums, int k) {
        return findPages(nums,k);
    }
};