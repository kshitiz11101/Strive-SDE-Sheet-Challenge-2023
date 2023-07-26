#include <iostream>
#include <string>
#include <vector>

bool isPalindrome(const std::string& s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

void solve(int i, const std::string& s, std::vector<std::string>& v, std::vector<std::vector<std::string>>& ans)
{
    int n = s.length();
    if (i == n)
    {
        ans.push_back(v);
        return;
    }
    for (int j = i; j < n; j++)
    {
        if (isPalindrome(s, i, j))
        {
            std::string k = s.substr(i, j - i + 1);
            v.push_back(k);
            solve(j + 1, s, v, ans);
            v.pop_back();
        }
    }
}

std::vector<std::vector<std::string>> partition(const std::string& s)
{
    std::vector<std::vector<std::string>> ans;
    std::vector<std::string> v;
    solve(0, s, v, ans);
    return ans;
}
