#include<iostream>
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn = 'x';
int row,column;
bool draw= false;
using namespace std;
void display_board(){
    system("cls");
  cout<<"\n\n\tWELCOME TO NITISH GAMING \n";
    cout<<"\tplayer1 [X] \n \tplayer2 [O] \n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t "<<board[0][0]<<"   | "<<board[0][1]<<"   | "<<board[0][2]<<"   \n";
    cout<<"\t\t-----|-----|-----\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t "<<board[1][0]<<"   | "<<board[1][1]<<"   | "<<board[1][2]<<"   \n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t-----|-----|-----\n";
    cout<<"\t\t "<<board[2][0]<<"   | "<<board[2][1]<<"   | "<<board[2][2]<<"   \n";
    cout<<"\t\t     |     |     \n";
}
   void player_turn(){
       int choice;

       if(turn== 'x')
       cout<<"\n\tplayer1[x]turn";

        if(turn== 'o')
       cout<<"\n\tplayer2[o]turn";
       cin>>choice;
    switch(choice)
    {
        case 1:
        row =0; column =0; break;
        case 2:
        row =0; column =1; break;
        case 3:
        row =0; column =2; break;
        case 4:
        row =1; column =0; break;
        case 5:
        row =1; column =1; break;
        case 6:
        row =1; column =2; break;
        case 7:
        row =2; column =0; break;
        case 8:
        row =2; column =1; break;
        case 9:
        row =2; column =2; break;

        default:
            cout<<"invalid choice\n";
            break;
    }
    if(turn =='x' && board[row][column]!='x' && board[row][column]!='o')
    {
        board[row][column]='x';
        turn = 'o';
    }
    else if(turn =='o' && board[row][column]!='x' && board[row][column]!='o')
    {
        board[row][column]='o';
        turn = 'x';
    }
        else
        {
            cout<<"box already filled\n please try again!!\n\n";
            player_turn();
        }
        display_board();
        }
        bool gameover(){
            for(int i=0; i<3; i++)
                if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
                return false;
                if(board[0][0] == board[1][1] && board[0][0]==board[2][2] || board[0][2]==board[1][1] && board[0][2]==board[2][0])
                    return false;

               for(int i=0; i<3; i++)
                for(int j=0; j<3; j++)
                if(board[i][j] != 'x' && board[i][j] != 'o')
                return true;
                draw = true;
                return false;

        }

 main()
{
     while(gameover()){
     display_board();
     player_turn();
     gameover();

      }
    if(turn='x'&& draw == false)
        cout<<"player2[o]wins!! coungratulation\n";
   else if(turn='o'&& draw == false)
    cout<<"player1[x]wins!! coungratulation\n";
    else
        cout<<"gamedraw!!\n";

}
