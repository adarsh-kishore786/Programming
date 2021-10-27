/** Consider an array of numeric strings where each string is a positive number with anywhere from 1 to 10⁶ digits. Sort the array's elements in non-decreasing or
ascending order of their integer values **/

#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cout<<"Enter number of elements you are going to enter " << endl;
  cin>>n;
  cout<<"Enter the elements one by one now "<<endl;
  vector<string>a(n);
  
  for(int i=0; i<n ; i++ )
    cin>>a[i];
   
  sort(a.begin(),a.end(),[](const string left , const string right)
  {
    if(left.size() != right.size() )
        return left.size() < right.size();
        
    else
       return left<right;
   });
   
   cout<<" The array in ascending order " << endl;
   
    for(int i=0 ; i<n ; i++)
       cout<<a[i]<<endl;
      
     return 0;
     
    }
     
