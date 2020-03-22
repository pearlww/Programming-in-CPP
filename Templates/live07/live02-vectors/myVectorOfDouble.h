#ifndef myVectorOfDoubleOFINT_H_
#define myVectorOfDoubleOFINT_H_

//See comments in myVectorOfInt.h
class myVectorOfDouble {
private:
	double * content;
	int size;
	int capacity;
	void resize();

public:
	myVectorOfDouble();
	myVectorOfDouble(int initialCapacity);

	~myVectorOfDouble();


	int getCapacity();
	int getSize();
	void push_back(double v);

	double at(unsigned int where);
	double & operator[](unsigned int where);

	myVectorOfDouble & operator=(myVectorOfDouble &);
};

#endif /* myVectorOfDoubleOFINT_H_ */
