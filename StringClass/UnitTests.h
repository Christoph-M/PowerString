#pragma once

#include "PowerString.h"


namespace Power {
	void AssertString(const String& string, size_t size, size_t capacity = 0, const char* const data = nullptr) {
		if (capacity > 0) assert(string.Capacity() == capacity);
		assert(string.Size() == size);
		assert(string.CString()[string.Size()] == '\0');
		if (data) assert(string == data);
	}

	size_t ResizedCapacity(size_t oldCapcity, size_t newSize) { return oldCapcity * 2 + newSize; }

	void TestComparisonOperators() {
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
		String conversionCharConstructor = 'c';
		String charConstructor('c');
		String cStringLengthConstructor("c-string length constructor", static_cast<size_t>(27));
		String charFillLengthConstructor('c', static_cast<size_t>(33));
		String copyConstructor(cStringConstructor);

		AssertString(emptyConstructor, 0, String::s_defaultCapacity, "");
		AssertString(capacityConstructor, 0, 6, "");
		AssertString(conversionCStringConstructor, 31, 31 + String::s_defaultCapacity, "conversion c-string constructor");
		AssertString(cStringConstructor, 20, 20 + String::s_defaultCapacity, "c-string constructor");
		AssertString(conversionCharConstructor, 1, String::s_defaultCapacity, "c");
		AssertString(charConstructor, 1, String::s_defaultCapacity, "c");
		AssertString(cStringLengthConstructor, 27, 27 + String::s_defaultCapacity, "c-string length constructor");
		char* charFillTest = new char[String::s_defaultCapacity]{ '\0' };
		memset(charFillTest, 'c', 33);
		AssertString(charFillLengthConstructor, 33, 33 + String::s_defaultCapacity, charFillTest);
		delete[](charFillTest);
		charFillTest = nullptr;
		AssertString(copyConstructor, cStringConstructor.Size(), cStringConstructor.Capacity(), "c-string constructor");
	}

	void TestAssignmentOperators() {
		String stringAssignment(static_cast<size_t>(12));
		String cstringAssignment(static_cast<size_t>(15));
		String charAssignment(static_cast<size_t>(1));

		AssertString(stringAssignment, 0, 13, "");
		AssertString(cstringAssignment, 0, 16, "");
		AssertString(charAssignment, 0, 2, "");

		cstringAssignment = "c-string";
		AssertString(cstringAssignment, 8, 16, "c-string");
		stringAssignment = cstringAssignment;
		AssertString(stringAssignment, 8, 13, "c-string");
		cstringAssignment = "c-string assignment";
		AssertString(cstringAssignment, 19, ResizedCapacity(16, 19), "c-string assignment");
		cstringAssignment = cstringAssignment.CString();
		AssertString(cstringAssignment, 19, ResizedCapacity(16, 19), "c-string assignment");
		stringAssignment = cstringAssignment;
		AssertString(stringAssignment, 19, ResizedCapacity(13, 19), "c-string assignment");
		stringAssignment = stringAssignment;
		AssertString(stringAssignment, 19, ResizedCapacity(13, 19), "c-string assignment");
		cstringAssignment = cstringAssignment.CString() + cstringAssignment.Size() - 10;
		AssertString(cstringAssignment, 10, ResizedCapacity(16, 19), "assignment");
		cstringAssignment = "";
		AssertString(cstringAssignment, 0, ResizedCapacity(16, 19), "");
		stringAssignment = charAssignment;
		AssertString(stringAssignment, 0, ResizedCapacity(13, 19), "");
		charAssignment = 'c';
		AssertString(charAssignment, 1, 2, "c");
	}

	void TestToString() {
		String toString;
		toString = String::ToString("c-string to string");
		AssertString(toString, 18, String::s_defaultCapacity, "c-string to string");
		toString = String::ToString("c-string length to string", 25);
		AssertString(toString, 25, String::s_defaultCapacity, "c-string length to string");
		toString = String::ToString('c');
		AssertString(toString, 1, String::s_defaultCapacity, "c");
		toString = String::ToString(std::numeric_limits<int16_t>::min());
		AssertString(toString, 6, String::s_defaultCapacity, "-32768");
		toString = String::ToString(std::numeric_limits<int16_t>::max());
		AssertString(toString, 5, String::s_defaultCapacity, "32767");
		toString = String::ToString(std::numeric_limits<uint16_t>::min());
		AssertString(toString, 1, String::s_defaultCapacity, "0");
		toString = String::ToString(std::numeric_limits<uint16_t>::max());
		AssertString(toString, 5, String::s_defaultCapacity, "65535");
		toString = String::ToString(std::numeric_limits<int32_t>::min());
		AssertString(toString, 11, String::s_defaultCapacity, "-2147483648");
		toString = String::ToString(std::numeric_limits<int32_t>::max());
		AssertString(toString, 10, String::s_defaultCapacity, "2147483647");
		toString = String::ToString(std::numeric_limits<uint32_t>::min());
		AssertString(toString, 1, String::s_defaultCapacity, "0");
		toString = String::ToString(std::numeric_limits<uint32_t>::max());
		AssertString(toString, 10, String::s_defaultCapacity, "4294967295");
		toString = String::ToString(std::numeric_limits<int64_t>::min());
		AssertString(toString, 20, String::s_defaultCapacity, "-9223372036854775808");
		toString = String::ToString(std::numeric_limits<int64_t>::max());
		AssertString(toString, 19, String::s_defaultCapacity, "9223372036854775807");
		toString = String::ToString(std::numeric_limits<uint64_t>::min());
		AssertString(toString, 1, String::s_defaultCapacity, "0");
		toString = String::ToString(std::numeric_limits<uint64_t>::max());
		AssertString(toString, 20, String::s_defaultCapacity, "18446744073709551615");
		toString = String::ToString(-std::numeric_limits<float>::min());
		AssertString(toString, 12, String::s_defaultCapacity, "-1.17549e-38");
		toString = String::ToString(std::numeric_limits<float>::max());
		AssertString(toString, 11, String::s_defaultCapacity, "3.40282e+38");
		toString = String::ToString(-std::numeric_limits<double>::min());
		AssertString(toString, 13, String::s_defaultCapacity, "-2.22507e-308");
		toString = String::ToString(std::numeric_limits<double>::max());
		AssertString(toString, 12, String::s_defaultCapacity, "1.79769e+308");
	}

	void TestShrinkToFit() {
		String shrinkToFit(static_cast<size_t>(999));
		shrinkToFit = "shrink to fit";

		AssertString(shrinkToFit, 13, 1000, "shrink to fit");

		shrinkToFit.ShrinkToFit();
		AssertString(shrinkToFit, 13, 14, "shrink to fit");
		shrinkToFit.ShrinkToFit();
		AssertString(shrinkToFit, 13, 14, "shrink to fit");
	}

