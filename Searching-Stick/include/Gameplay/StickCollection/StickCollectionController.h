#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <thread>

namespace Gameplay
{
	namespace StickCollection
	{
		class StickCollectionView;
		class StickCollectionModel;
		enum class SearchType;
		struct Stick;		

		class StickCollectionController
		{
		private:
			StickCollectionView* stick_collection_view;
			StickCollectionModel* stick_collection_model;
			Stick* stick_to_search;
			std::vector<Stick*> sticks;
			std::thread search_thread;
			SearchType search_type;
			int number_of_comparisons;
			int number_of_array_access;
			int current_operation_delay;

			void initializeSticks();
			float calculateStickWidth();
			void updateSticksPosition();
			void resetSticksColor();
			void initializeSticksArray();
			float calculateStickHeight(int array_pos);
			void shuffleSticks();
			void resetSearchStick();
			void processLinearSearch();
			void resetVariables();
			int getDelayMilliseconds();
			void processSearchThreadState();
			void joinThreads();
			void destroy();

		public:
			StickCollectionController();
			~StickCollectionController();

			void initialize();
			void update();
			void render();

			void reset();
			void searchElement(SearchType search_type);
			SearchType getSearchType();

			int getNumberOfSticks();
			int getNumberOfComparisons();
			int getNumberOfArrayAccess();

		};
	}
}