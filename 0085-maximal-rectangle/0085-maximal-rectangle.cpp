class Solution {
public:
    int largestRectangleArea(vector<int>& heights){
        stack<int> st;
        int n = heights.size();
        int maxArea = 0;

        for(int i=0;i<=n;i++){
            while(!st.empty() && (i == n || heights[i] < heights[st.top()])){
                int height = heights[st.top()];
                st.pop();

                int width;
                if(st.empty()) width = i;
                else width = i - st.top() - 1;

                int area = height * width;
                maxArea = max(area, maxArea);
            }
            if(i < n)
                st.push(i);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> heights(cols, 0);

        int maxArea = 0;
        for(int i = 0; i<rows;i++){
            // Build histogram for current row
            for(int j=0;j<cols;j++){
                if(matrix[i][j]== '1'){
                    heights[j]++;
                }
                else{
                    heights[j] = 0;
                }
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
};