	void TestCompoundAssignmentOperators() {
		String assignmentString("");
		String plusStringAssignment(static_cast<size_t>(0));
		String plusCStringAssignment(static_cast<size_t>(0));
		String plusCharAssignment(static_cast<size_t>(0));
		String plusShortAssignment(static_cast<size_t>(0));
		String plusUnsignedShortAssignment(static_cast<size_t>(0));
		String plusIntegerAssignment(static_cast<size_t>(0));
		String plusUnsignedIntegerAssignment(static_cast<size_t>(0));
		String plusLongLongAssignment(static_cast<size_t>(0));
		String plusUnsignedLongLongAssignment(static_cast<size_t>(0));
		String plusFloatAssignment(static_cast<size_t>(0));
		String plusDoubleAssignment(static_cast<size_t>(0));

		AssertString(assignmentString, 0, String::s_defaultCapacity, "");
		AssertString(plusStringAssignment, 0, 1, "");
		AssertString(plusCStringAssignment, 0, 1, "");
		AssertString(plusCharAssignment, 0, 1, "");
		AssertString(plusShortAssignment, 0, 1, "");
		AssertString(plusUnsignedShortAssignment, 0, 1, "");
		AssertString(plusIntegerAssignment, 0, 1, "");
		AssertString(plusUnsignedIntegerAssignment, 0, 1, "");
		AssertString(plusLongLongAssignment, 0, 1, "");
		AssertString(plusUnsignedLongLongAssignment, 0, 1, "");
		AssertString(plusFloatAssignment, 0, 1, "");
		AssertString(plusDoubleAssignment, 0, 1, "");

		plusStringAssignment += assignmentString;
		AssertString(plusStringAssignment, 0, 1, "");
		assignmentString = 'c';
		plusStringAssignment += assignmentString;
		AssertString(plusStringAssignment, 1, ResizedCapacity(1, 1), "c");
		plusStringAssignment += plusStringAssignment;
		AssertString(plusStringAssignment, 2, ResizedCapacity(1, 1), "cc");
		plusStringAssignment += plusStringAssignment;
		AssertString(plusStringAssignment, 4, ResizedCapacity(ResizedCapacity(1, 1), 4), "cccc");
		plusCStringAssignment += "";
		AssertString(plusCStringAssignment, 0, 1, "");
		plusCStringAssignment += "plus c-string assignment";
		AssertString(plusCStringAssignment, 24, ResizedCapacity(1, 24), "plus c-string assignment");
		plusCStringAssignment += "2";
		AssertString(plusCStringAssignment, 25, ResizedCapacity(1, 24), "plus c-string assignment2");
		plusCStringAssignment += plusCStringAssignment.CString();
		AssertString(plusCStringAssignment, 50, ResizedCapacity(ResizedCapacity(1, 24), 50), "plus c-string assignment2plus c-string assignment2");
		plusCStringAssignment += plusCStringAssignment.CString() + plusCStringAssignment.Size() - 5;
		plusCStringAssignment.ShrinkToFit();
		AssertString(plusCStringAssignment, 55, 56, "plus c-string assignment2plus c-string assignment2ment2");
		plusCStringAssignment += plusCStringAssignment.CString() + plusCStringAssignment.Size() - 1;
		AssertString(plusCStringAssignment, 56, ResizedCapacity(56, 56), "plus c-string assignment2plus c-string assignment2ment22");
		plusCharAssignment += 'c';
		AssertString(plusCharAssignment, 1, ResizedCapacity(1, 1), "c");
		plusCharAssignment += 'd';
		AssertString(plusCharAssignment, 2, ResizedCapacity(1, 1), "cd");
		plusCharAssignment += 'e';
		AssertString(plusCharAssignment, 3, ResizedCapacity(ResizedCapacity(1, 1), 3), "cde");
		plusShortAssignment += static_cast<int16_t>(0);
		AssertString(plusShortAssignment, 1, ResizedCapacity(1, 1), "0");
		plusShortAssignment += std::numeric_limits<int16_t>::min();
		AssertString(plusShortAssignment, 7, ResizedCapacity(ResizedCapacity(1, 1), 7), "0-32768");
		plusShortAssignment += std::numeric_limits<int16_t>::max();
		AssertString(plusShortAssignment, 12, ResizedCapacity(ResizedCapacity(1, 1), 7), "0-3276832767");
		plusUnsignedShortAssignment += std::numeric_limits<uint16_t>::min();
		AssertString(plusUnsignedShortAssignment, 1, ResizedCapacity(1, 1), "0");
		plusUnsignedShortAssignment += std::numeric_limits<uint16_t>::max();
		AssertString(plusUnsignedShortAssignment, 6, ResizedCapacity(ResizedCapacity(1, 1), 6), "065535");
		plusIntegerAssignment += static_cast<int32_t>(0);
		AssertString(plusIntegerAssignment, 1, ResizedCapacity(1, 1), "0");
		plusIntegerAssignment += std::numeric_limits<int32_t>::min();
		AssertString(plusIntegerAssignment, 12, ResizedCapacity(ResizedCapacity(1, 1), 12), "0-2147483648");
		plusIntegerAssignment += std::numeric_limits<int32_t>::max();
		AssertString(plusIntegerAssignment, 22, ResizedCapacity(ResizedCapacity(ResizedCapacity(1, 1), 12), 22), "0-21474836482147483647");
		plusUnsignedIntegerAssignment += std::numeric_limits<uint32_t>::min();
		AssertString(plusUnsignedIntegerAssignment, 1, ResizedCapacity(1, 1), "0");
		plusUnsignedIntegerAssignment += std::numeric_limits<uint32_t>::max();
		AssertString(plusUnsignedIntegerAssignment, 11, ResizedCapacity(ResizedCapacity(1, 1), 11), "04294967295");
		plusLongLongAssignment += static_cast<int64_t>(0);
		AssertString(plusLongLongAssignment, 1, ResizedCapacity(1, 1), "0");
		plusLongLongAssignment += std::numeric_limits<int64_t>::min();
		AssertString(plusLongLongAssignment, 21, ResizedCapacity(ResizedCapacity(1, 1), 21), "0-9223372036854775808");
		plusLongLongAssignment += std::numeric_limits<int64_t>::max();
		AssertString(plusLongLongAssignment, 40, ResizedCapacity(ResizedCapacity(ResizedCapacity(1, 1), 21), 40), "0-92233720368547758089223372036854775807");
		plusUnsignedLongLongAssignment += std::numeric_limits<uint64_t>::min();
		AssertString(plusUnsignedLongLongAssignment, 1, ResizedCapacity(1, 1), "0");
		plusUnsignedLongLongAssignment += std::numeric_limits<uint64_t>::max();
		AssertString(plusUnsignedLongLongAssignment, 21, ResizedCapacity(ResizedCapacity(1, 1), 21), "018446744073709551615");
		plusFloatAssignment += 0.0f;
		AssertString(plusFloatAssignment, 1, ResizedCapacity(1, 1), "0");
		plusFloatAssignment += -std::numeric_limits<float>::min();
		AssertString(plusFloatAssignment, 13, ResizedCapacity(ResizedCapacity(1, 1), 13), "0-1.17549e-38");
		plusFloatAssignment += std::numeric_limits<float>::max();
		AssertString(plusFloatAssignment, 24, ResizedCapacity(ResizedCapacity(ResizedCapacity(1, 1), 13), 24), "0-1.17549e-383.40282e+38");
		plusDoubleAssignment += 0.0;
		AssertString(plusDoubleAssignment, 1, ResizedCapacity(1, 1), "0");
		plusDoubleAssignment += -std::numeric_limits<double>::min();
		AssertString(plusDoubleAssignment, 14, ResizedCapacity(ResizedCapacity(1, 1), 14), "0-2.22507e-308");
		plusDoubleAssignment += std::numeric_limits<double>::max();
		AssertString(plusDoubleAssignment, 26, ResizedCapacity(ResizedCapacity(ResizedCapacity(1, 1), 14), 26), "0-2.22507e-3081.79769e+308");
	}

