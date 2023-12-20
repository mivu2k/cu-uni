#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;


int main() {
    string original;
    string word;
    string temp[]={};
    
    cout<< "enter an sentence: ";
    getline(cin,original);
    
    int uniques = 0;
    
    
    // for counting word
    const char* str = original.c_str();
    int count=0;
    for (int i = 0; str[i] != '\0';i++)
    {
        if (str[i] == ' ')
            count++;
    }
    // for slpiting word annd outputing
    std::istringstream iss(original);
    for(int i = 0; i < count+1; i++){
        getline(iss, word, ' ');
        temp[i] = word;
        cout << temp[i] << " ";
    }
    int stemp = sizeof(temp)/sizeof(temp[0]);
    sort(temp, temp + stemp);
    
    for(int i = 0; i <= count; i++){
        if(temp == temp+1){
            continue;
        }else{
            uniques++;
        }
       
    }
    
    cout << endl;
    cout <<"total unique word : "  <<uniques;
    cout << endl;
   
 
    
   
}
