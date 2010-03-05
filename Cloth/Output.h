#ifndef __CLOTH_OUTPUT_H__
#define __CLOTH_OUTPUT_H__

#include <Cloth/Point.h>
#include <Cloth/Vector.h>

#include <iostream>

std::ostream& operator<<(std::ostream&, const Cloth::Point&);
std::ostream& operator<<(std::ostream&, const Cloth::Vector3&);

#endif //__CLOTH_OUTPUT_H__