#pragma once
#include <iostream>
#include <vector>
using namespace std;

class AlarmListener
{
public:
	virtual void Alarm() = 0;
};

class SensorSystem
{
private:
	vector<AlarmListener*> listeners;

public:
	void Attach(AlarmListener *al)
	{
		listeners.push_back(al);
	}

	void SoundTheAlarm()
	{
		for (int i = 0; i < listeners.size(); i++)
			listeners[i]->Alarm();
	}
};

class Lighting : public AlarmListener
{
public:
	void Alarm()
	{
		cout << "lights up" << '\n';
	}
};

class Gates : public AlarmListener
{
public:
	void Alarm()
	{
		cout << "gates close" << '\n';
	}
};

class CheckList
{
private:
	virtual void Localize()
	{
		cout << "   establish a perimeter" << '\n';
	}

	virtual void Isolate()
	{
		cout << "   isolate the grid" << '\n';
	}

	virtual void Identify()
	{
		cout << "   identify the source" << '\n';
	}

public:
	void ByTheNumbers()
	{
		// Template Method design pattern
		Localize();
		Isolate();
		Identify();
	}
};

// class inheri.  // type inheritance
class Surveillance : public CheckList, public AlarmListener
{
private:
	void Isolate()
	{
		cout << "   train the cameras" << '\n';
	}

public:
	void Alarm()
	{
		cout << "Surveillance - by the numbers:" << '\n';
		ByTheNumbers();
	}
};
