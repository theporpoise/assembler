#include <stdio.h>
#include <string.h>
#include <ctype.h>

// count the line you are on
// change from addresses to 1's and 0's
// chnage from instructions to 1's and 0's

main()
{
    int c;
    int pre;
    int comment = 0;

    while ((c = getchar()) != EOF)
    {
        if(c == '\n' && pre == '\n')
        {
            comment = 0;
            pre = c;
        }
        else if(c == '\n' && comment == 1)
        {
            pre = c;
            comment = 0;
        }
        else if(c == '\n')
        {
            pre = c;
            putchar(c);
            comment = 0;
        }
        else if(comment == 1)
        {
            pre = c;
        }
        else if(pre == '/' && c == '/')
        {
            comment = 1;
            pre = c;
        }
        else if(c == '/')
        {
            pre = c;
        }
        else if(pre =='/')
        {
            putchar(pre);
            putchar(c);
            pre = c;
        } 
        else
            putchar(c);
    }
    return 0;
}





/*psuedo code:
 *
 *
 * open file that you want to assemble
 * ignore line comments //
 * ignore everything but addresses :-)
 * change addresses into numbers
 *j
 *
 *
 *
 *
 *
 * initialize a bunch of variables.
 * open up the file that we need to assemble.
 * make a first pass over the file and replace all the pointers and potentially also the variable referecnes with acutal addresses
 * create a file here that just does this translation.
 * make a secone pass
 * translate the 3 parts of the code d=m+1;jgt (register, operatin, jump code) into what they do.
 * output the results.
 *
 * How to:
 * Program 1:
 * first just write the translator file that takes in output and subs out all the label references because otherwise that's confusing.
 * this program will need to count which line it's on so it cna make line references.
 * that's all this program does!  maybe it will also have to sub in addresses for variable names, i cna't remember right now, but check that.
 *
 * Program 2:
 * now you have to create some tables 
 * take each line and break it into it's 3 parts - address, operation, and jump.
 * map the parts of the line to the 000's and 1 1 1's using the tables you created earlier
 * output the machine language file.
 *
 * NOTE:  You can write either program first.  It may make sense to write program 2 first since they give you files without symbols towork with.  Then you can see if that works.  If that works, then you can create program 1.  run the example with symbols through program 1, see if that matches.  then you can run it through program 2, which you already checked and know matches, then you have it.  You can combine program ! and 2 into program 3 if you want!
*/



