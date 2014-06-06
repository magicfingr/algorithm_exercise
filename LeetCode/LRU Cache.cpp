/*
用带空的头指针和空的尾指针的双向链表
可以考虑加hash，加速查找
*/
class LRUCache{
public:
    LRUCache(int capacity): capacity(capacity), size(0) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        //查找
        Node *p = search(key);
        //找到则调整节点位置
        if(p != tail){
            int value = p->value;
            adjustNode(p);
            return value;
        } else
            return -1;
    }
    
    void set(int key, int value) {
        //查找
        Node *p = search(key);
        //找到则直接设值，并调整节点位置
        if(p != tail){
            p->value = value;
            adjustNode(p);
            return;
        }
        //未找到：
        //若还有多余空间，则在链表头插入新节点
        if(size < capacity){
            insertHead(key, value);
        } else{ //无多余空间，则删除链表尾节点，并在链表头插入新节点
            deleteTail();
            insertHead(key, value);
        }
    }
private:
    struct Node{
        int key;
        int value;
        Node* next;
        Node* pre;
        Node(int key, int value): key(key), value(value), next(NULL), pre(NULL){}
    };
    
    int capacity;
    int size;
    Node* head; //空的头结点
    Node* tail; //空的尾节点
    
    /*
    找不到则返回tail
    */
    Node* search(int key){
        Node *p = head->next;
        while(p != tail && p->key != key)
            p = p->next;
        return p;
    }
    
    /*
    将节点调整到链表头部
    仅调整，节点的地址不会改变
    */
    void adjustNode(Node *node){
        node->pre->next = node->next;
        node->next->pre = node->pre;
        
        node->pre = head;
        node->next = head->next;
        head->next->pre = node;
        head->next = node;
    }
    
    void insertHead(int key, int value){
        Node* newNode = new Node(key, value);
        newNode->pre = head;
        newNode->next = head->next;
        head->next->pre = newNode;
        head->next = newNode;
        
        size++;
    }
    
    void deleteTail(){
        Node *p = tail->pre;
        tail->pre = p->pre;
        p->pre->next = tail;
        delete p;
        
        size--;
    }
};