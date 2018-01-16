#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <string>
using namespace std;
enum Seme{Bastoni=0,Coppe,Denari,Spade};
string Semi[]={"Bastoni","Coppe","Denari","Spade"};
const int punteggio[10]={11,0,10,0,0,0,0,2,3,4};
const int NumCarte=40;

int iniziale;
    struct carta{
    Seme seme;
    int valore;
    int punteggio;

};
void mescolamento(carta m[]){
  for(int i=0;i<NumCarte;i++){
    int r=rand() % NumCarte;
    carta temp=m[i];
    m[i]=m[r];
    m[r]=temp;
  }

}
void creaMazzo(carta m[]){
    int k=0;
    for(int i=1;i<=10;i++){
        for(int j=0;j<4;j++){
            carta c;
            c.seme=static_cast<Seme>(j);
            c.valore=i;
            c.punteggio=punteggio[c.valore-1];
            m[k]=c;
            k++;
        }

      }

}
void stampaMazzo(carta m[]){
    for(int i=0;i<NumCarte;i++){
        cout<<"seme: "<<m[i].seme<<" valore: "<<m[i].valore<<" punteggio: "<<m[i].punteggio<<endl;
    }
}
void manoIniziale(carta manoUtente[],carta manoIa[],carta mazzo[],int &numCarteRimaste){
    for(int i=0;i<3;i++){
        manoUtente[i]=mazzo[numCarteRimaste-1];
        numCarteRimaste--;
        manoIa[i]=mazzo[numCarteRimaste-1];
        numCarteRimaste--;
    }
}
void pesca(carta mano[],carta mazzo[],int sceltaUtente,int &numCarteRimaste){
    mano[sceltaUtente-1]=mazzo[numCarteRimaste-1];
}
void stampaMano(carta mano[]){
    for(int i=0;i<3;i++){
            if(mano[i].valore!=0)
                cout<<i+1<<": "<<mano[i].valore<<" di "<<Semi[mano[i].seme]<<endl;
    }
}
void giocatoreIniziale(int &iniz){
iniz=rand()%2;
    if(iniz==0)
        cout<<"Inizia il giocatore"<<endl;
    else if(iniz==1)
        cout<<"Inizia il Computer"<<endl;
}
void stampaTerra(carta terra[]){
    cout<<endl<<"A terra ci sono:"<<endl<<"-----------------------------------------"<<endl;
    for(int i=0;i<2;i++){
        cout<<terra[i].valore<<" di "<<Semi[terra[i].seme]<<endl;
    }
}
void giocaCarta(carta terra[], carta manoUtente[],int &sceltaUtente,carta mazzo[],int &numCarteRimaste){
    carta cartaVuota;
    cartaVuota.valore=0;
    cartaVuota.seme=Bastoni;
    cout<<endl<<"Scegli la carta da lanciare "<<endl;
    stampaMano(manoUtente);
    cin>>sceltaUtente;
    while((manoUtente[sceltaUtente-1].valore==cartaVuota.valore)||(sceltaUtente!=1&&sceltaUtente!=2&&sceltaUtente!=3)){
        cout<<"Scelta Non Valida"<<endl;
        cin>>sceltaUtente;
    }
    if(numCarteRimaste<=0){
        terra[iniziale]=manoUtente[sceltaUtente-1];
        manoUtente[sceltaUtente-1]=cartaVuota;
    }
    else if(numCarteRimaste>0){
    terra[iniziale]=manoUtente[sceltaUtente-1];
    manoUtente[sceltaUtente-1]=mazzo[numCarteRimaste-1];
    }
    numCarteRimaste--;

}
void giocaCartaIaRandom(carta terra[], carta manoIa[],int &sceltaIa,carta mazzo[],int &numCarteRimaste){
    carta cartaVuota;
    cartaVuota.valore=0;
    cartaVuota.seme=Bastoni;
    do
    sceltaIa=rand()%3;//applicare intelligenza artificiale
    while(manoIa[sceltaIa].valore==0);

    if(numCarteRimaste<=0){
            terra[!iniziale]=manoIa[sceltaIa];
            manoIa[sceltaIa]=cartaVuota;
        }
        else if(numCarteRimaste>0){
            terra[!iniziale]=manoIa[sceltaIa];
            manoIa[sceltaIa]=mazzo[numCarteRimaste-1];
        }

    numCarteRimaste--;

    cout<<"-----------------------------------------"<<endl<<"Il computer ha giocato: "<<terra[!iniziale].valore<<" di "<<Semi[terra[!iniziale].seme]<<endl;

}
void giocaCartaIa(carta terra[], carta manoIa[],int &sceltaIa,carta mazzo[],int &numCarteRimaste,int iniziale,carta briscola){
    carta cartaVuota;
    cartaVuota.valore=0;
    cartaVuota.seme=Bastoni;
    if(iniziale==0)
    {
        for(int i=0;i<3;i++){
            if(manoIa[i].seme==terra[0].seme&&manoIa[i].punteggio>terra[0].punteggio&&manoIa[i].valore!=cartaVuota.valore){
                sceltaIa=i;
                break;}
            else if(terra[0].seme==briscola.seme&&manoIa[i].seme!=briscola.seme&&manoIa[i].punteggio==0&&manoIa[i].valore!=cartaVuota.valore){
                sceltaIa=i;
                break;}
            else if(terra[0].seme==briscola.seme&&manoIa[i].seme!=briscola.seme&&manoIa[i].punteggio==2&&manoIa[i].valore!=cartaVuota.valore){
                sceltaIa=i;
                break;}
            else if(terra[0].seme==briscola.seme&&manoIa[i].seme!=briscola.seme&&manoIa[i].punteggio==3&&manoIa[i].valore!=cartaVuota.valore){
                sceltaIa=i;
                break;}
            else if(terra[0].seme==briscola.seme&&manoIa[i].seme!=briscola.seme&&manoIa[i].punteggio==4&&manoIa[i].valore!=cartaVuota.valore){
                sceltaIa=i;
                break;}
            else
                do
                    sceltaIa=rand()%3;
                while(manoIa[sceltaIa].valore==0);


        }
    }
    else if(iniziale==1)
        do
            sceltaIa=rand()%3;
        while(manoIa[sceltaIa].valore==0);

        if(numCarteRimaste<=0){
            terra[!iniziale]=manoIa[sceltaIa];
            manoIa[sceltaIa]=cartaVuota;
        }
        else if(numCarteRimaste>0){
            terra[!iniziale]=manoIa[sceltaIa];
            manoIa[sceltaIa]=mazzo[numCarteRimaste-1];
        }
    numCarteRimaste--;

    cout<<"-----------------------------------------"<<endl<<"Il computer ha giocato: "<<terra[!iniziale].valore<<" di "<<Semi[terra[!iniziale].seme]<<endl;

}
carta cartaBriscola(carta terra[],bool &cartaIniziale){
                   cartaIniziale=true;
                   return terra[0];

}
void calcolaPresa(carta terra[],carta carteUtente[40],carta carteIa[40],carta briscola,int &iniziale,int &numCarteUtente,int &numCarteIa){
    if(terra[1].seme==terra[0].seme){
        if(terra[0].punteggio>=terra[1].punteggio){
            if(iniziale==0){
                carteUtente[numCarteUtente]=terra[0];
                numCarteUtente++;
                carteUtente[numCarteUtente]=terra[1];
                numCarteUtente++;
                cout<<endl<<"Prende il Giocatore"<<endl;
                iniziale=0;

            }
            else{
                carteIa[numCarteIa]=terra[0];
                numCarteIa++;
                carteIa[numCarteIa]=terra[1];
                numCarteIa++;
                cout<<endl<<"Prende il Computer"<<endl;
                iniziale=1;

            }
            }
        else{
            if(iniziale==1){
                carteUtente[numCarteUtente]=terra[0];
                numCarteUtente++;
                carteUtente[numCarteUtente]=terra[1];
                numCarteUtente++;
                cout<<endl<<"Prende il Giocatore"<<endl;
                iniziale=0;

            }
            else{
                carteIa[numCarteIa]=terra[0];
                numCarteIa++;
                carteIa[numCarteIa]=terra[1];
                numCarteIa++;
                cout<<endl<<"Prende il Computer"<<endl;
                iniziale=1;
            }
        }

    }
    else if(terra[1].seme==briscola.seme){
        if(iniziale==1){
                carteUtente[numCarteUtente]=terra[0];
                numCarteUtente++;
                carteUtente[numCarteUtente]=terra[1];
                numCarteUtente++;
                cout<<endl<<"Prende il Giocatore"<<endl;
                iniziale=0;

            }
            else{
                carteIa[numCarteIa]=terra[0];
                numCarteIa++;
                carteIa[numCarteIa]=terra[1];
                numCarteIa++;
                cout<<endl<<"Prende il Computer"<<endl;
                iniziale=1;
            }
    }
    else if(terra[1].seme!=terra[0].seme){
         if(iniziale==0){
                carteUtente[numCarteUtente]=terra[0];
                numCarteUtente++;
                carteUtente[numCarteUtente]=terra[1];
                numCarteUtente++;
                cout<<endl<<"Prende il Giocatore"<<endl;
                iniziale=0;

            }
            else{
                carteIa[numCarteIa]=terra[0];
                numCarteIa++;
                carteIa[numCarteIa]=terra[1];
                numCarteIa++;
                cout<<endl<<"Prende il Computer"<<endl;
                iniziale=1;
            }
    }

}
carta sceltaBriscola(){
    carta b;
    string s;
    cout<<"Scegli la briscola"<<endl;
    cout<<"Bastoni"<<endl<<"Coppe"<<endl<<"Denari"<<endl<<"Spade"<<endl;
    cin>>s;
    b.valore=1;
    b.punteggio=punteggio[b.valore-1];
    if(s=="Bastoni")
        b.seme=Bastoni;
    else if(s=="Coppe")
        b.seme=Coppe;
    else if(s=="Denari")
        b.seme=Denari;
    else if(s=="Spade")
        b.seme=Spade;
    else{
        cout<<"Seme non valido"<<endl;
        sceltaBriscola();
    }
    cout<<endl<<"Il seme della briscola e' "<<Semi[b.seme]<<endl<<endl;

    return b;
}
int main()
{
    int sceltaUtente;
    int sceltaIa;
    int numCarteRimaste=40;
    int numCarteUtente=0;
    int numCarteIa=0;
    int totUtente=0;
    int totIa=0;
    int modalita;
    int difficolta;


    srand(time(0));

    carta mazzo[NumCarte];
    carta manoUtente[3];
    carta manoIa[3];
    carta carteUtente[40];
    carta carteIa[40];
    carta terra[2];
    carta briscola;

    bool cartaIniziale=false;

    creaMazzo(mazzo);
    mescolamento(mazzo);
    manoIniziale(manoUtente,manoIa,mazzo,numCarteRimaste);
    cout<<"++++++++++++++ Benvenuto A Briscola 2018 ++++++++++++++"<<endl<<endl;
    cout<<"Scegli la modalita': "<<endl<<"1) briscola scelta dall'utente"<<endl<<"2) briscola automatica"<<endl;
    cin>>modalita;
    while(modalita!=1&&modalita!=2){
        cout<<endl<<"Scelta Non Valida"<<endl;
        cin>>modalita;
    }
    cout<<"Scegli la difficolta': "<<endl<<"1) Facile"<<endl<<"2) Normale"<<endl;
    cin>>difficolta;
    while(difficolta!=1&&difficolta!=2){
        cout<<endl<<"Scelta Non Valida"<<endl;
        cin>>difficolta;
    }
    if(modalita==1){
    briscola=sceltaBriscola();
    }
    giocatoreIniziale(iniziale);
    //stampaMazzo(mazzo);
    //stampaMano(manoIa);
    while(numCarteRimaste+6>0){
                        if(iniziale){
                            if(difficolta==1)
                                giocaCartaIaRandom(terra,manoIa,sceltaIa,mazzo,numCarteRimaste);

                            if(difficolta==2)
                                giocaCartaIa(terra,manoIa,sceltaIa,mazzo,numCarteRimaste,iniziale,briscola);

                        }

                        giocaCarta(terra,manoUtente,sceltaUtente,mazzo,numCarteRimaste);

                        if(!iniziale){
                            if(difficolta==1)
                                giocaCartaIaRandom(terra,manoIa,sceltaIa,mazzo,numCarteRimaste);

                            if(difficolta==2)
                                giocaCartaIa(terra,manoIa,sceltaIa,mazzo,numCarteRimaste,iniziale,briscola);
                        }

                        if(modalita==2){ //briscola automatica
                        if(cartaIniziale==false){
                          briscola=cartaBriscola(terra,cartaIniziale);
                           cout<<"-----------------------------------------"<<endl<<"La briscola e' il "<<briscola.valore<<" di "<<Semi[briscola.seme]<<endl;}}
                         
                        stampaTerra(terra);
        
        calcolaPresa(terra,carteUtente,carteIa,briscola,iniziale,numCarteUtente,numCarteIa);

 
 
    }
    //if(numCarte=0)
    for(int i=0;i<numCarteUtente;i++)
        totUtente+=carteUtente[i].punteggio;

    for(int i=0;i<numCarteIa;i++)
        totIa+=carteIa[i].punteggio;

        if(totUtente>totIa)
            cout<<endl<<"Ha vinto l'utente con: "<<totUtente<<" punti";
        if(totUtente<totIa)
            cout<<endl<<"Ha vinto il Computer con: "<<totIa<<" punti";
        if(totUtente==totIa)
            cout<<endl<<"Pareggio";
    return 0;
}
