class Solution {
public:
    bool isIsomorphic(string s, string t) {
         //If length of any of the string is not equal the we return false
        if(s.length() != t.length()){
            return false;
        }
        //To check which character of s is mapped with t 
        unordered_map<char, char> checkS;
        unordered_map<char, char>::iterator it;
        
        //To check character of t is mapped or not
        map<char, bool> checkT;
        
            for(int i=0; i<s.length(); i++){
                char c1 = s[i];
                char c2 = t[i];
                
            // Checking if character is already present in checkS or not
            it = checkS.find(c1);
            if(it!=checkS.end()){
                // If character is present the we check the map value is equal to c2 or not
                // If not then we return false
                if(checkS[c1]!=c2){
                    return false;
                }
            }else{
                // if element of t already mapped with some other element the we return false
                // Here note that we come after if statement i.e. here when we come the condition is character of s is not mapped with anyone because of the one-one mapping t also doesn't want to map with any of the previous element of s 
                if(checkT[c2]){
                    return false;
                }else{
                    //If element are not mapped yet
                    //i.e. element are not yet compared the we insert it into checkS and checkT
                    checkS[c1] = c2;
                    checkT[c2] = true;
                }
            }
        }
        
        return true;
    }
};