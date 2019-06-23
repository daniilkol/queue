#include "student_node.h"
class student_queue
{
private:
    student_node*head;
    student_node*tail;
public:
    student_queue(){head=0;tail=0;}
    ~student_queue()
    {
        student_node* tmp=head;
        while(tmp!=0)
        {
            tmp=head->next;
            delete head;
            head=tmp;
        }
    }
    void add (student_node&a)
    {

         if(head!=0)
         {
             a.next=0;
             tail->next=&a;
             tail=&a;
         } else head=tail=&a;
    }
    int read(const char*name,student_queue& a)
    {
        FILE *fp;
        char b[1000];
        int c;
        student_node* q;
        if(!(fp=fopen(name,"r"))) return -1;
        if(fscanf(fp,"%s%d",b,&c)==2)
        {
            q=new student_node(b,c);
            a.add(*q);
        }
        else{fclose(fp);return -3;}

        while(fscanf(fp,"%s%d",b,&c)==2)
        {
            q=new student_node(b,c);
            a.add(*q);
        }
        if(!feof(fp))
            {
                fclose(fp);
                return -2;
            }
        fclose(fp);
         return 1;
    }
    bool empty(){if(head) return false; return true;}
    void print()
    {
       student_node* tmp=head;
       while(tmp!=0)
       {
           printf("%s %d\n",tmp->get_name(),tmp->get_value());
           tmp=tmp->next;
       }
    }
    void del()
    {
        if(head!=0)
        {
            student_node* tmp=head;
            printf("Element <%s %d> is out\n",tmp->get_name(),tmp->get_value());
            head=head->next;
            delete tmp;
        }
    }
    int size ()
    {
       student_node* tmp=head;
       int i=0;
       while(tmp)
       {
           i++;
           tmp=tmp->next;
       }
       return i;
    }
    void menu(student_queue& a)
    {
        int key;
        printf("-1. Info\n");
        printf("0. Quit\n");
        printf("1. Add element\n");
        printf("2. Delete element\n");
        printf("3. Size of queue\n");
        printf("4. Print head of queue\n");
        printf("5. Print the queue\n");
        for(;;)
        {
            printf("Number of the command\n");
            scanf("%d",&key);
            switch (key)
            {
                case -1:
                    printf("0. Quit\n");
                    printf("1. Add element\n");
                    printf("2. Delete element\n");
                    printf("3. Size of queue\n");
                    printf("4. Print head of queue\n");
                    printf("5. Print the queue\n"); break;
                case 0:
                     return;
                case 1:
                    {
                            char b[1000];
                        int c;
                        printf("Input student:");
                        scanf("%s%d",b,&c);
                        student_node *tmp=new student_node(b,c);
                        a.add(*tmp);
                        break;
                    }
                case 2: a.del(); break;
                case 3: {int c=a.size(); printf("Size is equal to:%d\n",c); break;}
                case 4: printf("%s %d\n",head->get_name(),head->get_value()); break;
                case 5: a.print(); break;
                default: printf("Command is undefined\n");break;
            }
        }

    }
};


