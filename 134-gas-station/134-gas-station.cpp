class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int n = gas.size();
      int tank = 0;
      int index = 0;
      int total=0;
      for(int i = 0;i<n;i++)
      {
        tank+=gas[i]-cost[i];
        total+=gas[i]-cost[i];
        if(tank<0)
        {
          index = i+1;
          tank = 0;
        }
      }
      if(total<0)
        return -1;
      return index;
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      /*
        int n = gas.size();
        int tank = 0;
        int total = 0;
        int index = 0;
        for(int i =0;i<n;i++)
        {
            int consume = gas[i]-cost[i];
            tank+=consume;
            total+=consume;
            if(tank<0)
            {
                index = i+1;
                tank = 0;
            }
        }
        if(total>=0)
            return index;
        return -1;
        */
        
        
        
        
        
        
        /*
        if sum of differences >=0 then possible solution otherwise not
        if anytime total fuel in tank get less than 0 than update the tank and answer can't be less than that index so for time being put it as i+1 
        at end if ans possible return index otherwise return -1
        
        
        */
        
        
        
        
        
        
        
        
        
        
        
        

        //https://www.youtube.com/watch?v=xWgbFI_rXJs
        /*
        //let's check from each stop 
        int n = gas.size();
        for(int i = 0;i<n;i++)
        {
            int petrol = 0,stopcount = 0,j = i;
            while(stopcount<n)
            {
                petrol+=gas[j%n];
                petrol-=cost[j%n];
                if(petrol<0)
                    break;
                stopcount++;
                j++;
            }
            if(stopcount==n && petrol>=0)
                return i;
            
        }
        return -1;
        */
        
    }
};
