#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int i=0;
struct web
{
char name[30],pass[30];
}w[99];
int n;
void login(void);
void reg(void);

//==========================================
struct place_info

{
    char place_name[100];
    char place_location[100];
    char place_view[100];
    char place_cost[100];
    struct place_info *next;

};
void add_PLACE();
void display_PLACE();
void search_PLACE();
void delete_PLACE();

int total_cont=0;
typedef struct place_info PLACE;
PLACE *head_pro = NULL ;
PLACE* alloc_mem_pro( char *name , char *location ,char *view ,char *cost  )

{

    PLACE *node_pro = (PLACE*)malloc(sizeof(PLACE));
    strcpy(node_pro->place_name,name) ;
    strcpy(node_pro->place_location,location) ;
    strcpy(node_pro->place_view,view) ;
    strcpy(node_pro->place_cost,cost) ;
    node_pro->next = NULL;
    return node_pro ;

}
//=============================================================

void reg()
  {
    FILE *fp;
    char c,checker[30]; int z=0;
    fp=fopen("Web_reg.txt","ab+");
    printf("\n\n\t\t\t\tWELCOME TO REGISTER ZONE");
    printf("\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^");
    for(i=0;i<100;i++)
    {
      printf("\n\n\t\t\t\t  ENTER USERNAME: ");
      scanf("%s",checker);
        while(!feof(fp))
        {
          fread(&w[i],sizeof(w[i]),1,fp);
          if(strcmp(checker,w[i].name)==0)
            {
            printf("\n\n\t\t\tUSERNAME ALREDY EXISTS");
            system("cls");
            reg();
            }
          else
          {
            strcpy(w[i].name,checker);
            break;
          }
        }
      printf("\n\n\t\t\t\t  DESIRED PASSWORD: ");
      while((c=getch())!=13)
        {
          w[i].pass[z++]=c;
          printf("%c",'*');
        }
      fwrite(&w[i],sizeof(w[i]),1,fp);
      fclose(fp);
      printf("\n\n\tPress enter if you agree with Username and Password");
      if((c=getch())==13)
        {
      system("cls");
        printf("\n\n\t\tYou are successfully registered");
        printf("\n\n\t\tTry login your account??\n\n\t\t  ");
        printf("> PRESS 1 FOR YES\n\n\t\t  > PRESS 2 FOR NO\n\n\t\t\t\t");
        scanf("%d",&n);
        switch(n)
          {
              case 1: system("cls");
                    login();
                    break;
              case 2: system("cls");
                    printf("\n\n\n\t\t\t\t\tTHANK YOU FOR REGISTERING");
                    break;
          }
        }
        break;
      }
    getch();
  }


  void login()
    {
      FILE *fp;
      char c,name[30],pass[30]; int z=0;
      int checku,checkp;
      fp=fopen("Web_reg.txt","rb");
      printf("\n\n\t\t\t\tWELCOME TO LOG IN ZONE");
      printf("\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^");
      for(i=0;i<1000;i++)
      {
        printf("\n\n\t\t\t\t  ENTER USERNAME: ");
        scanf("%s",name);
        printf("\n\n\t\t\t\t  ENTER PASSWORD: ");
        while((c=getch())!=13)
        {
          pass[z++]=c;
          printf("%c",'*');
        }
        pass[z]='\0';
      while(!feof(fp))
        {
        fread(&w[i],sizeof(w[i]),1,fp);
          checku=strcmp(name,w[i].name);
          checkp=strcmp(pass,w[i].pass);
          if(checku==0&&checkp==0)
          {
            system("cls");
            printf("\n\n\n\t\t\tYOU HAVE LOGGED IN SUCCESSFULLY!!");
            MainFunction();
            break;
          }
        else if(checku==0&&checkp!=0)
          {
            printf("\n\n\n\t\t\tWRONG PASSWORD!! Not %s??",name);
            printf("\n\n\t\t\t\t  (Press 'Y' to re-login)");
            if(getch()=='y'||getch()=='Y')
              login();
          }
        else if(checku!=0)
          {
            printf("\n\n\n\t\t\tYou are not a Registered User\n \t\t\tPress enter to register yourself");
            if(getch()==13)
            system("cls");
            reg();
          }
        }
        break;
      }
      getch();
    }


