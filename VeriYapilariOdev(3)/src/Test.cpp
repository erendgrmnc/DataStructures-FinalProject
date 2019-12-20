/*@file  :Test.cpp
* @description :Test programı için gereken kodları bulundurur.
* @course  :2.Öğretim C Grubu
* @assignment : 3
* @date  :9.12.2019
* @author :Salih Eren Değirmenci(salih.degirmenci@ogr.sakarya.edu.tr) Berkay Çete(berkay.cete@ogr.sakarya.edu.tr)*/

#include "BinaryTree.h"
#include "iostream"
#include "fstream"
#include "string.h"

 
using namespace std;



int main()
{

char ans;
int scoreCounter = 0;

//Gerekli Agac nesnelerinin olusturulmasi.
	BinarySearchTree* BenimTree = new BinarySearchTree();
	BinarySearchTree* RakipTree = new BinarySearchTree();

	//Text dosyalarindaki verilerin agaclara yerlestirilmesini saglayan fonksiyonun cagirilmasi.
	
	BenimTree->AddTreeFromText(BenimTree->ReturnRoot(), "benim.txt");
	RakipTree->AddTreeFromText(RakipTree->ReturnRoot(), "rakip.txt");
	


		do{
           //Agaclarin postorder sekilde ekrana yazdirilmasi
            cout << "--------- BENIM AGACIM ---------" << endl;
			BenimTree->PostOrder(BenimTree->ReturnRoot()); cout << endl;
			cout << "En Buyuk Deger :" << BenimTree->FindMaxValue(BenimTree->ReturnRoot()) << endl;
			cout << " Toplam Soy: " << BenimTree->PrintToplamSoy() << endl;
            
			cout << "--------- RAKIP AGAC ---------" << endl;
			RakipTree->PostOrder(RakipTree->ReturnRoot()); cout << endl;
			cout << "En Buyuk Deger :" << RakipTree->FindMaxValue(RakipTree->ReturnRoot()) << endl;
			cout << " Toplam Soy: " << RakipTree->PrintToplamSoy(); cout << endl;

        //Eger rakip dugumun toplam soyu daha buyukse benim agacinin en buyuk degerli node u silinir ve rakibe verilir.
			if (RakipTree->PrintToplamSoy() > BenimTree->PrintToplamSoy())
			{
				cout << "-------TEBRIKLER TURU KAZANDINIZ !-------" << endl;
				BenimTree->IncScore();
				scoreCounter++;
				cout <<"Benim Skorum : " << BenimTree->PrintScore() << endl;
				cout <<"Rakip SKor : " << RakipTree->PrintScore() << endl;
				cout << "--------------------------------" << endl;
				int toBeDeleted = RakipTree->FindMaxValue(RakipTree->ReturnRoot());
				RakipTree->SearchAndDelete(RakipTree->ReturnRoot(), toBeDeleted);
				BenimTree->AddNode(BenimTree->ReturnRoot(), toBeDeleted);
				RakipTree->AddNode(RakipTree->ReturnRoot(),BenimTree->ReturnRoot()->Data());
				BenimTree->SearchAndDelete(BenimTree->ReturnRoot(),BenimTree->ReturnRoot()->Data());
				RakipTree->ResetToplamSoy();
				BenimTree->ResetToplamSoy();
			}

        //Eger Benim agacinin toplam soyu Rakip agacinin toplam soyundan buyukse benim agacinin en buyuk degerli node u silinir ve Rakip agacina verilir.
			else if (BenimTree->PrintToplamSoy() > RakipTree->PrintToplamSoy())
			{
				cout << "-------TURU KAYBETINIZ !-------" << endl;
				RakipTree->IncScore();
				scoreCounter++;
				cout << "Benim Skorum : " << BenimTree->PrintScore() << endl;
				cout <<"Rakip Skor : " << RakipTree->PrintScore() << endl;
				cout << "--------------------------------" << endl;
				int toBeDeleted = BenimTree->FindMaxValue(BenimTree->ReturnRoot());
				int toBeDeletedRoot = RakipTree->ReturnRoot()->Data();
				BenimTree->SearchAndDelete(BenimTree->ReturnRoot(), toBeDeleted);
				RakipTree->AddNode(RakipTree->ReturnRoot(), toBeDeleted);
				BenimTree->AddNode(BenimTree->ReturnRoot(),RakipTree->ReturnRoot()->Data());
				RakipTree->SearchAndDelete(RakipTree->ReturnRoot(),toBeDeletedRoot);
				RakipTree->ResetToplamSoy();
				BenimTree->ResetToplamSoy();
			}
				//Eger Toplam soylar esit ise her agactaki en buyuk degerli node lar takaslanır.
				else if(BenimTree->PrintToplamSoy() == RakipTree->PrintToplamSoy())
			{
				cout << "----------BERABERE ----------" << endl;
				cout << "Benim Skorum : " << BenimTree->PrintScore() << endl;
				cout << "Rakip Skor : " << RakipTree->PrintScore() << endl;
			    
				BenimTree->AddNode(BenimTree->ReturnRoot(),RakipTree->ReturnRoot()->Data());
				RakipTree->AddNode(RakipTree->ReturnRoot(),BenimTree->ReturnRoot()->Data());

				BenimTree->SearchAndDelete(BenimTree->ReturnRoot(),BenimTree->ReturnRoot()->Data());
				RakipTree->SearchAndDelete(RakipTree->ReturnRoot(),RakipTree->ReturnRoot()->Data());

				RakipTree->ResetToplamSoy();
				BenimTree->ResetToplamSoy();
				
				
				

			}
			
			//Benim agacinin skoru 5 olduysa oyunu kazanir.
			 if(BenimTree->PrintScore() == 5)
			{
				cout << "---------TEBRIKLER OYUNU KAZANDINIZ ! ----------" << endl;
				cout << "Benim Skorum : " << BenimTree->PrintScore() << endl;
				cout << "Rakip Skor : " << RakipTree->PrintScore() << endl;
				
				break;

			}

           //Eger Rakip agacinin skoru 5 olduysa oyunu kazanir.
			else if(RakipTree->PrintScore() == 5)
			{
				cout << "--------- OYUNU KAYBETTINIZ ! ----------" << endl;
				cout << "Benim Skorum : " << BenimTree->PrintScore() << endl;
				cout << "Rakip Skor : " << RakipTree->PrintScore() << endl;
            
				break;

			}
            // Toplam tur 20'yi gectiyse ve Benim agacinin skoru fazlaysa oyunu kazanir.
			else if (scoreCounter == 20 && BenimTree->PrintScore() > RakipTree->PrintScore())
			{
				cout << "---------TEBRIKLER OYUNU KAZANDINIZ ! ----------" << endl;
				cout << "Benim Skorum : " << BenimTree->PrintScore() << endl;
				cout << "Rakip Skor : " << RakipTree->PrintScore() << endl;
				
				break;

			}

            //Toplam tur 20'yi gectiyse ve Rakip agacin skoru fazlaysa oyunu kazanir.
			else if(scoreCounter == 20 && RakipTree->PrintScore() > BenimTree->PrintScore())
			{
				cout << "--------- OYUNU KAYBETTINIZ ! ----------" << endl;
				cout << "Benim Skorum : " << BenimTree->PrintScore() << endl;
				cout << "Rakip Skor : " << RakipTree->PrintScore() << endl;				
				
				
				break;
			}
			
			


		
		}
		while(getchar() != '\r');

delete RakipTree;//Olusturulan nesnelerin silinmesi.
delete BenimTree;//Olusturulan nesnelerin silinmesi.
	
	system("pause");
	return 0;

	
} 