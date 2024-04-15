#include "dijkstra.h"

int dijkstra(Graph *graph, int start_ID, int end_ID, FILE *out, Position* pos) {

    PriorityQueue *pq = createQueue();
    PQNode node = {end_ID, 0};
    insert(pq, &node);

    PQNode currentNode, nextNode;

    int newID, newLen;

    int previous[graph->node_count]; //array of previous ids
    for (int i = 0; i < graph->node_count; i++) {
        previous[i] = -1;
    }


    while(!is_empty(pq)) {

        currentNode = pop(pq);

        if (previous[currentNode.ID] > 0) {
            continue;
        }

        previous[currentNode.ID] = currentNode.previousID;

        if (currentNode.ID == start_ID) {
            break;
        }

        for (int i = 0; i < 4 && graph->node_list[currentNode.ID]->weight[i] > 0; i++) {
            newID = graph->node_list[currentNode.ID]->connections[i];
            newLen = graph->node_list[currentNode.ID]->weight[i] + currentNode.len;

            nextNode.ID = newID;
            nextNode.len = newLen;
            nextNode.previousID = currentNode.ID;
            insert(pq, &nextNode);
        }
        
    }
    fprintf(out, "Length: %d\n", currentNode.len);
    printPath(pos, previous, out, start_ID, end_ID);
    printf("PQ final size: %hd\n", pq->size);

    free(pq->array);
    free(pq);

    return 0;

}