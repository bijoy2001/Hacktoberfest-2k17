#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next;
};

struct node *ins(struct node *head,int val) {
    struct node *nw = new node;
    nw->data = val;
    nw->next = NULL;
    if(head == NULL)
        head = nw;
    else {
        struct node *tmp = head;
        while(tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = nw;
    }
    return head;
}

void display(struct node *head) {
    struct node *tmp = head;
    while(tmp->next != NULL) {
        cout<<tmp->data<<"->";
        tmp = tmp->next;
    }
    cout<<tmp->data<<"\n";
}

struct node *rvs(struct node *head) {
    struct node *pre = NULL,*cur,*nxt;
    cur = head;
    while(cur->next != NULL) {
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    cur->next = pre;
    return cur;
}

struct node *addOne(struct node *head) {
    struct node *tmp;
    head = rvs(head);
    int x,rem = 1;
    while(tmp->next != NULL) {
        x = tmp->data + rem;
        tmp->data = x%10;
        rem = x/10;
        if(!rem)
            break;
        tmp = tmp->next;
    }
    if(rem) {
        x = tmp->data + 1;
        tmp->data = x%10;
        rem = x/10;   
    }
    if(rem)
        head = ins(head,rem);   
    head = rvs(head);
    return head;
}

int main() {
    struct node *head = NULL;
    int n,i,ele;
    cout<<"Hw mny elements\n";
    cin>>n;
    cout<<"Enter elements\n";    
    for(i=1;i<=n;i++) {
        cin>>ele;    
        head = ins(head,ele);
    }
    display(head);
    head = addOne(head);
    display(head);
    return 0;
}
