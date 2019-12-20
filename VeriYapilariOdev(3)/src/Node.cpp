/*@file  :Node.cpp
* @description :Node sınıfı için gereken metod gövdelerini bulundurur.
* @course  :2.Öğretim C Grubu
* @assignment : 3
* @date  :9.12.2019
* @author :Salih Eren Değirmenci(salih.degirmenci@ogr.sakarya.edu.tr) Berkay Çete(berkay.cete@ogr.sakarya.edu.tr)*/
#include "iostream"
#include "Node.h"
using namespace std;

Node::Node(int input)//Node un kurucu metodu.
{ 
	data = input;
	Right = NULL;
	Left = NULL;
}
int Node::Data()//Node un icindeki veriyi donduren metod.
{
	return data;
}



void Node::SetData(int Data)//Node'un icindeki veriyi parametresindeki veri ile degistiren metod.
{
	data = Data;
}

