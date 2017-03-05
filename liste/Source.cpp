#include <iostream>
using namespace std;
typedef struct nod{
	int nr;
	struct nod *urm;
}NOD;

NOD *varf, *cursor;

void creeaza()
{
	varf=NULL;
	cursor=varf;
}

int vida()
{	
	if (varf==NULL) return 1;
	else return 0;
}

void primul()
{
	cursor=varf;
}

int urmatorul()
{
	if (cursor->urm!=NULL){
		cursor=cursor->urm;
		return 1;
	}
	else{ cout<<"Suntem la final de lista.";
	cout<<"Nu se poate trece la urmatorul nod"<<endl;
	return 0;
	}
}

void adauga_cap(int a)
{
	NOD *p=new NOD;
	//p=(struct nod *)malloc(sizeof(struct nod));
	p->nr=a;
	p->urm=varf;
	varf=p;
	cursor=p;
}

void adauga_dupa(int a)
{
	NOD *p=new NOD;
	if (vida()) adauga_cap(a);
	else{
		//p=(struct nod *)malloc(sizeof(struct nod));
		p->nr=a;
		p->urm=cursor->urm;
		cursor->urm=p;
		cursor=p;
	}
}

void cauta(int a)
{
	NOD *p;
	int n=0;
	p=varf;
	while ((p!=NULL)&&(p->nr!=a)){
		n++;
		p=p->urm;
	}
	if (p!=NULL) 
		cout<<a <<" este al "<< n+1 <<"-lea element din lista"<<endl;
	else cout<<a<<" nu este in lista"<<endl;
}

void tiparire()
{
  NOD *p;
  p=varf;
  cout<<"Lista contine : "<<endl;
  while (p!=NULL)
  {
    cout<<p->nr<<endl;
    p=p->urm;
  }
}

void stergere(int a)
{
	NOD *p,*prec;
	p=varf;
	prec=NULL;
	while ((p!=NULL)&&(a!=p->nr)){
		prec=p;
		p=p->urm;
	}
	if (p!=NULL){
		if (p==varf) varf=varf->urm;
		else prec->urm=p->urm;
		delete(p); // sau free(p);
		cout<<"Nodul a fost sters "<<endl;
		cursor=varf;
	}
	else
		cout<<"Numarul nu este in lista"<<endl;
}

void actualizeaza(int a)
{
	cursor->nr=a;
}

int extrage()
{
	return cursor->nr;
}


void adauga_inainte(int b,int a)
{
	NOD *p,*prec,*q=new NOD;
	p=varf;
	prec=NULL;
	while ((p!=NULL)&&(b!=p->nr)){
		prec=p;
		p=p->urm;
	}
	if (p!=NULL){
		//q=(struct nod *)malloc(sizeof(struct nod));
		q->nr=a;
		if (p==varf){
			q->urm=varf;
			varf=q;
		}
		else{
			q->urm=p;
			prec->urm=q;
		}
	}
	else cout<<"Nu exista "<<b<<" in lista"<<endl;
}

int main(){
	int r=1,a,i,b;
	creeaza();  
	while (r!=0)
	{
		cout<<"Meniu:"<<endl;
		cout<<"1. Insereaza un element in capul listei" <<endl;
		cout<<"2. Insereaza un element dupa elementul curent" <<endl;
		cout<<"3. Insereaza un element inaintea unui element"<<endl;
		cout<<"4. Actualizeaza elementul curent din lista"<<endl;
		cout<<"5. Cauta un element in lista"<<endl;
		cout<<"6. Pozitioneaza cursorul pe prima pozitie a  listei"<<endl;
		cout<<"7. Pozitioneaza cursorul pe urmatoarea pozitie din lista"<<endl;
		cout<<"8. Extrage valoarea elementului curent"<<endl;
		cout<<"9. Sterge un element din lista"<<endl;
		cout<<"10.Testeaza daca lista este vida"<<endl;
		cout<<"11.Tipareste elementele listei"<<endl;
		cout<<"0. Termina executia programului"<<endl;
		cout<<"Alegeti obtiunea: ";
		cin>>r;
		switch(r)
		{
			case 1: cout<<"Dati numarul care doriti sa-l adaugati: ";
				cin>>a;
				adauga_cap(a);
				break;
			case 2: cout<<"Dati numarul care doriti sa-l adaugati: ";
				cin>>a;
				adauga_dupa(a);
				break;
			case 3: cout<<"Dati numarul in fata caruia doriti sa adaugati: ";
				cin>>b;
	  			cout<<"Dati numarul care doriti sa-l adaugati: ";
				cin>>a;
	    			adauga_inainte(b,a);
				break;
			case 4: cout<<"Dati numarul cu care doriti sa-l actualizati: ";
				cin>>a;
	   			actualizeaza(a);
				break;
			case 5: cout<<"Dati numarul pe care doriti sa-l cautati: ";
				cin>>a;
				cauta(a);
				break;
			case 6: primul();
				cout<<"Pozitionarea a fost facuta"<<endl;
				break;
			case 7: i=urmatorul();
				if (i==1)
				cout<<"Pozitionarea a fost facuta"<<endl;
				break;
			case 8: i=extrage();
				cout<<"Nodul curent are valoarea "<<i<<endl;
				break;
			case 9: cout<<"Dati numarul pe care doriti sa-l stergeti: ";
				cin>>a;
	  			stergere(a);
				break;
			case 10: if (vida()) cout<<"Lista este vida"<<endl;
				else cout<<"Lista nu este vida"<<endl;
				break;
			case 11: tiparire();break;
			case 0: break;
			default:cout<<"Ati dat o optiune gresita"<<endl; 
		}
	}


}