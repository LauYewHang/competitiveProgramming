#include <iostream>
#include <vector>

using namespace std;

struct WALL{
    int data = 0;
    WALL* right;
    WALL* left;
    
    WALL(int dataP = 0, WALL* rightP = nullptr){
        this->data = dataP;
        this->right = rightP;
        this->left = nullptr;
    }
};

int main(){
    WALL W1;
    cout << W1.right << "\n";
    vector <WALL> grid;
    
    WALL* nextWall = nullptr;
    for (int i = 0; i < 10; i++){
        if (i != 0 && i != 10-1){
            grid.emplace_back(WALL(i, nextWall));
            nextWall = &grid[i];
        }else{
            grid.emplace_back(WALL());
            nextWall = &grid[i];
        }
    }
    cout << grid.size() << "\n";
    for (WALL p : grid){
        cout << p.right << " ";
    }
}