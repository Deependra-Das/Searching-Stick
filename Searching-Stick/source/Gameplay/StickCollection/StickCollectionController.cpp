#include "Gameplay/StickCollection/StickCollectionController.h"
#include "Gameplay/StickCollection/StickCollectionModel.h"
#include "Gameplay/StickCollection/StickCollectionView.h"
#include "Gameplay/StickCollection/Stick.h"
#include "Gameplay/GameplayService.h"
#include "Global/ServiceLocator.h"

namespace Gameplay
{
	namespace StickCollection
	{
		using namespace UI::UIElement;
		using namespace Global;
		using namespace Graphics;

		StickCollectionController::StickCollectionController()
		{
			stick_collection_model = new StickCollectionModel();
			stick_collection_view = new StickCollectionView();
			initializeSticksArray();
		}

		StickCollectionController::~StickCollectionController()
		{
			destroy();
		}

		void StickCollectionController::initializeSticksArray()
		{
			for (int i = 0; i < stick_collection_model->number_of_elements; i++)
			{
				sticks.push_back(new Stick(i));
			}
		}

		void StickCollectionController::initialize()
		{
			initializeSticks();
			reset();
		}

		void StickCollectionController::initializeSticks()
		{
			float rectangle_width = calculateStickWidth();
			for (int i = 0; i < stick_collection_model->number_of_elements; i++)
			{
				float rectangle_height = calculateStickHeight(i);
				sf::Vector2f rectangle_size = sf::Vector2f(rectangle_width, rectangle_height);
				sticks[i]->stick_view->initialize(rectangle_size, sf::Vector2f(0, 0), 0, stick_collection_model->element_color);

			}
		}

		float StickCollectionController::calculateStickWidth()
		{
			float total_space = static_cast<float>(ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize().x);
			float total_spacing = stick_collection_model->space_percentage * total_space;

			float space_between = total_spacing / (stick_collection_model->number_of_elements - 1);
			stick_collection_model->setElementSpacing(space_between);
			float remaining_space = total_space - total_spacing;
			float rectangle_width = remaining_space / stick_collection_model->number_of_elements;

			return rectangle_width;
		}

		float StickCollectionController::calculateStickHeight(int array_pos)
		{
			return (static_cast<float>(array_pos + 1) / stick_collection_model->number_of_elements) * stick_collection_model->max_element_height;
		}

		void StickCollectionController::updateSticksPosition()
		{
			for (int i = 0; i < sticks.size(); i++)
			{
				float x_pos = (i * sticks[i]->stick_view->getSize().x + (i + 1) * stick_collection_model->elements_spacing);
				float y_pos = stick_collection_model->element_y_position - sticks[i]->stick_view->getSize().y;

				sticks[i]->stick_view->setPosition(sf::Vector2f(x_pos, y_pos));

			}
		}

		void StickCollectionController::update()
		{
			for (int i = 0; i < sticks.size(); i++)
			{
				sticks[i]->stick_view->update();
			}
		}

		void StickCollectionController::render()
		{
			for (int i = 0; i < sticks.size(); i++)
			{
				sticks[i]->stick_view->render();
			}
		}

		void StickCollectionController::resetSticksColor()
		{
			for (int i = 0; i < sticks.size(); i++)
			{
				sticks[i]->stick_view->setFillColor(stick_collection_model->element_color);
			}
		}

		void StickCollectionController::reset()
		{
			updateSticksPosition();
			resetSticksColor();
		}

		void StickCollectionController::destroy()
		{
			for (int i = 0; i < sticks.size(); i++)
			{
				delete(sticks[i]);
			}
			sticks.clear();
			delete(stick_collection_model);
			delete(stick_collection_view);
		}

		void StickCollectionController::searchElement(SearchType search_type)
		{
		}

		SearchType StickCollectionController::getSearchType()
		{
			return search_type;
		}

		int StickCollectionController::getNumberOfSticks()
		{
			return stick_collection_model->number_of_elements;
		}
	}
}