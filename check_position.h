int check_position(int chessboard[8][8][3], int r, int c, int detector1, int detector2){

    int i, j;
    if(detector1 == 1){
        // checking for rook or queen.
        for(int i = r + 1; i < 8; ++i){
            if(chessboard[i][c][2] == 2) break;
            if(chessboard[i][c][2] == 1 && chessboard[i][c][1] != 114 && chessboard[i][c][1] != 113) break;
            if(chessboard[i][c][1] == 114 || chessboard[i][c][1] == 113) return 1;
        }
        for(int i = r - 1; i > -1; --i){
            if(chessboard[i][c][2] == 2) break;
            if(chessboard[i][c][2] == 1 && chessboard[i][c][1] != 114 && chessboard[i][c][1] != 113) break;
            if(chessboard[i][c][1] == 114 || chessboard[i][c][1] == 113) return 1;
        }
        for(int i = c + 1; i < 8; ++i){
            if(chessboard[r][i][2] == 2) break;
            if(chessboard[r][i][2] == 1 && chessboard[r][i][1] != 114 && chessboard[r][i][1] != 113) break;
            if(chessboard[r][i][1] == 114 || chessboard[r][i][1] == 113) return 1;
        }
        for(int i = c - 1; i > -1; --i){
            if(chessboard[r][i][2] == 2) break;
            if(chessboard[r][i][2] == 1 && chessboard[r][i][1] != 114 && chessboard[r][i][1] != 113) break;
            if(chessboard[r][i][1] == 114 || chessboard[r][i][1] == 113) return 1;
        }

        // check for bishop or queen.
        for(i = r + 1, j = c + 1; i < 8 && j < 8; ++i, ++j){
            if(chessboard[i][j][2] == 2) break;
            if(chessboard[i][j][2] == 1 && chessboard[i][j][1] != 98 && chessboard[i][j][1] != 113) break;
            if(chessboard[i][j][1] == 98 || chessboard[i][j][1] == 113) return 1;
        }
        for(i = r + 1, j = c - 1; i < 8 && j > -1; ++i, --j){
            if(chessboard[i][j][2] == 2) break;
            if(chessboard[i][j][2] == 1 && chessboard[i][j][1] != 98 && chessboard[i][j][1] != 113) break;
            if(chessboard[i][j][1] == 98 || chessboard[i][j][1] == 113) return 1;
        }
        for(i = r - 1, j = c + 1; i > -1 && j < 8; --i, ++j){
            if(chessboard[i][j][2] == 2) break;
            if(chessboard[i][j][2] == 1 && chessboard[i][j][1] != 98 && chessboard[i][j][1] != 113) break;
            if(chessboard[i][j][1] == 98 || chessboard[i][j][1] == 113) return 1;
        }
        for(i = r - 1, j = c - 1; i > -1 && j > -1; --i, --j){
            if(chessboard[i][j][2] == 2) break;
            if(chessboard[i][j][2] == 1 && chessboard[i][j][1] != 98 && chessboard[i][j][1] != 113) break;
            if(chessboard[i][j][1] == 98 || chessboard[i][j][1] == 113) return 1;
        }

        // checking for knight.
        if(r+1<8 && r+1>-1 && c+2<8 &&c+2>-1){
            if(chessboard[r+1][c+2][1] == 110) return 1;
        }
        if(r+1<8 && r+1>-1 && c-2<8 &&c-2>-1){
            if(chessboard[r+1][c-2][1] == 110) return 1;
        }
        if(r-1<8 && r-1>-1 && c+2<8 &&c+2>-1){
            if(chessboard[r-1][c+2][1] == 110) return 1;
        }
        if(r-1<8 && r-1>-1 && c-2<8 &&c-2>-1){
            if(chessboard[r-1][c-2][1] == 110) return 1;
        }
        if(r+2<8 && r+2>-1 && c+1<8 &&c+1>-1){
            if(chessboard[r+2][c+1][1] == 110) return 1;
        }
        if(r-2<8 && r-2>-1 && c+1<8 &&c+1>-1){
            if(chessboard[r-2][c+1][1] == 110) return 1;
        }
        if(r+2<8 && r+2>-1 && c-1<8 &&c-1>-1){
            if(chessboard[r+2][c-1][1] == 110) return 1;
        }
        if(r-2<8 && r-2>-1 && c-1<8 &&c-1>-1){
            if(chessboard[r-2][c-1][1] == 110) return 1;
        }


        // checking for pawn.
        if(detector2 == 1){
            if(r-1<8 && r-1>-1 && c+1<8 && c+1>-1){
                if(chessboard[r-1][c+1][1] == 112) return 1;
            }
            if(r-1<8 && r-1>-1 && c-1<8 && c-1>-1){
                if(chessboard[r-1][c-1][1] == 112) return 1;
            }
        }else if(detector2 == 2){
            if(r-1<8 && r-1>-1){
                if(chessboard[r-1][c][1] == 112) return 1;
            }
            if(r-2<8 && r-2>-1){
                if(r-2 == 1){
                    if(chessboard[r-2][c][1] == 112) return 1;
                }
            }
        }

        // checking for king.
        if(detector2 == 1){
            if(r+1<8 && r+1>-1 && c+1<8 && c+1>-1){
                if(chessboard[r+1][c+1][1] == 107) return 2;
            }
            if(r<8 && r>-1 && c+1<8 && c+1>-1){
                if(chessboard[r][c+1][1] == 107) return 2;
            }
            if(r-1<8 && r-1>-1 && c+1<8 && c+1>-1){
                if(chessboard[r-1][c+1][1] == 107) return 2;
            }
            if(r+1<8 && r+1>-1 && c-1<8 && c-1>-1){
                if(chessboard[r+1][c-1][1] == 107) return 2;
            }
            if(r<8 && r>-1 && c-1<8 && c-1>-1){
                if(chessboard[r][c-1][1] == 107) return 2;
            }
            if(r-1<8 && r-1>-1 && c-1<8 && c-1>-1){
                if(chessboard[r-1][c-1][1] == 107) return 2;
            }
            if(r+1<8 && r+1>-1 && c<8 && c>-1){
                if(chessboard[r+1][c][1] == 107) return 2;
            }
            if(r-1<8 && r-1>-1 && c<8 && c>-1){
                if(chessboard[r-1][c][1] == 107) return 2;
            }
        }
        return 0;

    }
    else if(detector1 == 2){
        // checking for rook or queen.
        for(int i = r + 1; i < 8; ++i){
            if(chessboard[i][c][2] == 1) break;
            if(chessboard[i][c][2] == 2 && chessboard[i][c][1] != 82 && chessboard[i][c][1] != 81) break;
            if(chessboard[i][c][1] == 82 || chessboard[i][c][1] == 81) return 1;
        }
        for(int i = r - 1; i > -1; --i){
            if(chessboard[i][c][2] == 1) break;
            if(chessboard[i][c][2] == 2 && chessboard[i][c][1] != 82 && chessboard[i][c][1] != 81) break;
            if(chessboard[i][c][1] == 82 || chessboard[i][c][1] == 81) return 1;
        }
        for(int i = c + 1; i < 8; ++i){
            if(chessboard[r][i][2] == 1) break;
            if(chessboard[r][i][2] == 2 && chessboard[r][i][1] != 82 && chessboard[r][i][1] != 81) break;
            if(chessboard[r][i][1] == 82 || chessboard[r][i][1] == 81) return 1;
        }
        for(int i = c - 1; i > -1; --i){
            if(chessboard[r][i][2] == 1) break;
            if(chessboard[r][i][2] == 2 && chessboard[r][i][1] != 82 && chessboard[r][i][1] != 81) break;
            if(chessboard[r][i][1] == 82 || chessboard[r][i][1] == 81) return 1;
        }

        // check for bishop or queen.
        for(i = r + 1, j = c + 1; i < 8 && j < 8; ++i, ++j){
            if(chessboard[i][j][2] == 1) break;
            if(chessboard[i][j][2] == 2 && chessboard[i][j][1] != 66 && chessboard[i][j][1] != 81) break;
            if(chessboard[i][j][1] == 66 || chessboard[i][j][1] == 81) return 1;
        }
        for(i = r + 1, j = c - 1; i < 8 && j > -1; ++i, --j){
            if(chessboard[i][j][2] == 1) break;
            if(chessboard[i][j][2] == 2 && chessboard[i][j][1] != 66 && chessboard[i][j][1] != 81) break;
            if(chessboard[i][j][1] == 66 || chessboard[i][j][1] == 81) return 1;
        }
        for(i = r - 1, j = c + 1; i > -1 && j < 8; --i, ++j){
            if(chessboard[i][j][2] == 1) break;
            if(chessboard[i][j][2] == 2 && chessboard[i][j][1] != 66 && chessboard[i][j][1] != 81) break;
            if(chessboard[i][j][1] == 66 || chessboard[i][j][1] == 81) return 1;
        }
        for(i = r - 1, j = c - 1; i > -1 && j > -1; --i, --j){
            if(chessboard[i][j][2] == 1) break;
            if(chessboard[i][j][2] == 2 && chessboard[i][j][1] != 66 && chessboard[i][j][1] != 81) break;
            if(chessboard[i][j][1] == 66 || chessboard[i][j][1] == 81) return 1;
        }

        // checking for knight.
        if(r+1<8 && r+1>-1 && c+2<8 &&c+2>-1){
            if(chessboard[r+1][c+2][1] == 78) return 1;
        }
        if(r+1<8 && r+1>-1 && c-2<8 &&c-2>-1){
            if(chessboard[r+1][c-2][1] == 78) return 1;
        }
        if(r-1<8 && r-1>-1 && c+2<8 &&c+2>-1){
            if(chessboard[r-1][c+2][1] == 78) return 1;
        }
        if(r-1<8 && r-1>-1 && c-2<8 &&c-2>-1){
            if(chessboard[r-1][c-2][1] == 78) return 1;
        }
        if(r+2<8 && r+2>-1 && c+1<8 &&c+1>-1){
            if(chessboard[r+2][c+1][1] == 78) return 1;
        }
        if(r-2<8 && r-2>-1 && c+1<8 &&c+1>-1){
            if(chessboard[r-2][c+1][1] == 78) return 1;
        }
        if(r+2<8 && r+2>-1 && c-1<8 &&c-1>-1){
            if(chessboard[r+2][c-1][1] == 78) return 1;
        }
        if(r-2<8 && r-2>-1 && c-1<8 &&c-1>-1){
            if(chessboard[r-2][c-1][1] == 78) return 1;
        }

        // checking for pawn.
        if(detector2 == 1){
            if(r+1<8 && r+1>-1 && c+1<8 && c+1>-1){
                if(chessboard[r+1][c+1][1] == 80) return 1;
            }
            if(r+1<8 && r+1>-1 && c-1<8 && c-1>-1){
                if(chessboard[r+1][c-1][1] == 80) return 1;
            }
        }else if(detector2 == 2){
            if(r+1<8 && r+1>-1){
                if(chessboard[r+1][c][1] == 80) return 1;
            }
            if(r+2<8 && r+2>-1){
                if(r+2 == 6){
                    if(chessboard[r+2][c][1] == 80) return 1;
                }
            }
        }

        // checking for king.
        if(detector2 == 1){
            if(r+1<8 && r+1>-1 && c+1<8 && c+1>-1){
                if(chessboard[r+1][c+1][1] == 75) return 2;
            }
            if(r<8 && r>-1 && c+1<8 && c+1>-1){
                if(chessboard[r][c+1][1] == 75) return 2;
            }
            if(r-1<8 && r-1>-1 && c+1<8 && c+1>-1){
                if(chessboard[r-1][c+1][1] == 75) return 2;
            }
            if(r+1<8 && r+1>-1 && c-1<8 && c-1>-1){
                if(chessboard[r+1][c-1][1] == 75) return 2;
            }
            if(r<8 && r>-1 && c-1<8 && c-1>-1){
                if(chessboard[r][c-1][1] == 75) return 2;
            }
            if(r-1<8 && r-1>-1 && c-1<8 && c-1>-1){
                if(chessboard[r-1][c-1][1] == 75) return 2;
            }
            if(r+1<8 && r+1>-1 && c<8 && c>-1){
                if(chessboard[r+1][c][1] == 75) return 2;
            }
            if(r-1<8 && r-1>-1 && c<8 && c>-1){
                if(chessboard[r-1][c][1] == 75) return 2;
            }
        }
    }
    return 0;
}