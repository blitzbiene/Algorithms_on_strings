#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define fr(i,a,b) for(int i=a;i<b;i++)
#define tc int t;cin>>t;while(t--)
vector<lli> prefix(string s)
{
    int n = s.length();
	vector<lli> prefixarray(n);
	lli cur=0;
	prefixarray[0]=0;
	fr(i,1,n)
	{
        while(cur>=0)
        {
        	if(cur==0 && s[cur]!=s[i]){prefixarray[i]=0;break;}
        	else 
        	if(s[cur]==s[i]){prefixarray[i]=++cur;break;}
        	cur=prefixarray[cur-1];
        }

 	}
 	return prefixarray;
 }
void kmp()
{
	 string s;
     cin>>s;
      lli hash[s.length()]={0};
     tc
     {string pat;
     cin>>pat;                
     
     string check=pat+"$"+s;
     vector<lli> p = prefix(check);
     for(int i=pat.length()+1;i<p.size();i++)
     if(p[i]==pat.length())hash[i-2*pat.length()]=1;}
     fr(i,0,s.length())if(hash[i]==1)cout<<i<<" ";}



vector<lli> getorder(string s)
{
	lli hash[256]={0};
	int n = s.length();
	vector<lli> order(n);
	fr(i,0,n)hash[(int)(s[i])]++;
	fr(i,1,256)hash[i]+=hash[i-1];
	for(int i=n-1;i>=0;i--)
	{hash[(int)(s[i])]--;order[hash[(int)(s[i])]]=i;}
    return order;
}

vector<lli> getclas(vector<lli> order,string s)
{
	int n = s.length();
	vector<lli> clas(n);
	lli cnt=0;
	fr(i,0,n)
	{
		if(i==0)clas[order[i]]=0;
		else if(s[order[i]]==s[order[i-1]])clas[order[i]]=clas[order[i-1]];
		else clas[order[i]]=clas[order[i-1]]+1;
	}
	return clas;

}

vector<lli> sortdoublecycle(string s,vector<lli> clas,vector<lli> order,lli l)
{
	
	int n=s.length();
	vector<lli> neworder(n);
	lli hash[n]={0};
	fr(i,0,n)hash[clas[i]]++;
	fr(i,1,n)hash[i]+=hash[i-1];
	for(int i=n-1;i>=0;i--)
	{
		hash[clas[(order[i]-l+n)%n]]--;
		neworder[hash[clas[(order[i]-l+n)%n]]]=(order[i]-l+n)%n;

	}
    return neworder;

}
vector<lli> updateclass(vector<lli> neworder,vector<lli>clas,lli l)
{
   vector<lli> newclas(clas.size());
   int n= clas.size();
   fr(i,0,n)
   {
   if(i==0)newclas[neworder[i]]=0;
   else if(clas[neworder[i-1]]==clas[neworder[i]]
   && clas[(neworder[i-1]+l)%n]==clas[(neworder[i]+l)%n])
   newclas[neworder[i]]=newclas[neworder[i-1]];
    else newclas[neworder[i]]=newclas[neworder[i-1]]+1;

   }
   return newclas;


}
void suffixarray()
{
	string s;
	cin>>s;
	vector<lli> order,clas,neworder,newclas;
	order = getorder(s);
	clas = getclas(order,s);
	lli l=1;
	while(l<=s.length())
	{
	neworder=sortdoublecycle(s,clas,order,l);
	newclas= updateclass(neworder,clas,l);
	order=neworder;
	clas=newclas;
	l*=2;
	}
	fr(i,0,s.length())cout<<neworder[i]<<" ";



}
int main()
{suffixarray();return 0;}