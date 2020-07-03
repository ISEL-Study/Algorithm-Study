#include <iostream>

using namespace std ;

int dp[30][30] ;

int main() 
{
  int loop, M, N ;
  
  for(int i = 1 ; i <= 29 ; i++) dp[1][i] = i ;
  
  for(int i = 2 ; i <= 29 ; i++)
  {
    for(int j = i ; j <= 29 ; j++)
    {
      if(i == j) dp[i][j] = 1 ;
      else dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1] ;
    }
  }

  cin >> loop ;

  for(int k = 0 ; k < loop ; k++)
  {
    cin >> N >> M ;
    cout << dp[N][M] << "\n" ;
  }
}
