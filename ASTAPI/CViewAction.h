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

	zACTION mouse_enter	;	// указатель входит в область компонента
	zACTION mouse_leave	;	// указатель покидает область компонента
	zACTION mouse_hover	;	// указатель неподвижен в области компонента
	zACTION mouse_move	;	// указатель перемещается в области компонента
	zACTION mouse_down	;	// указатель нажимает на облать компонента
	zACTION mouse_up	;	// указатель отжимает от области компонента
	zACTION mouse_loop	;	// постоянный цикл

	// -------------------------------------------------------------------;

	ASTAPI ~CViewAction();
};
