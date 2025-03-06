#include <iostream>
using namespace std;

struct Node{
    Node *left;
    int data;
    Node *right;
};  


template <typename T>
class Circular_Queue{
    private:
        int size;
        int f;
        int r;
        T** Q;
    public:
    Circular_Queue(int size){
        this->size = size;
        this->f = 0;
        this->r = 0;
        this->Q = new T*[this->size];
    }
    bool Circular_is_full(){
        if((this->r + 1) % this->size == this->f){
            return true;
        }
        else{
            return false;
        }
    }
    bool Circular_is_empty(){
        if(this->r == this->f){
            return true;
        }
        else{
            return false;
        }
    }
    void Circular_Enqueue(T* val){
        if(this->Circular_is_full()){
            cout << "Queue is Full" << endl;
        }
        else{
            this->r = (this->r+1)%this->size ;
            this->Q[this->r] =  val;
        }
    }
    T* Circular_Dequeue(){
        if(this->Circular_is_empty() == true){
            cout << "Queue is Empty" << endl;
            return NULL;
        }
        this->f = (this->f+1)%this->size ;
        return(this->Q[this->f]);
    }
    T* last(){
        if(this->Circular_is_empty() == true){
            cout << "Queue is Empty" << endl;
            return NULL;
        }
        else{
            return this->Q[this->r];
        }
    }
    T* first(){
        if(this->Circular_is_empty() == true){
            cout << "Queue is Empty" << endl;
            return NULL;
        }
        else{
            return this->Q[this->f+1];
        }
    }
};

class Tree{
    private:
    Node *root;
    public:
    Tree(){
        this->root = NULL;
    }
    Node* Create_Tree(int val){
        Node *p,*t;
        int x;
        Circular_Queue<Node> *q = new Circular_Queue<Node>(100);
        cout << "Enter Root Value : ";
        cin >> x;
        this->root = new Node();
        this->root->data = x;
        this->root->left =  NULL;
        this->root->right = NULL;
        q->Circular_Enqueue(this->root);

        while (q->Circular_is_empty() != true)
        {
            p = q->Circular_Dequeue();
            cout << "Enter Left Child of " << p->data << ": ";
            cin >> x;
            if(x!= -1){
                t =  new Node();
                t->data = x;
                t->left = NULL;
                t->right =  NULL;
                p->left = t;
                q->Circular_Enqueue(t);
            }
            cout << "Enter Right Child " << p->data << ": ";
            cin >> x;
            if(x!= -1){
                t =  new Node();
                t->data = x;
                t->left = NULL;
                t->right =  NULL;
                p->right = t;
                q->Circular_Enqueue(t);
        }
    }
    return this->root;
}
void Inorder(Node *node){
    if (node == NULL) {
        return;
    }
    Inorder(node->left);
    cout << node->data << " ";
    Inorder(node->right);
}
void Postorder(Node *node){
    if (node == NULL) {
        return;
    }
    Postorder(node->left);
    Postorder(node->right);
    cout << node->data << " ";
}
void Preorder(Node *node){
    if (node == NULL) {
        return;
    }
    cout << node->data << " ";
    Preorder(node->left);
    Preorder(node->right);
}
};

class BST{
    private:
    Node *root;
    public:
    BST(){
        this->root = NULL;
    }
    Node * get_root(){
        return this->root;
    }
    void Insert(int val){
        Node *r,*p;
        if(this->root ==  NULL){
            Node *p = new Node();
            p->data = val;
            p->left = p->right = NULL;
            root=p;
            return;
        }
        Node *temp = this->root;
        while (temp != NULL)
        {
            r = temp;
            if(val < temp->data){
                temp = temp->left;
            }
            else if(val > temp->data){
                temp = temp->right;
            }
            else{
                return;
            }
        }
            p = new Node();
            p->data = val;
            p->left = p->right = NULL;
            if(val < r->data){
                r->left =p;
            }
            else{
                r->right=p;
            }
    }
    void Inorder(Node* root){
        Node *node = root;
        if (node == NULL) {
            return;
        }
        Inorder(node->left);
        cout << node->data << " ";
        Inorder(node->right);
    }
    Node * Search(int val){
        Node *temp = this->root;
        while (temp != NULL)
        {
            if(val == temp->data){
                return temp;
            }
            else if(val < temp->data){
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }
        return NULL;
    }


    int Height(Node *p){
        int x,y;
        if(p ==  NULL){
            return 0;
        }
        x = Height(p->left);
        y =  Height(p->right);
        return(x>y?x+1:y+1);
    }

    Node * Inorder_Pre(Node *p){
        while (p && p->right != NULL)
        {
            p = p->right;
        }
        return p;
    }

    Node * Inorder_Suc(Node *p){
        while (p && p->left != NULL)
        {
            p = p->left;
        }
        return p;
    }

    Node *Delete(Node *root,int val){
        Node *temp = root;
        if(temp == NULL){
            return NULL;
        }
        if(temp->left ==  NULL && temp->right == NULL){
            if(temp == root){
                temp = NULL;
            }
            free(temp);
            return temp;
        }
        if(val < temp->data){
            temp->left =  Delete(temp->left,val);
        }
        else if(val > temp->data){
            temp->right =  Delete(temp->right,val);
        }
        else{
            if(this->Height(temp->left) > this->Height(temp->right)){
                Node *q = Inorder_Pre(temp->left);
                temp->data = q->data;
                temp->left= Delete(temp->left,val);
            }
            else{
                Node *q = Inorder_Suc(temp->right);
                temp->data = q->data;
                temp->right= Delete(temp->right,val);
            }
        }
        return temp;
    }
};

int main(){
    // Tree *t = new Tree();
    // Node *root = t->Create_Tree(10);
    // t->Preorder(root);
    // cout << endl;
    // t->Postorder(root);
    // cout << endl;
    // t->Inorder(root);
    // cout << endl;

    BST *t1 = new BST();
    t1->Insert(10);
    t1->Insert(5);
    t1->Insert(20);
    t1->Insert(8);
    t1->Insert(30);
    // t1->Inorder(t1->get_root());
    // cout << (t1->Search(20))->data << endl;
    t1->Delete(t1->get_root(),5);
    t1->Inorder(t1->get_root());

    return 0;
}