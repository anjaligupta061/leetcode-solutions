class Solution {
    public long subArrayMin(int[] nums){
        int n = nums.length;

        int[] nse = new int[n];
        int[] psee = new int[n];

        Stack<Integer> st = new Stack<>();

        //NEXT SMALLER ELEMENT;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.peek()] >= nums[i]){
                st.pop();
            }

            if(!st.empty()) nse[i] = st.peek();
            else nse[i] = n;

            st.push(i);
        }

        //EMPTYING THE STACK
        while(!st.empty()) st.pop();

        //PREVIOUS SMALLER OR EQUAL ELEMENT
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.peek()] > nums[i]){
                st.pop();
            }

            if(!st.empty()) psee[i] = st.peek();
            else psee[i] = -1;

            st.push(i);
        }

        long sum = 0;

        for(int i=0;i<n;i++){
            int left = i - psee[i];
            int right = nse[i] - i;

            long freq = 1L * left * right;
            long contribution = freq * nums[i];

            sum = (sum + contribution);
        }

        return sum;
    }

    public long subArrayMax(int[] nums){
        int n = nums.length;

        int[] nge = new int[n];
        int[] pgee = new int[n];

        Stack<Integer> st = new Stack<>();

        //NEXT GREATER ELEMENT;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.peek()] <= nums[i]){
                st.pop();
            }

            if(!st.empty()) nge[i] = st.peek();
            else nge[i] = n;

            st.push(i);
        }

        //EMPTYING THE STACK
        while(!st.empty()) st.pop();

        //PREVIOUS GREATER OR EQUAL ELEMENT
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.peek()] < nums[i]){
                st.pop();
            }

            if(!st.empty()) pgee[i] = st.peek();
            else pgee[i] = -1;

            st.push(i);
        }

        long sum = 0;

        for(int i=0;i<n;i++){
            int left = i - pgee[i];
            int right = nge[i] - i;

            long freq = 1L * left * right;
            long contribution = freq * nums[i];

            sum = (sum + contribution);
        }

        return sum;
    }
    public long subArrayRanges(int[] nums) {
        long ans = subArrayMax(nums) - subArrayMin(nums);
        return ans;
    }
}