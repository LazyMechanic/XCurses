#define CATCH_CONFIG_MAIN
#include <Catch2/catch.hpp>

#include <XCurses/Widget.h>
#include <XCurses/Context.h>
#include <XCurses/Container.h>

using namespace xcur;

TEST_CASE("Container and widget init and edit", "[Widget][Container]")
{
	SECTION("Create widget") 
	{
		Object::Ptr<Widget> widget = Object::create<Widget>();
		REQUIRE(widget->getParent() == nullptr);
		REQUIRE(widget->getContext() == nullptr);
	}

	SECTION("Call Container::add(...) for new Widget")
	{
		Object::Ptr<Container> container = Object::create<Container>();
		Object::Ptr<Widget> widget = Object::create<Widget>();
		REQUIRE(container->add(widget) == Status::Ok);
		REQUIRE(container->has(widget) == true);
		REQUIRE(container->find(widget) != container->end());

		SECTION("Call Container::remove(...) for added Widget")
		{
			REQUIRE(container->remove(widget) == Status::Ok);
			REQUIRE(container->has(widget) == false);
			REQUIRE(container->find(widget) == container->end());
		}

		SECTION("Call Container::remove(...) for not added Widget")
		{
			Object::Ptr<Widget> notAdded = Object::create<Widget>();
			REQUIRE(container->remove(notAdded) == Status::Err);
			REQUIRE(container->has(notAdded) == false);
			REQUIRE(container->find(notAdded) == container->end());
		}
	}

	SECTION("Call Container::add(...) for existed Widget")
	{
		Object::Ptr<Container> container = Object::create<Container>();
		Object::Ptr<Widget> widget = Object::create<Widget>();
		REQUIRE(container->add(widget) == Status::Ok);
		REQUIRE(container->add(widget) == Status::Err);
	}
}

TEST_CASE("Context init and edit", "[Widget][Container][Context]")
{
	Object::Ptr<Context> context = Object::create<Context>();

    SECTION("Call Context::add(...) for single Widget")
    {
		Object::Ptr<Widget> widget = Object::create<Widget>();
		REQUIRE(context->add(widget) == Status::Ok);
		REQUIRE(context->has(widget) == true);
		REQUIRE(widget->getParent() != nullptr);
		REQUIRE(widget->getContext() != nullptr);

		SECTION("Call Context::remove(...) for added Widget")
		{
			REQUIRE(context->remove(widget) == Status::Ok);
			REQUIRE(context->has(widget) == false);
		}

		SECTION("Call Context::remove(...) for not added Widget")
		{
			Object::Ptr<Widget> notAdded = Object::create<Widget>();
			REQUIRE(context->remove(notAdded) == Status::Err);
		}

        SECTION("Call Context::toFront(...) for added Widget")
		{
			widget->toFront();
			REQUIRE(context->has(widget) == true);
		}
    }
}