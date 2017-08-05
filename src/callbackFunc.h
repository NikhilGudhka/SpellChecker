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
 * The Header file for callbackFunc.c
 */
#ifndef CALLBACKFUNC_H
#define CALLBACKFUNC_H

#include <stdio.h>
#include <string.h>
/**
 * @param FALSE false defined a value 0,preprocessor replaces FALSE with 0.
 * @param TRUE defined a value that is not false.preprocessor replaces TRUE with anything thats not 0, mostly 1.
 * @param LENGTH The max length of a word 50, plus 1 for null terminator.
 */
#define FALSE 0
#define TRUE !FALSE
#define LENGTH 51
/**
 * suggestionWord A function prototype.
 * @param  word The misspelt word from the user file.
 * @param  suggestion The suggestion to replace that word if there is any suggestion,NULL if no suggestion.
 * @return An integer to represent whether correction is to be accepted,return 0 if false and 1 for true.
 */
int suggestionWord(char* word,char* suggestion);
/**
 * getAutoCorrectVal A Function prototype.
 * @param  value a character array passing in the autocorrect value from teh settigns file
 * @return An integer representing the autocorrect value, 0 for no, 1 for yes.
 */
int getAutoCorrectVal(char* value);

#endif
