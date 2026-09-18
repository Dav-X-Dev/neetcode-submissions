class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //add nums to set for auto sort & fast look up
        //if # doesn't have a num -1 in set, it is the start of sequence
        //check if n+1 exists in set. keep cnt for longest seq
        int seq = 0;
        int max_seq = 0;
        set<int> sequence;

        for (auto n : nums){
            sequence.insert(n);
        }

        for (auto c : sequence){
            if (!sequence.count(c-1)){
               seq = 1; 
            }
            else{
                seq++;
            }

            if (seq > max_seq){
                max_seq = seq;
            }
        }

        return max_seq;
    }
};
