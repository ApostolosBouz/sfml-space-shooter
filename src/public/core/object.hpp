#ifndef OBJECT_HPP
#define OBJECT_HPP

namespace game
{
	class Object
	{
	public:
        Object();
		virtual void update() = 0;
		virtual ~Object();

    protected:
        static unsigned int idCounter_;
        unsigned int id_;
	};
}

#endif