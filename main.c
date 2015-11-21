#include <stdio.h>
#include "hul/hul.h"
#include "math.h"
#include "time.h"
#define radius 5.0
#define pts 15

int main()
{
    
    int pointsize = 10; int pointlength = 0;
    TRI* tr = NULL;
    
    double v[pts][3];
        
    double p[3];
    
    srand48(time(NULL));
    
    for(int i = 0; i<pointsize; i++)
    {
        const double eps = 0.25;
        double rng1 = 0;
        double rng2 = 360;
        double phi = (rng2-rng1) * (drand48()) + rng1;
        double theta = (rng2-rng1) * (drand48()) + rng1;
        double myradius = ((drand48()*eps)+1.0-eps) * radius;
                
        v[i][0] = myradius*sin(phi) * cos(theta);
        v[i][1] = myradius*sin(phi) * sin(theta);
        v[i][2] = myradius*cos(phi);
        
        printf("P[0]: %f, P[1]: %f, P[2]: %f\n", v[i][0], v[i][1], v[i][2]);
    }
    free(tr);
    tr = hull((double *)v, pointsize, &pointlength);
    int counter = 0;

    for(TRI *t = tr, *e = t + pointlength; t < e; t ++){counter++;}
    printf("# vtk DataFile Version 4.0\nvtk output\nASCII\nDATASET UNSTRUCTURED_GRID\nPOINTS %i float\n", counter*3);
    
    for(TRI *t = tr, *e = t + pointlength; t < e; t ++)
    {
      double p[3];
      //p[3] = *t->out;
      p[0] = t->ver [0][0];
      p[1] = t->ver [0][1];
      p[2] = t->ver [0][2];
      printf("%f %f %f\n",p[0], p[1], p[2]);
      p[0] = t->ver [1][0];
      p[1] = t->ver [1][1];
      p[2] = t->ver [1][2];
      printf("%f %f %f\n",p[0], p[1], p[2]);
      p[0] = t->ver [2][0];
      p[1] = t->ver [2][1];
      p[2] = t->ver [2][2];
      printf("%f %f %f\n",p[0], p[1], p[2]);
    }
    printf("CELLS %i %i\n", pointlength, pointlength*4);
    counter=0;
    for(int i=0; i < pointlength; i++)
    {
      printf("3 %i %i %i\n", counter, counter+1, counter+2);
      counter = counter + 3;
    }
    printf("CELL_TYPES %i\n", pointlength);
    for(int i=0; i < pointlength; i++)
    {
      printf("5\n");
    }

    printf("Pointlength: %i", pointlength);
    
    //printf("hello\n");
    return 0;
}
