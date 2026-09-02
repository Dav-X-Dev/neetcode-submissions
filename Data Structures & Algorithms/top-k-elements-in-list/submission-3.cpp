class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //need to track how many times a num appears
        unordered_map<int, int> count;
        for (auto n : nums){
            count[n]++;
        }

        //a # can appear max size of arr or less. Use arr idx as markers for a #'s freq 
       // (idx 2= num appears twice) - bucket must be size of nums+1
       vector<vector<int>> bucket(nums.size()+1);
       //populate the bucket
       for (auto& c : count){
            bucket[c.second].push_back(c.first);
       }

       //iter thru bucket starting from end to get the top K elts
       vector<int> topK;
       for (int i = bucket.size()-1; i > 0; i--){
            //at each idx iter thru #s that are in bucket
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
