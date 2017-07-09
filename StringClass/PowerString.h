#pragma once

#include <cstring>
#include <cstdio>
#include <inttypes.h>
#include <cstdlib>


#define INT16_MAX_CHR_COUNT		 7		///< Maximum character count of a signed short including the null character.
#define UINT16_MAX_CHR_COUNT	 6		///< Maximum character count of an unsigned short including the null character.
#define INT32_MAX_CHR_COUNT		12		///< Maximum character count of a signed integer including the null character.
#define UINT32_MAX_CHR_COUNT	11		///< Maximum character count of an unsigned initeger including the null character.
#define INT64_MAX_CHR_COUNT		21		///< Maximum character count of a signed long long including the null character.
#define UINT64_MAX_CHR_COUNT	21		///< Maximum character count of an unsigned long long including the null character.
#define FLOAT_MAX_CHR_COUNT		13		///< Maximum character count of a float including the null character.
#define DOUBLE_MAX_CHR_COUNT	18		///< Maximum character count of a double including the null character.


namespace Power {
	/// @brief A mutable string class with similar functionality to the C# string.
	/// @brief This string is capable of storing SIZE_MAX / 2 characters, but operation is only guaranteed up to INT32_MAX characters.
	///
	class String {
	public:
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--ToString-->
		/// @brief Converts a c-string to a Power::String.
		/// @param[in] other The c-string to be converted.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use ToString(const char) instead.
		/// @return A Power::String with the content of other.
		/// @note <b>If the size of the c-string is already known, it is recommended to use ToString(const char* const, size_t) instead as it is faster.</b>
		///
		static String ToString(const char* const other) { return String(other); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Converts a c-string to a Power::String.
		/// @param[in] other The c-string to be converted.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use ToString(const char) instead.
		/// @param[in] size The size of the c-string excluding the null character.
		/// @return A Power::String with the content of other.
		///
		static String ToString(const char* const other, size_t size) { return String(other, size); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Converts a character to a Power::String
		/// @param[in] c The character to be converted.
		/// @return A Power::String with the single character c.
		///
		static String ToString(const char c) { return String(c); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Converts a signed short value to a Power::String.
		/// @param[in] value The signed short value to be converted.
		/// @return A Power::String containing the signed short value.
		///
		static String ToString(const int16_t value) {
			char buffer[INT16_MAX_CHR_COUNT];
			snprintf(buffer, INT16_MAX_CHR_COUNT, "%hd", value);
			return String(buffer);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Converts an unsigned short value to a Power::String.
		/// @param[in] value The unsigned short value to be converted.
		/// @return A Power::String containing the unsigned short value.
		///
		static String ToString(const uint16_t value) {
			char buffer[UINT16_MAX_CHR_COUNT];
			snprintf(buffer, UINT16_MAX_CHR_COUNT, "%hu", value);
			return String(buffer);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Converts a signed integer value to a Power::String.
		/// @param[in] value The signed integer value to be converted.
		/// @return A Power::String containing the signed integer value.
		///
		static String ToString(const int32_t value) {
			char buffer[INT32_MAX_CHR_COUNT];
			snprintf(buffer, INT32_MAX_CHR_COUNT, "%d", value);
			return String(buffer);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Converts an unsigned integer value to a Power::String.
		/// @param[in] value The unsigned integer value to be converted.
		/// @return A Power::String containing the unsigned integer value.
		///
		static String ToString(const uint32_t value) {
			char buffer[UINT32_MAX_CHR_COUNT];
			snprintf(buffer, UINT32_MAX_CHR_COUNT, "%u", value);
			return String(buffer, strlen(buffer));
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Converts a signed long long value to a Power::String.
		/// @param[in] value The signed long long value to be converted.
		/// @return A Power::String containing the signed long long value.
		///
		static String ToString(const int64_t value) {
			char buffer[INT64_MAX_CHR_COUNT];
			snprintf(buffer, INT64_MAX_CHR_COUNT, "%lld", value);
			return String(buffer);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Converts an unsigned long long value to a Power::String.
		/// @param[in] value The unsigned long long value to be converted.
		/// @return A Power::String containing the unsigned long long value.
		///
		static String ToString(const uint64_t value) {
			char buffer[UINT64_MAX_CHR_COUNT];
			snprintf(buffer, UINT64_MAX_CHR_COUNT, "%llu", value);
			return String(buffer);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Converts a float value to a Power::String.
		/// @param[in] value The float value to be converted.
		/// @return A Power::String containing the float value.
		///
		static String ToString(const float value) {
			char buffer[FLOAT_MAX_CHR_COUNT];
			snprintf(buffer, FLOAT_MAX_CHR_COUNT, "%g", value);
			return String(buffer);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Converts a double value to a Power::String.
		/// @param[in] value The double value to be converted.
		/// @return A Power::String containing the double value.
		///
		static String ToString(const double value) {
			char buffer[DOUBLE_MAX_CHR_COUNT];
			snprintf(buffer, DOUBLE_MAX_CHR_COUNT, "%g", value);
			return String(buffer);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Merge-->
		/// @brief Merges two Power::Strings into one.
		/// @param[in] lhs Left-hand side of the merged Power::String.
		/// @param[in] rhs Right-hand side of the merged Power::String.
		/// @return A Power::String containing lhs+rhs.
		///
		inline static String Merge(const String& lhs, const String& rhs) { return String(lhs, rhs); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges a Power::String with a c-string.
		/// @param[in] lhs Left-hand side of the merged Power::String.
		/// @param[in] rhs Right-Hand side of the merged Power::String.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Merge(const String&, const char) instead.
		/// @return A Power::String containing lhs+rhs.
		///
		inline static String Merge(const String& lhs, const char* const rhs) { return String(lhs, rhs); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges a c-string with a Power::String.
		/// @param[in] lhs Left-hand side of the merged Power::String.
		/// @param[in] rhs Right-Hand side of the merged Power::String.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Merge(const char, const String&) instead.
		/// @return A Power::String containing lhs+rhs.
		///
		inline static String Merge(const char* const lhs, const String& rhs) { return String(lhs, rhs); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges a Power::String with a character.
		/// @param[in] lhs Left-hand side of the merged Power::String.
		/// @param[in] rhs Right-hand side of the merged Power::String.
		/// @return A Power::String containing lhs+rhs.
		///
		inline static String Merge(const String& lhs, const char rhs) { return String(lhs, rhs); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges a character with a Power::String.
		/// @param[in] lhs Left-hand side of the merged Power::String.
		/// @param[in] rhs Right-hand side of the merged Power::String.
		/// @return A Power::String containing lhs+rhs.
		///
		inline static String Merge(const char lhs, const String& rhs) { return String(lhs, rhs); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Join-->
		/// @brief Merges multiple Power::Strings with the specified seperator between each Power::String.
		/// @param[in] space The seperator which will be placed between each Power::String.
		/// @param[in] others A pointer to an array of Power::Strings to be merged.
		/// @param[in] size The size of the specified Power::String array.
		/// @return A Power::String containing the merged Power::Strings.
		///
		inline static String Join(const String& space, const String* const others, size_t size) {
			size_t totalSize = (size - 1) * space.size_;
			for (size_t i = 0; i < size; ++i) totalSize += others[i].size_;
			String newString = String("", totalSize);
			memcpy(newString.data_, others[0].data_, others[0].size_);
			char* data = newString.data_ + others[0].size_ + space.size_;
			for (size_t i = 1; i < size; ++i) {
				memcpy(data, others[i].data_, others[i].size_);
				memcpy(data - space.size_, space.data_, space.size_);
				data += others[i].size_ + space.size_;
			}
			return newString;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges multiple Power::Strings with the specified seperator between each Power::String.
		/// @param[in] space The seperator which will be placed between each Power::String.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Join(const char, const String* const, size_t) instead.
		/// @param[in] others A pointer to an array of Power::Strings to be merged.
		/// @param[in] size The size of the specified Power::String array.
		/// @return A Power::String containing the merged Power::Strings.
		/// @note <b>If the size of the c-string parameter space is already known, it is recommended to use Join(const char* const, size_t, const String* const, size_t) instead as it is faster</b>
		///
		inline static String Join(const char* const space, const String* const others, size_t size) { return String::Join(space, strlen(space), others, size); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges multiple Power::Strings with the specified seperator between each Power::String.
		/// @param[in] space The seperator which will be placed between each Power::String.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Join(const char, const String* const, size_t) instead.
		/// @param[in] spaceSize The size of the c-string parameter space excluding the null character.
		/// @param[in] others A pointer to an array of Power::Strings to be merged.
		/// @param[in] size The size of the specified Power::String array.
		/// @return A Power::String containing the merged Power::Strings.
		///
		inline static String Join(const char* const space, size_t spaceSize, const String* const others, size_t size) {
			size_t totalSize = (size - 1) * spaceSize;
			for (size_t i = 0; i < size; ++i) totalSize += others[i].size_;
			String newString = String("", totalSize);
			memcpy(newString.data_, others[0].data_, others[0].size_);
			char* data = newString.data_ + others[0].size_ + spaceSize;
			for (size_t i = 1; i < size; ++i) {
				memcpy(data, others[i].data_, others[i].size_);
				memcpy(data - spaceSize, space, spaceSize);
				data += others[i].size_ + spaceSize;
			}
			return newString;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges multiple Power::Strings with the specified seperator between each Power::String.
		/// @param[in] c The seperator which will be placed between each Power::String.
		/// @param[in] others A pointer to an array of Power::Strings to be merged.
		/// @param[in] size The size of the specified Power::String array.
		/// @return A Power::String containing the merged Power::Strings.
		///
		inline static String Join(const char c, const String* const others, size_t size) {
			size_t totalSize = size - 1;
			for (size_t i = 0; i < size; ++i) totalSize += others[i].size_;
			String newString = String(c, totalSize);
			char* data = newString.data_;
			for (size_t i = 0; i < size; ++i) {
				memcpy(data, others[i].data_, others[i].size_);
				data += others[i].size_ + 1;
			}
			return newString;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges multiple c-strings with the specified seperator between each Power::String.
		/// @param[in] space The seperator which will be placed between each c-strings.
		/// @param[in] others A pointer to an array of c-string to be merged.
		/// @param[in] size The size of the specified c-string array.
		/// @return A Power::String containing the merged c-strings.
		///
		inline static String Join(const String& space, const char* const* const others, size_t size) {
			size_t totalSize = (size - 1) * space.size_;
			for (size_t i = 0; i < size; ++i) totalSize += strlen(others[i]);
			String newString = String("", totalSize);
			size_t otherSize = strlen(others[0]);
			memcpy(newString.data_, others[0], otherSize);
			char* data = newString.data_ + otherSize + space.size_;
			for (size_t i = 1; i < size; ++i) {
				otherSize = strlen(others[i]);
				memcpy(data, others[i], otherSize);
				memcpy(data - space.size_, space.data_, space.size_);
				data += otherSize + space.size_;
			}
			return newString;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges multiple c-strings with the specified seperator between each Power::String.
		/// @param[in] space The seperator which will be placed between each c-strings.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Join(const char, const char* const* const, size_t) instead.
		/// @param[in] others A pointer to an array of c-string to be merged.
		/// @param[in] size The size of the specified c-string array.
		/// @return A Power::String containing the merged c-strings.
		/// @note <b>If the size of the c-string parameter space is already known, it is recommended to use Join(const char* const, size_t, const char* const* const, size_t) instead as it is faster</b>
		///
		inline static String Join(const char* const space, const char* const* const others, size_t size) { return String::Join(space, strlen(space), others, size); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges multiple c-strings with the specified seperator between each Power::String.
		/// @param[in] space The seperator which will be placed between each c-strings.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Join(const char, const char* const* const, size_t) instead.
		/// @param[in] spaceSize The size of the c-string parameter space excluding the null character.
		/// @param[in] others A pointer to an array of c-string to be merged.
		/// @param[in] size The size of the specified c-string array.
		/// @return A Power::String containing the merged c-strings.
		///
		inline static String Join(const char* const space, size_t spaceSize, const char* const* const others, size_t size) {
			size_t totalSize = (size - 1) * spaceSize;
			for (size_t i = 0; i < size; ++i) totalSize += strlen(others[i]);
			String newString = String("", totalSize);
			size_t otherSize = strlen(others[0]);
			memcpy(newString.data_, others[0], otherSize);
			char* data = newString.data_ + otherSize + spaceSize;
			for (size_t i = 1; i < size; ++i) {
				otherSize = strlen(others[i]);
				memcpy(data, others[i], otherSize);
				memcpy(data - spaceSize, space, spaceSize);
				data += otherSize + spaceSize;
			}
			return newString;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges multiple c-strings with the specified seperator between each Power::String.
		/// @param[in] c The seperator which will be placed between each c-strings.
		/// @param[in] others A pointer to an array of c-string to be merged.
		/// @param[in] size The size of the specified c-string array.
		/// @return A Power::String containing the merged c-strings.
		///
		inline static String Join(const char c, const char* const* const others, size_t size) {
			size_t totalSize = size - 1;
			for (size_t i = 0; i < size; ++i) totalSize += strlen(others[i]);
			String newString = String(c, totalSize);
			char* data = newString.data_;
			for (size_t i = 0; i < size; ++i) {
				size_t otherSize = strlen(others[i]);
				memcpy(data, others[i], otherSize);
				data += otherSize + 1;
			}
			return newString;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--SplitStringAt-->
		/// @brief Splits a Power::String into two substrings at the specified index.
		/// @param[in] source The Power::String to be split.
		/// @param[in] index The position where source should be split.
		/// \n If this index is greater than the size of the source Power::String, the method will return wihout filling lhs and rhs.
		/// @param[out] lhs A Power::String containing the left-hand part from index.
		/// @param[out] rhs A Power::String containing the right-hand part from index.
		///
		inline static void SplitStringAt(const String& source, size_t index, String& lhs, String& rhs) {
			if (index > source.size_) return;
			lhs = String(source.data_, index);
			rhs = String(source.data_ + index, source.size_ - index);
		}
		
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--LoadFileIntoString-->
		/// @brief Loads the specified file directly into a new Power::String.
		/// @param filePath The path of the file to be loaded.
		/// @return A new Power::String containing the file data.
		///
		inline static String LoadFileIntoString(const String& filePath) {
			FILE* fp = nullptr;
			return String(fp, filePath.CString());
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Loads the specified file directly into a new Power::String.
		/// @param filePath The path of the file to be loaded.
		/// @return A new Power::String containing the file data.
		///
		inline static String LoadFileIntoString(const char* const filePath) {
			FILE* fp = nullptr;
			return String(fp, filePath);
		}

	public:
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Constructors-->
		/// @brief Initializes a new Power::String with the default capacity.
		///
		String() :
			capacity_(s_defaultCapacity),
			size_(0),
			data_(static_cast<char*>(malloc(capacity_ * 2))),
			temp_(data_ + capacity_)
		{
			*data_ = '\0';
			this->IncInstCounter();
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Initializes a new Power::String with the specified capacity.
		/// @param[in] size The capacity the new Power::String shall have.
		///
		explicit String(size_t size) :
			capacity_(size + 1),
			size_(0),
			data_(static_cast<char*>(malloc(capacity_ * 2))),
			temp_(data_ + capacity_)
		{
			*data_ = '\0';
			this->IncInstCounter();
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Initializes a new Power::String containing the specified c-string.
		/// @param[in] data The c-string with the data.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use String(const char) instead.
		/// @note Implicit conversion constructor. Direct assignment of c-string possible.
		/// @note <b>If the size of the c-string is already known, it is recommended to use String(const char* const, size_t) instead as it is faster</b>
		///
		String(const char* const data) :
			capacity_(0),
			size_(0),
			data_(nullptr),
			temp_(nullptr)
		{
			size_ = strlen(data);
			capacity_ = size_ + s_defaultCapacity;
			data_ = static_cast<char*>(malloc(capacity_ * 2));
			this->IncInstCounter();
			temp_ = data_ + capacity_;
			memcpy(data_, data, size_);
			data_[size_] = '\0';
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Initializes a new Power::String containing the specified character.
		/// @param[in] c The character.
		/// @note Implicit conversion constructor. Direct assignment of character possible.
		///
		String(const char c) :
			capacity_(s_defaultCapacity),
			size_(1),
			data_(static_cast<char*>(malloc(capacity_ * 2))),
			temp_(data_ + capacity_)
		{
			*data_ = c;
			data_[1] = '\0';
			this->IncInstCounter();
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Initializes a new Power::String containing the specified c-string.
		/// @param[in] data The c-string with the data.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use String(const char) instead.
		/// @param[in] size The size of the c-string excluding the null character.
		///
		String(const char* const data, size_t size) :
			capacity_(size + s_defaultCapacity),
			size_(size),
			data_(static_cast<char*>(malloc(capacity_ * 2))),
			temp_(data_ + capacity_)
		{
			memcpy(data_, data, size_);
			data_[size_] = '\0';
			this->IncInstCounter();
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Initializes a new Power::String and fills it to the specified size with the specified character.
		/// @param[in] c The character to fill with.
		/// @param[in] size The size of the new Power::String.
		///
		String(const char c, size_t size) :
			capacity_(size + s_defaultCapacity),
			size_(size),
			data_(static_cast<char*>(malloc(capacity_ * 2))),
			temp_(data_ + capacity_)
		{
			memset(data_, c, size_);
			data_[size_] = '\0';
			this->IncInstCounter();
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Initializes a copy of the specified Power::String.
		/// @param[in] other The Power::String to copy.
		///
		String(const String& other) :
			capacity_(other.capacity_),
			size_(other.size_),
			data_(static_cast<char*>(malloc(capacity_ * 2))),
			temp_(data_ + capacity_)
		{
			memcpy(data_, other.data_, other.size_);
			data_[size_] = '\0';
			this->IncInstCounter();
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Assignment operators-->
		/// @brief Assignes the content of another Power::String to the Power::String.
		/// @param other The Power::String to be assigned.
		///
		inline void operator=(const String& other) {
			this->CheckCapacityAndReallocate(other.size_);
			memcpy(data_, other.data_, other.size_);
			this->SetNewSize(other.size_);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Assignes a c-string to the Power::String.
		/// @param other The c-string to be assigned.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use operator=(const char) instead.
		///
		inline void operator=(const char* const other) {
			size_t newSize = strlen(other);
			int64_t offset = other - data_;
			this->CheckCapacityAndReallocate(newSize);
			if (this->PointerToSelf(offset)) {
				memcpy(temp_, data_ + offset, newSize);
				memcpy(data_, temp_, newSize);
			} else 
				memcpy(data_, other, newSize);
			this->SetNewSize(newSize);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Assigns a character to the Power::String.
		/// @param c The character to be assigned.
		///
		inline void operator=(const char c) {
			this->CheckCapacityAndReallocate(1);
			*data_ = c;
			this->SetNewSize(1);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Addition operators-->
		/// @brief Merges the Power::String with another Power::String.
		/// @param[in] other The Power::String to be merged with.
		/// @return A copy of the new Power::String.
		///
		inline String operator+(const String& other) const { return String(*this, other); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges the Power::String with a c-string.
		/// @param[in] other The c-string to be merged with.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use operator+(const char) const instead.
		/// @return A copy of the new Power::String.
		///
		inline String operator+(const char* const other) const { return String(*this, other); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges the Power::String with a character.
		/// @param[in] c The character to be merged with.
		/// @return A copy of the new Power::String.
		///
		inline String operator+(const char c) const { return String(*this, c); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges the Power::String with a signed short value.
		/// @param[in] value The signed short value to be merged with.
		/// @return A copy of the new Power::String.
		///
		inline String operator+(const int16_t value) const { return String(*this, value); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges the Power::String with a unsigned short value.
		/// @param[in] value The unsigned short value to be merged with.
		/// @return A copy of the new Power::String.
		///
		inline String operator+(const uint16_t value) const { return String(*this, value); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges the Power::String with a signed integer value.
		/// @param[in] value The signed integer value to be merged with.
		/// @return A copy of the new Power::String.
		///
		inline String operator+(const int32_t value) const { return String(*this, value); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges the Power::String with a unsigned integer value.
		/// @param[in] value The unsigned integer value to be merged with.
		/// @return A copy of the new Power::String.
		///
		inline String operator+(const uint32_t value) const { return String(*this, value); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges the Power::String with a signed long long value.
		/// @param[in] value The signed long long value to be merged with.
		/// @return A copy of the new Power::String.
		///
		inline String operator+(const int64_t value) const { return String(*this, value); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges the Power::String with a unsigned long long value.
		/// @param[in] value The unsigned long long value to be merged with.
		/// @return A copy of the new Power::String.
		///
		inline String operator+(const uint64_t value) const { return String(*this, value); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges the Power::String with a float value.
		/// @param[in] value The float value to be merged with.
		/// @return A copy of the new Power::String.
		///
		inline String operator+(const float value) const { return String(*this, value); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges the Power::String with a double value.
		/// @param[in] value The double value to be merged with.
		/// @return A copy of the new Power::String.
		///
		inline String operator+(const double value) const { return String(*this, value); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Compound addition operators-->
		/// @brief Merges the Power::String with another Power::String.
		/// @param[in] other The Power::String to be merged with.
		///
		inline void operator+=(const String& other) { this->Concatenate(other); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges the Power::String with a c-string.
		/// @param[in] other The c-string to be merged with.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use operator+=(const char) instead.
		///
		inline void operator+=(const char* const other) { this->Concatenate(other, strlen(other)); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges the Power::String with a character.
		/// @param[in] c The character to be merged with.
		///
		inline void operator+=(const char c) { this->Concatenate(c); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges the Power::String with a signed short value.
		/// @param[in] value The signed short value to be merged with.
		///
		inline void operator+=(const int16_t value) {
			char buffer[INT16_MAX_CHR_COUNT];
			snprintf(buffer, INT16_MAX_CHR_COUNT, "%hd", value);
			size_t otherSize = strlen(buffer);
			size_t newSize = size_ + otherSize;
			this->CheckCapacityAndReallocate(newSize);
			memcpy(data_ + size_, buffer, otherSize + 1);
			size_ = newSize;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges the Power::String with a unsigned short value.
		/// @param[in] value The unsigned short value to be merged with.
		///
		inline void operator+=(const uint16_t value) {
			char buffer[UINT16_MAX_CHR_COUNT];
			snprintf(buffer, UINT16_MAX_CHR_COUNT, "%hu", value);
			size_t otherSize = strlen(buffer);
			size_t newSize = size_ + otherSize;
			this->CheckCapacityAndReallocate(newSize);
			memcpy(data_ + size_, buffer, otherSize + 1);
			size_ = newSize;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief TMerges the Power::String with a signed integer value.
		/// @param[in] value The signed integer value to be merged with.
		///
		inline void operator+=(const int32_t value) {
			char buffer[INT32_MAX_CHR_COUNT];
			snprintf(buffer, INT32_MAX_CHR_COUNT, "%d", value);
			size_t otherSize = strlen(buffer);
			size_t newSize = size_ + otherSize;
			this->CheckCapacityAndReallocate(newSize);
			memcpy(data_ + size_, buffer, otherSize + 1);
			size_ = newSize;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges the Power::String with a unsigned integer value.
		/// @param[in] value The unsigned integer value to be merged with.
		///
		inline void operator+=(const uint32_t value) {
			char buffer[UINT32_MAX_CHR_COUNT];
			snprintf(buffer, UINT32_MAX_CHR_COUNT, "%u", value);
			size_t otherSize = strlen(buffer);
			size_t newSize = size_ + otherSize;
			this->CheckCapacityAndReallocate(newSize);
			memcpy(data_ + size_, buffer, otherSize + 1);
			size_ = newSize;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges the Power::String with a signed long long value.
		/// @param[in] value The signed long long value to be merged with.
		///
		inline void operator+=(const int64_t value) {
			char buffer[INT64_MAX_CHR_COUNT];
			snprintf(buffer, INT64_MAX_CHR_COUNT, "%lld", value);
			size_t otherSize = strlen(buffer);
			size_t newSize = size_ + otherSize;
			this->CheckCapacityAndReallocate(newSize);
			memcpy(data_ + size_, buffer, otherSize + 1);
			size_ = newSize;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges the Power::String with a unsigned long long value.
		/// @param[in] value The unsigned long long value to be merged with.
		///
		inline void operator+=(const uint64_t value) {
			char buffer[UINT64_MAX_CHR_COUNT];
			snprintf(buffer, UINT64_MAX_CHR_COUNT, "%llu", value);
			size_t otherSize = strlen(buffer);
			size_t newSize = size_ + otherSize;
			this->CheckCapacityAndReallocate(newSize);
			memcpy(data_ + size_, buffer, otherSize + 1);
			size_ = newSize;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges the Power::String with a float value.
		/// @param[in] value The float value to be merged with.
		///
		inline void operator+=(const float value) {
			char buffer[FLOAT_MAX_CHR_COUNT];
			snprintf(buffer, FLOAT_MAX_CHR_COUNT, "%g", value);
			size_t otherSize = strlen(buffer);
			size_t newSize = size_ + otherSize;
			this->CheckCapacityAndReallocate(newSize);
			memcpy(data_ + size_, buffer, otherSize + 1);
			size_ = newSize;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges the Power::String with a double value.
		/// @param[in] value The double value to be merged with.
		///
		inline void operator+=(const double value) {
			char buffer[DOUBLE_MAX_CHR_COUNT];
			snprintf(buffer, DOUBLE_MAX_CHR_COUNT, "%g", value);
			size_t otherSize = strlen(buffer);
			size_t newSize = size_ + otherSize;
			this->CheckCapacityAndReallocate(newSize);
			memcpy(data_ + size_, buffer, otherSize + 1);
			size_ = newSize;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Bitwise left shift operators-->
		/// @brief Merges the Power::String with another Power::String.
		/// @param[in] other The Power::String to be merged with.
		/// @return A reference to the current Power::String.
		/// @note This operator is faster than the addition operator since it returns a reference instead of a copy.
		/// \n As a result this can lead to unexpected behaviour when chaining this operator.
		/// \n If for example the operator is used like this: "string << string << string << string;", the contents will double with each operator call.
		/// \n If that behaviour is undesired, use operator+(const String& other) const instead.
		///
		inline String& operator<<(const String& other) { return this->Concatenate(other); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges the Power::String with a c-string.
		/// @param[in] other The c-string to be merged with.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use operator<<(const char) instead.
		/// @return A reference to the current Power::String.
		/// @note This operator is faster than the addition operator since it returns a reference instead of a copy.
		/// \n As a result this can lead to unexpected behaviour when chaining this operator.
		/// \n If for example the operator is used like this: "string << string.CString() << string.CString() << string.CString();", the contents will double with each operator call.
		/// \n If that behaviour is undesired, use operator+(const char* const other) const instead.
		///
		inline String& operator<<(const char* const other) { return this->Concatenate(other, strlen(other)); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges the Power::String with a character.
		/// @param[in] c The character to be merged with.
		/// @return A reference to the current Power::String.
		///
		inline String& operator<<(const char c) { return this->Concatenate(c); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Subscript operator-->
		/// @brief Returns the character at the specified index.
		/// @param i The index.
		/// @return The character at the specified index.
		///
		inline char operator[](size_t i) const { return *(data_ + i); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Cast operators-->
		/// @brief Gets the underlying c-string as a constant.
		/// @return The underlying c-string as a constant.
		///
		inline explicit operator const char*() const { return data_; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Checks if the Power::String is not empty.
		/// @return <span style="color:#30AA00">True</span>, if the size is not 0.
		/// @return <span style="color:#CC3000">False</span>, if the size is 0.
		///
		inline explicit operator bool() const { return size_ != 0; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Comparison equal operators-->
		/// @brief Compares the current Power::String to the specified Power::String.
		/// @param other The Power::String to be compared against.
		/// @return <span style="color:#30AA00">True</span>, if both Power::Strings are equal.
		/// @return <span style="color:#CC3000">False</span>, if both Power::Strings are not equal.
		///
		inline bool operator==(const String& other) const { return size_ == other.size_ && memcmp(data_, other.data_, other.size_) == 0; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Compares the current Power::String to the specified c-string.
		/// @param other The c-string to be compared against.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use operator==(const char) const instead.
		/// @return <span style="color:#30AA00">True</span>, if the Power::String is equal to the c-string.
		/// @return <span style="color:#CC3000">False</span>, if the Power::String is not equal to the c-string.
		///
		inline bool operator==(const char* const other) const { return strcmp(data_, other) == 0; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Compares the current Power::String to the specified character.
		/// @param c The character to be compared against.
		/// @return <span style="color:#30AA00">True</span>, if the Power::String is equal to the character.
		/// @return <span style="color:#CC3000">False</span>, if the Power::String is not equal to the character.
		///
		inline bool operator==(const char c) const { return size_ == 1 && *data_ == c; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Comparison not equal operators-->
		/// @brief Compares the current Power::String to the specified Power::String.
		/// @param other The Power::String to be compared against.
		/// @return <span style="color:#30AA00">True</span>, if both Power::Strings are not equal.
		/// @return <span style="color:#CC3000">False</span>, if both Power::Strings are equal.
		///
		inline bool operator!=(const String& other) const { return size_ != other.size_ || memcmp(data_, other.data_, other.size_) != 0; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Compares the current Power::String to the specified c-string.
		/// @param other The c-string to be compared against.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use operator!=(const char) const instead.
		/// @return <span style="color:#30AA00">True</span>, if the Power::String is not equal to the c-string.
		/// @return <span style="color:#CC3000">False</span>, if the Power::String is equal to the c-string.
		///
		inline bool operator!=(const char* const other) const { return strcmp(data_, other) != 0; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Compares the current Power::String to the specified character.
		/// @param c The character to be compared against.
		/// @return <span style="color:#30AA00">True</span>, if the Power::String is not equal to the character.
		/// @return <span style="color:#CC3000">False</span>, if the Power::String is equal to the character.
		///
		inline bool operator!=(const char c) const { return size_ > 1 || *data_ != c; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Capacity-->
		/// @brief Gets the current total number of array elements of the Power::String.
		/// @return The current total number of array elements of the Power::String.
		///
		inline size_t Capacity() const { return capacity_; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--MaxCharCount-->
		/// @brief Gets the current maximum character count of the Power::String which is Capacity() - 1.
		/// @return The current maximum character count of the Power::String.
		///
		inline size_t MaxCharCount() const { return capacity_ - 1; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Size-->
		/// @brief Gets the current size excluding the null character of the Power::String.
		/// @return The current size excluding the null character of the Power::String.
		///
		inline size_t Size() const { return size_; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--CString-->
		/// @brief Gets the underlying c-string as a constant.
		/// @return The underlying c-string as a constant.
		///
		inline const char* CString() const { return data_; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--IsEmpty-->
		/// @brief Checks if the Power::String is empty.
		/// @return <span style="color:#30AA00">True</span>, if the size is 0.
		/// @return <span style="color:#CC3000">False</span>, if the size is not 0.
		///
		inline bool IsEmpty() const { return size_ == 0; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--ShrinkToFit-->
		/// @brief Shrinks the capacity of the Power::String to fit the size to conserve memory.
		///
		inline void ShrinkToFit() {
			if (size_ + 1 == capacity_) return;
			capacity_ = size_ + 1;
			data_ = static_cast<char*>(realloc(data_, capacity_ * 2));
			temp_ = data_ + capacity_;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Concatenate-->
		/// @brief Merges the Power::String with another Power::String.
		/// @param[in] other The Power::String to be merged with.
		/// @return A reference to the current Power::String.
		///
		inline String& Concatenate(const String& other) {
			size_t newSize = size_ + other.size_;
			this->CheckCapacityAndReallocate(newSize);
			memcpy(data_ + size_, other.data_, other.size_);
			this->SetNewSize(newSize);
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges the Power::String with a c-string. The c-string will be placed after the Power::String.
		/// @param[in] other The c-string to be merged with.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Concatenate(const char) instead.
		/// @note <b>If the size of the c-string is already known, it is recommend to use Concatenate(const char* const, size_t) instead as it is faser.</b>
		/// @return A reference to the current Power::String.
		///
		inline String& Concatenate(const char* const other) { return this->Concatenate(other, strlen(other)); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges the Power::String with a c-string. The c-string will be placed after the Power::String.
		/// @param[in] other The c-string to be merged with.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Concatenate(const char) instead.
		/// @param[in] size The size of the c-string excluding the null character.
		/// @return A reference to the current Power::String.
		///
		inline String& Concatenate(const char* const other, size_t size) {
			int64_t offset = other - data_;
			size_t newSize = size_ + size;
			this->CheckCapacityAndReallocate(newSize);
			if (this->PointerToSelf(offset)) memcpy(data_ + size_, data_ + offset, size);
			else memcpy(data_ + size_, other, size);
			this->SetNewSize(newSize);
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges the Power::String with a character. The character will be placed after the Power::String.
		/// @param[in] c The character to be merged with.
		/// @return A reference to the current Power::String.
		///
		inline String& Concatenate(const char c) {
			this->CheckCapacityAndReallocate(++size_);
			data_[size_ - 1] = c;
			data_[size_] = '\0';
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges a c-string with the Power::String. The c-string will be placed before the Power::String.
		/// @param[in] other The c-string to be merged with.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use ConcatenateAfter(const char) instead.
		/// @note <b>If the size of the c-string is already known, it is recommend to use ConcatenateAfter(const char* const, size_t) instead as it is faser.</b>
		/// @return A reference to the current Power::String.
		///
		inline String& ConcatenateAfter(const char* const other) { return this->ConcatenateAfter(other, strlen(other)); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges a c-string with the Power::String. The c-string will be placed before the Power::String.
		/// @param[in] other The c-string to be merged with.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use ConcatenateAfter(const char) instead.
		/// @param[in] size The size of the c-string excluding the null character.
		/// @return A reference to the current Power::String.
		///
		inline String& ConcatenateAfter(const char* const other, size_t size) {
			int64_t offset = other - data_;
			size_t newSize = size_ + size;
			this->CheckCapacityAndReallocate(newSize);
			if (this->PointerToSelf(offset)) {
				memcpy(temp_, data_, size_);
				memcpy(data_, temp_ + offset, size);
				memcpy(data_ + size, temp_, size_);
			} else {
				memcpy(temp_, data_, size_);
				memcpy(data_, other, size);
				memcpy(data_ + size, temp_, size_);
			}
			this->SetNewSize(newSize);
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges a character with the Power::String. The character will be placed before the Power::String.
		/// @param[in] c The character to be merged with.
		/// @return A reference to the current Power::String.
		///
		inline String& ConcatenateAfter(const char c) {
			this->CheckCapacityAndReallocate(++size_);
			memcpy(temp_, data_, size_ - 1);
			*data_ = c;
			memcpy(data_ + 1, temp_, size_ - 1);
			data_[size_] = '\0';
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Contains-->
		/// @brief Checks the Power::String if it contains the specified Power::String.
		/// @param[in] other The Power::String to be checked for.
		/// @return <span style="color:#30AA00">True</span>, if the Power::String contains the spcified Power::String.
		/// @return <span style="color:#CC3000">False</span>, if it doesn't or if the size of the specified Power::String is greater than the Power::String.
		///
		inline bool Contains(const String& other) const { return this->IndexOf(other) >= 0; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Checks the Power::String if it contains the specified c-string.
		/// @param[in] other The c-string to be checked for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Contains(const char) const instead.
		/// @return <span style="color:#30AA00">True</span>, if the Power::String contains the spcified c-string.
		/// @return <span style="color:#CC3000">False</span>, if it doesn't or if the size of the specified c-string is greater than the Power::String.
		/// @note <b>If the size of the c-string is already known, it is recommended to use Contains(const char* const, size_t) const instead as it is faster.</b>
		///
		inline bool Contains(const char* const other) const { return this->IndexOf(strlen(other), other) >= 0; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Checks the Power::String if it contains the specified c-string.
		/// @param[in] other The c-string to be checked for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Contains(const char) const instead.
		/// @param[in] size The size of the c-string excluding the null character.
		/// @return <span style="color:#30AA00">True</span>, if the Power::String contains the spcified c-string.
		/// @return <span style="color:#CC3000">False</span>, if it doesn't or if the size of the specified c-string is greater than the Power::String.
		///
		inline bool Contains(const char* const other, size_t size) const { return this->IndexOf(size, other) >= 0; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Checks the Power::String if it contains the specified character.
		/// @param[in] c The character to be checked for.
		/// @return <span style="color:#30AA00">True</span>, if the Power::String contains the spcified character.
		/// @return <span style="color:#CC3000">False</span>, if it doesn't.
		///
		inline bool Contains(const char c) const { return strchr(data_, c) != nullptr; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--IndexOf-->
		/// @brief Finds the first occurance of the specified Power::String.
		/// @param[in] other The Power::String to look for.
		/// @return The start index of the first occurance of the specified Power::String.
		/// @return Or -1 if the specified Power::String does not occur.
		///
		inline int32_t IndexOf(const String& other) const {
			if (other.size_ > size_ || other.size_ == 0) return -1;
			char* p = strstr(data_, other.data_);
			return p ? static_cast<int32_t>(p - data_) : -1;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the first occurance of the specified Power::String starting from the specified index.
		/// @param[in] other The Power::String to look for.
		/// @param[in] begin The index from where to start looking.
		/// @return The start index of the first occurance of the specified Power::String.
		/// @return Or -1 if the specified Power::String does not occur or if the begin index is greater or equal to the size of the Power::String.
		///
		inline int32_t IndexOf(const String& other, size_t begin) const { 
			if (begin >= size_ || other.size_ > size_ - begin || other.size_ == 0) return -1;
			char* p = strstr(data_ + begin, other.data_);
			return p ? static_cast<int32_t>(p - data_) : -1;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the first occurance of the specified Power::String between the specified start and end index.
		/// @param[in] other The Power::String to look for.
		/// @param[in] begin The index from where to start looking.
		/// @param[in] end The index to where to stop looking.
		/// \n This index is clamped to the size of the Power::String.
		/// @return The start index of the first occurance of the specified Power::String.
		/// @return Or -1 if the specified Power::String does not occur or if the begin index is greater or equal to the size of the Power::String
		/// or if the begin index is greater or equal to the end index.
		///
		inline int32_t IndexOf(const String& other, size_t begin, size_t end) const {
			if (end > size_) end = size_;
			if (begin >= end || other.size_ > end - begin || other.size_ == 0) return -1;
			for (size_t i = begin; i < end - other.size_ + 1; ++i) {
				if (memcmp(data_ + i, other.data_, other.size_) == 0) return static_cast<int32_t>(i);
			}
			return -1;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the first occurance of the specified c-string.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use IndexOf(const char) const instead.
		/// @return The start index of the first occurance of the specified c-string.
		/// @return Or -1 if the specified c-string does not occur.
		/// @note <b>If the size of the c-string is already known, it is recommended to use IndexOf(size_t, const char* const) const instead as it is faster.</b>
		///
		inline int32_t IndexOf(const char* const other) const { return this->IndexOf(strlen(other), other); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the first occurance of the specified c-string starting from the specified index.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use IndexOf(const char, size_t) const instead.
		/// @param[in] begin The index from where to start looking.
		/// @return The start index of the first occurance of the specified c-string.
		/// @return Or -1 if the specified c-string does not occur or if the begin index is greater or equal to the size of the Power::String.
		/// @note <b>If the size of the c-string is already known, it is recommended to use IndexOf(size_t, const char* const, size_t) const instead as it is faster.</b>
		///
		inline int32_t IndexOf(const char* const other, size_t begin) const { return this->IndexOf(strlen(other), other, begin); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the first occurance of the specified c-string between the specified start and end index.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use IndexOf(const char, size_t, size_t) const instead.
		/// @param[in] begin The index from where to start looking.
		/// @param[in] end The index to where to stop looking.
		/// \n This index is clamped to the size of the Power::String.
		/// @return The start index of the first occurance of the specified c-string.
		/// @return Or -1 if the specified c-string does not occur or if the begin index is greater or equal to the size of the Power::String
		/// or if the begin index is greater or equal to the end index.
		/// @note <b>If the size of the c-string is already known, it is recommended to use IndexOf(size_t, const char* const, size_t, size_t) const instead as it is faster.</b>
		///
		inline int32_t IndexOf(const char* const other, size_t begin, size_t end) const { return this->IndexOf(strlen(other), other, begin, end); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the first occurance of the specified c-string.
		/// @param[in] size The size of the specified c-string excluding the null character.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use IndexOf(const char) const instead.
		/// @return The start index of the first occurance of the specified c-string.
		/// @return Or -1 if the specified c-string does not occur.
		///
		inline int32_t IndexOf(size_t size, const char* const other) const {
			if (size > size_ || size == 0) return -1;
			char* p = strstr(data_, other);
			return p ? static_cast<int32_t>(p - data_) : -1;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the first occurance of the specified c-string starting from the specified index.
		/// @param[in] size The size of the specified c-string excluding the null character.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use IndexOf(const char, size_t) const instead.
		/// @param[in] begin The index from where to start looking.
		/// @return The start index of the first occurance of the specified c-string.
		/// @return Or -1 if the specified c-string does not occur or if the begin index is greater or equal to the size of the Power::String.
		///
		inline int32_t IndexOf(size_t size, const char* const other, size_t begin) const {
			if (begin >= size_ || size > size_ - begin || size == 0) return -1;
			char* p = strstr(data_ + begin, other);
			return p ? static_cast<int32_t>(p - data_) : -1;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the first occurance of the specified c-string between the specified start and end index.
		/// @param[in] size The size of the specified c-string excluding the null character.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use IndexOf(const char, size_t, size_t) const instead.
		/// @param[in] begin The index from where to start looking.
		/// @param[in] end The index to where to stop looking.
		/// \n This index is clamped to the size of the Power::String.
		/// @return The start index of the first occurance of the specified c-string.
		/// @return Or -1 if the specified c-string does not occur or if the begin index is greater or equal to the size of the Power::String
		/// or if the begin index is greater or equal to the end index.
		///
		inline int32_t IndexOf(size_t size, const char* const other, size_t begin, size_t end) const {
			if (end > size_) end = size_;
			if (begin >= end || size > end - begin || size == 0) return -1;
			for (size_t i = begin; i < end - size + 1; ++i) {
				if (memcmp(data_ + i, other, size) == 0) return static_cast<int32_t>(i);
			}
			return -1;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the first occurance of the specified character.
		/// @param[in] c The character to look for.
		/// @return The index of the first occurance of the specified character.
		/// @return Or -1 if the specified character does not occur.
		///
		inline int32_t IndexOf(const char c) const {
			char* p = static_cast<char*>(memchr(data_, c, size_));
			return p ? static_cast<int32_t>(p - data_) : -1;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the first occurance of the specified character starting from the specified index.
		/// @param[in] c The character to look for.
		/// @param[in] begin The index from where to start looking.
		/// @return The index of the first occurance of the specified character.
		/// @return Or -1 if the specified character does not occur or if the begin index is greater or equal to the size of the Power::String.
		///
		inline int32_t IndexOf(const char c, size_t begin) const {
			if (begin >= size_) return -1;
			char* p = static_cast<char*>(memchr(data_ + begin, c, size_ - begin));
			return p ? static_cast<int32_t>(p - data_) : -1;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the first occurance of the specified character between the specified start and end index.
		/// @param[in] c The character to look for.
		/// @param[in] begin The index from where to start looking.
		/// @param[in] end The index to where to stop looking.
		/// \n This index is clamped to the size of the Power::String.
		/// @return The index of the first occurance of the specified character.
		/// @return Or -1 if the specified character does not occur or if the begin index is greater or equal to the size of the Power::String
		/// or if the begin index is greater or equal to the end index.
		///
		inline int32_t IndexOf(const char c, size_t begin, size_t end) const {
			if (end > size_) end = size_;
			if (begin >= end) return -1;
			char* p = static_cast<char*>(memchr(data_ + begin, c, end - begin));
			return p ? static_cast<int32_t>(p - data_) : -1;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--LastIndexOf-->
		/// @brief Finds the last occurance of the specified Power::String.
		/// @param[in] other The Power::String to look for.
		/// @return The start index of the last occurance of the specified Power::String.
		/// @return Or -1 if the spcified Power::String does not occur.
		///
		inline int32_t LastIndexOf(const String& other) const { return this->LastIndexOf(other, size_, 0); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the last occurance of the specified Power::String starting from the specified index.
		/// @param[in] other The Power::String for look for.
		/// @param[in] begin The index from where to start lookin.
		/// @return The start index of the last occurance of the specified Power::String.
		/// @return Or -1 if the spcified Power::String does not occur or if the end index is greater or equal to the size of the Power::String.
		///
		inline int32_t LastIndexOf(const String& other, size_t begin) const { return this->LastIndexOf(other, begin, 0); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the last occurance of the specified Power::String between the specified start and end index.
		/// @param[in] other The Power::String for look for.
		/// @param[in] begin The index from where to start lookin.
		/// \n This index is clamped to the size of the Power::String.
		/// @param[in] end The index to where to stop looking.
		/// @return The start index of the last occurance of the specified Power::String.
		/// @return Or -1 if the spcified Power::String does not occur or if the end index is greater or equal to the size of the Power::String
		/// or if the end index is greater or equal to the begin index.
		///
		inline int32_t LastIndexOf(const String& other, size_t begin, size_t end) const {
			if (begin > size_) begin = size_;
			if (end >= begin || other.size_ > end - begin || other.size_ == 0) return -1;
			for (int32_t i = static_cast<int32_t>(begin); i >= static_cast<int32_t>(end + other.size_) - 1; --i) {
				if (data_[i] != other.data_[other.size_ - 1]) continue;
				int32_t x = i - static_cast<int32_t>(other.size_) + 1;
				if (x < 0) return -1;
				if (memcmp(data_ + x, other.data_, other.size_) == 0) return x;
			}
			return -1;
		}
				
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the last occurance of the specified c-string.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use LastIndexOf(const char) const instead.
		/// @return The start index of the last occurance of the specified c-string.
		/// @return Or -1 if the specified c-string does not occur.
		/// @note <b>If the size of the c-string is already known, it is recommended to use LastIndexOf(size_t, const char* const) const instead as it is faster.</b>
		///
		inline int32_t LastIndexOf(const char* const other) const { return this->LastIndexOf(strlen(other), other, size_, 0);	}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the last occurance of the specified c-string starting from the specified index.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use LastIndexOf(const char, size_t) const instead.
		/// @param[in] begin The index from where to start looking.
		/// \n This index is clamped to the size of the Power::String.
		/// @return The start index of the last occurance of the specified c-string.
		/// @return Or -1 if the specified c-string does not occur.
		/// @note <b>If the size of the c-string is already known, it is recommended to use LastIndexOf(size_t, const char* const, size_t) const instead as it is faster.</b>
		///
		inline int32_t LastIndexOf(const char* const other, size_t begin) const { return this->LastIndexOf(strlen(other), other, begin, 0); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the last occurance of the specified c-string between the specified start and end index.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use LastIndexOf(const char, size_t, size_t) const instead.
		/// @param[in] begin The index from where to start looking.
		/// \n This index is clamped to the size of the Power::String.
		/// @param[in] end The index to where to stop looking.
		/// @return The start index of the last occurance of the specified c-string.
		/// @return Or -1 if the specified c-string does not occur or if the end index is greater or equal to the size of the Power::String
		/// or if the end index is greater or equal to the eegin index.
		/// @note <b>If the size of the c-string is already known, it is recommended to use LastIndexOf(size_t, const char* const, size_t, size_t) const instead as it is faster.</b>
		///
		inline int32_t LastIndexOf(const char* const other, size_t begin, size_t end) const { return this->LastIndexOf(strlen(other), other, begin, end); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the last occurance of the specified c-string.
		/// @param[in] size The size of the specified c-string excluding the null character.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use LastIndexOf(const char) const instead.
		/// @return The start index of the last occurance of the specified c-string.
		/// @return Or -1 if the specified c-string does not occur.
		///
		inline int32_t LastIndexOf(size_t size, const char* const other) const { return this->LastIndexOf(size, other, 0, size_); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the last occurance of the specified c-string starting from the specified index.
		/// @param[in] size The size of the specified c-string excluding the null character.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use LastIndexOf(const char, size_t) const instead.
		/// @param[in] begin The index from where to start looking.
		/// \n This index is clamped to the size of the Power::String.
		/// @return The start index of the last occurance of the specified c-string.
		/// @return Or -1 if the specified c-string does not occur.
		///
		inline int32_t LastIndexOf(size_t size, const char* const other, size_t begin) const { return this->LastIndexOf(size, other, begin, size_); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the last occurance of the specified c-string between the specified start and end index.
		/// @param[in] size The size of the specified c-string excluding the null character.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use LastIndexOf(const char, size_t, size_t) const instead.
		/// @param[in] begin The index from where to start looking.
		/// \n This index is clamped to the size of the Power::String.
		/// @param[in] end The index to where to stop looking.
		/// @return The start index of the last occurance of the specified c-string.
		/// @return Or -1 if the specified c-string does not occur or if the end index is greater or equal to the size of the Power::String
		/// or if the end index is greater or equal to the begin index.
		///
		inline int32_t LastIndexOf(size_t size, const char* const other, size_t begin, size_t end) const {
			if (begin > size_) begin = size_;
			if (end >= begin || size > end - begin || size == 0) return -1;
			for (int32_t i = static_cast<int32_t>(begin); i >= static_cast<int32_t>(end + size) - 1; --i) {
				if (data_[i] != other[size - 1]) continue;
				int32_t x = i - static_cast<int32_t>(size) + 1;
				if (x < 0) return -1;
				if (memcmp(data_ + x, other, size) == 0) return x;
			}
			return -1;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the last occurance of the specified character.
		/// @param[in] c The character to look for.
		/// @return The index of the last occurance of the specified character.
		/// @return Or -1 if the specified character does not occur.
		///
		inline int32_t LastIndexOf(const char c) const {
			char* p = strrchr(data_, c);
			return p ? static_cast<int32_t>(p - data_) : -1;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the last occurance of the specified character starting from the specified index.
		/// @param[in] c The character to look for.
		/// @param[in] begin The index from where to start looking.
		/// \n This index is clamped to the size of the Power::String.
		/// @return The index of the last occurance of the specified character.
		/// @return Or -1 if the specified character does not occur.
		///
		inline int32_t LastIndexOf(const char c, size_t begin) const { return this->LastIndexOf(c, begin, 0); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the last occurance of the specified character between the specified start and end index.
		/// @param[in] c The character to look for.
		/// @param[in] begin The index from where to start looking.
		/// \n This index is clamped to the size of the Power::String.
		/// @param[in] end The index to where to stop looking.
		/// @return The index of the last occurance of the specified character.
		/// @return Or -1 if the specified character does not occur or if the end index is greater or equal to the size of the Power::String
		/// or if the end index is greater or equal to the begin index.
		///
		inline int32_t LastIndexOf(const char c, size_t begin, size_t end) const {
			if (begin > size_) begin = size_;
			if (end >= begin) return -1;
			for (int32_t i = static_cast<int32_t>(begin); i >= static_cast<int32_t>(end); --i) if (data_[i] == c) return i;
			return -1;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Count-->
		/// @brief Counts how many times the specified Power::String occurs in the Power::String.
		/// @param[in] other The Power::String to look for.
		/// @return How many times the specified Power::String occurs.
		/// @return Or 0 if the specified Power::String does not occur.
		///
		inline int32_t Count(const String& other) const { return this->Count(other, 0, size_); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Counts how many times the specified Power::String occurs in the Power::String from the specified index.
		/// @param[in] other The Power::String to look for.
		/// @param[in] begin The index from where to start looking.
		/// @return How many times the specified Power::String occurs.
		/// @return Or 0 if the specified Power::String does not occur or if the begin index is greater or equal to the size of the Power::String.
		///
		inline int32_t Count(const String& other, size_t begin) const { return this->Count(other, begin, size_); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Counts how many times the specified Power::String occurs in the Power::String from the specified start and end index.
		/// @param[in] other The Power::String to look for.
		/// @param[in] begin The index from where to start looking.
		/// @param[in] end The index to where to stop looking.
		/// \n This index is clamped to the size of the Power::String.
		/// @return How many times the specified Power::String occurs.
		/// @return Or 0 if the specified Power::String does not occur or if the begin index is greater or equal to the size of the Power::String
		/// or if the begin index is greater or equal to the end index.
		///
		inline int32_t Count(const String& other, size_t begin, size_t end) const {
			int32_t count = 0;
			int32_t curIndex = this->IndexOf(other, begin, end);
			while (curIndex != -1) {
				++count;
				curIndex = this->IndexOf(other, curIndex + 1, end);
			}
			return count;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Counts how many times the specified c-string occurs in the Power::String.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Count(const char) const instead.
		/// @return How many times the specified c-string occurs.
		/// @return Or 0 if the specified c-string does not occur.
		/// @note <b>If the size of the c-string is already known, it is recommended to use Count(size_t, const char* const) const instead as it is faster.</b>
		///
		inline int32_t Count(const char* const other) const { return this->Count(strlen(other), other, 0, size_); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Counts how many times the specified c-string occurs in the Power::String.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Count(const char, size_t) const instead.
		/// @param[in] begin The index from where to start looking.
		/// @return How many times the specified c-string occurs.
		/// @return Or 0 if the specified c-string does not occur or if the begin index is greater or equal to the size of the Power::String.
		/// @note <b>If the size of the c-string is already known, it is recommended to use Count(size_t, const char* const, size_t) const instead as it is faster.</b>
		///
		inline int32_t Count(const char* const other, size_t begin) const { return this->Count(strlen(other), other, begin, size_); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Counts how many times the specified c-string occurs in the Power::String.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Count(const char, size_t, size_t) const instead.
		/// @param[in] begin The index from where to start looking.
		/// @param[in] end The index to where to stop looking.
		/// \n This index is clamped to the size of the Power::String.
		/// @return How many times the specified c-string occurs.
		/// @return Or 0 if the specified c-string does not occur or if the begin index is greater or equal to the size of the Power::String
		/// or if the begin index is greater or equal to the end index.
		/// @note <b>If the size of the c-string is already known, it is recommended to use Count(size_t, const char* const, size_t, size_t) const instead as it is faster.</b>
		///
		inline int32_t Count(const char* const other, size_t begin, size_t end) const { return this->Count(strlen(other), other, begin, end); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Counts how many times the specified c-string occurs in the Power::String.
		/// @param[in] size The size of the specified c-string excluding the null character.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Count(const char) const instead.
		/// @return How many times the specified c-string occurs.
		/// @return Or 0 if the specified c-string does not occur.
		///
		inline int32_t Count(size_t size, const char* const other) const { return this->Count(size, other, 0, size_); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Counts how many times the specified c-string occurs in the Power::String.
		/// @param[in] size The size of the specified c-string excluding the null character.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Count(const char, size_t) const instead.
		/// @param[in] begin The index from where to start looking.
		/// @return How many times the specified c-string occurs.
		/// @return Or 0 if the specified c-string does not occur or if the begin index is greater or equal to the size of the Power::String.
		///
		inline int32_t Count(size_t size, const char* const other, size_t begin) const { return this->Count(size, other, begin, size_); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Counts how many times the specified c-string occurs in the Power::String.
		/// @param[in] size The size of the specified c-string excluding the null character.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Count(const char, size_t, size_t) const instead.
		/// @param[in] begin The index from where to start looking.
		/// @param[in] end The index to where to stop looking.
		/// \n This index is clamped to the size of the Power::String.
		/// @return How many times the specified c-string occurs.
		/// @return Or 0 if the specified c-string does not occur or if the begin index is greater or equal to the size of the Power::String
		/// or if the begin index is greater or equal to the end index.
		///
		inline int32_t Count(size_t size, const char* const other, size_t begin, size_t end) const {
			int32_t count = 0;
			int32_t curIndex = this->IndexOf(size, other, begin, end);
			while (curIndex != -1) {
				++count;
				curIndex = this->IndexOf(size, other, curIndex + 1, end);
			}
			return count;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Counts how many times the specified character occurs in the Power::String.
		/// @param[in] c The character to look for.
		/// @return How many times the specified character occurs.
		/// @return Or 0 if the specified character does not occur.
		///
		inline int32_t Count(const char c) const { return this->Count(c, 0, size_); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Counts how many times the specified character occurs in the Power::String.
		/// @param[in] c The character to look for.
		/// @param[in] begin The index from where to start looking.
		/// @return How many times the specified character occurs.
		/// @return Or 0 if the specified character does not occur or if the begin index is greater or equal to the size of the Power::String.
		///
		inline int32_t Count(const char c, size_t begin) const { return this->Count(c, begin, size_); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Counts how many times the specified character occurs in the Power::String.
		/// @param[in] c The character to look for.
		/// @param[in] begin The index from where to start looking.
		/// @param[in] end The index to where to stop looking.
		/// \n This index is clamped to the size of the Power::String.
		/// @return How many times the specified character occurs.
		/// @return Or 0 if the specified character does not occur or if the begin index is greater or equal to the size of the Power::String
		/// or if the begin index is greater or equal to the end index.
		///
		inline int32_t Count(const char c, size_t begin, size_t end) const {
			int32_t count = 0;
			int32_t curIndex = this->IndexOf(c, begin, end);
			while (curIndex != -1) {
				++count;
				curIndex = this->IndexOf(c, curIndex + 1, end);
			}
			return count;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Substring-->
		/// @brief Creates a substring from the specified start index to the end of the Power::String.
		/// @param[in] begin The index from where to start.
		/// @return A Power::String containing the substring.
		/// @return The returned Power::String will be empty, if the start index is greater than the size of the Power::String.
		///
		inline String Substring(size_t begin) const {
			if (begin > size_) begin = size_;
			return String(data_ + begin, size_ - begin);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Creates a substring from the specified start index to the specified end index.
		/// @param[in] begin The index from where to start.
		/// @param[in] end The index to where to stop.
		/// @return A Power::String containing the substring.
		/// @return The returned Power::String will be empty, if the start index is greater than the end index or the size of the Power::String.
		///
		inline String Substring(size_t begin, size_t end) const {
			if (end > size_) end = size_;
			if (begin > end) begin = end;
			return String(data_ + begin, end - begin);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Insert-->
		/// @brief Inserts the specified Power::String at the specified index.
		/// @param[in] index The index where the specified Power::String will be inserted at.
		/// \n If this index is greater than the size of the Power::String, the method will return and nothing will be inserted.
		/// @param[in] other The Power::String to be inserted.
		/// @return A reference to the current Power::String.
		///
		inline String& Insert(size_t index, const String& other) {
			if (index > size_) return *this;
			size_t newSize = size_ + other.size_;
			this->CheckCapacityAndReallocate(newSize);
			memcpy(temp_, other.data_, other.size_);
			memcpy(temp_ + other.size_, data_ + index, size_ - index);
			memcpy(data_ + index, temp_, newSize - index);
			this->SetNewSize(newSize);
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Inserts the specified c-string at the specified index.
		/// @param[in] index The index where the specified c-string will be inserted at.
		/// \n If this index is greater than the size of the Power::String, the method will return and nothing will be inserted.
		/// @param[in] other The c-string to be inserted.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Insert(size_t, const char) instead.
		/// @note <b>If the size of the c-string is already known, it is recommended to use Insert(sizt_t, const char* const, size_t) instead as it is faster.</b>
		/// @return A reference to the current Power::String.
		///
		inline String& Insert(size_t index, const char* const other) { return this->Insert(index, other, strlen(other)); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Inserts the specified c-string at the specified index.
		/// @param[in] index The index where the specified c-string will be inserted at.
		/// \n If this index is greater than the size of the Power::String, the method will return and nothing will be inserted.
		/// @param[in] other The c-string to be inserted.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Insert(size_t, const char) instead.
		/// @param[in] size The size of the c-string excluding the null character.
		/// @return A reference to the current Power::String.
		///
		inline String& Insert(size_t index, const char* const other, size_t size) {
			if (index > size_) return *this;
			size_t newSize = size_ + size;
			this->CheckCapacityAndReallocate(newSize);
			int64_t offset = other - data_;
			if (this->PointerToSelf(offset)) memcpy(temp_, data_ + offset, size);
			else memcpy(temp_, other, size);
			memcpy(temp_ + size, data_ + index, size_ - index);
			memcpy(data_ + index, temp_, newSize - index);
			this->SetNewSize(newSize);
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Inserts the specified character at the specified index.
		/// @param[in] index The index where the specified character will be inserted at.
		/// \n If this index is greater than the size of the Power::String, the method will return and nothing will be inserted.
		/// @param[in] c The character to be inserted.
		/// @return A reference to the current Power::String.
		///
		inline String& Insert(size_t index, const char c) {
			if (index > size_) return *this;
			size_t newSize = size_ + 1;
			this->CheckCapacityAndReallocate(newSize);
			*temp_ = c;
			memcpy(temp_ + 1, data_ + index, size_ - index);
			memcpy(data_ + index, temp_, newSize - index);
			this->SetNewSize(newSize);
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Remove-->
		/// @brief Removes all characters in the Power::Strig starting from the specified index.
		/// @param[in] index The index from where to start.
		/// \n If this index is greater or equal to the size of the Power::String, the method will return and nothing will be removed.
		/// @return A reference to the current Power::String.
		///
		inline String& Remove(size_t index) { return this->Remove(index, size_ - index); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Removes a specified amount of characters in the Power::String starting from the specified index.
		/// @param[in] index The index from where to start.
		/// \n If this index is greater or equal to the size of the Power::String, the method will return and nothing will be removed.
		/// @param[in] count How many characters shall be removed.
		/// \n This value gets clamped to the size of the Power::String minus the specified index.
		/// @return A reference to the current Power::String.
		///
		inline String& Remove(size_t index, size_t count) {
			if (index >= size_) return *this;
			if (count > size_ - index) count = size_ - index;
			memcpy(temp_, data_, index);
			memcpy(temp_ + index, data_ + index + count, size_ - index - count);
			size_ = size_ - count;
			memcpy(data_, temp_, size_);
			data_[size_] = '\0';
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--RemoveAll-->
		/// @brief Removes all occurances of the specified Power::String.
		/// @param[in] other The Power::String to remove.
		/// @return A reference to the current Power::String.
		///
		inline String& RemoveAll(const String& other) {
			int32_t index = 0;
			int32_t nextIndex = this->IndexOf(other.data_);
			if (nextIndex < 0) return *this;
			size_t i = 0;
			char* temp = temp_;
			while (nextIndex >= 0) {
				memcpy(temp, data_ + index, nextIndex - index);
				temp += nextIndex - index;
				index = nextIndex + static_cast<int32_t>(other.size_);
				nextIndex = this->IndexOf(other.data_, index);
				++i;
			}
			memcpy(temp, data_ + index, size_ - index);
			size_ = size_ - i * other.size_;
			memcpy(data_, temp_, size_);
			data_[size_] = '\0';
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Removes all occurances of the specified c-string.
		/// @param[in] other The c-string to remove.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use RemoveAll(const char) instead.
		/// @node <b>If the size of the c-string is already known, it is recommended to use RemoveAll(const char* const, size_t) instead as it is faster.</b>
		/// @return A reference to the current Power::String.
		///
		inline String& RemoveAll(const char* const other) { return this->RemoveAll(other, strlen(other)); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Removes all occurances of the specified c-string.
		/// @param[in] other The c-string to remove.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use RemoveAll(const char) instead.
		/// @param[in] size The size of the c-string excluding the null character.
		/// @return A reference to the current Power::String.
		///
		inline String& RemoveAll(const char* const other, size_t size) {
			int32_t index = 0;
			int32_t nextIndex = this->IndexOf(other);
			if (nextIndex < 0) return *this;
			size_t i = 0;
			char* temp = temp_;
			while (nextIndex >= 0) {
				memcpy(temp, data_ + index, nextIndex - index);
				temp += nextIndex - index;
				index = nextIndex + static_cast<int32_t>(size);
				nextIndex = this->IndexOf(other, index);
				++i;
			}
			memcpy(temp, data_ + index, size_ - index);
			size_ = size_ - i * size;
			memcpy(data_, temp_, size_);
			data_[size_] = '\0';
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Removes all occurances of the specified character.
		/// @param[in] c The character to remove.
		/// @return A reference to the current Power::String.
		///
		inline String& RemoveAll(const char c) {
			size_t count = 0;
			for (size_t i = 0; i < size_; ++i) if (data_[i] == c) ++count;
			if (count == 0) return *this;
			size_t newSize = size_ - count;
			count = 0;
			for (size_t i = 0; i < size_; ++i) {
				if (data_[i] == c) continue;
				temp_[count] = data_[i];
				++count;
			}
			memcpy(data_, temp_, newSize);
			this->SetNewSize(newSize);
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Replace-->
		/// @brief Replaces all characters from the specified start index with the specified Power::String.
		/// @param[in] index The index from where to replace.
		/// \n If this index is greater or equal to the size of the Power::String, the method will return and nothing will be replaced.
		/// @param[in] other The Power::String with which to replace.
		/// @return A reference to the current Power::String.
		///
		inline String& Replace(size_t index, const String& other) { return this->Replace(index, size_ - index, other); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Replaces a specified amount of characters from the specified start index with the specified Power::String.
		/// @param[in] index The index from where to replace.
		/// \n If this index is greater or equal to the size of the Power::String, the method will return and nothing will be replaced.
		/// @param[in] count How many characters will be replaced.
		/// \n This value gets clamped to the size of the Power::String minus the specified index.
		/// @param[in] other The Power::String with which to replace.
		/// @return A reference to the current Power::String.
		///
		inline String& Replace(size_t index, size_t count, const String& other) {
			if (index >= size_) return *this;
			if (count > size_ - index) count = size_ - index;
			size_t newSize = size_ - count + other.size_;
			this->CheckCapacityAndReallocate(newSize);
			memcpy(temp_, other.data_, other.size_);
			memcpy(temp_ + other.size_, data_ + index + count, size_ - index - count);
			memcpy(data_ + index, temp_, newSize - index);
			this->SetNewSize(newSize);
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Replaces all characters from the specified start index with the specified c-string.
		/// @param[in] index The index from where to replace.
		/// \n If this index is greater or equal to the size of the Power::String, the method will return and nothing will be replaced.
		/// @param[in] other The c-string with which to replace.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Replace(size_t, const char) instead.
		/// @node <b>If the size of the c-string is already known, it is recommended to use Replace(size_t, const char* const, size_t) instead as it is faster.</b>
		/// @return A reference to the current Power::String.
		///
		inline String& Replace(size_t index, const char* const other) { return this->Replace(index, size_ - index, other, strlen(other)); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Replaces all characters from the specified start index with the specified c-string.
		/// @param[in] index The index from where to replace.
		/// \n If this index is greater or equal to the size of the Power::String, the method will return and nothing will be replaced.
		/// @param[in] count How many characters will be replaced.
		/// \n This value gets clamped to the size of the Power::String minus the specified index.
		/// @param[in] other The c-string with which to replace.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Replace(size_t, size_t, const char) instead.
		/// @node <b>If the size of the c-string is already known, it is recommended to use Replace(size_t, const char* const, size_t) instead as it is faster.</b>
		/// @return A reference to the current Power::String.
		///
		inline String& Replace(size_t index, size_t count, const char* const other) { return this->Replace(index, count, other, strlen(other)); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Replaces all characters from the specified start index with the specified c-string.
		/// @param[in] index The index from where to replace.
		/// \n If this index is greater or equal to the size of the Power::String, the method will return and nothing will be replaced.
		/// @param[in] other The c-string with which to replace.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Replace(size_t, const char) instead.
		/// @param[in] size The size of the c-string excluding the null character.
		/// @return A reference to the current Power::String.
		///
		inline String& Replace(size_t index, const char* const other, size_t size) { return this->Replace(index, size_ - index, other, size); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Replaces all characters from the specified start index with the specified c-string.
		/// @param[in] index The index from where to replace.
		/// \n If this index is greater or equal to the size of the Power::String, the method will return and nothing will be replaced.
		/// @param[in] count How many characters will be replaced.
		/// \n This value gets clamped to the size of the Power::String minus the specified index.
		/// @param[in] other The c-string with which to replace.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Replace(size_t, size_t, const char) instead.
		/// @param[in] size The size of the c-string excluding the null character.
		/// @return A reference to the current Power::String.
		///
		inline String& Replace(size_t index, size_t count, const char* const other, size_t size) {
			if (index >= size_) return *this;
			if (count > size_ - index) count = size_ - index;
			size_t newSize = size_ - count + size;
			this->CheckCapacityAndReallocate(newSize);
			int64_t offset = other - data_;
			if (this->PointerToSelf(offset)) memcpy(temp_, data_ + offset, size);
			else memcpy(temp_, other, size);
			memcpy(temp_ + size, data_ + index + count, size_ - index - count);
			memcpy(data_ + index, temp_, newSize - index);
			this->SetNewSize(newSize);
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Replaces all characters from the specified start index with the specified character.
		/// @param[in] index The index from where to replace.
		/// \n If this index is greater or equal to the size of the Power::String, the method will return and nothing will be replaced.
		/// @param[in] c The character with which to replace.
		/// @return A reference to the current Power::String.
		///
		inline String& Replace(size_t index, const char c) { return this->Replace(index, size_ - index, c); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Replaces a specified amount of characters from the specified start index with the specified character.
		/// @param[in] index The index from where to replace.
		/// \n If this index is greater or equal to the size of the Power::String, the method will return and nothing will be replaced.
		/// @param[in] count How many characters will be replaced.
		/// \n This value gets clamped to the size of the Power::String minus the specified index.
		/// @param[in] c The character with which to replace.
		/// @return A reference to the current Power::String.
		///
		inline String& Replace(size_t index, size_t count, const char c) {
			if (index >= size_) return *this;
			if (count > size_ - index) count = size_ - index;
			size_t newSize = size_ - count + 1;
			this->CheckCapacityAndReallocate(newSize);
			temp_[0] = c;
			memcpy(temp_ + 1, data_ + index + count, size_ - index - count);
			memcpy(data_ + index, temp_, newSize - index);
			this->SetNewSize(newSize);
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--ReplaceAt-->
		/// @brief Replaces the characters with the specified Power::String at the specified index.
		/// @param[in] index The index from where to replace.
		/// \n If this index is greater or equal to the size of the Power::String, the method will return and nothing will be replaced.
		/// @param[in] other The Power::String with which to replace.
		/// @return A reference to the current Power::String.
		///
		inline String& ReplaceAt(size_t index, const String& other) {
			if (index >= size_) return *this;
			size_t newSize = index + other.size_;
			this->CheckCapacityAndReallocate(newSize);
			this->MemCpyCheckData(index, other.data_, other.size_);
			if (newSize > size_) this->SetNewSize(newSize);
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Replaces the characters with the specified c-string at the specified index.
		/// @param[in] index The index from where to replace.
		/// \n If this index is greater or equal to the size of the Power::String, the method will return and nothing will be replaced.
		/// @param[in] other The c-string with which to replace.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use ReplaceAt(size_t, const char) instead.
		/// @node <b>If the size of the c-string is already known, it is recommended to use ReplaceAt(size_t, const char* const, size_t) instead as it is faster.</b>
		/// @return A reference to the current Power::String.
		///
		inline String& ReplaceAt(size_t index, const char* const other) { return  this->ReplaceAt(index, other, strlen(other)); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Replaces the characters with the specified c-string at the specified index.
		/// @param[in] index The index from where to replace.
		/// \n If this index is greater or equal to the size of the Power::String, the method will return and nothing will be replaced.
		/// @param[in] other The c-string with which to replace.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use ReplaceAt(size_t, const char) instead.
		/// @param[in] size The size of the c-string excluding the null character.
		/// @return A reference to the current Power::String.
		///
		inline String& ReplaceAt(size_t index, const char* const other, size_t size) {
			if (index >= size_) return *this;
			size_t newSize = index + size;
			int64_t offset = other - data_;
			this->CheckCapacityAndReallocate(newSize);
			if (this->PointerToSelf(offset)) {
				memcpy(temp_, data_ + offset, size);
				memcpy(data_ + index, temp_, size);
			} else
				memcpy(data_ + index, other, size);
			if (newSize > size_) this->SetNewSize(newSize);
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Replaces the character with the specified character at the specified index.
		/// @param[in] index The index at where to replace.
		/// \n If this index is greater or equal to the size of the Power::String, the method will return and nothing will be replaced.
		/// @param[in] c The character with which to replace.
		/// @return A reference to the current Power::String.
		///
		inline String& ReplaceAt(size_t index, const char c) {
			if (index >= size_) return *this;
			data_[index] = c;
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Trim-->
		/// @brief Removes all leading and trailing whitespaces.
		/// @return A reference to the current Power::String.
		///
		inline String& Trim() {
			this->TrimEnd(' ');
			this->TrimStart(' ');
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Removes all leading and trailing occurances of the specified character.
		/// @param[in] c The character to be trimmed.
		/// @return A reference to the current Power::String.
		///
		inline String& Trim(const char c) {
			this->TrimEnd(c);
			this->TrimStart(c);
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--TrimStart-->
		/// @brief Removes all leading whitespaces.
		/// @return A reference to the current Power::String.
		///
		inline String& TrimStart() { return this->TrimStart(' '); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Removes all leading occurances of the specified character.
		/// @param[in] c The character to be trimmed.
		/// @return A reference to the current Power::String.
		///
		inline String& TrimStart(const char c) {
			size_t startIndex = 0;
			for (size_t i = 0; i <= size_; ++i) {
				if (data_[i] != c) {
					startIndex = i;
					break;
				}
			}
			size_ = size_ - startIndex;
			memcpy(temp_, data_ + startIndex, size_);
			memcpy(data_, temp_, size_);
			data_[size_] = '\0';
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--TrimEnd-->
		/// @brief Removes all trailing whitespaces.
		/// @return A reference to the current Power::String.
		///
		inline String& TrimEnd() { return this->TrimEnd(' '); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Removes all trailing occurances of the specified character.
		/// @param[in] c The character to be trimmed.
		/// @return A reference to the current Power::String.
		///
		inline String& TrimEnd(const char c) {
			for (int32_t i = static_cast<int32_t>(size_) - 1; i >= 0; --i) {
				if (data_[i] != c) {
					this->SetNewSize(static_cast<size_t>(i + 1));
					break;
				} else if (i == 0) {
					this->SetNewSize(static_cast<size_t>(0));
					break;
				}
			}
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--PadLeft-->
		/// @brief Right-aligns the Power::String by filling it to the left with whitespaces to the specified total size.
		/// @param[in] size The total size the Power::String should be including the current size of the Power::String.
		/// \n If this value is less or equal to the size of the Power::String, this method will return without padding.
		/// @return A reference to the current Power::String.
		///
		inline String& PadLeft(size_t size) { return this->PadLeft(size, ' '); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Right-aligns the Power::String by filling it to the left with the specified character to the specified total size.
		/// @param[in] size The total size the Power::String should be including the current size of the Power::String.
		/// \n If this value is less or equal to the size of the Power::String, this method will return without padding.
		/// @param[in] c The character with which to fill.
		/// @return A reference to the current Power::String.
		///
		inline String& PadLeft(size_t size, char c) {
			if (size_ >= size) return *this;
			this->CheckCapacityAndReallocate(size);
			memset(temp_, c, size - size_);
			memcpy(temp_ + size - size_, data_, size_);
			memcpy(data_, temp_, size);
			this->SetNewSize(size);
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--PadRight-->
		/// @brief Left-aligns the Power::String by filling it to the right with whitespaces to the specified total size.
		/// @param[in] size The total size the Power::String should be including the current size of the Power::String.
		/// \n If this value is less or equal to the size of the Power::String, this method will return without padding.
		/// @return A reference to the current Power::String.
		///
		inline String& PadRight(size_t size) { return this->PadRight(size, ' '); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Left-aligns the Power::String by filling it to the right with the specified character to the specified total size.
		/// @param[in] size The total size the Power::String should be including the current size of the Power::String.
		/// \n If this value is less or equal to the size of the Power::String, this method will return without padding.
		/// @param[in] c The character with which to fill.
		/// @return A reference to the current Power::String.
		///
		inline String& PadRight(size_t size, char c) {
			if (size_ >= size) return *this;
			this->CheckCapacityAndReallocate(size);
			memset(data_ + size_, c, size - size_);
			this->SetNewSize(size);
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--StartsWith-->
		/// @brief Checks if the Power::String starts with the specified Power::String.
		/// @param[in] other The Power::String to check for.
		/// @return <span style="color:#30AA00">True</span>, if the Power::String starts with the specified Power::String.
		/// @return <span style="color:#CC3000">False</span>, if it doesn't, or if the size of the specified Power::String is greater than the size of the Power::String.
		///
		inline bool StartsWith(const String& other) const {
			if (other.size_ > size_ || other.size_ == 0) return false;
			return memcmp(data_, other.data_, other.size_) == 0;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Checks if the c-string starts with the specified Power::String.
		/// @param[in] other The c-string to check for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use StartsWith(const char) const instead.
		/// @return <span style="color:#30AA00">True</span>, if the Power::String starts with the specified c-string.
		/// @return <span style="color:#CC3000">False</span>, if it doesn't, or if the size of the specified c-string is greater than the size of the Power::String.
		/// @node <b>If the size of the c-string is already known, it is recommended to use StartsWith(const char* const, size_t) const instead as it is faster.</b>
		///
		inline bool StartsWith(const char* const other) const { return this->StartsWith(other, strlen(other)); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Checks if the c-string starts with the specified Power::String.
		/// @param[in] other The c-string to check for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use StartsWith(const char) const instead.
		/// @param[in] size The size of the c-string excluding the null character.
		/// @return <span style="color:#30AA00">True</span>, if the Power::String starts with the specified c-string.
		/// @return <span style="color:#CC3000">False</span>, if it doesn't, or if the size of the specified c-string is greater than the size of the Power::String.
		///
		inline bool StartsWith(const char* const other, size_t size) const {
			if (size > size_ || size == 0) return false;
			return memcmp(data_, other, size) == 0;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Checks if the character starts with the specified Power::String.
		/// @param[in] c The character to check for.
		/// @return <span style="color:#30AA00">True</span>, if the Power::String starts with the specified character.
		/// @return <span style="color:#CC3000">False</span>, if it doesn't, or if the size of the specified character is greater than the size of the Power::String.
		///
		inline bool StartsWith(const char c) const { return *data_ == c; }


		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--EndsWith-->
		/// @brief Checks if the Power::String ends with the specified Power::String.
		/// @param[in] other The Power::String to check for.
		/// @return <span style="color:#30AA00">True</span>, if the Power::String ends with the specified Power::String.
		/// @return <span style="color:#CC3000">False</span>, if it doesn't, or if the size of the specified Power::String is greater than the size of the Power::String.
		///
		inline bool EndsWith(const String& other) const {
			if (other.size_ > size_ || other.size_ == 0) return false;
			return memcmp(data_ + size_ - other.size_, other.data_, other.size_) == 0;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Checks if the c-string ends with the specified Power::String.
		/// @param[in] other The c-string to check for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use EndsWith(const char) const instead.
		/// @return <span style="color:#30AA00">True</span>, if the Power::String ends with the specified c-string.
		/// @return <span style="color:#CC3000">False</span>, if it doesn't, or if the size of the specified c-string is greater than the size of the Power::String.
		/// @node <b>If the size of the c-string is already known, it is recommended to use EndsWith(const char* const, size_t) const instead as it is faster.</b>
		///
		inline bool EndsWith(const char* const other) const { return this->EndsWith(other, strlen(other)); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Checks if the c-string ends with the specified Power::String.
		/// @param[in] other The c-string to check for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use EndsWith(const char) const instead.
		/// @param[in] size The size of the c-string excluding the null character.
		/// @return <span style="color:#30AA00">True</span>, if the Power::String ends with the specified c-string.
		/// @return <span style="color:#CC3000">False</span>, if it doesn't, or if the size of the specified c-string is greater than the size of the Power::String.
		///
		inline bool EndsWith(const char* const other, size_t size) const {
			if (size > size_ || size == 0) return false;
			return memcmp(data_ + size_ - size, other, size) == 0;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Checks if the character ends with the specified Power::String.
		/// @param[in] c The character to check for.
		/// @return <span style="color:#30AA00">True</span>, if the Power::String ends with the specified character.
		/// @return <span style="color:#CC3000">False</span>, if it doesn't, or if the size of the specified character is greater than the size of the Power::String.
		///
		inline bool EndsWith(const char c) const { return data_[size_ - 1] == c; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Fill-->
		/// @brief Fills the Power::String with the specified Power::String.
		/// @param[in] other The Power::String to fill with.
		/// @return A reference to the current Power::String.
		///
		inline String& Fill(const String& other) { return this->Fill(other, 0, size_); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Fills the Power::String with the specified Power::String starting from the specified index.
		/// @param[in] other The Power::String to fill with.
		/// @param[in] begin The index from where to start filling.
		/// \n If this index is greater or equal to the size of the Power::String, the method will return without filling.
		/// @return A reference to the current Power::String.
		///
		inline String& Fill(const String& other, size_t begin) { return this->Fill(other, begin, size_); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Fills the Power::String with the specified Power::String between the specified start and end index.
		/// @param[in] other The Power::String to fill with.
		/// @param[in] begin The index from where to start filling.
		/// \n If this index is greater or equal to the end index or the size of the Power::String, the method will return without filling.
		/// @param[in] end The index to where to stop filling.
		/// \n This index is clamped to the size of the Power::String.
		/// @return A reference to the current Power::String.
		///
		inline String& Fill(const String& other, size_t begin, size_t end) {
			if (end > size_) end = size_;
			if (begin >= end || other.size_ == 0) return *this;
			size_t range = end - begin;
			size_t count = range / other.size_;
			int64_t offset = other.data_ - data_;
			if (this->PointerToSelf(offset)) {
				for (size_t i = 0; i < count; ++i) memcpy(temp_ + i * other.size_, other.data_, other.size_);
				memcpy(temp_ + count * other.size_, other.data_, range % other.size_);
				memcpy(data_ + begin, temp_, range);
			} else {
				for (size_t i = 0; i < count; ++i) memcpy(data_ + begin + i * other.size_, other.data_, other.size_);
				memcpy(data_ + begin + count * other.size_, other.data_, range % other.size_);
			}
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Fills the Power::String with the specified c-string.
		/// @param[in] other The c-string to fill with.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Fill(const char) instead.
		/// @node <b>If the size of the c-string is already known, it is recommended to use Fill(size_t, const char* const) const instead as it is faster.</b>
		/// @return A reference to the current Power::String.
		///
		inline String& Fill(const char* const other) { return this->Fill(strlen(other), other, 0, size_); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Fills the Power::String with the specified c-string starting from the specified index.
		/// @param[in] other The c-string to fill with.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Fill(const char, size_t) instead.
		/// @param[in] begin The index from where to start filling.
		/// \n If this index is greater or equal to the size of the Power::String, the method will return without filling.
		/// @node <b>If the size of the c-string is already known, it is recommended to use Fill(size_t, const char* const, size_t) instead as it is faster.</b>
		/// @return A reference to the current Power::String.
		///
		inline String& Fill(const char* const other, size_t begin) { return this->Fill(strlen(other), other, begin, size_); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Fills the Power::String with the specified c-string between the specified start and end index.
		/// @param[in] other The c-string to fill with.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Fill(const char, size_t, size_t) instead.
		/// @param[in] begin The index from where to start filling.
		/// \n If this index is greater or equal to the end index or the size of the Power::String, the method will return without filling.
		/// @param[in] end The index to where to stop filling.
		/// \n This index is clamped to the size of the Power::String.
		/// @node <b>If the size of the c-string is already known, it is recommended to use Fill(size_t, const char* const, size_t, size_t) instead as it is faster.</b>
		/// @return A reference to the current Power::String.
		///
		inline String& Fill(const char* const other, size_t begin, size_t end) { return this->Fill(strlen(other), other, begin, end); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Fills the Power::String with the specified c-string.
		/// @param[in] size The size of the c-string excluding the null character.
		/// @param[in] other The c-string to fill with.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Fill(const char) instead.
		/// @return A reference to the current Power::String.
		///
		inline String& Fill(size_t size, const char* const other) { return this->Fill(size, other, 0, size_); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Fills the Power::String with the specified c-string starting from the specified index.
		/// @param[in] size The size of the c-string excluding the null character.
		/// @param[in] other The c-string to fill with.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Fill(const char, size_t) instead.
		/// @param[in] begin The index from where to start filling.
		/// \n If this index is greater or equal to the size of the Power::String, the method will return without filling.
		/// @return A reference to the current Power::String.
		///
		inline String& Fill(size_t size, const char* const other, size_t begin) { return this->Fill(size, other, begin, size_); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Fills the Power::String with the specified c-string between the specified start and end index.
		/// @param[in] size The size of the c-string excluding the null character.
		/// @param[in] other The c-string to fill with.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Fill(const char, size_t, size_t) instead.
		/// @param[in] begin The index from where to start filling.
		/// \n If this index is greater or equal to the end index or the size of the Power::String, the method will return without filling.
		/// @param[in] end The index to where to stop filling.
		/// \n This index is clamped to the size of the Power::String.
		/// @return A reference to the current Power::String.
		///
		inline String& Fill(size_t size, const char* const other, size_t begin, size_t end) {
			if (end > size_) end = size_;
			if (begin >= end || size == 0) return *this;
			size_t range = end - begin;
			size_t count = range / size;
			int64_t offset = other - data_;
			if (this->PointerToSelf(offset)) {
				for (size_t i = 0; i < count; ++i) memcpy(temp_ + i * size, other, size);
				memcpy(temp_ + count * size, other, range % size);
				memcpy(data_ + begin, temp_, range);
			} else {
				for (size_t i = 0; i < count; ++i) memcpy(data_ + begin + i * size, other, size);
				memcpy(data_ + begin + count * size, other, range % size);
			}
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Fills the Power::String with the specified character.
		/// @param[in] c The character to fill with.
		/// @return A reference to the current Power::String.
		///
		inline String& Fill(const char c) { memset(data_, c, size_); return *this; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Fills the Power::String with the specified character starting from the specified index.
		/// @param[in] c The character to fill with.
		/// @param[in] begin The index from where to start filling.
		/// \n If this index is greater or equal to the size of the Power::String, the method will return without filling.
		/// @return A reference to the current Power::String.
		///
		inline String& Fill(const char c, size_t begin) {
			if (begin >= size_) return *this;
			memset(data_ + begin, c, size_ - begin);
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Fills the Power::String with the specified character between the specified start and end index.
		/// @param[in] c The character to fill with.
		/// @param[in] begin The index from where to start filling.
		/// \n If this index is greater or equal to the end index or the size of the Power::String, the method will return without filling.
		/// @param[in] end The index to where to stop filling.
		/// \n This index is clamped to the size of the Power::String.
		/// @return A reference to the current Power::String.
		///
		inline String& Fill(const char c, size_t begin, size_t end) {
			if (end > size_) end = size_;
			if (begin >= end) return *this;
			memset(data_ + begin, c, end - begin);
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--SplitAt-->
		/// @brief Splits the Power::String into two substrings at the specified index.
		/// @param[in] index The index at where to split.
		/// \n If this index is greater than the size of the Power::String, the method will return wihout filling lhs and rhs.
		/// @param[out] lhs A Power::String containing the left-hand part from index.
		/// @param[out] rhs A Power::String containing the right-hand part from index.
		///
		inline void SplitAt(size_t index, String& lhs, String& rhs) const {
			if (index > size_) return;
			lhs = String(data_, index);
			rhs = String(data_ + index, size_ - index);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--ToLower-->
		/// @brief Converts all upper case characters to lower case.
		/// @return A reference to the current Power::String.
		///
		inline String& ToLower() { _strlwr_s(data_, size_ + 1); return *this; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--ToUpper-->
		/// @brief Converts all lower case characters to upper case.
		/// @return A reference to the current Power::String.
		///
		inline String& ToUpper() { _strupr_s(data_, size_ + 1); return *this; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Destructor-->
		/// @brief Frees all allocated memory of the Power::String.
		///
		~String() {
			free(data_);
			--s_instanceCounter_;
		}

	private:
		String(const String& lhs, const String& rhs) :
			capacity_(lhs.size_ + rhs.size_ + 1),
			size_(lhs.size_ + rhs.size_),
			data_(static_cast<char*>(malloc(capacity_ * 2))),
			temp_(data_ + capacity_)
		{
			memcpy(data_, lhs.data_, lhs.size_);
			memcpy(data_ + lhs.size_, rhs.data_, rhs.size_);
			data_[size_] = '\0';
			this->IncInstCounter();
		}
		String(const String& lhs, const char* const rhs) :
			capacity_(0),
			size_(0),
			data_(nullptr),
			temp_(nullptr)
		{
			size_t rhsSize = strlen(rhs);
			size_ = lhs.size_ + rhsSize;
			capacity_ = size_ + 1;
			data_ = static_cast<char*>(malloc(capacity_ * 2));
			this->IncInstCounter();
			temp_ = data_ + capacity_;
			memcpy(data_, lhs.data_, lhs.size_);
			memcpy(data_ + lhs.size_, rhs, rhsSize);
			data_[size_] = '\0';
		}
		String(const char* const lhs, const String& rhs) :
			capacity_(0),
			size_(0),
			data_(nullptr),
			temp_(nullptr)
		{
			size_t lhsSize = strlen(lhs);
			size_ = rhs.size_ + lhsSize;
			capacity_ = size_ + 1;
			data_ = static_cast<char*>(malloc(capacity_ * 2));
			this->IncInstCounter();
			temp_ = data_ + capacity_;
			memcpy(data_, lhs, lhsSize);
			memcpy(data_ + lhsSize, rhs.data_, rhs.size_);
			data_[size_] = '\0';
		}
		String(const String& lhs, const char rhs) :
			capacity_(lhs.size_ + 2),
			size_(lhs.size_ + 1),
			data_(static_cast<char*>(malloc(capacity_ * 2))),
			temp_(data_ + capacity_)
		{
			memcpy(data_, lhs.data_, lhs.size_);
			data_[lhs.size_] = rhs;
			data_[size_] = '\0';
			this->IncInstCounter();
		}
		String(const char lhs, const String& rhs) :
			capacity_(rhs.size_ + 2),
			size_(rhs.size_ + 1),
			data_(static_cast<char*>(malloc(capacity_ * 2))),
			temp_(data_ + capacity_)
		{
			data_[0] = lhs;
			memcpy(data_ + 1, rhs.data_, rhs.size_);
			data_[size_] = '\0';
			this->IncInstCounter();
		}
		String(const String& lhs, const int16_t rhs) :
			capacity_(0),
			size_(0),
			data_(nullptr),
			temp_(nullptr)
		{
			char buffer[INT16_MAX_CHR_COUNT];
			snprintf(buffer, INT16_MAX_CHR_COUNT, "%hd", rhs);
			size_t rhsSize = strlen(buffer);
			size_ = lhs.size_ + rhsSize;
			capacity_ = size_ + 1;
			data_ = static_cast<char*>(malloc(capacity_ * 2));
			temp_ = data_ + capacity_;
			memcpy(data_, lhs.data_, lhs.size_);
			memcpy(data_ + lhs.size_, buffer, rhsSize);
			data_[size_] = '\0';
			this->IncInstCounter();
		}
		String(const String& lhs, const uint16_t rhs) :
			capacity_(0),
			size_(0),
			data_(nullptr),
			temp_(nullptr)
		{
			char buffer[UINT16_MAX_CHR_COUNT];
			snprintf(buffer, UINT16_MAX_CHR_COUNT, "%hu", rhs);
			size_t rhsSize = strlen(buffer);
			size_ = lhs.size_ + rhsSize;
			capacity_ = size_ + 1;
			data_ = static_cast<char*>(malloc(capacity_ * 2));
			temp_ = data_ + capacity_;
			memcpy(data_, lhs.data_, lhs.size_);
			memcpy(data_ + lhs.size_, buffer, rhsSize);
			data_[size_] = '\0';
			this->IncInstCounter();
		}
		String(const String& lhs, const int32_t rhs) :
			capacity_(0),
			size_(0),
			data_(nullptr),
			temp_(nullptr)
		{
			char buffer[INT32_MAX_CHR_COUNT];
			snprintf(buffer, INT32_MAX_CHR_COUNT, "%d", rhs);
			size_t rhsSize = strlen(buffer);
			size_ = lhs.size_ + rhsSize;
			capacity_ = size_ + 1;
			data_ = static_cast<char*>(malloc(capacity_ * 2));
			temp_ = data_ + capacity_;
			memcpy(data_, lhs.data_, lhs.size_);
			memcpy(data_ + lhs.size_, buffer, rhsSize);
			data_[size_] = '\0';
			this->IncInstCounter();
		}
		String(const String& lhs, const uint32_t rhs) :
			capacity_(0),
			size_(0),
			data_(nullptr),
			temp_(nullptr)
		{
			char buffer[UINT32_MAX_CHR_COUNT];
			snprintf(buffer, UINT32_MAX_CHR_COUNT, "%u", rhs);
			size_t rhsSize = strlen(buffer);
			size_ = lhs.size_ + rhsSize;
			capacity_ = size_ + 1;
			data_ = static_cast<char*>(malloc(capacity_ * 2));
			temp_ = data_ + capacity_;
			memcpy(data_, lhs.data_, lhs.size_);
			memcpy(data_ + lhs.size_, buffer, rhsSize);
			data_[size_] = '\0';
			this->IncInstCounter();
		}
		String(const String& lhs, const int64_t rhs) :
			capacity_(0),
			size_(0),
			data_(nullptr),
			temp_(nullptr)
		{
			char buffer[INT64_MAX_CHR_COUNT];
			snprintf(buffer, INT64_MAX_CHR_COUNT, "%lld", rhs);
			size_t rhsSize = strlen(buffer);
			size_ = lhs.size_ + rhsSize;
			capacity_ = size_ + 1;
			data_ = static_cast<char*>(malloc(capacity_ * 2));
			temp_ = data_ + capacity_;
			memcpy(data_, lhs.data_, lhs.size_);
			memcpy(data_ + lhs.size_, buffer, rhsSize);
			data_[size_] = '\0';
			this->IncInstCounter();
		}
		String(const String& lhs, const uint64_t rhs) :
			capacity_(0),
			size_(0),
			data_(nullptr),
			temp_(nullptr)
		{
			char buffer[UINT64_MAX_CHR_COUNT];
			snprintf(buffer, UINT64_MAX_CHR_COUNT, "%llu", rhs);
			size_t rhsSize = strlen(buffer);
			size_ = lhs.size_ + rhsSize;
			capacity_ = size_ + 1;
			data_ = static_cast<char*>(malloc(capacity_ * 2));
			temp_ = data_ + capacity_;
			memcpy(data_, lhs.data_, lhs.size_);
			memcpy(data_ + lhs.size_, buffer, rhsSize);
			data_[size_] = '\0';
			this->IncInstCounter();
		}
		String(const String& lhs, const float rhs) :
			capacity_(0),
			size_(0),
			data_(nullptr),
			temp_(nullptr)
		{
			char buffer[FLOAT_MAX_CHR_COUNT];
			snprintf(buffer, FLOAT_MAX_CHR_COUNT, "%g", rhs);
			size_t rhsSize = strlen(buffer);
			size_ = lhs.size_ + rhsSize;
			capacity_ = size_ + 1;
			data_ = static_cast<char*>(malloc(capacity_ * 2));
			temp_ = data_ + capacity_;
			memcpy(data_, lhs.data_, lhs.size_);
			memcpy(data_ + lhs.size_, buffer, rhsSize);
			data_[size_] = '\0';
			this->IncInstCounter();
		}
		String(const String& lhs, const double rhs) :
			capacity_(0),
			size_(0),
			data_(nullptr),
			temp_(nullptr)
		{
			char buffer[DOUBLE_MAX_CHR_COUNT];
			snprintf(buffer, DOUBLE_MAX_CHR_COUNT, "%g", rhs);
			size_t rhsSize = strlen(buffer);
			size_ = lhs.size_ + rhsSize;
			capacity_ = size_ + 1;
			data_ = static_cast<char*>(malloc(capacity_ * 2));
			temp_ = data_ + capacity_;
			memcpy(data_, lhs.data_, lhs.size_);
			memcpy(data_ + lhs.size_, buffer, rhsSize);
			data_[size_] = '\0';
			this->IncInstCounter();
		}
		String(FILE* fp, const char* const filePath) :
			capacity_(0),
			size_(0),
			data_(nullptr),
			temp_(nullptr)
		{
			if (!fopen_s(&fp, filePath, "r")) {
				fseek(fp, 0, SEEK_END);
				size_ = ftell(fp);
				capacity_ = size_ + s_defaultCapacity;
				fseek(fp, 0, 0);
				data_ = static_cast<char*>(malloc(capacity_ * 2));
				this->IncInstCounter();
				temp_ = data_ + capacity_;
				fread_s(data_, size_, 1, size_, fp);
				fclose(fp);
				data_[size_] = '\0';
			}
		}

		inline void IncInstCounter() const {
			++s_instanceCounter_;
			++s_totalInstancesCreated_;
		}

		inline void SetNewSize(size_t newSize) {
			data_[newSize] = '\0';
			size_ = newSize;
		}

		inline void CheckCapacityAndReallocate(size_t newSize) {
			if (newSize < capacity_) return;
			capacity_ = capacity_ * 2 + newSize;
			data_ = static_cast<char*>(realloc(data_, capacity_ * 2));
			temp_ = data_ + capacity_;
		}

		inline bool PointerToSelf(int64_t offset) const { return offset >= 0 && offset < static_cast<int64_t>(size_); }

		inline void MemCpyCheckData(size_t index, const char* source, size_t size) const {
			int64_t offset = source - data_;
			if (!this->PointerToSelf(offset)) memcpy(data_ + index, source, size);
			else {
				memcpy(temp_, data_ + offset, size);
				memcpy(data_ + index, temp_, size);
			}
		}

	public:
		static size_t s_defaultCapacity;			///< Default capacity of the string.
		static size_t s_instanceCounter_;			///< Current count of instances.
		static size_t s_totalInstancesCreated_;		///< Total amount of created instances.

	private:
		size_t capacity_;
		size_t size_;
		char* data_;
		char* temp_;
	};
}
