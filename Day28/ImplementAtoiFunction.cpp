int atoi(string str) {
    int index = 0;
    int sign = 1;
    int result = 0;
    
    while (index < str.length()) {
        if (str[index] >= '0' && str[index] <= '9') {
            int digit = str[index] - '0';
            result = result * 10 + digit;
        }
        index++;
    }

    if (str[0] == '-') {
        sign = -1;
    }
    
    return result * sign;
}
