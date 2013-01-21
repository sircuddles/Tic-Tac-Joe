#pragma once

class GridElement {
private:
	int gridProperty;
	
public:
	GridElement(void);
	~GridElement(void);
	
	void setElement(int newProperty);
	int getElement();
};

