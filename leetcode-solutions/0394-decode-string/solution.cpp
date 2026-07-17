class Solution {
public:
    string decodeString(string s) {
        if(s.length()==0) return s;

        string ans="";
        int num=0;
        stack<int> numstck;
        stack<string> strstck;

        for(auto &x : s){
            if(x>='0' && x<='9'){
                num= (num * 10) + (x-'0');  //to convert string ASCII char to a number 
            }

            else{
                if(x=='['){
                    numstck.push(num); //if num add to numstack
                    num=0;
                    strstck.push("[");
                }

                else if(x==']'){
                    string temp="";

                    while(!strstck.empty() && strstck.top()!="["){ //pop until ] and add to temp
                        temp= strstck.top() + temp;
                        strstck.pop();
                    }

                    strstck.pop();  //remove '['

                    int repeat=numstck.top(); //take the number
                    numstck.pop();

                    string tempans="";
                    //repeat the string n no of times 
                    for(int i=0; i<repeat; i++){
                        tempans+=temp;
                    }

                    strstck.push(tempans);
                }

                else{  //a normal character is seen here 
                    string temp="";
                    temp+=x;
                    strstck.push(temp);
                }
            }
        }

        while(!strstck.empty()){
            ans=strstck.top() + ans;
            strstck.pop(); 
        }
    return ans;

    }
};
