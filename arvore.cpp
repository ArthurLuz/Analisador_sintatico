#include "pessoa.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>


Pessoa *raiz=NULL ;
Pessoa *novo,*b ;


string n;
int idade;

int main(int argc, char **argv){
    int k;
  //raiz->Ordem(raiz);
  int imprimir =0;
  int op=1;
  do{
        system("cls");
        cout << "\n1.Inserir .\n2.Busca\n3.Listar \n0.Sair" << endl;
        cout << "\nO que deseja fazer?\n<_>\b\b" << endl;
        cin >> op;


  switch(op)
        {
        case 0:
            cout << "fechando programa.." << endl;
            break;
        case 1:
            novo = new Pessoa();
            cout << "informe o nome" << endl;
            cin >> n;
            novo->setnome(n);

            cout << "informe a idade" << endl;
            cin >> idade;
            novo->setidade(idade);
            if(raiz==NULL){
              raiz =novo;
              novo->pai=novo->dir=novo->esq=NULL;

            }else{
              raiz->inserirfilho(novo);
            }
            break;
        case 2:
            cout << "digite uma idade pra buscar:" << endl;
              cin >> k;
              b=raiz->busca(k);
              if(b==NULL)
                cout << "pessoa não encontrada" << endl;
              else
                cout << "pessoa encontrada:"<< b->getnome()<<endl;
            break;
        case 3:
            cout << "Iniciando impressao" << endl;
            system("pause");
            system("cls");
            cout << "|---------|"<<endl;
            cout <<"|EM ORDEM|"<<endl;
            raiz->Ordem();

           cout << "|---------|"<<endl;
            cout <<"|PRE ORDEM|"<<endl;
            raiz->PreOrdem();

            cout << "|---------|"<<endl;
            cout <<"|POS ORDEM|"<<endl;

            raiz->PosOrdem();
            system("pause");
            system("cls");
            break;

        default:
            cout    <<"Digite uma opcao valida !"<<endl;
        }
    }while(op!=0);

  return 0;

};
