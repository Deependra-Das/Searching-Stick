#include "Gameplay/GameplayService.h"
#include "Gameplay/GameplayController.h"
#include "Global/ServiceLocator.h"

namespace Gameplay
{
	using namespace Global;

	GameplayService::GameplayService()
	{
		gameplay_controller = new GameplayController();
		stick_collection_controller = new StickCollectionController();
	}

	GameplayService::~GameplayService()
	{
		delete(gameplay_controller);
		delete(stick_collection_controller);
	}

	void GameplayService::initialize()
	{
		gameplay_controller->initialize();
		stick_collection_controller->initialize();
		initializeRandomSeed();
	}

	void GameplayService::initializeRandomSeed()
	{
		std::srand(static_cast<unsigned int>(std::time(nullptr)));
	}


	void GameplayService::update()
	{
		gameplay_controller->update();
		stick_collection_controller->update();
	}

	void GameplayService::render()
	{
		gameplay_controller->render();
		stick_collection_controller->render();
	}

	void GameplayService::reset()
	{
		gameplay_controller->reset();
		stick_collection_controller->reset();
	}

}