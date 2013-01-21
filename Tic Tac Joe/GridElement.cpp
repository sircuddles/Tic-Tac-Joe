#include "GridElement.h"

GridElement::GridElement(void) {} 
GridElement::~GridElement(void) {}

void GridElement::setElement(int newProperty) {
	GridElement::gridProperty = newProperty;
}

int GridElement::getElement() {
	return gridProperty;
}