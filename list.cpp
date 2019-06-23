#include "student_list.h"
int getlist(const char*name,student_list& a)
{
    FILE *fp;
     char b[1000];
    int c;
    student_node* q;
    if(!(fp=fopen(name,"r"))) return -1;

    if(fscanf(fp,"%s%d",b,&c)==2)
    {
        q=new student_node(b,c);
        a.add_first(*q);
    }
    else{fclose(fp);return -3;}

    while(fscanf(fp,"%s%d",b,&c)==2)
    {
        q=new student_node(b,c);
        a.addA(*q);
        a.goto_next();
    }
    if(!feof(fp))
        {
            fclose(fp);
            return -2;
        }
    fclose(fp);
   // printf("q=%s %d\n",q->get_name(),q->get_value());
    return 1;
}
void printarray(student_list &a)
{
    int i=0;
    printf("\n\n\n");
   a.goto_head();
   while(a.get_curr()->get_next()&&i<MAX_N){printf("%s %d\n",a.get_curr()->get_name(),a.get_curr()->get_value());a.goto_next();i++;}
   printf("%s %d\n",a.get_curr()->get_name(),a.get_curr()->get_value());
}
void printarray(student_node *a)
{
    int i=0;
    printf("\n\n\n");
   while(a&&i<MAX_N){printf("%s %d\n",a->get_name(),a->get_value());a=a->get_next();i++;}
}
