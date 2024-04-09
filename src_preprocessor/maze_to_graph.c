#include "maze_to_graph.h"
#include <stdio.h>

void place_node(char **board, int i, int j) {
    board[i][j] = 'N';

}

int placer(char **board, int height, int width) {
    int OX;
    int OY;
    int placed = 0;
    for (int i = 0; i < height; i++) {
        
        for (int j = 0; j < width; j++) {
            OX = 0;
            OY = 0;
            if (board[i][j] == ' ') {
                if (board[i][j+1] == ' ' || board[i][j+1] == 'N' || board[i][j+1] == 'P' || board[i][j+1] == 'K') OX++;
                if (board[i][j-1] == ' ' || board[i][j-1] == 'N' || board[i][j-1] == 'P' || board[i][j-1] == 'K') OX++;
                if (board[i+1][j] == ' ' || board[i+1][j] == 'N' || board[i+1][j] == 'P' || board[i+1][j] == 'K') OY++;
                if (board[i-1][j] == ' ' || board[i-1][j] == 'N' || board[i-1][j] == 'P' || board[i-1][j] == 'K') OY++;
            } else if (board[i][j] == 'K' || board[i][j] == 'P') {
                OX++; OY++;
            }
            if (OX >= 1 && OY >= 1) {
                place_node(board, i, j);
                placed++;
            }
        }
    }
    return placed;
}

void connecter(char **board, int **ID, int height, int width, int placed, FILE *out) {
    //for each node check up, right, left, down
    // if wall met before N, end this direction with nothing
    // if P or K, also connect them
    // also save the distance between them (if they are adjacent then distance is 1 not 0)
    int udlf;
    int link_count = 0;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (board[i][j] == 'N') {
                fprintf(out, "%d (%d %d):", ID[i][j], i, j);
                udlf = check_direction(board, UP, height, width, j, i);
                if (udlf > 0){ 
                    fprintf(out, " [%d %d]", ID[i-udlf][j], udlf); 
                    link_count++;
                }
                udlf = check_direction(board, DOWN, height, width, j, i);
                if (udlf > 0) {
                    fprintf(out, " [%d %d]", ID[i+udlf][j], udlf); 
                    link_count++;
                }
                udlf = check_direction(board, LEFT, height, width, j, i);
                if (udlf > 0) { 
                    fprintf(out, " [%d %d]", ID[i][j-udlf], udlf); 
                    link_count++;
                }
                udlf = check_direction(board, RIGHT, height, width, j, i);
                if (udlf > 0) {
                    fprintf(out, " [%d %d]", ID[i][j+udlf], udlf); 
                    link_count++;
                }
                
                for (int l = 0; l < 4-link_count; l++) {    //max 4 links, substract existing links
                    fprintf(out, " [-1 -1]");
                }
                link_count = 0;

                fprintf(out, "\n");
            }

        }
    }

}

int check_direction(char **board, enum Direction dir, int height, int width, int x, int y) {
    int steps = 1;

    switch(dir) {
        case UP:
            y--;
            if (y < 0)
                return 0;
            while(y >= 0) {
                if (board[y][x] == 'X')
                    return 0;
                if (board[y][x] == 'N')
                    return steps;
            
                steps++;
                y--;
            }
            break;
        case DOWN:
            y++;
            if (y >= height)
                return 0;
            while(y < height) {
                    if (board[y][x] == 'X')
                        return 0;
                    if (board[y][x] == 'N')
                        return steps;
                    steps++;
                    y++;
            }
            break;
        case RIGHT:
            x++;
            if (x >= width)
                return 0;
            while(x < width) {
                    if (board[y][x] == 'X')
                        return 0;
                    if (board[y][x] == 'N')
                        return steps;
                    steps++;
                    x++;
            }
            break;
        case LEFT:
            x--;
            if (x < 0) {
                return 0;
            }
            while(x >= 0) {
                if (board[y][x] == 'X')
                        return 0;
                if (board[y][x] == 'N')
                    return steps;
                steps++;
                x--;
            }
            break;
        default:
            break;
    }
    return 0;
}

void ID_fill(char **board, int **ID, int height, int width) {
    int number = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (board[i][j] == 'N') {
                ID[i][j] = number;
                number++;
            }else
                ID[i][j] = -1;
        }
    }
}