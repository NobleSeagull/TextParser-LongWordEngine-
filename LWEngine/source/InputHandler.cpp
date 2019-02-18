#include "InputHandler.h"

InputHandler::InputHandler(SDL_Event * e, EventListener * el)
{
	m_e = e;
	m_eventListener = el;
}
void InputHandler::InputCheck()
{
	while (SDL_PollEvent(m_e) != 0)
	{
		switch (m_e->type)
		{
		case SDL_MOUSEBUTTONDOWN:
			if (!m_e->key.repeat)
			{
				switch (m_e->button.button)
				{
				case SDL_BUTTON_LEFT:
					m_eventListener->LeftClick = true;
					break;
				case SDL_BUTTON_RIGHT:
					m_eventListener->RightClick = true;
					break;

				default:
					break;
				}
				break;
			}

		case SDL_MOUSEBUTTONUP:
			if (!m_e->key.repeat)
			{
				switch (m_e->button.button)
				{
				case SDL_BUTTON_LEFT:
					m_eventListener->LeftClick = false;
					break;
				case SDL_BUTTON_RIGHT:
					m_eventListener->RightClick = false;
					break;

				default:
					break;
				}
				break;
			}
		case SDL_KEYDOWN:
		{
			switch (m_e->key.keysym.sym)
			{
			case SDLK_LCTRL:
				m_eventListener->Ctrl = true;
				break;
			case SDLK_RCTRL:
				m_eventListener->Ctrl = true;
				break;
			case SDLK_LSHIFT:
				m_eventListener->Shift = true;
				break;
			case SDLK_RSHIFT:
				m_eventListener->Shift = true;
				break;
			case SDLK_SPACE:
				m_eventListener->Space = true;
				break;
			case SDLK_ESCAPE:
				m_eventListener->Esc = true;
				break;
			case SDLK_UP:
				m_eventListener->Up = true;
				break;
			case SDLK_DOWN:
				m_eventListener->Down = true;
				break;
			case SDLK_LEFT:
				m_eventListener->Left = true;
				break;
			case SDLK_RIGHT:
				m_eventListener->Right = true;
				break;
			case SDLK_a:
				m_eventListener->A = true;
				break;
			case SDLK_b:
				m_eventListener->B = true;
				break;
			case SDLK_c:
				m_eventListener->C = true;
				break;
			case SDLK_d:
				m_eventListener->D = true;
				break;
			case SDLK_e:
				m_eventListener->E = true;
				break;
			case SDLK_f:
				m_eventListener->F = true;
				break;
			case SDLK_g:
				m_eventListener->G = true;
				break;
			case SDLK_h:
				m_eventListener->H = true;
				break;
			case SDLK_i:
				m_eventListener->I = true;
				break;
			case SDLK_j:
				m_eventListener->J = true;
				break;
			case SDLK_k:
				m_eventListener->K = true;
				break;
			case SDLK_l:
				m_eventListener->L = true;
				break;
			case SDLK_m:
				m_eventListener->M = true;
				break;
			case SDLK_n:
				m_eventListener->N = true;
				break;
			case SDLK_o:
				m_eventListener->O = true;
				break;
			case SDLK_p:
				m_eventListener->P = true;
				break;
			case SDLK_q:
				m_eventListener->Q = true;
				break;
			case SDLK_r:
				m_eventListener->R = true;
				break;
			case SDLK_s:
				m_eventListener->S = true;
				break;
			case SDLK_t:
				m_eventListener->T = true;
				break;
			case SDLK_u:
				m_eventListener->U = true;
				break;
			case SDLK_v:
				m_eventListener->V = true;
				break;
			case SDLK_w:
				m_eventListener->W = true;
				break;
			case SDLK_x:
				m_eventListener->X = true;
				break;
			case SDLK_y:
				m_eventListener->Y = true;
				break;
			case SDLK_z:
				m_eventListener->Z = true;
				break;
			case SDLK_0:
				m_eventListener->Zero = true;
				break;
			case SDLK_1:
				m_eventListener->One = true;
				break;
			case SDLK_2:
				m_eventListener->Two = true;
				break;
			case SDLK_3:
				m_eventListener->Three = true;
				break;
			case SDLK_4:
				m_eventListener->Four = true;
				break;
			case SDLK_5:
				m_eventListener->Five = true;
				break;
			case SDLK_6:
				m_eventListener->Six = true;
				break;
			case SDLK_7:
				m_eventListener->Seven = true;
				break;
			case SDLK_8:
				m_eventListener->Eight = true;
				break;
			case SDLK_9:
				m_eventListener->Nine = true;
				break;
			case SDLK_MINUS:
				m_eventListener->Minus = true;
				break;
			case SDLK_EQUALS:
				m_eventListener->Equals = true;
				break;
			case SDLK_BACKSPACE:
				m_eventListener->Backspace = true;
				break;
			default:
				break;
			}
			break;
		}
		case SDL_KEYUP:
		{
			switch (m_e->key.keysym.sym)
			{
			case SDLK_LCTRL:
				m_eventListener->Ctrl = false;
				break;
			case SDLK_RCTRL:
				m_eventListener->Ctrl = false;
				break;
			case SDLK_LSHIFT:
				m_eventListener->Shift = false;
				break;
			case SDLK_RSHIFT:
				m_eventListener->Shift = false;
				break;
			case SDLK_SPACE:
				m_eventListener->Space = false;
				break;
			case SDLK_ESCAPE:
				m_eventListener->Esc = false;
				break;
			case SDLK_UP:
				m_eventListener->Up = false;
				break;
			case SDLK_DOWN:
				m_eventListener->Down = false;
				break;
			case SDLK_LEFT:
				m_eventListener->Left = false;
				break;
			case SDLK_RIGHT:
				m_eventListener->Right = false;
				break;
			case SDLK_a:
				m_eventListener->A = false;
				break;
			case SDLK_b:
				m_eventListener->B = false;
				break;
			case SDLK_c:
				m_eventListener->C = false;
				break;
			case SDLK_d:
				m_eventListener->D = false;
				break;
			case SDLK_e:
				m_eventListener->E = false;
				break;
			case SDLK_f:
				m_eventListener->F = false;
				break;
			case SDLK_g:
				m_eventListener->G = false;
				break;
			case SDLK_h:
				m_eventListener->H = false;
				break;
			case SDLK_i:
				m_eventListener->I = false;
				break;
			case SDLK_j:
				m_eventListener->J = false;
				break;
			case SDLK_k:
				m_eventListener->K = false;
				break;
			case SDLK_l:
				m_eventListener->L = false;
				break;
			case SDLK_m:
				m_eventListener->M = false;
				break;
			case SDLK_n:
				m_eventListener->N = false;
				break;
			case SDLK_o:
				m_eventListener->O = false;
				break;
			case SDLK_p:
				m_eventListener->P = false;
				break;
			case SDLK_q:
				m_eventListener->Q = false;
				break;
			case SDLK_r:
				m_eventListener->R = false;
				break;
			case SDLK_s:
				m_eventListener->S = false;
				break;
			case SDLK_t:
				m_eventListener->T = false;
				break;
			case SDLK_u:
				m_eventListener->U = false;
				break;
			case SDLK_v:
				m_eventListener->V = false;
				break;
			case SDLK_w:
				m_eventListener->W = false;
				break;
			case SDLK_x:
				m_eventListener->X = false;
				break;
			case SDLK_y:
				m_eventListener->Y = false;
				break;
			case SDLK_z:
				m_eventListener->Z = false;
				break;
			case SDLK_0:
				m_eventListener->Zero = false;
				break;
			case SDLK_1:
				m_eventListener->One = false;
				break;
			case SDLK_2:
				m_eventListener->Two = false;
				break;
			case SDLK_3:
				m_eventListener->Three = false;
				break;
			case SDLK_4:
				m_eventListener->Four = false;
				break;
			case SDLK_5:
				m_eventListener->Five = false;
				break;
			case SDLK_6:
				m_eventListener->Six = false;
				break;
			case SDLK_7:
				m_eventListener->Seven = false;
				break;
			case SDLK_8:
				m_eventListener->Eight = false;
				break;
			case SDLK_9:
				m_eventListener->Nine = false;
				break;
			case SDLK_MINUS:
				m_eventListener->Minus = false;
				break;
			case SDLK_EQUALS:
				m_eventListener->Equals = false;
				break;
			case SDLK_BACKSPACE:
				m_eventListener->Backspace = false;
				break;
			default:
				break;
			}
			break;
		}
		}
	}
}