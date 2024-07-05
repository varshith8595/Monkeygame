#include<bits/stdc++.h>
using namespace std;
    bool is_prime(int x){
        for(int i=2;i*i<=x;i++){
            if(x%i==0){
                return false;
            }
        }
        return true;
    }
    void solve(int i,int j,vector<vector<int>>&mat,int sum,vector<int>&st,vector<vector<int>>&check){
        int n = mat.size(),m = mat[0].size();
        if(i<=n&&i>=0&&j<=m&&j>=0){
            if(check[i][j]==0){
            sum = sum*10+mat[i][j];
            check[i][j] = 1;
            if(sum>10&&is_prime(sum)){
                st.push_back(sum);
            }
            solve(i-1,j-1,mat,sum,st,check);
            solve(i-1,j,mat,sum,st,check);
            solve(i-1,j+1,mat,sum,st,check);
            solve(i,j-1,mat,sum,st,check);
            solve(i,j+1,mat,sum,st,check);
            solve(i+1,j-1,mat,sum,st,check);
            solve(i+1,j+1,mat,sum,st,check);
            solve(i+1,j,mat,sum,st,check);
            }
        }
    }
    int main() {
        vector<vector<int>>mat;
        mat.push_back({1,1});
        mat.push_back({9,9});
        mat.push_back({1,1});
        vector<int>st;
        int n = mat.size(),m = mat[0].size();
        vector<vector<int>>check(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                solve(i,j,mat,0,st,check);
            }
        }
        map<int,int>mp;
        for(int i=0;i<st.size();i++){
            mp[st[i]]++;
        }
        int maxi=0,ans=0;
        for(auto it : mp){
            if(maxi<=it.second){
                maxi = it.second;
                ans = it.first;
            }
        }
        cout<<ans;
        return 0;
    }
