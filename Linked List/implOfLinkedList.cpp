#include<iostream>
using namespace std;

struct Node{
    int info;
    struct Node* link;
};

class LinkedList{
    public:

    struct Node* start;
    LinkedList(){
        start = nullptr;
    }

    void insertAtFront(int data){ // 1. To insert at front of the linkedList
        struct Node* newNode;
        
        newNode = (struct Node*)malloc(sizeof(struct Node));

        newNode->info = data;
        newNode->link = start;
        
        //update the Start
        start = newNode;

    }

    void insertAtEnd(int data){ // 2. To insert at the end of the LinkedList
        struct Node* newNode;
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->info = data;
        newNode->link = nullptr;

        if(start == nullptr){
            start = newNode;
        }else{
            struct Node* current = start;

            while(current->link!=nullptr){
                current = current->link;
            }
            current->link = newNode;

        }

    }

    void insertAtAnyPlace(int data, int place){ // 3. To insert at any place in the linkedList

        if(place<= 0){
            cout<<"Invalid position!"<<endl;
            return;
        }

        struct Node* current = start;
        int lenght = 0;
        while(current->link != nullptr){
            current = current->link;
            lenght++;
        }
        cout<<"Length of the LinkedList is : " << lenght << endl;

        struct Node* newNode;
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->info = data;
        newNode->link = nullptr;


        if(place == 1){
            newNode->link = start;
            start = newNode;
            return;
        }
        struct Node* temp = start;
        int i = 1;

            while(i < place - 1 && temp != nullptr){
                temp = temp->link;
                i++;
            }
            newNode->link = temp->link;
            temp->link = newNode;
        

    }

    void deleteFromFront(){ // 4. To delete the node from the front of the linkedList
        if(start == nullptr){
            return;
        }

        struct Node* temp;
        temp = start;
        start = start->link;
        free(temp);
        cout<<"Node deleted from the linkedList successfully"<<endl;
    }

    void deleteFromEnd(){ // 5. To delete the node from the front of the linkedList
        if(start == nullptr){
            return;
        }

        if(start->link == nullptr){
            free(start);
            start = nullptr;
            cout<<"Node deleted from the linkedList successfully"<<endl;
            return;

        }

        struct Node* temp;
        temp = start;

        while(temp->link->link != nullptr){
            temp = temp->link;
        }
        free(temp->link);
        temp->link = nullptr;
        cout<<"Node deleted from the linkedList successfully"<<endl;

    }
    void deleteAtAnyPlace(int place){ // 6. To delete the node at any place in the linkedList
        if(place<= 0){
            cout<<"Invalid position!"<<endl;
            return;
        }

        if (start == nullptr) {
        cout << "The list is already empty." << endl;
        return;
        }

        if(place == 1){
            struct Node* temp = start;
            start = start->link;
            free(temp);
            cout<<"Node deleted from the linkedList successfully"<<endl;
            return;

        }
        
        struct Node* temp = start;
        int i = 1;

            while(i < place -1 && temp != nullptr){
                temp = temp->link;
                i++;
            }
            Node* nodeToDelte = temp->link;
            temp->link = nodeToDelte->link ;
            free(nodeToDelte);
            cout<<"Node deleted from the linkedList successfully"<<endl;
    }

    void printLinkedList(){  // To print the LikedList
        Node* current = start;

        if(start == nullptr){
            cout<<"The List is empty."<<endl;
            return;
        }
        cout<<"Data in Linked List : "<<endl;
        while(current != nullptr){
            cout<< current->info<< " ";
            current = current->link;
        }
        cout<<endl;
    }
};




int main(){

    LinkedList list;

    int choice;
    do{
    cout<<"\n1. To insert at front\n2. To insert at end\n3. To insert at any place\n4. To delete the node from the front\n5. To delete from the end\n6. To delete node at any place\n7. To print the LinkedList\n0. To exit the program\n\n";
    cout<<"Enter your choice"<<endl;
    cin>>choice;

        switch (choice)
        {
        case 1:
        {
            cout<<"Enter the data to insert at the front of the LinkedList"<<endl;
            int data;
            cin>>data;
            list.insertAtFront(data);
            cout<<"Data inserted at front successfully"<<endl;
            break;
        }
        case 2: 
        {
            cout<<"Enter the data to insert at the end of the LinkedList"<<endl;
            int data;
            cin>>data;
            list.insertAtEnd(data);
            cout<<"Data inserted at end successfully"<<endl;
            break;
        }
        case 3: 
        {
            cout<<"Enter the data to insert at any place in the  LinkedList"<<endl;
            int data;
            int place;
            cin>>data;
            cout<<"Enter the place where you want to insert the New Node"<<endl;
            cin>>place;
            list.insertAtAnyPlace(data, place);
            cout<<"Data inserted at place " << place << " successfully"<<endl;
            break;

        }
        case 4:
        {
            list.deleteFromFront();
            list.printLinkedList();
            break;

        }
        case 5:
        {
            list.deleteFromEnd();
            list.printLinkedList();
            break;

        }
        case 6:
        {
            int place;
            cout<<"Enter the place where you want to delete theNode"<<endl;
            cin>>place;
            list.deleteAtAnyPlace(place);
            cout<<"Node delete at place " << place << " successfully"<<endl;
            list.printLinkedList();
            break;
        }
        case 7:
        {
            cout<<"Data in Linked List : "<<endl;
            list.printLinkedList();
            cout<<endl;
            break;
        }
        case 0:
        {
            cout<<"Exiting...."<<endl;
            break;
        }
        
        default:
            cout<<"Enter the correct choice"<<endl;
            break;
        }

    }while(choice!=0);



    return 0;
}