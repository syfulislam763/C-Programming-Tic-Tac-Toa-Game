#include <stdio.h>
typedef unsigned int Array[3][3];

void positionSetter(unsigned short index, Array board, char player);
void preventReplacing(unsigned short i,unsigned short j, Array board, char player);
int getWinner(Array board);
void ticTacToaBoard(Array board);

void main(void){
    

    
    char player;
    unsigned short index;
    Array board = {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'},
    };
    
    
    
    ticTacToaBoard(board);

    printf("Take a first turn of X or Y in the position of above box(player position): ");
    scanf("%c %hu", &player, &index);
    positionSetter(index, board, player);

    printf("\n");

    for(int i=0; i < 9; i++){
        
        ticTacToaBoard(board);
        
        int isWin = getWinner(board);

        if(isWin)break;

        if(i < 8){
            player = player == 'X'?'Y':'X';
            printf("Turn of %c (position): ", player);
            scanf("%hu", &index);
            positionSetter(index, board, player);
        }

    }

}




void positionSetter(unsigned short index, Array board, char player){
    switch(index){
        case 1:
            preventReplacing(0, 0, board, player);
            break;
        case 2:
            preventReplacing(0, 1, board, player);
            break;
        case 3:
            preventReplacing(0, 2, board, player);
            break;
        case 4:
            preventReplacing(1, 0, board, player);
            break;
        case 5:
            preventReplacing(1, 1, board, player);
            break;
        case 6:
            preventReplacing(1, 2, board, player);
            break;
        case 7:
            preventReplacing(2, 0, board, player);
            break;
        case 8:
            preventReplacing(2, 1, board, player);
            break;
        case 9:
            preventReplacing(2, 2, board, player);
            break;
        default:
            printf("Ivalid Position you Entered\n");
            
    }
}


void preventReplacing(unsigned short i,unsigned short j, Array board, char player){
    if(board[i][j] != 'X' && board[i][j] != 'Y'){
        board[i][j] = player;
    }else{
        unsigned short temp;
        printf("%c is exist in this position\n", board[i][j]);
        printf("Enter new Position: ");
        scanf("%hu", &temp);
        positionSetter(temp, board, player);
    }
}

int getWinner(Array board){
    int row1 = board[0][0] == board[0][1] && board[0][0] == board[0][2] && board[0][1] == board[0][2];
    int row2 = board[1][0] == board[1][1] && board[1][0] == board[1][2] && board[1][1] == board[1][2];
    int row3 = board[2][0] == board[2][1] && board[2][0] == board[2][2] && board[2][1] == board[2][2];

    int col1 = board[0][0] == board[1][0] && board[0][0] == board[2][0] && board[1][0] == board[2][0];
    int col2 = board[0][1] == board[1][1] && board[0][1] == board[2][1] && board[1][1] == board[2][1];
    int col3 = board[0][2] == board[1][2] && board[0][2] == board[2][2] && board[1][2] == board[2][2];

    int cros1 = board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[1][1] == board[2][2];
    int cros2 = board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[1][1] == board[2][0];

    if(row1 || col1 || cros1){
        printf("%c is winner\n\n", board[0][0]);
        return 1;
    }else if(col3 || cros2){
        printf("%c is winner\n\n", board[0][2]);
        return 1;
    }else if(row2){
        printf("%c is winner\n\n", board[1][0]);
        return 1;
    }else if(col2){
        printf("%c is winner\n", board[0][1]);
        return 1;
    }else if(row3){
        printf("%c is winner\n", board[2][0]);
        return 1;
    }


    return 0;
}

void ticTacToaBoard(Array board){
    printf("%c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("------------\n");
    printf("%c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("------------\n");
    printf("%c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}