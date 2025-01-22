#include<bits/stdc++.h> 
using namespace std; 
struct date 
{ 
    int day; 
    int month; 
    int year; 
}; 
  
int main() 
{ 
    int n;
    cin>>n;
    struct date input[n]; 
    for(int i=0; i<n; i++) 
    { 
        cin>>input[i].day; 
        cin>>input[i].month; 
        cin>>input[i].year; 
  
    } 
    for (int i=0; i<n-1; i++) 
    { 
        for (int j=i+1; j<n; j++) 
        { 
            if (input[i].year > input[j].year) 
            { 
                struct date temp = input[i]; 
                input[i] = input[j]; 
                input[j] = temp; 
            } 
            else if (input[i].year == input[j].year && input[i].month > input[j].month) 
            { 
                struct date temp = input[i]; 
                input[i] = input[j]; 
                input[j] = temp; 
            } 
            else if (input[i].year == input[j].year && input[i].month == input[j].month && input[i].day > input[j].day) 
            { 
                struct date temp = input[i]; 
                input[i] = input[j]; 
                input[j] = temp; 
            } 
  
        } 
    } 
  
  
    for(int i=0; i<n; i++) 
    { 
        cout<<input[i].day<<" "<<input[i].month<<" "<<input[i].year; 
        cout<<endl; 
    } 
}