	void TestAdditionOperators() {
		String plusString(static_cast<size_t>(0));
		String plusStringOperator("plus string operator");
		String plusCStringOperator("plus c-string operator");

		AssertString(plusString, 0, 1, "");
		AssertString(plusStringOperator, 20, 20 + String::s_defaultCapacity, "plus string operator");
		AssertString(plusCStringOperator, 22, 22 + String::s_defaultCapacity, "plus c-string operator");

		plusString = plusStringOperator + plusString;
		AssertString(plusString, 20, ResizedCapacity(1, 20), "plus string operator");
		plusString = plusStringOperator + plusStringOperator;
		AssertString(plusString, 40, ResizedCapacity(ResizedCapacity(1, 20), 40), "plus string operatorplus string operator");
		plusString = plusStringOperator + plusStringOperator + plusStringOperator + plusStringOperator + String("");
		AssertString(plusString, 80, ResizedCapacity(ResizedCapacity(1, 20), 40), "plus string operatorplus string operatorplus string operatorplus string operator");
		plusString = plusCStringOperator + "";
		AssertString(plusString, 22, ResizedCapacity(ResizedCapacity(1, 20), 40), "plus c-string operator");
		plusString = plusCStringOperator + " c-string";
		AssertString(plusString, 31, ResizedCapacity(ResizedCapacity(1, 20), 40), "plus c-string operator c-string");
		plusString = plusCStringOperator + plusCStringOperator.CString();
		AssertString(plusString, 44, ResizedCapacity(ResizedCapacity(1, 20), 40), "plus c-string operatorplus c-string operator");
		plusString.ShrinkToFit();
		AssertString(plusString, 44, 45, "plus c-string operatorplus c-string operator");
		plusString = plusCStringOperator + plusCStringOperator.CString() + plusCStringOperator.CString() + "";
		AssertString(plusString, 66, ResizedCapacity(45, 66), "plus c-string operatorplus c-string operatorplus c-string operator");
		plusString = plusCStringOperator + (plusCStringOperator.CString() + plusCStringOperator.Size() - 8);
		AssertString(plusString, 30, ResizedCapacity(45, 66), "plus c-string operatoroperator");
		plusString = String::ToString("plus char operator") + 'c';
		AssertString(plusString, 19, ResizedCapacity(45, 66), "plus char operatorc");
		plusString = String::ToString("short min: ") + std::numeric_limits<int16_t>::min();
		AssertString(plusString, 17, ResizedCapacity(45, 66), "short min: -32768");
		plusString = String::ToString("short max: ") + std::numeric_limits<int16_t>::max();
		AssertString(plusString, 16, ResizedCapacity(45, 66), "short max: 32767");
		plusString = String::ToString("unsigned short min: ") + std::numeric_limits<uint16_t>::min();
		AssertString(plusString, 21, ResizedCapacity(45, 66), "unsigned short min: 0");
		plusString = String::ToString("unsigned short max: ") + std::numeric_limits<uint16_t>::max();
		AssertString(plusString, 25, ResizedCapacity(45, 66), "unsigned short max: 65535");
		plusString = String::ToString("integer min: ") + std::numeric_limits<int32_t>::min();
		AssertString(plusString, 24, ResizedCapacity(45, 66), "integer min: -2147483648");
		plusString = String::ToString("integer max: ") + std::numeric_limits<int32_t>::max();
		AssertString(plusString, 23, ResizedCapacity(45, 66), "integer max: 2147483647");
		plusString = String::ToString("unsigned integer min: ") + std::numeric_limits<uint32_t>::min();
		AssertString(plusString, 23, ResizedCapacity(45, 66), "unsigned integer min: 0");
		plusString = String::ToString("unsigned integer max: ") + std::numeric_limits<uint32_t>::max();
		AssertString(plusString, 32, ResizedCapacity(45, 66), "unsigned integer max: 4294967295");
		plusString = String::ToString("long long min: ") + std::numeric_limits<int64_t>::min();
		AssertString(plusString, 35, ResizedCapacity(45, 66), "long long min: -9223372036854775808");
		plusString = String::ToString("long long max: ") + std::numeric_limits<int64_t>::max();
		AssertString(plusString, 34, ResizedCapacity(45, 66), "long long max: 9223372036854775807");
		plusString = String::ToString("unsigned long long min: ") + std::numeric_limits<uint64_t>::min();
		AssertString(plusString, 25, ResizedCapacity(45, 66), "unsigned long long min: 0");
		plusString = String::ToString("unsigned long long max: ") + std::numeric_limits<uint64_t>::max();
		AssertString(plusString, 44, ResizedCapacity(45, 66), "unsigned long long max: 18446744073709551615");
		plusString = String::ToString("float min: ") + -std::numeric_limits<float>::min();
		AssertString(plusString, 23, ResizedCapacity(45, 66), "float min: -1.17549e-38");
		plusString = String::ToString("float max: ") + std::numeric_limits<float>::max();
		AssertString(plusString, 22, ResizedCapacity(45, 66), "float max: 3.40282e+38");
		plusString = String::ToString("double min: ") + -std::numeric_limits<double>::min();
		AssertString(plusString, 25, ResizedCapacity(45, 66), "double min: -2.22507e-308");
		plusString = String::ToString("double max: ") + std::numeric_limits<double>::max();
		AssertString(plusString, 24, ResizedCapacity(45, 66), "double max: 1.79769e+308");
		plusString = "";
		AssertString(plusString, 0, ResizedCapacity(45, 66), "");
		plusString.ShrinkToFit();
		AssertString(plusString, 0, 1, "");
		plusString = plusString + 1 + -1 + 1.01f + -1.01f + 1.01 + -1.01 + 'c' + false + true + "c-string" + String::ToString("string");
		AssertString(plusString, 38, ResizedCapacity(1, 38), "1-11.01-1.011.01-1.01c01c-stringstring");
	}

	void TestBitwiseLeftShiftOperators() {
		String assignmentString("");
		String plusStringAssignment(static_cast<size_t>(0));
		String plusCStringAssignment(static_cast<size_t>(0));
		String plusCharAssignment(static_cast<size_t>(0));

		AssertString(assignmentString, 0, String::s_defaultCapacity, "");
		AssertString(plusStringAssignment, 0, 1, "");
		AssertString(plusCStringAssignment, 0, 1, "");
		AssertString(plusCharAssignment, 0, 1, "");

		plusStringAssignment << assignmentString;
		AssertString(plusStringAssignment, 0, 1, "");
		assignmentString = 'c';
		AssertString(assignmentString, 1, String::s_defaultCapacity, "c");
		plusStringAssignment << assignmentString;
		AssertString(plusStringAssignment, 1, ResizedCapacity(1, 1), "c");
		plusStringAssignment << plusStringAssignment;
		AssertString(plusStringAssignment, 2, ResizedCapacity(1, 1), "cc");
		plusStringAssignment << plusStringAssignment;
		AssertString(plusStringAssignment, 4, ResizedCapacity(ResizedCapacity(1, 1), 4), "cccc");
		plusStringAssignment << plusStringAssignment << plusStringAssignment << plusStringAssignment;
		AssertString(plusStringAssignment, 32, ResizedCapacity(ResizedCapacity(ResizedCapacity(1, 1), 4), 16), "cccccccccccccccccccccccccccccccc");
		plusCStringAssignment << "";
		AssertString(plusCStringAssignment, 0, 1, "");
		plusCStringAssignment << "plus c-string assignment";
		AssertString(plusCStringAssignment, 24, ResizedCapacity(1, 24), "plus c-string assignment");
		plusCStringAssignment << "2";
		AssertString(plusCStringAssignment, 25, ResizedCapacity(1, 24), "plus c-string assignment2");
		plusCStringAssignment << plusCStringAssignment.CString();
		AssertString(plusCStringAssignment, 50, ResizedCapacity(ResizedCapacity(1, 24), 50), "plus c-string assignment2plus c-string assignment2");
		plusCStringAssignment << plusCStringAssignment.CString() + plusCStringAssignment.Size() - 5;
		plusCStringAssignment.ShrinkToFit();
		AssertString(plusCStringAssignment, 55, 56, "plus c-string assignment2plus c-string assignment2ment2");
		plusCStringAssignment << plusCStringAssignment.CString() + plusCStringAssignment.Size() - 1;
		AssertString(plusCStringAssignment, 56, ResizedCapacity(56, 56), "plus c-string assignment2plus c-string assignment2ment22");
		plusCStringAssignment << plusCStringAssignment.CString() + plusCStringAssignment.Size() - 1 << plusCStringAssignment.CString() + plusCStringAssignment.Size() - 1;
		AssertString(plusCStringAssignment, 59, ResizedCapacity(56, 56), "plus c-string assignment2plus c-string assignment2ment22222");
		plusCharAssignment << 'c';
		AssertString(plusCharAssignment, 1, ResizedCapacity(1, 1), "c");
		plusCharAssignment << 'd';
		AssertString(plusCharAssignment, 2, ResizedCapacity(1, 1), "cd");
		plusCharAssignment << 'e';
		AssertString(plusCharAssignment, 3, ResizedCapacity(ResizedCapacity(1, 1), 3), "cde");
		plusCharAssignment << 'f' << 'g' << 'h';
		AssertString(plusCharAssignment, 6, ResizedCapacity(ResizedCapacity(1, 1), 3), "cdefgh");
		plusStringAssignment << plusCharAssignment << plusCStringAssignment.CString() << 'z';
		AssertString(plusStringAssignment, 98, ResizedCapacity(ResizedCapacity(ResizedCapacity(ResizedCapacity(1, 1), 4), 16), 38), "cccccccccccccccccccccccccccccccccdefghplus c-string assignment2plus c-string assignment2ment22222z");
	}

