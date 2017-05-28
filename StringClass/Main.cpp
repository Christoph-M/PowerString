#include <assert.h>
#include <stdint.h>
#include <intrin.h>

#include "PowerString.h"


void AssertString(Power::String& string, size_t length, size_t size = 0) {
	if (size > 0) assert(string.Size() == size);
	assert(string.Length() == length);
	assert(string.CString()[string.Length()] == '\0');
}

int main() {
	{
		Power::String string = "asd";
		AssertString(string, 3);
		char buffer[5] = "asdf";
		string = Power::String(buffer, 4);
		AssertString(string, 4);
		string = Power::String("asdasd", 6);
		AssertString(string, 6);
		string = buffer;
		AssertString(string, 4);
		string = "asdfghjk";
		AssertString(string, 8);
		Power::String otherString = Power::String("asdfg", 5);
		AssertString(otherString, 5);
		string = otherString;
		AssertString(string, 5);
		Power::String thirdWheelString = otherString;
		AssertString(thirdWheelString, 5);
		char c = 'e';
		string = c;
		AssertString(string, 1);

		printf("String: %s; OtherString: %s; ThirdWheelString: %s\n", string.CString(), otherString.CString(), thirdWheelString.CString());

		string = otherString + thirdWheelString;
		AssertString(string, 10);
		assert(string == string.CString());

		printf("String: %s\n", string.CString());

		string += string;
		otherString = string;
		AssertString(string, 20);
		assert(string == string.CString());
		assert(string == otherString);
		assert(string != thirdWheelString.CString());
		assert(string != thirdWheelString);

		printf("String: %s\n", string.CString());

		string = "s";
		assert(string == "s");
		assert(string != "p");

		string = "Hallo World World!";
		otherString = "World";
		thirdWheelString = "Something else";

		int pos = string.IndexOf(otherString);
		assert(pos == 6);
		pos = otherString.IndexOf(thirdWheelString);
		assert(pos == -1);
		pos = string.IndexOf('o');
		assert(pos == 4);

		pos = string.IndexOf(otherString.CString());
		assert(pos == 6);
		pos = string.IndexOf("World!a");
		assert(pos == -1);
		pos = otherString.IndexOf(thirdWheelString.CString());
		assert(pos == -1);
		pos = string.IndexOf("o");
		assert(pos == 4);

		pos = string.LastIndexOf(otherString);
		assert(pos == 12);
		pos = otherString.LastIndexOf(thirdWheelString);
		assert(pos == -1);
		pos = string.LastIndexOf('o');
		assert(pos == 13);

		pos = string.LastIndexOf(otherString.CString());
		assert(pos == 12);
		pos = string.LastIndexOf("aHallo");
		assert(pos == -1);
		pos = otherString.LastIndexOf(thirdWheelString.CString());
		assert(pos == -1);
		pos = string.LastIndexOf("o");
		assert(pos == 13);

		string = "";
		assert(string.Length() == 0);

		string = "Hallo";
		string.PadLeft(10, '0');
		assert(string.Length() == 10);
		printf("String: %s\n", string.CString());
		string.PadLeft(5);
		assert(string.Length() == 10);
		string.PadRight(15, '0');
		assert(string.Length() == 15);
		printf("String: %s\n", string.CString());
		string.PadRight(5);
		assert(string.Length() == 15);

		string.Insert(10, " Welt");
		assert(string.Length() == 20);
		printf("String: %s\n", string.CString());

		string.Remove(string.IndexOf(" Welt"), 5);
		assert(string.Length() == 15);
		printf("String: %s\n", string.CString());

		string.RemoveAll('0');
		assert(string.Length() == 5);
		printf("String: %s\n", string.CString());

		Power::String insertString = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
		const uint32_t measureCount = 10000;
		uint64_t deltaTimes[measureCount] = { 0 };
		for (int i = 0; i < measureCount; ++i) {
			uint64_t startCount = __rdtsc();
			string.Insert(0, insertString);
			string.RemoveAll("0000000000");
			uint64_t endCount = __rdtsc();
			deltaTimes[i] = endCount - startCount;
		}

		uint64_t averageTime = 0;
		for (int i = 0; i < measureCount; ++i) averageTime += deltaTimes[i];
		averageTime /= measureCount;

		printf("String: %s\n", string.CString());
		printf("Average cycles taken: %lld\n", averageTime);

		Power::String newString = Power::String(static_cast<size_t>(0));
		AssertString(newString, 0, 1);
		newString = 'c';
		AssertString(newString, 1, 3);
		newString += "cc";
		AssertString(newString, 3, 9);
		newString += "cccccc";
		AssertString(newString, 9, 27);
		newString += "cccccccccccccccccc";
		AssertString(newString, 27, 81);
		newString += "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
		AssertString(newString, 153, 315);

		string = "";
		string += 1;
		string += '_';
		string += 1.01f;
		string += '_';
		string += 1.01;
		string += '_';
		string += true;
		string += '_';
		string += false;

		printf("String: %s\n", string.CString());

		string = "HalloArschArschHalloArschHupeHalloHupeArsch";
		printf("String: %s\n", string.CString());
		string.RemoveAll("Arsch");
		printf("String: %s\n", string.CString());
		string.RemoveAll("Hallo");
		printf("String: %s\n", string.CString());
		string.RemoveAll("Hupe");
		printf("String: %s\n", string.CString());

		string = "aklsjdhflkasjdhflkajsdhflkajsdhflkajsdhflkajsdhflkajsdhflkajshdfz";
		for (int i = 0; i < measureCount; ++i) {
			uint64_t startCount = __rdtsc();
			pos = string.IndexOf('z');
			uint64_t endCount = __rdtsc();
			deltaTimes[i] = endCount - startCount;
		}

		averageTime = 0;
		for (int i = 0; i < measureCount; ++i) averageTime += deltaTimes[i];
		averageTime /= measureCount;
		printf("Average cycles taken: %lld\n", averageTime);

		string = "Halt Die Backen";
		otherString = "Fresse";
		printf("String: %s\n", string.CString());
		string.Replace(string.IndexOf("Backen"), otherString);
		AssertString(string, 15);
		printf("String: %s\n", string.CString());
		string.Replace(string.IndexOf(otherString), "Eier");
		AssertString(string, 13);
		printf("String: %s\n", string.CString());
		string.Replace(string.IndexOf("Eier"), 'c');
		AssertString(string, 10);
		printf("String: %s\n", string.CString());

		string.Insert(string.Length(), " -> Nein!");
		AssertString(string, 19);
		printf("String: %s\n", string.CString());
		
		otherString = "Halt";
		assert(string.StartsWith(otherString));
		assert(string.StartsWith("Halt"));
		assert(string.StartsWith('H'));
		otherString = "Nein!";
		assert(string.EndsWith(otherString));
		assert(string.EndsWith("Nein!"));
		assert(string.EndsWith('!'));
	}

	printf("Total instances created: %d; Remaining instances: %d\n", Power::String::s_totalInstancesCreated_, Power::String::s_instanceCounter_);
	assert(Power::String::s_instanceCounter_ == 0);

	getchar();
	return 0;
}
