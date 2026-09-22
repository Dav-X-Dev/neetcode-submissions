class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //anagrams= strs w same char freqs; use hash to group strs
        //key=char freqs val = words w that char freq
        unordered_map<string, vector<string>> hash;

        /*how to track freqs: str arr/vec that maps letter to place in alphabet (a-         z) ascii values can map when starting from a
        //iter strs->iter chars in str->add char 

        */

        for (const auto & s : strs){
            vector<int> count(26, 0);
            for (auto c : s){
                //+1 whenever letter is seen, maps to spot in alphabet
                count[c - 'a']++;
            }
            //turn count arr to 1 unified string to add to hash
            string str = "";
            for (auto n : count){
                //add # w delim so  it isn't confused for having #s 2+ digits 
                str += to_string(n) + "-";
            }
            //add new word freq str to hash n add the word as val
            hash[str].push_back(s);
        }

        //iter thru hash and add all vals->words to 2d vec 
        vector<vector<string>> output;

        for (const auto & s : hash){
            //iter thru each vec in hash
            output.push_back(s.second);
        }

        return output;
    }
};
