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
 * This file contains the settings() function, which uses a struct to store the contents of the settings file.
 */
#include "settings.h"
/**
 * settings() takes a pointer to the settings file name
 * @param  sFileName -a pointer to the file.
 */
SetSettings settings(char* sFileName)
{
	/*
	 * @param nReads - number of values read.
	 * @param errorCheck - checks if the settings file is in the correct format.
	 * @param sName - a character array to hold the left had side of the settings file.
	 * @param set - a struct of type SetSettings to hold the settings.
	 */
	int nRead=0,errorCheck=FALSE;
	char sName[SETTINGSNAME];
	SetSettings set;
	/* initialize struct fields to default values */
	set.maxCorrection=0;
	strcpy(set.dictionary,"");
	strcpy(set.autoCorrect,"");
	/* only run if statement if the settings file is called "spellrc" */
	if(strcmp(sFileName,"spellrc")==0)
	{
		/* open the settings file for reading */
		FILE* sFile=fopen(sFileName,"r");
		/* print error if settings file cannot be opened */
		if(sFile==NULL)
		{
			perror("Error Opening File 'spellrc'");
		}
		else
		{
			/* read upto a maximum of 14 characters from the settings file. returns 1 to nReads if one word is read  */
			nRead=fscanf(sFile,"%14s",sName);
			/* print error if settigns file is not in correct format */
			if(nRead!=1)
			{
				printf("ERROR! File in unexpected format\n");
			}
			else
			{
				/* keep looping till not End of File and no errors in settings file */
				while((nRead!=EOF)&&(errorCheck==FALSE))
				{
					/* check if the left hand side of the settings file is "maxcorrection" */
					if(strcmp(sName,"maxcorrection")==0)
					{
						nRead=fscanf(sFile," = %d",&set.maxCorrection);
						/* print error if settigns file is not in correct format */
						if(nRead!=1)
						{
							printf("ERROR! File in unexpected format\n");
							errorCheck=TRUE;
							/* set struct fields to default values */
							set.maxCorrection=0;
							strcpy(set.dictionary,"");
							strcpy(set.autoCorrect,"");
						}
					}
					/* check if the left hand side of the settings file is "dictionary" */
					else if(strcmp(sName,"dictionary")==0)
					{
						nRead=fscanf(sFile," = %100s",set.dictionary);
						/* print error if settigns file is not in correct format */
						if(nRead!=1)
						{
							printf("ERROR! File in unexpected format\n");
							errorCheck=TRUE;
							/* set struct fields to default values */
							set.maxCorrection=0;
							strcpy(set.dictionary,"");
							strcpy(set.autoCorrect,"");
						}
					}
					/* check if the left hand side of the settings file is "autocorrect" */
					else if(strcmp(sName,"autocorrect")==0)
					{
						nRead=fscanf(sFile," = %4s",set.autoCorrect);
						/* print error if settigns file is not in correct format */
						if(nRead!=1)
						{
							printf("ERROR! File in unexpected format\n");
							errorCheck=TRUE;
							/* set struct fields to default values */
							set.maxCorrection=0;
							strcpy(set.dictionary,"");
							strcpy(set.autoCorrect,"");
						}
					}
					/* print error if settigns file is not in correct format */
					else
					{
						printf("ERROR! File in unexpected format\n");
						errorCheck=TRUE;
						/* set struct fields to default values */
						set.maxCorrection=0;
						strcpy(set.dictionary,"");
						strcpy(set.autoCorrect,"");
					}
					/* read upto a maximum of 14 characters from the settings file. returns 1 to nReads if one word is read  */
					nRead=fscanf(sFile,"%14s",sName);
				}
			}
			/* if an error occurs during reading the file, an error is displayed. */
			if(ferror(sFile))
			{
				perror("Error while reading file 'spellrc'");
			}
			/* close the file */
			fclose(sFile);
		}
	}
	/* if settings file not named "spellrc" print error */
	else
	{
		printf("ERROR! Setting file not found");
	}

	return set;
}
