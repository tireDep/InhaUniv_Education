#pragma once

class Tv
{
private:
	int state;	// On or Off
	int volume;	// 디지털 볼륨이라 가정
	int maxchannel;	// 최대 채널 수
	int channel;	// 현재 설정된 채널
	int mode;	// 지상파 방송 or 케이블 방송
	int input;	// TV 입력 or DVD 입력

public:
	friend class Remote;	// Remote는 Tv의 private 부분에 접근 할 수 있다.
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
	void Settings() const;	// 모든 설정 값을 출력한다.
};

class Remote
{
private:
	int mode;	// TV 조정기 or DVD 조정기

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