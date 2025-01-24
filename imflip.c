#include <stdlib.h>
#include <stdio.h>
#include "cbmp.h"
#include <time.h>

#define REPS 129

BMP* FlipImageV(BMP* bmp)
{
   int width = get_width(bmp);
   int height = get_height(bmp);

   bmpN = b_deep_copy(bmp);
   
   for (x = 0; x < width; x++)
   {
      for (y = 0; y < height; y++)
      {
         get_pixel_rgb(bmp, x, y, &r, &g, &b);
         set_pixel_rgb(bmpN, x, y, 255 - r, 255 - g, 255 - b);
        }
    }
    return bmpN;
}

int main(int argc, char** argv) 
{
  double timer; unsigned int a; clock_t start,stop; 
  if(argc != 4){ 
    printf("\n\nUsage: imflip [input][output][h/v]"); 
    printf("\n\nExample: imflip square.bmp square_h.bmp h\n\n"); 
    return 0; 
  }

  BMP* data = bopen(argv[1]);

  width = get_width(bmp);

    // Gets image height in pixels
  height = get_height(bmp);

   start = clock(); 
   switch (argv[3][0]){ 
     case 'v' :
     case 'V' : for(a=0; a<REPS; a++) data = FlipImageV(data); break;
//     case 'h' :
//     case 'H' : for(a=0; a<REPS; a++) data = FlipImageH(data); break;
     default : printf("\nINVALID OPTION\n"); return 0;

    } 
    stop = clock(); 
    timer = 1000*((double)(stop-start))/(double)CLOCKS_PER_SEC/(double)REPS; 
    //merge with header and write to file 
    bwrite(data, argv[2]); // free() the allocated memory for the image
    bclose(bmp);
    for(int i = 0; i < ip.Vpixels; i++) { free(data[i]); }
    free(data); 
    printf("\n\nTotal execution time: %9.4f ms",timer); 
    printf(" (%7.3f ns/pixel)\n", 1000000*timer/(double)(ip.Hpixels*ip.Vpixels));
}


