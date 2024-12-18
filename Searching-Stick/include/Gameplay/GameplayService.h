#pragma once
#include <SFML/System/String.hpp>
#include "Gameplay/StickCollection/StickCollectionController.h"
#include "Gameplay/StickCollection/StickCollectionModel.h"

namespace Gameplay
{
	using namespace StickCollection;

	class GameplayController;
	class StickCollectionContoller;
	enum class SearchType;

	class GameplayService
	{
	private:
		GameplayController* gameplay_controller;
		StickCollectionContoller* collection_controller;

	public:
		GameplayService();
		~GameplayService();

		void initialize();
		void update();
		void render();

		void reset();

		void searchElement(StickCollection::SearchType search_type);
		StickCollection::SearchType getCurrentSearchType();
		int getNumberOfSticks();
	};
}