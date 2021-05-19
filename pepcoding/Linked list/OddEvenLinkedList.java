// 1. You are given a partially written LinkedList class.
// 2. You are required to complete the body of oddEven function. The function is expected to tweak the list such that all odd values are followed by all even values. The relative order of elements should not change. Also, take care of the cases when there are no odd or no even elements. Make sure to properly set head, tail and size as the function will be tested by calling addFirst and addLast.
// 3. Input and Output is managed for you.

public void oddEven(){
    // write your code here
    if(head==null){
        return;
    }
    Node prev = head;
    Node curr = head.next;
    Node oddIndex = head;
    while(curr!=null){
        if(curr.data%2!=0){
            if(oddIndex.data%2!=0 && oddIndex.next==curr){
                oddIndex = curr;
                curr = curr.next;
                continue;
            }
            prev.next = curr.next;
            if(curr == tail){
                tail = prev;
            }
            if(oddIndex.data%2==0){
                curr.next = head;
                head = curr;
                oddIndex = curr;
                curr = prev.next;
            }else{
                curr.next = oddIndex.next;
                oddIndex.next = curr;
                oddIndex = curr;
                curr = prev.next;
            }
        }else{
            prev = curr;
            curr = curr.next;
        }
    }
    
  }
