#include "BSTree.h"

static void BSTree_recursive_node_print(BSTree_node* node, int indent, char* prefix);
static void BSTree_recursive_node_add(BSTree_node* node, int value);
static bool BSTree_recursive_node_exists(BSTree_node* node, int value);
static void BSTree_recursive_node_clean(BSTree_node* node);

BSTree* BSTree_create() {
    BSTree* tree = malloc( sizeof(BSTree) );
    BSTREE_MALLOC_CHECK(tree);

    tree->size = 0;
    tree->top = NULL;

    return tree;
}


void BSTree_clean(BSTree* tree) {
    BSTree_recursive_node_clean(tree->top);
    tree->size = 0;
    tree->top = NULL;
}


void BSTree_delete(BSTree* tree) {
    BSTree_clean(tree);
    free(tree);
}


size_t BSTree_get_size(BSTree* tree) {
    return tree->size;
}


void BSTree_add(BSTree* tree, int value) {
    if (tree->top == NULL) {
        tree->top = BSTree_node_create(value);
    }
    else {
        BSTree_recursive_node_add(tree->top, value);
    } 

    tree->size++;
}


bool BSTree_exists(BSTree* tree, int value) {
    return BSTree_recursive_node_exists(tree->top, value);
}


int BSTree_get_max(BSTree* tree) {
    BSTree_node* current_node = tree->top;
    
    while(current_node->right != NULL) {
        current_node = current_node->right;
    }

    return current_node->value;
}


int BSTree_get_min(BSTree* tree) {
    BSTree_node* current_node = tree->top;
    
    while(current_node->left != NULL) {
        current_node = current_node->left;
    }

    return current_node->value;
}


void BSTree_print_nodes(BSTree* tree) {
    BSTree_node* node = tree->top;
    
    if (node == NULL) {
        puts("Tree is empty");
        return;
    }

    BSTree_recursive_node_print(node, 0, "Top");
}


BSTree_node* BSTree_node_create(int value) {
    BSTree_node* node = malloc( sizeof(BSTree_node) );
    BSTREE_MALLOC_CHECK(node);

    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}


void BSTree_node_delete(BSTree_node* node) {
    free(node);
}


void BSTree_node_print(BSTree_node* node) {
    if (node == NULL){
        return;
    }

    printf("Value = %d. ", node->value);
    
    if (node->left) {
        printf("Left = %d. ", node->left->value);
    } 
    else {
        printf("Left = NULL. ");
    }
    
    if (node->right) {
        printf("Right = %d. ", node->right->value);
    } 
    else {
        printf("Right = NULL. ");
    }

    puts("");

}


static void BSTree_recursive_node_print(BSTree_node* node, int indent, char* prefix) {
    for (int i = 0; i < indent; i++) {
        printf(" ");
    }
    printf("%s: ", prefix);

    BSTree_node_print(node);
    
    if (node->left) {
        BSTree_recursive_node_print(node->left, indent+1, "L");
    }

    if (node->right) {
        BSTree_recursive_node_print(node->right, indent+1, "R");
    }
}


static void BSTree_recursive_node_add(BSTree_node* node, int value) { 

    if (node->value == value) {
        return;
    }

    if (node->value > value) {
        if (node->left) {
            BSTree_recursive_node_add(node->left, value);
        }
        else {
            BSTree_node* new_node = BSTree_node_create(value);
            node->left = new_node;
        }
    } 
    
    if (node->value < value) {
        if (node->right) {
            BSTree_recursive_node_add(node->right, value);
        }
        else {
            BSTree_node* new_node = BSTree_node_create(value);
            node->right = new_node;
        }
    } 

}


static bool BSTree_recursive_node_exists(BSTree_node* node, int value) {
    if (node == NULL) {
        return false;
    }

    if (node->value == value) {
        return true;
    }

    if (node->value > value) {
        return BSTree_recursive_node_exists(node->left, value);
    }

    if (node->value < value) {
        return BSTree_recursive_node_exists(node->right, value);
    }
}


static void BSTree_recursive_node_clean(BSTree_node* node) {
    if (node == NULL) {
        return;
    }
    BSTree_recursive_node_clean(node->left);
    BSTree_recursive_node_clean(node->right);
    free(node);
}
