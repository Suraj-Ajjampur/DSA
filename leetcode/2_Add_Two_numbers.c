
// * Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

//print the linked list

printf("%d",);
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    //Cases where either/both lists are empty
    if(l1 == NULL && l2 != NULL)
        return l2;
    else if(l1 != NULL && l2 == NULL)
        return l1;
    else if(l1 == NULL && l2 == NULL)
        return NULL;
    
    //init traversal nodes to respective heads
    struct ListNode *t_l1, *t_l2;
    t_l1 = l1; t_l2 = l2;

    bool carry_bit = false;

    //case where there are elements in both nodes
    while(!t_l1 && !t_l2){
        //check carry bit set
        if(carry_bit){
            t_l1->val++;
            carry_bit = false;
        }
        //add values assign in l1 list
        t_l1->val += t_l2->val;
        if(t_l1->val >= 10){
            t_l1->val %= 10;
            carry_bit = true;
        }
        //traversal
        t_l1 = t_l1->next; 
        t_l2 = t_l2->next;
    }
    //case where list1 is longer
    while(!t_l1){
        if(carry_bit){
            t_l1->val++;
            carry_bit = false;
        }
        t_l1 = t_l1->next;
    }
    //case where list2 is longer
    while(!t_l2){
        //handler carry bit set
        if(carry_bit){
            t_l2->val++;
            carry_bit = false;
        }
        //create new nodes each iteration as we are adding values in list 1
        struct ListNode *temp_l1_node = (struct ListNode*)malloc(sizeof(struct ListNode)); 
        temp_l1_node->val += t_l2->val;
        //handle overflow
        if(temp_l1_node->val >= 10){
            temp_l1_node->val %= 10;
            carry_bit = true;
        }
        temp_l1_node = temp_l1_node->next; //traversal
        t_l2 = t_l2->next;
    }
    //return l1
    return l1;
}