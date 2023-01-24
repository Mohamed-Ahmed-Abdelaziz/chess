int stalemate(int chessboard[8][8][3], int detector, int king_r, int king_c){

    int sub1, sub2, flag = 0;
    if(detector == 2){
        for(int r = 0; r < 8; ++r){
            for(int c = 0; c < 8; ++c){

                if(chessboard[r][c][1] == 75){
                    // checking if king can move.
                    if(r+1<8 && r+1>-1 && c+1<8 && c+1>-1){
                        if(chessboard[r+1][c+1][2] == 2) {}
                        else {
                            if(check_position(chessboard, r+1, c+1, 1, 1) == 0) return 0;
                        }
                    }
                    if(r<8 && r>-1 && c+1<8 && c+1>-1){
                        if(chessboard[r][c+1][2] == 2) {}
                        else {
                            if(check_position(chessboard, r, c+1, 1, 1) == 0) return 0;
                        }
                    }
                    if(r-1<8 && r-1>-1 && c+1<8 && c+1>-1){
                        if(chessboard[r-1][c+1][2] == 2) {}
                        else {
                            if(check_position(chessboard, r-1, c+1, 1, 1) == 0) return 0;
                        }
                    }
                    if(r+1<8 && r+1>-1 && c-1<8 && c-1>-1){
                        if(chessboard[r+1][c-1][2] == 2) {}
                        else {
                            if(check_position(chessboard, r+1, c-1, 1, 1) == 0) return 0;
                        }
                    }
                    if(r<8 && r>-1 && c-1<8 && c-1>-1){
                        if(chessboard[r][c-1][2] == 2) {}
                        else {
                            if(check_position(chessboard, r, c-1, 1, 1) == 0) return 0;
                        }
                    }
                    if(r-1<8 && r-1>-1 && c-1<8 && c-1>-1){
                        if(chessboard[r-1][c-1][2] == 2) {}
                        else {
                            if(check_position(chessboard, r-1, c-1, 1, 1) == 0) return 0;
                        }
                    }
                    if(r+1<8 && r+1>-1 && c<8 && c>-1){
                        if(chessboard[r+1][c][2] == 2) {}
                        else {
                            if(check_position(chessboard, r+1, c, 1, 1) == 0) return 0;
                        }
                    }
                    if(r-1<8 && r-1>-1 && c<8 && c>-1){
                        if(chessboard[r-1][c][2] == 2) {}
                        else {
                            if(check_position(chessboard, r-1, c, 1, 1) == 0) return 0;
                        }
                    }
                }

                // checking if pawn can move.
                if(chessboard[r][c][1] == 80){
                    if(r-1>-1){
                        if(chessboard[r-1][c][1] == 0){
                            sub1 = chessboard[r-1][c][1];
                            sub2 = chessboard[r-1][c][2];
                            chessboard[r-1][c][1] = chessboard[r][c][1];
                            chessboard[r-1][c][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 1, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r-1][c][1];
                            chessboard[r][c][2] = chessboard[r-1][c][2];
                            chessboard[r-1][c][1] = sub1;
                            chessboard[r-1][c][2] = sub2;
                            if(flag == 1) return 0;

                        }
                    }
                    if(r-1>-1 && c+1<8){
                        if(chessboard[r-1][c+1][2] == 1){
                            sub1 = chessboard[r-1][c+1][1];
                            sub2 = chessboard[r-1][c+1][2];
                            chessboard[r-1][c+1][1] = chessboard[r][c][1];
                            chessboard[r-1][c+1][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 1, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r-1][c+1][1];
                            chessboard[r][c][2] = chessboard[r-1][c+1][2];
                            chessboard[r-1][c+1][1] = sub1;
                            chessboard[r-1][c+1][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(r-1>-1 && c-1>-1){
                        if(chessboard[r-1][c-1][2] == 1){
                            sub1 = chessboard[r-1][c-1][1];
                            sub2 = chessboard[r-1][c-1][2];
                            chessboard[r-1][c-1][1] = chessboard[r][c][1];
                            chessboard[r-1][c-1][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 1, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r-1][c-1][1];
                            chessboard[r][c][2] = chessboard[r-1][c-1][2];
                            chessboard[r-1][c-1][1] = sub1;
                            chessboard[r-1][c-1][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                }

                // checking if night can move.
                if(chessboard[r][c][1] == 78){
                    if(r+1<8 && r+1>-1 && c+2<8 &&c+2>-1){
                        if(chessboard[r+1][c+2][2] != 2){
                            sub1 = chessboard[r+1][c+2][1];
                            sub2 = chessboard[r+1][c+2][2];
                            chessboard[r+1][c+2][1] = chessboard[r][c][1];
                            chessboard[r+1][c+2][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 1, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r+1][c+2][1];
                            chessboard[r][c][2] = chessboard[r+1][c+2][2];
                            chessboard[r+1][c+2][1] = sub1;
                            chessboard[r+1][c+2][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(r+1<8 && r+1>-1 && c-2<8 &&c-2>-1){
                        if(chessboard[r+1][c-2][2] != 2){
                            sub1 = chessboard[r+1][c-2][1];
                            sub2 = chessboard[r+1][c-2][2];
                            chessboard[r+1][c-2][1] = chessboard[r][c][1];
                            chessboard[r+1][c-2][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 1, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r+1][c-2][1];
                            chessboard[r][c][2] = chessboard[r+1][c-2][2];
                            chessboard[r+1][c-2][1] = sub1;
                            chessboard[r+1][c-2][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(r-1<8 && r-1>-1 && c+2<8 &&c+2>-1){
                        if(chessboard[r-1][c+2][2] != 2){
                            sub1 = chessboard[r-1][c+2][1];
                            sub2 = chessboard[r-1][c+2][2];
                            chessboard[r-1][c+2][1] = chessboard[r][c][1];
                            chessboard[r-1][c+2][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 1, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r-1][c+2][1];
                            chessboard[r][c][2] = chessboard[r-1][c+2][2];
                            chessboard[r-1][c+2][1] = sub1;
                            chessboard[r-1][c+2][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(r-1<8 && r-1>-1 && c-2<8 &&c-2>-1){
                        if(chessboard[r-1][c-2][2] != 2){
                            sub1 = chessboard[r-1][c-2][1];
                            sub2 = chessboard[r-1][c-2][2];
                            chessboard[r-1][c-2][1] = chessboard[r][c][1];
                            chessboard[r-1][c-2][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 1, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r-1][c-2][1];
                            chessboard[r][c][2] = chessboard[r-1][c-2][2];
                            chessboard[r-1][c-2][1] = sub1;
                            chessboard[r-1][c-2][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(r+2<8 && r+2>-1 && c+1<8 &&c+1>-1){
                        if(chessboard[r+2][c+1][2] != 2){
                            sub1 = chessboard[r+2][c+1][1];
                            sub2 = chessboard[r+2][c+1][2];
                            chessboard[r+2][c+1][1] = chessboard[r][c][1];
                            chessboard[r+2][c+1][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 1, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r+2][c+1][1];
                            chessboard[r][c][2] = chessboard[r+2][c+1][2];
                            chessboard[r+2][c+1][1] = sub1;
                            chessboard[r+2][c+1][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(r-2<8 && r-2>-1 && c+1<8 &&c+1>-1){
                        if(chessboard[r-2][c+1][2] != 2){
                            sub1 = chessboard[r-2][c+1][1];
                            sub2 = chessboard[r-2][c+1][2];
                            chessboard[r-2][c+1][1] = chessboard[r][c][1];
                            chessboard[r-2][c+1][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 1, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r-2][c+1][1];
                            chessboard[r][c][2] = chessboard[r-2][c+1][2];
                            chessboard[r-2][c+1][1] = sub1;
                            chessboard[r-2][c+1][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(r+2<8 && r+2>-1 && c-1<8 &&c-1>-1){
                        if(chessboard[r+2][c-1][2] != 2){
                            sub1 = chessboard[r+2][c-1][1];
                            sub2 = chessboard[r+2][c-1][2];
                            chessboard[r+2][c-1][1] = chessboard[r][c][1];
                            chessboard[r+2][c-1][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 1, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r+2][c-1][1];
                            chessboard[r][c][2] = chessboard[r+2][c-1][2];
                            chessboard[r+2][c-1][1] = sub1;
                            chessboard[r+2][c-1][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(r-2<8 && r-2>-1 && c-1<8 &&c-1>-1){
                        if(chessboard[r-2][c-1][2] != 2){
                            sub1 = chessboard[r-2][c-1][1];
                            sub2 = chessboard[r-2][c-1][2];
                            chessboard[r-2][c-1][1] = chessboard[r][c][1];
                            chessboard[r-2][c-1][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 1, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r-2][c-1][1];
                            chessboard[r][c][2] = chessboard[r-2][c-1][2];
                            chessboard[r-2][c-1][1] = sub1;
                            chessboard[r-2][c-1][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                }

                //checking if rook can move.
                if(chessboard[r][c][1] == 82){
                    if(r+1<8){
                        if(chessboard[r+1][c][2] != 2){
                            sub1 = chessboard[r+1][c][1];
                            sub2 = chessboard[r+1][c][2];
                            chessboard[r+1][c][1] = chessboard[r][c][1];
                            chessboard[r+1][c][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 1, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r+1][c][1];
                            chessboard[r][c][2] = chessboard[r+1][c][2];
                            chessboard[r+1][c][1] = sub1;
                            chessboard[r+1][c][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(r-1>-1){
                        if(chessboard[r-1][c][2] != 2){
                            sub1 = chessboard[r-1][c][1];
                            sub2 = chessboard[r-1][c][2];
                            chessboard[r-1][c][1] = chessboard[r][c][1];
                            chessboard[r-1][c][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 1, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r-1][c][1];
                            chessboard[r][c][2] = chessboard[r-1][c][2];
                            chessboard[r-1][c][1] = sub1;
                            chessboard[r-1][c][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(c+1<8){
                        if(chessboard[r][c+1][2] != 2){
                            sub1 = chessboard[r][c+1][1];
                            sub2 = chessboard[r][c+1][2];
                            chessboard[r][c+1][1] = chessboard[r][c][1];
                            chessboard[r][c+1][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 1, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r][c+1][1];
                            chessboard[r][c][2] = chessboard[r][c+1][2];
                            chessboard[r][c+1][1] = sub1;
                            chessboard[r][c+1][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(c-1>-1){
                        if(chessboard[r][c-1][2] != 2){
                            sub1 = chessboard[r][c-1][1];
                            sub2 = chessboard[r][c-1][2];
                            chessboard[r][c-1][1] = chessboard[r][c][1];
                            chessboard[r][c-1][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 1, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r][c-1][1];
                            chessboard[r][c][2] = chessboard[r][c-1][2];
                            chessboard[r][c-1][1] = sub1;
                            chessboard[r][c-1][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                }

                // checking if bishop can move.
                if(chessboard[r][c][1] == 66){
                    if(r+1<8 && c+1<8){
                        if(chessboard[r+1][c+1][2] != 2){
                            sub1 = chessboard[r+1][c+1][1];
                            sub2 = chessboard[r+1][c+1][2];
                            chessboard[r+1][c+1][1] = chessboard[r][c][1];
                            chessboard[r+1][c+1][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 1, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r+1][c+1][1];
                            chessboard[r][c][2] = chessboard[r+1][c+1][2];
                            chessboard[r+1][c+1][1] = sub1;
                            chessboard[r+1][c+1][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(r-1>-1 && c-1>-1){
                        if(chessboard[r-1][c-1][2] != 2){
                            sub1 = chessboard[r-1][c-1][1];
                            sub2 = chessboard[r-1][c-1][2];
                            chessboard[r-1][c-1][1] = chessboard[r][c][1];
                            chessboard[r-1][c-1][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 1, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r-1][c-1][1];
                            chessboard[r][c][2] = chessboard[r-1][c-1][2];
                            chessboard[r-1][c-1][1] = sub1;
                            chessboard[r-1][c-1][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(c+1<8 && r-1>-1){
                        if(chessboard[r-1][c+1][2] != 2){
                            sub1 = chessboard[r-1][c+1][1];
                            sub2 = chessboard[r-1][c+1][2];
                            chessboard[r-1][c+1][1] = chessboard[r][c][1];
                            chessboard[r-1][c+1][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 1, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r-1][c+1][1];
                            chessboard[r][c][2] = chessboard[r-1][c+1][2];
                            chessboard[r-1][c+1][1] = sub1;
                            chessboard[r-1][c+1][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(c-1>-1 && r+1<8){
                        if(chessboard[r+1][c-1][2] != 2){
                            sub1 = chessboard[r+1][c-1][1];
                            sub2 = chessboard[r+1][c-1][2];
                            chessboard[r+1][c-1][1] = chessboard[r][c][1];
                            chessboard[r+1][c-1][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 1, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r+1][c-1][1];
                            chessboard[r][c][2] = chessboard[r+1][c-1][2];
                            chessboard[r+1][c-1][1] = sub1;
                            chessboard[r+1][c-1][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                }

                // checking if queen can move.
                if(chessboard[r][c][1] == 81){
                    if(r+1<8){
                        if(chessboard[r+1][c][2] != 2){
                            sub1 = chessboard[r+1][c][1];
                            sub2 = chessboard[r+1][c][2];
                            chessboard[r+1][c][1] = chessboard[r][c][1];
                            chessboard[r+1][c][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 1, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r+1][c][1];
                            chessboard[r][c][2] = chessboard[r+1][c][2];
                            chessboard[r+1][c][1] = sub1;
                            chessboard[r+1][c][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(r-1>-1){
                        if(chessboard[r-1][c][2] != 2){
                            sub1 = chessboard[r-1][c][1];
                            sub2 = chessboard[r-1][c][2];
                            chessboard[r-1][c][1] = chessboard[r][c][1];
                            chessboard[r-1][c][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 1, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r-1][c][1];
                            chessboard[r][c][2] = chessboard[r-1][c][2];
                            chessboard[r-1][c][1] = sub1;
                            chessboard[r-1][c][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(c+1<8){
                        if(chessboard[r][c+1][2] != 2){
                            sub1 = chessboard[r][c+1][1];
                            sub2 = chessboard[r][c+1][2];
                            chessboard[r][c+1][1] = chessboard[r][c][1];
                            chessboard[r][c+1][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 1, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r][c+1][1];
                            chessboard[r][c][2] = chessboard[r][c+1][2];
                            chessboard[r][c+1][1] = sub1;
                            chessboard[r][c+1][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(c-1>-1){
                        if(chessboard[r][c-1][2] != 2){
                            sub1 = chessboard[r][c-1][1];
                            sub2 = chessboard[r][c-1][2];
                            chessboard[r][c-1][1] = chessboard[r][c][1];
                            chessboard[r][c-1][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 1, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r][c-1][1];
                            chessboard[r][c][2] = chessboard[r][c-1][2];
                            chessboard[r][c-1][1] = sub1;
                            chessboard[r][c-1][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(r+1<8 && c+1<8){
                        if(chessboard[r+1][c+1][2] != 2){
                            sub1 = chessboard[r+1][c+1][1];
                            sub2 = chessboard[r+1][c+1][2];
                            chessboard[r+1][c+1][1] = chessboard[r][c][1];
                            chessboard[r+1][c+1][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 1, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r+1][c+1][1];
                            chessboard[r][c][2] = chessboard[r+1][c+1][2];
                            chessboard[r+1][c+1][1] = sub1;
                            chessboard[r+1][c+1][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(r-1>-1 && c-1>-1){
                        if(chessboard[r-1][c-1][2] != 2){
                            sub1 = chessboard[r-1][c-1][1];
                            sub2 = chessboard[r-1][c-1][2];
                            chessboard[r-1][c-1][1] = chessboard[r][c][1];
                            chessboard[r-1][c-1][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 1, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r-1][c-1][1];
                            chessboard[r][c][2] = chessboard[r-1][c-1][2];
                            chessboard[r-1][c-1][1] = sub1;
                            chessboard[r-1][c-1][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(c+1<8 && r-1>-1){
                        if(chessboard[r-1][c+1][2] != 2){
                            sub1 = chessboard[r-1][c+1][1];
                            sub2 = chessboard[r-1][c+1][2];
                            chessboard[r-1][c+1][1] = chessboard[r][c][1];
                            chessboard[r-1][c+1][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 1, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r-1][c+1][1];
                            chessboard[r][c][2] = chessboard[r-1][c+1][2];
                            chessboard[r-1][c+1][1] = sub1;
                            chessboard[r-1][c+1][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(c-1>-1 && r+1<8){
                        if(chessboard[r+1][c-1][2] != 2){
                            sub1 = chessboard[r+1][c-1][1];
                            sub2 = chessboard[r+1][c-1][2];
                            chessboard[r+1][c-1][1] = chessboard[r][c][1];
                            chessboard[r+1][c-1][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 1, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r+1][c-1][1];
                            chessboard[r][c][2] = chessboard[r+1][c-1][2];
                            chessboard[r+1][c-1][1] = sub1;
                            chessboard[r+1][c-1][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                }
                // -----
            }
        }
        return 1;
    }
    else if(detector == 1){
        for(int r = 0; r < 8; ++r){
            for(int c = 0; c < 8; ++c){

                if(chessboard[r][c][1] == 107){
                    // checking if king can move.
                    if(r+1<8 && r+1>-1 && c+1<8 && c+1>-1){
                        if(chessboard[r+1][c+1][2] == 1) {}
                        else {
                            if(check_position(chessboard, r+1, c+1, 2, 1) == 0) return 0;
                        }
                    }
                    if(r<8 && r>-1 && c+1<8 && c+1>-1){
                        if(chessboard[r][c+1][2] == 1) {}
                        else {
                            if(check_position(chessboard, r, c+1, 2, 1) == 0) return 0;
                        }
                    }
                    if(r-1<8 && r-1>-1 && c+1<8 && c+1>-1){
                        if(chessboard[r-1][c+1][2] == 1) {}
                        else {
                            if(check_position(chessboard, r-1, c+1, 2, 1) == 0) return 0;
                        }
                    }
                    if(r+1<8 && r+1>-1 && c-1<8 && c-1>-1){
                        if(chessboard[r+1][c-1][2] == 1) {}
                        else {
                            if(check_position(chessboard, r+1, c-1, 2, 1) == 0) return 0;
                        }
                    }
                    if(r<8 && r>-1 && c-1<8 && c-1>-1){
                        if(chessboard[r][c-1][2] == 1) {}
                        else {
                            if(check_position(chessboard, r, c-1, 2, 1) == 0) return 0;
                        }
                    }
                    if(r-1<8 && r-1>-1 && c-1<8 && c-1>-1){
                        if(chessboard[r-1][c-1][2] == 1) {}
                        else {
                            if(check_position(chessboard, r-1, c-1, 2, 1) == 0) return 0;
                        }
                    }
                    if(r+1<8 && r+1>-1 && c<8 && c>-1){
                        if(chessboard[r+1][c][2] == 1) {}
                        else {
                            if(check_position(chessboard, r+1, c, 2, 1) == 0) return 0;
                        }
                    }
                    if(r-1<8 && r-1>-1 && c<8 && c>-1){
                        if(chessboard[r-1][c][2] == 1) {}
                        else {
                            if(check_position(chessboard, r-1, c, 2, 1) == 0) return 0;
                        }
                    }
                }

                // checking if pawn can move.
                if(chessboard[r][c][1] == 112){
                    if(r+1<8){
                        if(chessboard[r+1][c][1] == 0){
                            sub1 = chessboard[r+1][c][1];
                            sub2 = chessboard[r+1][c][2];
                            chessboard[r+1][c][1] = chessboard[r][c][1];
                            chessboard[r+1][c][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 2, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r+1][c][1];
                            chessboard[r][c][2] = chessboard[r+1][c][2];
                            chessboard[r+1][c][1] = sub1;
                            chessboard[r+1][c][2] = sub2;
                            if(flag == 1) return 0;

                        }
                    }
                    if(r+1<8 && c+1<8){
                        if(chessboard[r+1][c+1][2] == 2){
                            sub1 = chessboard[r+1][c+1][1];
                            sub2 = chessboard[r+1][c+1][2];
                            chessboard[r+1][c+1][1] = chessboard[r][c][1];
                            chessboard[r+1][c+1][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 2, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r+1][c+1][1];
                            chessboard[r][c][2] = chessboard[r+1][c+1][2];
                            chessboard[r+1][c+1][1] = sub1;
                            chessboard[r+1][c+1][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(r+1<8 && c-1>-1){
                        if(chessboard[r+1][c-1][2] == 2){
                            sub1 = chessboard[r+1][c-1][1];
                            sub2 = chessboard[r+1][c-1][2];
                            chessboard[r+1][c-1][1] = chessboard[r][c][1];
                            chessboard[r+1][c-1][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 2, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r+1][c-1][1];
                            chessboard[r][c][2] = chessboard[r+1][c-1][2];
                            chessboard[r+1][c-1][1] = sub1;
                            chessboard[r+1][c-1][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                }

                // checking if night can move.
                if(chessboard[r][c][1] == 110){
                    if(r+1<8 && r+1>-1 && c+2<8 &&c+2>-1){
                        if(chessboard[r+1][c+2][2] != 1){
                            sub1 = chessboard[r+1][c+2][1];
                            sub2 = chessboard[r+1][c+2][2];
                            chessboard[r+1][c+2][1] = chessboard[r][c][1];
                            chessboard[r+1][c+2][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 2, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r+1][c+2][1];
                            chessboard[r][c][2] = chessboard[r+1][c+2][2];
                            chessboard[r+1][c+2][1] = sub1;
                            chessboard[r+1][c+2][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(r+1<8 && r+1>-1 && c-2<8 &&c-2>-1){
                        if(chessboard[r+1][c-2][2] != 1){
                            sub1 = chessboard[r+1][c-2][1];
                            sub2 = chessboard[r+1][c-2][2];
                            chessboard[r+1][c-2][1] = chessboard[r][c][1];
                            chessboard[r+1][c-2][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 2, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r+1][c-2][1];
                            chessboard[r][c][2] = chessboard[r+1][c-2][2];
                            chessboard[r+1][c-2][1] = sub1;
                            chessboard[r+1][c-2][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(r-1<8 && r-1>-1 && c+2<8 &&c+2>-1){
                        if(chessboard[r-1][c+2][2] != 1){
                            sub1 = chessboard[r-1][c+2][1];
                            sub2 = chessboard[r-1][c+2][2];
                            chessboard[r-1][c+2][1] = chessboard[r][c][1];
                            chessboard[r-1][c+2][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 2, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r-1][c+2][1];
                            chessboard[r][c][2] = chessboard[r-1][c+2][2];
                            chessboard[r-1][c+2][1] = sub1;
                            chessboard[r-1][c+2][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(r-1<8 && r-1>-1 && c-2<8 &&c-2>-1){
                        if(chessboard[r-1][c-2][2] != 1){
                            sub1 = chessboard[r-1][c-2][1];
                            sub2 = chessboard[r-1][c-2][2];
                            chessboard[r-1][c-2][1] = chessboard[r][c][1];
                            chessboard[r-1][c-2][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 2, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r-1][c-2][1];
                            chessboard[r][c][2] = chessboard[r-1][c-2][2];
                            chessboard[r-1][c-2][1] = sub1;
                            chessboard[r-1][c-2][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(r+2<8 && r+2>-1 && c+1<8 &&c+1>-1){
                        if(chessboard[r+2][c+1][2] != 1){
                            sub1 = chessboard[r+2][c+1][1];
                            sub2 = chessboard[r+2][c+1][2];
                            chessboard[r+2][c+1][1] = chessboard[r][c][1];
                            chessboard[r+2][c+1][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 2, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r+2][c+1][1];
                            chessboard[r][c][2] = chessboard[r+2][c+1][2];
                            chessboard[r+2][c+1][1] = sub1;
                            chessboard[r+2][c+1][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(r-2<8 && r-2>-1 && c+1<8 &&c+1>-1){
                        if(chessboard[r-2][c+1][2] != 1){
                            sub1 = chessboard[r-2][c+1][1];
                            sub2 = chessboard[r-2][c+1][2];
                            chessboard[r-2][c+1][1] = chessboard[r][c][1];
                            chessboard[r-2][c+1][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 2, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r-2][c+1][1];
                            chessboard[r][c][2] = chessboard[r-2][c+1][2];
                            chessboard[r-2][c+1][1] = sub1;
                            chessboard[r-2][c+1][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(r+2<8 && r+2>-1 && c-1<8 &&c-1>-1){
                        if(chessboard[r+2][c-1][2] != 1){
                            sub1 = chessboard[r+2][c-1][1];
                            sub2 = chessboard[r+2][c-1][2];
                            chessboard[r+2][c-1][1] = chessboard[r][c][1];
                            chessboard[r+2][c-1][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 2, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r+2][c-1][1];
                            chessboard[r][c][2] = chessboard[r+2][c-1][2];
                            chessboard[r+2][c-1][1] = sub1;
                            chessboard[r+2][c-1][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(r-2<8 && r-2>-1 && c-1<8 &&c-1>-1){
                        if(chessboard[r-2][c-1][2] != 1){
                            sub1 = chessboard[r-2][c-1][1];
                            sub2 = chessboard[r-2][c-1][2];
                            chessboard[r-2][c-1][1] = chessboard[r][c][1];
                            chessboard[r-2][c-1][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 2, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r-2][c-1][1];
                            chessboard[r][c][2] = chessboard[r-2][c-1][2];
                            chessboard[r-2][c-1][1] = sub1;
                            chessboard[r-2][c-1][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                }

                //checking if rook can move.
                if(chessboard[r][c][1] == 114){
                    if(r+1<8){
                        if(chessboard[r+1][c][2] != 1){
                            sub1 = chessboard[r+1][c][1];
                            sub2 = chessboard[r+1][c][2];
                            chessboard[r+1][c][1] = chessboard[r][c][1];
                            chessboard[r+1][c][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 2, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r+1][c][1];
                            chessboard[r][c][2] = chessboard[r+1][c][2];
                            chessboard[r+1][c][1] = sub1;
                            chessboard[r+1][c][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(r-1>-1){
                        if(chessboard[r-1][c][2] != 1){
                            sub1 = chessboard[r-1][c][1];
                            sub2 = chessboard[r-1][c][2];
                            chessboard[r-1][c][1] = chessboard[r][c][1];
                            chessboard[r-1][c][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 2, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r-1][c][1];
                            chessboard[r][c][2] = chessboard[r-1][c][2];
                            chessboard[r-1][c][1] = sub1;
                            chessboard[r-1][c][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(c+1<8){
                        if(chessboard[r][c+1][2] != 1){
                            sub1 = chessboard[r][c+1][1];
                            sub2 = chessboard[r][c+1][2];
                            chessboard[r][c+1][1] = chessboard[r][c][1];
                            chessboard[r][c+1][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 2, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r][c+1][1];
                            chessboard[r][c][2] = chessboard[r][c+1][2];
                            chessboard[r][c+1][1] = sub1;
                            chessboard[r][c+1][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(c-1>-1){
                        if(chessboard[r][c-1][2] != 1){
                            sub1 = chessboard[r][c-1][1];
                            sub2 = chessboard[r][c-1][2];
                            chessboard[r][c-1][1] = chessboard[r][c][1];
                            chessboard[r][c-1][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 2, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r][c-1][1];
                            chessboard[r][c][2] = chessboard[r][c-1][2];
                            chessboard[r][c-1][1] = sub1;
                            chessboard[r][c-1][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                }

                // checking if bishop can move.
                if(chessboard[r][c][1] == 98){
                    if(r+1<8 && c+1<8){
                        if(chessboard[r+1][c+1][2] != 1){
                            sub1 = chessboard[r+1][c+1][1];
                            sub2 = chessboard[r+1][c+1][2];
                            chessboard[r+1][c+1][1] = chessboard[r][c][1];
                            chessboard[r+1][c+1][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 2, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r+1][c+1][1];
                            chessboard[r][c][2] = chessboard[r+1][c+1][2];
                            chessboard[r+1][c+1][1] = sub1;
                            chessboard[r+1][c+1][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(r-1>-1 && c-1>-1){
                        if(chessboard[r-1][c-1][2] != 1){
                            sub1 = chessboard[r-1][c-1][1];
                            sub2 = chessboard[r-1][c-1][2];
                            chessboard[r-1][c-1][1] = chessboard[r][c][1];
                            chessboard[r-1][c-1][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 2, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r-1][c-1][1];
                            chessboard[r][c][2] = chessboard[r-1][c-1][2];
                            chessboard[r-1][c-1][1] = sub1;
                            chessboard[r-1][c-1][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(c+1<8 && r-1>-1){
                        if(chessboard[r-1][c+1][2] != 1){
                            sub1 = chessboard[r-1][c+1][1];
                            sub2 = chessboard[r-1][c+1][2];
                            chessboard[r-1][c+1][1] = chessboard[r][c][1];
                            chessboard[r-1][c+1][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 2, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r-1][c+1][1];
                            chessboard[r][c][2] = chessboard[r-1][c+1][2];
                            chessboard[r-1][c+1][1] = sub1;
                            chessboard[r-1][c+1][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(c-1>-1 && r+1<8){
                        if(chessboard[r+1][c-1][2] != 1){
                            sub1 = chessboard[r+1][c-1][1];
                            sub2 = chessboard[r+1][c-1][2];
                            chessboard[r+1][c-1][1] = chessboard[r][c][1];
                            chessboard[r+1][c-1][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 2, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r+1][c-1][1];
                            chessboard[r][c][2] = chessboard[r+1][c-1][2];
                            chessboard[r+1][c-1][1] = sub1;
                            chessboard[r+1][c-1][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                }

                // checking if queen can move.
                if(chessboard[r][c][1] == 113){
                    if(r+1<8){
                        if(chessboard[r+1][c][2] != 1){
                            sub1 = chessboard[r+1][c][1];
                            sub2 = chessboard[r+1][c][2];
                            chessboard[r+1][c][1] = chessboard[r][c][1];
                            chessboard[r+1][c][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 2, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r+1][c][1];
                            chessboard[r][c][2] = chessboard[r+1][c][2];
                            chessboard[r+1][c][1] = sub1;
                            chessboard[r+1][c][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(r-1>-1){
                        if(chessboard[r-1][c][2] != 1){
                            sub1 = chessboard[r-1][c][1];
                            sub2 = chessboard[r-1][c][2];
                            chessboard[r-1][c][1] = chessboard[r][c][1];
                            chessboard[r-1][c][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 2, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r-1][c][1];
                            chessboard[r][c][2] = chessboard[r-1][c][2];
                            chessboard[r-1][c][1] = sub1;
                            chessboard[r-1][c][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(c+1<8){
                        if(chessboard[r][c+1][2] != 1){
                            sub1 = chessboard[r][c+1][1];
                            sub2 = chessboard[r][c+1][2];
                            chessboard[r][c+1][1] = chessboard[r][c][1];
                            chessboard[r][c+1][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 2, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r][c+1][1];
                            chessboard[r][c][2] = chessboard[r][c+1][2];
                            chessboard[r][c+1][1] = sub1;
                            chessboard[r][c+1][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(c-1>-1){
                        if(chessboard[r][c-1][2] != 1){
                            sub1 = chessboard[r][c-1][1];
                            sub2 = chessboard[r][c-1][2];
                            chessboard[r][c-1][1] = chessboard[r][c][1];
                            chessboard[r][c-1][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 2, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r][c-1][1];
                            chessboard[r][c][2] = chessboard[r][c-1][2];
                            chessboard[r][c-1][1] = sub1;
                            chessboard[r][c-1][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(r+1<8 && c+1<8){
                        if(chessboard[r+1][c+1][2] != 1){
                            sub1 = chessboard[r+1][c+1][1];
                            sub2 = chessboard[r+1][c+1][2];
                            chessboard[r+1][c+1][1] = chessboard[r][c][1];
                            chessboard[r+1][c+1][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 2, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r+1][c+1][1];
                            chessboard[r][c][2] = chessboard[r+1][c+1][2];
                            chessboard[r+1][c+1][1] = sub1;
                            chessboard[r+1][c+1][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(r-1>-1 && c-1>-1){
                        if(chessboard[r-1][c-1][2] != 1){
                            sub1 = chessboard[r-1][c-1][1];
                            sub2 = chessboard[r-1][c-1][2];
                            chessboard[r-1][c-1][1] = chessboard[r][c][1];
                            chessboard[r-1][c-1][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 2, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r-1][c-1][1];
                            chessboard[r][c][2] = chessboard[r-1][c-1][2];
                            chessboard[r-1][c-1][1] = sub1;
                            chessboard[r-1][c-1][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(c+1<8 && r-1>-1){
                        if(chessboard[r-1][c+1][2] != 1){
                            sub1 = chessboard[r-1][c+1][1];
                            sub2 = chessboard[r-1][c+1][2];
                            chessboard[r-1][c+1][1] = chessboard[r][c][1];
                            chessboard[r-1][c+1][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 2, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r-1][c+1][1];
                            chessboard[r][c][2] = chessboard[r-1][c+1][2];
                            chessboard[r-1][c+1][1] = sub1;
                            chessboard[r-1][c+1][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                    if(c-1>-1 && r+1<8){
                        if(chessboard[r+1][c-1][2] != 1){
                            sub1 = chessboard[r+1][c-1][1];
                            sub2 = chessboard[r+1][c-1][2];
                            chessboard[r+1][c-1][1] = chessboard[r][c][1];
                            chessboard[r+1][c-1][2] = chessboard[r][c][2];
                            chessboard[r][c][1] = 0;
                            chessboard[r][c][2] = 0;
                            if(check_position(chessboard, king_r, king_c, 2, 1) == 0) flag = 1;
                            chessboard[r][c][1] = chessboard[r+1][c-1][1];
                            chessboard[r][c][2] = chessboard[r+1][c-1][2];
                            chessboard[r+1][c-1][1] = sub1;
                            chessboard[r+1][c-1][2] = sub2;
                            if(flag == 1) return 0;
                        }
                    }
                }
                // -----

            }
        }
    }
    return 1;
}