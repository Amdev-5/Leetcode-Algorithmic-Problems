class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
      int burgers = cheeseSlices;
      for(int jumbo=0;jumbo<=burgers;jumbo++)
      {
        int small= burgers-jumbo;
        if((4*jumbo+2*small)==tomatoSlices)
          return {jumbo,small};
      }
      return {};
    }
};