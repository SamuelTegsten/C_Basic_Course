#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXAMNEN 1001
#define MAXORDLANGD 21
#define MAXFIL 100
struct amnenlista
{
    char amnen[MAXORDLANGD];
    int masstal;
    double halveringstid;
};
typedef struct amnenlista AmnenLista;

AmnenLista skapaAmnen(char amnen[], int masstal, double halveringstid);
void readFromFile(AmnenLista AmnenRegistrera[],char filNamn[], int *pNrAvAmnen);
int registreraNyaAmnen(AmnenLista AmnenRegistrera[], int *pNrAvAmnen);
void visaAmnen(AmnenLista AmnenRegistrera[],int *pNrAvAmnen,int *taBort);
void sorteraAmnen(AmnenLista AmnenRegistrera[], int *pNrAvAmnen);
int jamforAmnen(const void *tmp1, const void *tmp2);
int jamforMasstal(const void *tmp1, const void *tmp2);
int jamforHalveringstid(const void *tmp1, const void *tmp2);
int sokaElement(AmnenLista AmnenRegistrera[], int *pNrAvAmnen,int *plats,int *taBort);
int sokaMasstal(AmnenLista AmnenRegistrera[], int *pNrAvAmnen,int *plats,int *taBort);
int sokaHalveringstid(AmnenLista AmnenRegistrera[], int *pNrAvAmnen,int *plats,int *taBort);
void sokaAmnen(AmnenLista AmnenRegistrera[], int *pNrAvAmnen,int *plats, int *taBort);
void andraHalveringstid(AmnenLista AmnenRegistrera[], int *pNrAvAmnen,int *plats, int *taBort);
void avregistreraAmne(AmnenLista AmnenRegistrera[], int *pNrAvAmnen,int *plats,int *taBort);
void tabortAmne(AmnenLista AmnenRegistrera[], int *pNrAvAmnen,int *plats,int *taBort);
void avsluta(AmnenLista AmnenRegistrera[],char filNamn[], int *pNrAvAmnen, int *taBort);

int main()
{
    AmnenLista AmnenRegistrera[MAXAMNEN];
    char Filnamn[MAXFIL];
    int i, val;
    int pNrAvAmnen = 0;
    int plats = 0;
    int taBort =0;
    readFromFile(AmnenRegistrera,Filnamn,&pNrAvAmnen);
    while(1)
    {
        printf("(1) Registrera nya radioaktiva amnen\n");
        printf("(2) Alla amnen\n");
        printf("(3) Sortera amnen\n");
        printf("(4) Soka efter amnen\n");
        printf("(5) Andra halveringstid\n");
        printf("(6) Avregistrera amne\n");
        printf("(7) Avsluta\n");
        printf("Ange val: ");
        scanf("%d[^\n]%*c", &val);
        if(val==1)
        {
            registreraNyaAmnen(AmnenRegistrera, &pNrAvAmnen);
        }
        else if(val==2)
        {
            visaAmnen(AmnenRegistrera, &pNrAvAmnen, &taBort);
        }
        else if(val==3)
        {
            sorteraAmnen(AmnenRegistrera, &pNrAvAmnen);
        }
        else if(val==4)
        {
            sokaAmnen(AmnenRegistrera, &pNrAvAmnen,&plats,&taBort);
        }
        else if(val==5)
        {
            andraHalveringstid(AmnenRegistrera, &pNrAvAmnen,&plats,&taBort);
        }
        else if(val==6)
        {
            avregistreraAmne(AmnenRegistrera, &pNrAvAmnen,&plats, &taBort);
        }
        else if(val==7)
        {
            avsluta(AmnenRegistrera,Filnamn, &pNrAvAmnen, &taBort);
            break;    
        }
        else if(val>=8 || val==0)
        {
            printf("Ditt nummer maste vara mellan 1-7");
        }
        else;
    }
    return 0;
}

AmnenLista skapaAmnen(char amnen[], int masstal, double halveringstid)
{
    AmnenLista c;
    strcpy(c.amnen, amnen);
    c.masstal=masstal;
    c.halveringstid=halveringstid;
    return c;
}

