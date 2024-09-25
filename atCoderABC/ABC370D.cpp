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
    cout << W1.right << "\n";
    vector <WALL> grid;
    
    WALL* nextWallptr = nullptr;
    WALL* currentWallptr = nullptr;
    WALL currentWall;
    for (int i = 0; i < 10; i++){
        currentWall = WALL(i);
        currentWallptr = &currentWall;
        cout << "currentwallptr: " << currentWallptr << endl;
        grid.emplace_back(*currentWallptr);
        switch(i){
            case 0:
                break;
            default:
                break;
        }
    }
    cout << grid.size() << "\n";
    for (WALL p : grid){
        cout << &p << " ";
    }
    cout << endl;
    grid[3].bomb = 0;
    for (WALL p : grid){
        cout << p.bomb << " ";
    }
    cout << endl;
    for (WALL p : grid){
        cout << (&(p)) -> data << " ";
    }
    cout << endl;
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