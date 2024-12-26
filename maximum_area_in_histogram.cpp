class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left, right;
        stack<pair<int, int>> st; // we will store the pair i.e. <elem, idx> into the stack

        int pseudo_idx = -1;

        // nearest smaller to left
        for(int i = 0; i < n; i++) {
            if(st.size() == 0) left.push_back(pseudo_idx);
            else if(st.size() > 0 and st.top().first < heights[i]) left.push_back(st.top().second);
            else if(st.size() > 0 and st.top().first >= heights[i]) {
                while(st.size() > 0 and st.top().first >= heights[i]) st.pop();
                if(st.size() == 0) left.push_back(pseudo_idx);
                else left.push_back(st.top().second);
            }

            st.push({heights[i], i});
        }

        while(st.size() > 0) st.pop();

        // nearest smaller to right
        for(int i = n-1; i >= 0; i--) {
            if(st.size() == 0) right.push_back(n);
            else if(st.size() > 0 and st.top().first < heights[i]) right.push_back(st.top().second);
            else if(st.size() > 0 and st.top().first >= heights[i]) {
                while(st.size() > 0 and st.top().first > heights[i]) st.pop();
                if(st.size() == 0) right.push_back(n);
                else right.push_back(st.top().second);
            }

            st.push({heights[i], i});
        }

        reverse(right.begin(), right.end());

        int max_area = 0;
        for(int i = 0; i < n; i++) {
            int width = right[i]-left[i]-1;
            int area = heights[i]*width;
            max_area = max(max_area, area);
        }

        return max_area;
    }
};