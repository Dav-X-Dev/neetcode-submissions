class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output;
        int prod = 1;
        int zero_cnt = 0;
        for (auto n : nums){
            if (n == 0){
                zero_cnt++;
            }
            else{
                prod *= n;
            }
            
        }

        for (auto n : nums){
            
            if (zero_cnt == 0){
                int quotient = prod / n;
                output.push_back(quotient);
            }
            else if (zero_cnt == 1) {
                if (n == 0){
                    output.push_back(prod);
                }
                else {
                    output.push_back(0);
                }
            }
            else {
                output.push_back(0);
            }

        }
        return output;
    }
};
