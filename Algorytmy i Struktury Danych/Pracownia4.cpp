#include <iostream>

using namespace std;

class Tree{
    private:
        struct Node{
            long val;
            int height;
            int elemsInLeft;
            int elemsInRight;
            long sumInLeft;
            long sumInRight;
            Node* left;
            Node* right;
            Node(){
                val = 0;
                height = 1;
                elemsInLeft = 0;
                elemsInRight = 0;
                sumInLeft = 0;
                sumInRight = 0;
                left = nullptr;
                right = nullptr;
            }
        };
        Node* rightRotate(Node* n){
            Node* x = n->left;
            Node* y = x->right;

            n->left = y;
            x->right = n;

            if(y) n->elemsInLeft = y->elemsInLeft + y->elemsInRight + 1;
            else n->elemsInLeft = 0;

            x->elemsInRight = n->elemsInLeft + n->elemsInRight + 1;
            n->sumInLeft = getSum(y);
            x->sumInRight = getSum(n);

            n->height = 1 + max(getHeight(n->right), getHeight(n->left));
            x->height = 1 + max(getHeight(x->right), getHeight(x->left));

            return x;
        }

        Node* leftRotate(Node* n){
            Node* x = n->right;
            Node* y = x->left;

            n->right = y;
            x->left = n;

            if(y) n->elemsInRight = y->elemsInLeft + y->elemsInRight + 1;
            else n->elemsInRight = 0;

            x->elemsInLeft = n->elemsInLeft + n->elemsInRight + 1;
            n->sumInRight = getSum(y);
            x->sumInLeft = getSum(n);

            n->height = 1 + max(getHeight(n->right), getHeight(n->left));
            x->height = 1 + max(getHeight(x->right), getHeight(x->left));

            return x;
        }

        int heightDiff(Node* r){
            if(r) return getHeight(r->right) - getHeight(r->left);
            else return 0;
        }

        void balance(Node* &r){
            int BF = heightDiff(r);
            int lBF = heightDiff(r->left);
            int rBF = heightDiff(r->right);

            if(BF > 1 && rBF >= 0){
                r = leftRotate(r);
            }
            else if(BF < -1 && lBF <= 0){
                r = rightRotate(r);
            }
            else if(BF > 1 && rBF < 0){
                r->right = rightRotate(r->right);
                r = leftRotate(r);
            }

            else if(BF < -1 && lBF > 0){
                r->left = leftRotate(r->left);
                r = rightRotate(r);
            }
        }

        int getHeight(Node* r){
            if(r) return r->height;
            else return 0;
        }

        long getSum(Node* r){
            if(r) return r->val + r->sumInLeft + r->sumInRight;
            else return 0;
        }

    public:
        Node* root;

        Tree(){
            root = nullptr;
        }

        Node* insertNode(Node* &r, long x, int p){
            if(r == nullptr){
                r = new Node;
                r->val = x;
            }
            else if(r->elemsInLeft < p){
                r->right = insertNode(r->right, x, p-r->elemsInLeft-1);
                r->elemsInRight++;
                r->sumInRight += x;
            }
            else if(r->elemsInLeft >= p){
                r->left = insertNode(r->left, x, p);
                r->elemsInLeft++;
                r->sumInLeft += x;
            }
            r->height = 1 + max(getHeight(r->left), getHeight(r->right));
            balance(r); 
            return r;
        }


        Node* deleteNode(Node* &r, int p){
            if(r){
                if(r->elemsInLeft > p){
                    r->left = deleteNode(r->left, p);
                    r->elemsInLeft--;
                    r->sumInLeft = getSum(r->left);
                }
                else if(r->elemsInLeft < p){
                    r->right = deleteNode(r->right, p-r->elemsInLeft-1);
                    r->elemsInRight--;
                    r->sumInRight = getSum(r->right);
                }
                else if(r->elemsInLeft == p){
                    if(r->left && r->right){
                        Node* temp = r->right;
                        while(temp->left){
                            temp = temp->left;
                        }
                        r->val = temp->val;
                        r->right = deleteNode(r->right, 0);
                        r->elemsInRight--;
                        r->sumInRight = getSum(r->right);
                        return r;
                    }
                    else if(r->left){
                        Node* temp = r->left;
                        r = nullptr;
                        r = temp;
                        return r;
                    }
                    else if(r->right){
                        Node* temp = r->right;
                        r = nullptr;
                        r = temp;
                        return r;
                    }
                    else{
                        delete(r);
                        return nullptr;
                    }
                }
                balance(r);
                return r;
            }
            return nullptr;
        }

        long sum(Node* &r, int p1, int p2){
            if(r){
                long result = getSum(r);
                Node* temp = r;
                
                while(temp){
                    if(p1 > temp->elemsInLeft){
                        result -= temp->sumInLeft + temp->val;
                        p1 -= temp->elemsInLeft + 1;
                        temp = temp->right;
                    }
                    else if(p1 == temp->elemsInLeft){
                        result-= temp->sumInLeft;
                        break;
                    }
                    else{
                        temp = temp->left;
                    }
                }

                temp = r;

                while(temp){
                    if(p2 < temp->elemsInLeft){
                        result -= temp->sumInRight + temp->val;
                        temp = temp->left;
                    }
                    else if(p2 == temp->elemsInLeft){
                        result-= temp->sumInRight;
                        break;
                    }
                    else{
                        p2 -= temp->elemsInLeft +1;
                        temp = temp->right;
                    }
                }
            return result;
            }
            return 0;
        }

        void printTree(Node* &r){
            if(r){
                printTree(r->left);
                cout<<"("<<r->val<<")";
                printTree(r->right);
            }
        }

        void printTreeInfo(Node* &r){
            if(r){
                printTreeInfo(r->left);
                cout<<"\nR ("<<r->val<<") has "<<r->elemsInLeft<<" elements in left and "<<r->elemsInRight<<" elements in right"<<endl;
                cout<<"R ("<<r->val<<") has "<<r->sumInLeft<<" in left and "<<r->sumInRight<<" in right"<<endl;
                printTreeInfo(r->right);
            }
        }

        
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Tree *t = new Tree;
    int n;
    cin >> n;
    char c;
    long a,b;
    int i = 0;
    while(i < n){
        cin >>c;
        if(c == 'I'){
            cin >> a >> b;
            t->insertNode(t->root, b, a);
            /*t->printTree(t->root);
            t->printTreeInfo(t->root);
            cout<<"Root: "<<t->root->val<<endl;
            cout<<endl;*/
        }
        else if(c == 'D'){
            cin >> a;
            t->deleteNode(t->root, a-1);
            /*t->printTree(t->root);
            t->printTreeInfo(t->root);
            cout<<"Root: "<<t->root->val<<endl;
            cout<<endl;*/
        }
        else if(c == 'S'){
            cin >> a >> b;
            cout<<t->sum(t->root, a-1,b-1)<<"\n";
        }
        
        i++;
    }
    delete(t);
    return 0;
}