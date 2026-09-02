class Solution {
public:
    bool isAnagram(string s, string t) {
        //idea: add char of str1 to map; if char is in str2 decrement val
        //if they're anagrams hash should be empty? or 0s across the board
        unordered_map<char, int> hash;

        for (int i = 0; i < s.size(); i++) {
            hash[s[i]]++;
        }

        for (int i = 0; i < t.size(); i++){
            hash[t[i]]--;
        }

        for (auto i : hash){
            if (i.second != 0){
                return false;
            }
        }
        return true;
    }
};
