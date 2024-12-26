class Solution {
  public:
    vector<int> nearestSmallerElement(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> res;
        
        for(int i = n-1; i >= 0; i--) {
            if(st.size() == 0) {
                res.push_back(-1);
            }
            else if(st.size() > 0 and st.top() < arr[i]) {
                res.push_back(st.top());
            }
            else if(st.size() > 0 and st.top() >= arr[i]) {
                // pop the stack top untill we find a smaller element in stack top than current array element
                while(st.size() > 0 and st.top() >= arr[i]) st.pop();
                // if the stack has been emptied
                if(st.size() == 0) res.push_back(-1);
                // we have found out the smaller element
                else res.push_back(st.top());
            }
            
            // push the current array element into the stack
            st.push(arr[i]);
        }
        
        // reverse the vector
        reverse(res.begin(), res.end());
        
        return res;
    }
};