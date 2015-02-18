#include <stdio.h>

void depthFirstTraverse(int **graph, int arcs, int nodes, int currentNode, bool *visitedNodes)
{
    for (int i = 0; i < arcs; i++)
        if (graph[currentNode][i] == 1)
            for (int j = currentNode + 1; j < nodes; j++)
                if (graph[j][i] == 1 && visitedNodes[j] == false)
                {
                    depthFirstTraverse(graph, arcs, nodes, j, visitedNodes);
                }

    visitedNodes[currentNode] = true;
    printf("%d", currentNode);

    return;
}

void components(int **graph, int arcs, int nodes, bool *visitedNodes)
{
    int numberOfComponent = 1;
    for (int i = 0; i < nodes; i++)
        if (visitedNodes[i] == false)
        {
            printf("%d) ", numberOfComponent);
            numberOfComponent++;
            depthFirstTraverse(graph, arcs, nodes, i, visitedNodes);
            printf("\n");
        }
}

int main()
{
    printf("Программа находит компоненты связности в неориентированном графе\n");
    const int size = 1000;

    char fileName[size] = "";
    printf("Введите имя файла, содержащего граф:\n");
    scanf("%s", &fileName);

    FILE *file = fopen(fileName, "r");
    if (file == nullptr)
    {
        printf("Файл не найден!");
        return 0;
    }

    int nodes = 0;
    int arcs = 0;

    fscanf(file, "%d", &arcs);
    fscanf(file, "%d", &nodes);

    int **graph = new int *[arcs];
    for (int i = 0; i < arcs; i++)
        graph[i] = new int[nodes];

    for (int i = 0; i < nodes; i++)
        for (int j = 0; j < arcs; j++)
            fscanf(file, "%d", &graph[i][j]);

    fclose(file);

    bool *visitedNodes = new bool[nodes];
    for (int i = 0; i < nodes; i++)
        visitedNodes[i] = false;

    components(graph, arcs, nodes, visitedNodes);

    for (int i = 0; i < arcs; i++)
        delete[] graph[i];
    delete[] graph;
    delete[] visitedNodes;

    return 0;
}

