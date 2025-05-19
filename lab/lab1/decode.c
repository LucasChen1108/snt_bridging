#include<stdio.h>

int main(int argc,char *argv[])
{
  FILE *indata,*outdata;
  char this1;

  indata=fopen(argv[1],"r");
  outdata=fopen(argv[2],"w");

  while (fscanf(indata,"%c",&this1)==1)
  {
    if (this1>='A' && this1<='Z')
        fprintf(outdata,"%c",(this1 - 'A' + 'Z'+1 - 'K')%26+'A'); // (this1-2*'A'+'K')%26+'A'
    else if (this1>='a' && this1<='z')
	    fprintf(outdata,"%c", 'z' - this1 + 'a');//'z'-(this1-'a')
    else
      fprintf(outdata,"%c",this1);
  }
  fclose(indata);
  fclose(outdata);

  return 0;
}