#include "header.h"

bool isEmptyStatus (List *L)
{
    if (L->first == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void CreateListStatus(List &L)
{
    L.first=NULL;
    L.last=NULL;
}

address alokasi(status x)
{
    address p = new element_status;
    if (p != NULL)
    {
        p->infos = x;
        p->next = NULL;
    }
    else
    {
        cout << "Alokasi Gagal" << endl;
    }
    return p;
}

void insertFirstStatus (List &L, address P)
{
    if (L.first == NULL)
    {
        L.first = P;
        L.last = P;
        L.last->next = L.first;
        L.first->prev = L.last;
    }
    else
    {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
        L.last->next = L.first;
        L.first->prev = L.last;
    }
}

void insertAfterStatus (List &L, address P, address Q)
{
        P->next = Q->next;
        Q->next->prev = P;
        Q->next = P;
        P->prev = Q;
}

void insertLastStatus (List &L, address P)
{
    L.last->next = P;
    P->prev = L.last;
    P->next = L.first;
    L.first->prev = P;
    L.last = P;
}


address findStatus(List &L, status x)
{
    address P = L.first;
    while (P != NULL)
    {
        if (P->infos.id_status == x.id_status)
        {
            return P;
        }
        P = P->next;
    }
    return 0;
}

void EditStatus(List &L,status x)
{
    address p=L.first;
    string s;
    if(L.first==NULL)
    {
        cout<<"Data Kosong"<<endl;
    }
    else if (p!=NULL)
    {
        findStatus(L,x);
        cout<<"Masukkan Status: ";
        cin>>s;
        p->infos.stats=s;
        cout<<"Status Berhasil Diedit";
    }
}

void inputStatus(status s)
{
    cout<<"INPUT STATUS"<<endl;
    cout<<"=============="<<endl;
    cout<<"Masukkan ID : ";
    cin>>s.id_status;
    cout<<"Masukkan Status : ";
    cin>>s.stats;
}
