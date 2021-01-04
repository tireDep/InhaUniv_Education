#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Subject 
{
private:
	// 1. "independent" functionality
	vector<class Observer*> views; // 3. Coupled only to "interface"
	int value;

public:
	void Attach(Observer *obs) 
	{
		views.push_back(obs);
	}

	void SetVal(int val) 
	{
		value = val;
		Notify();
	}

	int GetVal() 
	{
		return value;
	}

	void Notify();
};

class Observer 
{
private:
	// 2. "dependent" functionality
	Subject *model;
	int denom;

public:
	Observer(Subject *mod, int div) 
	{
		model = mod;
		denom = div;
		// 4. Observers register themselves with the Subject
		model->Attach(this);
	}

	virtual void Update() = 0;

protected:
	Subject *GetSubject() 
	{
		return model;
	}

	int GetDivisor() 
	{
		return denom;
	}
};

void Subject::Notify() 
{
	// 5. Publisher broadcasts
	for (int i = 0; i < views.size(); i++)
		views[i]->Update();
}

class DivObserver : public Observer 
{
public:
	DivObserver(Subject *mod, int div) : Observer(mod, div) {}
	void Update() 
	{
		// 6. "Pull" information of interest
		int v = GetSubject()->GetVal(), d = GetDivisor();
		cout << v << " div " << d << " is " << v / d << '\n';
	}
};

class ModObserver : public Observer 
{
public:
	ModObserver(Subject *mod, int div) : Observer(mod, div) {}
	void Update() 
	{
		int v = GetSubject()->GetVal(), d = GetDivisor();
		cout << v << " mod " << d << " is " << v % d << '\n';
	}
};
