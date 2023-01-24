int checkmate(int chessboard[8][8][3],int piece, int r, int c, int r2, int c2, int detector){


    int i, j;
    if(detector == 2){
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

            // check if threatening piece can be eaten.
            if(check_position(chessboard, r2, c2, 2, 1) == 1) return 0;
            if(check_position(chessboard, r2, c2, 2, 1) == 2){
                if(check_position(chessboard, r2, c2, 1, 1) == 0) return 0;
            }

            // check if threatening path can be blocked by rook or queen.
            if(piece == 114 || piece == 113){
                if(r2 > r){
                    for(int i = r + 1; i < r2; ++i){
                        if(check_position(chessboard, i, c, 2, 2) == 1) return 0;
                    }
                }
                if(r2 < r){
                    for(int i = r - 1; i > r2; --i){
                        if(check_position(chessboard, i, c, 2, 2) == 1) return 0;
                    }
                }
                if(c2 > c){
                    for(int i = c + 1; i < c2; ++i){
                        if(check_position(chessboard, r, i, 2, 2) == 1) return 0;
                    }
                }
                if(c2 < c){
                    for(int i = c - 1; i > c2; --i){
                        if(check_position(chessboard, r, i, 2, 2) == 1) return 0;
                    }
                }
            }

            //check if threatening path can be blocked by bishop or queen.
            if(piece == 98 || piece == 113){

                if(r2 > r && c2 > c){
                    for(i=r+1 , j=c+1; i<r2 && j<c2; ++i, ++j){
                        if(check_position(chessboard, i, j, 2, 2) == 1) return 0;
                    }
                }
                if(r2 > r && c2 < c){
                    for(i=r+1 , j=c-1; i<r2 && j>c2; ++i, --j){
                        if(check_position(chessboard, i, j, 2, 2) == 1) return 0;
                    }
                }
                if(r2 < r && c2 > c){
                    for(i=r-1 , j=c+1; i>r2 && j<c2; --i, ++j){
                        if(check_position(chessboard, i, j, 2, 2) == 1) return 0;
                    }
                }
                if(r2 < r && c2 < c){
                    for(i=r-1 , j=c-1; i>r2 && j>c2; --i, --j){
                        if(check_position(chessboard, i, j, 2, 2) == 1) return 0;
                    }
                }
            }

    }else if(detector == 1){
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

            // check if threatening piece can be eaten.
            if(check_position(chessboard, r2, c2, 1, 1) == 1) return 0;
            if(check_position(chessboard, r2, c2, 1, 1) == 2){
                if(check_position(chessboard, r2, c2, 2, 1) == 0) return 0;
            }

            // check if threatening path can be blocked by rook or queen.
            if(piece == 82 || piece == 81){
                if(r2 > r){
                    for(int i = r + 1; i < r2; ++i){
                        if(check_position(chessboard, i, c, 1, 2) == 1) return 0;
                    }
                }
                if(r2 < r){
                    for(int i = r - 1; i > r2; --i){
                        if(check_position(chessboard, i, c, 1, 2) == 1) return 0;
                    }
                }
                if(c2 > c){
                    for(int i = c + 1; i < c2; ++i){
                        if(check_position(chessboard, r, i, 1, 2) == 1) return 0;
                    }
                }
                if(c2 < c){
                    for(int i = c - 1; i > c2; --i){
                        if(check_position(chessboard, r, i, 1, 2) == 1) return 0;
                    }
                }
            }
            //check if threatening path can be blocked by bishop or queen.
            if(piece == 66 || piece == 81){

                if(r2 > r && c2 > c){
                    for(i=r+1 , j=c+1; i<r2 && j<c2; ++i, ++j){
                        if(check_position(chessboard, i, j, 1, 2) == 1) return 0;
                    }
                }
                if(r2 > r && c2 < c){
                    for(i=r+1 , j=c-1; i<r2 && j>c2; ++i, --j){
                        if(check_position(chessboard, i, j, 1, 2) == 1) return 0;
                    }
                }
                if(r2 < r && c2 > c){
                    for(i=r-1 , j=c+1; i>r2 && j<c2; --i, ++j){
                        if(check_position(chessboard, i, j, 1, 2) == 1) return 0;
                    }
                }
                if(r2 < r && c2 < c){
                    for(i=r-1 , j=c-1; i>r2 && j>c2; --i, --j){
                        if(check_position(chessboard, i, j, 1, 2) == 1) return 0;
                    }
                }
            }
    }
    return 1;
}