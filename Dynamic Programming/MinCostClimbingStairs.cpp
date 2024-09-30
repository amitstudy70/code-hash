class Solution {
public:

    // recurssion
    // int ways(vector<int>& dp,vector<int>& cost,int n){
    //     if(n==1){
    //         return 0;
    //     }
    //     if(n==2){
    //         return min(cost[0],cost[1]);
    //     }
    //     if(dp[n]!=-1){
    //         return dp[n];
    //     }

    //     return dp[n] = min( ways(dp,cost,n-1)+cost[n-1],ways(dp,cost,n-2)+cost[n-2]);
        
    // }

    // bootom up appraoch
    int iterative(int n,vector<int>& dp,vector<int>& cost){
       
        dp[0]=0;
        dp[1]=0;

        for(int i=2;i<=n;i++){
            dp[i]= min(cost[i-1]+dp[i-1],cost[i-2]+dp[i-2]);
        }
        return dp[n]; 
    }

    // space optimitazion
    int spo(vector<int>& cost,int n){
        int p1=0;
        int p2=0;
        int curr=0;

          for(int i=2;i<=n;i++){
            // dp[i]= min(cost[i-1]+dp[i-1],cost[i-2]+dp[i-2]);
            curr = min(cost[i-1]+p1,p2+cost[i-2]);
            p2=p1;
            p1=curr;
        }
        return curr; 

    }


    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        
        // return ways(dp,cost,n);
        // return iterative(n,dp,cost);
        return spo(cost,n);

    }
};