void GLSTM()
{
guideline();
}


void MMSTM()
{
 mamagement();
}


void MainFunctionCall()
{
    int MM;
   printf("\n\nPlease enter 1 to go to the main menu : ");
scanf("%d",&MM);
system("cls");
if (MM==1)
{
   MainFunction();
}
else
    {
    printf("Invalid number.");
   }
}


void MainFunction()
{
      int nmbr;
      // system("color A");system("color A");

    printf(" \n\t\t\t****************************************\n");
    printf(" \t\t\t*                                      *");
    printf(" \n\t\t\t*        :WELCOME TO TRAVEL BD:        *\n");
    printf(" \t\t\t*                                      *");
    printf(" \n\t\t\t*   :The travelers guideline system:   *\n");
    printf(" \t\t\t*                                      *");
    printf(" \n\t\t\t*     :with the management system:     *\n");
    printf(" \t\t\t*                                      *");
    printf(" \n\t\t\t****************************************\n");

    printf(" \n\t\t\t*       :PLEASE SELECT AN OPTION:      *\n");

 printf(" \n\n\t\t\t\t*************************\n");
    printf(" \t\t\t\t*                       *");
    printf(" \n\t\t\t\t*   1.GUIDELINE SYSTEM  *\n");
    printf(" \t\t\t\t*                       *");
    printf(" \n\t\t\t\t*************************\n");

 printf(" \n\t\t\t\t*************************\n");
    printf(" \t\t\t\t*                       *");
    printf(" \n\t\t\t\t*  2.MANEGEMENT SYSTEM  *\n");
    printf(" \t\t\t\t*                       *");
    printf(" \n\t\t\t\t*************************\n");

    printf("\n\tENTER YOUR CHOICE: ");
    scanf("%d",&nmbr);
    if (nmbr==1)
    {
      system("cls");
        GLSTM();
    }
    else if(nmbr==2)
    {
        system("cls");
        MMSTM();
            }
    else
    {
     system("cls");
     printf("\nInvalid Number.");
    }
MainFunctionCall();
}



int main()
{
   int nmbr;
//   system("cls");
printf("\n\n\n\n\n\t\t\t\tWELCOME TO THE SYSTEM");
printf("\n\t\t\t\t=====================");
printf("\n\n\n\n\t\t\tPress Enter to proceed...!!");
if(getch()==13)
  system("cls");
XY:

 printf(" \n\n\t\t\t\t*************************\n");
    printf(" \t\t\t\t*                       *");
    printf(" \n\t\t\t\t*   1.LOGIN SYSTEM      *\n");
    printf(" \t\t\t\t*                       *");
    printf(" \n\t\t\t\t*************************\n");

 printf(" \n\t\t\t\t*************************\n");
    printf(" \t\t\t\t*                       *");
    printf(" \n\t\t\t\t*  2.REGISTER SYSTEM    *\n");
    printf(" \t\t\t\t*                       *");
    printf(" \n\t\t\t\t*************************\n");

printf("\n\n\n\t\t\t\tENTER YOUR CHOICE: ");
scanf("%d",&nmbr);
 if (nmbr==1)
    {
      system("cls");
        login();
    }
    else if(nmbr==2)
    {
        system("cls");
        reg();
            }
    else
    {
     system("cls");
      printf("\n\n\t\t\t\tNO MATCH FOUND");
        printf("\n\n\t\t\tPress Enter to re-Enter the choice");
        if(getch()==13)
       system("cls");
        goto XY;
    }

MainFunctionCall();
   return 0;
}
//===================================================

