#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int value;
    Node *next;
}*head, *tail;

// estarei criando e add valores na lista encadeada
void _insert (int valor){
    if(head==nullptr){
        tail = head = (Node *) malloc(sizeof(Node)); // Cria um nó vazio
        head->value = valor;                         // aqui insere o valor desejado dentro do nó
        tail->next = nullptr;                        // cria um ponteiro apontando para null o proximo
    }
    else{
        Node *temp; // cria uma variavel temporaria
        temp = (Node *) malloc(sizeof(Node));
        temp->value = valor;
        tail = tail->next = temp;
    }
}

// mostra os valores que estão na lista encadeada
void show(){
    Node *temp = head;
    cout << temp->value << " ";
    while(temp!=tail){
        temp = temp->next;
        cout << temp->value << " ";
    }
    cout << endl;
}

int main(){
    _insert(3);
    _insert(5);
    _insert(1);
    _insert(2);
    show();
    return 0;
}
