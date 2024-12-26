class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> max_left(n), max_right(n);

        max_left[0] = height[0];
        for(int i = 1; i < n; i++) {
            max_left[i] = max(height[i], max_left[i-1]);
        }

        max_right[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--) {
            max_right[i] = max(height[i], max_right[i+1]);
        }

        vector<int> water_height(n);
        int area_sum = 0;
        for(int i = 0; i < n; i++) {
            water_height[i] = min(max_left[i], max_right[i]);
            int area = water_height[i] - height[i];
            area_sum += area; 
        }

        return area_sum;
    }
};