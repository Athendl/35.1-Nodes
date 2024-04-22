#ifndef BSTCHECKER_H
#define BSTCHECKER_H

#include "Node.h"
#include <climits> // Include for INT_MIN and INT_MAX

class BSTChecker {
public:
    // Function to check the validity of the entire BST
    static Node* CheckBSTValidity(Node* rootNode) {
        // Initial call to the helper function with infinite range and no ancestor
        return CheckSubtreeValidity(rootNode, INT_MIN, INT_MAX, nullptr);
    }

private:
    // Helper function to recursively check the validity of a subtree
    static Node* CheckSubtreeValidity(Node* node, int minKey, int maxKey, Node* ancestor) {
        if (!node) {
            return nullptr; // Base case: Null node is valid
        }

        if ((node->left && node->left->key == node->key) || (node->right && node->right->key == node->key)) {
            return node; // Return if child node is linking to parent
        }

        if (ancestor && ((node->left && node->left == ancestor) || (node->right && node->right == ancestor))) {
            return node; // Return if child node is linking to ancestor
        }

        if (node->key <= minKey || node->key >= maxKey) {
            return node; // Violation: Node key out of range
        }

        // Recursively check left and right subtrees
        Node* leftViolation = CheckSubtreeValidity(node->left, minKey, node->key, ancestor ? ancestor : node);
        Node* rightViolation = CheckSubtreeValidity(node->right, node->key, maxKey, ancestor ? ancestor : node);

        // Return the first violating node found
        if (leftViolation) {
            return leftViolation;
        }
        if (rightViolation) {
            return rightViolation;
        }

        // If no violation found in this subtree, return nullptr
        return nullptr;
    }
};

#endif





