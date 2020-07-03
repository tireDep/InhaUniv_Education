#pragma once

class Tv;	//  ���� ����

class Remote
{
private:
	int mode;

public:
	enum State { Off, On };
	enum { MinVal, MaxVal = 20 };
	enum { Antenna, Cable };
	enum { TV, DVD };

	Remote(int m = TV) : mode(m) { }
	bool Volup(Tv & t);
	bool VolDown(Tv & t);
	void OnOff(Tv & t);
	void ChanUp(Tv & t);
	void ChanDown(Tv & t);
	void Set_Chan(Tv & t, int c);
	void Set_Mode(Tv & t);
	void Set_Input(Tv & t);
};

class Tv
{
private:
	int state;
	int volume;
	int maxchannel;
	int channel;
	int mode;
	int input;

public:
	friend void Remote::Set_Chan(Tv & t, int c);	// ������ ��� �Լ�, Tv�� private ����� ����
	// Set_Chan�� Tv�� private ����� ä�ο� �����ϱ� ������, Remote Ŭ���� ��ü�� friedn �� �ʿ�� x

	enum State { Off, On };
	enum { MinVal, MaxVal = 20 };
	enum { Antenna, Cable };
	enum { TV, DVD };
	`
	Tv(int s = Off, int mc = 125) :state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV) {}
	void OnOff() { state = (state == On) ? Off : On; }
	bool IsOn() const { return state == On; }
	bool VolUp();
	bool VolDown();
	void ChanUp();
	void ChanDown();
	void Set_Mode() { mode = (mode == Antenna) ? Cable : Antenna; }
	void Set_Input() { input = (input == TV) ? DVD : TV; }
	void Settings() const;
};

// �ζ��� �Լ��� ����� Remote �޼����
inline bool Remote::Volup(Tv & t) { return t.VolUp(); }
inline bool Remote::VolDown(Tv & t) { return t.VolDown(); }
inline void Remote::OnOff(Tv & t) { t.OnOff(); }
inline void Remote::ChanUp(Tv & t) { t.ChanUp(); }
inline void Remote::ChanDown(Tv & t) { t.ChanDown(); }
inline void Remote::Set_Chan(Tv & t, int c) { t.channel = c; }
inline void Remote::Set_Mode(Tv & t) { t.Set_Mode(); }
inline void Remote::Set_Input(Tv & t) { t.Set_Input(); }
