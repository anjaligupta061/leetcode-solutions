class Solution {
public:
    int maxele(vector<vector<int>>& arr, int col){
        int n = arr.size();
        int maxi = INT_MIN;
        int idx=-1;
        for(int i=0;i<n;i++){
            if(arr[i][col]>maxi){
                maxi = arr[i][col];
                idx=i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            int row = maxele(arr,mid);
            int left = mid - 1>=0 ? arr[row][mid-1] : INT_MIN;
            int right = mid + 1<n ? arr[row][mid+1] : INT_MIN;
            if (arr[row][mid] > left && arr[row][mid] > right) {
                return {row, mid};
            } 
            else if (left > arr[row][mid]) {
                high = mid - 1;
            } 
            else {
                low = mid + 1;
            }
        }
        return {-1,-1};
    }
};