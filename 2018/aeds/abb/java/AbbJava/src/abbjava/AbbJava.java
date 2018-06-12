/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package abbjava;

/**
 *
 * @author daniel.conrado
 */
public class AbbJava {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        Arvore arvore = new Arvore();
        arvore.inserir(5);
        arvore.inserir(3);
        arvore.inserir(2);
        arvore.inserir(1);
        arvore.inserir(7);
        arvore.inserir(6);
        
        arvore.imprimirEmOrdem();
        
        
        System.out.println("\nNó mínimo:");
        Arvore.No minimo = arvore.minimo();
        System.out.println(minimo.chave);
        
        System.out.println("Procurando 3:");
        Arvore.No no = arvore.procurar(9);
        System.out.println(no == null ? null : no.chave);
    }
    
}
