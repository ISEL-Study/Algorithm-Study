#include <iostream>
#include <queue>


using namespace std ;

void bfs(int oldx, int oldy, int x, int y, int size) ;

int main() {
  int loop, size ;
  int x, y, oldx, oldy ;
  
  cin >> loop ;

  for(int k = 0 ; k < loop ; k++)
  {
    cin >> size ;
    cin >> oldx >> oldy ;
    cin >> x >> y ;

    bfs(oldx, oldy, x, y, size) ;
  }
}

void bfs(int oldx, int oldy, int x, int y, int size)
{
  queue< pair<int, int> > q ;
  int x_dir[8] = {-2, -1, 2, 1, -2, -1, 2, 1} ;
  int y_dir[8] = {1, 2, 1, 2, -1, -2, -1, -2} ;
  
  int map[301][301] ;
  bool visit[301][301] ;

  fill(map[0], map[300], 0) ;
  fill(visit[0], visit[300], false) ;
  visit[oldx][oldy] = true ;
  q.push(make_pair(oldx, oldy)) ;

  while(!q.empty())
  {
    auto temp = q.front() ;
    q.pop() ;

    int tx = temp.first ;
    int ty = temp.second ;
    //printf("%d %d\n", tx, ty) ;
    
    if(tx == x && ty == y)
    {
      printf("%d\n", map[tx][ty]) ;
      return ;
    }
    for(int i = 0 ; i < 8 ; i++)
    {
      if(tx + x_dir[i] >= 0 && tx + x_dir[i] < size)
      {
        if(ty + y_dir[i] >= 0 && ty + y_dir[i] < size)
        {
          if(!visit[tx + x_dir[i]][ty + y_dir[i]])
          {
            q.push(make_pair(tx + x_dir[i], ty + y_dir[i])) ;
            visit[tx + x_dir[i]][ty + y_dir[i]] = true ;
            map[tx + x_dir[i]][ty + y_dir[i]] = map[tx][ty] + 1 ;
          }
        }
      }
    }  
  }

  printf("%d\n", map[x][y]) ;  
}
