#include <stdio.h>
#include "map.h"


int main(){
  
  int n,k;
  scanf("%d %d",&n, &k);
  Map m;
  CreateEmpty(&m);

  int ans = 0;
  int i;
  for(i =0 ;i < n;i++){
    int valueNow;
    scanf("%d",&valueNow);
    
    int findAnother = k-valueNow;
    int cnt = Value(m,findAnother);
    
    ans += cnt;
    int valueItself = Value(m,valueNow);
    
    Delete(&m,valueNow);
    Insert(&m,valueNow,valueItself+1);
  }

  printf("%d\n",ans);


    


  
  return 0;
}
