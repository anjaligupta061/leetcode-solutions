class Solution {
    public int largestRectangleArea(int[] heights) {
        Stack<Integer> st = new Stack<>();
        int maxArea = 0;
        int n = heights.length;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || heights[i] < heights[st.peek()])) {
                int height = heights[st.peek()];
                st.pop();

                int width;
                if (st.empty())
                    width = i;
                else
                    width = i - st.peek() - 1;

                int area = height * width;
                maxArea = Math.max(area, maxArea);
            }
            if (i < n)
                st.push(i);
        }
        return maxArea;
    }
    public int maximalRectangle(char[][] matrix) {
        if (matrix.length == 0)
            return 0;

        int rows = matrix.length;
        int cols = matrix[0].length;

        int[] heights = new int[cols];

        int maxArea = 0;
        for (int i = 0; i < rows; i++) {
            // Build histogram for current row
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            maxArea = Math.max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
}