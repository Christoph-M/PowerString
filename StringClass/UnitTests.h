#pragma once

#include "PowerString.h"


namespace Power {
	void AssertString(String& string, size_t length, size_t size = 0) {
		if (size > 0) assert(string.Size() == size);
		assert(string.Length() == length);
		assert(string.CString()[string.Length()] == '\0');
	}

	void TestCompareOperators() {
		String equalsPowerString = "equalsPowerString";
		String equalsCString = "equalsCString";
		String equalsChar = "c";
		String equalsNothing = "";

		AssertString(equalsPowerString, 17, 17 + String::s_defaultCapacity);
		AssertString(equalsCString, 13, 13 + String::s_defaultCapacity);
		AssertString(equalsChar, 1, 1 + String::s_defaultCapacity);
		AssertString(equalsNothing, 0, String::s_defaultCapacity);

		assert(equalsPowerString == equalsPowerString);
		assert(equalsChar == equalsChar);
		assert(equalsPowerString == "equalsPowerString");
		assert(equalsChar == "c");
		assert(equalsNothing == "");
		assert(equalsChar == 'c');
		assert(!(equalsPowerString == equalsCString));
		assert(!(equalsCString == equalsPowerString));
		assert(!(equalsNothing == equalsPowerString));
		assert(!(equalsPowerString == equalsNothing));
		assert(!(equalsPowerString == "does not equal power string"));
		assert(!(equalsPowerString == "does not equal"));
		assert(!(equalsPowerString == "equalsPowerStrinG"));
		assert(!(equalsNothing == "does not equal"));
		assert(!(equalsChar == "b"));
		assert(!(equalsPowerString == ""));
		assert(!(equalsChar == 'b'));
		assert(!(equalsPowerString == 'c'));
		assert(!(equalsNothing == 'c'));

		assert(equalsPowerString != equalsCString);
		assert(equalsCString != equalsPowerString);
		assert(equalsNothing != equalsPowerString);
		assert(equalsPowerString != equalsNothing);
		assert(equalsPowerString != "does not equal power string");
		assert(equalsPowerString != "does not equal");
		assert(equalsPowerString != "equalsPowerStrinG");
		assert(equalsNothing != "does not equal");
		assert(equalsChar != "b");
		assert(equalsPowerString != "");
		assert(equalsChar != 'b');
		assert(equalsPowerString != 'c');
		assert(equalsNothing != 'c');
		assert(!(equalsPowerString != equalsPowerString));
		assert(!(equalsChar != equalsChar));
		assert(!(equalsPowerString != "equalsPowerString"));
		assert(!(equalsChar != "c"));
		assert(!(equalsNothing != ""));
		assert(!(equalsChar != 'c'));
	}

	void TestConstructors() {
		String emptyConstructor;
		String capacityConstructor(static_cast<size_t>(5));
		String conversionCStringConstructor = "conversion c-string constructor";
		String cStringConstructor("c-string constructor");
		String conversionCharFillConstructor = 'c';
		String charFillConstructor('c');
		String cStringLengthConstructor("c-string length constructor", static_cast<size_t>(27));
		String charFillLengthConstructor('c', static_cast<size_t>(33));
		String copyConstructor(cStringConstructor);

		AssertString(emptyConstructor, 0, String::s_defaultCapacity);
		AssertString(capacityConstructor, 0, 6);
		AssertString(conversionCStringConstructor, 31, 31 + String::s_defaultCapacity);
		AssertString(cStringConstructor, 20, 20 + String::s_defaultCapacity);
		AssertString(conversionCharFillConstructor, String::s_defaultCapacity - 1, String::s_defaultCapacity);
		AssertString(charFillConstructor, String::s_defaultCapacity - 1, String::s_defaultCapacity);
		AssertString(cStringLengthConstructor, 27, 27 + String::s_defaultCapacity);
		AssertString(charFillLengthConstructor, 33, 33 + String::s_defaultCapacity);
		AssertString(copyConstructor, cStringConstructor.Length(), cStringConstructor.Size());

		assert(emptyConstructor == "");
		assert(capacityConstructor == "");
		assert(conversionCStringConstructor == "conversion c-string constructor");
		assert(cStringConstructor == "c-string constructor");
		char* charFillTest = new char[String::s_defaultCapacity]{ '\0' };
		memset(charFillTest, 'c', 255);
		assert(conversionCharFillConstructor == charFillTest);
		assert(charFillConstructor == charFillTest);
		assert(cStringLengthConstructor == "c-string length constructor");
		charFillTest[33] = '\0';
		assert(charFillLengthConstructor == charFillTest);
		delete[](charFillTest);
		charFillTest = nullptr;
		assert(copyConstructor == cStringConstructor);
	}

	void RunUnitTests() {
		TestCompareOperators();
		TestConstructors();
	}
}
