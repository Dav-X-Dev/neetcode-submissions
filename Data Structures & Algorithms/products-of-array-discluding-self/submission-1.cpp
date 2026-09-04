class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int prod = 1;
        int donuts = 0;
        //calc cumulative product of arr
        for (const auto &n : nums){
            if (n == 0){
                donuts++;
            }
            else{
                prod *= n;
            }
                
        }
        int except;
        //if donuts=1, 0 @ every idx that isn't 0
        vector<int> output;
        for (const auto &n : nums){
            if (donuts == 1) {
                
                if (n == 0){
                    output.push_back(prod);
                }
                else{
                    output.push_back(0);
                }
            }
            else if (donuts > 1){
                output.push_back(0);
                
            }
            else{
                
                except = prod / n;
                output.push_back(except);
            }
        }

        return output;
    }
};
