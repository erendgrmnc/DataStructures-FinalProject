/*@file  :BinaryTree.h
* @description :BinarySearchTree sınıfının tanımlanması yapılan header dosyası.
* @course  :2.Öğretim C Grubu
* @assignment : 3
* @date  :9.12.2019
* @author :Salih Eren Değirmenci(salih.degirmenci@ogr.sakarya.edu.tr) Berkay Çete(berkay.cete@ogr.sakarya.edu.tr)*/
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include "fstream"
#include "windows.h"
#include "Node.h"
#include "string.h"
#include "string"

using namespace std;

class BinarySearchTree
{
public:

	

	BinarySearchTree();
	~BinarySearchTree();
	
	
	void AddNode(Node*& node, int Data);//Agaca node ekleyen metod.
	bool SearchAndDelete(Node*& node,int Data);
	bool Delete(Node*& node);//Agactan node silen metod
	void PostOrder(Node*& node);//Agaci postorder yazdiran metod.
    Node* minNode(Node*& node);//Sol alt agacin max degerini bulan metod.
	void AddTreeFromText(Node*& node,string fileName);//Text dosyasindan agaca node ekleyen metod.
	int getNodeCount(Node*& node);//Agacin icindeki nodelari sayan metod.
	Node*& ReturnRoot();//Agacin rootunu donduren metod.
	void IncScore();//Skor alinca skoru arttıran metod.
	int PrintScore();//Skoru yazdiran metod.
	int PrintMaxValue();//Maksimum degerli nodeun degerini yazdiran metod.
	int FindMaxValue(Node*& node);//Agacin maksimum degerini hesaplayan metod.
	int PrintToplamSoy();//Toplam soy sayisini hesaplayan metod.
	void ResetToplamSoy();//Toplam soy sayisini sifirlayan metod.



private:
	
    Node* root = nullptr;
	int score;
	int maxValue;
	int toplamSoy = 0;
	
};






#endif