	void TestIndexOf() {
		String indexOfString("wwww index of string wwww");

		AssertString(indexOfString, 25, 25 + String::s_defaultCapacity, "wwww index of string wwww");

		int index = indexOfString.IndexOf(String::ToString('w'));
		assert(index == 0);
		index = indexOfString.IndexOf(String::ToString("ww"));
		assert(index == 0);
		index = indexOfString.IndexOf(String::ToString("index of string w"));
		assert(index == 5);
		index = indexOfString.IndexOf(String::ToString('z'));
		assert(index == -1);
		index = indexOfString.IndexOf(String::ToString("no index"));
		assert(index == -1);
		index = indexOfString.IndexOf(String::ToString(""));
		assert(index == -1);
		index = indexOfString.IndexOf(String::ToString('w'), 0);
		assert(index == 0);
		index = indexOfString.IndexOf(String::ToString('w'), 4);
		assert(index == 21);
		index = indexOfString.IndexOf(String::ToString("ww"), 0);
		assert(index == 0);
		index = indexOfString.IndexOf(String::ToString("ww"), 4);
		assert(index == 21);
		index = indexOfString.IndexOf(String::ToString("index of string w"), 0);
		assert(index == 5);
		index = indexOfString.IndexOf(String::ToString("index of string w"), 20);
		assert(index == -1);
		index = indexOfString.IndexOf(String::ToString('z'), 0);
		assert(index == -1);
		index = indexOfString.IndexOf(String::ToString("no index"), 0);
		assert(index == -1);
		index = indexOfString.IndexOf(String::ToString(""), 0);
		assert(index == -1);
		index = indexOfString.IndexOf(String::ToString('w'), 1000);
		assert(index == -1);
		index = indexOfString.IndexOf(String::ToString('w'), 0, indexOfString.Size());
		assert(index == 0);
		index = indexOfString.IndexOf(String::ToString('w'), 4, indexOfString.Size());
		assert(index == 21);
		index = indexOfString.IndexOf(String::ToString('i'), 6, 1000);
		assert(index == 17);
		index = indexOfString.IndexOf(String::ToString("ww"), 0, indexOfString.Size());
		assert(index == 0);
		index = indexOfString.IndexOf(String::ToString("ww"), 4, indexOfString.Size());
		assert(index == 21);
		index = indexOfString.IndexOf(String::ToString("ww"), 4, 10);
		assert(index == -1);
		index = indexOfString.IndexOf(String::ToString("index of string w"), 0, indexOfString.Size());
		assert(index == 5);
		index = indexOfString.IndexOf(String::ToString("index of string w"), 20, indexOfString.Size());
		assert(index == -1);
		index = indexOfString.IndexOf(String::ToString('z'), 0, indexOfString.Size());
		assert(index == -1);
		index = indexOfString.IndexOf(String::ToString("no index"), 0, indexOfString.Size());
		assert(index == -1);
		index = indexOfString.IndexOf(String::ToString(""), 0, indexOfString.Size());
		assert(index == -1);
		index = indexOfString.IndexOf(String::ToString('w'), 1000, indexOfString.Size());
		assert(index == -1);
		index = indexOfString.IndexOf(String::ToString('w'), 2, 1);
		assert(index == -1);

		index = indexOfString.IndexOf("w");
		assert(index == 0);
		index = indexOfString.IndexOf("ww");
		assert(index == 0);
		index = indexOfString.IndexOf("index of string w");
		assert(index == 5);
		index = indexOfString.IndexOf("z");
		assert(index == -1);
		index = indexOfString.IndexOf("no index");
		assert(index == -1);
		index = indexOfString.IndexOf("");
		assert(index == -1);
		index = indexOfString.IndexOf(indexOfString.CString());
		assert(index == 0);
		index = indexOfString.IndexOf(indexOfString.CString() + indexOfString.Size() - 5);
		assert(index == 20);
		index = indexOfString.IndexOf("w", 0);
		assert(index == 0);
		index = indexOfString.IndexOf("w", 4);
		assert(index == 21);
		index = indexOfString.IndexOf("ww", 0);
		assert(index == 0);
		index = indexOfString.IndexOf("ww", 4);
		assert(index == 21);
		index = indexOfString.IndexOf("index of string w", 0);
		assert(index == 5);
		index = indexOfString.IndexOf("index of string w", 20);
		assert(index == -1);
		index = indexOfString.IndexOf("z", 0);
		assert(index == -1);
		index = indexOfString.IndexOf("no index", 0);
		assert(index == -1);
		index = indexOfString.IndexOf("", 0);
		assert(index == -1);
		index = indexOfString.IndexOf("w", 1000);
		assert(index == -1);
		index = indexOfString.IndexOf(indexOfString.CString(), 0);
		assert(index == 0);
		index = indexOfString.IndexOf(indexOfString.CString(), 5);
		assert(index == -1);
		index = indexOfString.IndexOf(indexOfString.CString() + indexOfString.Size() - 5, 0);
		assert(index == 20);
		index = indexOfString.IndexOf(indexOfString.CString() + indexOfString.Size() - 5, 21);
		assert(index == -1);
		index = indexOfString.IndexOf("w", 0, indexOfString.Size());
		assert(index == 0);
		index = indexOfString.IndexOf("w", 4, indexOfString.Size());
		assert(index == 21);
		index = indexOfString.IndexOf("i", 6, 1000);
		assert(index == 17);
		index = indexOfString.IndexOf("ww", 0, indexOfString.Size());
		assert(index == 0);
		index = indexOfString.IndexOf("ww", 4, indexOfString.Size());
		assert(index == 21);
		index = indexOfString.IndexOf("ww", 4, 10);
		assert(index == -1);
		index = indexOfString.IndexOf("index of string w", 0, indexOfString.Size());
		assert(index == 5);
		index = indexOfString.IndexOf("index of string w", 20, indexOfString.Size());
		assert(index == -1);
		index = indexOfString.IndexOf("z", 0, indexOfString.Size());
		assert(index == -1);
		index = indexOfString.IndexOf("no index", 0, indexOfString.Size());
		assert(index == -1);
		index = indexOfString.IndexOf("", 0, indexOfString.Size());
		assert(index == -1);
		index = indexOfString.IndexOf("w", 1000, indexOfString.Size());
		assert(index == -1);
		index = indexOfString.IndexOf("w", 2, 1);
		assert(index == -1);
		index = indexOfString.IndexOf(indexOfString.CString(), 0, 1000);
		assert(index == 0);
		index = indexOfString.IndexOf(indexOfString.CString(), 5, indexOfString.Size());
		assert(index == -1);
		index = indexOfString.IndexOf(indexOfString.CString(), 0, indexOfString.Size() - 10);
		assert(index == -1);
		index = indexOfString.IndexOf(indexOfString.CString() + indexOfString.Size() - 5, 0, indexOfString.Size());
		assert(index == 20);
		index = indexOfString.IndexOf(indexOfString.CString() + indexOfString.Size() - 5, 20, indexOfString.Size());
		assert(index == 20);
		index = indexOfString.IndexOf(indexOfString.CString() + indexOfString.Size() - 5, 20, indexOfString.Size() - 3);
		assert(index == -1);

		index = indexOfString.IndexOf('w');
		assert(index == 0);
		index = indexOfString.IndexOf('i');
		assert(index == 5);
		index = indexOfString.IndexOf('z');
		assert(index == -1);
		index = indexOfString.IndexOf('w', 0);
		assert(index == 0);
		index = indexOfString.IndexOf('w', 4);
		assert(index == 21);
		index = indexOfString.IndexOf('i', 0);
		assert(index == 5);
		index = indexOfString.IndexOf('i', 6);
		assert(index == 17);
		index = indexOfString.IndexOf('z', 0);
		assert(index == -1);
		index = indexOfString.IndexOf('w', 1000);
		assert(index == -1);
		index = indexOfString.IndexOf('w', 0, indexOfString.Size());
		assert(index == 0);
		index = indexOfString.IndexOf('w', 4, indexOfString.Size());
		assert(index == 21);
		index = indexOfString.IndexOf('i', 0, indexOfString.Size());
		assert(index == 5);
		index = indexOfString.IndexOf('i', 6, 1000);
		assert(index == 17);
		index = indexOfString.IndexOf('z', 0, indexOfString.Size());
		assert(index == -1);
		index = indexOfString.IndexOf('w', 1000, indexOfString.Size());
		assert(index == -1);
		index = indexOfString.IndexOf('w', 2, 1);
		assert(index == -1);
	}

