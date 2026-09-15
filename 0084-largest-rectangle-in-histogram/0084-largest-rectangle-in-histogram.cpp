class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> st;
        int n = arr.size();
        int maxArea = 0;

        for(int i =0;i<=n;i++){
            while(!st.empty() && ((i==n) || arr[st.top()] >= arr[i])){
                int height = arr[st.top()];
                st.pop();

                int width;

                if(st.empty()) width = i;
                else width = i - st.top() - 1;

                int area = height * width;
                maxArea = max(maxArea, area);
            }
            if (i < n) {
                st.push(i);
            }
        }
        return maxArea;
    }
};