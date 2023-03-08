#include "bst.h"

// ---------------------------------------
// Node class
// Default constructor
Node::Node() {
// TODO: Implement this
    key = 0;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
}
// Constructor
Node::Node(int in) {
// TODO: Implement this
    key = in;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
}
// Destructor
Node::~Node() {
// TODO: Implement this
    if (left) {
        delete left;
        left = nullptr;
    }
    
    if (right) {
        delete right;
        right = nullptr;
    }

}

// Add parent 
void Node::add_parent(Node* in) {
// TODO: Implement this
    this->parent = in;
}
// Add to left of current node
void Node::add_left(Node* in) {
// TODO: Implement this
    this->left = in;
}
// Add to right of current node
void Node::add_right(Node* in) {
// TODO: Implement this
    this->right = in;
}

// Get key
int Node::get_key()
{
// TODO: Implement this
    return this->key;
}
// Get parent node
Node* Node::get_parent()
{
// TODO: Implement this
    return this->parent;
}
// Get left node
Node* Node::get_left()
{
// TODO: Implement this
    return this->left;
}
// Get right node
Node* Node::get_right()
{
// TODO: Implement this
    return this->right;
}
// Print the key to ostream to
// Do not change this
void Node::print_info(ostream& to)
{
    to << key << endl;
}
// ---------------------------------------


// ---------------------------------------
// BST class
// Walk the subtree from the given node
void BST::inorder_walk(Node* in, ostream& to)
{
// TODO: Implement this
    if (in) {
        BST::inorder_walk(in->get_left(), to);
        in->print_info(to);
        BST::inorder_walk(in->get_right(), to);
    }
}
// Constructor
BST::BST()
{
// TODO: Implement this
    root = nullptr;
}
// Destructor
BST::~BST()
{
// TODO: Implement this
    if (root) {
        delete root;
        root = nullptr;
    }
}
// Insert a node to the subtree
void BST::insert_node(Node* in)
{
// TODO: Implement this
    Node *y = NULL;
    Node *x = this->root;
    while(x) {
        y = x;
        if (in->get_key() < x->get_key()) {
            x = x->get_left();
        } else {
            x = x->get_right();
        }
    }
    in->add_parent(y);
    if (!y) {
        this->root = in;
    } else if (in->get_key() < y->get_key()) {
        y->add_left(in);
    } else {
        y->add_right(in);
    }
}
// Delete a node to the subtree
void BST::delete_node(Node* out)
{
// TODO: Implement this
    Node *y = NULL;
    if (out->get_left() == nullptr) {
        this->transplant(out, out->get_right());
    } else if (out->get_right() == nullptr) {
        this->transplant(out, out->get_left());
    } else {
        y = this->get_min(out->get_right());
        if (y->get_parent() != out) {
            this->transplant(y, y->get_right());
            y->add_right(out->get_right());
            y->get_right()->add_parent(y);
        }
        this->transplant(out, y);
        y->add_left(out->get_left());
        y->get_left()->add_parent(y);
    }

    // disconnect out node from tree, so we dont free memory we need
    out->add_left(nullptr);
    out->add_right(nullptr);
    delete out;
}
// minimum key in the BST
Node* BST::tree_min()
{
// TODO: Implement this
    Node *current = this->root;
    while (current->get_left()) {
        current = current->get_left();
    }
    return current;
}
// maximum key in the BST
Node* BST::tree_max()
{
// TODO: Implement this
    Node *current = this->root;
    while (current->get_right()) {
        current = current->get_right();
    }
    return current;
}
// Get the minimum node from the subtree of given node
Node* BST::get_min(Node* in)
{
// TODO: Implement this
    Node *current = in;
    while (current->get_left()) {
        current = current->get_left();
    }
    return current;
}
// Get the maximum node from the subtree of given node
Node* BST::get_max(Node* in)
{
// TODO: Implement this
    Node *current = in;
    while (current->get_right()) {
        current = current->get_right();
    }
    return current;
}
// Get successor of the given node
Node* BST::get_succ(Node* in)
{
// TODO: Implement this
    if (in->get_right()) {
        return this->get_min(in->get_right());
    }
    Node *y = in->get_parent();
    Node *current = in;
    while (y && current == y->get_right()) {
        current = y;
        y = y->get_parent();
    }
    return y;
}
// Get predecessor of the given node
Node* BST::get_pred(Node* in)
{
// TODO: Implement this
    if (in->get_left()) {
        return this->get_max(in->get_left());
    }
    Node *y = in->get_parent();
    Node *current = in;
    while (y && current == y->get_left()) {
        current = y;
        y = y->get_parent();
    }
    return y;
}
// Walk the BST from min to max
void BST::walk(ostream& to)
{
// TODO: Implement this
    this->inorder_walk(this->root, to);
}
// Search the tree for a given key
Node* BST::tree_search(int search_key)
{
// TODO: Implement this
    Node *current = this->root;
    while (current and search_key != current->get_key()) {
        if (search_key < current->get_key()) {
            current = current->get_left();
        } else {
            current = current->get_right();
        }
    }
    return current;
}

void BST::transplant(Node* u, Node* v) {
    if (u->get_parent() == nullptr) {this->root = v;}
    else if (u == u->get_parent()->get_left()) {
        u->get_parent()->add_left(v);
    } else {u->get_parent()->add_right(v);}

    if (v) {v->add_parent(u->get_parent());}
}
// ---------------------------------------