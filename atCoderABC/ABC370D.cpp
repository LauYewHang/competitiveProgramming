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
    vector <WALL> grid;
    
    WALL* previousWALL = nullptr;
    for (int i = 0; i < 10; i++){
        grid.emplace_back(WALL(i));
        previousWALL = &(grid[i]);
        switch(i){
            case 0:
                break;
            default:
                grid[i].left = previousWALL;
        }
    }

    for (WALL w : grid){
        cout << "reference: " << (&(w)) << "  data: " << (&w)->data << endl;
        cout << "previous reference: " << (&w)->left << endl;
    }

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
}