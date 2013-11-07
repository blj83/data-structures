//
//  DataGenerator.c
//  
//
//  Created by Benjamin Johnson on 4/17/12.
//  Copyright 2012 University of Georgia. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char **argv){
    
    if (argc != 2){
        printf("Please enter number of elementsto be generated\n");
        return -1;
    }
    
    int amount;
    amount = atoi(argv[1]);
    
    FILE *f1, *f2, *f3, *f4, *f5, *f6, *f7, *f8, *f9, *f10, *f11, *f12, *f13, *f14, *f15, *f16, *f17, *f18, *f19, *f20;
    
    f1 = fopen("num1.txt","w");
    f2 = fopen("num2.txt","w");
    f3 = fopen("num3.txt","w");
    f4 = fopen("num4.txt","w");
    f5 = fopen("num5.txt","w");
    f6 = fopen("num6.txt","w");
    f7 = fopen("num7.txt","w");
    f8 = fopen("num8.txt","w");
    f9 = fopen("num9.txt","w");
    f10 = fopen("num10.txt","w");
    f11 = fopen("num11.txt","w");
    f12 = fopen("num12.txt","w");
    f13 = fopen("num13.txt","w");
    f14 = fopen("num14.txt","w");
    f15 = fopen("num15.txt","w");
    f16 = fopen("num16.txt","w");
    f17 = fopen("num17.txt","w");
    f18 = fopen("num18.txt","w");
    f19 = fopen("num19.txt","w");
    f20 = fopen("num20.txt","w");
    
    int i;
    srand(time(NULL));
    for (i=0; i < amount; i++){
        fprintf(f1, "%d ", (rand() % 1000000 + 1));
        fprintf(f2, "%d ", (rand() % 1000000 + 1));
        fprintf(f3, "%d ", (rand() % 1000000 + 1));
        fprintf(f4, "%d ", (rand() % 1000000 + 1));
        fprintf(f5, "%d ", (rand() % 1000000 + 1));
        fprintf(f6, "%d ", (rand() % 1000000 + 1));
        fprintf(f7, "%d ", (rand() % 1000000 + 1));
        fprintf(f8, "%d ", (rand() % 1000000 + 1));
        fprintf(f9, "%d ", (rand() % 1000000 + 1));
        fprintf(f10, "%d ", (rand() % 1000000 + 1));
        fprintf(f11, "%d ", (rand() % 1000000 + 1));
        fprintf(f12, "%d ", (rand() % 1000000 + 1));
        fprintf(f13, "%d ", (rand() % 1000000 + 1));
        fprintf(f14, "%d ", (rand() % 1000000 + 1));
        fprintf(f15, "%d ", (rand() % 1000000 + 1));
        fprintf(f16, "%d ", (rand() % 1000000 + 1));
        fprintf(f17, "%d ", (rand() % 1000000 + 1));
        fprintf(f18, "%d ", (rand() % 1000000 + 1));
        fprintf(f19, "%d ", (rand() % 1000000 + 1));
        fprintf(f20, "%d ", (rand() % 1000000 + 1));
    }
    
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    fclose(f5);
    fclose(f6);
    fclose(f7);
    fclose(f8);
    fclose(f9);
    fclose(f10);
    fclose(f11);
    fclose(f12);
    fclose(f13);
    fclose(f14);
    fclose(f15);
    fclose(f16);
    fclose(f17);
    fclose(f18);
    fclose(f19);
    fclose(f20);
    
    return 0;
}