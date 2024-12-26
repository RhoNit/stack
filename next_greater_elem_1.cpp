class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp; // map to store {elem, NGE-R} in terms of `nums2`
        
        // find NGE-R and store the pair in the map
        for(int i = nums2.size()-1; i >= 0; i--) {
            if(st.size() == 0) mp[nums2[i]] = -1;
            else if(st.size() > 0 and st.top() > nums2[i]) mp[nums2[i]] = st.top();
            else if(st.size() > 0 and st.top() <= nums2[i]) {
                while(st.size() > 0 and st.top() <= nums2[i]) st.pop();
                if(st.size() == 0) mp[nums2[i]] = -1;
                else mp[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }

        vector<int> res;
        // traverse through the `nums1` and fetch the existing keys' values
        for(auto num: nums1) {
            if(mp.find(num) != mp.end()) res.push_back(mp[num]);
        }

        return res;
    }
};