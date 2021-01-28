#include<iostream>
#include "billing.h"
using namespace std;
//base class
class ThaiTannic
{
        public:
        string name ,location,owners;

        private:
        int noOfStaff;
        string staffName;
        
       
        
};
//Class menu displays the menu
class menu
{
   public:
   string allStarters[8]={"Veg tom yum soup -110","Veg man chow soup-110","Veg wonton soup-110","Dim sum(vegetable/paneer/chicken)-200","Paneer Sichuan-200","Lotus stem gangjeong-210","Spicy water-chestnut-210","Potato fries-80"};
   string allMainCourse[9]={"Thai green curry-220","Pad Thai-280","Som tam-265","Veg laska-160","veg noodles-180","Chicken kimchi fried rice-280","Prawn ramen noodles-200","Asian pot noodles-360","Thai wonton vegetable pot-380"};
   string allDesserts[5]={"Coconut ice cream-140","hai jelly-185","Mango sticky rice-185","Chocolate fudge ice-cream-160","Chocolate lava cake-130"};
   int allStartersPrice[8]={110,110,110,200,200,210,210,80};
   int allMainPrices[9]={220,280,265,160,180,280,200,360,380};
   int allDessertPrices[5]={140,185,185,160,130};
   void starterMenu()
   {

cout<<"\n-------------------------------------------------------"<<endl;
cout<<"T.H.A.I   T.A.N.N.I.C"<<endl;

cout<<"\n-------------------------------------------------------"<<endl;	   
cout<<"\nM.E.N.U"<<endl;
cout<<"\n-------------------------------------------------------"<<endl;


cout<<"\nSOUPS"<<endl;
cout<<"\n-------------------------------------------------------"<<endl;   
cout<<"\n1.Veg tom yum soup -110";
cout<<"\n2.Veg man chow soup-110";
cout<<"\n3.Veg wonton soup-110";
cout<<"\n-------------------------------------------------------"<<endl;
cout<<"\nSTARTERS";
cout<<"\n-------------------------------------------------------"<<endl;
cout<<"\n4.Dim sum(vegetable/paneer/chicken)-200";
cout<<"\n5.Paneer Sichuan";
cout<<"\n6.Lotus stem gangjeong";
cout<<"\n7.Spicy water-chestnut";
cout<<"\n8.Potato fries";

cout<<"\n-------------------------------------------------------"<<endl;
}
void mainMenu()
{
cout<<"\n-------------------------------------------------------"<<endl;
cout<<"T.H.A.I   T.A.N.N.I.C"<<endl;

cout<<"\n-------------------------------------------------------"<<endl;	   
cout<<"\nM.E.N.U"<<endl;
cout<<"\n-------------------------------------------------------"<<endl;

cout<<"\nMAIN COURSE";
cout<<"\n-------------------------------------------------------"<<endl;
cout<<"\nVEG:";
cout<<"\n1.Thai green curry-220";
cout<<"\n2.Pad Thai-280";
cout<<"\n3.Som tam-265";
cout<<"\n4.Veg laska-160";
cout<<"\n5.veg noodles-180";
cout<<"\nNON VEG:";
cout<<"\n6.Chicken kimchi fried rice-280";
cout<<"\n-------------------------------------------------------"<<endl;
cout<<"\nMEALS:";
cout<<"\n-------------------------------------------------------"<<endl;
cout<<"\n7.Prawn ramen noodles-200";
cout<<"\n8.Asian pot noodles-360";
cout<<"\n9.Thai wonton vegetable pot-380";
cout<<"\n-------------------------------------------------------"<<endl;
}
void dessertMenu()
{
cout<<"\n-------------------------------------------------------"<<endl;
cout<<"T.H.A.I   T.A.N.N.I.C"<<endl;

cout<<"\n-------------------------------------------------------"<<endl;	   
cout<<"\nM.E.N.U"<<endl;

cout<<"\n-------------------------------------------------------"<<endl;
cout<<"\nDESERTS:";
cout<<"\n-------------------------------------------------------"<<endl;
cout<<"\n1.Coconut ice cream-140";
cout<<"\n2.hai jelly-185";
cout<<"\n3.Mango sticky rice-185";
cout<<"\n4.Chocolate fudge ice-cream-160";
cout<<"\n5.Chocolate lava cake-130";
cout<<"\n-------------------------------------------------------"<<endl;
}

      
           
};
//class TableNo checks availability and allots available table

