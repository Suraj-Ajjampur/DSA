//Question 1 Check if a linked list is circular, make it linear and return the head.
#include<stdio.h>
#include<stdlib.h>

//General Formatting
#define GEN_FORMAT_RESET                "0"
#define GEN_FORMAT_BRIGHT               "1"
#define GEN_FORMAT_DIM                  "2"
#define GEN_FORMAT_UNDERSCORE           "3"
#define GEN_FORMAT_BLINK                "4"
#define GEN_FORMAT_REVERSE              "5"
#define GEN_FORMAT_HIDDEN               "6"

//Foreground Colors
#define FOREGROUND_COL_BLACK            "30"
#define FOREGROUND_COL_RED              "31"
#define FOREGROUND_COL_GREEN            "32"
#define FOREGROUND_COL_YELLOW           "33"
#define FOREGROUND_COL_BLUE             "34"
#define FOREGROUND_COL_MAGENTA          "35"
#define FOREGROUND_COL_CYAN             "36"
#define FOREGROUND_COL_WHITE            "37"

//Background Colors
#define BACKGROUND_COL_BLACK            "40"
#define BACKGROUND_COL_RED              "41"
#define BACKGROUND_COL_GREEN            "42"
#define BACKGROUND_COL_YELLOW           "43"
#define BACKGROUND_COL_BLUE             "44"
#define BACKGROUND_COL_MAGENTA          "45"
#define BACKGROUND_COL_CYAN             "46"
#define BACKGROUND_COL_WHITE            "47"

#define SHELL_COLOR_ESCAPE_SEQ(X) "\x1b["X"m"
#define SHELL_FORMAT_RESET  ANSI_COLOR_ESCAPE_SEQ(GEN_FORMAT_RESET)

//If you don't do this
// //quallcomm_video_linux.c:7:5: error: unknown type name ‘NODE_t’
//     7 |     NODE_t *next;
//       |     ^~~

typedef struct NODE_s NODE_t; // Forward declaration

typedef struct NODE_s{
    int val;
    NODE_t *next;
}NODE_t;

typedef enum{
    false,
    true,
}bool;

NODE_t* circular_to_linear(NODE_t *head) {
    if(head == NULL || head->next == NULL) {
        return head; // List is empty or has only one node, no cycle.
    }
    
    NODE_t *fast = head;
    NODE_t *slow = head;
    NODE_t *entry = head;
    int isCircular = 0; // Flag to indicate if a cycle is detected.

    // Detect cycle
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) { // Cycle detected.
            isCircular = 1;
            break;
        }
    }

    // If there's a cycle, find the start of the cycle.
    if(isCircular) {
        while(slow != entry) {
            slow = slow->next;
            entry = entry->next;
        }
        
        // Now entry points to the start of the cycle.
        // If the cycle starts at head, we need to find the node before the start of the cycle to break it.
        if(entry == head) {
            // Find the node before the head in the cycle to break the cycle.
            while(fast->next != slow) {
                fast = fast->next;
            }
            fast->next = NULL; // Break the cycle.
        } else {
            // If the cycle does not start at the head, entry is at the start of the cycle.
            // Find the node before the entry to break the cycle.
            while(fast->next != entry) {
                fast = fast->next;
            }
            fast->next = NULL; // Break the cycle.
        }
    }

    return head; // Return the linearized list.
}



void Display(NODE_t *head){
    NODE_t *p = head;
    static int number = 0;
    number++;
    printf("\033[0;31m\nList list %d After linearizing\n",number);
    while(p!=NULL){
        printf("%d ->",p->val);
        p=p->next;
    }
    printf("\n\033[0m");
}

/**
 * @brief creates a circular linked list of size n
 */ 
NODE_t* create__linked_list(int n, int loop_node_index){
    //create a dummy pointing to head if size is > 0, else NULL 
    NODE_t *dummy = (NODE_t*)malloc(sizeof(NODE_t));
    NODE_t *temp_pointer = NULL;
    NODE_t* follow, *head;
    NODE_t *looping_point;
    dummy->val = 0;
    static int number = 0;
    number++;
    printf("\nList list %d Before linearizing\n",number);

    if(n == 0){
        dummy->next = NULL;
    }
    else if(n > 0){
        head = (NODE_t*)malloc(sizeof(NODE_t)); // 1 node created here
        dummy->next = head;
        follow = head;
        head->next = temp_pointer; //NULL for n =1
        head->val = 1;
        looping_point = head;
        printf("\n1 ->");
        //loop to create n-1 nodes
        for(int i=2;i<=n;i++){
            temp_pointer = (NODE_t*)malloc(sizeof(NODE_t));
            //link prev element to new temp
            follow->next = temp_pointer;
            temp_pointer->next = NULL;
            temp_pointer->val = i;
            follow = temp_pointer;
            printf("%d -> ",follow->val);
            fflush(stdout);
            //traversal
            temp_pointer = temp_pointer->next;
            //Check if it's the loop node index
            if(i == loop_node_index){
                //store the follow pointer to a pointer here
                looping_point = follow;
            }
        }
        //create the loop here
        follow->next = looping_point;
    }
    return head;
}

int main(void){
    Display(circular_to_linear(create__linked_list(5,4)));
    Display(circular_to_linear(create__linked_list(10,3)));
    Display(circular_to_linear(create__linked_list(20,5)));
    Display(circular_to_linear(create__linked_list(20,1))); //failing
    Display(circular_to_linear(create__linked_list(30,4)));
    Display(circular_to_linear(create__linked_list(12,12)));

    return 0;
}
//Question 2
//Add 2 linked lists
// https://leetcode.com/problems/add-two-numbers/description/


// Question 3
//Detect n consecutive 1's (5 in my case) in the network stream (0x1F) in 

//char input[] = {0x00, 0x01, 0x00 , 0x1F} and return bit position. return 28, 
//char input[] = {0x00, 0x01, 0xF0 , 0x1F} and return bit position. return 1610