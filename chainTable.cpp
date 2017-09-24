#include <iostream>
#include "chainTable.h"

using namespace std;

template <class T>
ChainTable<T>::ChainTable(){
	m_headp = NULL;
};//default constructor

template <class T>
ChainTable<T>::ChainTable(const ChainTable & src){
	DataNode * srcp = src.m_headp;//source pointer
	DataNode * currentp;
	DataNode * thisp = m_headp = NULL;//initialize head pointer and this pointer
	while (srcp){
		currentp = new DataNode;
		currentp->data = srcp->data;//copy value
		currentp->nextp = NULL;
		if (m_headp){
			thisp->nextp = currentp;
			thisp = thisp->nextp;//move pointer
		} else {
			m_headp = currentp;
			thisp = m_headp;
		}
		srcp = srcp->nextp;//move pointer
	}
}//copy constructor

template <class T>
ChainTable<T>::~ChainTable(){
	while (m_headp){
		DataNode * p = m_headp->nextp;
		delete m_headp;
		m_headp = p;
	}
}//destructor

template <class T>
ChainTable<T> & ChainTable<T>::push(const T & item){
	DataNode * currentp = new DataNode;
	currentp->data = item;
	currentp->nextp = NULL;
	if (!m_headp){
		m_headp = currentp;
		return *this;
	}

	//m_headp != NULL
	DataNode * lastp = m_headp;
	while (lastp->nextp){
		lastp = lastp->nextp;//move pointer
	}
	lastp->nextp = currentp;//reset lastp->nextp
	return *this;
}

template <class T>
ChainTable<T> & ChainTable<T>::reverse(){
	if (!m_headp || !m_headp->nextp);
	else {
		//two or more items
		DataNode * p1, * p2, * p3;
		p1 = m_headp;
		p2 = m_headp->nextp;
		m_headp->nextp = NULL;//make head node be last node
		while (p2->nextp){
			p3 = p2->nextp;
			p2->nextp = p1;
			p1 = p2;//move pointer
			p2 = p3;//move pointer
		}
		//p2->nextp == NULL
		p2->nextp = p1;
		m_headp = p2;//p2 is the last node's pointer and the new head pointer
	}
	return *this;
}

template <class T>
const ChainTable<T> & ChainTable<T>::print(const char sep[]) const {
	DataNode * thisp = m_headp;
	while (thisp){
		cout << thisp->data << sep;
		thisp = thisp->nextp;//move pointer
	}
	return *this;
}

template <class T>
ChainTable<T> & ChainTable<T>::sort(const bool sort_way){
	if (!m_headp || !m_headp->nextp);
	else {
		//more than two items
		DataNode * p1 = m_headp;
		DataNode * p2 = m_headp->nextp;//target item
		while (p2){
			p1 = m_headp;//reset p1;
			if ((sort_way && p1->data > p2->data) || (!sort_way && p1->data < p2->data)){
				//first compared with m_headp
				DataNode * p3 = p2->nextp;
				DataNode * p4 = m_headp;
				while (p4->nextp != p2){
					p4 = p4->nextp;
				}//now p4->nextp == p2
				m_headp = p2;//redirect pointer
				p2->nextp = p1;//redirect pointer
				p4->nextp = p3;//redirect pointer
				p2 = p3;//move pointer
				continue;
			}
			//compared with m_headp over
			while (p1->nextp != p2 && ((sort_way && p1->nextp->data < p2->data) || (!sort_way && p1->nextp->data > p2->data))){
				p1 = p1->nextp;
			}//move p1 to a proper place where p1->nextp should be p2
			if (p1->nextp != p2){
				DataNode * p3 = p1->nextp;
				DataNode * p4 = p2->nextp;
				p1->nextp = p2;//redirect pointer
				p2->nextp = p3;//redirect pointer
				p3->nextp = p4;//redirect pointer
				p2 = p4;//move pointer
			} else {
				p2 = p2->nextp;//move pointer
			}
		}
	}
	return *this;
}