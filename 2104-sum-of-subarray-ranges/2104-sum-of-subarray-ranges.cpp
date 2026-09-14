class Solution {
public:
    long long subArrayMin(vector<int>& nums) {
        int n = nums.size();

        vector<int> nse(n);
        vector<int> psee(n);

        stack<int> st;

        //NEXT SMALLER ELEMENT;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            if (!st.empty())
                nse[i] = st.top();
            else
                nse[i] = n;

            st.push(i);
        }

        //EMPTYING THE STACK
        while (!st.empty())
            st.pop();

        //PREVIOUS SMALLER OR EQUAL ELEMENT
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            if (!st.empty())
                psee[i] = st.top();
            else
                psee[i] = -1;

            st.push(i);
        }

        long long sum = 0;

        for (int i = 0; i < n; i++) {
            int left = i - psee[i];
            int right = nse[i] - i;

            long long freq = 1LL * left * right;
            long long contribution = freq * nums[i];

            sum = (sum + contribution);
        }

        return sum;
    }

    long long subArrayMax(vector<int>& nums) {
        int n = nums.size();

        vector<int> nge(n);
        vector<int> pgee(n);

        stack<int> st;

        //NEXT GREATER ELEMENT;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            if (!st.empty())
                nge[i] = st.top();
            else
                nge[i] = n;

            st.push(i);
        }

        //EMPTYING THE STACK
        while (!st.empty())
            st.pop();

        //PREVIOUS GREATER OR EQUAL ELEMENT
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            if (!st.empty())
                pgee[i] = st.top();
            else
                pgee[i] = -1;

            st.push(i);
        }

        long long sum = 0;

        for (int i = 0; i < n; i++) {
            int left = i - pgee[i];
            int right = nge[i] - i;

            long long freq = 1L * left * right;
            long long contribution = freq * nums[i];

            sum = (sum + contribution);
        }

        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long ans = subArrayMax(nums) - subArrayMin(nums);
        return ans;
    }
};