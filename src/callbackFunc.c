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
 * This file contains the suggestionWord() and getAutoCorrectVal() functions,
 * the function suggestionWord is used as a callback function, the user's misspelt word
 * and a suggestion from the check function is passed in as Parameters.
 * It checks what the autocorrect value is using the getAutoCorrectVal function and if autocorrect
 * is "yes" then autocorrects to the suggested word if "no", then asks the user if he/she would like
 * to autocorrect the misspelt word with the suggestion.
 * The getAutoCorrectVal function gets the autocorrect value from the struct used to store the settings
 * file.
 * suggestionWord() is passed in as a parameter to function check in check.c as a callback Function.
 */
#include "callbackFunc.h"

/**
 * suggestionWord
 * @param  word       - misspelt word.
 * @param  suggestion - suggested correction for misspelt word.
 * @return accepted   - returns TRUE (as int 1) if word is replaced else FALSE (as int 0) if not.
 */
int suggestionWord(char* word,char* suggestion)
{
    /*
     * @param accepted - an integer to check if accepted by user
     * @param change - if change = "1", replace misspelt word with suggested word, else if "0", ignore suggestion.
     * @param userInput - variable to check if user inputs valid option to replace or not replace the misspelt word.
     */
    int accepted=FALSE,change=-1,userInput=0;
    /* function call to getAutocorrectVal, returns 1 if autocorrect is "yes", 0 if autocorrect is "no"  */
    int autocorrect=getAutoCorrectVal("");
    if(suggestion!=NULL)
    {
        /*
         * if the autocorrect in the settings file is yes the word will be replaced
         * else the user will be asked if the misspelt word is to be replaced by the suggested word
         */
        if(autocorrect==1)
        {
            strncpy(word,suggestion,LENGTH);
            accepted=TRUE;
        }
        else if(autocorrect==0)
        {
            /*
             * the misspelt word and its suggestion is displayed to the user.
             * the user is asked to input 1 for "yes" and 0 for "no", if the inputted value is not 0 or 1,
             * the user is asked again to enter either 0 or 1
             */
            printf("would you like to replace %s with %s\n",word, suggestion);
            while(userInput!=1)
            {
                printf("Enter '1' if you would like to change to the suggested word and '0' if not\n");
                scanf("%d",&change);
                if((change==0)||(change==1))
                {
                    userInput=1;
                }
            }
            /* if the option selected is "1" the word is replaced */
            if(change==1)
            {
                strncpy(word,suggestion,LENGTH);
                accepted=TRUE;
            }
            /* else if the selected option is "0", the suggestion is rejected and original word kept */
            else if(change==0)
            {
                accepted=FALSE;
            }
        }
    }
    /*print to user that there are no suggestions available for the word */
    else
    {
        printf("No suggestions available for '%s'\n",word);
    }

    return accepted;
}

/**
 * getAutoCorrectVal gets the autocorrect value from the struct used to store the settings file.
 * @param  value - a character array(String) with the autocorrect value "yes" or "no".
 * @return correct - an integer variable assigned 1 if autocorrect is "yes" and 0 if autocorrect is "no".
 */
int getAutoCorrectVal(char* value)
{
    static int correct;
    if(strcmp(value,"yes")==0)
    {
        correct=1;
    }
    else if(strcmp(value,"no")==0)
    {
        correct=0;
    }
    return correct;
}
