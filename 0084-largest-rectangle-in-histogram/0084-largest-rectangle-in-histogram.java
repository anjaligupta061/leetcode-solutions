class Solution {
    public int largestRectangleArea(int[] arr) {
        Stack<Integer> st = new Stack<>();
        int n = arr.length;
        int maxArea = 0;

        for(int i =0;i<=n;i++){
            while(!st.isEmpty() && ((i==n) || arr[st.peek()] >= arr[i])){
                int height = arr[st.peek()];
                st.pop();

                int width;

                if(st.isEmpty()) width = i;
                else width = i - st.peek() - 1;

                int area = height * width;
                maxArea = Math.max(maxArea, area);
            }
            if (i < n) {
                st.push(i);
            }
        }
        return maxArea;
    }
}