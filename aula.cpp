#include "veiculo.hpp"

using namespace std;
int main(int argc, char **argv) {
  string texto;
  float valor;
  int numero;
/*  Veiculo veiculo;

  cout << "Informe a marca do Veiculo:" << endl;
  cin >> texto;
  veiculo.setmarca(texto);

  cout << "Informe o modelo do veiculo:" << endl;
  cin >> texto;
  veiculo.setmodelo(texto);

  cout << "Informe o preco de veiculo:" << endl;
  cin >> valor;
  veiculo.setpreco(valor);

  cout << "Dados do veiculo:";
  cout << veiculo.getmarca() << endl;
  cout << veiculo.getmodelo() << endl;
  cout << veiculo.getpreco()  << endl;
*/
  // Carro *carro;
  // carro = new Carro();
  // cout << "Informe a marca do Veiculo:" << endl;
  // cin >> texto;
  // carro->setmarca(texto);
  //
  // cout << "Informe o modelo do veiculo:" << endl;
  // cin >> texto;
  // carro->setmodelo(texto);
  //
  // cout << "Informe o preco de veiculo:" << endl;
  // cin >> valor;
  // carro->setpreco(valor);
  //
  // cout << "Informe tipo de cambio:" << endl;
  // cin >> numero;
  // carro->settipocambio(numero);
  //  vetor_motos = new Moto[10];
  // cout << "informe o numero de assentos:" << endl;
  // cin >> numero;
  // carro->setnumeroassentos(numero);
  //
  //
  // cout << "Dados do carro:";
  // cout << carro->getmarca() << endl;
  // cout << carro->getmodelo() << endl;
  // cout << carro->getpreco()  << endl;
  // cout << carro->getnumeroassentos() << endl;
  // delete  carro;
  //
  // Moto *moto;
  // moto = new Moto("Moto teste","Modelo teste",30000.5,600);
  // cout << moto->getmarca() << " - ";
  // cout << moto->getmodelo() << " - ";
  // cout << moto->getpreco() << " - ";
  // cout << moto->getcilindros() << endl << endl;
  // delete moto;

  Moto *vetor_motos;
  vetor_motos = new Moto[10];
  for(int i=0;i<10;i++){
      //vetor_motos[i] = new Moto("moto %d","Modelo %d",3000,700,i,i);
      cout << "Informe a marca da moto:" << endl;
      cin >> texto;
      vetor_motos[i].setmarca(texto);

      cout << "Informe o modelo do veiculo:" << endl;
      cin >> texto;
      vetor_motos[i].setmodelo(texto);

      cout << "Informe o preco de veiculo:" << endl;
      cin >> valor;
      vetor_motos[i].setpreco(valor);

      cout << "informe as cilindradas:" << endl;
      cin >> numero;
      vetor_motos[i].setcilindros(numero);

  }
  delete [] vetor_motos;







  return 0;
}
