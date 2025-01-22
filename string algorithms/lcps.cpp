#include<iostream>
#include<algorithm>

using namespace std;

// Function to find the longest common prefix
string longestCommonPrefix(string ar[], int n)
{

    if (n == 0)
        return "";
  
   if (n == 1)
        return ar[0];

    sort(ar, ar + n);

    int en = min(ar[0].size(), 
                 ar[n - 1].size());

    
    string first = ar[0], last = ar[n - 1];
    int i = 0;
    while (i < en && first[i] == last[i])
        i++;

    string pre = first.substr(0, i);
    return pre;
}

int main()
{
    int n;
    cin>>n;
    string ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    string str = longestCommonPrefix(ar, n);
    if(str=="")
    cout<<"No longest prefix found";
    else
    cout<<str;
    return 0;
}
