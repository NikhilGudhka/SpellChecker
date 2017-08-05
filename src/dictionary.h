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
 * The Header file for dictionary.c
 */
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdio.h>
#include <stdlib.h>
/**
 * @param FALSE false defined a value 0,preprocessor replaces FALSE with 0.
 * @param TRUE defined a value that is not false.preprocessor replaces TRUE with anything thats not 0, mostly 1.
 * @param LENGTH The max length of a word 50, plus 1 for null terminator.
 */
#define FALSE 0
#define TRUE !FALSE
#define LENGTH 51
/**
 * @param DictListNode A linked list node to hold a single word and a next pointer.
 * @param dWord A charater Array (String) to hold a single dictionary file word.
 * @param next A next pointer to point to a UserListNode.
 */
typedef struct DictListNode{
	char dWord[LENGTH];
	struct DictListNode* next;
}DictListNode;
/**
 * @param DictLinkedList A linked list to store the entire dictionary file.
 * @param dCount A counter variable for the linked list to know how many elements are in the list.
 * @param head A pointer to the first node of the list.
 * @param tail A pointer to the last node of the list.
 */
typedef struct DictLinkedList{
	int dCount;
	DictListNode* head;
	DictListNode* tail;
}DictLinkedList;
/**
 * dict A Function prototype.
 * @param  dFile A file pointer to the dictionary file.
 * @param  dList A pointer to the dictionayr Linkedlist.
 * @return DictLinkedList A pointer to the intitialized dictionary Linkedlist if the file could be open sucessfully and no errors found.
 */
DictLinkedList* dict(FILE* dFile,DictLinkedList* list);

#endif
