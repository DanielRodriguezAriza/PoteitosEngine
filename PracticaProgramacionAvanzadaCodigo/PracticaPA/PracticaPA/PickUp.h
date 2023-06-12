#pragma once
#include <string>
#include "Solid.h"
#include "Model.h"
#include "ModelLoader.h"

class PickUp : public Solid
{
public:
	PickUp();
	PickUp(Vector3D const& newPos);

	void Render() override;
	void Update(double dt) override;

	void collideWithSolid(Solid& other) override;

	virtual void Pick();

	void setPickUpModel(std::string const& s);

protected:
	Model pickUpModel;
};