int mamagement()

{

    system("cls");

    int x,c_1,c_2;
    char name[40],location[20], view[80], cost[20],srch[20];
  printf(" \t\t\t      Welcome to the Management System        ");
    printf(" \n\t\t\t****************************************\n");
    printf(" \n\t\t\t*       :PLEASE SELECT AN OPTION:      *\n");
    printf(" \n\t\t\t\t1. Add a new place           ");
    printf(" \n\t\t\t\t2. List of all places               ");
    printf(" \n\t\t\t\t3. Search for a place                ");
    printf(" \n\t\t\t\t4. Delete a place              ");
    printf(" \n\t\t\t\t0. Exit              ");
    printf(" \n\t\t\t****************************************\n");
    printf("Please enter a valid number : ");

    scanf("%d",&x);

    if ( x == 1 )
        {
            add_1:
            system("cls");
            printf("\n\t----------------------------- Add New Place -----------------------------\n");
            printf("\n> Name           : ");
            scanf("%s",&name);
            printf("\n> Location       : ");
            scanf("%s",&location);
            printf("\n> View           : ");
            scanf("%s",&view);
            printf("\n> Estimated cost : ");
            scanf("%s",&cost);
            printf("\n> Confirm to save? [1/0] : ");
            scanf("%d",&c_2);

            switch(c_2)
            {
                case 1:
                    add_PLACE(name,location,view,cost);
                    printf("\n> %s > Successfully saved !\n",name);
                    break;
                case 0:
                    goto add_1;
                break;
            }

            SystemCall();
        }
    else if(x==2)
        {

            system("cls");
            printf("\n\t----------------------------- List of all places -----------------------------\n");
            display_PLACE();
            SystemCall();
        }
    else if(x==3)

        {

           system("cls");

            printf("\n\t----------------------------- Search Place -----------------------------\n");
            printf("\n> Enter Place Name : ");
            scanf("%s",&srch);
            search_PLACE(srch);

            SystemCall();
        }

    else if(x==4)

        {

            system("cls");
            printf("\n\t----------------------------- Delete a place -----------------------------\n");
            printf("\n> Enter the place name : ");
            scanf("%s",&name);
            delete_PLACE(name);
            SystemCall();

        }


    else if(x==0)

        {

             exit(0);

        }

    else

        {

             main();

        }

    return 0;

}

void add_PLACE(  char *name , char *location , char *view , char *cost )

{
    PLACE *node = alloc_mem_pro(name,location,view,cost);
    if(head_pro == NULL)

        {

            head_pro = node;

        }

    else

        {

            PLACE *temp = head_pro;
            while(temp->next != NULL)
                {

                    temp = temp->next;

                }
            temp->next = node;
        }

    total_cont++;

}

void display_PLACE()

{

    PLACE *temp = head_pro;
    int c_1 ;
    char PLACE[20];
    printf("\n Total place saved : %d\n\n",total_cont);

    while(temp != NULL)

    {

        printf("\n> Name      : %s\n",temp->place_name);
        printf("\n> location     : %s\n",temp->place_location);
        printf("\n> view     : %s\n",temp->place_view);
        printf("\n> cost     : %s\n",temp->place_cost);
        printf("\n");
        temp = temp->next;

    }

}


void search_PLACE( char *type )

{
    PLACE *temp = head_pro;

    PLACE place_name[20];

    while( temp != NULL )

    {

        if( strcmp(temp->place_name,type) == 0 )

            {
                 printf("\n> Name      : %s\n",temp->place_name);
                 printf("\n> location     : %s\n",temp->place_location);
                 printf("\n> view     : %s\n",temp->place_view);
                 printf("\n> cost   : %s\n",temp->place_cost);
                 temp = temp->next;

            }

        else

            {

                 temp = temp->next;

            }

    }
}

void delete_PLACE( char *name )

