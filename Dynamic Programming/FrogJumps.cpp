#include <bits/stdc++.h>

// int ways(int n, vector<int> &heights){
//     if(n==0){
//         return 0;
//     }
//     if(n<0){
//         return 0;
//     }

//     int oneStep = ways(n-1,heights) + abs(heights[n]-heights[n-1]);
//     int twoStep=INT_MAX;
//     if(n>1)
//      twoStep = ways(n-2,heights) + abs(heights[n]-heights[n-2]);

//     return min(oneStep,twoStep);
// }

// int memozation(int n, vector<int> &heights,vector<int> &dp){
//     if(n==0){
//         return 0;
//     }
//     if(n<0){
//         return 0;
//     }

//     if(dp[n]!=-1){
//         return dp[n];
//     }

// int oneStep = memozation(n-1,heights,dp) + abs(heights[n]-heights[n-1]);
// int twoStep=INT_MAX;
// if(n>1)
//  twoStep = memozation(n-2,heights,dp) + abs(heights[n]-heights[n-2]);

// dp[n] = min(oneStep,twoStep);
//     return dp[n];
// }

// int tabulation(int n, vector<int> &heights, vector<int> &dp) {
//  dp[0] = 0;
//   for (int i = 1; i <= n; i++) {
    // int oneStep =dp[i-1] + abs(heights[i] - heights[i - 1]);
    // int twoStep = INT_MAX;
    // if (i > 1)
    //   twoStep  =dp[i-2] + abs(heights[i] - heights[i - 2]);

    // dp[i] = min(oneStep, twoStep);
//   }

//   return dp[n]; 
// }

int spaceOptimization(int n, vector<int> &heights){
    int prev1 = 0;
    int prev2 = 0;
    int curr = 0;
    for(int i=1;i<=n;i++){
        int oneStep =prev1 + abs(heights[i] - heights[i - 1]);
    int twoStep = INT_MAX;
    if (i > 1)
      twoStep  =prev2 + abs(heights[i] - heights[i - 2]);


    curr = min(oneStep, twoStep);

    prev2 = prev1;
    prev1=curr;
    }
    return curr;
}


int frogJump(int n, vector<int> &heights) {
    //recursive
  // return ways(n-1,heights);


// memozation
  vector<int> dp(n + 1, -1);
//   return memozation(n - 1, heights, dp);

//tabulation
// return tabulation(n-1,heights,dp);

// space optimztion
  return spaceOptimization(n-1,heights);
}