#include <iostream>
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>
#include "list.h"

TEST_CASE("New list is empty", "[list]") {
	List list;
	CHECK(list.Empty() == true);
	CHECK(list.Size() == 0);
}

TEST_CASE("Cleared list is empty", "[list]") {
	List list;
	list.PushBack(1);
	list.PushBack(2);
	list.Clear();
	CHECK(list.Empty() == true);
	CHECK(list.Size() == 0);
}

// Тест-кейсы на добавление элементов разными способами

TEST_CASE("Correct number of items #1", "[list]") {
	List list;
	CHECK(list.Size() == 0);
	list.PushBack(1);
	CHECK(list.Size() == 1);
	list.PushBack(2);
	CHECK(list.Size() == 2);
}

TEST_CASE("Correct number of items #2", "[list]") {
	List list;
	CHECK(list.Size() == 0);
	list.PushFront(1);
	CHECK(list.Size() == 1);
	list.PushFront(2);
	CHECK(list.Size() == 2);
}

TEST_CASE("Correct number of items #3", "[list]") {
	List list;
	CHECK(list.Size() == 0);
	list.PushBack(1);
	CHECK(list.Size() == 1);
	list.PushFront(2);
	CHECK(list.Size() == 2);
}

TEST_CASE("Correct number of items #4", "[list]") {
	List list;
	CHECK(list.Size() == 0);
	list.PushFront(1);
	CHECK(list.Size() == 1);
	list.PushBack(2);
	CHECK(list.Size() == 2);
}

TEST_CASE("Correct number of items #5 (many items)", "[list]") {
	List list;
	CHECK(list.Size() == 0);
	for (auto i = 1; i <= 10; ++i)
	{
		list.PushFront(i);
		CHECK(list.Size() == i);
	}
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
    return Catch::Session().run(argc, argv);
}