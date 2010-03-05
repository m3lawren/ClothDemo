#ifndef __CLOTH_SIMULATION_H__
#define __CLOTH_SIMULATION_H__

#include <Cloth/Constraint.h>
#include <Cloth/Vector.h>

#include <utility>
#include <vector>

namespace Cloth {

	class Simulation {
	public:
		Simulation();
		~Simulation();

		void tick();

		void clear();

		unsigned addPoint(float x, float y, float z);
		unsigned addPoint(const Cloth::Vector3&);

		unsigned addFixed(float x, float y, float z);
		unsigned addFixed(const Cloth::Vector3&);

		void addConstraint(unsigned, unsigned);

		void setGravity(float dx, float dy, float dz);
		void setGravity(const Cloth::Vector3&);

		void setBounds(float x1, float y1, float z1, float x2, float y2, float z2);

		unsigned numPoints() const;
		Cloth::Point& point(unsigned);
		const Cloth::Point& point(unsigned) const;

		unsigned numConstraints() const;
		const std::pair<unsigned,unsigned>& constraint(unsigned) const;

	private:
		typedef std::vector<Cloth::Point*>					pvec_t;
		typedef std::vector<Cloth::Constraint*>				cvec_t;
		typedef std::vector<std::pair<unsigned,unsigned> >	ivec_t;

		Cloth::BoundsConstraint	_bounds;
		pvec_t					_points;
		cvec_t					_constraints;
		ivec_t					_indices;
		Cloth::Vector3			_gravity;		

		Simulation(const Simulation&);
		Simulation& operator=(const Simulation&);
	};

};

#endif //__CLOTH_SIMULATION_H__