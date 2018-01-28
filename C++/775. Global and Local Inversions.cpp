/*
We have some permutation A of [0, 1, ..., N - 1], where N is the length of A.

The number of (global) inversions is the number of i < j with 0 <= i < j < N and A[i] > A[j].

The number of local inversions is the number of i with 0 <= i < N and A[i] > A[i+1].

Return true if and only if the number of global inversions is equal to the number of local inversions.

Example 1:

Input: A = [1,0,2]
Output: true
Explanation: There is 1 global inversion, and 1 local inversion.
Example 2:

Input: A = [1,2,0]
Output: false
Explanation: There are 2 global inversions, and 1 local inversion.
Note:

A will be a permutation of [0, 1, ..., A.length - 1].
A will have length in range [1, 5000].
The time limit for this problem has been reduced.

*/

/*
算法思想：可以直接进行统计Global inversions和Local inversions然后进行比较。在统计Global inversions时实际上就是个求在数组中求逆序数问题。超时方法是直接两层循环遍历，但快速方法可以使用归并排序来统计逆序数的个数。
*/
class Solution {
public:
    long long int cnt;
    vector<int> a;
    int b[5005];
    void mergesort(int low,int mid,int high)  
    {  
        int i=low,j=mid+1,k=0;  
        while(j<=high&&i<=mid)  
        {  
            if(a[i]<=a[j])  
                b[k++]=a[i++];  
            else  
            {  
                b[k++]=a[j++];  
                cnt+=(mid-i)+1;  
            }  
        }  
        while(i<=mid)  
            b[k++]=a[i++];  
        while(j<=high)  
            b[k++]=a[j++];  
        for(i=0; i<k; i++)  
            a[i+low]=b[i];  
    }  
    void msort(int low,int high)  
    {  
        if(low<high)  
        {  
            int mid=(low+high)/2;  
            msort(low,mid);  
            msort(mid+1,high);  
            mergesort(low,mid,high);  
        }  
    }
    bool isIdealPermutation(vector<int>& A) {
        int cnt1 = 0,cnt2 = 0;
        int sz = A.size();
        for(int i = 0;i < sz - 1;i++)
        {
            if(A[i] > A[i + 1])
                cnt1++;
        }
        a = A;
        msort(0,sz - 1);
        cout<<cnt<<endl;
        return cnt1 == cnt;
    }
};


/*
方法二：由于这道题只需要判断Global inversions是否等于Local inversions，所以当局部出现nums[i] > nums[i + 1]时置换，循环完毕，判断置换后的数组是否是有序数组，如果是说明两者相等，否则不等。
*/
class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        vector<int> Abak = A;
        int sz = A.size();
        for(int i = 0;i < sz - 1;i++)
        {
            if(Abak[i] > Abak[i + 1])
            {
                swap(A[i],A[i + 1]);
            }
        }
        for(int i = 0;i < sz - 1;i++)
        {
            if(A[i] > A[i + 1])
                return false;
        }
        return true;
    }
};