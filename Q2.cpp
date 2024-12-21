Given the head of a linked list and an integer val, remove all the nodes of the 
linked list that has Node.val == val, and return the new head. 
 #include <iostream> using 
using namespace std;
struct 
ListNode {  
int val;  
ListNode* next;  
ListNode(int x) : val(x), next(nullptr) {}  
};  
ListNode* removeElements(ListNode* head, int val) 
{     ListNode* dummy = new ListNode(0);      
dummy->next = head;  
ListNode* current = dummy;  
while (current->next != nullptr) {         
(current->next->val == val) 
{             
current->next = 
current->next->next;   
} else {             
current->next;   
current = 
if 
}  
}  
ListNode* newHead = dummy->next;     
delete dummy;      return newHead;  
}  
void printList(ListNode* head) 
{     while (head != nullptr) 
{         
cout << head->val << " ";         
head = head->next;  
}  
cout << endl;  
}  
int main() {     int n, val;     cout << 
"Enter the number of nodes: ";     cin >> 
n;  
ListNode* head = nullptr;     ListNode* tail = 
nullptr;     
cout << "Enter the elements of the 
linked list: ";     for (int i = 0; i < n; i++) {         int 
nodeVal;         cin >> nodeVal;  
        ListNode* newNode = new ListNode(nodeVal);         if (head == nullptr) 
{             head = newNode;             tail = newNode;  
        } else 
{             tail->next = 
newNode;             tail = 
newNode;  
        }  
    }  
    cout << "Enter the value to remove: ";     
cin >> val;     head = 
removeElements(head, val);     cout << 
"Linked list after removal: ";     
printList(head);     return 0;  
}
