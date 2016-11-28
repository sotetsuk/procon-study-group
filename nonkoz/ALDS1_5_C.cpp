#include <iostream>
#include <cstdlib>
#include <cstdio>

#include <cmath>

void koch(double p1x,double p1y, double p2x,double p2y,int n){
  double sx, sy,ux, uy,tx,ty;
  
  if(n != 0){
    sx = (2.0 * p1x + 1.0 * p2x)/3.0;
    sy = (2.0 * p1y + 1.0 * p2y)/3.0;
    tx = (1.0 * p1x + 2.0 * p2x)/3.0;
    ty = (1.0 * p1y + 2.0 * p2y)/3.0;
    ux = (tx - sx) * cos(M_PI/3.0) - (ty - sy)*sin(M_PI/3.0) + sx;
    uy = (tx - sx) * sin(M_PI/3.0) + (ty - sy)*cos(M_PI/3.0) + sy;
    koch(p1x,p1y, sx,sy,n-1);
    printf("%f %f\n", sx,sy);
    koch(sx,sy, ux,uy,n-1);
    printf("%f %f\n", ux,uy);
    koch(ux, uy, tx, ty,n-1);
    printf("%f %f\n", tx,ty);
    koch(tx,ty, p2x,p2y,n-1);
  }
  return;
}
int main()
{
  int n;
  scanf("%d", &n);
  double p1x = 0.0;
  double p1y = 0.0;
  double p2x = 100.0;
  double  p2y = 0.0;
  printf("%f %f\n",p1x,p1y); 
  koch(p1x, p1y,p2x,p2y, n);
  printf("%f %f\n",p2x,p2y); 
  return 0;
}