void readFromFile(AmnenLista AmnenRegistrera[],char filNamn[], int *pNrAvAmnen)
{
    printf("Ange textfil: ");
    scanf("%s[^\n]%*c",filNamn);
    FILE *fp;
    fp=fopen(filNamn,"r");
    if(fp!=NULL)
    {
        char amnen[MAXORDLANGD];
        int masstal;
        double halveringstid;
        while(fscanf(fp,"%s %d %lf",amnen,&masstal,&halveringstid)==3)
        {
            fgets(AmnenRegistrera[*pNrAvAmnen].amnen, MAXORDLANGD,fp);
            AmnenRegistrera[*pNrAvAmnen]=skapaAmnen(amnen,masstal,halveringstid);
            (*pNrAvAmnen)++;
            if(*pNrAvAmnen == MAXAMNEN)
            {
                printf("Max filstorlek är 1000\n");
                fclose(fp);
                return;
            }
        }
        fclose(fp);
        printf("Filen finns\n");
    }
    else
    {
        printf("Tom fil\n");
    } 
}

int registreraNyaAmnen(AmnenLista AmnenRegistrera[], int *pNrAvAmnen)
{
    int i;
    char storbokstav[MAXORDLANGD];
    char TidOmvandlare[MAXORDLANGD];
    int *pJamforPlats;
    printf("Registrera nya radioaktiva amnen\n");
    while(1)
    {   
        if(*pNrAvAmnen == MAXAMNEN) 
    {
            printf("Max antal filer ar uppnatt\n");
            return *pNrAvAmnen;
    }
    for(i=0;i<=*pNrAvAmnen;i++)
    {
        printf("Ange namn (q for att avsluta): ");
        fgetc(stdin);
        fgets(storbokstav, MAXORDLANGD, stdin);
        storbokstav[strlen(storbokstav)-1]='\0';
        storbokstav[i] = toupper(storbokstav[i]);
        strcpy(AmnenRegistrera[*pNrAvAmnen].amnen,storbokstav);
        break;
    }
        char *testQ = AmnenRegistrera[*pNrAvAmnen].amnen;
        if(*testQ == 'Q')
        {
            return *pNrAvAmnen;
        }
        printf("Ange masstal: ");
        scanf("%d[^\n]%*c\n",&AmnenRegistrera[*pNrAvAmnen].masstal);
        for(int i=0;i<=*pNrAvAmnen-1;i++)
        {
            *pJamforPlats = i;
            if((strcmp(AmnenRegistrera[i].amnen,AmnenRegistrera[*pNrAvAmnen].amnen)==0 && AmnenRegistrera[i].masstal==AmnenRegistrera[*pNrAvAmnen].masstal)&&*pNrAvAmnen!=0)
            {
                printf("Amnet ar redan registrerat\n");
                break;
            }  
        }
        if(*pJamforPlats+1==*pNrAvAmnen || *pNrAvAmnen ==0)
        {
            printf("Halveringstid (s,min,h,dagar,ar): ");
            scanf("%lf %s[^\n]%*c\n", &AmnenRegistrera[*pNrAvAmnen].halveringstid, TidOmvandlare);
            if(strcmp(TidOmvandlare,"min")==0)
            {
                double min_halveringstid = AmnenRegistrera[*pNrAvAmnen].halveringstid;
                min_halveringstid = min_halveringstid * 60.0f;
                AmnenRegistrera[*pNrAvAmnen].halveringstid = min_halveringstid;
            }
            else if(strcmp(TidOmvandlare,"h")==0)
            {
                double h_halveringstid = AmnenRegistrera[*pNrAvAmnen].halveringstid;
                h_halveringstid = h_halveringstid * 3600.0f;
                AmnenRegistrera[*pNrAvAmnen].halveringstid = h_halveringstid;
            }
            else if(strcmp(TidOmvandlare,"dagar")==0)
            {
                double dagar_halveringstid = AmnenRegistrera[*pNrAvAmnen].halveringstid;
                dagar_halveringstid = dagar_halveringstid * 86400.0f;
                AmnenRegistrera[*pNrAvAmnen].halveringstid = dagar_halveringstid;
            }
            else if(strcmp(TidOmvandlare,"ar")==0)
            {
                double ar_halveringstid = AmnenRegistrera[*pNrAvAmnen].halveringstid;
                ar_halveringstid = ar_halveringstid * 31536000.0f;
                AmnenRegistrera[*pNrAvAmnen].halveringstid = ar_halveringstid;
            }  
            else(strcmp(TidOmvandlare,"s")==0);
            {
                AmnenRegistrera[*pNrAvAmnen].halveringstid = AmnenRegistrera[*pNrAvAmnen].halveringstid;
            }
            (*pNrAvAmnen)++;
        }
    }
}

void visaAmnen(AmnenLista AmnenRegistrera[],int *pNrAvAmnen,int *taBort)
{
    if(*pNrAvAmnen==0)
    {
        printf("Filen ar tom\n");
        return;
    }
    else;
    printf("Namn\t   Masstal\t  Halveringstid(s)\n");
    for(int i=0;i<*pNrAvAmnen-*taBort;i++)
    {
        printf("%s\t      %d\t   %.4e\n",AmnenRegistrera[i].amnen, AmnenRegistrera[i].masstal,AmnenRegistrera[i].halveringstid);
    }
}

void sorteraAmnen(AmnenLista AmnenRegistrera[], int *pNrAvAmnen)
{
    int val,i,j;
    if(*pNrAvAmnen==0)
    {
        printf("Filen ar tom\n");
        return;
    }
    printf("Vill du sortera efter namn(1), masstal(2) eller halveringstid(3): ");
    scanf("%d[^\n]%*c", &val);
    if(val==1)
    {
        for(i=0;i<*pNrAvAmnen;i++)
        {
            for(j=i+1;j<*pNrAvAmnen;j++)
            {
                if(strcmp(AmnenRegistrera[i].amnen,AmnenRegistrera[j].amnen)>0)
                {
                    qsort(AmnenRegistrera, *pNrAvAmnen, sizeof(AmnenLista), jamforAmnen);
                }
            }
        }
    }
    if(val==2)
    {
        for(i=0;i<*pNrAvAmnen;i++)
        {
            for(j=i+1;j<*pNrAvAmnen;j++)
            {
                if(AmnenRegistrera[i].masstal<AmnenRegistrera[j].masstal)
                {
                    qsort(AmnenRegistrera, *pNrAvAmnen, sizeof(AmnenLista), jamforMasstal);
                }
            }
        }
    }
    if(val==3)
    {
        for(int sort=0;sort<*pNrAvAmnen;sort++)
        {
            for(i=0;i<*pNrAvAmnen;i++)
            {
                for(j=i+1;j<*pNrAvAmnen;j++)
                {
                    if(AmnenRegistrera[i].halveringstid<AmnenRegistrera[j].halveringstid)
                    {
                        qsort(AmnenRegistrera, *pNrAvAmnen, sizeof(AmnenLista), jamforHalveringstid);
                    }
                }
            }
        }
    }
}

int jamforAmnen(const void *tmp1, const void *tmp2)
{
    const AmnenLista *t1 = tmp1; 
    const AmnenLista *t2 = tmp2;
    return strcmp(t1 ->amnen, t2 ->amnen);
}

int jamforMasstal(const void *tmp3, const void *tmp4)
{
    const AmnenLista *t3 = tmp3; 
    const AmnenLista *t4 = tmp4;
    return(t4->masstal - t3->masstal);
}

int jamforHalveringstid(const void *tmp5, const void *tmp6)
{
    const AmnenLista *t5 = tmp5; 
    const AmnenLista *t6 = tmp6;
    return(t6->halveringstid - t5->halveringstid);
}

void sokaAmnen(AmnenLista AmnenRegistrera[], int *pNrAvAmnen,int *plats, int *taBort)
{
    int val, i;
    double letaHalveringstid_MIN, letaHalveringstid_MAX;
    if(*pNrAvAmnen==0)
    {
        printf("Filen ar tom\n");
        return;
    }
    while(i=i++)
    {
        printf("Hur vill du soka?\n");
        printf("(1) namn\n");
        printf("(2) masstal\n");
        printf("(3) halveringstid\n");
        printf("(4) huvudmeny\n");
        scanf("%d[^\n]%*c", &val);
        if(val==1)
        {
            sokaElement(AmnenRegistrera, pNrAvAmnen, plats, taBort);
        }
        else if(val==2)
        {
            sokaMasstal(AmnenRegistrera, pNrAvAmnen, plats, taBort);
        }
        else if(val==3)
        {
            sokaHalveringstid(AmnenRegistrera, pNrAvAmnen, plats, taBort);
        }
        else if(val==4)
        {
            return;
        }
        else;
    }
}

int sokaElement(AmnenLista AmnenRegistrera[], int *pNrAvAmnen,int *plats,int *taBort)
{
    int i;
    char letaStrang[MAXORDLANGD];
    int raknare=0;
    int *plats1=0;
    printf("Ange sokstrang: ");
    scanf("%s[^\n]%*c\n", letaStrang);
    for(i=0;i<*pNrAvAmnen-*taBort;i++)
    {
        char *ptr =strstr(AmnenRegistrera[i].amnen, letaStrang);
        if(ptr !=NULL)
        {
            printf("%s %d %20.4e\n", AmnenRegistrera[i].amnen, AmnenRegistrera[i].masstal,AmnenRegistrera[i].halveringstid);
            raknare++;
            *plats=i;
        }
        else;
    }
    return raknare;
}

int sokaMasstal(AmnenLista AmnenRegistrera[], int *pNrAvAmnen,int *plats,int *taBort)
{
    int i, letaMasstal;
    int raknare=0;
    int *plats2=0;
    printf("Ange val: ");
    scanf("%d[^\n]%*c\n", &letaMasstal);
    for(i=0;i<*pNrAvAmnen-*taBort;i++)
    {
        if(AmnenRegistrera[i].masstal==letaMasstal)
        {
            printf("%s %d %20.4e\n", AmnenRegistrera[i].amnen, AmnenRegistrera[i].masstal,AmnenRegistrera[i].halveringstid);
            raknare++;
            *plats=i;
        }
        else;
    }    
    return raknare;
}

int sokaHalveringstid(AmnenLista AmnenRegistrera[], int *pNrAvAmnen,int *plats,int *taBort)
{
    double letaHalveringstid_MIN, letaHalveringstid_MAX;
    int i;
    int raknare=0;
    printf("Ange minsta halveringstid: ");
    scanf("%lf[^\n]%*c\n",&letaHalveringstid_MIN);
    printf("Ange storsta halveringstid: ");
    scanf("%lf[^\n]%*c\n",&letaHalveringstid_MAX);
    for(i=0;i<*pNrAvAmnen-*taBort;i++)
    {
        if(letaHalveringstid_MIN <= AmnenRegistrera[i].halveringstid && letaHalveringstid_MAX >= AmnenRegistrera[i].halveringstid)
        {
            printf("%s %d %20.4e\n", AmnenRegistrera[i].amnen, AmnenRegistrera[i].masstal,AmnenRegistrera[i].halveringstid);
            raknare++;
            *plats=i;
        }
        else;
    }
    return raknare;
}