class TableNo : public ThaiTannic 
{
    public:
    
    bool isAvailable;
    int tableNo;
    void checkAvailability(int );
     
     
};

// checkAvailability is a function of class of TableNo

    
void  TableNo :: checkAvailability(int members)

{
    static bool tableNos[30];
         isAvailable=false;
        if (members>=1 && members<=2)
        {
            for(int i=0;i<10;i++)
            {
                if (tableNos[i]!=true)
                {
                    isAvailable=true;
                    tableNo=i;
                    tableNos[i]=true;
                    break;
                }
            }


        }
        else if (members>=3 && members<=4)
        {
            for(int i=10;i<20;i++)
            {
                if (tableNos[i]!=true)
                {
                    isAvailable=true;
                    tableNo=i;
                    tableNos[i]=true;
                    break;
                }
            }


        }
        else if (members>=5 && members <=8)
        {
            for(int i=20;i<30;i++)
            {
                if (tableNos[i]!=true)
                {
                    isAvailable=true;
                    tableNo=i;
                    tableNos[i]=true;
                    break;
                }
            }


        }
        if (isAvailable)
        {
            cout<<"Bonjure! \n";
            cout<<"Table number "<<tableNo+1<<"\nOur waiter will guide you .";

        }
        else
        {
            cout<<"All the tables seem to be taken at the moment. \n";
            cout<<"We request you to take a seat in our waiting room.\n";
            cout<<"We'll gte back to you in a bit .\n";

        }

       

}
class OrdersandTakeout :  public TableNo,public menu

{
	
