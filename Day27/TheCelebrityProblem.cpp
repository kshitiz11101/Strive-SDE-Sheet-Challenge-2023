#include <bits/stdc++.h> 
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
    stack<int> stk;

    for (int i = 0; i < n; i++) {
        stk.push(i);
    }

    while (stk.size() > 1) {
        int personA = stk.top();
        stk.pop();

        int personB = stk.top();
        stk.pop();

        if (knows(personA, personB)) {
            stk.push(personB);
        } else {
            stk.push(personA);
        }
    }

    bool rowCheck = false;
    int zeroCount = 0;

    for (int i = 0; i < n; i++) {
        if (M[stk.top()][i] == 0) {
            zeroCount++;
        }
    }

    if (zeroCount == n) {
        rowCheck = true;
    }

    bool colCheck = false;
    int oneCount = 0;

    for (int i = 0; i < n; i++) {
        if (M[i][stk.top()] == 1) {
            oneCount++;
        }
    }

    if (oneCount == n - 1) {
        colCheck = true;
    }

    if (rowCheck == true && colCheck == true) {
        return stk.top();
    } else {
        return -1;
    }
}
