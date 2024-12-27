class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> res(n);

        for(int i = 2*n-1; i >= 0; i--) {
            int curr_idx = i%n;
            
            // maintain a monotonic stack
            while(st.size() > 0 and st.top() <= nums[curr_idx]) st.pop();

            // insertion will happen only when we are processing within original array boundary
            if(i < n) {
                if(st.size() == 0) res[i] = -1;
                else res[i] = st.top();
            }

            st.push(nums[curr_idx]);
        }

        return res;
    }
};