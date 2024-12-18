#pragma once
#include <SFML/Graphics.hpp>
#include "UI/Interface/IUIController.h"
#include "UI/UIElement/ImageView.h"
#include "UI/UIElement/ButtonView.h"
#include "UI/UIElement/TextView.h"
#include "Gameplay/GameplayService.h"

namespace UI
{
	namespace GameplayUI
	{
		class GameplayUIController : public Interface::IUIController
		{
		private:
		UIElement::TextView* search_type_text;
		UIElement::TextView* number_of_comparisons_text;
		UIElement::TextView* number_of_array_access_text;
		UIElement::TextView* num_sticks_text;
		UIElement::TextView* delay_text;
		UIElement::TextView* time_complexity_text;

		UIElement::ButtonView* menu_button;

		Gameplay::SearchType current_search_type;

		const float font_size = 40.f;

		const float text_y_position = 36.f;
		const float text_y_pos2 = 76.f;
		const float search_type_text_x_position = 480.f;
		const float comparisons_text_x_position =   960.f;
		const float array_access_text_x_position = 1440.f;
		const float num_sticks_text_x_position =  480.f;
		const float delay_text_x_position = 960.f;
		const float time_complexity_text_x_position = 1440.f;
		const float menu_button_x_position = 80.f;
		const float menu_button_y_position = 33.f;
		const float menu_button_width = 100.f;
		const float menu_button_height = 50.f;

		void createButton();
		void createTexts();
		void initializeButton();
		void initializeTexts();

		void updateSearchTypeText();
		void updateComparisonsText();
		void updateArrayAccessText();

		void updateNumberOfSticksText();
		void updateDelayText();
		void updateTimeComplexityText();

		void menuButtonCallback();
		void registerButtonCallback();

		void destroy();

		public:
		GameplayUIController();
		~GameplayUIController();

		void initialize() override;
		void update() override;
		void render() override;
		void show() override;

		};
	}
}