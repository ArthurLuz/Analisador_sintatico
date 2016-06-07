#include <iostream>
#include <string>
using namespace std;

//modela classe veiculo
class Veiculo{
  protected:
  string marca;
  string modelo;
  float preco;

//atributos da classe
  private:
  int teste;

//metodos da classe
  public:
//construtor
  Veiculo(){
  marca= "";
  modelo="";
  preco=0.0;

  };
//construtor com parametros , polimorfismo do tipo sobrecarga
  Veiculo(string mc,string md, float pr){
  marca=mc;
  modelo=md;
  preco=pr;
  };
//metodos destrutor
  ~Veiculo(){
      cout << "deletando instancia de veiculo." << endl;
  };
  //metodo para retornar marca
  string getmarca(){
    return marca;
  };
  void setmarca(string mc){
    marca=mc;
  };
  string getmodelo(){
    return modelo;
  };
  void setmodelo(string md){
    modelo = md;
  };
  float getpreco(){
    return preco;
  };
  void setpreco(float pr){
    preco = pr;
  };

  int getTeste(){
    return teste;
  };

};
//modelagem da classe carro q herda as caracteristicas de veiculo
  class Carro:public Veiculo{

// atributos da classe
  private:
    int tipocambio;
    int numeroassentos;
//metodos da classe
  public:
      Carro(){

      };
      Carro(string mc , string md, float pr , int tc, int na){
        marca = mc;
        modelo = md;
        preco = pr;

        tipocambio = tc;
        numeroassentos = na;
      };
//metodo destrutor
      ~Carro(){

      };

      int gettipocambio(){
        return tipocambio;
      };
      void settipocambio(int tc){
        tipocambio = tc;
      };

      int getnumeroassentos(){
        return numeroassentos;
      };
      void setnumeroassentos(int na){
        numeroassentos = na;
      };
  };

  class Moto:public Veiculo{
    private:
      int cilindros;

    public:
      Moto(){

      };
      Moto(string mc, string md, float pr, int c){
        marca = mc;
        modelo = md;
        preco = pr;
        cilindros = c;
      };
      ~Moto(){

      };
      int getcilindros(){
        return cilindros;
      };
      void setcilindros(int c){
        cilindros = c;
      };
  };
