class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> dupes;
        for (auto n : nums){
            if (dupes.count(n)){
                return true;
            }
            dupes.insert(n);
        }

        return false;
    }
};