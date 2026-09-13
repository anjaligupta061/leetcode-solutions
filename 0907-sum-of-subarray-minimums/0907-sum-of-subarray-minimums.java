class Solution {
    public int sumSubarrayMins(int[] arr) {
        int n = arr.length;
        int mod = 1000000007;

        int[] nse = new int[n];
        int[] psee = new int[n];

        Stack<Integer> st = new Stack<>();

        //next smaller element
        for(int i = n-1;i>=0;i--){
            while(!st.isEmpty() && arr[st.peek()] >= arr[i]){
                st.pop();
            }
            if(!st.isEmpty()){
                nse[i] = st.peek();
            }
            else{
                nse[i] = n;
            }
            st.push(i);
        }

        //emptying the stack
        while(!st.isEmpty()){
            st.pop();
        }

        //previous smaller and equal element
        for(int i = 0;i<n;i++){
            while(!st.isEmpty() && arr[st.peek()] > arr[i]){
                st.pop();
            }
            if(!st.isEmpty()){
                psee[i] = st.peek();
            }
            else{
                psee[i] = -1;
            }
            st.push(i);
        }

        long sum = 0;
        for(int i=0;i<n;i++){
            int left = i - psee[i];
            int right = nse[i] - i;
            long freq = 1L * left * right;
            long contribution = freq * arr[i];
            sum = (sum + contribution) % mod;
        }
        return (int)sum;
    }
}