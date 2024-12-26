// https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1

class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        stack<int> st;
        vector<int> res;
        int n = arr.size();
        
        for(int i = n-1; i >= 0; i--) {
            if(st.size() == 0) res.push_back(-1);
            else if(st.size() > 0 and st.top() > arr[i]) res.push_back(st.top());
            else if(st.size() > 0 and st.top() <= arr[i]) {
                while(st.size() > 0 and st.top() <= arr[i]) {
                    st.pop();
                }
                if(st.size() == 0) {
                    res.push_back(-1);
                } else {
                    res.push_back(st.top());
                }
            }
            
            st.push(arr[i]);
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};