class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // 1. we have to find out the `idx` of the NEAREST GREATER ELEMENT to RIGHT
        // 2. side-by-side store those `idx` in a vector/array
        // 3. output: for i -> n-1 in temperatures: res[i] = idx_vec[i] - temperatures[i]

        vector<int> right; // we will store the idx of NGE-R elements
        stack<pair<int, int>> st; // we will store pair <elem, idx> inside the stack

        // (73 -> nil in right) i.e. check the st.top() | here st.size() == 0
        // result.push_back(0)
        // st.push(73) | st: 73 <-top
    
        // (76 -> 73) | st.size() > 0 and st.top() == 73
        // check whether st.top() > 76
        // NO: st.pop() till we find a greater elem
            // but we didn't find one..and stack became empty
                // if st.size() == 0: result.push_back(0)
        // st.push(76) | st: 76 <-top

        // (72 -> 76) | st.size() > 0 and st.top() == 76
        // check whether st.top() > 72
        // YES: result.push_back(idx of st.top() i.e. 76)
        // st.push(72) | st: 76 72 <-top

        // (69 -> 72) 
        // if 72 > 69
        // YES: result.push_back(idx of 72 i.e. st.top())
        // st.push(69) | st: 76 72 69 <-top

        // (71 -> 69)
        // if 69 > 71
        // NO: check untill we find a greater elem in st and parallelly pop the elem
            // st.pop() once | st: 76 72 <-top
            // and we found st.top() > 71
                // result.push_back(idx of st.top())
        //st.push(71) | st: 76 72 71 <-top

        // (75 -> 71)
        // if 71 > 75
        // NO: check and pop until we find st.top() > 75
            // st.pop() | st: 76 72 <-top
            // st.pop() | st: 76 <-top
            // we found st.top() > 75
                // result.push_back(idx of 76 i.e. st.top())
            // st.push(75) | st: 76 75 <-top

        // (74 -> 75)
        // if 75 > 74
        // YES: result.push_back(idx of 75 i.e. st.top())
        // st.push(74) | st: 76 75 74 <-top

        // (73 -> 74)
        // if 74 > 73
        // YES: result.push_back(idx of 74 i.e. st.top())
        // st.push(73) | st: 76 75 74 73<-top

        for(int i = temperatures.size()-1; i >= 0; i--) {
            if(st.size() == 0) right.push_back(i); // storing the index as it is cause we know that would be 0 in the final result vector.. we will simply do i-i that time
            else if(st.size() > 0 and st.top().first > temperatures[i]) right.push_back(st.top().second);
            else if(st.size() > 0 and st.top().first <= temperatures[i]) {
                while(st.size() > 0 and st.top().first <= temperatures[i]) st.pop();
                if(st.size() == 0) right.push_back(i); // i-i would be 0, that's why storing the idx as it is
                else right.push_back(st.top().second);
            }

            st.push({temperatures[i], i});
        }

        // reverse the `result` vector as we've processed the `temperatures` array from the right
        // and stored the indexes into the `result` vector from rightwards
        reverse(right.begin(), right.end());

        // now comes the last part
        // find the index difference and store the result in a vector
        vector<int> result(temperatures.size());
        for(int i = 0; i < temperatures.size(); i++) {
            int idx_diff = right[i]-i;
            result[i] = idx_diff; 
        }

        return result;
    }
};