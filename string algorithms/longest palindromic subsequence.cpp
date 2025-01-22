#include <bits/stdc++.h>
using namespace std;


bool isSubSequence(string str1, string str2)
{
	int m = str1.length(), n = str2.length();

	int j = 0; 

	for (int i = 0; i < n && j < m; i++)
		if (str1[j] == str2[i])
			j++;

	return (j == m);
}


string findLongestString(vector<string> dict, string str)
{
	string result = "";
	int length = 0;


	for (string word : dict) {
			if (length < word.length()
			&& isSubSequence(word, str)) {
			result = word;
			length = word.length();
		}
	}

	return result;
}

int main()
{
	vector<string> dict;
	int n;
	cin>>n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	for(int i=0;i<n;i++){
	    string word;
        getline(cin, word); 
	     dict.push_back(word);
	}
	string str ;
	cin>>str;       
	cout << findLongestString(dict, str) << endl;
	return 0;
}