{

    int choice_0 = 0 ;

    PLACE *temp = head_pro;
    if( strcmp(temp->place_name,name) == 0 )

        {

            head_pro = temp->next;
            free(temp);
            printf("\n> %s > deleted successfully ! \n",name);

        }
    else

    {

        while( temp->next != NULL && strcmp(temp->next->place_name,name) != 0 )

            {

                temp = temp->next;

            }

        if(temp->next == NULL)

            {

                printf("\n> Data Not Found!\n");

            }

        else

            {

                PLACE *temp2 = temp->next;
                temp->next = temp->next->next;
                free(temp2);
                printf("\n> %s > deleted successfully ! \n",name);

            }

    }

}

//********************************************************************************

struct diary{
    char date[20];
    char place[30];
    char experience[200];
};

int nmbr;

////////////////////////////////////////////////////////////////

void n1()
{
int sn;  /*SN=SERIAL NUMBER  ,   MM =MAIN MENU */
printf("\nplease choose a place.\n  1  > Ahsan Manzil\n  2  > Comilla Moynamoti\n  3  > Cox’s Bazar\n  4  > Khagrachari\n  5  > Kopotakkho Nod\n  6  > Kuakata\n  7  > Lalbagh Kella\n  8  > Mahasthangarh\n  9  > National Botanical Garden\n  10 > National Martyr’s Memorial\n  11 > National Shangshad Bhabon\n  12 > Rangamati\n  13 > Saint Martin\n  14 > Sajek valley\n  15 > Shatgombuj Mosque\n");
printf("\nplease enter the serial number of a place:");
scanf("%d",&sn);
system("cls");
if(sn==1)
   {
      FILE *place;
    char details[10000];
    place=fopen("Ahsan Manzil.txt","r");
    while(!feof(place))
       {
       fgets(details,10000,place);
       puts(details);
       }
    fclose(place);
   }

else if(sn==2)
   {
     FILE *place;
    char details[10000];
    place=fopen("Comilla Moynamoti.txt","r");
    while(!feof(place))
       {
       fgets(details,10000,place);
       puts(details);
       }
    fclose(place);
   }

else if(sn==3)
   {
     FILE *place;
    char details[10000];
    place=fopen("Cox’s Bazar.txt","r");
    while(!feof(place))
       {
       fgets(details,10000,place);
       puts(details);
       }
    fclose(place);
   }

else if(sn==4)
   {
     FILE *place;
    char details[10000];
    place=fopen("Khagrachari.txt","r");
    while(!feof(place))
       {
       fgets(details,10000,place);
       puts(details);
       }
    fclose(place);
   }

else if(sn==5)
   {
    FILE *place;
    char details[10000];
    place=fopen("Kopotakkho Nod.txt","r");
    while(!feof(place))
       {
       fgets(details,10000,place);
       puts(details);
       }
    fclose(place);
   }

else if(sn==6)
   {
     FILE *place;
    char details[10000];
    place=fopen("Kuakata.txt","r");
    while(!feof(place))
       {
       fgets(details,10000,place);
       puts(details);
       }
    fclose(place);
   }

else if(sn==7)
   {
    FILE *place;
    char details[10000];
    place=fopen("Lalbagh Kella.txt","r");
    while(!feof(place))
       {
       fgets(details,10000,place);
       puts(details);
       }
    fclose(place);
   }

else if(sn==8)
   {
    FILE *place;
    char details[10000];
    place=fopen("Mahasthangarh.txt","r");
    while(!feof(place))
       {
       fgets(details,10000,place);
       puts(details);
       }
    fclose(place);
   }

else if(sn==9)
   {
    FILE *place;
    char details[10000];
    place=fopen("National Botanical Garden.txt","r");
    while(!feof(place))
       {
       fgets(details,10000,place);
       puts(details);
       }
    fclose(place);
   }

else if(sn==10)
   {
     FILE *place;
    char details[10000];
    place=fopen("National Martyr’s Memorial.txt","r");
    while(!feof(place))
       {
       fgets(details,10000,place);
       puts(details);
       }
    fclose(place);
   }

else if(sn==11)
   {
     FILE *place;
    char details[10000];
    place=fopen("National Shangshad Bhabon.txt","r");
    while(!feof(place))
       {
       fgets(details,10000,place);
       puts(details);
       }
    fclose(place);
   }

else if(sn==12)
   {
     FILE *place;
    char details[10000];
    place=fopen("Rangamati.txt","r");
    while(!feof(place))
       {
       fgets(details,10000,place);
       puts(details);
       }
    fclose(place);
   }

else if(sn==13)
   {
     FILE *place;
    char details[10000];
    place=fopen("Saint Martin.txt","r");
    while(!feof(place))
       {
       fgets(details,10000,place);
       puts(details);
       }
    fclose(place);
   }
else if(sn==14)
   {
     FILE *place;
    char details[10000];
    place=fopen("Sajek valley.txt","r");
    while(!feof(place))
       {
       fgets(details,10000,place);
       puts(details);
       }
    fclose(place);
   }

else if(sn==15)
   {
     FILE *place;
    char details[10000];
    place=fopen("Shatgombuj Mosque.txt","r");
    while(!feof(place))
       {
       fgets(details,10000,place);
       puts(details);
       }
    fclose(place);
   }

else
   {
    printf("Invalid number.");
   }

SystemCall();

}


