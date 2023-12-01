#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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


  

    int calibration = 0;
    string line_num;
    for (auto&line: inputs)
    {
        cout << line << endl;
        for (auto &character: line)
        {
            if (isdigit(character)) 
            {
                line_num += character;
                break;
            }
        }

        for (int i = line.length() - 1; i >= 0; i--)
        {
            if (isdigit(line[i])) 
            {
                line_num += line;
                break;
            }
        }
        cout << line_num << endl;
        calibration += stoi(line_num);
        line_num.clear();
    }

    cout << calibration << endl;

}