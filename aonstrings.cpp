#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define fr(i,a,b) for(int i=a;i<b;i++)
string burrows_wheeler_transform(string s)
{
    lli n=s.length();
    //cout<<s<<'\n';
    string arr[n];
    fr(i,0,n)
    {arr[i]= s.substr(n-i-1,i+1)+s.substr(0,n-i-1);
    //cout<<arr[i]<<'\n';
    }
    sort(arr,arr+n);
    string bwt="";
    fr(i,0,n)bwt.push_back(arr[i][n-1]);
    //cout<<bwt;
    return bwt;

}
string reversebwt(string s)
{
	int n = s.length();
	vector<pair<char,lli>> v(n);
	fr(i,0,n)v[i]={s[i],i};
	sort(v.begin(),v.end());
	lli hash[n]={0};
	fr(i,0,n)hash[i]=v[i].second;
	lli cnt=0;
	string rwbt="";
	fr(i,0,n)
	{rwbt.push_back(s[hash[cnt]]);cnt=hash[cnt];}





		return rwbt;
}
vector<lli> better_bwmatching(string s,vector<string> p)
{
	int n = s.length();
	vector<pair<char,lli>> v(n);
	fr(i,0,n)v[i]={s[i],i};
	sort(v.begin(),v.end());
	lli hash[n]={0};
	fr(i,0,n)hash[v[i].second]=i;
	


}


int main()
{
	/*#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif*/
    

    string s;
    cin>>s;
    string rbwt = reversebwt(s);
    cout<<rbwt.substr(1)+"$";
    //cout<<"helo";
	return 0;

}