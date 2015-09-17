//  tugaskelompokpegawai.cpp
//  MUHAMAD RIFKY ADHANI - 1103134368
//  CHANDRA GILANG K
//  YOBEL
//  REYNALDO 

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <iomanip>

using namespace std;

int isEmpty(list l)
{
    if(first(l) == NULL)
        return true;
    else
        return false;
}

int isFull(list l)
{
    if(l.mark==15)
        return 1;
    else
        return 0;
}

void insertFirst(list *l, infotype x)
{
    address p;
    p=(address)malloc(sizeof(elm));
    info(p)=x;
    prev(p)=NULL;
    if(isEmpty(*l)==1)
    {
        next(p)=NULL;
        first(*l)=p;
        last(*l)=p;
    }
    else
    {
        next(p)=first(*l);
        prev(first(*l))=p;
        first(*l)=p;
    }
}

void insertLast(list *l, infotype x)
{
    address p;
    p=(address)malloc(sizeof(elm));
    info(p)=x;
    next(p)=NULL;
    next(last(*l))=p;
    prev(p)=last(*l);
    last(*l)=p;
}

void insertAfter(list *l, infotype x)
{
    address p;
    p=(address)malloc(sizeof(elm));
    info(p)=x;
    next(p)=NULL;
    next(last(*l))=p;
    prev(p)=last(*l);
    last(*l)=p;
}

void insertBefore(list *l, infotype x)
{
    address p, q;
    q=next(first(*l));
    while(x.tahunmasuk>info(q).tahunmasuk)
        q=next(q);
    p=(address)malloc(sizeof(elm));
    info(p)=x;
    prev(p)=prev(q);
    next(prev(q))=p;
    next(p)=q;
    prev(q)=p;
}

void insert(list *l, infotype x)
{
    if(isFull(*l)==1)
    {
        cout<<"penuh !!!"<<endl;
        getch();
    }
    else
    {
        if(isEmpty(*l)==1 || x.tahunmasuk<=info(first(*l)).tahunmasuk)
            insertFirst(&(*l),x);
        else if(x.tahunmasuk>info(last(*l)).tahunmasuk)
            insertLast(&(*l),x);
        else
            insertBefore(&(*l),x);
        (*l).mark++;
    }
}

void deleteFirst(list *l)
{
    if(isEmpty(*l)==1)
        cout<<"data kosong"<<endl;
    else
    {
        address p = first(*l);

        if(next(first(*l)) == NULL)
        {
            first(*l) = NULL;
            free(p);
        }
        else
        {
            first(*l) = next(first(*l));
            next(p) = NULL;
            free(p);
        }
    }
}

void deleteLast(list *l)
{
    if(isEmpty(*l)==1){
       cout<<"\n List kosong, tidak ada data untuk dihapus."<<endl;
        getch();
    }
    else
    {
        address p;
        p=last(*l);

        next(prev(p))=NULL;
        last(*l)=prev(p);
        prev(p)=NULL;

        cout<<"Pegawai urutan terakhir dengan nama %s telah p.", info(p).nama<<endl;
        free(p);
        getch();
        (*l).mark--;
    }
}

void deleteAfter(list *l)
{
    address p;
    p = next(*l);
    next(*l) = next(next(*l));
    free(p);
}

void searchData(list l){

}

void viewAll(list l)
{
    if(isEmpty(l)==1)
        cout<<"\n List kosong, tidak ada data untuk ditampilkan."<<endl;
    else
    {
        system("cls");
        address p;
        p=first(l);
        cout<<"Data Pegawai: \n\n"<<endl;
        while(p!=last(l))
        {
            cout<<"i++ [ %d ] %s masuk kerja pada tahun : %d ",info(p).id, info(p).nama, info(p).tahunmasuk<<endl;
            p=next(p);
        }
        cout<<"i++ [ %d ] %s masuk kerja pada tahun : %d ",info(p).id, info(p).nama, info(p).tahunmasuk<<endl;
    }
    getch();
}
