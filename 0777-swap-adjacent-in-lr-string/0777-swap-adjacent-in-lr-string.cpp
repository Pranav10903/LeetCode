class Solution {
public:
    bool canTransform(string start, string end) {
        if(start.size()==1){
            if(start[0]==end[0])
                return true;
            return false;
        }
        
        int ptr1=0, ptr2=0; //X == ignore
        while( ptr1<start.size() && ptr2<end.size() ){
            while(start[ptr1] == 'X')
                ptr1++;
            while(end[ptr2] == 'X')
                ptr2++;                 // 0 1
            char a=start[ptr1];
            char b=end[ptr2]; //R R
            if(a!=b)
                return false;
            if(a == 'L' && ptr1<ptr2)
                return false;
            if(a == 'R' && ptr1>ptr2)
                return false;
            ptr1++;
            ptr2++;
        }
        // for remaining spaces in the end (X's)
        while(ptr1<start.size() && start[ptr1]=='X')
            ptr1++;
        while(ptr2<end.size() && end[ptr2]=='X')
            ptr2++;
        
        return ptr1==ptr2;
    }
};