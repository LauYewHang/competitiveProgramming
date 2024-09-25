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
        grid.emplace_back(WALL(i));
        nextWall = &grid[i];
        switch(i){
            case 0:
                break;
            default:
                grid[i-1].right = nextWall;
                break;
        }
    }
    cout << grid.size() << "\n";
    for (WALL p : grid){
        cout << (p.right)->data << " ";
    }
}