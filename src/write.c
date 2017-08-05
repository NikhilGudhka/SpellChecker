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
 *  This file contains the writeToFile() function, which writes the contents of the array to the output file.
 */
#include "write.h"

/**
 * writeToFile writes the contents of the array to the output file.
 * @param filename - the name of the userfile that will be overwritten
 * @param uArray   - an array containing the corrected words
 * @param length   - length of the array
 */
void writeToFile(char* filename,char** uArray,int length)
{
    /*
     * opens the file for writing, if the file cannot be opened, print out an error,
     * else writes the contents of the array to the file separated with a whitespace.
     * if an error occurs during writing an error is displayed.
     * the file is closed after sucessfully writing to it.
     */
    int i=0;
    FILE* file=fopen(filename,"w");
    if(file==NULL)
    {
        perror("Error opening file for writing");
    }
    else
    {
        for(i=0;i<length;i++)
        {
            fprintf(file,"%s ",uArray[i]);
        }
        if(ferror(file))
        {
            perror("Error while writing to file");
        }
        fclose(file);
    }
}
