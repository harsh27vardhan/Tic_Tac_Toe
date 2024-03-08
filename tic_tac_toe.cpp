#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
bool isWon(vector<vector<char>>& mat , char a){
    if((mat[0][0]==a&&mat[0][1]==a&&mat[0][2]==a) ||
    (mat[1][0]==a&&mat[1][1]==a&&mat[1][2]==a) ||
    (mat[2][0]==a&&mat[2][1]==a&&mat[2][2]==a) ||
    (mat[0][0]==a&&mat[1][0]==a&&mat[2][0]==a) ||
    (mat[0][1]==a&&mat[1][1]==a&&mat[2][1]==a) ||
    (mat[0][2]==a&&mat[1][2]==a&&mat[2][2]==a) ||
    (mat[0][0]==a&&mat[1][1]==a&&mat[2][2]==a) ||
    (mat[0][2]==a&&mat[1][1]==a&&mat[2][0]==a)) return true;
    return false;
}
int main(){
    vector<vector<char>> mat(3,vector<char>(3,' '));
    vector<vector<int>> v(3,vector<int> (3,0));
    for(int i=0;i<3;i++){
        cout<<"-----------------"<<endl;
        for(int j=0;j<3;j++){
            cout<<"| "<<mat[i][j]<<" | ";
        }
        cout<<endl<<"-----------------"<<endl;
    }
    int turn=1;
    int k;
    for(k=0;k<9;k++){
        int row,col;
        cout<<"Enter the index in which you want to put your make. (0-Based)"<<endl;
        cin>>row>>col;
        if(mat[row][col]!=' ' || row>2 || col>2 || row<0 || col<0){
            cout<<"Plese enter a valid position."<<endl;
            break;
        }
        else{
            if(turn%2){
                mat[row][col]='X';
                v[row][col]=turn;
                for(int i=0;i<3;i++){
                cout<<"-----------------"<<endl;
                for(int j=0;j<3;j++){
                    cout<<"| "<<mat[i][j]<<" | ";
                }
                cout<<endl<<"-----------------"<<endl;
            }
                if(isWon(mat,'X')){
                    cout<<"Player 1 Won the Match."<<endl;
                    break;
                }
                turn=2; // Next turn will be Player 2's
            }
            else{
                mat[row][col]='O';
                v[row][col]=turn;
                for(int i=0;i<3;i++){
                    cout<<"-----------------"<<endl;
                    for(int j=0;j<3;j++){
                        cout<<"| "<<mat[i][j]<<" | ";
                    }
                    cout<<endl<<"-----------------"<<endl;
                }
                if(isWon(mat,'O')){
                    cout<<"Player 2 Won the Match."<<endl;
                    break;
                }
                turn=1; // Next turn will be Player 1's
            }
            if(k==8)    cout<<"It's a tie."<<endl;
        }
    }
    cout<<"Thanks for Playing."<<endl;
    return 0;
}
