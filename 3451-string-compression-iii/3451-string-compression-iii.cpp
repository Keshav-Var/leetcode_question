#include <sstream>
#include <string>

class Solution {
public:
    string compressedString(string word) {
        std::ostringstream comp;  // Use ostringstream for efficient string building
        int n = word.length();
        
        for (int i = 0; i < n;) {
            char ch = word[i];
            int freq = 0;

            // Count frequency of the current character
            while (i < n && word[i] == ch) {
                i++;
                freq++;
            }

            // Append the frequency and character to the compressed string
            while (freq > 0) {
                if (freq > 9) {
                    comp << "9" << ch;  // Add '9' for the first 9 occurrences
                    freq -= 9;          // Reduce frequency by 9
                } else {
                    comp << freq << ch; // Add remaining frequency
                    freq = 0;           // All frequency accounted for
                }
            }
        }
        return comp.str();  // Convert ostringstream to string
    }
};