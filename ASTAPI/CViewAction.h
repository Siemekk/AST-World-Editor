#pragma once

class CViewAction;
typedef zVOID (__cdecl * zACTION) (CViewAction*);

class CViewAction : public CViewAni
{

public:

	struct {
		zBOOL	mouse_selected	: 1;
		zBOOL	mouse_pressed	: 1;
	};

	ASTAPI CViewAction();
	ASTAPI CViewAction(
		zACTION enter,
		zACTION leave,
		zACTION hover,
		zACTION move,
		zACTION down,
		zACTION up,
		zACTION loop);

	ASTAPI CViewAction* GetHighObject ();

	// -------------------------------------------------------------------;

	zACTION mouse_enter	;	// ��������� ������ � ������� ����������
	zACTION mouse_leave	;	// ��������� �������� ������� ����������
	zACTION mouse_hover	;	// ��������� ���������� � ������� ����������
	zACTION mouse_move	;	// ��������� ������������ � ������� ����������
	zACTION mouse_down	;	// ��������� �������� �� ������ ����������
	zACTION mouse_up	;	// ��������� �������� �� ������� ����������
	zACTION mouse_loop	;	// ���������� ����

	// -------------------------------------------------------------------;

	ASTAPI ~CViewAction();
};
