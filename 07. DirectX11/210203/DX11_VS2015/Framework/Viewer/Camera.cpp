#include "Framework.h"
#include "Camera.h"

Camera::Camera() : 
	position(0,0,0), 
	rotation(0,0,0),
	forward(0,0,1),
	right(1,0,0),
	up(0,1,0)
{
	D3DXMatrixIdentity(&matView);
	Move();
}

Camera::~Camera()
{
}

void Camera::Position(float x, float y, float z)
{
	Position(Vector3(x, y, z));
}

void Camera::Position(Vector3 & vec)
{
	position = vec;
	Move();
}

void Camera::Position(Vector3 * vec)
{
	*vec = position;
	// >> 위치 가져오는 목적(Get)
}

void Camera::GetMatrix(Matrix * matrix)
{
	memcpy(matrix, &matView, sizeof(Matrix));
}

void Camera::View()
{
	D3DXMatrixLookAtLH(&matView, &position, &(position + forward), &up);
}

void Camera::Move()
{
	View();
}
