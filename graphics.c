#include <stdio.h>
#include <stdlib.h>
#include "graphics.h"

char canvas[HEIGHT][WIDTH];

void clearCanvas()
{
    int i,j;

    for(i=0;i<HEIGHT;i++)
    {
        for(j=0;j<WIDTH;j++)
        {
            canvas[i][j]='_';
        }
    }
}

void displayCanvas()
{
    int i,j;

    for(i=0;i<HEIGHT;i++)
    {
        for(j=0;j<WIDTH;j++)
        {
            printf("%c",canvas[i][j]);
        }
        printf("\n");
    }
}

void putPixel(int x,int y,char ch)
{
    if(x>=0 && x<WIDTH && y>=0 && y<HEIGHT)
    {
        canvas[y][x]=ch;
    }
}

void drawLine(int x1,int y1,int x2,int y2)
{
    int dx=abs(x2-x1);
    int dy=abs(y2-y1);

    int sx=(x1<x2)?1:-1;
    int sy=(y1<y2)?1:-1;

    int err=dx-dy;

    while(1)
    {
        putPixel(x1,y1,'*');

        if(x1==x2 && y1==y2)
            break;

        int e2=2*err;

        if(e2>-dy)
        {
            err-=dy;
            x1+=sx;
        }

        if(e2<dx)
        {
            err+=dx;
            y1+=sy;
        }
    }
}

void drawRectangle(int x,int y,int width,int height)
{
    int i;

    for(i=x;i<x+width;i++)
    {
        putPixel(i,y,'*');
        putPixel(i,y+height-1,'*');
    }

    for(i=y;i<y+height;i++)
    {
        putPixel(x,i,'*');
        putPixel(x+width-1,i,'*');
    }
}

void drawTriangle(int x1,int y1,
                  int x2,int y2,
                  int x3,int y3)
{
    drawLine(x1,y1,x2,y2);
    drawLine(x2,y2,x3,y3);
    drawLine(x3,y3,x1,y1);
}

void drawCircle(int xc,int yc,int r)
{
    int x=0;
    int y=r;
    int d=3-2*r;

    while(x<=y)
    {
        putPixel(xc+x,yc+y,'*');
        putPixel(xc-x,yc+y,'*');
        putPixel(xc+x,yc-y,'*');
        putPixel(xc-x,yc-y,'*');

        putPixel(xc+y,yc+x,'*');
        putPixel(xc-y,yc+x,'*');
        putPixel(xc+y,yc-x,'*');
        putPixel(xc-y,yc-x,'*');

        if(d<0)
        {
            d=d+4*x+6;
        }
        else
        {
            d=d+4*(x-y)+10;
            y--;
        }

        x++;
    }
}