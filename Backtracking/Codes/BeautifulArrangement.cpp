class Solution {
public:

    void f(vector<int> &v,int n,int &ans,int currNum){
        if(currNum==n+1){
            ans++;
        }

        for(int i=1;i<=n;i++){
            if(v[i]==0 && (currNum%i==0 || i%currNum==0)){
                v[i]=currNum;
                f(v,n,ans,currNum+1);
                v[i]=0;
            }
        }
    }

    int countArrangement(int n) {
        vector<int> v(n+1);
        int ans = 0;
        f(v,n,ans,1);
        return ans;   
    }
};