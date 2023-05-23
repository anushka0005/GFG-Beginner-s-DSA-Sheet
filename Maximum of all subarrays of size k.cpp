//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    vector<int> max_of_subarrays(int *arr, int n, int k)
    {
        deque<int> q;
        q.push_back(arr[0]);

        vector<int> ans;

        int maxi;
        for (int i = 1; i < k; i++)
        {
            while (!q.empty() && arr[i] > q.back())
            {
                q.pop_back();
            }
            q.push_back(arr[i]);
        }
        
        maxi = q.front();
        ans.push_back(maxi);

        for (int i=0, j= i + k - 1; j<n-1; j++, i++)
        {
            if (arr[i] == q.front())
            {
                q.pop_front();
            }
            while (!q.empty() && arr[j + 1] > q.back())
            {
                q.pop_back();
            }
            q.push_back(arr[j + 1]);

            maxi = q.front();
            ans.push_back(maxi);
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
