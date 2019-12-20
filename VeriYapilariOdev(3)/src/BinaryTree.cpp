/*@file  :BinaryTree.cpp
* @description :BinarySearchTree sınıfı için gereken metod gövdelerini bulundurur.
* @course  :2.Öğretim C Grubu
* @assignment : 3
* @date  :9.12.2019
* @author :Salih Eren Değirmenci(salih.degirmenci@ogr.sakarya.edu.tr) Berkay Çete(berkay.cete@ogr.sakarya.edu.tr)*/

#include "BinaryTree.h"
#include "iostream"
#include "fstream"
#include "string"
#include "climits"
using namespace std;

BinarySearchTree::BinarySearchTree()//Agacin kurucu metodu.
{
	score = 0;
	maxValue = 0;
	root = NULL;
}

BinarySearchTree::~BinarySearchTree()//Cop toplayan metod.
{

while (root != NULL)
{

  SearchAndDelete(root,root->Data());
}
	
}


void BinarySearchTree::AddNode(Node*& node, int Data)//Agaca node ekleyen metod.
{
	if (node == NULL)
	{
		Node* New = new Node(Data);
		node = New;
		if (Data > maxValue)
		{
			maxValue = Data;
		}
	}

	

	else if(Data > node->Data()) 
	{
		AddNode(node->Right, Data);
	}
	else if(Data <= node->Data())
	{
		AddNode(node->Left,Data);
	}
	





		

}

Node* BinarySearchTree::minNode(Node*& node) //Sol alt agacın en büyük degerini hesaplayan metod.
{
		

Node* temp = node;

	while (temp && temp->Right != NULL)
	{
		 temp = temp->Right;
	}

	return temp;

	
}

bool BinarySearchTree::SearchAndDelete(Node*& node ,int Data)
{
	if (node == NULL) return false; //Eleman yok
	if (node->Data() == Data)
		return Delete(node);
	else if (Data < node->Data())
		return SearchAndDelete(node->Left, Data);
	else
		return SearchAndDelete(node->Right,Data);

}

bool BinarySearchTree::Delete(Node*& node)//Agactan node silme islemi yapan metod.
{
	
	

		Node *toBeDeleted = node;

	if (node->Right == NULL) node = node->Left;
	else if (node->Left == NULL)node = node->Right;
	else {
		toBeDeleted = node->Left;
		Node *ebeveynDugum = node;
		while (toBeDeleted->Right != NULL) {
			ebeveynDugum = toBeDeleted;
			toBeDeleted = toBeDeleted->Right;
		}
		node->SetData(toBeDeleted->Data());
		if (ebeveynDugum == node) node->Left = toBeDeleted->Left;
		else ebeveynDugum->Right = toBeDeleted->Left;
	}
	delete toBeDeleted;
	return true;





}


void BinarySearchTree::PostOrder(Node*& node)//Agaci postorder sekilde yazdiran metod.
{

	
	if (node != NULL)
	{
		PostOrder(node->Left);
		PostOrder(node->Right);

		toplamSoy += getNodeCount(node);
		cout << node->Data() << " (" << getNodeCount(node) << ")" << " ";

	} 
	
}

int BinarySearchTree::getNodeCount(Node*& node)//Soy sayisini hesaplamaya yarayan metod.
{
	int count = 0;

	if (node->Left== NULL && node->Right ==NULL)
	{
		return 0;
	}

	if (node->Right !=NULL)
	{
		count++;
		count += getNodeCount(node->Right);
	}
	if (node->Left != NULL)
	{
		count++;
		count += getNodeCount(node->Left);
	}
	return count;
		

}

void BinarySearchTree::IncScore()//Agacin oyundaki skorunu arttıran metod.
{
	score++;

}

int BinarySearchTree::PrintScore()//Agacin skorunu donduren metod.
{
	return score;
}

int BinarySearchTree::PrintMaxValue()//Agacin maksimum degerini bastıran metod.
{
	return maxValue;
}

int BinarySearchTree::PrintToplamSoy()//Agacin toplam soyunu donduren metod.
{
	return toplamSoy;
}

void BinarySearchTree::ResetToplamSoy()//Agacin toplam soyunu sifirlayan metod.
{
	toplamSoy = 0;
	
}

int BinarySearchTree::FindMaxValue(Node*& node)//Agacin node larindaki maksimum veriyi bulan metod.
{
	if (node == NULL)
	{
		return INT_MIN;
		
	}
	int res = node->Data();
	int lres = FindMaxValue(node->Left);
	int rres = FindMaxValue(node->Right);

	if (lres > res)
	{
		res = lres;
	}

	if (rres > res)
	{
		res = rres;
	}
	maxValue = res;
	return maxValue;


	
 
}

Node*& BinarySearchTree::ReturnRoot() //Rootu döndüren metod.
{
	return root;
}


void BinarySearchTree::AddTreeFromText(Node*& node,string fileName)//Text dosyasindan agaca verileri node olarak ekleyen metod.
{


	ifstream file;
	int integer;
	file.open(fileName);

	while (file >> integer)
	{
		AddNode(node,integer);

	}
	file.close();
}

