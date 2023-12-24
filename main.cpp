#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**
 * Question 1.1
 * is_unique detects if all characters in a string are unique.
 * @param str
 * @return bool
 */
bool is_unique(string& str) {
    /**
     * Approach 1: Hashset (unordered_set)
     * Time Complexity: O(N)
     * Space Complexity: O(N)
     */
    unordered_set<char> s;

    for (char c : str) {
        if (auto j = s.find(c); j != s.cend()) return false;
        s.insert(c);
    }

    return true;

    /** Approach 2: Bit Vector
     *  Assumes lowercase characters only
     *  Time Complexity: O(N)
     *  Space Complexity: O(1)
     *
        int bv = 0;
        for (char c : str) {
            int val = c - 'a';
            if ((bv & (1 << val)) > 0) return false;
            bv |= 1 << val;
        }

        return true;
     */
}


/**
 * Question 1.2
 * check_permutation sees if two strings are permutations of each other.
 * Assumes equal length strings
 * @param str1: first string
 * @param str2: second string
 * @return bool
 */
bool check_permutation(string& str1, string& str2) {
    /** Approach 1: Sort
     * Time complexity: O(N*log N)
     * Space Complexity: O(N)
        if (str1.length() != str2.length()) return false;

        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        return str1 == str2;
     */

    /** Approach 2: Hashmap
     * Time complexity: O(N)
     * Space complexity: O(N)
     */
    if (str1.length() != str2.length()) return false;
    unordered_map<char, int> s;

    for (char c : str1) {
        s[c]++;
    }

    for (char c : str2) {
        s[c]--;
        if (s[c] < 0) return false;
    }
    return true;
}


/**
 * Question 1.3
 * URLify encodes spaces to %20
 * @param str: input string
 * @param true_length: true length of string
 * @return string
 */
string urlify(string& str, int true_length) {
    int spaces = 0, new_length;
    for (int i = 0; i != true_length; ++i) if (str[i] == ' ') ++spaces;
    new_length = true_length + 2 * spaces;

    string url (new_length, ' ');
    for (int i = true_length - 1, index = new_length - 1; i != -1; --i) {
        if (str[i] == ' ') {
            url[index] = '0';
            url[index - 1] = '2';
            url[index - 2] = '%';
            index -= 3;
        }
        else {
            url[index] = str[i];
            --index;
        }
    }

    return url;
}


/**
 * Question 1.4
 * is_palindrome checks if string reads same from both sides
 * Assumes lowercase string
 * Time complexity: O(N)
 * Space complexity: O(1)
 * @param str
 * @return bool
 */
bool is_palindrome(string& str) {
    int spaces = 0;
    for (char c : str) if (c == ' ') ++spaces;

    // Remove spaces
    ignore = remove_if(str.begin(), str.end(), [](char c){ return isspace(c); });
    str.assign(str, 0, str.length() - spaces);

    // Lowercase
    ignore = transform(str.begin(), str.end(), str.begin(), [](char c) {return tolower(c); });

    for (int i = 0, j = (int) str.length() - 1; i != j; ++i, --j) if (str[i] != str[j]) return false;

    return true;
}

int main() {
    string str = "abcdefg";
    cout << "is_unique: " << is_unique(str) << '\n';

    string str1 = "hello", str2 = "hello";
    cout << "check_permutation: " << check_permutation(str1, str2) << '\n';

    string str3 = "Mr John Smith    ";
    cout << "URLify: " << urlify(str3, 13) << '\n';

    string palindrome_string = "Taco Cat";
    cout << "is_palindrome: " << is_palindrome(palindrome_string) << '\n';

    return 0;
}
