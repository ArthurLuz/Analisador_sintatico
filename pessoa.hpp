#include <iostream>
#include <string>
using namespace std;

//modela classe
class Pessoa{
  protected:
  string nome;
  int idade;
//metodos da classe
  public:

    Pessoa *dir;
    Pessoa *esq;
    Pessoa *pai;
    int altura,equilibrio;
    //construtor
  Pessoa(){
  nome="";
  idade=0;
  dir=NULL;
  esq=NULL;
  pai=NULL;
  altura=equilibrio=0;
  };
//construtor com parametros , polimorfismo do tipo sobrecarga
  Pessoa(string n, int i){
  nome=n;
  idade=i;
  dir=NULL;
  esq=NULL;
  pai=NULL;
  altura=equilibrio=0;
  };
//metodos destrutor
  ~Pessoa(){
      cout << "deletando instancia de pessoa." << endl;
  };
  //metodo para retornar nome
  string getnome(){
    return nome;
  };
  void setnome(string n ){
    nome=n;
  };
  float getidade(){
    return idade;
  };
  void setidade(int i){
    idade= i;
  };
  void inserirfilho(Pessoa *novo){
      //if(raiz==NULL){      raiz =this;      this->pai=NULL}else{
    if (this->idade >= novo->idade) {
      //cout << " if " << endl;
          if(this->esq!=NULL) this->esq->inserirfilho(novo);
          else{
            this->esq = novo;
            novo->pai = this;
            this->altura=vertam(this);
          cout <<" alt this: " << this->altura<<endl;
          cout <<" alt dir: " << this->dir<<endl;
          cout <<" alt esq: " << this->esq<<endl;
            this->equilibrio=(vertam(this->dir))-(vertam(this->esq));
            cout<<"aqui: "<<this->equilibrio<<endl;
            //if(-1<=this->equilibrio<=1)
            //rotacionar(this);
          }
      }else{
        //cout << "else if " << endl;
        if(this->dir!=NULL) this->dir->inserirfilho(novo);
        else{
          this->dir = novo;
          novo->pai = this;
          this->altura=vertam(this);
          cout <<" alt this: " << this->altura<<endl;
          cout <<" alt dir: " << this->dir<<endl;
          cout <<" alt esq: " << this->esq<<endl;
          this->equilibrio=(vertam(this->dir))-(vertam(this->esq));
          cout<<"equi: "<<this->equilibrio<<endl;
          //if(-1<=this->equilibrio<=1)
          //rotacionar(this);
          //setaltura(this);
          //cout << "altelse : " <<this->altura<<endl;
        }
      }
  };
  int vertam(Pessoa *h){
    int u, v;
    if (h == NULL) return -1;
    u = vertam(h->esq);
    v = vertam(h->dir);
    //this->equilibrio=v-u;
    if (u > v) return u+1;
    else return v+1;
  };
//============AO MESMO TEMPO Q SETA A VARIAVEL EQUILIBRIO JA VAI EQUILIBRANDO A ARVORE========


    void rotacaoESQ(Pessoa *p){
        Pessoa *b = this->dir;
        this->dir = b->esq;
        b->esq=this;
        p=b;
    };
    void rotacaoDIR(Pessoa *p){
        Pessoa *b = this->esq;
        this->esq=b->dir;
        b->dir=this;
        p=b;
    };
    void rotacao2ESQ(Pessoa *p){
        rotacaoDIR(this->dir);
        rotacaoESQ(this);
    };
    void rotacao2DIR(Pessoa *p){
        rotacaoESQ(this->esq);
        rotacaoDIR(this);
    };
     void rotacionar(Pessoa *p){
        if (this->equilibrio>1){
            if(this->dir->equilibrio<0){
                rotacao2ESQ(this);
            }else{
                rotacaoESQ(this);
            }
        }else{
            if(this->esq->equilibrio>0){
                rotacao2DIR(this);
            }else{
                rotacaoDIR(this);
            }
        }
    };
    //__________________________________________________________________________________
    void Ordem () {
      if(this->esq != NULL)      this->esq->Ordem();
      //this->altura=vertam(this);


        cout << "nome: " <<this->getnome()<<  "  | Idade: " << this->getidade() <<  "  | altura: " <<this->altura <<  "  | equi: " <<this->equilibrio <<endl;

      if(this->dir != NULL)      this->dir->Ordem();
    };
    void PreOrdem () {
      cout << "nome: " <<this->getnome()<< endl;
      cout << "Idade: " << this->getidade() << endl;

      if(this->esq != NULL)
        this->esq->PreOrdem();

      if(this->dir != NULL)
      this->dir->PreOrdem();
    };
    void PosOrdem () {
      if(this->esq != NULL)
        this->esq->PosOrdem();

      if(this->dir != NULL)
      this->dir->PosOrdem();

      cout << "nome: " <<this->getnome()<< endl;
      cout << "Idade: " << this->getidade() << endl;
    };
    //============================================================================
    // deleteando posordem
    void Delete (){
      if (esq != NULL){
        this->esq->Delete();
      }//else return NULL;
       if (dir != NULL){
          this->dir->Delete();
        }//else return NULL;

      delete this;

    };

