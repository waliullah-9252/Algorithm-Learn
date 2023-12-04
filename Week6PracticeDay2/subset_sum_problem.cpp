//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    int dp[1005][1005];
    bool subset_sum(vector<bool>a, int s)
    {
        if (a.size() == 0)
        {
            if (s == 0)
                return true;
            else
                return false;
        }
        if (dp[a.size()][s] != -1)
            return dp[a.size()][s];
        if (a[a.size() - 1] <= s)
        {
            bool op1 = subset_sum(a.size() - 1, a, s - a[a.size() - 1]);
            bool op2 = subset_sum(a.size() - 1, a, s);
            return dp[a.size()][s] = op1 || op2;
        }
        else
        {
            return dp[a.size()][s] = subset_sum(a.size() - 1, a, s);
        }
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        
        for (int i = 0; i <= arr.size(); i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                dp[i][j] = -1;
            }
        }
        int result = subset_sum(arr,sum);
        return result;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends