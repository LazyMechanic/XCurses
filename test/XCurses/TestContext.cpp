#define CATCH_CONFIG_MAIN
#include <Catch2/catch.hpp>

#include <XCurses/XCurses.h>

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
			REQUIRE(widget->getContext() == nullptr);
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

    SECTION("Call Context::add(...) for container Widget")
    {
		Object::Ptr<Container> container = Object::create<Container>();

        SECTION("Container add child Widget befor add into context")
        {
			Object::Ptr<Widget> widget = Object::create<Widget>();
			container->add(widget);

			REQUIRE(context->add(container) == Status::Ok);
			REQUIRE(context->has(container) == true);
			REQUIRE(context->has(widget) == true);

            SECTION("Remove child Widget from the container")
            {
				container->remove(widget);

				REQUIRE(context->has(widget) == false);
            }
        }

		SECTION("Container add child Widget after add into context")
		{
			Object::Ptr<Widget> widget = Object::create<Widget>();
			REQUIRE(context->add(container) == Status::Ok);
			REQUIRE(context->has(container) == true);

			container->add(widget);
			REQUIRE(context->has(widget) == true);

			SECTION("Remove child Widget from the container")
			{
				container->remove(widget);

				REQUIRE(context->has(widget) == false);
			}
		}
    }
}

uint64_t g_testValue = 0;

class TestContainer : public Container
{
public:
    void update(float dt) override
    {
		g_testValue = getId();
    }
};

class TestWidget : public Widget
{
public:
    void update(float dt) override
    {
		g_testValue = getId();
    }
};

TEST_CASE("Container and widget draw and update sequence", "[Widget][Container][Context]")
{
	Object::Ptr<Context> context = Object::create<Context>();

    SECTION("Add the container into context")
    {
		Object::Ptr<TestContainer> container1 = Object::create<TestContainer>();
		Object::Ptr<TestWidget> widget1 = Object::create<TestWidget>();
		Object::Ptr<TestWidget> widget2 = Object::create<TestWidget>();
		Object::Ptr<TestWidget> widget3 = Object::create<TestWidget>();

		context->add(container1);
		context->update(0.0f);

		REQUIRE(g_testValue == container1->getId());

        SECTION("Add widgets into container")
        {
			container1->add(widget1);
			container1->add(widget2);
			container1->add(widget3);
			context->update(0.0f);

			REQUIRE(g_testValue == widget3->getId());

            SECTION("Change front widget")
            {
				widget2->toFront();
				context->update(0.0f);

				REQUIRE(g_testValue == widget2->getId());
            }

        }
    }

	SECTION("Add several nested containers into context")
    {
		Object::Ptr<TestContainer> container1 = Object::create<TestContainer>();
		Object::Ptr<TestContainer> container2 = Object::create<TestContainer>();
		Object::Ptr<TestWidget> widget1 = Object::create<TestWidget>();
		Object::Ptr<TestWidget> widget2 = Object::create<TestWidget>();
		Object::Ptr<TestWidget> widget3 = Object::create<TestWidget>();

		container1->add(container2);
		container1->add(widget1);

		container2->add(widget2);
		container2->add(widget3);

		context->add(container1);
		context->update(0.0f);

		REQUIRE(g_testValue == widget1->getId());

        SECTION("Change front widget")
        {
			container2->toFront();
			context->update(0.0f);

			REQUIRE(g_testValue == widget3->getId());
        }
    }
}