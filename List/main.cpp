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
        head->value = valor;                        // aqui insere o valor desejado dentro do nó
        tail->next = nullptr;                        // cria um ponteiro apontando para null o proximo
    }
    else{
        Node *temp; // cria uma variavel temporaria
        temp = (Node *) malloc(sizeof(Node));
        temp->value = valor;
        tail = tail->next = temp;
        tail->next = nullptr;
    }
}

void _remove(int valor){
    if(head==nullptr && tail==nullptr){
        return;
    }
    else{
        Node *temp1, *temp2;
        temp1 = head;
        while(temp1!=nullptr){
            if(temp1->value==valor){
                if(temp1==tail){
                    temp2->next = nullptr;
                    tail = temp2;
                    cout << "Valor removido: " << temp1->value << endl;
                    free(temp1);
                    return;
                }
                else if(temp1==head){
                    head = head->next;
                    cout << "Valor removido: " << temp1->value << endl;
                    free(temp1);
                    return;
                }
                else{
                    Node *aux;
                    aux = temp1;
                    temp1 = temp1->next;
                    temp2->next = temp1;
                    cout << "Valor removido: " << aux->value << endl;
                    free(aux);
                    return;
                }
            }
            else{
                temp2 = temp1;
                temp1 = temp1->next;
            }
        }
        cout << "Valor não existe" << endl;
    }
}

// mostra os valores que estão na lista encadeada
void show(){
    if(head==nullptr){
        cout << "Lista nao existe" << endl;
        return;
    }
    Node *temp = head;
    cout << temp->value << " ";
    while(temp!=tail){
        temp = temp->next;
        cout << temp->value << " ";
    }
    cout << endl;
}

int main(){
    _insert(7);
    _insert(1);
    _insert(3);
    _insert(2);
    _remove(4);
    show();
    return 0;
}
