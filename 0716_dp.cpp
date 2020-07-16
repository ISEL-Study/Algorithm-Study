#include <iostream>
#include <algorithm>

using namespace std ;

#define MAX 100001
#define INF 9999999

int dp[MAX] ;

int
main()
{
    cin.tie(NULL) ;
    int N, i ;
    
    cin >> N ;
    
    for(int j = 1 ; j <= N ; j++) dp[j] = INF ;
    
    for(i = 1 ; i <= N ; i++)
    {
        if(i * i <= N) dp[i * i] = 1 ;
        else break ;
    }
    
    cout << "I is " << i << "\n" ;
    
    for(int j = 2 ; j <= N ; j++)
        if(dp[j] != 1)
            for(int k = 1 ; k <= (i - 1) && (j - (k * k)) > 0 ; k++) dp[j] = min(dp[j], dp[j - (k * k)] + 1) ;
    
    cout << dp[N] << "\n" ;
    
}

