int romanToInt(string s) {
    map<char,pair<int,int>>m;
    m['I']={1,1};
    m['V']={5,2};
    m['X']={10,3};
    m['L']={50,4};
    m['C']={100,5};
    m['D']={500,6};
    m['M']={1000,7};
    
    int sum=0,n=s.size();
    for(int i=0;i<n;i++){
        if(m[s[i]].second<m[s[i+1]].second)
            sum-=m[s[i]].first;
        else
            sum+=m[s[i]].first;
    }
    
    return sum;
}
