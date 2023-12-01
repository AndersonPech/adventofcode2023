#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <regex>


using namespace std;


int main() 
{
    vector<string> inputs;
    ifstream myfile;
    myfile.open("input.txt");
    string myline;

    if (myfile.is_open()) 
    {
        while (getline(myfile, myline)) 
        {
            inputs.insert(inputs.end(), myline);
        }
    }

    myfile.close();

    int res = part2(inputs);
    cout << res << endl;
    unordered_map<string, string> hashmap;
    hashmap.insert({"two", "2"});
    hashmap.insert({"three", "3"});
    hashmap.insert({"four", "4"});
    hashmap.insert({"five", "5"});
    hashmap.insert({"six", "6"});
    hashmap.insert({"seven", "7"});
    hashmap.insert({"eight", "8"});
    hashmap.insert({"nine", "9"});
    hashmap.insert({"one","1"});

    vector<string> val; 
    int sum = 0;
    string sum_string;

    for (auto &line: inputs)
    {
        string n = line;
        for(auto const iter: hashmap)
        {
            string k =  iter.first;
            string v = iter.second;
            //ignore value
            //Value v = iter->second;
            regex reg(k); // Replace string with number
            n = regex_replace(n, reg, string(k + v + k)); //Add string in front of number and behind for edge cases such as eighthree
        }
        val.push_back(n);
    }

    int calibration = 0;
    string line_num;
    int k = 0;
    for (auto&line: val)
    {
        for (int i = 0; i < line.length(); i++)
        {
            if (isdigit(line[i])) 
            {
                line_num += line[i];
                break;
            }
        }

        for (int i = line.length() - 1; i >= 0; i--)
        {
            if (isdigit(line[i])) 
            {
                line_num += line[i];
                break;
            }
        }

  
        calibration += stoi(line_num);
        line_num.clear();
    }

    cout << calibration << endl;

}