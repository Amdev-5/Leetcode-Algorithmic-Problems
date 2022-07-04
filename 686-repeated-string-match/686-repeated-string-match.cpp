class Solution {
public:
  int BASE = 1000000;
  int repeatedStringMatch(string A, string B) {
    /*
      if(A == B) return 1;
        int count = 1;
        string source = A;
        while(source.size() < B.size()){
            count++;
            source+=A;
        }
        if(source == B) return count;
        if(Rabin_Karp(source,B) != -1) return count;
        if(Rabin_Karp(source+A,B) != -1) return count+1;
        return -1;
        */
    if(A==B) return 1;
    int count = 1;
    string source = A;
    while(source.size()<B.size())
    {
      source+=A;
      count++;
    }
    if(source==B) return count;
    if(rab(source,B)!=-1) return count;
    if(rab(source+A,B)!=-1) return count+1;
    return -1;
  }
  int rab(string source, string target)
  {
    if(source=="" || target=="") return -1;
    int m = target.size();
    int power = 1;
    for(int i = 0;i<m;i++)
    {
      power = (power*31)%BASE;
    }
    int hashcode = 0;
    int targetcode = 0;
    for(int i =0;i<m;i++)
    {
      targetcode = (targetcode*31+target[i])%BASE;
    }
    for(int i = 0;i<source.size();i++)
    {
      hashcode = (hashcode*31+source[i])%BASE;
      if(i<m-1) continue;
      if(i>=m)
      {
        hashcode = (hashcode- source[i-m]*power)%BASE;
      }
      if(hashcode<0) hashcode+=BASE;
      if(hashcode==targetcode)
      {
        if(source.substr(i-m+1,m)==target)
          return i-m+1;
      }
    }
    return -1;
  }
};