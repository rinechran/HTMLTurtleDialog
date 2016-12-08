#pragma once

class Mouse {
public:
	Mouse();
	bool getLbutton();
	bool getRbutton();
	void SetRbutton();
	void SetLbutton();
	void SetRbutton(bool);
	void SetLbutton(bool);

private:

	bool mIsLbutton;
	bool mIsRbutton;
};
