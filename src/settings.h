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
 *The Header file for the Settings.c
 */
#ifndef SETTINGS_H
#define SETTINGS_H

#include <stdio.h>
#include <string.h>
/**
 * @param FALSE false defined a value 0,preprocessor replaces FALSE with 0.
 * @param true defined a value that is not false.preprocessor replaces TRUE with anything thats not 0, mostly 1.
 * @param SETTINGSNAME The max number of characters in the settigns file on the left hand side i.e "maxcorrection=13 characters",preprocessor replaces SETTINGSNAME with 14.
 * @param DICTNAME The max number of characters for the dictionary file, assuming dictionary file name is not greater than 100 characters,preprocessor replaces DICTNAME with 101.
 * @param AUTOCORRECTLEN the max number of characters to store the autocorrect value i.e yes or no, yes = 3 characters,preprocessor replaces AUTOCORRECTLEN with 4.
 */
#define FALSE 0
#define TRUE !FALSE
#define SETTINGSNAME 14
#define DICTNAME 101
#define AUTOCORRECTLEN 4
/**
 * A Struct called SetSettings that hold the settings file.
 * @param maxCorrection An integer value representing the maximum allowable difference between amisspelt word and any corrections found.
 * @param dictionary A String representing the name of the dictionary file.
 * @param autoCorrect A String either "yes" or "no" indicating whether the program should automatically apply any corrections found or ask the user.
 */
typedef struct SetSettings{
	int maxCorrection;
	char dictionary[DICTNAME];
	char autoCorrect[AUTOCORRECTLEN];
}SetSettings;
/**
 * settings a function prototype
 * @param  sFileName the file name of the settings file
 * @return SetSettings Struct A struct holding the settings file.
 */
SetSettings settings(char* sFileName);

#endif