	public :
	string customerAnswer;
	int startersOfOrders[10];
	int mainOfOrders[10];
	int dessertsOfOrders[10];
	int noOfitems;
	int mealCourse;
	int sos; //style of serving
	int s;//size
	int hc;//how cooked
	int von;//veg or non veg
	int ado;//addons
	int cbo;//combo for desserts
	int nd=0;//integer variable for dynamic allocation for dessertOrders array
	int ns=0;//integer variable for dynamice allocation for starterOrders array
	int nm=0;//integer variable for dynamic allocation for Main course array
	OrdersandTakeout()
	{
		for (int i =0; i<10; i++)
		{
		startersOfOrders[i]=0;
		mainOfOrders[i]=0;
		dessertsOfOrders[i]=0;
	    }
		
	}
	
	
	void takeinorder()
	{
	cout<<"\nBonjur! would you like to place your order YES/NO"<<endl;
	cin>>customerAnswer;
	
	
	
	 while(customerAnswer=="YES"||customerAnswer=="yes")
	{ 
		cout<<"\nEnter the \n1.Soups and Starters \n2.Main course and Meals \n3.Desserts "<<endl;
		cin>>mealCourse;
		switch(mealCourse)
		{
			case 1:
			cout<<"\nEnter the style of serving \n1.Sizzler \n2.Floats "<<endl;
			cin>>sos;
			takeinorder(sos);
			break;
			case 2:
			cout<<"\nEnter \n1.Veg or \n2.Non-Veg"<<endl;
			cin>>von;
			cout<<"\n Enter the size \n1.Large \n2.Medium \n3.Small "<<endl;
			cin>>s;
			if (von==2)
			{
			cout<<"\nEnter How cooked you want your meat \n1.Rare \n2.Medium \n3.well"<<endl;
			cin>>hc;
			}
		    takeinorder(s,hc,von);
		     break;
			
			case 3:
			cout<<"\n Enter your addons (if any) \n1.Chocolate garnish \n2.Mixed berry \n3.Mango and coconut sprinklers \n4.Praline and ganache \n5.Candied nuts ";
			cin>>ado;
			cout<<"\nEnter \n1.combos  \n2.No combos";
			cin>>cbo;
			
			takeinorder(ado,cbo);
			
			break;
			default:
			cout<<"\n We're afraid you might have entered an Incorrect choice";
			
		}
		cout<<"\n Would you like to continue ordering  YES/NO"<<endl;
	    cin>>customerAnswer;
		
	};
	cout<<"Your order has been succesfully placed , sit back and relax as we deliver your food to you :D"<<endl;
   }
	 void takeinorder(int styleOfServing)
	{
		
	 starterMenu();
	
	 
	 
		 
		 
		 cout<<"\nEnter the number of starters you would like to oreder";
		 cin >>ns;
     int *starterOrders= new int(ns);
	 cout<<"Enter the "<<ns<<" starters ";
	 for (int i=0; i<ns; i++)
	 {
		 cin>>starterOrders[i];
		 startersOfOrders[i]=starterOrders[i];
		 
		 
	 }
     
     
	
		
	}
	void takeinorder(int size, int howCooked, int vegOrNon)
	{
		mainMenu();
		
		 cout<<"\nEnter the number of main course dishes  you would like to oreder";
		 cin >>nm;
     int *mainOrders= new int(nm);
	 cout<<"Enter the "<<nm<<" main course dishes ";
	 for (int i=0; i<nm; i++)
	 {
		 cin>>mainOrders[i];
		 mainOfOrders[i]=mainOrders[i];
		 
	}
     }
	void takeinorder(int addons, int combo)
	{
		dessertMenu();
		
		 cout<<"\nEnter the number of desserts you would like to oreder";
		 cin >>nd;
     int *dessertOrders= new int(nd);
	 cout<<"Enter the "<<nd<<" Desserts. ";
	 for (int i=0; i<nd; i++)
	  {
		 cin>>dessertOrders[i];
		 dessertsOfOrders[i]=dessertOrders[i];
		 
	  }
	  
	}
	float sum =0;
	void printBill()
	{
    cout<<"PrintingBill......"<<endl;
    cout<<"------------------------------------------------------------------------------------------------"<<endl;
    cout<<"T.H.A.I T.A.N.N.I.C"<<endl;
    cout<<"------------------------------------------------------------------------------------------------"<<endl;
   
	cout <<"\nSTARTERS"<<endl;
	for (int i=0;i<ns;i++)
	{
	    cout <<allStarters[startersOfOrders[i]-1]<<"\n											Rs."<<allStartersPrice[startersOfOrders[i]-1]<<endl;
		sum+=allStartersPrice[startersOfOrders[i]-1];
	}
	cout<<"\nMAIN COURSE"<<endl;
	for(int i =0; i<nm;i++)
	{
		cout<<allMainCourse[mainOfOrders[i]-1]<<"\n											Rs."<<allMainPrices[mainOfOrders[i]-1]<<endl;
		sum+=allMainPrices[mainOfOrders[i]-1];
	}
	cout<<"\nDESSERTS"<<endl;
	for(int i=0;i<nd;i++)
	{
		
		cout<<allDesserts[dessertsOfOrders[i]-1]<<"\n											Rs."<<allDessertPrices[dessertsOfOrders[i]-1]<<endl;
		sum+=allDessertPrices[dessertsOfOrders[i]-1];
	}
	cout<<"\n-----------------------------------------------------------------------------------------------"<<endl;
	cout<<"TOTAl price                                                                  		Rs."<<sum<<endl;     
	
}
	
	
	
};




int main()
{
    TableNo t;
    t.checkAvailability(2);
    
    
    OrdersandTakeout o;
    o.takeinorder();
    o.printBill();
    
    return 0;
         
}
