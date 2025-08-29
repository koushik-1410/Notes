
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct PolyNode{
        int coeff,pow;
        struct PolyNode* next;
        }PolyNode;
       
PolyNode* createNode(int coeff,int pow){
         PolyNode* newNode=(PolyNode*)malloc(sizeof(PolyNode));
         newNode->coeff=coeff;
         newNode->pow=pow;
         newNode->next=NULL;
         return newNode;
         }
         
void insertTerm(PolyNode** poly,int coeff,int pow){
               if(coeff==0){
                  return;
                  }
                PolyNode* newNode=createNode(coeff,pow);
                if(*poly==NULL||(*poly)->pow<pow){
                   newNode->next=*poly;
                   *poly=newNode;
                   }else{
                     PolyNode* temp=*poly,*prev=NULL;
                       while(temp&&temp->pow>pow){
                             prev=temp;
                             temp=temp->next;
                          }
                        if(temp&&temp->pow==pow){
                            temp->coeff+=coeff;
                            free(newNode);
                            if(temp->coeff==0){
                              if(prev)prev->next=temp->next;
                                 else *poly=temp->next;
                                  free(temp);
                                  }
                                  }else{
                                   newNode->next=temp;
                                   if(prev)prev->next=newNode;
                                   }
                                   }
                                   }
                                   
void displayPoly(PolyNode* poly){
              if(!poly){
                 printf("0\n");
                 return;
                 }
             int first=1;
             while(poly){
                  if(first){
                    printf("%dx^%d",poly->coeff,poly->pow);
                    first=0;
                    }
                    else{
                       if(poly->coeff>=0)
                          printf("+%dx^%d",poly->coeff,poly->pow);
                         else
                          printf("-%dx^%d",poly->coeff,poly->pow);
                          }
                          poly=poly->next;
                          }
                         printf("\n");
                         }
                         
                         
PolyNode* addPoly(PolyNode* p1,PolyNode* p2){
          PolyNode* result=NULL;
          while(p1){
                insertTerm(&result,p1->coeff,p1->pow);
                         p1=p1->next;
                    }
           while(p2){
                 insertTerm(&result,p2->coeff,p2->pow);
                        p2=p2->next;
                       }
                       return result;
                       }
                       
void freePoly(PolyNode* poly){
      while(poly){
           PolyNode* temp=poly;
           poly=poly->next;
           free(temp);
           }
           }
           
PolyNode* multiply(PolyNode* p1,PolyNode* p2){
           PolyNode* result=NULL;
           PolyNode* a;
           PolyNode* b;
           for(a=p1;a;a=a->next){
               for(b=p2;b;b=b->next){
                printf("currently at %f, %d\n", b->coeff,b->pow);
                insertTerm(&result,a->coeff*b->coeff,a->pow+b->pow);
                }
                }
                return result;
                }
               
int evaluate(int x,PolyNode* poly){
    int result=0;
    while(poly){
      result+=poly->coeff*(int)pow(x,poly->pow);
      poly=poly->next;
      }
      return result;
     }
             
int main(){
    PolyNode* poly1=NULL;
    PolyNode* poly2=NULL;
    PolyNode* result=NULL;
   
    int choice,subchoice,coeff,pow;
   
    while(1){
         printf("Select your choice:\n");
         printf("1.insertion:\n");
         printf("2.display:\n");
         printf("3.add:\n");
         printf("4.multiply\n");
         printf("5.evaluate:\n");
         printf("6.exit\n");
         printf("enter your choice:");
         scanf("%d",&choice);
         
         switch(choice){
               case 1:
               printf("1.insert into polynomial 1\n");
               printf("2.insert into polynomial 2\n");
               printf("enter subchoice:");
               scanf("%d",&subchoice);
               printf("enter coefficient and power:");
               scanf("%d %d",&coeff,&pow);
               if(subchoice==1){
                  insertTerm(&poly1,coeff,pow);
                  }else{
                   insertTerm(&poly2,coeff,pow);
                   }
                   break;
                   
               case 2:
                 printf("1.display polynomial 1\n");
                 printf("2.display polynomial 2\n");
                 printf("enter subchoice:");
                 scanf("%d",&subchoice);
                 if(subchoice==1){
                   displayPoly(poly1);
                 }else{
                    displayPoly(poly2);
                   }
                   break;
                   
                 case 3:
                  freePoly(result);
                  result=addPoly(poly1,poly2);
                  printf("SUM:");
                  displayPoly(result);
                  break;
                 
                  case 4:
                  freePoly(result);
                  result=multiply(poly1,poly2);
                  printf("multiplication:");
                  displayPoly(result);
                  break;
                 
                 
                 
                  case 6:
                  printf("exiting program.\n");
                  exit(1);
                  break;
                 
                  default:
                  printf("invalid choice");
                  break;
               
                 
                  }
                  }
return 0;
}