	void TestLastIndexOf() {
		String lastIndexOfString("wwww last index of string wwww");

		AssertString(lastIndexOfString, 30, 30 + String::s_defaultCapacity, "wwww last index of string wwww");

		int index = lastIndexOfString.LastIndexOf(String::ToString('w'));
		assert(index == 29);
		index = lastIndexOfString.LastIndexOf(String::ToString("ww"));
		assert(index == 28);
		index = lastIndexOfString.LastIndexOf(String::ToString("index of string w"));
		assert(index == 10);
		index = lastIndexOfString.LastIndexOf(String::ToString('z'));
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf(String::ToString("no index"));
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf(String::ToString(""));
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf(String::ToString('w'), lastIndexOfString.Size());
		assert(index == 29);
		index = lastIndexOfString.LastIndexOf(String::ToString('w'), 25);
		assert(index == 3);
		index = lastIndexOfString.LastIndexOf(String::ToString("ww"), lastIndexOfString.Size());
		assert(index == 28);
		index = lastIndexOfString.LastIndexOf(String::ToString("ww"), 25);
		assert(index == 2);
		index = lastIndexOfString.LastIndexOf(String::ToString("index of string w"), lastIndexOfString.Size());
		assert(index == 10);
		index = lastIndexOfString.LastIndexOf(String::ToString("index of string w"), 15);
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf(String::ToString('z'), lastIndexOfString.Size());
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf(String::ToString("no index"), lastIndexOfString.Size());
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf(String::ToString(""), lastIndexOfString.Size());
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf(String::ToString('w'), 0);
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf(String::ToString('w'), 1000, 0);
		assert(index == 29);
		index = lastIndexOfString.LastIndexOf(String::ToString('w'), 25, 0);
		assert(index == 3);
		index = lastIndexOfString.LastIndexOf(String::ToString('i'), 20, 0);
		assert(index == 10);
		index = lastIndexOfString.LastIndexOf(String::ToString("ww"), lastIndexOfString.Size(), 0);
		assert(index == 28);
		index = lastIndexOfString.LastIndexOf(String::ToString("ww"), 25, 0);
		assert(index == 2);
		index = lastIndexOfString.LastIndexOf(String::ToString("ww"), 10, 25);
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf(String::ToString("index of string w"), lastIndexOfString.Size(), 0);
		assert(index == 10);
		index = lastIndexOfString.LastIndexOf(String::ToString("index of string w"), 15, 0);
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf(String::ToString('z'), lastIndexOfString.Size(), 0);
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf(String::ToString("no index"), lastIndexOfString.Size(), 0);
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf(String::ToString(""), lastIndexOfString.Size(), 0);
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf(String::ToString('w'), lastIndexOfString.Size(), 1000);
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf(String::ToString('w'), 1, 2);
		assert(index == -1);

		index = lastIndexOfString.LastIndexOf("w");
		assert(index == 29);
		index = lastIndexOfString.LastIndexOf("ww");
		assert(index == 28);
		index = lastIndexOfString.LastIndexOf("index of string w");
		assert(index == 10);
		index = lastIndexOfString.LastIndexOf("z");
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf("no index");
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf("");
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf(lastIndexOfString.CString());
		assert(index == 0);
		index = lastIndexOfString.LastIndexOf(lastIndexOfString.CString() + lastIndexOfString.Size() - 5);
		assert(index == 25);
		index = lastIndexOfString.LastIndexOf("w", lastIndexOfString.Size());
		assert(index == 29);
		index = lastIndexOfString.LastIndexOf("w", 25);
		assert(index == 3);
		index = lastIndexOfString.LastIndexOf("ww", lastIndexOfString.Size());
		assert(index == 28);
		index = lastIndexOfString.LastIndexOf("ww", 25);
		assert(index == 2);
		index = lastIndexOfString.LastIndexOf("index of string w", lastIndexOfString.Size());
		assert(index == 10);
		index = lastIndexOfString.LastIndexOf("index of string w", 15);
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf("z", lastIndexOfString.Size());
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf("no index", lastIndexOfString.Size());
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf("", lastIndexOfString.Size());
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf("w", 0);
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf(lastIndexOfString.CString(), lastIndexOfString.Size());
		assert(index == 0);
		index = lastIndexOfString.LastIndexOf(lastIndexOfString.CString(), lastIndexOfString.Size() - 5);
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf(lastIndexOfString.CString() + lastIndexOfString.Size() - 5, lastIndexOfString.Size());
		assert(index == 25);
		index = lastIndexOfString.LastIndexOf(lastIndexOfString.CString() + lastIndexOfString.Size() - 5, lastIndexOfString.Size() - 5);
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf("w", 1000, 0);
		assert(index == 29);
		index = lastIndexOfString.LastIndexOf("w", 25, 0);
		assert(index == 3);
		index = lastIndexOfString.LastIndexOf("i", 20, 0);
		assert(index == 10);
		index = lastIndexOfString.LastIndexOf("ww", lastIndexOfString.Size(), 0);
		assert(index == 28);
		index = lastIndexOfString.LastIndexOf("ww", 25, 0);
		assert(index == 2);
		index = lastIndexOfString.LastIndexOf("ww", 10, 25);
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf("index of string w", lastIndexOfString.Size(), 0);
		assert(index == 10);
		index = lastIndexOfString.LastIndexOf("index of string w", 15, 0);
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf("z", lastIndexOfString.Size(), 0);
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf("no index", lastIndexOfString.Size(), 0);
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf("", lastIndexOfString.Size(), 0);
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf("w", lastIndexOfString.Size(), 1000);
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf("w", 1, 2);
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf(lastIndexOfString.CString(), lastIndexOfString.Size(), 0);
		assert(index == 0);
		index = lastIndexOfString.LastIndexOf(lastIndexOfString.CString(), lastIndexOfString.Size(), 5);
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf(lastIndexOfString.CString(), lastIndexOfString.Size() - 5, 0);
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf(lastIndexOfString.CString() + lastIndexOfString.Size() - 5, lastIndexOfString.Size(), 0);
		assert(index == 25);
		index = lastIndexOfString.LastIndexOf(lastIndexOfString.CString() + lastIndexOfString.Size() - 5, lastIndexOfString.Size(), 25);
		assert(index == 25);
		index = lastIndexOfString.LastIndexOf(lastIndexOfString.CString() + lastIndexOfString.Size() - 5, lastIndexOfString.Size() - 5, 0);
		assert(index == -1);

		index = lastIndexOfString.LastIndexOf('w');
		assert(index == 29);
		index = lastIndexOfString.LastIndexOf('i');
		assert(index == 22);
		index = lastIndexOfString.LastIndexOf('z');
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf('w', lastIndexOfString.Size());
		assert(index == 29);
		index = lastIndexOfString.LastIndexOf('w', 25);
		assert(index == 3);
		index = lastIndexOfString.LastIndexOf('i', 1000);
		assert(index == 22);
		index = lastIndexOfString.LastIndexOf('i', 20);
		assert(index == 10);
		index = lastIndexOfString.LastIndexOf('z', lastIndexOfString.Size());
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf('w', 0);
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf('w', 1000, 0);
		assert(index == 29);
		index = lastIndexOfString.LastIndexOf('w', 25, 0);
		assert(index == 3);
		index = lastIndexOfString.LastIndexOf('i', lastIndexOfString.Size(), 0);
		assert(index == 22);
		index = lastIndexOfString.LastIndexOf('i', 20, 0);
		assert(index == 10);
		index = lastIndexOfString.LastIndexOf('i', 20, 15);
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf('z', lastIndexOfString.Size(), 0);
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf('w', lastIndexOfString.Size(), 1000);
		assert(index == -1);
		index = lastIndexOfString.LastIndexOf('w', 1, 2);
		assert(index == -1);
	}

	void TestContains() {
		String containsString("wwww contains string wwww");

		AssertString(containsString, 25, 25 + String::s_defaultCapacity, "wwww contains string wwww");

		assert(containsString.Contains(String::ToString('w')));
		assert(!containsString.Contains(String::ToString('z')));
		assert(containsString.Contains(String::ToString("wwww")));
		assert(!containsString.Contains(String::ToString("wwwww")));
		assert(containsString.Contains(String::ToString("contains string")));
		assert(!containsString.Contains(String::ToString("this string is way too long to contain itself!")));
		assert(containsString.Contains(containsString));
		assert(containsString.Contains("w"));
		assert(!containsString.Contains("z"));
		assert(containsString.Contains("wwww"));
		assert(!containsString.Contains("wwwww"));
		assert(containsString.Contains("contains string"));
		assert(!containsString.Contains("this string is way too long to contain itself!"));
		assert(containsString.Contains(containsString.CString()));
		assert(containsString.Contains(containsString.CString() + containsString.Size() - 10));
		assert(containsString.Contains('w'));
		assert(!containsString.Contains('W'));
	}

	void TestSubstring() {
		String substring("1. string number one2. string number two");

		AssertString(substring, 40, 40 + String::s_defaultCapacity, "1. string number one2. string number two");

		AssertString(substring.Substring(20), 20, 20 + String::s_defaultCapacity, "2. string number two");
		AssertString(substring.Substring(substring.Size()), 0, String::s_defaultCapacity, "");
		AssertString(substring.Substring(substring.Size() + 10), 0, String::s_defaultCapacity, "");		
		AssertString(substring.Substring(20, substring.Size()), 20, 20 + String::s_defaultCapacity, "2. string number two");
		AssertString(substring.Substring(20, substring.Size() + 10), 20, 20 + String::s_defaultCapacity, "2. string number two");
		AssertString(substring.Substring(20, 10), 0, String::s_defaultCapacity, "");
		AssertString(substring.Substring(substring.Size(), substring.Size()), 0, String::s_defaultCapacity, "");
		AssertString(substring.Substring(substring.Size(), substring.Size() + 10), 0, String::s_defaultCapacity, "");
		AssertString(substring.Substring(substring.Size(), 10), 0, String::s_defaultCapacity, "");
		AssertString(substring.Substring(substring.Size() + 10, substring.Size()), 0, String::s_defaultCapacity, "");
		AssertString(substring.Substring(substring.Size() + 10, substring.Size() + 10), 0, String::s_defaultCapacity, "");
	}

