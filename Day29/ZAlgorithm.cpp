int zAlgorithm(string mainString, string pattern, int mainLength, int patternLength)
{
    int count = 0;

    for (int i = 0; i < mainLength - patternLength + 1; i++) {
        if (mainString[i] == pattern[0]) {
            if (mainString.substr(i, patternLength) == pattern)
                count++;
        }
    }
    return count;
}
