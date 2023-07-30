#include <string>

string writeAsYouSpeak(int n) {
    if (n == 1)
        return "1";

    if (n == 2)
        return "11";

    string s = "11";

    for (int i = 3; i <= n; i++) {
        s += "?";
        int count = 1;
        std::string str = "";

        for (int j = 0; j < s.length() - 1; j++) {
            if (s[j] == s[j + 1]) {
                count++;
            } else {
                str += std::to_string(count);
                str += s[j];
                count = 1;
            }
        }

        s = str;
    }

    return s;
}
