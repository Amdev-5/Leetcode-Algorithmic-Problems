class Solution {
public:
    string removeDigit(string number, char digit){
      for(int i =0;i<number.size()-1;i++)
      {
        if(number[i]==digit && number[i]<number[i+1])
          return number.substr(0,i)+number.substr(i+1);
      }
      int index = number.rfind(digit);
      return number.substr(0,index)+number.substr(index+1);
      
        
    }
};