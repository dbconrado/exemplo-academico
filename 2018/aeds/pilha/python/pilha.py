# -*- coding: utf-8 -*-

# Implementação "agnóstica" de pilha em Python

class Pilha:
    def __init__(self, tamanho):
        self.tamanho = tamanho
        self.vetor = [None] * tamanho
        self.topo = -1
    
    def vazia(self):
        return self.topo == -1
    
    def cheia(self):
        return self.topo == self.tamanho-1
    
    def push(self, e):
        if not self.cheia():
            self.topo += 1
            self.vetor[self.topo] = e
        else:
            raise Exception('pilha cheia')
    
    def pop(self):
        if not self.vazia():
            self.topo -= 1
            return self.vetor[self.topo+1]
        else:
            raise Exception('Pilha vazia')

if __name__ == "__main__":
    print "Testando a pilha"
    print "Criando uma pilha de 5 elementos"
    p = Pilha(5)
    try:
        for i in range(1,10):
            print 'Tentando empilhar %d' % i,
            p.push(i)
            print 'empilhou'
    except Exception as e:
        print 'oops! ', e
    
    print "Desempilhando..."
    try:
        while True:
            print "Desempilhou ", p.pop()
    except Exception as e:
        print "OOps! ", e


