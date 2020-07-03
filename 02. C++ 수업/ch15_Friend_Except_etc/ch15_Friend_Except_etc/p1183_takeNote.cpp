/*
RTTI
- Runtime Type Identification
- 가상 함수들을 가지고 있는 클래스들에 대해서만 사용할 수 있다

[RTTI의 동작 방식]
- dynamic_cast 연산자 : 기초 클래스 형을 지시하는 포인터로부터 파생 클래스형을 지시하는 포인터 생성, 가능하지 x면 null포인터 0 리턴
- typeid 연산자 : 어떤 객체의 정확한 데이터형을 식별하는 하나의 값을 리턴
- type_info 구조체 : 어떤 특별한 데이터형에 대한 정보 저장

*/