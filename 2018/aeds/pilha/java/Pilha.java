public class Pilha {
   private int tamanho;
   private int[] vetor;
   private int topo = -1;

   public Pilha(int tamanho) {
      this.tamanho = tamanho;
      vetor = new int[tamanho];
   }

   public boolean vazia() {
      return topo == -1;
   }

   public boolean cheia() {
      return topo == tamanho-1;
   }

   public void push(int e) {
      if (!cheia())
         vetor[++topo] = e;
      else
         throw new IllegalStateException("Pilha Cheia");
   }

   public int pop() {
      if (!vazia())
         return vetor[topo--];
      else
         throw new IllegalStateException("Pilha vazia");
   }

   public static void main(String[] args) {
      System.out.println("Criando uma pilha de 5 elementos");
      Pilha p = new Pilha(5);

      try {
         int i = 1;
         while (true) {
            System.out.printf("Empilhando %d\n", i);
            p.push(i++);
         }
      } catch (Exception e) {
         System.out.printf("Ops! %s\n", e.getMessage());
      }

      System.out.println("Agora, desempilhando...");
      try {
         while (true)
            System.out.printf("Desempilhou %d\n", p.pop());
      } catch (Exception e) {
         System.out.printf("Ops! %s\n", e.getMessage());
      }
   }
}
