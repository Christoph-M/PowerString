#pragma once

#include "PowerString.h"


namespace Power {
	void AssertString(const String& string, size_t length, size_t size = 0, const char* const data = nullptr) {
		if (size > 0) assert(string.Size() == size);
		assert(string.Length() == length);
		assert(string.CString()[string.Length()] == '\0');
		if (data) assert(string == data);
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
		AssertString(copyConstructor, cStringConstructor.Length(), cStringConstructor.Size(), "c-string constructor");
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
		AssertString(cstringAssignment, 19, 16 * 2 + 19, "c-string assignment");
		cstringAssignment = cstringAssignment.CString();
		AssertString(cstringAssignment, 19, 16 * 2 + 19, "c-string assignment");
		stringAssignment = cstringAssignment;
		AssertString(stringAssignment, 19, 13 * 2 + 19, "c-string assignment");
		stringAssignment = stringAssignment;
		AssertString(stringAssignment, 19, 13 * 2 + 19, "c-string assignment");
		cstringAssignment = cstringAssignment.CString() + cstringAssignment.Length() - 10;
		AssertString(cstringAssignment, 10, 16 * 2 + 19, "assignment");
		cstringAssignment = "";
		AssertString(cstringAssignment, 0, 16 * 2 + 19, "");
		stringAssignment = charAssignment;
		AssertString(stringAssignment, 0, 13 * 2 + 19, "");
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

	void TestPlusAssignmentOperators() {
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
		AssertString(plusStringAssignment, 1, 1 * 2 + 1, "c");
		plusStringAssignment += plusStringAssignment;
		AssertString(plusStringAssignment, 2, 1 * 2 + 1, "cc");
		plusStringAssignment += plusStringAssignment;
		AssertString(plusStringAssignment, 4, 3 * 2 + 4, "cccc");
		plusCStringAssignment += "";
		AssertString(plusCStringAssignment, 0, 1, "");
		plusCStringAssignment += "plus c-string assignment";
		AssertString(plusCStringAssignment, 24, 1 * 2 + 24, "plus c-string assignment");
		plusCStringAssignment += "2";
		AssertString(plusCStringAssignment, 25, 1 * 2 + 24, "plus c-string assignment2");
		plusCStringAssignment += plusCStringAssignment.CString();
		AssertString(plusCStringAssignment, 50, 26 * 2 + 50, "plus c-string assignment2plus c-string assignment2");
		plusCStringAssignment += plusCStringAssignment.CString() + plusCStringAssignment.Length() - 5;
		plusCStringAssignment.ShrinkToFit();
		AssertString(plusCStringAssignment, 55, 56, "plus c-string assignment2plus c-string assignment2ment2");
		plusCStringAssignment += plusCStringAssignment.CString() + plusCStringAssignment.Length() - 1;
		AssertString(plusCStringAssignment, 56, 56 * 2 + 56, "plus c-string assignment2plus c-string assignment2ment22");
		plusCharAssignment += 'c';
		AssertString(plusCharAssignment, 1, 1 * 2 + 1, "c");
		plusCharAssignment += 'd';
		AssertString(plusCharAssignment, 2, 1 * 2 + 1, "cd");
		plusCharAssignment += 'e';
		AssertString(plusCharAssignment, 3, 3 * 2 + 3, "cde");
		plusShortAssignment += static_cast<int16_t>(0);
		AssertString(plusShortAssignment, 1, 1 * 2 + 1, "0");
		plusShortAssignment += std::numeric_limits<int16_t>::min();
		AssertString(plusShortAssignment, 7, 3 * 2 + 7, "0-32768");
		plusShortAssignment += std::numeric_limits<int16_t>::max();
		AssertString(plusShortAssignment, 12, 3 * 2 + 7, "0-3276832767");
		plusUnsignedShortAssignment += std::numeric_limits<uint16_t>::min();
		AssertString(plusUnsignedShortAssignment, 1, 1 * 2 + 1, "0");
		plusUnsignedShortAssignment += std::numeric_limits<uint16_t>::max();
		AssertString(plusUnsignedShortAssignment, 6, 3 * 2 + 6, "065535");
		plusIntegerAssignment += static_cast<int32_t>(0);
		AssertString(plusIntegerAssignment, 1, 1 * 2 + 1, "0");
		plusIntegerAssignment += std::numeric_limits<int32_t>::min();
		AssertString(plusIntegerAssignment, 12, 3 * 2 + 12, "0-2147483648");
		plusIntegerAssignment += std::numeric_limits<int32_t>::max();
		AssertString(plusIntegerAssignment, 22, 18 * 2 + 22, "0-21474836482147483647");
		plusUnsignedIntegerAssignment += std::numeric_limits<uint32_t>::min();
		AssertString(plusUnsignedIntegerAssignment, 1, 1 * 2 + 1, "0");
		plusUnsignedIntegerAssignment += std::numeric_limits<uint32_t>::max();
		AssertString(plusUnsignedIntegerAssignment, 11, 3 * 2 + 11, "04294967295");
		plusLongLongAssignment += static_cast<int64_t>(0);
		AssertString(plusLongLongAssignment, 1, 1 * 2 + 1, "0");
		plusLongLongAssignment += std::numeric_limits<int64_t>::min();
		AssertString(plusLongLongAssignment, 21, 3 * 2 + 21, "0-9223372036854775808");
		plusLongLongAssignment += std::numeric_limits<int64_t>::max();
		AssertString(plusLongLongAssignment, 40, 27 * 2 + 40, "0-92233720368547758089223372036854775807");
		plusUnsignedLongLongAssignment += std::numeric_limits<uint64_t>::min();
		AssertString(plusUnsignedLongLongAssignment, 1, 1 * 2 + 1, "0");
		plusUnsignedLongLongAssignment += std::numeric_limits<uint64_t>::max();
		AssertString(plusUnsignedLongLongAssignment, 21, 3 * 2 + 21, "018446744073709551615");
		plusFloatAssignment += 0.0f;
		AssertString(plusFloatAssignment, 1, 1 * 2 + 1, "0");
		plusFloatAssignment += -std::numeric_limits<float>::min();
		AssertString(plusFloatAssignment, 13, 3 * 2 + 13, "0-1.17549e-38");
		plusFloatAssignment += std::numeric_limits<float>::max();
		AssertString(plusFloatAssignment, 24, 19 * 2 + 24, "0-1.17549e-383.40282e+38");
		plusDoubleAssignment += 0.0;
		AssertString(plusDoubleAssignment, 1, 1 * 2 + 1, "0");
		plusDoubleAssignment += -std::numeric_limits<double>::min();
		AssertString(plusDoubleAssignment, 14, 3 * 2 + 14, "0-2.22507e-308");
		plusDoubleAssignment += std::numeric_limits<double>::max();
		AssertString(plusDoubleAssignment, 26, 20 * 2 + 26, "0-2.22507e-3081.79769e+308");
	}

	void TestPlusOperator() {
		String plusString(static_cast<size_t>(0));
		String plusStringOperator("plus string operator");
		String plusCStringOperator("plus c-string operator");

		AssertString(plusString, 0, 1, "");
		AssertString(plusStringOperator, 20, 20 + String::s_defaultCapacity, "plus string operator");
		AssertString(plusCStringOperator, 22, 22 + String::s_defaultCapacity, "plus c-string operator");

		plusString = plusStringOperator + plusString;
		AssertString(plusString, 20, 1 * 2 + 20, "plus string operator");
		plusString = plusStringOperator + plusStringOperator;
		AssertString(plusString, 40, 22 * 2 + 40, "plus string operatorplus string operator");
		plusString = plusStringOperator + plusStringOperator + plusStringOperator + plusStringOperator + String("");
		AssertString(plusString, 80, 22 * 2 + 40, "plus string operatorplus string operatorplus string operatorplus string operator");
		plusString = plusCStringOperator + "";
		AssertString(plusString, 22, 22 * 2 + 40, "plus c-string operator");
		plusString = plusCStringOperator + " c-string";
		AssertString(plusString, 31, 22 * 2 + 40, "plus c-string operator c-string");
		plusString = plusCStringOperator + plusCStringOperator.CString();
		AssertString(plusString, 44, 22 * 2 + 40, "plus c-string operatorplus c-string operator");
		plusString.ShrinkToFit();
		plusString = plusCStringOperator + plusCStringOperator.CString() + plusCStringOperator.CString() + "";
		AssertString(plusString, 66, 45 * 2 + 66, "plus c-string operatorplus c-string operatorplus c-string operator");
		plusString = plusCStringOperator + (plusCStringOperator.CString() + plusCStringOperator.Length() - 8);
		AssertString(plusString, 30, 45 * 2 + 66, "plus c-string operatoroperator");
		plusString = String::ToString("plus char operator") + 'c';
		AssertString(plusString, 19, 45 * 2 + 66, "plus char operatorc");
		plusString = String::ToString("short min: ") + std::numeric_limits<int16_t>::min();
		AssertString(plusString, 17, 45 * 2 + 66, "short min: -32768");
		plusString = String::ToString("short max: ") + std::numeric_limits<int16_t>::max();
		AssertString(plusString, 16, 45 * 2 + 66, "short max: 32767");
		plusString = String::ToString("unsigned short min: ") + std::numeric_limits<uint16_t>::min();
		AssertString(plusString, 21, 45 * 2 + 66, "unsigned short min: 0");
		plusString = String::ToString("unsigned short max: ") + std::numeric_limits<uint16_t>::max();
		AssertString(plusString, 25, 45 * 2 + 66, "unsigned short max: 65535");
		plusString = String::ToString("integer min: ") + std::numeric_limits<int32_t>::min();
		AssertString(plusString, 24, 45 * 2 + 66, "integer min: -2147483648");
		plusString = String::ToString("integer max: ") + std::numeric_limits<int32_t>::max();
		AssertString(plusString, 23, 45 * 2 + 66, "integer max: 2147483647");
		plusString = String::ToString("unsigned integer min: ") + std::numeric_limits<uint32_t>::min();
		AssertString(plusString, 23, 45 * 2 + 66, "unsigned integer min: 0");
		plusString = String::ToString("unsigned integer max: ") + std::numeric_limits<uint32_t>::max();
		AssertString(plusString, 32, 45 * 2 + 66, "unsigned integer max: 4294967295");
		plusString = String::ToString("long long min: ") + std::numeric_limits<int64_t>::min();
		AssertString(plusString, 35, 45 * 2 + 66, "long long min: -9223372036854775808");
		plusString = String::ToString("long long max: ") + std::numeric_limits<int64_t>::max();
		AssertString(plusString, 34, 45 * 2 + 66, "long long max: 9223372036854775807");
		plusString = String::ToString("unsigned long long min: ") + std::numeric_limits<uint64_t>::min();
		AssertString(plusString, 25, 45 * 2 + 66, "unsigned long long min: 0");
		plusString = String::ToString("unsigned long long max: ") + std::numeric_limits<uint64_t>::max();
		AssertString(plusString, 44, 45 * 2 + 66, "unsigned long long max: 18446744073709551615");
		plusString = String::ToString("float min: ") + -std::numeric_limits<float>::min();
		AssertString(plusString, 23, 45 * 2 + 66, "float min: -1.17549e-38");
		plusString = String::ToString("float max: ") + std::numeric_limits<float>::max();
		AssertString(plusString, 22, 45 * 2 + 66, "float max: 3.40282e+38");
		plusString = String::ToString("double min: ") + -std::numeric_limits<double>::min();
		AssertString(plusString, 25, 45 * 2 + 66, "double min: -2.22507e-308");
		plusString = String::ToString("double max: ") + std::numeric_limits<double>::max();
		AssertString(plusString, 24, 45 * 2 + 66, "double max: 1.79769e+308");
		plusString = "";
		plusString.ShrinkToFit();
		AssertString(plusString, 0, 1, "");
		plusString = plusString + 1 + -1 + 1.01f + -1.01f + 1.01 + -1.01 + 'c' + false + true + "c-string" + String::ToString("string");
		AssertString(plusString, 38, 1 * 2 + 38, "1-11.01-1.011.01-1.01c01c-stringstring");
	}

	void RunUnitTests() {
		TestCompareOperators();
		TestConstructors();
		TestShrinkToFit();
		TestAssignmentOperators();
		TestToString();
		TestPlusAssignmentOperators();
		TestPlusOperator();
	}
}
