#include "dijkstra.h"

int dijkstra(Graph *graph, int start_ID, int end_ID) {
    /*
    tworzy pq
    wsadza początkowy node do pq

    pętla:
    1. dodaje sąsiednie node'y do pq
    1.1 jak weight = -1 to nie ma więcej node'ów
    2. pop i dodaje do 
    
    
    
    */
    PriorityQueue *pq = createQueue();
    PQNode node = createPQNode(start_ID, 0);
    insert(pq, &node);

    PQNode currentNode, nextNode;

    unsigned int max_len = 0xffffffff;
    int currentID;

    while(!is_empty(pq)) {
        currentNode = pop(pq);  
                    
        if (graph->node_list[currentNode.ID]->visited == 1) {
            continue;
        } 
        for (int i = 0; i < 4 && graph->node_list[currentNode.ID]->weight[i] > 0; i++) {

            graph->node_list[currentNode.ID]->visited = 1;
            if(graph->node_list[currentNode.ID]->ID == end_ID) {
                printf("KONIEC: %d", currentNode.len);
                return 0;
            }

            nextNode = createPQNode(graph->node_list[currentNode.ID]->connections[i],
                        graph->node_list[currentNode.ID]->weight[i] + currentNode.len);

            printf("%d %d   ->   %d %d\n", currentNode.ID, currentNode.len,
                graph->node_list[currentNode.ID]->connections[i], graph->node_list[currentNode.ID]->weight[i]);

            insert(pq, &nextNode);
        }
        
    }
    free(pq->array);
    free(pq);

    return 0;

}