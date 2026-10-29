module;

#include <vector>
#include <memory> 
#include <utility>

export module node;

export namespace node {
    /**
     * @brief A node which represents a possibility, and then sub possibilites within it, recursively.
     * @author Shaurya Juneja
     *  */

    struct Node {
        int value; // node's value
        std::vector<std::unique_ptr<Node>> children; // decisions that can be made from this value

        // coordinates of the cell in the grid
        std::pair<int, int> coordinates;

        // reference back to parent
        Node* parent = nullptr;

        Node(int val, int x, int y) : value(val) {
            coordinates = std::make_pair(x, y);
        };

        /**
         * @brief Adds a decision to the node (i.e. adds a child), and returns its index for future reference.`
         */
        int addChildNode(std::unique_ptr<Node> node) {
            node->parent = this;
            children.push_back(std::move(node));
            return static_cast<int>(children.size()) - 1; // returns index number
        }
        /**
         * @brief Removes a decision from the node
         */
        void removeChildNode(int index) {
            // remove child entirely
            children.erase(children.begin() + index);
        }
    };

    std::unique_ptr<Node> createNode(int value, int coordinate_x, int coordinate_y) {
        return std::make_unique<Node>(value, coordinate_x, coordinate_y);
    }

    /**
     * @brief Holds the nodes that are not children of other nodes
     * @author Shaurya Juneja
     */
}