bool canPlace(const vector<int>& positions, int n, int c, int dist)
{
    int coord = positions[0];
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if ((positions[i] - coord) >= dist)
        {
            count++;
            coord = positions[i];
        }
        if (count == c)
        {
            return true;
        }
    }
    return false;
}

int chessTournament(const vector<int>& positions, int n, int c)
{
    vector<int> sortedPositions = positions;  // Create a copy of positions vector
    sort(sortedPositions.begin(), sortedPositions.end());

    int low = 1;
    int high = (sortedPositions[n - 1] - sortedPositions[0]);
    int res;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (canPlace(sortedPositions, n, c, mid))
        {
            res = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return res;
}
