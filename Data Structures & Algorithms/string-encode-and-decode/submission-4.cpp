class Solution {
public:

    string encode(vector<string>& strs) {
        //concatenate each str continuously; how to know the start of str when 
        //decoding? use size and a char as delimiter-
        // when char is seen str starts right after
        
        string encoded = "";

        for (const auto& s : strs){
            encoded += to_string(s.size()) + "-" + s;
        }

        return encoded;

        
    }

    vector<string> decode(string s) {
        //iter str->read in size-> if delim set ptrs to 1st char of str
        //after each char check if the diff = size
        int str_size, ptr1 = 0, ptr2 = 0;
        vector<string> strs;

        while (ptr1 <s.size()){
            string s_size = "";
            //int ptr2 = ptr1;
            //read str size up to delim
            while (s[ptr2] != '-'){
                s_size += s[ptr2];
                ptr2++;
            }

            //convert read in size to int->complete int
            str_size = stoi(s_size);

            //now ptrs are @ start of str;const check their diff 
            //if ptr2 - ptr1 = to str_size str is complete
            //reset ptrs to repeat process for next
            ptr2++;
            ptr1 = ptr2;

            string decoded = "";
            while ((ptr2 - ptr1) != str_size){
                decoded += s[ptr2];
                ptr2++;
            }
            strs.push_back(decoded);

            ptr1 = ptr2;
        }

        return strs;
    }
};
