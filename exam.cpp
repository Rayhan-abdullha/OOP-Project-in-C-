// Resturant Project in C++ with OOP

#include <bits/stdc++.h>
using namespace std;

class Restaurant 
{    
    public:  
        int food_item_code[12];
        int food_item_prices[12];
        string food_item_names[12];
    protected:
        int total_tax = 0;
    public:
        void create_food_menu(int n);
        void foodDetails(int n);  
        void order_food(int n);
};

void Restaurant :: create_food_menu(int n) {
    for (int i = 0; i < n; i++) {   
        cin >> food_item_code[i];
        cin.ignore();
        getline(cin, food_item_names[i]);
        cin >> food_item_prices[i];
    }
}

void Restaurant :: foodDetails(int n) {
    cout <<"                                MAKE BILL                               "<<endl;
    cout <<"                            -----------------                       "<<endl;
    cout <<"Item Code           "<<"        Item Name        "<<"        Item Price      "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<food_item_code[i]<<"                      ";
        
        cout<<food_item_names[i]<<"                     ";

        cout<<food_item_prices[i];
        cout<<endl;
    }
}


void Restaurant :: order_food(int n) {
    cout<<endl;
    cout << "                               Make Order"<<endl;
    cout << "                            ----------------                      "<<endl;
    cout <<"Enter Table No : ";
    int table;
    cin >> table;

    cout <<"Enter Number of Items : ";
    int t;
    cin>>t;

    while (true)
    {
        if (t > n){
            cout<<"Please enter valid item number: ";
            cin>>t;
        } else {
            break;
        }
    }

    int foodCode[t];
    int quantityArray[t];
    for (int i = 0; i < t; i++) {   
        cout <<"Enter Item "<<i+1<<" Code : ";
        cin >> foodCode[i];
        cout <<"Enter Item "<<i+1<<" Quanity : ";
        cin >> quantityArray[i];
    }    


    //bill summary

    int netToal = 0;
    double tax = 0;

    cout<<endl;
    cout<<"                             BILL SUMMARY"<<endl;
    cout<<"                          -------------------"<<endl;
    cout<<"Table No : " << table<<endl;
    cout<<"Item Code       ";
    cout<<"Item Name            ";
    cout<<"     Item Price      ";
    cout<<"Item Quantity   ";
    cout<<"   Total Price"<<endl;
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < n; j++)
        {   
            int totalPrice = 0;
            if (foodCode[i] == food_item_code[j]){
                cout<<food_item_code[j]<<"       ";
                cout<<"      "<<food_item_names[j]<<"          ";
                cout<<"    "<<food_item_prices[j]<<"          ";
                cout<<"     "<<quantityArray[i]<<"            ";
                totalPrice += food_item_prices[j] * quantityArray[i];
                netToal += totalPrice;
                cout<<"      "<<totalPrice;
                cout<<endl;
            }
        }
    }
    // tax
    tax = (netToal / 10) / 2;
    netToal += tax;
    total_tax += tax;

    cout<<"TAX                                                                                  "<<tax<<endl;
    cout<<"-------------------------------------------------------------------------------------------"<<endl;
    cout<<"NFT TOTAL                                                                           "<< netToal<<endl;
}

int main() {
    Restaurant abc;
        int n;
        cin >> n;
        abc.create_food_menu(n);
        abc.foodDetails(n);
        abc.order_food(n);
    return 0;
}
