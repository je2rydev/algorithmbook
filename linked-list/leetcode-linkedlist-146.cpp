/*
146. LPU Cache
TimeLimit
2 hours
*/

// class LRUCache {
// private:
//     struct cacheNode{
//         int key=-1;
//         int value=-1;
//         cacheNode* prev= NULL;
//         cacheNode* next= NULL;
//     };
//     int capacity=0;
//     int countNode=0;
//     cacheNode* head = NULL;
//     cacheNode* tail = NULL;
    
//     bool isFull(){
//         if(this->capacity <= countNode)
//             return true;
//         return false;
//     }

//     cacheNode* searchKey(int key){
//         cacheNode* cur = head->next;
//         while(cur!=NULL){
//             if(cur->key==key)
//                 return cur;
//             cur = cur->next;
//         }
//         return NULL;
//     };

// public:
//     LRUCache(int capacity) {
//         this->capacity = capacity;
//         head = new cacheNode();
//         head->next = NULL;
//         tail = head;
//     }
    
//     int get(int key) {
//         // search key in linkedlist
//         cacheNode* keyNode = searchKey(key);
//         if(keyNode != NULL){
//             if(keyNode == tail){
//                 return keyNode->value;
//             }
//             cacheNode* temp = keyNode->prev;
//             keyNode->prev->next = keyNode->next;
//             keyNode->next->prev = temp;
//             tail->next = keyNode;
//             keyNode->prev = tail;
//             tail = keyNode;
//             tail->next = NULL;
//             return keyNode->value;
//         }
//         return -1;
//     }
    
//     void put(int key, int value) {
//         cacheNode* keyNode = searchKey(key);
//         if(keyNode != NULL){
//             keyNode->value = value;
//             if(keyNode == tail){
//                 return;
//             }
//             cacheNode* temp = keyNode->prev;
//             keyNode->prev->next = keyNode->next;
//             keyNode->next->prev = temp;
//             tail->next = keyNode;
//             keyNode->prev = tail;
//             tail = keyNode;
//             tail->next = NULL;
//             return;
//         }
//         if(isFull()){
//             // delete
//             cacheNode* delNode = head->next;
//             if(this->capacity==1){
//                 head->next = NULL;
//             }else{
//                 head->next = head->next->next;
//                 head->next->prev = head;
//             }
//             delete(delNode);
//         }
//         cacheNode* cur = new cacheNode();
//         cur->key = key;
//         cur->value = value;
//         if(this->capacity==1){
//             head->next = cur;
//         }else{
//             tail->next = cur;
//             cur->prev = tail;
//         }
//         cur->next = NULL;
//         tail = cur;
//         countNode++;
//     }
// };

class LRUCache {
public:
    class node{
      public:
        int key;
        int data;
        node *next;
        node *prev;
        node(int _key,int _data)
        {
            key = _key;
            data = _data;
        }
    };
    //End points of the dll
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    
    unordered_map<int, node*> ump;
    int size;
    
    LRUCache(int capacity) {
        size=capacity;
        head->next = tail;
        tail->next = head;
    }
    //Appending node
    void addNode(node *newNode) {
        node *temp = head->next;
        newNode->prev = head;
        newNode->next = temp;
        head->next = newNode;
        temp->prev = newNode;
    }
    //Deleting node from tail
    void deleteNode(node *delNode)
    {
        node *pr = delNode->prev;
        node *nxt = delNode->next;
        pr->next = nxt;
        nxt->prev = pr;
    }
    
    int get(int _key) {
        if(ump.find(_key)!=ump.end())
        {
            node *temp = ump[_key];
            int res = temp->data;
            ump.erase(_key);
            deleteNode(temp);
            addNode(temp);
            ump[_key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int _key, int value) {
        if(ump.find(_key)!=ump.end())
        {
            //update
            node *temp = ump[_key];
            ump.erase(_key);
            deleteNode(temp);
        }
        else if(ump.size()==size){
            //delete
            ump.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        node *newNode = new node(_key,value);
        addNode(newNode);
        ump[_key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */