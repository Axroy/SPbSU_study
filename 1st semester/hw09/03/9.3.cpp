#include <stdio.h>
#include <limits.h>


int findMin(int shortestDistance[], bool seen[], int nodes)
{
    int min = INT_MAX;
    int minNode = 0;
    for (int i = 0; i < nodes; i++)
        if (!seen[i] && shortestDistance[i] < min)
        {
            min = shortestDistance[i];
            minNode = i;
        }

    return minNode;
}

int main()
{
    printf("The program builds the minimum spanning tree (MST) of given graph.\n");
    const int length = 1000;
    char fileName[length] = "";
    printf("Enter the name of file with graph: ");
    scanf("%s", &fileName);

    FILE *file = fopen(fileName, "r");
    if (file == nullptr)
    {
        printf("File not found!");
        return 0;
    }

    int size = 0;
    fscanf(file, "%d", &size);

    int **graph = new int *[size];
    for (int i = 0; i < size; i++)
        graph[i] = new int[size];

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
        {
            fscanf(file, "%d", &graph[i][j]);
            if (graph[i][j] == 0)
                graph[i][j] = INT_MAX;
        }

    fclose(file);

    int *shortestDistance = new int[size];
    for (int i = 1; i < size; i++)
        shortestDistance[i] = INT_MAX;
    shortestDistance[0] = 0;

    int *previous = new int[size];
    for (int i = 0; i < size; i++)
        previous[i] = 0;

    bool *seen = new bool[size];
    for (int i = 0; i < size; i++)
        seen[i] = false;

    printf("\nArcs in MST:\n");
    for (int i = 0; i < size; i++)
    {
        int current = findMin(shortestDistance, seen, size);
        seen[current] = true;

        for (int k = 0; k < size; k++)
            if (!seen[k])
                if ((graph[current][k] < INT_MAX) && (shortestDistance[k] > graph[current][k]))
                {
                    shortestDistance[k] = graph[current][k];
                    previous[k] = current;
                }

        if (current != 0)
            printf("%c - %c\n", previous[current] + 'A', current + 'A');
    }


    for (int i = 0; i < size; i++)
        delete[] graph[i];
    delete[] graph;

    delete[] shortestDistance;
    delete[] seen;
    delete[] previous;

    return 0;
}

