#pragma once
#include <SFML/Graphics.hpp>
#include <UI/UIElement/RectangleShapeView.h>

namespace Gameplay
{
	namespace StickCollection
	{
		struct Stick
		{
			int data;
			UI::UIElement::RectangleShapeView* stick_view;

			Stick() {}

			Stick(int data_value)
			{
				this->data = data_value;
				stick_view = new UI::UIElement::RectangleShapeView();
			}

			~Stick()
			{
				delete(stick_view);
			}
		};
	}
}