void n2()
{
int snd,snp;          /*snd=serial number of division, snp=serial number of place*/
printf("\nplease choose a division.\n  1.Dhaka Division.\n  2.Mymensingh Division.\n  3.Khulna Division.\n  4.Chittagong Division.\n  5.Rajshahi Division.\n  6.Rangpur Division.\n  7.Sylhet Division.\n  8.Barishal Division.\n");
printf("\nplease enter the serial number of a division:");
scanf("%d",&snd);
system("cls");
if(snd==1)
  {
    printf("\n\nThe tourist spots of Dhaka Division.\n");
    printf("\n\t1.Ahsan Manzil.\n\t2.Lalbagh Kella.\n\t3.National Botanical Garden\n");
    printf("\nPlease enter any valid number : ");
    scanf("%d",&snp);
    system("cls");
      if(snp==1)
       {
       FILE *place;
      char details[10000];
      place=fopen("Ahsan Manzil.txt","r");
         while(!feof(place))
          {
          fgets(details,10000,place);
          puts(details);
          }
      fclose(place);
       }

     else if(snp==2)
       {
       FILE *place;
      char details[10000];
      place=fopen("Lalbagh Kella.txt","r");
         while(!feof(place))
          {
          fgets(details,10000,place);
          puts(details);
          }
      fclose(place);
       }

       else if(snp==3)
       {
       FILE *place;
      char details[10000];
      place=fopen("National Botanical Garden.txt","r");
         while(!feof(place))
          {
          fgets(details,10000,place);
          puts(details);
          }
      fclose(place);
       }

      else
         {
         printf("\nINVALID NUMBER");
         }
   }
else if(snd==2)
   {
    printf("\n\nThe tourist spots of Mymensingh Division.");
     printf("\n\t1.Madhutila Eco Park.\n");
    printf("\nPlease enter any valid number : ");
    scanf("%d",&snp);
    system("cls");
      if(snp==1)
       {
       FILE *place;
      char details[10000];
      place=fopen("Madhutila Eco Park.txt","r");
         while(!feof(place))
          {
          fgets(details,10000,place);
          puts(details);
          }
      fclose(place);
       }

      else
         {
         printf("\nINVALID NUMBER");
         }
   }

else if(snd==3)
   {
    printf("\n\nThe tourist spots of Khulna Division.");
     printf("\n\t1.Sundarban.\n\t2.Shatgombuj Mosque. ");
    printf("\nPlease enter any valid number : ");
    scanf("%d",&snp);
    system("cls");
      if(snp==1)
       {
       FILE *place;
      char details[10000];
      place=fopen("Sundarban.txt","r");
         while(!feof(place))
          {
          fgets(details,10000,place);
          puts(details);
          }
      fclose(place);
       }

     else if(snp==2)
       {
       FILE *place;
      char details[10000];
      place=fopen("Shatgombuj Mosque.txt","r");
         while(!feof(place))
          {
          fgets(details,10000,place);
          puts(details);
          }
      fclose(place);
       }
      else
         {
         printf("\nINVALID NUMBER");
         }
   }

else if(snd==4)
   {
    printf("\n\nThe tourist spots of Chittagong Division.");
     printf("\n\t1.Cox’s Bazar.\n");
    printf("\nPlease enter any valid number : ");
    scanf("%d",&snp);
    system("cls");
      if(snp==1)
       {
       FILE *place;
      char details[10000];
      place=fopen("Cox’s Bazar.txt","r");
         while(!feof(place))
          {
          fgets(details,10000,place);
          puts(details);
          }
      fclose(place);
       }

      else
         {
         printf("\nINVALID NUMBER");
         }
   }

else if(snd==5)
   {
    printf("\n\nThe tourist spots of Rajshahi Division.");
     printf("\n\t1.Mahasthangarh.\n");
    printf("\nPlease enter any valid number : ");
    scanf("%d",&snp);
    system("cls");
      if(snp==1)
       {
       FILE *place;
      char details[10000];
      place=fopen("Mahasthangarh.txt","r");
         while(!feof(place))
          {
          fgets(details,10000,place);
          puts(details);
          }
      fclose(place);
       }

      else
         {
         printf("\nINVALID NUMBER");
         }
   }

else if(snd==6)
   {
    printf("\n\nThe tourist spots of Rangpur Division.");
     printf("\n\t1.Tajhat Palace.\n");
    printf("\nPlease enter any valid number : ");
    scanf("%d",&snp);
    system("cls");
      if(snp==1)
       {
       FILE *place;
      char details[10000];
      place=fopen("Tajhat Palace.txt","r");
         while(!feof(place))
          {
          fgets(details,10000,place);
          puts(details);
          }
      fclose(place);
       }

      else
         {
         printf("\nINVALID NUMBER");
         }
   }

else if(snd==7)
   {
    printf("\n\nThe tourist spots of Sylhet Division.");
     printf("\n\t1.Madhabkunda Waterfall.\n");
    printf("\nPlease enter any valid number : ");
    scanf("%d",&snp);
    system("cls");
      if(snp==1)
       {
       FILE *place;
      char details[10000];
      place=fopen("Madhabkunda Waterfall.txt","r");
         while(!feof(place))
          {
          fgets(details,10000,place);
          puts(details);
          }
      fclose(place);
       }

      else
         {
         printf("\nINVALID NUMBER");
         }
   }

else if(snd==8)
   {
    printf("\n\nThe tourist spots of Barishal Division.");
     printf("\n\t1.Kuakata Sea Beach.\n");
    printf("\nPlease enter any valid number : ");
    scanf("%d",&snp);
    system("cls");
      if(snp==1)
       {
       FILE *place;
      char details[10000];
      place=fopen("Kuakata Sea Beach.txt","r");
         while(!feof(place))
          {
          fgets(details,10000,place);
          puts(details);
          }
      fclose(place);
       }

      else
         {
         printf("\nINVALID NUMBER");
         }
   }

else
   {
     printf("Invalid number.");
   }

SystemCall();
}