    Pessoa *busca (int k) {
    if ( this->idade == k){
        cout << "achou aki"  <<endl;
        return this;
      }else{
        if(k > this->idade){
            if(this->dir != NULL)
              this->dir->busca(k);
            else
              return NULL;
          }else{
            if(this->esq != NULL)
              this->esq->busca(k);
            else
              return NULL;
          }
      }
    };
    Pessoa *removefilhofolha(Pessoa *e){
        //============== Metodo Apaga folha =================
        if(e->dir==NULL && e->esq==NULL){
            if(e->pai->dir==e){
                e->pai->dir=NULL;
                delete e;
                cout <<"filho deletado!"<<endl;
            }else{
                e->pai->esq=NULL;
                delete e;
                cout <<"filho deletado!!"<<endl;
            }
        }
    };
    Pessoa *remove1filho(Pessoa *e){
        if(e->esq == NULL){ // verifica se o filho esta na esquerda ou direita
          e->dir->pai = e->pai; //o pai do filho q vai ser deletado passa a ser o avo
          if(e->pai->dir == e){
            e->pai->dir= e->dir; //pai do e recebe o filho do e como filho
          }else{
            e->pai->esq = e->dir;
          }
          delete e;

        }else{
            e->esq->pai = e->pai;
          if(e->pai->esq == e){
            e->pai->esq = e->esq;
          }else{
            e->pai->dir = e->esq;
          }
          delete e;
        }
    };
    void deletar2Filhos(Pessoa* pessoa){
      int binario;
      if(pessoa->pai->esq == pessoa){
        binario = 0;
      }else{
        binario = 1;
      }
        if(pessoa->dir->esq == NULL){
          if(binario == 0){
            pessoa->pai->esq = pessoa->dir;
          }else{
            pessoa->pai->dir = pessoa->dir;
          }
          pessoa->dir>esq = pessoa->esq;
          pessoa->dir->papai = pessoa->pai;
          pessoa->esq->pai = pessoa->dir;
          delete pessoa;
        }else{
          Pessoa* aux = pessoa->dir;
          while(aux->esq != NULL){
            aux = aux->esq;
          }
          if(aux->dir != NULL){
              aux->dir->pai = aux->pai;
           }
           aux->pai->esq = aux->dir;

          if(binario == 0){
            pessoa->pai->esq = aux;
          }else{
            pessoa->pai->dir = aux;
          }
          aux->pai = pessoa->pai;
          aux->esq= pessoa->esq;
          aux->dir = pessoa->dir;
          aux->esq->pai = aux;
          aux->dir->papai = aux;
          delete pessoa;
        }
    };



};


  class Pessoafisica:public Pessoa{

private:
    int CPF;
//metodos da classe
  public:
      Pessoafisica(){

      };
      Pessoafisica(string n, int i,int cpf){
        nome  = n;
        idade = i;
        CPF = cpf;
      };
//metodo destrutor
      ~Pessoafisica(){

      };

      int getcpf(){
        return CPF;
      };
      void settipocambio(int cpf){
        CPF = cpf;
      };
  };

  class Pessoajuridica:public Pessoa{

// atributos da classe
  private:
    int CNPJ;
//metodos da classe
  public:
      Pessoajuridica(){

      };
      Pessoajuridica(string n, int i,int cnpj){
        nome  = n;
        idade = i;
        CNPJ = cnpj;
      };
//metodo destrutor
      ~Pessoajuridica(){

      };

      int getcnpj(){
        return CNPJ;
      };
      void settipocambio(int cnpj){
        CNPJ = cnpj;
      };
  };
