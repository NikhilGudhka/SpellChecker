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
 * This file contains the main() function, it starts the program and ends it.
 */
#include <stdio.h>
#include "dictionary.h"
#include "user.h"
#include "settings.h"
#include "check.h"
#include "callbackFunc.h"
#include "write.h"
/**
 * main starts the program.
 * @param  argc - argument count of command line parameters.
 * @param  argv - argument vector of command line parameters.
 * @return 0 if program exits successfully.
 */
int main (int argc,char* argv[])
{
	/* print an error,if the arguments are less than 2 or greater than 2 */
	if((argc<2)||(argc>2))
	{
		printf("Error! Too few/many arguments. Enter 1 argument after the filename\n");
	}
	else
	{
		/*
		 * @param i - counter variable.
		 * @param num - length of dictionary filename.
		 * @param autoCorrectVal - autocorrect value from the settings file.
		 * @param dName - the dictionary filename.
		 * @param sName -the setting filename.
		 * @param uName -the user filename.
		 * @param uFile - a pointer to the user file.
		 * @param dFile - a pointer to the dictionary file.
		 * @param sets - a struct of type SetSettings.
		 * @param temp - a pointer to a DictListNode.
		 * @param uTemp - a pointer to a UserListNode.
		 * @param dArray - a two dimensional character array to store the dictionary words.
		 * @param uArray -a two dimensional character array to store the userfile words.
		 * @param dList - a pointer to a DictLinkedList.
		 * @param uList - a pointer to a UserLinkedList.
		 * @param action - a variable of type ActionFunc.
		 */
		int i=0,num=0,autoCorrectVal=-1;
		char dName[100]="";
		char sName[100]="spellrc";
		char uName[100];
		FILE* uFile=NULL;
		FILE* dFile=NULL;
		SetSettings sets;
		DictListNode *temp=NULL;
		UserListNode *uTemp=NULL;
		char **dArray=NULL,**uArray=NULL;
		/* a typedefed pointer to a function that takes 2 character pointers as parameters and returns an int. */
		typedef int (*ActionFunc)(char* word,char* suggestion);
		ActionFunc action;
		DictLinkedList* dList=NULL;
		UserLinkedList* uList=NULL;
		/* use string copy to copy the name of the userfile from the command line paramter (argv[1]) to uName */
		strcpy(uName,argv[1]);
		/* open the user file for reading */
		uFile= fopen(uName,"r");
		/* if the userfile could not be opened print error */
		if(uFile==NULL)
		{
			perror("Error opening User File");
		}
		else
		{
			/*
			 * dynamically allocate memory for a Linkedlist (uList).
			 * call the user() function with parameters, a pointer to the userfile (uFile) and the user Linkedlist (uList).
			 * dynamically allocate memory for a two dimentional array (uArray).
			 */
			uList=(UserLinkedList*)malloc(sizeof(UserLinkedList));
			uList=user(uFile,uList);
			uArray=(char**)calloc(uList->uCount,sizeof(char[51]));

			/* call the settings function with paramter sName which returns the struct with the settings */
			sets=settings(sName);
			/* check if dictionary filename exists in settings file */
			if(strcmp(sets.dictionary,"")!=0)
			{
				/* num is set to the length of the dictionary filename */
				num=strlen(sets.dictionary);
				/* use string copy to copy the name of the dictionary file from the struct to dName, where num is number of characters to copy */
				strncpy(dName,sets.dictionary,num);
				/* open the dictionary file for reading */
				dFile= fopen(dName,"r");
				/* if the dictionary file could not be opened print error */
				if(dFile==NULL)
				{
					perror("Error opening Dictionary File");
				}
				else
				{
					/*
					 * dynamically allocate memory for a Linkedlist (dList).
					 * call the dict() function with parameters, a pointer to the dictionary file (dFile) and the dictionary Linkedlist (dList).
					 * dynamically allocate memory for a two dimentional array (dArray).
					 */
					dList=(DictLinkedList*)malloc(sizeof(DictLinkedList));
					dList=dict(dFile,dList);
					dArray=(char**)calloc(dList->dCount,sizeof(char[51]));
					/* a temporary pointer (dTemp) pointing to the dictionary linkedlist head */
					temp=dList->head;
					/*
					 *  store each word from dictionary likedlist (dList) into the dictionary array (dArray).
					 */
					for(i=0;i<dList->dCount;i++)
					{
						dArray[i]=temp->dWord;
						temp=temp->next;
					}
					/* a temporary pointer (uTemp) pointing to the user linkedlist head (uList)*/
					uTemp=uList->head;
					/*
					 *  store each word from user likedlist (uList) into the user array (uArray).
					 */
					for(i=0;i<uList->uCount;i++)
					{
						uArray[i]=uTemp->uWord;
						uTemp=uTemp->next;
					}
					/* function call to getAutocorrectVal, returns 1 if autocorrect is "yes", 0 if autocorrect is "no"  */
					autoCorrectVal=getAutoCorrectVal(sets.autoCorrect);
					autoCorrectVal++;
					/* assign address of function suggestionWord to action */
					action=&suggestionWord;
					/* call check, a two dimensional user word array (uArray), the list of the userfile array (uList->uCount),
					 * a two dimensional dictionary word array (dArray), the list of the dictionary file array (dList->dCount),
					 * the max correction and the callback function action as parameters.
					 */
					check(uArray, uList->uCount, dArray, dList->dCount, sets.maxCorrection, action);
					/* call writeToFile, passing teh userfile name, the userfile two dimensional array (uArray) and the length of the array as parameters */
					writeToFile(uName,uArray,uList->uCount);
					/*free dArray*/
					free(dArray);
					/* keep looping and freeing the top node while head is pointeed to the next node*/
					while (dList->head->next!=NULL)
					{
						temp=dList->head;
						dList->head=dList->head->next;
						free(temp);
					}
					/* free the dictionary list head */
					free(dList->head);
					/* free the dictionary list (dList)*/
					free(dList);
					/* close the dictionary file */
					fclose(dFile);
				}
			}
			/* loop and free each element in the 2D userfile array (uArray) */
			for(i=0;i<uList->uCount;i++)
			{
				free(uArray[i]);
			}
			/* free the userfile array (uArray) */
			free(uArray);
			/* free the userfile list (uList) */
			free(uList);
			/* close the userfile */
			fclose(uFile);
		}

	}
	return 0;
}