void n3()
{

  int sn;
printf("THE FAMOUS SPOTS OF BANGLADESH :\n");
printf("\nplease choose a place.\n  1.Cox’s Bazar\n  2.Khagrachari\n  3.Kuakata\n  4.Lalbagh Kella\n  5.Sundarban\n");
printf("\nplease enter the serial number of a place:");
scanf("%d",&sn);
system("cls");
if(sn==1)
   {
      FILE *place;
    char details[10000];
    place=fopen("Cox’s Bazar.txt","r");
    while(!feof(place))
       {
       fgets(details,10000,place);
       puts(details);
       }
    fclose(place);
   }

else if(sn==2)
   {
     FILE *place;
    char details[10000];
    place=fopen("Khagrachari.txt","r");
    while(!feof(place))
       {
       fgets(details,10000,place);
       puts(details);
       }
    fclose(place);
   }

else if(sn==3)
   {
     FILE *place;
    char details[10000];
    place=fopen("Kuakata.txt","r");
    while(!feof(place))
       {
       fgets(details,10000,place);
       puts(details);
       }
    fclose(place);
   }

else if(sn==4)
   {
     FILE *place;
    char details[10000];
    place=fopen("Lalbagh Kella.txt","r");
    while(!feof(place))
       {
       fgets(details,10000,place);
       puts(details);
       }
    fclose(place);
   }

else if(sn==5)
   {
    FILE *place;
    char details[10000];
    place=fopen("Sundarban.txt","r");
    while(!feof(place))
       {
       fgets(details,10000,place);
       puts(details);
       }
    fclose(place);
   }

 else
    {
     printf("Invalid number.");
    }

  SystemCall();
}

