# -*- coding: utf-8 -*-

def particionar(a,p,r):
    x = a[r]
    i = p-1
    for j in range(p,r):
        if a[j] <= x:
            i = i+1
            a[i], a[j] = a[j], a[i]
    a[i+1], a[r] = a[r], a[i+1]
    return i+1

def quicksort(a,p,r):
    if p < r:
        q = particionar(a,p,r)
        quicksort(a,p,q-1)
        quicksort(a,q+1,r)

if __name__ == "__main__":
    print("Testando o quicksort")
    v = [5,4,3,2,1]
    print("Vetor atual: ", v)
    quicksort(v,0,len(v)-1)
    print("Vetor ordenado: ", v)
