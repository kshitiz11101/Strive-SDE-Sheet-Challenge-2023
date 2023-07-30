string check(string s, int left, int right) {
    int length = s.length();
    while (left >= 0 && right < length) {
        if (s[left] != s[right])
            break;
        left--;
        right++;
    }
    return s.substr(left + 1, right - left - 1);
}

string longestPalinSubstring(string str) {
    string longest;
    int length = str.size();
    for (int i = 0; i < length; i++) {
        string oddPalindrome = check(str, i, i);
        if (oddPalindrome.size() > longest.size())
            longest = oddPalindrome;
    }
    for (int i = 0; i < length; i++) {
        string evenPalindrome = check(str, i, i + 1);
        if (evenPalindrome.size() > longest.size())
            longest = evenPalindrome;
    }
    return longest;
}
