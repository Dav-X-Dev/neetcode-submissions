class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //need to keep track of # freqs
        unordered_map<int, int> count;
        for (auto n : nums){
            count[n]++;
        }

        //num will appear at most the size of nums (only elt in vec)
        //use vec where idx is a #'s freq and #s of same freq are grouped 
        vector<vector<int>> buckets(nums.size()+1);
        for (auto &c : count){
            buckets[c.second].push_back(c.first);
        }  

        vector<int> topK;
        //loop bucket from back and add top K to vec
        for (int i = buckets.size()-1; i > 0; i--){
            //go thru each freq/idx and get each # in bucket 
            for (auto b : buckets[i]){
                topK.push_back(b);

                if (topK.size() == k){
                    return topK;
                }

            }
        }

        return topK;

    }
};
