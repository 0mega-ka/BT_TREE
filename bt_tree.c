#include <stdio.h>

struct bt_node{
    int elem;
    struct bt_node* left_child;
    struct bt_node* right_child;
};

void bt_node_create(struct bt_node* node, int node_elem){
    node->elem = node_elem;
    node->left_child = NULL;
    node->right_child = NULL;
};

void bt_insert(struct bt_node* root,struct bt_node* node){
    if(node->elem >= root->elem){
        if(node->right_child == NULL){
            node->right_child = node;
        }else{
            bt_insert(root->right_child,node);
        };
    }else{
        if(node->left_child == NULL){
            node->left_child = node;
        }else{
            bt_insert(root->left_child,node);
        };
    };
};

int bt_length(struct bt_node* root){
    if(root == NULL){
        return 0;
    };

    int left_depth = bt_length(root->left_child);
    int right_depth = bt_length(root->right_child);

    if(left_depth > right_depth){
        return left_depth;
    }
    else{
        return right_depth;
    }
}



void bt_pre_order(struct bt_node* root){

}

int main(){
    struct bt_node root_node;
    struct bt_node root_left;
    struct bt_node root_right;
    bt_node_create(&root_node,10);
    bt_node_create(&root_left,2);
    bt_node_create(&root_right,3);
    root_node.left_child = &root_left;
    root_node.right_child = &root_right;
    printf("%d \n",bt_length(root_node));
    return 0;
} 