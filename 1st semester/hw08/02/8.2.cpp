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
    printf("Программа решает задачу про захват городов (алгоритм Дейкстры)\n");
    const int size = 1000;
    const int maxDistance = INT_MAX;

    char fileName[size] = "";
    printf("Введите имя файла, содержащего условия:\n");
    scanf("%s", &fileName);

    FILE *file = fopen(fileName, "r");
    if (file == nullptr)
    {
        printf("Файл не найден!");
        return 0;
    }

    int nodes = 0;
    int arcs = 0;

    fscanf(file, "%d", &nodes);
    fscanf(file, "%d", &arcs);

    int **graph = new int *[nodes];
    for (int i = 0; i < nodes; i++)
        graph[i] = new int[nodes];

    for (int i = 0; i < nodes; i++)
        for (int j = 0; j < nodes; j++)
            graph[i][j] = maxDistance;

    int i = 0;
    int j = 0;
    for (int k = 0; k < arcs; k++)
    {
        fscanf(file, "%d", &i);
        fscanf(file, "%d", &j);
        i--;
        j--;
        fscanf(file, "%d", &graph[i][j]);
        graph[j][i] = graph[i][j];
    }

    fclose(file);


    bool *seen = new bool[nodes];
    for (int i = 0; i < nodes; i++)
        seen[i] = false;

    int *shortestDistance = new int[nodes];
    for (int i = 0; i < nodes; i++)
        shortestDistance[i] = maxDistance;
    shortestDistance[0] = 0;

    int **shortestPath = new int*[nodes];
    for (int i = 0; i < nodes; i++)
        shortestPath[i] = new int[nodes];
    for (int i = 0; i < nodes; i++)
        for (int j = 0; j < nodes; j++)
            shortestPath[i][j] = -1;


    printf("\nПорядок захвата городов:\n");
    for (int i = 0; i < nodes; i++)
    {
        int current = findMin(shortestDistance, seen, nodes);
        seen[current] = true;

        int p = 0;
        while (shortestPath[current][p] != -1)
            p++;
        shortestPath[current][p] = current;

        for (int k = 0; k < nodes; k++)
            if (!seen[k])
            {
                if ((graph[current][k] < maxDistance) && (shortestDistance[k] > shortestDistance[current] + graph[current][k]))
                    shortestDistance[k] = shortestDistance[current] + graph[current][k];

                int p = 0;
                while (shortestPath[k][p] != -1)
                    p++;
                shortestPath[k][p] = current;
            }
        printf("%d ", current + 1);
    }

    printf("\n\nКратчайшие расстояния до городов:\n");
    for (int i = 1; i < nodes; i++)
        printf("%d: %d\n", i + 1, shortestDistance[i]);

    printf("\nПути до городов:");
    for (int i = 1; i < nodes; i++)
    {
        printf("\n%d: ", i + 1);
        for (int j = 0; j < nodes; j++)
            if (shortestPath[i][j] != -1)
                printf("%d ", shortestPath[i][j] + 1);
    }

    for (int i = 0; i < nodes; i++)
        delete[] graph[i];
    delete[] graph;

    delete[] seen;
    delete[] shortestDistance;

    for (int i = 0; i < nodes; i++)
        delete[] shortestPath[i];
    delete[] shortestPath;

    return 0;
}

