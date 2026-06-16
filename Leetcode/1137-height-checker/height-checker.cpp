class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n=heights.size();
        int count=0;
        vector<int> sorted=heights;
        sort(sorted.begin(),sorted.end());
        for(int i=0;i<n;i++){
            if(heights[i]!=sorted[i]){
                count++;
            }
        }
        return count;
    }
};