#include <assert.h>
#include <intrin.h>
#include <string>

#include "UnitTests.h"


uint64_t CalcAverageTSC(uint64_t* data, uint32_t count) {
	uint64_t averageTime = 0;
	for (uint32_t i = 0; i < count; ++i) averageTime += data[i];
	averageTime /= count;
	return averageTime;
}

int main() {
	Power::RunUnitTests();

	{
		Power::String string = "asd";
		Power::AssertString(string, 3);
		char buffer[5] = "asdf";
		string = Power::String(buffer, static_cast<size_t>(4));
		Power::AssertString(string, 4);
		string = Power::String("asdasd", static_cast<size_t>(6));
		Power::AssertString(string, 6);
		string = buffer;
		Power::AssertString(string, 4);
		string = "asdfghjk";
		Power::AssertString(string, 8);
		Power::String otherString = Power::String("asdfg", static_cast<size_t>(5));
		Power::AssertString(otherString, 5);
		string = otherString;
		Power::AssertString(string, 5);
		Power::String thirdWheelString = otherString;
		Power::AssertString(thirdWheelString, 5);
		char c = 'e';
		string = c;
		Power::AssertString(string, 1);

		printf("String: %s; OtherString: %s; ThirdWheelString: %s|\n", string.CString(), otherString.CString(), thirdWheelString.CString());

		string = otherString + thirdWheelString;
		Power::AssertString(string, 10);
		assert(string == string.CString());

		printf("String: %s|\n", static_cast<const char*>(string));

		string += string;
		otherString = string;
		Power::AssertString(string, 20);
		assert(string == string.CString());
		assert(string == otherString);
		assert(string != thirdWheelString.CString());
		assert(string != thirdWheelString);

		printf("String: %s|\n", string.CString());

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
		assert(string.Size() == 0);

		string = "Hallo";
		string.PadLeft(10, '0');
		assert(string.Size() == 10);
		printf("String: %s|\n", string.CString());
		string.PadLeft(5);
		assert(string.Size() == 10);
		string.PadRight(15, '0');
		assert(string.Size() == 15);
		printf("String: %s|\n", string.CString());
		string.PadRight(5);
		assert(string.Size() == 15);

		string.Insert(10, " Welt");
		assert(string.Size() == 20);
		printf("String: %s|\n", string.CString());

		string.Remove(string.IndexOf(" Welt"), 5);
		assert(string.Size() == 15);
		printf("String: %s|\n", string.CString());

		string.RemoveAll('0');
		assert(string.Size() == 5);
		printf("String: %s|\n", string.CString());

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

		printf("String: %s|\n", string.CString());
		printf("Average cycles taken: %lld\n", CalcAverageTSC(deltaTimes, measureCount));

		Power::String newString = Power::String(static_cast<size_t>(0));
		Power::AssertString(newString, 0, 1);
		newString = 'c';
		Power::AssertString(newString, 1, 3);
		newString += "cc";
		Power::AssertString(newString, 3, 9);
		newString += "cccccc";
		Power::AssertString(newString, 9, 27);
		newString += "cccccccccccccccccc";
		Power::AssertString(newString, 27, 81);
		newString += "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
		Power::AssertString(newString, 153, 315);

		string = "";
//		string += Power::String::ToString(1) + '_' + 1.01f + '_' + 1.01 + '_' + true + '_' + false;
		string += 1;
		string += '_';
		string += 1.01f;
		string += '_';
		string += 1.01;
		string += '_';
		string += true;
		string += '_';
		string += false;

		printf("String: %s|\n", string.CString());

		string = "HalloArschArschHalloArschHupeHalloHupeArsch";
		printf("String: %s|\n", string.CString());
		string.RemoveAll("Arsch");
		printf("String: %s|\n", string.CString());
		string.RemoveAll("Hallo");
		printf("String: %s|\n", string.CString());
		string.RemoveAll("Hupe");
		printf("String: %s|\n", string.CString());

		string = "aklsjdhflkasjdhflkajsdhflkajsdhflkajsdhflkajsdhflkajsdhflkajshdfz";
		for (int i = 0; i < measureCount; ++i) {
			uint64_t startCount = __rdtsc();
			pos = string.IndexOf('z');
			uint64_t endCount = __rdtsc();
			deltaTimes[i] = endCount - startCount;
		}

		printf("Average cycles taken: %lld\n", CalcAverageTSC(deltaTimes, measureCount));

		string = "Halt Die Backen";
		otherString = "Fresse";
		printf("String: %s|\n", string.CString());
		string.Replace(string.LastIndexOf("Backen"), otherString);
		Power::AssertString(string, 15);
		printf("String: %s|\n", string.CString());
		string.Replace(string.LastIndexOf(otherString), "Eier");
		Power::AssertString(string, 13);
		printf("String: %s|\n", string.CString());
		string.Replace(string.IndexOf("Eier"), 'c');
		Power::AssertString(string, 10);
		printf("String: %s|\n", string.CString());

		string.Insert(string.Size(), " -> Nein!");
		Power::AssertString(string, 19);
		printf("String: %s|\n", string.CString());
		
		otherString = "Halt";
		assert(string.StartsWith(otherString));
		assert(string.StartsWith("Halt"));
		assert(string.StartsWith('H'));
		otherString = "Nein!";
		assert(string.EndsWith(otherString));
		assert(string.EndsWith("Nein!"));
		assert(string.EndsWith('!'));

		for (int i = 0; i < measureCount; ++i) {
			uint64_t startCount = __rdtsc();
			std::string stdString = "asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdf";
//			stdString.shrink_to_fit();
			uint64_t endCount = __rdtsc();
			deltaTimes[i] = endCount - startCount;
		}

		printf("STD average cycles taken: %lld\n", CalcAverageTSC(deltaTimes, measureCount));

		for (int i = 0; i < measureCount; ++i) {
			uint64_t startCount = __rdtsc();
			Power::String powerString = "asdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdfasdf";
//			powerString.ShrinkToFit();
			uint64_t endCount = __rdtsc();
			deltaTimes[i] = endCount - startCount;
//			Power::AssertString(powerString, 8);
		}

		printf("POWER average cycles taken: %lld\n", CalcAverageTSC(deltaTimes, measureCount));

		for (int i = 0; i < measureCount; ++i) {
			uint64_t startCount = __rdtsc();
			Power::String powerString = Power::String::ToString(static_cast<uint16_t>(5));
			uint64_t endCount = __rdtsc();
			deltaTimes[i] = endCount - startCount;
		}

		printf("Average cycles taken: %lld\n", CalcAverageTSC(deltaTimes, measureCount));

		string = Power::String::ToString(std::numeric_limits<int16_t>::min());
		printf("String: %s|\n", string.CString());

		string = "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM";
		otherString = "ASDF";
		string.Fill(otherString, 8, 16);
		printf("String: %s|\n", string.CString());

		Power::String strings[10] = { "String1", "String2", "String3", "String4", "String5", "String6", "String7", "String8", "String9", "String10" };

		Power::String joinedString = Power::String::Join(otherString, strings, 10);
		printf("String: %s|\n", joinedString.CString());
		Power::AssertString(joinedString, 107, 363);
		char* cStrings[3] = { "Eins", "Zwei", "Drei" };
		joinedString = Power::String::Join("___", cStrings, 3);
		printf("String: %s|\n", joinedString.CString());
		Power::AssertString(joinedString, 18, 363);

		Power::String::SplitStringAt(string, 15, otherString, thirdWheelString);
		printf("String: %s|\n", otherString.CString());
		printf("String: %s|\n", thirdWheelString.CString());

		joinedString.ToUpper();
		printf("String: %s|\n", joinedString.CString());
		joinedString.ToLower();
		printf("String: %s|\n", joinedString.CString());

		for (int i = 0; i < measureCount; ++i) {
			uint64_t startCount = __rdtsc();
			Power::String powerString = Power::String::Join(' ', strings, 10);
			uint64_t endCount = __rdtsc();
			deltaTimes[i] = endCount - startCount;
		}
		printf("Join average cycles taken: %lld\n", CalcAverageTSC(deltaTimes, measureCount));

		for (int i = 0; i < measureCount; ++i) {
			uint64_t startCount = __rdtsc();
			Power::String powerString = strings[0] + strings[1] + strings[2] + strings[3] + strings[4] + strings[5] + strings[6] + strings[7] + strings[8] + strings[9];
			uint64_t endCount = __rdtsc();
			deltaTimes[i] = endCount - startCount;
		}
		printf("Plus average cycles taken: %lld\n", CalcAverageTSC(deltaTimes, measureCount));
		
		for (int i = 0; i < measureCount; ++i) {
			uint64_t startCount = __rdtsc();
			Power::String powerString = "";
			powerString.Concatenate(strings[0]);
			powerString.Concatenate(strings[1]);
			powerString.Concatenate(strings[2]);
			powerString.Concatenate(strings[3]);
			powerString.Concatenate(strings[4]);
			powerString.Concatenate(strings[5]);
			powerString.Concatenate(strings[6]);
			powerString.Concatenate(strings[7]);
			powerString.Concatenate(strings[8]);
			powerString.Concatenate(strings[9]);
			uint64_t endCount = __rdtsc();
			deltaTimes[i] = endCount - startCount;
		}
		printf("Concatenate average cycles taken: %lld\n", CalcAverageTSC(deltaTimes, measureCount));

		string = "            arsch             ";
		printf("String: %s|\n", string.CString());
		string.TrimEnd();
		printf("String: %s|\n", string.CString());
		string.Trim();
		printf("String: %s|\n", string.CString());

		string = "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwueoiuiwtuezasdf";

		for (int i = 0; i < measureCount; ++i) {
			uint64_t startCount = __rdtsc();
			string.Contains("wueoiuiwtuezasdf", 16);
			uint64_t endCount = __rdtsc();
			deltaTimes[i] = endCount - startCount;
		}
		printf("Concatenate average cycles taken: %lld\n", CalcAverageTSC(deltaTimes, measureCount));

		size_t count = string.Count('w', 0 , string.Size());
		printf("Count: %zd\n", count);

		string = "doodle_";
		string << "die_" << "doodle";
		printf("String: %s|\n", string.CString());

		for (int i = 0; i < measureCount; ++i) {
			uint64_t startCount = __rdtsc();
			int index = string.LastIndexOf('w');
			uint64_t endCount = __rdtsc();
			deltaTimes[i] = endCount - startCount;
		}
		printf("LastIndexOf strrchr average cycles taken: %lld\n", CalcAverageTSC(deltaTimes, measureCount));

		for (int i = 0; i < measureCount; ++i) {
			uint64_t startCount = __rdtsc();
			int index = string.LastIndexOf('w', string.Size(), 0);
			uint64_t endCount = __rdtsc();
			deltaTimes[i] = endCount - startCount;
		}
		printf("LastIndexOf for-loop average cycles taken: %lld\n", CalcAverageTSC(deltaTimes, measureCount));

		Power::String fileString = Power::String::LoadFileIntoString("test.txt");

		printf("Size: %zd\n", fileString.Capacity());
		printf("Count of f: %d\n", fileString.Count('f'));
		{
			uint64_t startCount = __rdtsc();
			fileString.ToUpper();
			fileString.ToLower();
			fileString.Fill("I am a new string ");
			fileString.ToUpper();
			uint64_t endCount = __rdtsc();
			printf("Large string operation average cycles taken: %lld\n", endCount - startCount);
		}
	}

	printf("Total instances created: %zd; Remaining instances: %zd\n", Power::String::s_totalInstancesCreated_, Power::String::s_instanceCounter_);
	assert(Power::String::s_instanceCounter_ == 0);

	getchar();
	return 0;
}