	void TestToUpperLower() {
		String toUpper("To Upper");
		String toLower("To Lower");

		AssertString(toUpper, 8, 8 + String::s_defaultCapacity, "To Upper");
		AssertString(toLower, 8, 8 + String::s_defaultCapacity, "To Lower");
		
		toUpper.ToUpper();
		AssertString(toUpper, 8, 8 + String::s_defaultCapacity, "TO UPPER");
		toUpper.ToLower();
		AssertString(toUpper, 8, 8 + String::s_defaultCapacity, "to upper");
		toLower.ToLower();
		AssertString(toLower, 8, 8 + String::s_defaultCapacity, "to lower");
		toLower.ToUpper();
		AssertString(toLower, 8, 8 + String::s_defaultCapacity, "TO LOWER");
	}

	void TestConcatenate() {
		String concatString("concat string");
		String concatCString("concat c-string");
		String concatCharacter("concat character");
		String otherPart("; other part");
		String empty(static_cast<size_t>(0));
		String mergeString;

		AssertString(concatString, 13, 13 + String::s_defaultCapacity, "concat string");
		AssertString(concatCString, 15, 15 + String::s_defaultCapacity, "concat c-string");
		AssertString(concatCharacter, 16, 16 + String::s_defaultCapacity, "concat character");
		AssertString(otherPart, 12, 12 + String::s_defaultCapacity, "; other part");
		AssertString(empty, 0, 1, "");
		AssertString(mergeString, 0, String::s_defaultCapacity, "");

		mergeString = String::Merge(concatString, otherPart);
		AssertString(mergeString, 25, String::s_defaultCapacity, "concat string; other part");
		mergeString = String::Merge(concatString, empty);
		AssertString(mergeString, 13, String::s_defaultCapacity, "concat string");
		mergeString = String::Merge(empty, otherPart);
		AssertString(mergeString, 12, String::s_defaultCapacity, "; other part");
		mergeString = String::Merge(empty, empty);
		AssertString(mergeString, 0, String::s_defaultCapacity, "");
		mergeString = String::Merge(concatString, concatString);
		AssertString(mergeString, 26, String::s_defaultCapacity, "concat stringconcat string");

		mergeString = String::Merge(concatString, "; other part");
		AssertString(mergeString, 25, String::s_defaultCapacity, "concat string; other part");
		mergeString = String::Merge(concatString, "");
		AssertString(mergeString, 13, String::s_defaultCapacity, "concat string");
		mergeString = String::Merge(empty, "; other part");
		AssertString(mergeString, 12, String::s_defaultCapacity, "; other part");
		mergeString = String::Merge(empty, "");
		AssertString(mergeString, 0, String::s_defaultCapacity, "");
		mergeString = String::Merge(concatString, concatString.CString());
		AssertString(mergeString, 26, String::s_defaultCapacity, "concat stringconcat string");
		mergeString = String::Merge(concatString, concatString.CString() + concatString.Size() - 7);
		AssertString(mergeString, 20, String::s_defaultCapacity, "concat string string");

		mergeString = String::Merge("; other part", concatString);
		AssertString(mergeString, 25, String::s_defaultCapacity, "; other partconcat string");
		mergeString = String::Merge("", concatString);
		AssertString(mergeString, 13, String::s_defaultCapacity, "concat string");
		mergeString = String::Merge("; other part", empty);
		AssertString(mergeString, 12, String::s_defaultCapacity, "; other part");
		mergeString = String::Merge("", empty);
		AssertString(mergeString, 0, String::s_defaultCapacity, "");
		mergeString = String::Merge(concatString.CString(), concatString);
		AssertString(mergeString, 26, String::s_defaultCapacity, "concat stringconcat string");
		mergeString = String::Merge(concatString.CString() + concatString.Size() - 7, concatString);
		AssertString(mergeString, 20, String::s_defaultCapacity, " stringconcat string");

		mergeString = String::Merge(concatString, 'c');
		AssertString(mergeString, 14, String::s_defaultCapacity, "concat stringc");
		mergeString = String::Merge(concatString, concatString[4]);
		AssertString(mergeString, 14, String::s_defaultCapacity, "concat stringa");
		mergeString = String::Merge(empty, 'c');
		AssertString(mergeString, 1, String::s_defaultCapacity, "c");
		mergeString = String::Merge(empty, empty[0]);
		AssertString(mergeString, 1, String::s_defaultCapacity, "");

		mergeString = String::Merge('c', concatString);
		AssertString(mergeString, 14, String::s_defaultCapacity, "cconcat string");
		mergeString = String::Merge(concatString[4], concatString);
		AssertString(mergeString, 14, String::s_defaultCapacity, "aconcat string");
		mergeString = String::Merge('c', empty);
		AssertString(mergeString, 1, String::s_defaultCapacity, "c");
		mergeString = String::Merge(empty[0], empty);
		AssertString(mergeString, 1, String::s_defaultCapacity, "");

		concatString.Concatenate(otherPart);
		AssertString(concatString, 25, 13 + String::s_defaultCapacity, "concat string; other part");
		concatString.Concatenate(empty);
		AssertString(concatString, 25, 13 + String::s_defaultCapacity, "concat string; other part");
		concatString.Concatenate(concatString);
		AssertString(concatString, 50, 13 + String::s_defaultCapacity, "concat string; other partconcat string; other part");
		concatString.ShrinkToFit();
		AssertString(concatString, 50, 51, "concat string; other partconcat string; other part");
		concatString.Concatenate(concatString);
		AssertString(concatString, 100, ResizedCapacity(51, 100), "concat string; other partconcat string; other partconcat string; other partconcat string; other part");

		concatCString.Concatenate("; other part");
		AssertString(concatCString, 27, 15 + String::s_defaultCapacity, "concat c-string; other part");
		concatCString.Concatenate("");
		AssertString(concatCString, 27, 15 + String::s_defaultCapacity, "concat c-string; other part");
		concatCString.Concatenate(concatCString.CString());
		AssertString(concatCString, 54, 15 + String::s_defaultCapacity, "concat c-string; other partconcat c-string; other part");
		concatCString.Concatenate(concatCString.CString() + concatCString.Size() - 5);
		AssertString(concatCString, 59, 15 + String::s_defaultCapacity, "concat c-string; other partconcat c-string; other part part");
		concatCString.ShrinkToFit();
		AssertString(concatCString, 59, 60, "concat c-string; other partconcat c-string; other part part");
		concatCString.Concatenate(concatCString.CString() + concatCString.Size() - 5);
		AssertString(concatCString, 64, ResizedCapacity(60, 64), "concat c-string; other partconcat c-string; other part part part");

		concatCharacter.Concatenate('c');
		AssertString(concatCharacter, 17, 16 + String::s_defaultCapacity, "concat characterc");
		concatCharacter.Concatenate(concatCharacter[4]);
		AssertString(concatCharacter, 18, 16 + String::s_defaultCapacity, "concat characterca");
		concatCharacter.ShrinkToFit();
		AssertString(concatCharacter, 18, 19, "concat characterca");
		concatCharacter.Concatenate(concatCharacter[5]);
		AssertString(concatCharacter, 19, ResizedCapacity(19, 19), "concat charactercat");

		concatCString = String("concat c-string");
		AssertString(concatCString, 15, ResizedCapacity(60, 64), "concat c-string");
		concatCString.ConcatenateAfter("; other part");
		AssertString(concatCString, 27, ResizedCapacity(60, 64), "; other partconcat c-string");
		concatCString.ConcatenateAfter("");
		AssertString(concatCString, 27, ResizedCapacity(60, 64), "; other partconcat c-string");
		concatCString.ConcatenateAfter(concatCString.CString());
		AssertString(concatCString, 54, ResizedCapacity(60, 64), "; other partconcat c-string; other partconcat c-string");
		concatCString.ConcatenateAfter(concatCString.CString() + concatCString.Size() - 8);
		AssertString(concatCString, 62, ResizedCapacity(60, 64), "c-string; other partconcat c-string; other partconcat c-string");
		concatCString.ShrinkToFit();
		AssertString(concatCString, 62, 63, "c-string; other partconcat c-string; other partconcat c-string");
		concatCString.ConcatenateAfter(concatCString.CString() + concatCString.Size() - 8);
		AssertString(concatCString, 70, ResizedCapacity(63, 70), "c-stringc-string; other partconcat c-string; other partconcat c-string");

		concatCharacter = String("concat character");
		AssertString(concatCharacter, 16, ResizedCapacity(19, 19), "concat character");
		concatCharacter.ConcatenateAfter('c');
		AssertString(concatCharacter, 17, ResizedCapacity(19, 19), "cconcat character");
		concatCharacter.ConcatenateAfter(concatCharacter[5]);
		AssertString(concatCharacter, 18, ResizedCapacity(19, 19), "acconcat character");
		concatCharacter.ShrinkToFit();
		AssertString(concatCharacter, 18, 19, "acconcat character");
		concatCharacter.ConcatenateAfter(concatCharacter[7]);
		AssertString(concatCharacter, 19, ResizedCapacity(19, 19), "tacconcat character");
	}

