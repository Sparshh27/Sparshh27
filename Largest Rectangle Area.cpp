class Solution {
private:
    vector<int> prevSmall;
    vector<int> nextSmall;

    void previousSmaller(vector<int> heights){
        stack<int> s;
        s.push(0);
        prevSmall.push_back(-1);
        for(int i=1;i<heights.size();i++){
            while(s.empty()==false && heights[s.top()]>=heights[i])
                s.pop();
            if(s.empty())
                prevSmall.push_back(-1);
            else
                prevSmall.push_back(s.top());
            s.push(i);
        }
    }
    void nextSmaller(vector<int> heights){
        stack<int> s;
        int n = heights.size();
        s.push(n-1);
        nextSmall.push_back(n);
        for(int i=n-2;i>=0;i--){
            while(s.empty()==false && heights[s.top()]>=heights[i])
                s.pop();
            if(s.empty())
                nextSmall.push_back(n);
            else
                nextSmall.push_back(s.top());
            s.push(i);
        }
        //We used the reverse of array to find the next Smaller
        //So we need to reverse the vector
        reverse(nextSmall.begin(),nextSmall.end());
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        nextSmaller(heights);
        previousSmaller(heights);
        int res = 0;
        for(int i=0;i<heights.size();i++){
            int curr = heights[i];
            curr += (i-prevSmall[i]-1)*heights[i];
            curr += (nextSmall[i]-i-1)*heights[i];
            res=max(curr,res);
        }
        return res;
    }
};
