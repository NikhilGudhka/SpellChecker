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
 * The Header file for user.c
 */
#ifndef USER_H
#define USER_H

#include <stdio.h>
#include <stdlib.h>
/**
 * @param LENGTH The max length of a word 50, plus 1 for null terminator.
 * @param FALSE false defined a value 0,preprocessor replaces FALSE with 0.
 * @param TRUE defined a value that is not false.preprocessor replaces TRUE with anything thats not 0, mostly 1.
 */
#define LENGTH 51
#define FALSE 0
#define TRUE !FALSE
/**
 * @param UserListNode A linked list node to hold a single word and a next pointer.
 * @param uWord A charater Array (String) to hold a single user file word.
 * @param next A next pointer to point to a UserListNode.
 */
typedef struct UserListNode{
	char uWord[LENGTH];
	struct UserListNode* next;
}UserListNode;
/**
 * @param UserLinkedList A linked list to store the entire user file.
 * @param uCount A counter variable for the linked list to know how many elements are in the list.
 * @param head A pointer to the first node of the list.
 * @param tail A pointer to the last node of the list.
 */
typedef struct UserLinkedList{
	int uCount;
	UserListNode* head;
	UserListNode* tail;
}UserLinkedList;
/**
 * user A Function prototype.
 * @param  uFile A file pointer to the user file.
 * @param  uList A pointer to the user Linkedlist.
 * @return UserLinkedList A pointer to the intitialized user Linkedlist if the file could be open sucessfully and no errors found.
 */
UserLinkedList* user(FILE* uFile,UserLinkedList* uList);

#endif
