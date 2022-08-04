#define ll long long
class Solution {
public:
    int ans=0;
    void func(vector<ll> & vec,ll l,ll r)
    {   if(l==r)
            return;
        ll m=(l+r)/2;
        func(vec,l,m);
        func(vec,m+1,r);
        int mid=m+1;
        for(int i=l;i<=m;i++)
        {
            while(mid<=r && vec[i]>2*vec[mid])
                mid++;
            ans+= (mid-m-1);
        }
        int i=l,j=m+1,k=0;
        int f[m-l+1 + r-m];
        while(i<=m && j<=r)
        {
            if(vec[i]>vec[j])
                f[k]=vec[j],j++;
            else
                f[k]=vec[i],i++;
            k++;
        }
        while(i<=m)
            f[k++]=vec[i++];
        while(j<=r)
            f[k++]=vec[j++];
        for(i=l,m=0;i<=r;i++,m++)
            vec[i]=f[m];
        return ;
    }
    int reversePairs(vector<int>& nums) {
        vector<ll> vec(nums.begin(),nums.end());
        func(vec,0,nums.size()-1);
        return ans;
    }
};