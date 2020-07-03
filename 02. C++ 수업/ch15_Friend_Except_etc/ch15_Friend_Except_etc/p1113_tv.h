#pragma once

class Tv
{
private:
	int state;	// On or Off
	int volume;	// ������ �����̶� ����
	int maxchannel;	// �ִ� ä�� ��
	int channel;	// ���� ������ ä��
	int mode;	// ������ ��� or ���̺� ���
	int input;	// TV �Է� or DVD �Է�

public:
	friend class Remote;	// Remote�� Tv�� private �κп� ���� �� �� �ִ�.
	enum { Off, On };
	enum { MinVal, MaxVal = 20};
	enum { Antenna, Cable };
	enum { TV, DVD };

	Tv(int s = Off, int mc = 125) :state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV) {}
	void OnOff() { state = (state == On) ? Off : On; }
	bool IsOn() const { return state == On; }
	bool VolUp();
	bool VolDown();
	void ChanUp();
	void ChanDown();
	void Set_Mode() { mode = (mode == Antenna) ? Cable : Antenna; }
	void Set_Input() { input = (input == TV) ? DVD : TV; }
	void Settings() const;	// ��� ���� ���� ����Ѵ�.
};

class Remote
{
private:
	int mode;	// TV ������ or DVD ������

public:
	Remote(int m = Tv::TV) :mode(m) { }
	bool Volup(Tv & t) { return t.VolUp(); }
	bool VolDown(Tv & t) { return t.VolDown(); }
	void OnOff(Tv & t) { t.OnOff(); }
	void ChanUp(Tv & t) { t.ChanUp(); }
	void ChanDown(Tv & t) { t.ChanDown(); }
	void Set_Chan(Tv & t, int c) { t.channel = c; }
	void Set_Mode(Tv & t) { t.Set_Mode(); }
	void Set_Input(Tv & t) { t.Set_Input(); }
};