void n4()
{
char pn[25];  /*pn=place name*/
    printf("Please enter a name(for space use underscore) : ");
    scanf("%s",&pn);
     if(strcmp(pn , "Ahsan_Manzil")==0 )
    {
    FILE *place;
    char details[10000];
    place=fopen("Ahsan Manzil.txt","r");
    while(!feof(place))
       {
       fgets(details,10000,place);
       puts(details);
       }
    fclose(place);
    }

   else if(strcmp(pn , "Comilla_Moynamoti")==0 )
    {
    FILE *place;
    char details[10000];
    place=fopen("Comilla Moynamoti.txt","r");
    while(!feof(place))
       {
       fgets(details,10000,place);
       puts(details);
       }
    fclose(place);
    }

       else if(strcmp(pn , "Cox’s_Bazar")==0 )
    {
    FILE *place;
    char details[10000];
    place=fopen("Cox’s Bazar.txt","r");
    while(!feof(place))
       {
       fgets(details,10000,place);
       puts(details);
       }
    fclose(place);
    }

       else if(strcmp(pn , "Khagrachari")==0 )
    {
    FILE *place;
    char details[10000];
    place=fopen("Khagrachari.txt","r");
    while(!feof(place))
       {
       fgets(details,10000,place);
       puts(details);
       }
    fclose(place);
    }

       else if(strcmp(pn , "Kopotakkho_Nod")==0 )
    {
    FILE *place;
    char details[10000];
    place=fopen("Kopotakkho Nod.txt","r");
    while(!feof(place))
       {
       fgets(details,10000,place);
       puts(details);
       }
    fclose(place);
    }

       else if(strcmp(pn , "Kuakata")==0 )
    {
    FILE *place;
    char details[10000];
    place=fopen("Kuakata.txt","r");
    while(!feof(place))
       {
       fgets(details,10000,place);
       puts(details);
       }
    fclose(place);
    }

       else if(strcmp(pn , "Lalbagh_Kella")==0 )
    {
    FILE *place;
    char details[10000];
    place=fopen("Lalbagh Kella.txt","r");
    while(!feof(place))
       {
       fgets(details,10000,place);
       puts(details);
       }
    fclose(place);
    }

       else if(strcmp(pn , "Mahasthangarh")==0 )
    {
    FILE *place;
    char details[10000];
    place=fopen("Mahasthangarh.txt","r");
    while(!feof(place))
       {
       fgets(details,10000,place);
       puts(details);
       }
    fclose(place);
    }

       else if(strcmp(pn , "National_Botanical_Garden")==0 )
    {
    FILE *place;
    char details[10000];
    place=fopen("National Botanical Garden.txt","r");
    while(!feof(place))
       {
       fgets(details,10000,place);
       puts(details);
       }
    fclose(place);
    }

       else if(strcmp(pn , "National_Martyr’s_Memorial")==0 )
    {
    FILE *place;
    char details[10000];
    place=fopen("National Martyr’s Memorial.txt","r");
    while(!feof(place))
       {
       fgets(details,10000,place);
       puts(details);
       }
    fclose(place);
    }

       else if(strcmp(pn , "National_Shangshad_Bhabon")==0 )
    {
    FILE *place;
    char details[10000];
    place=fopen("National Shangshad Bhabon.txt","r");
    while(!feof(place))
       {
       fgets(details,10000,place);
       puts(details);
       }
    fclose(place);
    }

       else if(strcmp(pn , "Rangamati")==0 )
    {
    FILE *place;
    char details[10000];
    place=fopen("Rangamati.txt","r");
    while(!feof(place))
       {
       fgets(details,10000,place);
       puts(details);
       }
    fclose(place);
    }

       else if(strcmp(pn , "Saint_Martin")==0 )
    {
    FILE *place;
    char details[10000];
    place=fopen("Saint Martin.txt","r");
    while(!feof(place))
       {
       fgets(details,10000,place);
       puts(details);
       }
    fclose(place);
    }

       else if(strcmp(pn , "Sajek_valley")==0 )
    {
    FILE *place;
    char details[10000];
    place=fopen("Sajek valley.txt","r");
    while(!feof(place))
       {
       fgets(details,10000,place);
       puts(details);
       }
    fclose(place);
    }

       else if(strcmp(pn , "Shatgombuj_Mosque")==0 )
    {
    FILE *place;
    char details[10000];
    place=fopen("Shatgombuj Mosque.txt","r");
    while(!feof(place))
       {
       fgets(details,10000,place);
       puts(details);
       }
    fclose(place);
    }

      else if(strcmp(pn , "Sundarban")==0 )
    {
    FILE *place;
    char details[10000];
    place=fopen("Sundarban.txt","r");
    while(!feof(place))
       {
       fgets(details,10000,place);
       puts(details);
       }
    fclose(place);
    }
    else
    {
        printf("INVALID PLACE.");
    }

  SystemCall();

}



