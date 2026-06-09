#include <stdio.h>
#include "objects.h"
#include "graphics.h"

Shape shapes[MAX_OBJECTS];
int shapeCount=0;

void redrawAllShapes()
{
    int i;

    clearCanvas();

    for(i=0;i<shapeCount;i++)
    {
        if(shapes[i].active)
        {
            switch(shapes[i].type)
            {
                case LINE:
                    drawLine(
                        shapes[i].x1,
                        shapes[i].y1,
                        shapes[i].x2,
                        shapes[i].y2
                    );
                    break;

                case RECTANGLE:
                    drawRectangle(
                        shapes[i].x1,
                        shapes[i].y1,
                        shapes[i].width,
                        shapes[i].height
                    );
                    break;

                case TRIANGLE:
                    drawTriangle(
                        shapes[i].x1,
                        shapes[i].y1,
                        shapes[i].x2,
                        shapes[i].y2,
                        shapes[i].x3,
                        shapes[i].y3
                    );
                    break;

                case CIRCLE:
                    drawCircle(
                        shapes[i].x1,
                        shapes[i].y1,
                        shapes[i].radius
                    );
                    break;
            }
        }
    }
}

void addShape()
{
    Shape s;

    printf("\n1. Line\n");
    printf("2. Rectangle\n");
    printf("3. Triangle\n");
    printf("4. Circle\n");

    printf("Enter shape type: ");
    scanf("%d",(int *)&s.type);

    s.id=shapeCount+1;
    s.active=1;

    switch(s.type)
    {
        case LINE:
            printf("Enter x1 y1 x2 y2: ");
            scanf("%d%d%d%d",
                  &s.x1,&s.y1,
                  &s.x2,&s.y2);
            break;

        case RECTANGLE:
            printf("Enter x y width height: ");
            scanf("%d%d%d%d",
                  &s.x1,&s.y1,
                  &s.width,&s.height);
            break;

        case TRIANGLE:
            printf("Enter x1 y1 x2 y2 x3 y3: ");
            scanf("%d%d%d%d%d%d",
                  &s.x1,&s.y1,
                  &s.x2,&s.y2,
                  &s.x3,&s.y3);
            break;

        case CIRCLE:
            printf("Enter centerX centerY radius: ");
            scanf("%d%d%d",
                  &s.x1,&s.y1,
                  &s.radius);
            break;

        default:
            printf("Invalid shape\n");
            return;
    }

    shapes[shapeCount++]=s;

    printf("Shape added. ID=%d\n",s.id);
}

void deleteShape(int id)
{
    int i;

    for(i=0;i<shapeCount;i++)
    {
        if(shapes[i].id==id)
        {
            shapes[i].active=0;
            printf("Shape deleted\n");
            return;
        }
    }

    printf("Shape not found\n");
}

void modifyShape(int id)
{
    int i;

    for(i=0;i<shapeCount;i++)
    {
        if(shapes[i].id==id && shapes[i].active)
        {
            switch(shapes[i].type)
            {
                case LINE:
                    printf("New x1 y1 x2 y2: ");
                    scanf("%d%d%d%d",
                          &shapes[i].x1,
                          &shapes[i].y1,
                          &shapes[i].x2,
                          &shapes[i].y2);
                    break;

                case RECTANGLE:
                    printf("New x y width height: ");
                    scanf("%d%d%d%d",
                          &shapes[i].x1,
                          &shapes[i].y1,
                          &shapes[i].width,
                          &shapes[i].height);
                    break;

                case TRIANGLE:
                    printf("New x1 y1 x2 y2 x3 y3: ");
                    scanf("%d%d%d%d%d%d",
                          &shapes[i].x1,
                          &shapes[i].y1,
                          &shapes[i].x2,
                          &shapes[i].y2,
                          &shapes[i].x3,
                          &shapes[i].y3);
                    break;

                case CIRCLE:
                    printf("New centerX centerY radius: ");
                    scanf("%d%d%d",
                          &shapes[i].x1,
                          &shapes[i].y1,
                          &shapes[i].radius);
                    break;
            }

            printf("Shape modified\n");
            return;
        }
    }

    printf("Shape not found\n");
}