	void TestCount() {
		String countString("...this string has stuff to be counted...");

		AssertString(countString, 41, 41 + String::s_defaultCapacity, "...this string has stuff to be counted...");

		int count = countString.Count(String::ToString("s s"));
		assert(count == 2);
		count = countString.Count(String::ToString("stuff"));
		assert(count == 1);
		count = countString.Count(String::ToString(""));
		assert(count == 0);
		count = countString.Count(String::ToString('.'));
		assert(count == 6);
		count = countString.Count(countString);
		assert(count == 1);
		count = countString.Count(String::ToString("s s"), 0);
		assert(count == 2);
		count = countString.Count(String::ToString("s s"), 9);
		assert(count == 1);
		count = countString.Count(String::ToString("stuff"), 0);
		assert(count == 1);
		count = countString.Count(String::ToString("stuff"), 35);
		assert(count == 0);
		count = countString.Count(String::ToString(""), 0);
		assert(count == 0);
		count = countString.Count(String::ToString(""), 20);
		assert(count == 0);
		count = countString.Count(String::ToString('.'), 0);
		assert(count == 6);
		count = countString.Count(String::ToString('.'), 3);
		assert(count == 3);
		count = countString.Count(String::ToString('.'), 9999);
		assert(count == 0);
		count = countString.Count(countString, 0);
		assert(count == 1);
		count = countString.Count(countString, 1);
		assert(count == 0);
		count = countString.Count(String::ToString("s s"), 0, countString.Size());
		assert(count == 2);
		count = countString.Count(String::ToString("s s"), 9, countString.Size());
		assert(count == 1);
		count = countString.Count(String::ToString("s s"), 9, 8);
		assert(count == 0);
		count = countString.Count(String::ToString("stuff"), 0, countString.Size());
		assert(count == 1);
		count = countString.Count(String::ToString("stuff"), 35, 9999);
		assert(count == 0);
		count = countString.Count(String::ToString("stuff"), 0, 10);
		assert(count == 0);
		count = countString.Count(String::ToString(""), 0, countString.Size());
		assert(count == 0);
		count = countString.Count(String::ToString(""), 20, countString.Size());
		assert(count == 0);
		count = countString.Count(String::ToString('.'), 0, countString.Size());
		assert(count == 6);
		count = countString.Count(String::ToString('.'), 3, countString.Size());
		assert(count == 3);
		count = countString.Count(String::ToString('.'), 3, countString.Size() - 3);
		assert(count == 0);
		count = countString.Count(String::ToString('.'), 9999, 10000);
		assert(count == 0);
		count = countString.Count(countString, 0, countString.Size());
		assert(count == 1);
		count = countString.Count(countString, 1, countString.Size());
		assert(count == 0);
		count = countString.Count(countString, 0, countString.Size() - 1);
		assert(count == 0);

		count = countString.Count("s s");
		assert(count == 2);
		count = countString.Count("stuff");
		assert(count == 1);
		count = countString.Count("");
		assert(count == 0);
		count = countString.Count(".");
		assert(count == 6);
		count = countString.Count(countString.CString());
		assert(count == 1);
		count = countString.Count(countString.CString() + countString.Size() - 2);
		assert(count == 4);
		count = countString.Count("s s", 0);
		assert(count == 2);
		count = countString.Count("s s", 9);
		assert(count == 1);
		count = countString.Count("stuff", 0);
		assert(count == 1);
		count = countString.Count("stuff", 35);
		assert(count == 0);
		count = countString.Count("", 0);
		assert(count == 0);
		count = countString.Count("", 20);
		assert(count == 0);
		count = countString.Count(".", 0);
		assert(count == 6);
		count = countString.Count(".", 3);
		assert(count == 3);
		count = countString.Count(".", 9999);
		assert(count == 0);
		count = countString.Count(countString.CString(), 0);
		assert(count == 1);
		count = countString.Count(countString.CString(), 1);
		assert(count == 0);
		count = countString.Count(countString.CString() + countString.Size() - 2, 0);
		assert(count == 4);
		count = countString.Count(countString.CString() + countString.Size() - 2, 3);
		assert(count == 2);
		count = countString.Count("s s", 0, countString.Size());
		assert(count == 2);
		count = countString.Count("s s", 9, countString.Size());
		assert(count == 1);
		count = countString.Count("s s", 9, 8);
		assert(count == 0);
		count = countString.Count("stuff", 0, countString.Size());
		assert(count == 1);
		count = countString.Count("stuff", 35, 9999);
		assert(count == 0);
		count = countString.Count("stuff", 0, 10);
		assert(count == 0);
		count = countString.Count("", 0, countString.Size());
		assert(count == 0);
		count = countString.Count("", 20, countString.Size());
		assert(count == 0);
		count = countString.Count(".", 0, countString.Size());
		assert(count == 6);
		count = countString.Count(".", 3, countString.Size());
		assert(count == 3);
		count = countString.Count(".", 3, countString.Size() - 3);
		assert(count == 0);
		count = countString.Count(".", 9999, 10000);
		assert(count == 0);
		count = countString.Count(countString.CString(), 0, countString.Size());
		assert(count == 1);
		count = countString.Count(countString.CString(), 1, countString.Size());
		assert(count == 0);
		count = countString.Count(countString.CString(), 0, countString.Size() - 1);
		assert(count == 0);
		count = countString.Count(countString.CString() + countString.Size() - 2, 0, countString.Size());
		assert(count == 4);
		count = countString.Count(countString.CString() + countString.Size() - 2, 3, countString.Size());
		assert(count == 2);
		count = countString.Count(countString.CString() + countString.Size() - 2, 3, countString.Size() - 3);
		assert(count == 0);

		count = countString.Count('.');
		assert(count == 6);
		count = countString.Count('g');
		assert(count == 1);
		count = countString.Count('z');
		assert(count == 0);
		count = countString.Count('.', 0);
		assert(count == 6);
		count = countString.Count('.', 3);
		assert(count == 3);
		count = countString.Count('g', 0);
		assert(count == 1);
		count = countString.Count('g', 9999);
		assert(count == 0);
		count = countString.Count('z', 0);
		assert(count == 0);
		count = countString.Count('z', 20);
		assert(count == 0);
		count = countString.Count('.', 0, countString.Size());
		assert(count == 6);
		count = countString.Count('.', 3, countString.Size());
		assert(count == 3);
		count = countString.Count('.', 3, countString.Size() - 3);
		assert(count == 0);
		count = countString.Count('g', 0, countString.Size());
		assert(count == 1);
		count = countString.Count('g', 9999, countString.Size());
		assert(count == 0);
		count = countString.Count('g', 9999, 10000);
		assert(count == 0);
		count = countString.Count('g', 30, 29);
		assert(count == 0);
		count = countString.Count('g', 0, 5);
		assert(count == 0);
		count = countString.Count('z', 0, countString.Size());
		assert(count == 0);
		count = countString.Count('z', 20, countString.Size());
		assert(count == 0);
	}

