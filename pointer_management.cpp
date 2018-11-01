 	#include<vector>
    #include<string>
    #include<iostream>
    #include<algorithm>
    using namespace std;
    int main()  // small program messing around with strings
    {
        cout << "enter some whitespace-separated words:\n";
        vector<string> v;
        string s;
        getline(cin, s);
        cout << s << endl;
        cin.get();
    }