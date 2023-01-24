#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "check_position.h"
#include "checkmate.h"
#include "stalemate.h"


int main(){
    int chessboard[8][8][3];

    int a = 45, b = 46, c;
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            if(i % 2 == 0){
                c = a; a = b; b = c;
                chessboard[i][j][0] = a;
            }
            else{
                c = a; a = b; b = c;
                chessboard[i][j][0] = b;
            }
        }
    }

    chessboard[0][0][1] = chessboard [0][7][1] = 114; chessboard[0][0][2] = chessboard [0][7][2] = 1;
    chessboard[0][1][1] = chessboard [0][6][1] = 110; chessboard[0][1][2] = chessboard [0][6][2] = 1;
    chessboard[0][2][1] = chessboard [0][5][1] = 98; chessboard[0][2][2] = chessboard [0][5][2] = 1;
    chessboard[0][3][1] = 113; chessboard[0][3][2] = 1;
    chessboard[0][4][1] = 107; chessboard[0][4][2] = 1;

    chessboard[7][0][1] = chessboard [7][7][1] = 82; chessboard[7][0][2] = chessboard [7][7][2] = 2;
    chessboard[7][1][1] = chessboard [7][6][1] = 78; chessboard[7][1][2] = chessboard [7][6][2] = 2;
    chessboard[7][2][1] = chessboard [7][5][1] = 66; chessboard[7][2][2] = chessboard [7][5][2] = 2;
    chessboard[7][3][1] = 81; chessboard[7][3][2] = 2;
    chessboard[7][4][1] = 75; chessboard[7][4][2] = 2;

    for(int i = 0; i < 8; ++i){
        chessboard[1][i][1] = 112;
        chessboard[1][i][2] = 1;
    }
    for(int i = 0; i < 8; ++i){
        chessboard[6][i][1] = 80;
        chessboard[6][i][2] = 2;
    }

    for(int i = 2; i < 6; ++i){
        for(int j = 0; j < 8; ++j){
            chessboard[i][j][1] = chessboard[i][j][2] = 0;
        }
    }

    int i = 0, j = 0;
    int counter_king1 = 0, counter_king2 = 0;
    int flag = 1, flag2 = 0;
    int piece;
    char x, y, z;
    int c1, c2;
    int r1, r2;
    int player1_eaten_pieces[30];
    int player2_eaten_pieces[30];
    int undo_stack[300][8][8][3];
    int redo_stack[300][8][8][3];
    int undostack1_eaten_pieces[300][30];
    int redostack1_eaten_pieces[300][30];
    int undostack2_eaten_pieces[300][30];
    int redostack2_eaten_pieces[300][30];
    int counter1 = 0, counter2 = 0;
    int counter_undo = 0, counter_redo = 0;
    int king1_r = 0, king1_c = 4;
    int king2_r = 7, king2_c = 4;

    memset(player1_eaten_pieces, 0, sizeof player1_eaten_pieces);
    memset(player2_eaten_pieces, 0, sizeof player2_eaten_pieces);

    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            for(int k = 0; k < 3; ++k){
                undo_stack[counter_undo][i][j][k] = chessboard[i][j][k];
            }
        }
    }
    for(int i = 0; i < 30; ++i){
        undostack1_eaten_pieces[counter_undo][i] = player1_eaten_pieces[i];
        undostack2_eaten_pieces[counter_undo][i] = player2_eaten_pieces[i];
    }
    counter_undo++;

    int num;
    FILE * in = fopen("game_data.txt", "r");
    fscanf(in, "%d", &num);
    if(num == 1){
        for(int i = 0; i < 8; ++i){
            for(int j = 0; j < 8; ++j){
                for(int k = 0; k < 3; ++k){
                    fscanf(in, "%d ", &chessboard[i][j][k]);
                }
            }
        }
        fscanf(in, "%d %d %d ", &counter_king1, &counter_king2, &flag);
        for(int i = 0; i < 30; ++i){
            fscanf(in, "%d ", &player1_eaten_pieces[i]);
            fscanf(in, "%d ", &player2_eaten_pieces[i]);
        }
        fscanf(in, "%d %d ", &counter1, &counter2);
        fscanf(in, "%d %d %d %d ", &king1_r, &king1_c, &king2_r, &king2_c);
    }

    FILE * out = fopen("game_data.txt", "w");
    fprintf(out, "%d", 0);
    fclose(out);


    while(1){

        printf("\n\n");
        if(flag == 1) {printf("  Player's 1 turn");}
        if(flag == 2) {printf("  Player's 2 turn");}
        printf("\n\n\n\n\t\t\t\t");
        printf("a    b    c    d    e    f    g    h");
        printf("\n\n\n\t\t\t");
        for(int i = 7; i >= 0; --i){
            printf("%d\t", i+1);
            for(int j = 0; j < 8; ++j){

                if(chessboard[i][j][1] == 0){
                    printf("%c    ", chessboard[i][j][0]);
                }
                else{
                    printf("%c    ", chessboard[i][j][1]);
                }
            }
            printf("  %d\n\n\t\t\t", i+1);
        }
        printf("\n\t\t\t\ta    b    c    d    e    f    g    h\n\n");
        printf("Player's 1 eaten pieces: ");
        for(int i = 0; i < counter1; ++i){
            printf("%c ", player1_eaten_pieces[i]);
        }
        printf("\n\nPlayer's 2 eaten pieces: ");
        for(int i = 0; i < counter2; ++i){
            printf("%c ", player2_eaten_pieces[i]);
        }

        flag2 = 0;
        // Player 1.
        if(flag == 1){
            printf("\n\n");
            x = getchar();
            scanf("%d", &r1);
            y = getchar();
            scanf("%d", &r2);
            z = getchar();

            if(z == '\n'){
                c1 = x - 97;
                if(c1>7 || c1 < 0){system("cls"); printf("Invalid input, try again!\n"); continue;}
                r1 = r1 - 1;
                if(r1>7 || r1 < 0){system("cls");printf("Invalid input, try again!\n"); continue;}
                c2 = y - 97;
                if(c2>7 || c2 < 0){system("cls");printf("Invalid input, try again!\n"); continue;}
                r2 = r2 - 1;
                if(r2>7 || r2 < 0){system("cls");printf("Invalid input, try again!\n"); continue;}

                if(chessboard[r1][c1][1] == 0 || chessboard[r1][c1][2] != 1){
                    system("cls");
                    printf("Invalid play, try again!\n");
                    continue;
                }
                if(chessboard[r2][c2][2] == 1){
                    system("cls");
                    printf("Invalid play, try again!\n");
                    continue;
                }

                // pawn movement.
                if(chessboard[r1][c1][1] == 112){
                    if(r2 == 7){system("cls");printf("Invalid play, try again!"); continue;}
                    if(r2 == r1 + 1 && c2 == c1 && chessboard[r2][c2][1] == 0){
                        chessboard[r2][c2][1] = chessboard[r1][c1][1];
                        chessboard[r2][c2][2] = chessboard[r1][c1][2];
                        chessboard[r1][c1][1] = 0;
                        chessboard[r1][c1][2] = 0;
                        flag = 2;

                    }
                    else if(r2 == 3 && c2 == c1 && chessboard[r2][c2][1] == 0 && chessboard[r1+1][c1][1] == 0){
                        chessboard[r2][c2][1] = chessboard[r1][c1][1];
                        chessboard[r2][c2][2] = chessboard[r1][c1][2];
                        chessboard[r1][c1][1] = 0;
                        chessboard[r1][c1][2] = 0;
                        flag = 2;

                    }
                    else if(((r2 == r1 + 1 && c2 == c1 + 1) || (r2 == r1 + 1 && c2 == c1 - 1)) && chessboard[r2][c2][1] != 0){
                        player2_eaten_pieces[counter2++] = chessboard[r2][c2][1];
                        chessboard[r2][c2][1] = chessboard[r1][c1][1];
                        chessboard[r2][c2][2] = chessboard[r1][c1][2];
                        chessboard[r1][c1][1] = 0;
                        chessboard[r1][c1][2] = 0;
                        flag = 2;

                    }
                    else{system("cls"); printf("Invalid play, try again!"); continue;}

                }
                // king movement.
                else if(chessboard[r1][c1][1] == 107){
                    if((r2-r1==0 || r2-r1==1 || r2-r1==-1) && (c2-c1==0 || c2-c1==1 || c2-c1==-1)){
                        if(chessboard[r2][c2][1] == 0){
                             chessboard[r2][c2][1] = chessboard[r1][c1][1];
                             chessboard[r2][c2][2] = chessboard[r1][c1][2];
                             chessboard[r1][c1][1] = 0;
                             chessboard[r1][c1][2] = 0;
                             king1_r = r2;
                             king1_c = c2;
                             counter_king1++;
                             flag = 2;
                        }
                        else{
                            player2_eaten_pieces[counter2++] = chessboard[r2][c2][1];
                            chessboard[r2][c2][1] = chessboard[r1][c1][1];
                            chessboard[r2][c2][2] = chessboard[r1][c1][2];
                            chessboard[r1][c1][1] = 0;
                            chessboard[r1][c1][2] = 0;
                            king1_r = r2;
                            king1_c = c2;
                            counter_king1++;
                            flag = 2;
                        }
                    }
                    else if(counter_king1 == 0 && r2 == 0 && c2 == 6 &&
                    chessboard[0][5][1]==0 && chessboard[0][6][1]==0 && chessboard[0][7][1]==114){
                            chessboard[r2][c2][1] = chessboard[r1][c1][1];
                            chessboard[r2][c2][2] = chessboard[r1][c1][2];
                            chessboard[r1][c1][1] = 0;
                            chessboard[r1][c1][2] = 0;
                            chessboard[0][5][1] = 114;
                            chessboard[0][5][2] = 1;
                            chessboard[0][7][1] = 0;
                            chessboard[0][7][2] = 0;
                            king1_r = r2;
                            king1_c = c2;
                            counter_king1++;
                            flag = 2;
                    }
                    else if(counter_king1 == 0 && r2 == 0 && c2 == 2 &&
                    chessboard[0][3][1]==0 && chessboard[0][2][1]==0 && chessboard[0][1][1]==0 && chessboard[0][0][1]==114){
                            chessboard[r2][c2][1] = chessboard[r1][c1][1];
                            chessboard[r2][c2][2] = chessboard[r1][c1][2];
                            chessboard[r1][c1][1] = 0;
                            chessboard[r1][c1][2] = 0;
                            chessboard[0][3][1] = 114;
                            chessboard[0][3][2] = 1;
                            chessboard[0][0][1] = 0;
                            chessboard[0][0][2] = 0;
                            king1_r = r2;
                            king1_c = c2;
                            counter_king1++;
                            flag = 2;
                    }
                    else{system("cls"); printf("Invalid play, try again!"); continue;}
                }

                // rook movement.
                if(chessboard[r1][c1][1] == 114){
                    if(r2 > r1 && c1 == c2){
                        for(int i = r1 + 1; i < r2; ++i){
                            if(chessboard[i][c1][1] != 0){
                                system("cls");
                                printf("Invalid play, try again!");
                                flag2 = 1;
                                continue;
                            }
                        }
                        if(flag2 == 1) continue;
                        if(chessboard[r2][c2][1] != 0) player2_eaten_pieces[counter2++] = chessboard[r2][c2][1];
                        chessboard[r2][c2][1] = chessboard[r1][c1][1];
                        chessboard[r2][c2][2] = chessboard[r1][c1][2];
                        chessboard[r1][c1][1] = 0;
                        chessboard[r1][c1][2] = 0;
                        flag = 2;
                    }
                    else if(r2 < r1 && c1 == c2){
                        for(int i = r1 - 1; i > r2; --i){
                            if(chessboard[i][c1][1] != 0){
                                system("cls");
                                printf("Invalid play, try again!");
                                flag2 = 1;
                                continue;
                            }
                        }
                        if(flag2 == 1) continue;
                        if(chessboard[r2][c2][1] != 0) player2_eaten_pieces[counter2++] = chessboard[r2][c2][1];
                        chessboard[r2][c2][1] = chessboard[r1][c1][1];
                        chessboard[r2][c2][2] = chessboard[r1][c1][2];
                        chessboard[r1][c1][1] = 0;
                        chessboard[r1][c1][2] = 0;
                        flag = 2;
                    }
                    else if(c2 > c1 && r1 == r2){
                        for(int i = c1 + 1; i < c2; ++i){
                            if(chessboard[r1][i][1] != 0){
                                system("cls");
                                printf("Invalid play, try again!");
                                flag2 = 1;
                                continue;
                            }
                        }
                        if(flag2 == 1) continue;
                        if(chessboard[r2][c2][1] != 0) player2_eaten_pieces[counter2++] = chessboard[r2][c2][1];
                        chessboard[r2][c2][1] = chessboard[r1][c1][1];
                        chessboard[r2][c2][2] = chessboard[r1][c1][2];
                        chessboard[r1][c1][1] = 0;
                        chessboard[r1][c1][2] = 0;
                        flag = 2;
                    }
                    else if(c2 < c1 && r1 == r2){
                        for(int i = c1 - 1; i > c2; --i){
                            if(chessboard[r1][i][1] != 0){
                                system("cls");
                                printf("Invalid play, try again!");
                                flag2 = 1;
                                continue;
                            }
                        }
                        if(flag2 == 1) continue;
                        if(chessboard[r2][c2][1] != 0) player2_eaten_pieces[counter2++] = chessboard[r2][c2][1];
                        chessboard[r2][c2][1] = chessboard[r1][c1][1];
                        chessboard[r2][c2][2] = chessboard[r1][c1][2];
                        chessboard[r1][c1][1] = 0;
                        chessboard[r1][c1][2] = 0;
                        flag = 2;
                    }
                    else{system("cls"); printf("Invalid play, try again!"); continue;}
                }

                // bishop movement.
                else if(chessboard[r1][c1][1] == 98){
                    if(r2-r1 == c2-c1 || r2-r1 == -(c2-c1)){
                        if(r2 > r1 && c2 > c1){
                            for(i=r1+1 , j=c1+1; i<r2 && j<c2; ++i, ++j){
                                if(chessboard[i][j][1] != 0){
                                system("cls");
                                printf("Invalid play, try again!");
                                flag2 = 1;
                                continue;
                                }
                            }
                        }
                        else if(r2 > r1 && c2 < c1){
                            for(i=r1+1 , j=c1-1; i<r2 && j>c2; ++i, --j){
                                if(chessboard[i][j][1] != 0){
                                system("cls");
                                printf("Invalid play, try again!");
                                flag2 = 1;
                                continue;
                                }
                            }
                        }
                        else if(r2 < r1 && c2 > c1){
                            for(i=r1-1 , j=c1+1; i>r2 && j<c2; --i, ++j){
                                if(chessboard[i][j][1] != 0){
                                system("cls");
                                printf("Invalid play, try again!");
                                flag2 = 1;
                                continue;
                                }
                            }
                        }
                        else if(r2 < r1 && c2 < c1){
                            for(i=r1-1 , j=c1-1; i>r2 && j>c2; --i, --j){
                                if(chessboard[i][j][1] != 0){
                                system("cls");
                                printf("Invalid play, try again!");
                                flag2 = 1;
                                continue;
                                }
                            }
                        }
                        if(flag2 == 1) continue;
                        if(chessboard[r2][c2][1] != 0) player2_eaten_pieces[counter2++] = chessboard[r2][c2][1];
                        chessboard[r2][c2][1] = chessboard[r1][c1][1];
                        chessboard[r2][c2][2] = chessboard[r1][c1][2];
                        chessboard[r1][c1][1] = 0;
                        chessboard[r1][c1][2] = 0;
                        flag = 2;

                    }
                    else{system("cls"); printf("Invalid play, try again!"); continue;}
                }

                // queen movement.
                if(chessboard[r1][c1][1] == 113){
                    if(r2 > r1 && c1 == c2){
                        for(int i = r1 + 1; i < r2; ++i){
                            if(chessboard[i][c1][1] != 0){
                                system("cls");
                                printf("Invalid play, try again!");
                                flag2 = 1;
                                continue;
                            }
                        }
                        if(flag2 == 1) continue;
                        if(chessboard[r2][c2][1] != 0) player2_eaten_pieces[counter2++] = chessboard[r2][c2][1];
                        chessboard[r2][c2][1] = chessboard[r1][c1][1];
                        chessboard[r2][c2][2] = chessboard[r1][c1][2];
                        chessboard[r1][c1][1] = 0;
                        chessboard[r1][c1][2] = 0;
                        flag = 2;
                    }
                    else if(r2 < r1 && c1 == c2){
                        for(int i = r1 - 1; i > r2; --i){
                            if(chessboard[i][c1][1] != 0){
                                system("cls");
                                printf("Invalid play, try again!");
                                flag2 = 1;
                                continue;
                            }
                        }
                        if(flag2 == 1) continue;
                        if(chessboard[r2][c2][1] != 0) player2_eaten_pieces[counter2++] = chessboard[r2][c2][1];
                        chessboard[r2][c2][1] = chessboard[r1][c1][1];
                        chessboard[r2][c2][2] = chessboard[r1][c1][2];
                        chessboard[r1][c1][1] = 0;
                        chessboard[r1][c1][2] = 0;
                        flag = 2;
                    }
                    else if(c2 > c1 && r1 == r2){
                        for(int i = c1 + 1; i < c2; ++i){
                            if(chessboard[r1][i][1] != 0){
                                system("cls");
                                printf("Invalid play, try again!");
                                flag2 = 1;
                                continue;
                            }
                        }
                        if(flag2 == 1) continue;
                        if(chessboard[r2][c2][1] != 0) player2_eaten_pieces[counter2++] = chessboard[r2][c2][1];
                        chessboard[r2][c2][1] = chessboard[r1][c1][1];
                        chessboard[r2][c2][2] = chessboard[r1][c1][2];
                        chessboard[r1][c1][1] = 0;
                        chessboard[r1][c1][2] = 0;
                        flag = 2;
                    }
                    else if(c2 < c1 && r1 == r2){
                        for(int i = c1 - 1; i > c2; --i){
                            if(chessboard[r1][i][1] != 0){
                                system("cls");
                                printf("Invalid play, try again!");
                                flag2 = 1;
                                continue;
                            }
                        }
                        if(flag2 == 1) continue;
                        if(chessboard[r2][c2][1] != 0) player2_eaten_pieces[counter2++] = chessboard[r2][c2][1];
                        chessboard[r2][c2][1] = chessboard[r1][c1][1];
                        chessboard[r2][c2][2] = chessboard[r1][c1][2];
                        chessboard[r1][c1][1] = 0;
                        chessboard[r1][c1][2] = 0;
                        flag = 2;
                    }
                    if(r2-r1 == c2-c1 || r2-r1 == -(c2-c1)){
                        if(r2 > r1 && c2 > c1){
                            for(i=r1+1 , j=c1+1; i<r2 && j<c2; ++i, ++j){
                                if(chessboard[i][j][1] != 0){
                                system("cls");
                                printf("Invalid play, try again!");
                                flag2 = 1;
                                continue;
                                }
                            }
                        }
                        else if(r2 > r1 && c2 < c1){
                            for(i=r1+1 , j=c1-1; i<r2 && j>c2; ++i, --j){
                                if(chessboard[i][j][1] != 0){
                                system("cls");
                                printf("Invalid play, try again!");
                                flag2 = 1;
                                continue;
                                }
                            }
                        }
                        else if(r2 < r1 && c2 > c1){
                            for(i=r1-1 , j=c1+1; i>r2 && j<c2; --i, ++j){
                                if(chessboard[i][j][1] != 0){
                                system("cls");
                                printf("Invalid play, try again!");
                                flag2 = 1;
                                continue;
                                }
                            }
                        }
                        else if(r2 < r1 && c2 < c1){
                            for(i=r1-1 , j=c1-1; i>r2 && j>c2; --i, --j){
                                if(chessboard[i][j][1] != 0){
                                system("cls");
                                printf("Invalid play, try again!");
                                flag2 = 1;
                                continue;
                                }
                            }
                        }
                        if(flag2 == 1) continue;
                        if(chessboard[r2][c2][1] != 0) player2_eaten_pieces[counter2++] = chessboard[r2][c2][1];
                        chessboard[r2][c2][1] = chessboard[r1][c1][1];
                        chessboard[r2][c2][2] = chessboard[r1][c1][2];
                        chessboard[r1][c1][1] = 0;
                        chessboard[r1][c1][2] = 0;
                        flag = 2;

                    }
                }

                // night movement
                if(chessboard[r1][c1][1] == 110){
                    if((r2==r1+1 && c2==c1+2) || (r2==r1+1 && c2==c1-2)
                       || (r2==r1-1 && c2==c1+2) || (r2==r1-1 && c2==c1-2)
                       || (c2==c1+1 && r2==r1+2) || (c2==c1+1 && r2==r1-2)
                       || (c2==c1-1 && r2==r1+2) || (c2==c1-1 && r2==r1-2)){

                        if(chessboard[r2][c2][1] != 0) player2_eaten_pieces[counter2++] = chessboard[r2][c2][1];
                        chessboard[r2][c2][1] = chessboard[r1][c1][1];
                        chessboard[r2][c2][2] = chessboard[r1][c1][2];
                        chessboard[r1][c1][1] = 0;
                        chessboard[r1][c1][2] = 0;
                        flag = 2;
                       }
                    else{system("cls"); printf("Invalid play, try again!"); continue;}
                }

            }
            else if(x == 'u' && y == 'n' && z == 'd'){
                if(getchar() == 'o' && getchar() == '\n'){
                    if(counter_undo != 1){
                        flag = 2;
                        counter_undo = counter_undo - 1;
                        for(int i = 0; i < 8; ++i){
                            for(int j = 0; j < 8; ++j){
                                for(int k = 0; k < 3; ++k){
                                    redo_stack[counter_redo][i][j][k] = undo_stack[counter_undo][i][j][k];
                                }
                            }
                        }
                        if(undostack1_eaten_pieces[counter_undo-1][counter1-1] != undostack1_eaten_pieces[counter_undo][counter1-1]){
                            counter1--;
                        }
                        if(undostack2_eaten_pieces[counter_undo-1][counter2-1] != undostack2_eaten_pieces[counter_undo][counter2-1]){
                            counter2--;
                        }
                        for(int i = 0; i < 30; ++i){
                            redostack1_eaten_pieces[counter_redo][i] = undostack1_eaten_pieces[counter_undo][i];
                            redostack2_eaten_pieces[counter_redo][i] = undostack2_eaten_pieces[counter_undo][i];
                        }
                        counter_redo++;

                        for(int i = 0; i < 8; ++i){
                            for(int j = 0; j < 8; ++j){
                                for(int k = 0; k < 3; ++k){
                                    chessboard[i][j][k] = undo_stack[counter_undo-1][i][j][k];
                                }
                            }
                        }
                        for(int i = 0; i < 30; ++i){
                            player1_eaten_pieces[i] = undostack1_eaten_pieces[counter_undo-1][i];
                            player2_eaten_pieces[i] = undostack2_eaten_pieces[counter_undo-1][i];
                        }
                        system("cls");
                        continue;
                    }
                }
                else{
                    system("cls");
                    printf("Invalid input, try again!\n");
                    continue;
                }

            }
            else if(x == 'r' && y == 'e' && z == 'd'){
                if(getchar() == 'o' && getchar() == '\n'){
                    if(counter_redo == 0) continue;
                    flag = 2;
                    for(int i = 0; i < 8; ++i){
                        for(int j = 0; j < 8; ++j){
                            for(int k = 0; k < 3; ++k){
                                chessboard[i][j][k] = redo_stack[counter_redo - 1][i][j][k];
                                undo_stack[counter_undo][i][j][k] = redo_stack[counter_redo - 1][i][j][k];
                            }
                        }
                    }
                    if(redostack1_eaten_pieces[counter_redo-1][counter1] != undostack1_eaten_pieces[counter_undo-1][counter1]){
                        counter1++;
                    }
                    if(redostack2_eaten_pieces[counter_redo-1][counter2] != undostack2_eaten_pieces[counter_undo-1][counter2]){
                        counter2++;
                    }
                    for(int i = 0; i < 30; ++i){
                        player1_eaten_pieces[i] = redostack1_eaten_pieces[counter_redo-1][i];
                        player2_eaten_pieces[i] = redostack2_eaten_pieces[counter_redo-1][i];

                        undostack1_eaten_pieces[counter_undo][i] = redostack1_eaten_pieces[counter_redo-1][i];
                        undostack2_eaten_pieces[counter_undo][i] = redostack2_eaten_pieces[counter_redo-1][i];
                    }
                    counter_undo++;
                    counter_redo--;
                }
                else{
                    while(getchar() != '\n'){}
                    system("cls");
                    printf("Invalid input, try again!\n");
                    continue;
                }
                system("cls");
                continue;
            }
            else if(x == 's' && y == 'a' && z == 'v'){
                if(getchar() == 'e' && getchar() == '\n'){
                    FILE * game_data = fopen("game_data.txt", "w");
                    fprintf(game_data, "%d ", 1);
                    for(int i = 0; i < 8; ++i){
                        for(int j = 0; j < 8; ++j){
                            for(int k = 0; k < 3; ++k){
                                fprintf(game_data, "%d ", chessboard[i][j][k]);
                            }
                        }
                    }
                    fprintf(game_data, "%d %d %d ", counter_king1, counter_king2, flag);
                    for(int i = 0; i < 30; ++i){
                        fprintf(game_data, "%d ", player1_eaten_pieces[i]);
                        fprintf(game_data, "%d ", player2_eaten_pieces[i]);
                    }
                    fprintf(game_data, "%d %d ", counter1, counter2);
                    fprintf(game_data, "%d %d %d %d ", king1_r, king1_c, king2_r, king2_c);
                    fclose(game_data);
                    break;
                }
                else{
                    while(getchar() != '\n'){}
                    system("cls");
                    printf("Invalid input, try again!\n");
                    continue;
                }
            }

            // promotion
            else{
                if(getchar() == '\n'){
                    c1 = x - 97;
                    if(c1>7 || c1 < 0){system("cls");printf("Invalid input, try again!\n"); continue;}
                    r1 = r1 - 1;
                    if(r1>7 || r1 < 0){system("cls");printf("Invalid input, try again!\n"); continue;}
                    c2 = y - 97;
                    if(c2>7 || c2 < 0){system("cls");printf("Invalid input, try again!\n"); continue;}
                    r2 = r2 - 1;
                    if(r2>7 || r2 < 0){system("cls");printf("Invalid input, try again!\n"); continue;}

                    if(chessboard[r1][c1][1] == 0 || chessboard[r1][c1][2] != 1){
                        system("cls");
                        printf("Invalid play, try again!\n");
                        continue;
                    }
                    if(chessboard[r2][c2][2] == 1){
                        system("cls");
                        printf("Invalid play, try again!\n");
                        continue;
                    }

                    if(chessboard[r1][c1][1] == 112){
                        if(r1 == 6){
                            if(z == 114 || z==110 || z==113 || z==98){
                                if(r2 == r1 + 1 && c2 == c1 && chessboard[r2][c2][1] == 0){
                                    chessboard[r2][c2][1] = chessboard[r1][c1][1];
                                    chessboard[r2][c2][2] = chessboard[r1][c1][2];
                                    chessboard[r1][c1][1] = 0;
                                    chessboard[r1][c1][2] = 0;
                                    flag = 2;
                                    chessboard[r2][c2][1] = z;
                                }
                                else if(((r2 == r1 + 1 && c2 == c1 + 1) || (r2 == r1 + 1 && c2 == c1 - 1)) && chessboard[r2][c2][1] != 0){
                                    player2_eaten_pieces[counter2++] = chessboard[r2][c2][1];
                                    chessboard[r2][c2][1] = chessboard[r1][c1][1];
                                    chessboard[r2][c2][2] = chessboard[r1][c1][2];
                                    chessboard[r1][c1][1] = 0;
                                    chessboard[r1][c1][2] = 0;
                                    flag = 2;
                                    chessboard[r2][c2][1] = z;
                                }
                                else{system("cls"); printf("Invalid play, try again!"); continue;}
                            }
                            else{system("cls"); printf("Invalid play, try again!"); continue;}
                        }
                        else{
                            system("cls");
                            printf("Invalid play, try again!\n");
                            continue;
                        }
                    }
                    else{
                        system("cls");
                        printf("Invalid play, try again!\n");
                        continue;
                    }
                }
                else{
                    while(getchar() != '\n'){}
                    system("cls");
                    printf("Invalid input, try again!\n");
                    continue;
                }
            }
            if(flag == 2){
                if(check_position(chessboard, king1_r, king1_c, 2, 1) == 1){
                    flag = 1;
                    for(int i = 0; i < 8; ++i){
                        for(int j = 0; j < 8; ++j){
                            for(int k = 0; k < 3; ++k){
                                chessboard[i][j][k] = undo_stack[counter_undo-1][i][j][k];
                            }
                        }
                    }
                    if(undostack1_eaten_pieces[counter_undo-1][counter1-1] != player1_eaten_pieces[counter1-1]){
                        counter1--;
                    }
                    if(undostack2_eaten_pieces[counter_undo-1][counter2-1] != player2_eaten_pieces[counter2-1]){
                        counter2--;
                    }
                    for(int i = 0; i < 30; ++i){
                        player1_eaten_pieces[i] = undostack1_eaten_pieces[counter_undo-1][i];
                        player2_eaten_pieces[i] = undostack2_eaten_pieces[counter_undo-1][i];
                    }
                    system("cls");
                    printf("Invalid play, king in check");
                    continue;
                }


                piece = chessboard[r1][c1][1];

                // ---------------------------
                counter_redo = 0;
                for(int i = 0; i < 8; ++i){
                    for(int j = 0; j < 8; ++j){
                        for(int k = 0; k < 3; ++k){
                            undo_stack[counter_undo][i][j][k] = chessboard[i][j][k];
                        }
                    }
                }
                for(int i = 0; i < 30; ++i){
                    undostack1_eaten_pieces[counter_undo][i] = player1_eaten_pieces[i];
                    undostack2_eaten_pieces[counter_undo][i] = player2_eaten_pieces[i];
                }
                counter_undo++;

                if(check_position(chessboard, king2_r, king2_c, 1, 1) == 1){
                    if(checkmate(chessboard, piece, king2_r, king2_c, r2, c2, 2) == 1){
                        printf("\n\nPlayer 1 wins");
                        break;
                    }
                    system("cls");
                    printf("Player 2 in check");
                    continue;
                }
                if(stalemate(chessboard, 2, king2_r, king2_c) == 1){
                    printf("\n\nstalemate");
                    break;
                }
                system("cls");
            }
        }

        // Player 2.
        else if(flag == 2){
            printf("\n\n");
            x = getchar();
            scanf("%d", &r1);
            y = getchar();
            scanf("%d", &r2);
            z = getchar();

            if(z == '\n'){
                c1 = x - 97;
                if(c1>7 || c1 < 0){system("cls");printf("Invalid input, try again!\n"); continue;}
                r1 = r1 - 1;
                if(r1>7 || r1 < 0){system("cls");printf("Invalid input, try again!\n"); continue;}
                c2 = y - 97;
                if(c2>7 || c2 < 0){system("cls");printf("Invalid input, try again!\n"); continue;}
                r2 = r2 - 1;
                if(r2>7 || r2 < 0){system("cls");printf("Invalid input, try again!\n"); continue;}

                if(chessboard[r1][c1][1] == 0 || chessboard[r1][c1][2] != 2){
                    system("cls");
                    printf("Invalid play, try again!\n");
                    continue;
                }
                if(chessboard[r2][c2][2] == 2){
                    system("cls");
                    printf("Invalid play, try again!\n");
                    continue;
                }

                // pawn movement.
                if(chessboard[r1][c1][1] == 80){
                    if(r2 == 0){system("cls");printf("Invalid play, try again!"); continue;}
                    if(r2 == r1 - 1 && c2 == c1 && chessboard[r2][c2][1] == 0){
                        chessboard[r2][c2][1] = chessboard[r1][c1][1];
                        chessboard[r2][c2][2] = chessboard[r1][c1][2];
                        chessboard[r1][c1][1] = 0;
                        chessboard[r1][c1][2] = 0;
                        flag = 1;
                    }
                    else if(r2 == 4 && c2 == c1 && chessboard[r2][c2][1] == 0 && chessboard[r1-1][c1][1] == 0){
                        chessboard[r2][c2][1] = chessboard[r1][c1][1];
                        chessboard[r2][c2][2] = chessboard[r1][c1][2];
                        chessboard[r1][c1][1] = 0;
                        chessboard[r1][c1][2] = 0;
                        flag = 1;
                    }
                    else if(((r2 == r1 - 1 && c2 == c1 + 1) || (r2 == r1 - 1 && c2 == c1 - 1)) && chessboard[r2][c2][1] != 0){
                        player1_eaten_pieces[counter1++] = chessboard[r2][c2][1];
                        chessboard[r2][c2][1] = chessboard[r1][c1][1];
                        chessboard[r2][c2][2] = chessboard[r1][c1][2];
                        chessboard[r1][c1][1] = 0;
                        chessboard[r1][c1][2] = 0;
                        flag = 1;
                    }
                    else{system("cls"); printf("Invalid play, try again!"); continue;}
                }

                // king movement.
                else if(chessboard[r1][c1][1] == 75){
                    if((r2-r1==0 || r2-r1==1 || r2-r1==-1) && (c2-c1==0 || c2-c1==1 || c2-c1==-1)){
                        if(chessboard[r2][c2][1] == 0){
                             chessboard[r2][c2][1] = chessboard[r1][c1][1];
                             chessboard[r2][c2][2] = chessboard[r1][c1][2];
                             chessboard[r1][c1][1] = 0;
                             chessboard[r1][c1][2] = 0;
                             king2_r = r2;
                             king2_c = c2;
                             counter_king2++;
                             flag = 1;
                        }
                        else{
                            player1_eaten_pieces[counter1++] = chessboard[r2][c2][1];
                            chessboard[r2][c2][1] = chessboard[r1][c1][1];
                            chessboard[r2][c2][2] = chessboard[r1][c1][2];
                            chessboard[r1][c1][1] = 0;
                            chessboard[r1][c1][2] = 0;
                            king2_r = r2;
                            king2_c = c2;
                            counter_king2++;
                            flag = 1;
                        }
                    }
                    else if(counter_king2 == 0 && r2 == 7 && c2 == 6 &&
                    chessboard[7][5][1]==0 && chessboard[7][6][1]==0 && chessboard[7][7][1]==82){
                            chessboard[r2][c2][1] = chessboard[r1][c1][1];
                            chessboard[r2][c2][2] = chessboard[r1][c1][2];
                            chessboard[r1][c1][1] = 0;
                            chessboard[r1][c1][2] = 0;
                            chessboard[7][5][1] = 82;
                            chessboard[7][5][2] = 2;
                            chessboard[7][7][1] = 0;
                            chessboard[7][7][2] = 0;
                            king2_r = r2;
                            king2_c = c2;
                            counter_king2++;
                            flag = 1;
                    }
                    else if(counter_king2 == 0 && r2 == 7 && c2 == 2 &&
                    chessboard[7][3][1]==0 && chessboard[7][2][1]==0&& chessboard[7][1][1]==0 && chessboard[7][0][1]==82){
                            chessboard[r2][c2][1] = chessboard[r1][c1][1];
                            chessboard[r2][c2][2] = chessboard[r1][c1][2];
                            chessboard[r1][c1][1] = 0;
                            chessboard[r1][c1][2] = 0;
                            chessboard[7][3][1] = 82;
                            chessboard[7][3][2] = 2;
                            chessboard[7][0][1] = 0;
                            chessboard[7][0][2] = 0;
                            king2_r = r2;
                            king2_c = c2;
                            counter_king2++;
                            flag = 1;
                    }
                    else{system("cls"); printf("Invalid play, try again!"); continue;}
                }

                // rook movement.
                if(chessboard[r1][c1][1] == 82){
                    if(r2 > r1 && c1 == c2){
                        for(int i = r1 + 1; i < r2; ++i){
                            if(chessboard[i][c1][1] != 0){
                                system("cls");
                                printf("Invalid play, try again!");
                                flag2 = 1;
                                continue;
                            }
                        }
                        if(flag2 == 1) continue;
                        if(chessboard[r2][c2][1] != 0) player1_eaten_pieces[counter1++] = chessboard[r2][c2][1];
                        chessboard[r2][c2][1] = chessboard[r1][c1][1];
                        chessboard[r2][c2][2] = chessboard[r1][c1][2];
                        chessboard[r1][c1][1] = 0;
                        chessboard[r1][c1][2] = 0;
                        flag = 1;
                    }
                    else if(r2 < r1 && c1 == c2){
                        for(int i = r1 - 1; i > r2; --i){
                            if(chessboard[i][c1][1] != 0){
                                system("cls");
                                printf("Invalid play, try again!");
                                flag2 = 1;
                                continue;
                            }
                        }
                        if(flag2 == 1) continue;
                        if(chessboard[r2][c2][1] != 0) player1_eaten_pieces[counter1++] = chessboard[r2][c2][1];
                        chessboard[r2][c2][1] = chessboard[r1][c1][1];
                        chessboard[r2][c2][2] = chessboard[r1][c1][2];
                        chessboard[r1][c1][1] = 0;
                        chessboard[r1][c1][2] = 0;
                        flag = 1;
                    }
                    else if(c2 > c1 && r1 == r2){
                        for(int i = c1 + 1; i < c2; ++i){
                            if(chessboard[r1][i][1] != 0){
                                system("cls");
                                printf("Invalid play, try again!");
                                flag2 = 1;
                                continue;
                            }
                        }
                        if(flag2 == 1) continue;
                        if(chessboard[r2][c2][1] != 0) player1_eaten_pieces[counter1++] = chessboard[r2][c2][1];
                        chessboard[r2][c2][1] = chessboard[r1][c1][1];
                        chessboard[r2][c2][2] = chessboard[r1][c1][2];
                        chessboard[r1][c1][1] = 0;
                        chessboard[r1][c1][2] = 0;
                        flag = 1;
                    }
                    else if(c2 < c1 && r1 == r2){
                        for(int i = c1 - 1; i > c2; --i){
                            if(chessboard[r1][i][1] != 0){
                                system("cls");
                                printf("Invalid play, try again!");
                                flag2 = 1;
                                continue;
                            }
                        }
                        if(flag2 == 1) continue;
                        if(chessboard[r2][c2][1] != 0) player1_eaten_pieces[counter1++] = chessboard[r2][c2][1];
                        chessboard[r2][c2][1] = chessboard[r1][c1][1];
                        chessboard[r2][c2][2] = chessboard[r1][c1][2];
                        chessboard[r1][c1][1] = 0;
                        chessboard[r1][c1][2] = 0;
                        flag = 1;
                    }
                    else{system("cls"); printf("Invalid play, try again!"); continue;}
                }

                // bishop movement.
                else if(chessboard[r1][c1][1] == 66){
                    if(r2-r1 == c2-c1 || r2-r1 == -(c2-c1)){
                        if(r2 > r1 && c2 > c1){
                            for(i=r1+1 , j=c1+1; i<r2 && j<c2; ++i, ++j){
                                if(chessboard[i][j][1] != 0){
                                    system("cls");
                                printf("Invalid play, try again!");
                                flag2 = 1;
                                continue;
                                }
                            }
                        }
                        else if(r2 > r1 && c2 < c1){
                            for(i=r1+1 , j=c1-1; i<r2 && j>c2; ++i, --j){
                                if(chessboard[i][j][1] != 0){
                                system("cls");
                                printf("Invalid play, try again!");
                                flag2 = 1;
                                continue;
                                }
                            }
                        }
                        else if(r2 < r1 && c2 > c1){
                            for(i=r1-1 , j=c1+1; i>r2 && j<c2; --i, ++j){
                                if(chessboard[i][j][1] != 0){
                                system("cls");
                                printf("Invalid play, try again!");
                                flag2 = 1;
                                continue;
                                }
                            }
                        }
                        else if(r2 < r1 && c2 < c1){
                            for(i=r1-1 , j=c1-1; i>r2 && j>c2; --i, --j){
                                if(chessboard[i][j][1] != 0){
                                system("cls");
                                printf("Invalid play, try again!");
                                flag2 = 1;
                                continue;
                                }
                            }
                        }
                        if(flag2 == 1) continue;
                        if(chessboard[r2][c2][1] != 0) player1_eaten_pieces[counter1++] = chessboard[r2][c2][1];
                        chessboard[r2][c2][1] = chessboard[r1][c1][1];
                        chessboard[r2][c2][2] = chessboard[r1][c1][2];
                        chessboard[r1][c1][1] = 0;
                        chessboard[r1][c1][2] = 0;
                        flag = 1;

                    }
                    else{system("cls"); printf("Invalid play, try again!"); continue;}
                }

                // queen movement
                if(chessboard[r1][c1][1] == 81){
                    if(r2 > r1 && c1 == c2){
                        for(int i = r1 + 1; i < r2; ++i){
                            if(chessboard[i][c1][1] != 0){
                                system("cls");
                                printf("Invalid play, try again!");
                                flag2 = 1;
                                continue;
                            }
                        }
                        if(flag2 == 1) continue;
                        if(chessboard[r2][c2][1] != 0) player1_eaten_pieces[counter1++] = chessboard[r2][c2][1];
                        chessboard[r2][c2][1] = chessboard[r1][c1][1];
                        chessboard[r2][c2][2] = chessboard[r1][c1][2];
                        chessboard[r1][c1][1] = 0;
                        chessboard[r1][c1][2] = 0;
                        flag = 1;
                    }
                    else if(r2 < r1 && c1 == c2){
                        for(int i = r1 - 1; i > r2; --i){
                            if(chessboard[i][c1][1] != 0){
                                printf("Invalid play, try again!");
                                flag2 = 1;
                                continue;
                            }
                        }
                        if(flag2 == 1) continue;
                        if(chessboard[r2][c2][1] != 0) player1_eaten_pieces[counter1++] = chessboard[r2][c2][1];
                        chessboard[r2][c2][1] = chessboard[r1][c1][1];
                        chessboard[r2][c2][2] = chessboard[r1][c1][2];
                        chessboard[r1][c1][1] = 0;
                        chessboard[r1][c1][2] = 0;
                        flag = 1;
                    }
                    else if(c2 > c1 && r1 == r2){
                        for(int i = c1 + 1; i < c2; ++i){
                            if(chessboard[r1][i][1] != 0){
                                system("cls");
                                printf("Invalid play, try again!");
                                flag2 = 1;
                                continue;
                            }
                        }
                        if(flag2 == 1) continue;
                        if(chessboard[r2][c2][1] != 0) player1_eaten_pieces[counter1++] = chessboard[r2][c2][1];
                        chessboard[r2][c2][1] = chessboard[r1][c1][1];
                        chessboard[r2][c2][2] = chessboard[r1][c1][2];
                        chessboard[r1][c1][1] = 0;
                        chessboard[r1][c1][2] = 0;
                        flag = 1;
                    }
                    else if(c2 < c1 && r1 == r2){
                        for(int i = c1 - 1; i > c2; --i){
                            if(chessboard[r1][i][1] != 0){
                                system("cls");
                                printf("Invalid play, try again!");
                                flag2 = 1;
                                continue;
                            }
                        }
                        if(flag2 == 1) continue;
                        if(chessboard[r2][c2][1] != 0) player1_eaten_pieces[counter1++] = chessboard[r2][c2][1];
                        chessboard[r2][c2][1] = chessboard[r1][c1][1];
                        chessboard[r2][c2][2] = chessboard[r1][c1][2];
                        chessboard[r1][c1][1] = 0;
                        chessboard[r1][c1][2] = 0;
                        flag = 1;
                    }
                    if(r2-r1 == c2-c1 || r2-r1 == -(c2-c1)){
                        if(r2 > r1 && c2 > c1){
                            for(i=r1+1 , j=c1+1; i<r2 && j<c2; ++i, ++j){
                                if(chessboard[i][j][1] != 0){
                                system("cls");
                                printf("Invalid play, try again!");
                                flag2 = 1;
                                continue;
                                }
                            }
                        }
                        else if(r2 > r1 && c2 < c1){
                            for(i=r1+1 , j=c1-1; i<r2 && j>c2; ++i, --j){
                                if(chessboard[i][j][1] != 0){
                                system("cls");
                                printf("Invalid play, try again!");
                                flag2 = 1;
                                continue;
                                }
                            }
                        }
                        else if(r2 < r1 && c2 > c1){
                            for(i=r1-1 , j=c1+1; i>r2 && j<c2; --i, ++j){
                                if(chessboard[i][j][1] != 0){
                                system("cls");
                                printf("Invalid play, try again!");
                                flag2 = 1;
                                continue;
                                }
                            }
                        }
                        else if(r2 < r1 && c2 < c1){
                            for(i=r1-1 , j=c1-1; i>r2 && j>c2; --i, --j){
                                if(chessboard[i][j][1] != 0){
                                system("cls");
                                printf("Invalid play, try again!");
                                flag2 = 1;
                                continue;
                                }
                            }
                        }
                        if(flag2 == 1) continue;
                        if(chessboard[r2][c2][1] != 0) player1_eaten_pieces[counter1++] = chessboard[r2][c2][1];
                        chessboard[r2][c2][1] = chessboard[r1][c1][1];
                        chessboard[r2][c2][2] = chessboard[r1][c1][2];
                        chessboard[r1][c1][1] = 0;
                        chessboard[r1][c1][2] = 0;
                        flag = 1;

                    }
                }

                // night movement
                if(chessboard[r1][c1][1] == 78){
                    if((r2==r1+1 && c2==c1+2) || (r2==r1+1 && c2==c1-2)
                       || (r2==r1-1 && c2==c1+2) || (r2==r1-1 && c2==c1-2)
                       || (c2==c1+1 && r2==r1+2) || (c2==c1+1 && r2==r1-2)
                       || (c2==c1-1 && r2==r1+2) || (c2==c1-1 && r2==r1-2)){

                        if(chessboard[r2][c2][1] != 0) player1_eaten_pieces[counter1++] = chessboard[r2][c2][1];
                        chessboard[r2][c2][1] = chessboard[r1][c1][1];
                        chessboard[r2][c2][2] = chessboard[r1][c1][2];
                        chessboard[r1][c1][1] = 0;
                        chessboard[r1][c1][2] = 0;
                        flag = 1;
                       }
                    else{system("cls"); printf("Invalid play, try again!"); continue;}
                }

            }

            else if(x == 'u' && y == 'n' && z == 'd'){
                if(getchar() == 'o' && getchar() == '\n'){
                    if(counter_undo != 1){
                        flag = 1;
                        counter_undo = counter_undo - 1;
                        for(int i = 0; i < 8; ++i){
                            for(int j = 0; j < 8; ++j){
                                for(int k = 0; k < 3; ++k){
                                    redo_stack[counter_redo][i][j][k] = undo_stack[counter_undo][i][j][k];
                                }
                            }
                        }
                        if(counter1 != 0){
                            if(undostack1_eaten_pieces[counter_undo-1][counter1-1] != undostack1_eaten_pieces[counter_undo][counter1-1]){
                                counter1--;
                            }
                        }
                        if(counter2 != 0){
                            if(undostack2_eaten_pieces[counter_undo-1][counter2-1] != undostack2_eaten_pieces[counter_undo][counter2-1]){
                                counter2--;
                            }
                        }
                        for(int i = 0; i < 30; ++i){
                            redostack1_eaten_pieces[counter_redo][i] = undostack1_eaten_pieces[counter_undo][i];
                            redostack2_eaten_pieces[counter_redo][i] = undostack2_eaten_pieces[counter_undo][i];
                        }
                        counter_redo++;
                        for(int i = 0; i < 8; ++i){
                            for(int j = 0; j < 8; ++j){
                                for(int k = 0; k < 3; ++k){
                                    chessboard[i][j][k] = undo_stack[counter_undo-1][i][j][k];
                                }
                            }
                        }
                        for(int i = 0; i < 30; ++i){
                            player1_eaten_pieces[i] = undostack1_eaten_pieces[counter_undo-1][i];
                            player2_eaten_pieces[i] = undostack2_eaten_pieces[counter_undo-1][i];
                        }
                        system("cls");
                        continue;
                    }
                }
                else{
                    while(getchar() != '\n'){}
                    system("cls");
                    printf("Invalid input, try again!\n");
                    continue;
                }

            }
            else if(x == 'r' && y == 'e' && z == 'd'){
                if(getchar() == 'o' && getchar() == '\n'){
                    if(counter_redo == 0) continue;
                    flag = 1;
                    for(int i = 0; i < 8; ++i){
                        for(int j = 0; j < 8; ++j){
                            for(int k = 0; k < 3; ++k){
                                chessboard[i][j][k] = redo_stack[counter_redo - 1][i][j][k];
                                undo_stack[counter_undo][i][j][k] = redo_stack[counter_redo - 1][i][j][k];
                            }
                        }
                    }
                    if(redostack1_eaten_pieces[counter_redo-1][counter1] != undostack1_eaten_pieces[counter_undo-1][counter1]){
                        counter1++;

                    }
                    if(redostack2_eaten_pieces[counter_redo-1][counter2] != undostack2_eaten_pieces[counter_undo-1][counter2]){
                        counter2++;
                    }

                    for(int i = 0; i < 30; ++i){
                        player1_eaten_pieces[i] = redostack1_eaten_pieces[counter_redo-1][i];
                        player2_eaten_pieces[i] = redostack2_eaten_pieces[counter_redo-1][i];

                        undostack1_eaten_pieces[counter_undo][i] = redostack1_eaten_pieces[counter_redo-1][i];
                        undostack2_eaten_pieces[counter_undo][i] = redostack2_eaten_pieces[counter_redo-1][i];
                    }
                    counter_undo++;
                    counter_redo--;
                }
                else{
                    while(getchar() != '\n'){}
                    system("cls");
                    printf("Invalid input, try again!\n");
                    continue;
                }
                system("cls");
                continue;
            }
            else if(x == 's' && y == 'a' && z == 'v'){
                if(getchar() == 'e' && getchar() == '\n'){
                    FILE * game_data = fopen("game_data.txt", "w");
                    fprintf(game_data, "%d ", 1);
                    for(int i = 0; i < 8; ++i){
                        for(int j = 0; j < 8; ++j){
                            for(int k = 0; k < 3; ++k){
                                fprintf(game_data, "%d ", chessboard[i][j][k]);
                            }
                        }
                    }
                    fprintf(game_data, "%d %d %d ", counter_king1, counter_king2, flag);
                    for(int i = 0; i < 30; ++i){
                        fprintf(game_data, "%d ", player1_eaten_pieces[i]);
                        fprintf(game_data, "%d ", player2_eaten_pieces[i]);
                    }
                    fprintf(game_data, "%d %d ", counter1, counter2);
                    fprintf(game_data, "%d %d %d %d ", king1_r, king1_c, king2_r, king2_c);
                    fclose(game_data);
                    break;
                }
                else{
                    while(getchar() != '\n'){}
                    system("cls");
                    printf("Invalid input, try again!\n");
                    continue;
                }
            }

            // promotion
            else{
                if(getchar() == '\n'){
                    c1 = x - 97;
                    if(c1>7 || c1 < 0){system("cls");printf("Invalid input, try again!\n"); continue;}
                    r1 = r1 - 1;
                    if(r1>7 || r1 < 0){system("cls");printf("Invalid input, try again!\n"); continue;}
                    c2 = y - 97;
                    if(c2>7 || c2 < 0){system("cls");printf("Invalid input, try again!\n"); continue;}
                    r2 = r2 - 1;
                    if(r2>7 || r2 < 0){system("cls");printf("Invalid input, try again!\n"); continue;}

                    if(chessboard[r1][c1][1] == 0 || chessboard[r1][c1][2] != 2){
                        system("cls");
                        printf("Invalid play, try again!\n");
                        continue;
                    }
                    if(chessboard[r2][c2][2] == 2){
                        system("cls");
                        printf("Invalid play, try again!\n");
                        continue;
                    }

                    if(chessboard[r1][c1][1] == 80){
                        if(r1 == 1){
                            if(z == 82 || z==78 || z==81 || z==66){
                                if(r2 == r1 - 1 && c2 == c1 && chessboard[r2][c2][1] == 0){
                                    chessboard[r2][c2][1] = chessboard[r1][c1][1];
                                    chessboard[r2][c2][2] = chessboard[r1][c1][2];
                                    chessboard[r1][c1][1] = 0;
                                    chessboard[r1][c1][2] = 0;
                                    flag = 1;
                                    chessboard[r2][c2][1] = z;
                                }
                                else if(((r2 == r1 - 1 && c2 == c1 + 1) || (r2 == r1 - 1 && c2 == c1 - 1)) && chessboard[r2][c2][1] != 0){
                                    player1_eaten_pieces[counter1++] = chessboard[r2][c2][1];
                                    chessboard[r2][c2][1] = chessboard[r1][c1][1];
                                    chessboard[r2][c2][2] = chessboard[r1][c1][2];
                                    chessboard[r1][c1][1] = 0;
                                    chessboard[r1][c1][2] = 0;
                                    flag = 1;
                                    chessboard[r2][c2][1] = z;
                                }
                                else{system("cls"); printf("Invalid play, try again!"); continue;}
                            }
                            else{system("cls"); printf("Invalid play, try again!"); continue;}
                        }
                        else{
                            system("cls");
                            printf("Invalid play, try again!\n");
                            continue;
                        }
                    }
                    else{
                        system("cls");
                        printf("Invalid play, try again!\n");
                        continue;
                    }
                }
                else{
                    while(getchar() != '\n'){}
                    system("cls");
                    printf("Invalid input, try again!\n");
                    continue;
                }
            }

            if(flag == 1){
                if(check_position(chessboard, king2_r, king2_c, 1, 1) == 1){
                    flag = 2;
                    for(int i = 0; i < 8; ++i){
                        for(int j = 0; j < 8; ++j){
                            for(int k = 0; k < 3; ++k){
                                chessboard[i][j][k] = undo_stack[counter_undo-1][i][j][k];
                            }
                        }
                    }
                    if(undostack1_eaten_pieces[counter_undo-1][counter1-1] != player1_eaten_pieces[counter1-1]){
                        counter1--;
                    }
                    if(undostack2_eaten_pieces[counter_undo-1][counter2-1] != player2_eaten_pieces[counter2-1]){
                        counter2--;
                    }
                    for(int i = 0; i < 30; ++i){
                        player1_eaten_pieces[i] = undostack1_eaten_pieces[counter_undo-1][i];
                        player2_eaten_pieces[i] = undostack2_eaten_pieces[counter_undo-1][i];
                    }
                    system("cls");
                    printf("Invalid play, king in check");
                    continue;
                }


                piece = chessboard[r1][c1][1];

                // ---------------------------
                counter_redo = 0;
                for(int i = 0; i < 8; ++i){
                    for(int j = 0; j < 8; ++j){
                        for(int k = 0; k < 3; ++k){
                            undo_stack[counter_undo][i][j][k] = chessboard[i][j][k];
                        }
                    }
                }
                for(int i = 0; i < 30; ++i){
                    undostack1_eaten_pieces[counter_undo][i] = player1_eaten_pieces[i];
                    undostack2_eaten_pieces[counter_undo][i] = player2_eaten_pieces[i];
                }
                counter_undo++;

                if(check_position(chessboard, king1_r, king1_c, 2, 1) == 1){
                    if(checkmate(chessboard, piece, king1_r, king1_c, r2, c2, 1) == 1){
                        printf("\n\nPlayer 2 wins");
                        break;
                    }
                    system("cls");
                    printf("Player 1 in check");
                    continue;
                }
                if(stalemate(chessboard, 1, king1_r, king1_c) == 1){
                    printf("\n\nstalemate");
                    break;
                }
                system("cls");
            }
        }
    }

    return 0;
}

