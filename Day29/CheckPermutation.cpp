#include <bits/stdc++.h>

bool areAnagram(string &str1, string &str2)

{

  int one = 1;

  for (int i = 0; i < str1.length(); i++)
  {

    one = one * str1[i];
  }

  int two = 1;

  for (int i = 0; i < str2.length(); i++)
  {

    two = two * str2[i];
  }

  if (one == two)

    return true;

  else

    return false;
}
