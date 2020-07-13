#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std ;

int convert_hex_to_dec(string num) ;

int
main()
{
    cin.tie(NULL) ;
    // vector<int> word ;
    vector<char> result ;
    int N, con ;
    string input ;
    
    /*
    for(int i = 97 ; i <= 122 ; i++)
    {
        for(int j = 48 ; j <= 57 ; j++) word.push_back(i^j) ;
    }
    sort(word.begin(), word.end()) ;
    word.erase(unique(word.begin(), word.end()), word.end()) ;
    
    // for(int k = 0 ; k < word.size() ; k++) cout << word[k] << " " ;
    */
    
    cin >> N ;
    
    for(int i = 0 ; i < N ; i++)
    {
        cin >> input ;
        con = convert_hex_to_dec(input) ;
        // cout << con << "\n" ;
        if(con <= 95 && con >= 64) result.push_back('-') ;
        else result.push_back('.') ;
    }
    
    for(int i = 0 ; i < N ; i++) cout << result[i] ;
    cout << "\n" ;
}


int convert_hex_to_dec(string num)
{
    vector<int> number ;
    int sum = 0 ;
    char var ;
    
    for(int i = 0 ; i < num.size() ; i++)
    {
        var = num[i] ;
        if(var >= 48 && var <= 57) number.push_back(var - '0') ; // 0 ~ 9
        else // A ~ F
        {
            if(var == 'A') number.push_back(10) ;
            else if(var == 'B') number.push_back(11) ;
            else if(var == 'C') number.push_back(12) ;
            else if(var == 'D') number.push_back(13) ;
            else if(var == 'E') number.push_back(14) ;
            else if(var == 'F') number.push_back(15) ;
        }
    }

    for(int i = 0 ; i < num.size() ; i++)
    {
        sum += number[i] * pow(16, num.size() - i - 1) ;
    }
        
    return sum ;
}

