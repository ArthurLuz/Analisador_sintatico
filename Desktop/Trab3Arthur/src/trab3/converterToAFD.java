/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trab3;
import conversao_infixa_posfixa.Conversao_infixa_posfixa;
import java.util.ArrayList;
import trabson2_comp.Automato;
/**
 *
 * @author aluno
 */
public class converterToAFD {
    
    String fecho;    
    Automato afn  = new Automato();
    String alfabeto;
    ArrayList<String>estados = new ArrayList<>();
    
    public converterToAFD(String fecho,Automato afn,String alfabeto){
        this.fecho= fecho;
        this.afn=afn;
        this.alfabeto=alfabeto;
    }
    public converterToAFD(){
        
    }
    
    @SuppressWarnings("empty-statement")
    public ArrayList<String> afntoafd(){
        String outroauxiliar;
        String teste;
        String conjuntoEstados = "";
        Conversao_infixa_posfixa c = new Conversao_infixa_posfixa();
        int cont = 0;
        String string = "";
        ArrayList<String>divide = new ArrayList<>();
        ArrayList<String>divide2 = new ArrayList<>();
        ArrayList<String>auxiliar = new ArrayList<>();
        ArrayList<String> aux = new ArrayList<>();
        
        estados.add(fecho);
        
        alfabeto = c.getalfabeto(alfabeto);
        alfabeto += "&";
        alfabeto = "a".concat(alfabeto);        
       
        do{
//            if(estados.contains(string)){
//                break;
//            }

            
            //System.out.println("Fecho: " + fecho);
            for(int i = 0; i<afn.linhastabela; i++){
                if(fecho.contains("q"+i)){
                    divide.add("q"+i);
                    //System.out.println("q"+i);
                }
            }

            //System.out.println(alfabeto);

            for(int j = 1; j < alfabeto.length() - 1; j++){  // essa porra pega a concatenação do fecho tanto comparando 0 como 1 
                for(int k = 0; k < divide.size(); k++){
                    conjuntoEstados += Func_Transicao(divide.get(k), alfabeto.charAt(j));
                    //System.out.println(aux);
                }
                //System.out.println("J : " + j);
                conjuntoEstados = conjuntoEstados.replace("[", "");
                conjuntoEstados = conjuntoEstados.replace("]", "");
                auxiliar.add(conjuntoEstados);// da pra usar pra fazer a tabela(preencer)
                
                //System.out.print(" Conj: " + conjuntoEstados);
//                for(int z=0;z<conjuntoEstados.length();z++){
//                    System.out.print(conjuntoEstados.charAt(z));
//                }
                conjuntoEstados = "";
            }
            
            //System.out.println("" + auxiliar.toString());
           
            for(int j = 0; j < auxiliar.size(); j++){
                teste = auxiliar.get(j);
                //System.out.println(teste);
                    //for(int i = 0; i <= afn.linhastabela; i++){
                        for(int i=0;i<teste.length();i++){
                            int in = i;
                            if(teste.charAt(i) == 'q'){
                                in++;
                                outroauxiliar = "q";
                                while(in < teste.length() && teste.charAt(in) != 'q'){
                                    outroauxiliar += "" + teste.charAt(in);
                                    in++;  
                                }
                                divide2.add(outroauxiliar);
                                //outroauxiliar = "";
                                in--;
                            }
                            i = in;
                        }
                        
                    }
            //System.out.println("Divide2: " + divide2.toString());
            
               
            
            
            
            //System.out.println("Divide2: " + divide2.toString());
            
            for(int i = 0; i<divide2.size(); i++){
                string = afn.UniaoEstados(string, afn.Fecho_E(divide2.get(i)));
                //System.out.println("fechos :" + string);
                aux.add(string);
                string = "";
            }
            
            //System.out.println("Fechos: " + aux.toString());
            for(int i = 0; i < aux.size(); i++){
                if(!estados.contains(aux.get(i))){
                    //System.out.println("Entrou");
                    estados.add(aux.get(i));        
                    //entrou = true;
                }
            }
            

            cont++;
            if(cont < estados.size())
                fecho = estados.get(cont);


            

            divide.clear();
            divide2.clear();
            auxiliar.clear();
            string = "";
            

            
        }while(cont < estados.size());
        
        String Estadosarrumado = estados.toString();
        
        for(int i = 0; i < estados.size(); i++ ){
            Estadosarrumado = estados.get(i);
            Estadosarrumado = Estadosarrumado.replace("[", "");
            Estadosarrumado = Estadosarrumado.replace("]", "");
            Estadosarrumado = Estadosarrumado.replace(", ", "");
            estados.set(i, Estadosarrumado);
            
        }
        
        
        
        System.out.println("Estados: " + estados.toString());
        
//        String matriz[][] = new String[estados.size()][alfabeto.length() - 1];
//        for(int i = 0; i < estados.size(); i++){
//            matriz[i][0] = estados.get(i);
//            //System.out.println("Matriz: " + matriz[i][0]);
//        }
//        
//        for(int i = 0; i < estados.size(); i++){
//            for(int j = 1; j < alfabeto.length() - 1; j++){
//                matriz[i][j] = estados.get(i); 
//                System.out.println("Matriz: " + matriz[i][j]);
//            }
//        }
        
        return estados;
    }
    
    public String [][]matrizAFD(){
        String[][] afd = new String[estados.size()][alfabeto.length()-2];
        
        //converterToAFD a = new converterToAFD();
        for(int j = 1; j < alfabeto.length() - 1; j++){
            for(int k = 0; k < estados.size(); k++){
                afd[j][k]=estados.get(k);
            }
        }
        return afd;
    }
    
    public String Func_Transicao(String estado, char transicao){
        ArrayList<String> retorno = new ArrayList<>();
        String aux= "";
        ArrayList<String> fechos = new ArrayList<>();
        for(int i = 0; i<afn.linhastabela; i++){
            if(estado.equals("q" + i)){
                for(int j = 1; j < alfabeto.length()-1; j++){
                    if(transicao == alfabeto.charAt(j)){
                       retorno.add(afn.tabela[i][j]);
                        //System.out.print(retorno);
                    }
                }    
                //System.out.println("retorno: " + retorno);
                for(int k=0; k < retorno.size(); k++){
                    if(retorno.get(k) != "-" ){
                        //System.out.println("Entrou");
                        fechos.add(retorno.get(k));
                        aux = fechos.toString();
                        
                    }
                }
                
            }
           
        }
//        if(!fechos.isEmpty()){
//            for (int l=0; l<fechos.size();l++){
//                aux=afn.UniaoEstados(aux, afn.Fecho_E(fechos.get(l)));
//                //System.out.println(aux);
//            }
//        }
 //System.out.print("aux"+aux);
        //System.out.print("fechos: " + fechos.toString());

        //System.out.print("AUX: " + fechos.toString());
        return aux;
    }
}