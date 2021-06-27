#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct STOCK
{
    ​​​​
        std::string name;
    double price = 0;
    STOCK* next = NULL;
}​​​​;

STOCK* prependNode(STOCK* head, int price1, string name1)
{
    ​​​​
        STOCK* newNode = new STOCK;
    newNode->price = price1;
    newNode->name = name1;
    newNode->next = head;
    head = newNode;
    return head;
}​​​​

void printStock(STOCK* head)
{
    ​​​​
        STOCK* list = head;
    while (list)
    {
        ​​​​
            cout << list->name << " " << list->price;
        list = list->next;
        cout << endl;
    }​​​​
}​​​​

void SortLinkedList(STOCK* head)
    {
        ​​​​
            STOCK* node = NULL, * temp = NULL;
        double tempvar;
        string tempvar1;
        node = head;
        while (node != NULL)
        {
            ​​​​
                temp = node;
            while (temp->next != NULL)
            {
                ​​​​
                    if (temp->price < temp->next->price)
                    {
                        ​​​​
                            tempvar = temp->price;
                        tempvar1 = temp->name;
                        temp->price = temp->next->price;
                        temp->name = temp->next->name;
                        temp->next->price = tempvar;
                        temp->next->name = tempvar1;
                    }​​​​
                        temp = temp->next;
            }​​​​
                node = node->next;
        }​​​​
    }​​​​

        int main()
        {
            ​​​​
                int n;
            string name;
            int price;
            cin >> n;
            STOCK* head = NULL;
            for (int i = 0; i < n; i++)
            {
                ​​​​
                    cin >> name;
                cin >> price;
                head = prependNode(head, price, name);
            }​​​​

                SortLinkedList(head);
            printStock(head);
        }