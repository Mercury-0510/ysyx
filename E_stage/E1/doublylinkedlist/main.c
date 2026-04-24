#include<stdio.h>
#include<malloc.h>
struct node
{
    int num;
    struct node *prev;
    struct node *next;    
};

struct node *build_ring(int);
int pick_to_kill(struct node*, int);

int main()
{
    int member, pick, result;
    struct node *ring;
    printf("member N:");
    scanf("%d", &member);
    if (member <= 0) {
        printf("invalid member\n");
        return -1;
    }
    printf("pick M to kill every time:");
    scanf("%d", &pick);
    if (pick <= 0) {
        printf("invalid pick number\n");
        return -1;
    }
    ring = build_ring(member);
    result = pick_to_kill(ring, pick);
    free(ring); // kill the last one :D
    printf("number %d person is the survivor\n", result);
    return 0;
}

struct node *build_ring(int member)
{
    struct node *ring_node;
    ring_node = malloc(sizeof(struct node));
    ring_node->num = 1;
    ring_node->next = ring_node;
    ring_node->prev = ring_node;
    struct node *head = ring_node;
    for (int i = 2; i <= member; i++) {
        ring_node->next = malloc(sizeof(struct node));
        // prev pointer
        ring_node->next->prev = ring_node;
        head->prev = ring_node->next;
        //set next node
        ring_node = ring_node->next;
        ring_node->num = i;
        ring_node->next = head;
    }
    return head;
}

int pick_to_kill(struct node* ring, int pick)
{
    for (int i = 1; ring->next != ring; i++) {
        if (i%pick == 0) {
            ring->next->prev = ring->prev;
            ring->prev->next = ring->next;
            printf("num %d is killed!\n", ring->num);
            free(ring);
            ring = ring->next;
        } else {
            ring = ring->next;
        }
    }
    return ring->num;
}