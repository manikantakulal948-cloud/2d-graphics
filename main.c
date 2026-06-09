#include <stdio.h>
#include "graphics.h"
#include "objects.h"

int main()
{
    int choice;
    int id;

    clearCanvas();

    while(1)
    {
        printf("\n===== 2D GRAPHICS EDITOR =====\n");
        printf("1. Add Shape\n");
        printf("2. Delete Shape\n");
        printf("3. Modify Shape\n");
        printf("4. Display Picture\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                addShape();
                redrawAllShapes();
                break;

            case 2:
                printf("Enter Shape ID: ");
                scanf("%d",&id);
                deleteShape(id);
                redrawAllShapes();
                break;

            case 3:
                printf("Enter Shape ID: ");
                scanf("%d",&id);
                modifyShape(id);
                redrawAllShapes();
                break;

            case 4:
                displayCanvas();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}