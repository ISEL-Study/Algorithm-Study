#include <iostream>
#include <queue>
#include <vector>

using namespace std ;

int bfs(int x, int y, vector<pair<int,int>> wall) ;
int map[9][9] ;

int main() 
{
  cin.tie(NULL) ;
  int x, y ;
  int max = 0 ;
  fill(map[0], map[8], -1) ;  
  vector<pair<int, int>> zero ;

  cin >> y >> x ;

  for(int i = 1 ; i <= y ; i++)
  {
    for(int j = 1 ; j <= x ; j++)
    {
      cin >> map[i][j] ;
      if(map[i][j] == 0) zero.push_back(make_pair(i, j)) ;
    }
  }

  for(int i = 0 ; i < zero.size() ; i++)
  {
    for(int j = i + 1 ; j < zero.size() ; j++)
    {
      for(int k = j + 1 ; k < zero.size() ; k++)
      {
        vector<pair<int, int>> wall ;
        wall.push_back(zero[i]) ;
        wall.push_back(zero[j]) ;
        wall.push_back(zero[k]) ;

        int temp = bfs(x, y, wall) ;
        if(temp  > max) max = temp ;
      }
    }
  }

  cout << max << "\n" ;

  return 0 ;
}

int bfs(int x, int y, vector<pair<int,int>> wall)
{
  queue<pair<int, int>> que ;

  int cnt = 0 ;
  int n_map[y+1][x+1] ;
  bool visit[y + 1][x + 1] ;

  fill(visit[0], visit[y + 1], false) ;

  for(int i = 1 ; i <= y ; i++)
  {
    for(int j = 1 ; j <= x ; j++)
    {
      n_map[i][j] = map[i][j] ;
      if(n_map[i][j] == 2) // virus
      {
        que.push(make_pair(i, j)) ;
        visit[i][j] = true ;
      }
    }
  }

  for(auto p : wall) n_map[p.first][p.second] = 1 ;

  while(!que.empty())
  {
    // cout << "Checking...\n" ; 
    auto temp = que.front() ;
    que.pop() ;

    int ty = temp.first ;
    int tx = temp.second ;

    if(tx + 1 <= x)
    {
      if(n_map[ty][tx + 1] == 0 && !visit[ty][tx + 1])
      {
        n_map[ty][tx + 1] = 2 ; // virus
        que.push(make_pair(ty, tx + 1)) ;
        visit[ty][tx + 1] = true ;
      }
    }

    if(tx - 1 >= 1)
    {
      if(n_map[ty][tx - 1] == 0 && !visit[ty][tx - 1])
      {
        n_map[ty][tx - 1] = 2 ; // virus
        que.push(make_pair(ty, tx - 1)) ;
        visit[ty][tx - 1] = true ;
      }
    }

    if(ty + 1 <= y)
    {
      if(n_map[ty + 1][tx] == 0 && !visit[ty + 1][tx])
      {
        n_map[ty + 1][tx] = 2 ; // virus
        que.push(make_pair(ty + 1, tx)) ;
        visit[ty + 1][tx] = true ;
      }
    }

    if(ty - 1 >= 1)
    {
      if(n_map[ty - 1][tx] == 0 && !visit[ty - 1][tx])
      {
        n_map[ty - 1][tx] = 2 ; // virus
        que.push(make_pair(ty - 1, tx)) ;
        visit[ty - 1][tx] = true ;
      }
    }
  }

  for(int i = 1 ; i <= y ; i++)
    for(int j = 1 ; j <= x ; j++)
      if(n_map[i][j] == 0) cnt++ ;

  return cnt ;
}
