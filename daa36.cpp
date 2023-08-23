#include <stdio.h>
#include <stdlib.h>

#define MAX_CONTAINERS 100
#define MAX_ITEMS 100

typedef struct {
    int width;
    int height;
} Container;

typedef struct {
    int width;
    int height;
} Item;

void packItems(Container containers[], int numContainers, Item items[], int numItems) {
    int containerIndex = 0;
    
    for (int i = 0; i < numItems; i++) {
        if (containerIndex >= numContainers) {
            printf("Not enough containers to pack all items.\n");
            break;
        }
        
        if (containers[containerIndex].width >= items[i].width && containers[containerIndex].height >= items[i].height) {
            printf("Packing Item %d into Container %d\n", i + 1, containerIndex + 1);
            containers[containerIndex].width -= items[i].width;
            containers[containerIndex].height -= items[i].height;
        } else {
            containerIndex++;
            i--; // Try packing the current item into the next container
        }
    }
}

int main() {
    Container containers[MAX_CONTAINERS];
    Item items[MAX_ITEMS];
    int numContainers, numItems;

    printf("Enter the number of containers: ");
    scanf("%d", &numContainers);

    printf("Enter the dimensions of each container (width height):\n");
    for (int i = 0; i < numContainers; i++) {
        scanf("%d %d", &containers[i].width, &containers[i].height);
    }

    printf("Enter the number of items: ");
    scanf("%d", &numItems);

    printf("Enter the dimensions of each item (width height):\n");
    for (int i = 0; i < numItems; i++) {
        scanf("%d %d", &items[i].width, &items[i].height);
    }

    packItems(containers, numContainers, items, numItems);

    return 0;
}