void SystemCall()
{
    int MM;
   printf("\n\n\t*SELECT AN OPTION*\n\t1.Guideline System\n\t2.Management System\n\t3.Main Menu\n\tPlease enter your choice : ");
scanf("%d",&MM);
system("cls");
if (MM==1)
{
   guideline();
}
else if (MM==2)
{
  mamagement();
}
else if (MM==3)
{
  MainFunction();
}

else
    {
    printf("Invalid number.");
   }
}

///////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////
void guideline()
{

    printf(" \t\t\t      Welcome to the Guideline System        ");
    printf(" \n\t\t\t****************************************\n");
    printf(" \n\t\t\t*       :PLEASE SELECT AN OPTION:      *\n");
    printf(" \n\t\t\t\t1. All tourist spots           ");
    printf(" \n\t\t\t\t2. Division Wise               ");
    printf(" \n\t\t\t\t3. Famous Spots                ");
    printf(" \n\t\t\t\t4. Search by Name              ");
    printf(" \n\t\t\t****************************************\n");
    printf("Please enter a valid number : ");
    scanf("%d",&nmbr);
    if (nmbr==1)
    {
        system("cls");
        n1();
    }
    else if(nmbr==2)
    {
        system("cls");
        n2();
    }
    else if(nmbr==3)
    {
        system("cls");
        n3();
    }
    else if(nmbr==4)
    {
        system("cls");
        n4();
    }

    else
    {
     printf("invalid number.");
    }

}


