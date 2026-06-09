#ifndef OBJECTS_H
#define OBJECTS_H

#define MAX_OBJECTS 100

typedef enum
{
    LINE=1,
    RECTANGLE,
    TRIANGLE,
    CIRCLE
} ShapeType;

typedef struct
{
    int id;
    int active;

    ShapeType type;

    int x1,y1;
    int x2,y2;
    int x3,y3;

    int width;
    int height;

    int radius;

} Shape;

void addShape();
void deleteShape(int id);
void modifyShape(int id);
void redrawAllShapes();

#endif