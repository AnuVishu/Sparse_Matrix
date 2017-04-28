#include <bits/stdc++.h>
#include <debug/debug.h>
using namespace std;

int main() {

    int row;
    int col;

    cout << "enter the row ";
    cin >> row;

    cout << endl << "enter the column ";
    cin >> col;
    cout << endl;

    int mat[row][col];
    int cntr=0;
    int non_zero;

    cout << "enter the elements of the sparse matrix" << endl;
    for(int i=0 ; i<row ; ++i)
        for(int j=0; j<col ; ++j)
            cin >> mat[i][j];


    for(int i=0 ; i<row ; ++i){
        for(int j=0 ;j<col; ++j)
            cout << "| " << mat[i][j] << " ";
        cout << endl;
    }

    cout << "the total no of elements in the matrix is " << row*col << endl;

    for(int i=0 ; i<row ; ++i)
        for(int j=0 ; j<col ; ++j){
            if(mat[i][j] == 0) {
                cntr++;
            }
        }


    cout << "the total no fo 0's in the matrix are " << cntr << endl;
    non_zero = ((row*col)-cntr);
    cout << "total no of non zeros in the matrix is " << non_zero << endl;

    if(non_zero < cntr){
        cout << endl << "**suitable for sparse matrix**" << endl;
        cout << endl << "Do you want to proceed? (y/n) ";
    char usr_choice;
    cin >> usr_choice;
    int temp=0;


    if(usr_choice == 'y' || usr_choice == 'Y'){
        cout << "loading....." << endl << endl;

        int sprse_mat[non_zero][3];
        int row_count=0;
        int col_count=0;

        for(int i=0 ; i<row ; ++i){
            for(int j=0 ; j<col ; ++j) {
                if(mat[i][j] != 0){
                    col_count++;
                    break;
                }
            }
            for(int k=0 ; k<col ; ++k) {
                if(mat[k][i] != 0){
                    row_count++;
                    break;
                }
            }
        }
        cout << "row-> "<< row_count << endl <<"column-> "<< col_count << endl;

        //INITIALIZING THE INITIAL KNOWN VALUES
        sprse_mat[0][0] = row_count;
        sprse_mat[0][1] = col_count;
        sprse_mat[0][2] = non_zero;

        int cnt=1;

        for(int i=0 ; i<row ; ++i){
            for(int j=0 ; j<col ; ++j){

                if(mat[i][j] != 0){
                    sprse_mat[cnt][0] = i;
                    sprse_mat[cnt][1] = j;
                    sprse_mat[cnt][2] = mat[i][j];
                    cnt++;
                }
            }
        }


        //OUTPUT.....
        cout << "Sparse matrix of the above matrix is "<<endl;
        for(int i=0 ; i<=non_zero ; ++i){
            for(int j=0 ; j<3 ; ++j) {
                cout << sprse_mat[i][j] << " ";
            }
            cout << endl;
        }

    }
    else if(usr_choice == 'n' || usr_choice == 'N')
        exit(0);

    }
    else{

        cout << endl << "**not suitable for the sparse matrix**" << endl;
    }
}
