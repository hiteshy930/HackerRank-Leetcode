/*
Given an array of integers, where all elements but one occur twice, find the unique element.

Example [1,2,3,4,3,2,1]
The unique element is 4

.

Function Description

Complete the lonelyinteger function in the editor below.

lonelyinteger has the following parameter(s):

    int a[n]: an array of integers

Returns

    int: the element that occurs only once

Input Format

The first line contains a single integer n,
, the number of integers in the array.
The second line contains n space-separated integers that describe the values in  a


It is guaranteed that n is an odd number and that there is one unique element.

Sample Input 0

1
1

Sample Output 0

1


*/

======================================================================
  #include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the lonelyinteger function below.
int lonelyinteger(vector<int> a) {
            int result=0;
            for(int i=0;i<a.size();i++)
             result=result^a[i];                     ///LOGIc
        return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    int result = lonelyinteger(a);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}