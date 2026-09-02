class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //first need to track nums and their freqs
        unordered_map<int, int> count;
        for (auto n : nums){
            count[n]++;
        }

        //a # can appear at most the size of arr (only num in arr)
        //use this to relate an idx to a #'s freq (idx 4= # appears 4 times)
        //can be mult #s w same freq

        vector<vector<int>> bucket(nums.size() +1);
        for (auto c : count){
            bucket[c.second].push_back(c.first); 
        }

        vector<int> topK;
        //loop from end so get the TOP k elts 
        for (auto i = bucket.size() - 1; i > 0; i--){
            //outer loop goes thru each idx. inner loop goes thru each # at said idx
            for (auto b : bucket[i]){ 
                topK.push_back(b);
                
                if (topK.size() == k){
                    return topK;
                }
            }
        }

        return topK;
    }
};
