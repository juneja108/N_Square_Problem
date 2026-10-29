#include <string>
#include <print>
#include <iostream>
#include <sstream>
#include <vector>
#include <utility>
#include <optional>
#include <algorithm>

import node;
import S;
import grid;

/**
 * @breif Recursive function that rewrites the grid from the given node
 * @author Shaurya Juneja
 * @param node the node for which the grid needs to be updated
 * @param grid
 * @param editedCoordinates do not use this parameter! used internally for recursion!
 * @return void
 */
void rewriteGridFromNode(grid::Grid* grid, node::Node* node, std::optional<std::vector<std::pair<int, int>>> editedCoordinates = std::nullopt) {
    // set the value at (x,y) to value in the grid
    grid->set(node->coordinates.first, node->coordinates.second, node->value);

    // list for later so that the function does not reset the edited coordinates
    // create the list
    if (editedCoordinates == std::nullopt) {
        editedCoordinates = std::vector<std::pair<int, int>> {node->coordinates};
    }
    // list already exists, so add the current coordinates to the list
    else {
        editedCoordinates->push_back(std::make_pair(node->coordinates.first, node->coordinates.second));
    }

    // only the parent node will not have a parent it points to, so the parent node's parent is nullptr
    if (node->parent != nullptr) {
        return rewriteGridFromNode(grid, node->parent, editedCoordinates);
    }
    else {
        // for every row
        for (int i = 0; i < grid->size; i++){
            // for every column
            for (int j = 0; j < grid->size; j++) {
                // is the pair in the list of coordinates to not reset?
                auto iterator = std::find(editedCoordinates.begin(), editedCoordinates.end(), std::make_pair(i, j));
                if (iterator == editedCoordinates.end()) {
                    grid->set(i, j, 0);
                }
            }
        }
    }
}

int main() { 
    // get n
    std::string nString; 
    std::getline(std::cin, nString); 
    const int n = std::stoi(nString); 

    // input validation on n
    if(n <= 0)  {
        std::println("n must be a positive integer!");
        return 0;
    }

    // determine if n has solutions
    if (!S::S(n)) { 
        std::println("n = {} has no solutions.", nString); 
        return 0;
    }

    auto grid = grid::createGrid(n);

    // a 1 can be placed anywhere on the grid in the beginning
    auto root = node::createNode(0, 0, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            root->addChildNode(node::createNode(1, i, j));
        }
    }

    rewriteGridFromNode(grid.get(), root->children[2].get());

    grid->deepPrint();

    return 0;
}