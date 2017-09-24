#ifndef CHAIN_TABLE_H_
#define CHAIN_TABLE_H_

template <class T>
class ChainTable{
private:
	struct DataNode{
		T data;
		DataNode * nextp;//next pointer
	} * m_headp;//head pointer
public:
	ChainTable();//default constructor
	ChainTable(const ChainTable & src);//copy constructor
	~ChainTable();//destructor
	ChainTable & push(const T & item);//add an item to the end of the chainTable
	ChainTable & reverse();//reverse this chainTable
	const ChainTable & print(const char sep[] = "\n") const;//separation
	ChainTable & sort(const bool sort_way = 1);//sort_way = 1 increasingly; sort_way = 0 decreasingly
};

#endif