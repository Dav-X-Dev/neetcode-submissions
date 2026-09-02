class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        
        unordered_map<int, int> hash;
        //add elt to map: key=# val=count;
        //if already in map then its a dup bc only checks when entering into map
        for (int i=0; i < nums.size(); i++){

            if (hash.count(nums[i])){
                cout << "dup found: " << nums[i];
                return true;
            }
            else {
                hash[nums[i]]++;
            }
           
        }
        return false;

    }
};
