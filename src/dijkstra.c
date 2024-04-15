#include "dijkstra.h"

int dijkstra(FILE *in, FILE*out, int start_ID, int end_ID, int node_count) {

    fprintf(stderr, "Creating Position List...\t");
    Position *pos = createPositionList(in, node_count);
    fprintf(stderr, "Done!\n");

    PriorityQueue *pq = createQueue();
    PQNode node = {end_ID, 0};
    insert(pq, &node);

    PQNode currentNode, nextNode;

    int newID, newLen;

    int previous[node_count]; //array of previous ids
    for (int i = 0; i < node_count; i++) {
        previous[i] = -1;
    }
    Node graphNode;
    int links[4];
    short weights[4];


    while(!is_empty(pq)) {

        currentNode = pop(pq);

        if (previous[currentNode.ID] > 0) {
            continue;
        }

        previous[currentNode.ID] = currentNode.previousID;

        if (currentNode.ID == start_ID) {
            break;
        }
        
        get_node(in, links, weights, currentNode.ID, node_count);
        graphNode = createNode(currentNode.ID, links, weights);

        for (int i = 0; i < 4 && graphNode.weight[i] > 0; i++) {
            newID = graphNode.connections[i];
            newLen = graphNode.weight[i] + currentNode.len;

            nextNode.ID = newID;
            nextNode.len = newLen;
            nextNode.previousID = currentNode.ID;
            insert(pq, &nextNode);
        }
        
    }
    fprintf(out, "Length: %d\n", currentNode.len);
    fprintf(stderr, "Saving path...\n");
    printPath(pos, previous, out, start_ID, end_ID);
    fprintf(stderr, "Path saved!\n");
    //printf("PQ final size: %hd\n", pq->size);

    free(pq->array);
    free(pq);
    free(pos);

    return 0;

}