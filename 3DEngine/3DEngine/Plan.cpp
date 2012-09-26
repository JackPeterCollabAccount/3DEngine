/*

Ingredients:
- ( ) Player
	- ( ) Vars
		- ( ) Health
- ( ) Actors
	- ( ) NPCs
	- ( ) Enemies

- ( ) Rooms
	- ( ) World
		- ( ) Chunks?
	- ( ) Rooms

- ( ) Graphics
	- ( ) Models
		- ( ) Model Loader (.x file)
	- ( ) Textures
		- ( ) Texture Loader
	- ( ) Menus 

- (x) Encryption

- (x) XMLLoader

- ( ) Physics Engine (Bullet?)

- ( ) Hook for external game (__declspec(dllimport)?)

func **array;
array_size;

update()
{
	for(int c = 0; c < array_size; c++)
		array[c](arg1, arg2, etc.);

}

actors.h
{

	class Actor (std::string name, std::string id)
	{
		public:
			virtual void Update();
	};

}

actors.cpp

}

*/