#pragma once

namespace Gameplay
{
	namespace StickCollection
	{
		class StickCollectionView
		{
		public:
			StickCollectionView();
			~StickCollectionView();

			void initialize();
			void update();
			void render();
		};
	}
}