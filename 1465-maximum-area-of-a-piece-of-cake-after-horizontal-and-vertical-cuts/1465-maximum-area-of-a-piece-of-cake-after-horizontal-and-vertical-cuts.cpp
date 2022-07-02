class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
      int modulo = 1000000007;
      int hm = 0;
      int vm=0;
      sort(hc.begin(),hc.end());
      sort(vc.begin(),vc.end());
      hm = hc[0];
      vm = vc[0];
      if(hc.size()!=1)
      {
        for(int i =1;i<hc.size();i++)
        {
          hm  = max(hm,hc[i]-hc[i-1]);
        }
      }
      hm = max(hm,h-hc[hc.size()-1]);
      if(vc.size()!=1)
      {
        for(int i =1;i<vc.size();i++)
        {
          vm  = max(vm,vc[i]-vc[i-1]);
        }
      }
      vm = max(vm,w-vc[vc.size()-1]);
      return (long)hm * vm % 1000000007;
      
        
    }
};