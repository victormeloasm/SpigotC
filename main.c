#include <stdio.h>
#include <stdlib.h>

int DEBUG = 0;

void spigot(int n)
{

    int ft=0,len = (10 * n / 3) + 2;  // Corrected formula
    int *queue, *buffer;
    int transfer = 0;
    int queueLen = 0, bufferLen = 0;
    int *digits = (int *)malloc(sizeof(int) * len);
    if (digits == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    for (int i = 0; i < len; i++)
    {
        digits[i] = 2;
    }

    for (int i = 0; i < n; i++)
    {
        int carry = 0;
        for (int j = len - 1; j > 0; j--)
        {
            digits[j] = digits[j] * 10 + carry;
            int temp = digits[j] / (j * 2 + 1);
            digits[j] = digits[j] % (j * 2 + 1);
            carry = temp * j;
        }

        digits[0] = digits[0] * 10 + carry;
        int q = digits[0] / 10;
            
        if (digits[0] >= 100) {
          if (DEBUG)  {
            printf("Error in comming... Carry transfer needed\n");
          }
          //transfer!
          for(int index = queueLen - 1;index >= 0;index--) {
	        if (queue[index] + 1 == 10) {
	          queue[index] = 0;
	        } 
            else {
	          queue[index] += 1;
	          break;
	        }
          }
          transfer = 1;
        }
        
        // store q
        if (ft > 0) {
          if (queue) {
	        // check if the current q can make a mistake
	        if (q == 9)  {
	          if (DEBUG)  {
	            printf("Transfer risk!\n");
	          }
	          // copy the queue to save it
	          bufferLen = queueLen;
	          buffer = (int  * )malloc(sizeof(int)  *  bufferLen);
	          for(int index = 0; index < bufferLen; index++) {
	            buffer[index] = queue[index];
	          }
	          //free the queue
	          free(queue);
	          // create the new queue
	          queueLen = bufferLen + 1;
	          queue = (int  * )malloc(sizeof(int)  *  queueLen);
	          // copy the buffer into the queue
	          for(int index = 0;index < bufferLen;index++) {
	            queue[index] = buffer[index];
	          }
	          // free the buffer
	          free(buffer);
	        } 
            else {
	          // free the queue
	          for(int index = 0;index < queueLen;index++) {
	            printf("%d", queue[index]);
	          }
	          free(queue);
	          queueLen = 0;
	          // create a new empty queue
	          queue = (int  * )malloc(sizeof(int)  *  1);
	          queueLen = 1;
	        }
          } 
          else {
	        // allocate a buffer
	        queue = (int  * )malloc(sizeof(int)  *  1);
	        queueLen = 1;
          }
         // store q for later
         if (transfer)  {
	       queue[queueLen - 1] = 0;
	       transfer = 0;
         }
         else {
	      queue[queueLen - 1] = q;
         }
         // print queue
         if (DEBUG)  {
	       printf("\n== Queue ==\n");
	       printf("Current q:%d\n", q);
	       for(int index = 0;index < queueLen;index++) {
	         printf("%d", queue[index]);
	       }
	       printf("\n=====\n");
         }
        }
        
        digits[0] = digits[0] % 10;

        //printf("%d", q);
        if(ft==0)
        {
            printf("%d", q);
            printf(".");
            ft++;
        }
    }

    free(digits);
    free(queue);
}

int main()
{
    int n;
    printf("Enter the number of digits to generate: ");
    scanf("%d", &n);
    printf("Pi: ");
    spigot(n);
    printf("\n");
    return 0;
}
