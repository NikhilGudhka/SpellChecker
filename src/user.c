/**
 *   Copyright (c) 2017 Nikhil Gudhka
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a copy
 *   of this software and associated documentation files (the "Software"), to deal
 *   in the Software without restriction, including without limitation the rights
 *   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *   copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 *
 *   The above copyright notice and this permission notice shall be included in all
 *   copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *   SOFTWARE.
*/

/**
 * The file contains the user() function, which stores the contents of the user file into a Linkedlist.
 */
#include "user.h"
/**
 * user() takes a pointer to the file and a pointer to the linkedlist, storing each word of the user file
 * seperated by a whitespace into a linkedlist node, and creating a linkedlist of the user file.
 * @param  uFile -a pointer to the file.
 * @param  list  -a pointer to the linkedlist.
 * @return list  -the user file linkedlist if no errors encountered.
 */
UserLinkedList* user(FILE* uFile,UserLinkedList* list)
{
	/*
	 * @param nReads - number of values read.
	 * @param newNode - a pointer to a UserListNode, used to create a new linkedlist node.
	 * @param current - a pointer to a UserListNode, used to point to the current node in the linkedlist.
	 */
	int nReads=0;
	UserListNode *newNode,*current;
	list->head=NULL;
	list->tail=NULL;
	list->uCount=0;
	/*
	 *	create a new dynamically allocated linked list node.
	 */
	newNode=(UserListNode*)malloc(sizeof(UserListNode));
	/*read a single word from the user file and store the word in the newNode's uWord field,return the number of items read to nRead */
	nReads=fscanf(uFile,"%50s",newNode->uWord);
	/*
	 * make the head of the list point to the first node created above.
	 * make the tail of the list point to the new node created above since its the first node head and tail point to the same thing.
	 * make current point to what tail is pointing to.
	 */
	list->head=newNode;
	list->tail=newNode;
	current=list->tail;
	/* if the number of values read is not equal to 1 then print an error, else continue reading file */
	if(nReads!=1)
	{
		printf("Error reading user file, file not in correct format\n");
	}
	else
	{
		/*
         * Keep looping till end of file, create a newNode for each word in the user file seperated by a whitespace,
         * and store the word in the newNode.
		 */
		do
		{
			/* check if the number of values read is equal to 1,if not print an error, else continue reading */
			if(nReads!=1)
			{
				printf("Error reading user file, file not in correct format\n");
			}
			/* only run the if code if there is only one node in the list, i.e. the very first node */
			if((nReads==1)&&(list->uCount==0))
			{
				/*
				 * make the tail pointer equal to the newNode.
				 * set the next pointer of the newNode to NULL.
				 * increment the counter of the list.
				 * set the current pointer to point to the head.
				 */
				list->tail=newNode;
				newNode->next=NULL;
				list->uCount++;
				current=list->head;
			}
			/* run the else code if there is more then 1 node in teh list */
			else
			{
				/*
				 * make the tail pointer equal to the newNode.
				 * set the next pointer of the newNode to NULL.
				 * make current->next point to the newNode.
				 * current now points to the newNode.
				 * increment the counter of the list.
				 */
				list->tail=newNode;
				newNode->next=NULL;
				current->next=newNode;
				current=current->next;
				list->uCount++;
			}
			/*
			 * create a dynamically allocated UserListNode newNode.
			 * read the next word in the file,return 1 to nReads if a single word was read.
			 */
			newNode=(UserListNode*)malloc(sizeof(UserListNode));
			nReads=fscanf(uFile,"%50s",newNode->uWord);
		}
		while(nReads!=EOF);
	}
	/* if an error occurs during writing an error is displayed. */
	if(ferror(uFile))
	{
		perror("Error while reading user file");
	}
	/* memory allocated for newNode is freed */
	free(newNode);

    return list;
}
