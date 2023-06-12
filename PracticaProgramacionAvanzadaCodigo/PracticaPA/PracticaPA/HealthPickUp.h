#pragma once
#include "PickUp.h"

class HealthPickUp : public PickUp
{
public:
	HealthPickUp(Vector3D const& newPos = Vector3D{});

	void Pick() override;

};