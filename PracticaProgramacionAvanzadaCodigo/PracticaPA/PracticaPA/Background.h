#pragma once
#include "Solid.h"
#include "Model.h"
#include "ModelLoader.h"

class Background : public Solid
{
public:
	Background();

	void loadBackground(std::string s);
	void Render() override;
	void Update(double dt) override;
	
	inline void setBackgroundSpeed(Vector3D newSpeed) { this->backgroundSpeed = newSpeed; }

	inline void setModel(Model const& model) { this->backgroundModel.setModel(model); }

private:
	Model backgroundModel;
	Vector3D backgroundSpeed;
};