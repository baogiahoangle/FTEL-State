struct ListNode* removeElements(struct ListNode* head, int val) {
    while(head != NULL && head->val == val)
    {
        head = head->next;
    }

    struct ListNode* head_copy = head;

    while(head_copy != NULL && head_copy->next != NULL)
    {
        if(head_copy->next->val == val)
        {
            head_copy->next = head_copy->next->next;
        }
        else
        {
            head_copy = head_copy->next;
        }
    }
    return head;
}