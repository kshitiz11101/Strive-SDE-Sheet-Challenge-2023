int f(int k, int start, int end)
{
    if(end == start)
        return 0;
    if(k == 1)
        return (end-start);
    int mid = (start + end + 1)/2;
    return 1 + max(f(k-1, start, mid-1), f(k, mid, end));
}
int cutLogs(int k, int n)
{
    return f(k, 0, n);
}
