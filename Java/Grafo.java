import java.util.Scanner;
import java.util.ArrayList;
public class Grafo {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.printf("\n\t\tDigite quantos vértices tem nesse grafo: ");
        int tamGrafo = Integer.parseInt(input.nextLine());
        ArrayList<ArrayList<Integer>> listaGrafo = new ArrayList<ArrayList<Integer>>();

        
        System.out.printf("\n\t\tO grafo é direcionado?: ");
        String escolha = input.nextLine();

        if(escolha.equals("s") || escolha.equals("sim") || escolha.equals("S") || escolha.equals("Sim")){
            for(int i=0;i<tamGrafo;i++){
                ArrayList<Integer> l = new ArrayList<Integer>();
                for(int j=0;j<tamGrafo;j++){
                    if(i == j)
                        System.out.printf("\n\t\tQuantos lacos o vertice %d tem? ",i);
                    else
                        System.out.printf("\n\t\tQuantas arestas o vertice %d tem apontando para o vertice %d? ",i,j);
                    
                    l.add(Integer.parseInt(input.nextLine()));
                }
                listaGrafo.add(l);
            }
        }
        else{

            for(int i=0;i<tamGrafo;i++){
                ArrayList<Integer> l = new ArrayList<Integer>();
                for(int j=0;j<tamGrafo;j++){
                    if(i > j){
                        l.add(listaGrafo.get(j).get(i));
                        continue;
                    }
                    
                    if(i == j)
                        System.out.printf("\n\t\tQuantos lacos o vertice %d tem? ",i);
                    else
                        System.out.printf("\n\t\tQuantas arestas o vertice %d tem ligando ao vertice %d? ",i,j);
                    
                        l.add(Integer.parseInt(input.nextLine()));
                }
                listaGrafo.add(l);
            }
        }


        System.out.println("\nEssas são as listas que representa esse grafo");
        System.out.println(listaGrafo);



    }
}
