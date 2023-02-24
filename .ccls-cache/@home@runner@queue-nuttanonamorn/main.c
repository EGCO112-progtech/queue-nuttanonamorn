#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"
#include "Queue.h"

int main(int argc , char **argv) {
  NodePtr headPtr=NULL;
  NodePtr tailPtr=NULL;
/* For struct Queue */
  Queue q;
   q.headPtr=NULL;
   q.tailPtr=NULL;
   q.size=0;
  
int i,x,cash=0,ppl=1;
for(i=1;i<argc;i++){
        if(strcmp(argv[i],"x")==0){
          printf("Customer No.%d\n",ppl);
          ppl++;
          x=dequeue_struct(&q);
          if(x>0){
          printf("You have to pay: %d\n:",x);
          while(cash<x){
            printf("Cash: ");
            scanf("%d",&cash);
          } //end while
          
          if(cash==x) 
            printf("Thank you.\n"); //end if cash
          else if (cash>x) 
            printf("Thank you.\nChange is : %d\n",cash-x); // end else if cash
          cash=0;
          } //end if x>0
          else printf("Thank you.\n");
        } // end main for if
        else {
          enqueue_struct(&q, atoi(argv[i]),atoi(argv[i+1]));
          printf("My order is: %d\n",atoi(argv[i]));
          i++;
        } // end main for else
 }
printf("=============================================\n");
if(q.size==1) printf("There is %d person left in the queue\n",q.size);
else if(q.size==0) printf("No more person left in the queue\n");
else printf("There are %d people left in the queue\n",q.size);

printf("Clearing nodes :\n");
while(q.size>0){
  printf("Customer No.%d : ",ppl);
  dequeue_struct(&q); // clear all nodes
  ppl++;
  }
printf("Node left = %d\n",q.size); // check if node is all clear
  
return 0;
}
