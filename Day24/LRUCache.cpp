#include<bits/stdc++.h>

class LRUCache
{
public:
    vector<int> q;
   int cap;
   int size;
   int idx;
   unordered_map<int,int> mp;
   LRUCache(int capacity)
   {
       cap=capacity;
       size=0;
       idx=0;
   }

   int get(int key)
   {
       if(mp.find(key)!=mp.end()){
           for(int i=0;i<q.size();i++){
               if(q[i]==key){
                   q[i]=-1;
                   break;
               }
           }
           q.push_back(key);
           return mp[key];
       }
       return -1;
   }

   void put(int key, int value)
   {
        if(size<cap){
           if(mp.find(key)!=mp.end()){
               mp[key]=value;
               for(int i=0;i<q.size();i++){
                   if(q[i]==key){
                       q[i]=-1;
                       break;
                   }
               }
               q.push_back(key);
           }
           else{
               q.push_back(key);
               mp[key]=value;
               size++;
           }
           
       }
       else {
           if(mp.find(key)!=mp.end()){
               mp[key]=value;
               for(int i=0;i<q.size();i++){
                   if(q[i]==key){
                       q[i]=-1;
                       break;
                   }
               }
               q.push_back(key);
           }
           else{
               for(int i=0;i<q.size();i++){
                   if(q[i]!=-1){
                       idx=i;
                       break;
                   }
               }
               mp.erase(q[idx]);
               q[idx]=-1;
               q.push_back(key);
               mp[key]=value;
           }
       }
   }
};