void andraHalveringstid(AmnenLista AmnenRegistrera[], int *pNrAvAmnen,int *plats, int *taBort)
{
    int i,val, antal1 ,antal2 ,antal3;
    double nyHalveringstid,nyHalveringstid2,nyHalveringstid3;
    if(*pNrAvAmnen==0)
    {
        printf("Filen ar tom\n");
        return;
    }
    printf("Andra halveringstid\n");
    while(i=i++)
    {
        printf("Vill du soka pa namn (1), masstal (2), halveringstid(3): ");
        scanf("%d[^\n]%*c\n", &val);
        if(val==1)
        {
            antal1= sokaElement(AmnenRegistrera, pNrAvAmnen,plats,taBort);
            if(antal1 ==0 || antal1 >=2)
            {
                printf("Du fick inte exakt ett resultat.\n");
                continue;
            }
            else if(antal1 ==1)
            {
                printf("Ange ny halveringstid: ");
                scanf("%lf[^\n]%*c\n", &AmnenRegistrera[*plats].halveringstid);
                return;
            }
        }
        else if(val==2)
        {
            antal2= sokaMasstal(AmnenRegistrera, pNrAvAmnen,plats,taBort);
            if(antal2 ==0 || antal2 >=2)
            {
                printf("Du fick inte exakt ett resultat.\n");
                continue;
            }
            else if(antal2 ==1)
            {
                printf("Ange ny halveringstid: ");
                scanf("%lf[^\n]%*c\n", &AmnenRegistrera[*plats].halveringstid);
                return;
            }
        }
        else if(val==3)
        {
            antal3= sokaHalveringstid(AmnenRegistrera, pNrAvAmnen,plats,taBort);
            if(antal3 ==0 || antal3 >=2)
            {
                printf("Du fick inte exakt ett resultat.\n");
                continue;
            }
            else if(antal3 ==1)
            {
                printf("Ange ny halveringstid: ");
                scanf("%lf[^\n]%*c\n", &AmnenRegistrera[*plats].halveringstid);
                return;
            }
        }
        else;
    }
}

void avregistreraAmne(AmnenLista AmnenRegistrera[], int *pNrAvAmnen,int *plats,int *taBort)
{
    int i,val, antal1 ,antal2 ,antal3;
    if(*pNrAvAmnen==0)
    {
        printf("Filen ar tom\n");
        return;
    }
    printf("Avregistrera\n");
    while(i=i++)
    {
        printf("Vill du soka pa namn (1), masstal (2), halveringstid(3): ");
        scanf("%d[^\n]%*c\n", &val);
        if(val==1)
        {
            antal1=sokaElement(AmnenRegistrera, pNrAvAmnen,plats,taBort);
            if(antal1 ==0 || antal1 >=2)
            {
                printf("Du fick inte exakt ett resultat.\n");
                return;
            }   
            else if(antal1 ==1)
            {
                tabortAmne(AmnenRegistrera, pNrAvAmnen,plats,taBort);
                return;
            }
        }
        else if(val==2)
        {
            antal2=sokaMasstal(AmnenRegistrera, pNrAvAmnen,plats,taBort);
            if(antal2 ==0 || antal2 >=2)
            {
                printf("Du fick inte exakt ett resultat.\n");
                return;
            }
            else if(antal2 ==1)
            {
                tabortAmne(AmnenRegistrera, pNrAvAmnen,plats,taBort);
                return;
            }
        }
        else if(val==3)
        {
            antal3=sokaHalveringstid(AmnenRegistrera, pNrAvAmnen,plats,taBort);
            if(antal3 ==0 || antal3 >=2)
            {
                printf("Du fick inte exakt ett resultat.\n");
                return;
            }
            else if(antal3 ==1)
            {
                tabortAmne(AmnenRegistrera, pNrAvAmnen,plats,taBort);
                return;
            }
        }
        else;
    }  
}
void tabortAmne(AmnenLista AmnenRegistrera[], int *pNrAvAmnen,int *plats,int *taBort)
{
    int i;
    (*taBort=*taBort+1);
    printf("%s-%d avregistreras\n",AmnenRegistrera[*plats].amnen, AmnenRegistrera[*plats].masstal);
    for(i=*plats;i < *pNrAvAmnen - 1;i++)
    {
        AmnenRegistrera[i]=AmnenRegistrera[i+1];
    }
}

void avsluta(AmnenLista AmnenRegistrera[],char filNamn[], int *pNrAvAmnen, int *taBort)
{
    if(*pNrAvAmnen==0)
    {
        printf("Filen ar tom\n");
    }
    printf("%s sparas\n", filNamn);
    FILE *fp;
    fp=fopen(filNamn,"w");
    if(fp!=NULL)
    {
        AmnenRegistrera[MAXAMNEN];
        int masstal;
        double halveringstid;
        for(int i=0;i<*pNrAvAmnen-*taBort;i++)
        {
            fprintf(fp,"%s %d %.4e\n", AmnenRegistrera[i].amnen, AmnenRegistrera[i].masstal, AmnenRegistrera[i].halveringstid);          
        }
    fclose(fp);
    }
}