#include "Box.h"

Box::Box(Vector3 pos, Vector3 halfExtents) : Object(pos) {
	physx::PxBoxGeometry geo; geo.halfExtents = halfExtents;

}
