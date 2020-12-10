#include <stdio.h>
#include <string.h>

#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart highway, cool wind in my hair.";
char StrKey[] = "wind";

char* ForceSearch(char text[], char key[])
{
    //  ここを実装する
int start=0;
int pos=0;
int text_len = strlen(text);
int key_len = strlen(key);
for(start=0;start<text_len;start++)
{
 
 for(pos=0;pos<key_len;pos++)
 {
     if(key[pos]==text[pos+start])
     {
         if(key_len== pos+1)
         {
             return &text[start];
         }
     }
     else
     {
      break;
     }
 }
}
return NULL;
}

char* BMSearch(char text[], char key[])
{
    //  ここを実装する
int i ,keep;
int text_len = strlen(text);
int key_len = strlen(key);
int index = key_len-1;
int key_index=key_len-1;
int table[256];
for(i=0;i<ALPHABET_LEN;i++)
{
table[i]=key_len;
}
for(i=0;i<key_len;i++)
{
 table[key[i]]=key_len;
}
while(index<text_len)
{
    keep = index;
    for(key_index = key_len-1;-1<key_index;key_index--)
    {
     if(text[index] == key[key_index])
     {
         if(key_index == 0)
         {
          return&text[index];
         }
         else
         {
             index = index -1;
         }
     }
     else
     {
      break;
     }
    }
    if(keep>=keep+table[text[keep]])
    {
   index = keep +1;
    }
    else
    {
    index = keep + table[text[keep]];
    }
    
    
}
return NULL;
}


int main(void)
{
    char*   str;
    str = ForceSearch(StrOriginal, StrKey);
    printf("Force Search. Find keyword at:%s\n", str);

    str = BMSearch(StrOriginal, StrKey);
    printf("BM Search. Find keyword at:%s\n", str);

    return 0;
}