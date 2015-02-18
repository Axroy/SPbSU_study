#include <stdio.h>


char graphNodesNumeration(int **graph, int arcs, int nodes, int currentNode, bool *visitedNodes, char letter)
{
    visitedNodes[currentNode] = true;
    for (int i = 0; i < arcs; i++)
    {
        if (graph[currentNode][i] == 1)
            for (int j = currentNode; j < nodes; j++)
                if (graph[j][i] == -1 && visitedNodes[j] == false)
                    letter = graphNodesNumeration(graph, arcs, nodes, j, visitedNodes, letter);
        if (graph[currentNode][i] == -1)
            for (int j = currentNode; j >= 0; j--)
                if (graph[j][i] == 1 && visitedNodes[j] == false)
                    letter = graphNodesNumeration(graph, arcs, nodes, j, visitedNodes, letter);
    }

    printf("%c - Node %d\n", letter, currentNode);
    letter++;

    return letter;
}

int main()
{
    printf("Программа нумерует вершины ориентированного графа в произвольном порядке латинскими буквами\n");
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

    printf("Введите стартовую вершину: ");
    int startingNode = 0;
    scanf("%d", &startingNode);

    bool *visitedNodes = new bool[nodes];
    for (int i = 0; i < nodes; i++)
        visitedNodes[i] = false;

    graphNodesNumeration(graph, arcs, nodes, startingNode, visitedNodes, 'A');

    for (int i = 0; i < arcs; i++)
        delete[] graph[i];
    delete[] graph;
    delete[] visitedNodes;

    return 0;
}

