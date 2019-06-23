#include "../student_list.h"
student_node* Fun(student_list &a,student &s)
{
    int k,l=0,j=0;
    student_node *p=0;
    student_node *q=0;
    student_node *m=0;
    student_node *n=0;
    student_node *t=0;
    a.goto_head();
    while(a.get_curr()->get_next())
    {
        k=*(a.get_curr())<s;
     //   printf("%d",k);
        if(k>0)
        {
            a.goto_next();
        }
        else if(k<0)
        {
            m=a.get_curr();
            a.del();
            if(l==0) {p=m;q=m;l=1;}
            else {q->cha(*m);q=m;}
        }
        else if(k==0)
        {
            m=a.get_curr();
            a.del();
            if(j==0) {t=m;n=m;j=1;}
            else {n->cha(*m);n=m;}
        }
    }
//    printf("\n%s %d",p->get_name(),p->get_value());
 //   printf("\n%s %d",q->get_name(),q->get_value());
    if(t) a.get_curr()->cha(*t);
    while(a.get_curr()->get_next()) a.goto_next();
    if(p&&n) n->cha(*p);
    else if(p) a.get_curr()->cha(*p);
    a.goto_head();
    return a.get_curr();
}
