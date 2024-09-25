#include <iostream>
#include <vector>

using namespace std;

struct WALL{
    int data = 0;
    int bomb = 1;
    WALL* right;
    WALL* left;
    
    WALL(int dataP = 0, WALL* rightP = nullptr){
        this->data = dataP;
        this->right = rightP;
        this->left = nullptr;
    }
};

int main(){
    int a;
    WALL W1;
    vector <WALL> grid, grid2;
    
    WALL* previousWALL = nullptr;
    WALL* nextWALL = nullptr;
    for (int i = 0; i < 10; i++){
        grid.emplace_back(WALL(i));
        switch(i){
            case 0:
                break;
            default:
                nextWALL = &(grid[i]);
                cout << nextWALL << endl;
                grid[i].left = previousWALL;
                grid[i-1].right = nextWALL;
                break;
        }
        previousWALL = &(grid[i]);
    }
    cout << endl << endl;

    cout << "references:\n";
    for (int i = 0; i < 10; i++){
        cout << &(grid[i]) << ", val: " << (&grid[i]) -> data << endl;
        cout << "p_reference: " << ((&(grid[i]))->left == nullptr ? nullptr : (&grid[i])->left) << ", p_val: " << ((&(grid[i]))->left == nullptr ? -1 : (&grid[i])->left->data) << endl;
        cout << endl;
    }
    cout << endl;

    WALL* newWALLptr = nullptr;
    WALL* newWALLptr2 = nullptr;
    WALL newWALL;
    WALL newWALL2;
    //cout << "\ngrid2:\n";
    /*
    for (int i = 0; i < 10; i++){
        newWALL = WALL(i);
        newWALL2 = WALL(i);
        newWALLptr = &newWALL;
        newWALLptr2 = &newWALL2;
        cout << newWALLptr << ", " << newWALLptr2 << "\n";
        grid2.emplace_back(*newWALLptr);
    }
    cout << "\n";

    for (WALL w : grid2){
        cout << &w << ", " << (&w)->data << "\n";
    }
    */
    //cout << &grid2 << "\n";

    /*
    for (WALL w : grid){
        cout << "reference: " << (&(w)) << "  data: " << (&w)->data << endl;
        cout << "previous reference: " << (&w)->left << ", p_data: " << ((&w)->left == nullptr ? "null" : to_string((&w)->left->data)) << endl;
        cout << "next reference: " << (&w)->right << ", n_data: " << ((&w)->right == nullptr ? "null" : to_string((&w)->right->data)) << endl << endl;
    }
    */

    /*
    cout << "bomb:\n";
    cout << grid.size() << "\n";
    for (WALL p : grid){
        cout << (&p)->bomb << endl;
    }

    for (int i = 0; i < grid.size(); i++){
        cout << &(grid[i]) << endl;
    }
    */
    
    /*
    for (int i = 0; i < 3; i++){
        cin >> a;
        if (grid[a].bomb == 1){
            grid[a].bomb = 0;
        }else{
            grid[a].right->bomb = 0;
            cout << grid[a].right->bomb << endl;
            grid[a].right = grid[a].right -> right;
        }
        for (WALL p : grid){
            cout << p.bomb << " ";
        }
    }
    */

    /*
    cout << "input:\n";
    for (int i = 0; i < 3; i++){
        cin >> a;
        if (grid[a].bomb == 1)
            grid[a].bomb = 0;
        else{
            grid[a].right->bomb = 0;
            grid[a].right = grid[a].right->right;
        }
        for (WALL w : grid){
            cout << "reference: " << (&(w)) << "  bomb: " << (&w)->bomb << endl;
            cout << "previous reference: " << (&w)->left << ", p_data: " << ((&w)->left == nullptr ? "null" : to_string((&w)->left->data)) << endl;
            cout << "next reference: " << (&w)->right << ", n_data: " << ((&w)->right == nullptr ? "null" : to_string((&w)->right->data)) << endl << endl;
        }
    }
    */
}