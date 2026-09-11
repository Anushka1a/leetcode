#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> unique_numbers;
        int n = digits.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    
                    if (i != j && j != k && i != k) { 
                        int hundreds = digits[i];
                        int tens = digits[j];
                        int units = digits[k];
                        
                        if (hundreds != 0 && units % 2 == 0) {
                            int num = hundreds * 100 + tens * 10 + units;
                            unique_numbers.insert(num);
                        }
                    }
                    
                }
            }
        }
        
        return unique_numbers.size(); 
    }
};
