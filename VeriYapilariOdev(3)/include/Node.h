/*@file  :Node.h
* @description :Node sınıfının tanımlanması yapılan header dosyası.
* @course  :2.Öğretim C Grubu
* @assignment : 3
* @date  :9.12.2019
* @author :Salih Eren Değirmenci(salih.degirmenci@ogr.sakarya.edu.tr) Berkay Çete(berkay.cete@ogr.sakarya.edu.tr)*/
#ifndef NODE_HPP
#define NODE_HPP

#include "windows.h"
#include "string"

class Node
{
public:
	Node(int input);//Dugum Olusturan Metod.
	
	Node* Right;//Dugumun Sagindaki dugumu referansi.
	Node* Left;//Dugumun solundaki dugumun referansi.
	int Data();//Dugumun icindeki veriyi donduren metod.
	void SetData(int Data);//Dugumun icindeki veriyi degistiren metod.
	

private:
	int data;

};


#endif