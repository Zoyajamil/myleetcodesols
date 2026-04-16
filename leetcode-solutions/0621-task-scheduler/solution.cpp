/*class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //count frequwncy of each task
        unordered_map<char,int> freq;
        for(char t : tasks){
            freq[t]++;
        }

        //max heap to store the task with hughest remaining count 
        priority_queue<int> maxheap;
        for(auto &it : freq){
            maxheap.push(it.second);
        }

        int time=0;

        //process tasks in cycles of n+1
        while(!maxheap.empty()){

            vector<int> temp; //store tasks which have remaining count
            int cycle=n+1;    //one cycle
            int i=0;          //tracks slots used in the current cycle

            //fill the cycle with tasks  || until heap is empty
            while(i<cycle && !maxheap.empty()){
                int cnt=maxheap.top();
                maxheap.pop();

                //execute the task ->decrease the count
                if(cnt-1>0){
                    temp.push_back(cnt-1); //pending tasks in temp
                }

                time++;
                i++;
            }

            //Push remaining tasks back to heap for next cycles
            for(int val : temp){
                maxheap.push(val);
            }

            //if no tasks left
            if(maxheap.empty()) break;

            //add idle time if cycle was nt completely filled
            time+=(cycle-i);
        }
        return time;
    }
};*/


class Solution{
public: 
    int leastInterval(vector<char>& tasks, int n){


        vector<int> freq(26,0);
        for(char t : tasks){
            freq[t-'A']++;
        }

        int maxfreq=*max_element(freq.begin(),freq.end());
        int maxcount=0;
        for(int f : freq){
            if( f == maxfreq){
                maxcount++;
            }
        }

        int partcount=maxfreq-1;
        int partlength=n+1;
        int minTime= partcount*partlength + maxcount;

        return max((int)tasks.size(),minTime);
    }
};