	void TestInsert() {
		String insertString("will be");
		String insertCString("will be");
		String insertCharacter("will be");
		
		AssertString(insertString, 7, 7 + String::s_defaultCapacity, "will be");
		AssertString(insertCString, 7, 7 + String::s_defaultCapacity, "will be");
		AssertString(insertCharacter, 7, 7 + String::s_defaultCapacity, "will be");

		insertString.Insert(0, String::ToString("... i "));
		AssertString(insertString, 13, 7 + String::s_defaultCapacity, "... i will be");
		insertString.Insert(insertString.Size(), String::ToString(" inserted with other strings"));
		AssertString(insertString, 41, 7 + String::s_defaultCapacity, "... i will be inserted with other strings");
		insertString.Insert(33, String::ToString(" great"));
		AssertString(insertString, 47, 7 + String::s_defaultCapacity, "... i will be inserted with other great strings");
		insertString.Insert(0, String::ToString(""));
		AssertString(insertString, 47, 7 + String::s_defaultCapacity, "... i will be inserted with other great strings");
		insertString.Insert(insertString.Size(), String::ToString(""));
		AssertString(insertString, 47, 7 + String::s_defaultCapacity, "... i will be inserted with other great strings");
		insertString.Insert(33, String::ToString(""));
		AssertString(insertString, 47, 7 + String::s_defaultCapacity, "... i will be inserted with other great strings");
		insertString.ShrinkToFit();
		AssertString(insertString, 47, 48, "... i will be inserted with other great strings");
		insertString.Insert(0, insertString);
		AssertString(insertString, 94, ResizedCapacity(48, 94), "... i will be inserted with other great strings... i will be inserted with other great strings");
		insertString.Insert(insertString.Size(), insertString);
		AssertString(insertString, 188, ResizedCapacity(48, 94), "... i will be inserted with other great strings... i will be inserted with other great strings... i will be inserted with other great strings... i will be inserted with other great strings");
		insertString.Insert(33, insertString);
		AssertString(insertString, 376, ResizedCapacity(ResizedCapacity(48, 94), 376), "... i will be inserted with other... i will be inserted with other great strings... i will be inserted with other great strings... i will be inserted with other great strings... i will be inserted with other great strings great strings... i will be inserted with other great strings... i will be inserted with other great strings... i will be inserted with other great strings");
		insertString = String("... i will be inserted with other great strings");
		insertString.ShrinkToFit();
		AssertString(insertString, 47, 48, "... i will be inserted with other great strings");
		insertString.Insert(9999, String::ToString("index too high"));
		AssertString(insertString, 47, 48, "... i will be inserted with other great strings");

		insertCString.Insert(0, "... i ");
		AssertString(insertCString, 13, 7 + String::s_defaultCapacity, "... i will be");
		insertCString.Insert(insertCString.Size(), " inserted with other strings");
		AssertString(insertCString, 41, 7 + String::s_defaultCapacity, "... i will be inserted with other strings");
		insertCString.Insert(33, " great");
		AssertString(insertCString, 47, 7 + String::s_defaultCapacity, "... i will be inserted with other great strings");
		insertCString.Insert(0, "");
		AssertString(insertCString, 47, 7 + String::s_defaultCapacity, "... i will be inserted with other great strings");
		insertCString.Insert(insertCString.Size(), "");
		AssertString(insertCString, 47, 7 + String::s_defaultCapacity, "... i will be inserted with other great strings");
		insertCString.Insert(33, "");
		AssertString(insertCString, 47, 7 + String::s_defaultCapacity, "... i will be inserted with other great strings");
		insertCString.ShrinkToFit();
		AssertString(insertCString, 47, 48, "... i will be inserted with other great strings");
		insertCString.Insert(0, insertCString.CString());
		AssertString(insertCString, 94, ResizedCapacity(48, 94), "... i will be inserted with other great strings... i will be inserted with other great strings");
		insertCString.Insert(insertCString.Size(), insertCString.CString());
		AssertString(insertCString, 188, ResizedCapacity(48, 94), "... i will be inserted with other great strings... i will be inserted with other great strings... i will be inserted with other great strings... i will be inserted with other great strings");
		insertCString.Insert(33, insertCString.CString());
		AssertString(insertCString, 376, ResizedCapacity(ResizedCapacity(48, 94), 376), "... i will be inserted with other... i will be inserted with other great strings... i will be inserted with other great strings... i will be inserted with other great strings... i will be inserted with other great strings great strings... i will be inserted with other great strings... i will be inserted with other great strings... i will be inserted with other great strings");
		insertCString = String("... i will be inserted with other great strings");
		insertCString.ShrinkToFit();
		AssertString(insertCString, 47, 48, "... i will be inserted with other great strings");
		insertCString.Insert(9999, "index too high");
		AssertString(insertCString, 47, 48, "... i will be inserted with other great strings");
		insertCString.Insert(33, insertCString.CString() + insertCString.Size() - 8);
		AssertString(insertCString, 55, ResizedCapacity(48, 55), "... i will be inserted with other strings great strings");
		insertCString.Insert(33, insertCString.CString() + insertCString.Size() - 8);
		AssertString(insertCString, 63, ResizedCapacity(48, 55), "... i will be inserted with other strings strings great strings");

		insertCharacter.Insert(0, 'i');
		AssertString(insertCharacter, 8, 7 + String::s_defaultCapacity, "iwill be");
		insertCharacter.Insert(insertCharacter.Size(), ' ');
		AssertString(insertCharacter, 9, 7 + String::s_defaultCapacity, "iwill be ");
		insertCharacter.Insert(1, ' ');
		AssertString(insertCharacter, 10, 7 + String::s_defaultCapacity, "i will be ");
		insertCharacter.Insert(9999, 'x');
		AssertString(insertCharacter, 10, 7 + String::s_defaultCapacity, "i will be ");
		insertCharacter.ShrinkToFit();
		AssertString(insertCharacter, 10, 11, "i will be ");
		insertCharacter.Insert(insertCharacter.Size(), 'x');
		AssertString(insertCharacter, 11, ResizedCapacity(11, 11), "i will be x");
	}
	
	void TestRemove() { }
	void TestRemoveAll() { }
	void TestReplace() { }
	void TestReplaceAt() { }
	void TestTrim() { }
	void TestPadLeft() { }
	void TestPadRight() { }
	void TestStartswith() { }
	void TestEndsWith() { }
	void TestFill() { }

	void TestSplitAt() {
		String stringToBeSplit("I am a string that will be cut into two pieces.");
		String leftPart(static_cast<size_t>(0));
		String rightPart(static_cast<size_t>(0));

		AssertString(stringToBeSplit, 47, 47 + String::s_defaultCapacity, "I am a string that will be cut into two pieces.");
		AssertString(leftPart, 0, 1, "");
		AssertString(rightPart, 0, 1, "");

		stringToBeSplit.SplitAt(0, leftPart, rightPart);
		AssertString(leftPart, 0, 1, "");
		AssertString(rightPart, 47, 49, "I am a string that will be cut into two pieces.");
		stringToBeSplit.SplitAt(33, leftPart, rightPart);
		AssertString(leftPart, 33, 35, "I am a string that will be cut in");
		AssertString(rightPart, 14, 49, "to two pieces.");
		stringToBeSplit.SplitAt(60, leftPart, rightPart);
		AssertString(leftPart, 33, 35, "I am a string that will be cut in");
		AssertString(rightPart, 14, 49, "to two pieces.");

		String::SplitStringAt(stringToBeSplit, 0, leftPart, rightPart);
		AssertString(leftPart, 0, 35, "");
		AssertString(rightPart, 47, 49, "I am a string that will be cut into two pieces.");
		String::SplitStringAt(stringToBeSplit, 33, leftPart, rightPart);
		AssertString(leftPart, 33, 35, "I am a string that will be cut in");
		AssertString(rightPart, 14, 49, "to two pieces.");
		String::SplitStringAt(stringToBeSplit, 60, leftPart, rightPart);
		AssertString(leftPart, 33, 35, "I am a string that will be cut in");
		AssertString(rightPart, 14, 49, "to two pieces.");
	}

	void TestJoin() { }

	void RunUnitTests() {
		TestComparisonOperators();
		TestConstructors();
		TestShrinkToFit();
		TestAssignmentOperators();
		TestToString();
		TestCompoundAssignmentOperators();
		TestAdditionOperators();
		TestBitwiseLeftShiftOperators();
		TestIndexOf();
		TestLastIndexOf();
		TestContains();
		TestSubstring();
		TestToUpperLower();
		TestConcatenate();
		TestCount();
		TestInsert();
		TestRemove();
		TestRemoveAll();
		TestReplace();
		TestReplaceAt();
		TestTrim();
		TestPadLeft();
		TestPadRight();
		TestStartswith();
		TestEndsWith();
		TestFill();
		TestSplitAt();
		TestJoin();
	}
}
