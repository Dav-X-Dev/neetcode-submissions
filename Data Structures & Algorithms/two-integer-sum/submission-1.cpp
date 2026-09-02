class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //start 1:13pm
        //when adding elt to hash map check for diff. 
        //if diff is in map return indicies -> key=num val=idx
        unordered_map<int, int> cash;
        int diff;
        for (int i = 0; i < nums.size(); i++){
            
            diff = target - nums[i];
            if (cash.count(diff)){
                
                return {cash[diff], i};
            }
            cash[nums[i]] = i;
        }
        return {};
    }
};
