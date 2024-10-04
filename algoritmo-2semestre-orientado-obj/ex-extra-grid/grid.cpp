#include <iostream>
#include <vector>
using namespace std;

int main()
{
    /* 1
    vector<int> grid_largada = {1, 2, 3, 4, 5}; 
    vector<int> grid_chegada = {3, 1, 2, 5, 4}; resp = 3 
    */ 

    /* 2
    vector<int> grid_largada = {3, 1, 2, 5, 4}; 
    vector<int> grid_chegada = {1, 2, 3, 4, 5}; resp = 3
    */

    vector<int> grid_largada = {3, 1, 2, 5, 4}; 
    vector<int> grid_chegada = {5, 3, 2, 1, 4}; // resp = 4

    int aux, ult = 0;
    
    for (int i = 4; i > 0; i--)
    {
        for (int j = (i-1); j >= 0; j--)
        {
            if (grid_largada.at(i) != grid_chegada.at(i))
            {
                //int n = grid_largada[i];
                //n = findKey(grid_largada, n);
                
                aux = grid_largada.at(i);
                grid_largada.at(i) = grid_largada.at(j); 
                grid_largada.at(j) = aux;
                ult++;
            }   
        }
    }
    
    for (int i = 0; i < 5; i++)
    {
        std::cout << grid_largada.at(i);
    }
   
    std::cout << endl << "Ultrapassagens: " << ult;

    grid_largada.clear();
    grid_chegada.clear();
    return 0;
}