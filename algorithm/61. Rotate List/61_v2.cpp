if(!head || k==0) return head;
        ListNode res(0);
        res.next = head;
        int len = 0;
        ListNode *fast = &res, *slow = &res;
        while(fast->next)
        {
            len++;
            fast=fast->next;
        }
        fast=&res;
        k%=len;
        cout<<k;
        while(k-->0)    
        {
            fast = fast->next;
        }
        while(fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = res.next;
        res.next = slow->next;
        slow->next = NULL;
        return res.next;
