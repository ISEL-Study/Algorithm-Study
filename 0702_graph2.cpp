#include <iostream>
#include <queue>


using namespace std ;

void bfs(int M, int N) ;

int main() {
  int M, N ;

  cin >> M >> N ;

  bfs(M, N) ;

}

void bfs(int M, int N)
{
  queue< pair<int, int> > q ;
  
  int map[N + 1][M + 1] ;
  bool visit[N + 1][M + 1] ;
  int cnt = 0, zero = 0 ;

  fill(visit[0], visit[N], false) ;

  for(int i = 0 ; i < N ; i++)
  {
    for(int j = 0 ; j < M ; j++)
    {
      cin >> map[i][j] ;
      if(map[i][j] == 1) q.push(make_pair(i, j)) ;
      if(map[i][j] == 0) zero++ ;
    }
  }

  while(!q.empty() && zero != 0)
  {
    int size = q.size() ;

    for(int i = 0 ; i < size ; i++)
    {
      auto temp = q.front() ;
      q.pop() ;

      int tx = temp.first ;
      int ty = temp.second ;
      
      if(tx + 1 < N)
      {
        if(map[tx + 1][ty] == 0 && !visit[tx + 1][ty])
        {
          map[tx + 1][ty] = 1 ; 
          q.push(make_pair(tx + 1, ty)) ;
          zero-- ;
          visit[tx + 1][ty] = true ;
        }
        
      }

      if(tx - 1 >= 0)
      {
        if(map[tx - 1][ty] == 0 && !visit[tx - 1][ty])
        {
          map[tx - 1][ty] = 1 ; 
          q.push(make_pair(tx - 1, ty)) ;
          zero-- ;
          visit[tx - 1][ty] = true ;
        }
      }
      
      if(ty + 1 < M)
      {
        if(map[tx][ty + 1] == 0 && !visit[tx][ty + 1])
        {
          map[tx][ty + 1] = 1 ; 
          q.push(make_pair(tx, ty + 1)) ;
          zero-- ;
          visit[tx][ty + 1] = true ;
        }
      }

      if(ty - 1 >= 0)
      {
        if(map[tx][ty - 1] == 0 && !visit[tx][ty - 1])
        {
          map[tx][ty - 1] = 1 ; 
          q.push(make_pair(tx, ty - 1)) ;
          zero-- ;
          visit[tx][ty - 1] = true ;
        }
      }
    }
    cnt++ ; 
  }

  if(zero == 0) printf("%d\n", cnt) ;
  else printf("-1") ;
}
