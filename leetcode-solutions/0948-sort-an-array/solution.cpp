class Solution {
public:


    void merge(vector<int>& nums, int left,int right, int mid){
        int n1= mid-left+1;
        int n2=right-mid;

        vector<int> l(n1);
        vector<int> r(n2);

        for(int i=0;i<n1;i++){
            l[i]=nums[left+i];
        }
        for(int i=0;i<n2;i++){
            r[i]=nums[mid+1+i];
        }

        int i=0;
        int j=0;
        int k=left;

        while(i<n1 && j<n2){
            if(l[i]<r[j]){
                nums[k]=l[i];
                i++;
            }
            else{
                nums[k]=r[j];
                j++;
            }
            k++;
        }
            while(i<n1){
                nums[k]=l[i];
                i++;
                k++;
            }

            while(j<n2){
                nums[k]=r[j];
                j++;
                k++;
            }
    }

    void mergesort(vector<int>& nums, int left,int right){
        if(left<right){
            int mid= left + (right-left) /2;
            mergesort(nums,left,mid);
            mergesort(nums,mid+1,right);
            merge(nums,left,right,mid);
        }
    }


    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
};
