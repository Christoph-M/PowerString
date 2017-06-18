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
	///
	class String {
	public:
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--ToString-->
		/// @brief Converts a c-string to a Power::String.
		/// @param[in] other The c-string to be converted.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use ToString(const char) instead.
		/// @return A Power::String with the content of other.
		/// @note <b>If the length of the c-string is already known, it is recommended to use ToString(const char* const, size_t) instead as it is faster.</b>
		///
		static String ToString(const char* const other) { return String(other); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Converts a c-string to a Power::String.
		/// @param[in] other The c-string to be converted.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use ToString(const char) instead.
		/// @param[in] length The length of the c-string excluding the null character.
		/// @return A Power::String with the content of other.
		///
		static String ToString(const char* const other, size_t length) { return String(other, length); }

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
		/// @brief Merges a Power::String with a character.
		/// @param[in] lhs Left-hand side of the merged Power::String.
		/// @param[in] rhs Right-hand side of the merged Power::String.
		/// @return A Power::String containing lhs+rhs.
		///
		inline static String Merge(const String& lhs, const char rhs) { return String(lhs, rhs); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Join-->
		/// @brief Merges multiple Power::Strings with the specified seperator between each Power::String.
		/// @param[in] space The seperator which will be placed between each Power::String.
		/// @param[in] others A pointer to an array of Power::Strings to be merged.
		/// @param[in] size The size of the specified Power::String array.
		/// @return A Power::String containing the merged Power::Strings.
		///
		inline static String Join(const String& space, const String* const others, size_t size) {
			size_t totalLength = (size - 1) * space.length_;
			for (size_t i = 0; i < size; ++i) totalLength += others[i].length_;
			String newString = String("", totalLength);
			memcpy(newString.data_, others[0].data_, others[0].length_);
			char* data = newString.data_ + others[0].length_ + space.length_;
			for (size_t i = 1; i < size; ++i) {
				memcpy(data, others[i].data_, others[i].length_);
				memcpy(data - space.length_, space.data_, space.length_);
				data += others[i].length_ + space.length_;
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
		/// @note <b>If the length of the c-string parameter space is already known, it is recommended to use Join(const char* const, size_t, const String* const, size_t) instead as it is faster</b>
		///
		inline static String Join(const char* const space, const String* const others, size_t size) { return String::Join(space, strlen(space), others, size); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges multiple Power::Strings with the specified seperator between each Power::String.
		/// @param[in] space The seperator which will be placed between each Power::String.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Join(const char, const String* const, size_t) instead.
		/// @param[in] spaceLength The length of the c-string parameter space excluding the null character.
		/// @param[in] others A pointer to an array of Power::Strings to be merged.
		/// @param[in] size The size of the specified Power::String array.
		/// @return A Power::String containing the merged Power::Strings.
		///
		inline static String Join(const char* const space, size_t spaceLength, const String* const others, size_t size) {
			size_t totalLength = (size - 1) * spaceLength;
			for (size_t i = 0; i < size; ++i) totalLength += others[i].length_;
			String newString = String("", totalLength);
			memcpy(newString.data_, others[0].data_, others[0].length_);
			char* data = newString.data_ + others[0].length_ + spaceLength;
			for (size_t i = 1; i < size; ++i) {
				memcpy(data, others[i].data_, others[i].length_);
				memcpy(data - spaceLength, space, spaceLength);
				data += others[i].length_ + spaceLength;
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
			size_t totalLength = size - 1;
			for (size_t i = 0; i < size; ++i) totalLength += others[i].length_;
			String newString = String(c, totalLength);
			char* data = newString.data_;
			for (size_t i = 0; i < size; ++i) {
				memcpy(data, others[i].data_, others[i].length_);
				data += others[i].length_ + 1;
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
			size_t totalLength = (size - 1) * space.length_;
			for (size_t i = 0; i < size; ++i) totalLength += strlen(others[i]);
			String newString = String("", totalLength);
			size_t otherLength = strlen(others[0]);
			memcpy(newString.data_, others[0], otherLength);
			char* data = newString.data_ + otherLength + space.length_;
			for (size_t i = 1; i < size; ++i) {
				otherLength = strlen(others[i]);
				memcpy(data, others[i], otherLength);
				memcpy(data - space.length_, space.data_, space.length_);
				data += otherLength + space.length_;
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
		/// @note <b>If the length of the c-string parameter space is already known, it is recommended to use Join(const char* const, size_t, const char* const* const, size_t) instead as it is faster</b>
		///
		inline static String Join(const char* const space, const char* const* const others, size_t size) { return String::Join(space, strlen(space), others, size); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges multiple c-strings with the specified seperator between each Power::String.
		/// @param[in] space The seperator which will be placed between each c-strings.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Join(const char, const char* const* const, size_t) instead.
		/// @param[in] spaceLength The length of the c-string parameter space excluding the null character.
		/// @param[in] others A pointer to an array of c-string to be merged.
		/// @param[in] size The size of the specified c-string array.
		/// @return A Power::String containing the merged c-strings.
		///
		inline static String Join(const char* const space, size_t spaceLength, const char* const* const others, size_t size) {
			size_t totalLength = (size - 1) * spaceLength;
			for (size_t i = 0; i < size; ++i) totalLength += strlen(others[i]);
			String newString = String("", totalLength);
			size_t otherLength = strlen(others[0]);
			memcpy(newString.data_, others[0], otherLength);
			char* data = newString.data_ + otherLength + spaceLength;
			for (size_t i = 1; i < size; ++i) {
				otherLength = strlen(others[i]);
				memcpy(data, others[i], otherLength);
				memcpy(data - spaceLength, space, spaceLength);
				data += otherLength + spaceLength;
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
			size_t totalLength = size - 1;
			for (size_t i = 0; i < size; ++i) totalLength += strlen(others[i]);
			String newString = String(c, totalLength);
			char* data = newString.data_;
			for (size_t i = 0; i < size; ++i) {
				size_t otherLength = strlen(others[i]);
				memcpy(data, others[i], otherLength);
				data += otherLength + 1;
			}
			return newString;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--SplitStringAt-->
		/// @brief Splits a Power::String into two substrings at the specified index.
		/// @param[in] source The Power::String to be split.
		/// @param[in] index The position where source should be split.
		/// \n If this index is greater than the length of the source Power::String, the method will return wihout filling lhs and rhs.
		/// @param[out] lhs A Power::String containing the left-hand part from index.
		/// @param[out] rhs A Power::String containing the right-hand part from index.
		///
		inline static void SplitStringAt(const String& source, size_t index, String& lhs, String& rhs) {
			if (index > source.length_) return;
			lhs = String(source.data_, index);
			rhs = String(source.data_ + index, source.length_ - index);
		}

	public:
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Constructors-->
		/// @brief Initializes a new Power::String with the default capacity.
		///
		String() :
			size_(s_defaultCapacity),
			length_(0),
			data_(static_cast<char*>(malloc(size_ * 2))),
			temp_(data_ + size_)
		{
			*data_ = '\0';
			this->IncInstCounter();
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Initializes a new Power::String with the specified capacity.
		/// @param[in] size The capacity the new Power::String shall have.
		///
		explicit String(size_t size) :
			size_(size + 1),
			length_(0),
			data_(static_cast<char*>(malloc(size_ * 2))),
			temp_(data_ + size_)
		{
			*data_ = '\0';
			this->IncInstCounter();
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Initializes a new Power::String containing the specified c-string.
		/// @param[in] data The c-string with the data.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use String(const char) instead.
		/// @note Implicit conversion constructor. Direct assignment of c-string possible.
		/// @note <b>If the length of the c-string is already known, it is recommended to use String(const char* const, size_t) instead as it is faster</b>
		///
		String(const char* const data) :
			size_(0),
			length_(0),
			data_(nullptr),
			temp_(nullptr)
		{
			length_ = strlen(data);
			size_ = length_ + s_defaultCapacity;
			data_ = static_cast<char*>(malloc(size_ * 2));
			this->IncInstCounter();
			temp_ = data_ + size_;
			memcpy(data_, data, length_);
			data_[length_] = '\0';
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Initializes a new Power::String containing the specified character.
		/// @param[in] c The character.
		/// @note Implicit conversion constructor. Direct assignment of character possible.
		///
		String(const char c) :
			size_(s_defaultCapacity),
			length_(1),
			data_(static_cast<char*>(malloc(size_ * 2))),
			temp_(data_ + size_)
		{
			*data_ = c;
			data_[1] = '\0';
			this->IncInstCounter();
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Initializes a new Power::String containing the specified c-string.
		/// @param[in] data The c-string with the data.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use String(const char) instead.
		/// @param[in] length The length of the c-string excluding the null character.
		///
		String(const char* const data, size_t length) :
			size_(length + s_defaultCapacity),
			length_(length),
			data_(static_cast<char*>(malloc(size_ * 2))),
			temp_(data_ + size_)
		{
			memcpy(data_, data, length_);
			data_[length_] = '\0';
			this->IncInstCounter();
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Initializes a new Power::String and fills it to the specified length with the specified character.
		/// @param[in] c The character to fill with.
		/// @param[in] length The length of the new Power::String.
		///
		String(const char c, size_t length) :
			size_(length + s_defaultCapacity),
			length_(length),
			data_(static_cast<char*>(malloc(size_ * 2))),
			temp_(data_ + size_)
		{
			memset(data_, c, length_);
			data_[length_] = '\0';
			this->IncInstCounter();
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Initializes a copy of the specified Power::String.
		/// @param[in] other The Power::String to copy.
		///
		String(const String& other) :
			size_(other.size_),
			length_(other.length_),
			data_(static_cast<char*>(malloc(size_ * 2))),
			temp_(data_ + size_)
		{
			memcpy(data_, other.data_, other.length_);
			data_[length_] = '\0';
			this->IncInstCounter();
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Assignment operators-->
		/// @brief TODO: Document
		///
		inline void operator=(const String& other) {
			this->CheckSizeAndReallocate(other.length_);
			memcpy(data_, other.data_, other.length_);
			this->SetNewLength(other.length_);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief TODO: Document
		///
		inline void operator=(const char* const other) {
			size_t newLength = strlen(other);
			int64_t offset = other - data_;
			this->CheckSizeAndReallocate(newLength);
			if (offset >= 0 && offset < static_cast<int>(length_)) {
				memcpy(temp_, data_ + offset, newLength);
				memcpy(data_, temp_, newLength);
			} else 
				memcpy(data_, other, newLength);
			this->SetNewLength(newLength);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief TODO: Document
		///
		inline void operator=(const char c) {
			this->CheckSizeAndReallocate(1);
			*data_ = c;
			this->SetNewLength(1);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Addition operators-->
		/// @brief TODO: Document
		///
		inline String operator+(const String& other) const { return String(*this, other); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief TODO: Document
		///
		inline String operator+(const char* const other) const { return String(*this, other); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief TODO: Document
		///
		inline String operator+(const char c) const { return String(*this, c); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief TODO: Document
		///
		inline String operator+(const int16_t value) const { return String(*this, value); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief TODO: Document
		///
		inline String operator+(const uint16_t value) const { return String(*this, value); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief TODO: Document
		///
		inline String operator+(const int32_t value) const { return String(*this, value); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief TODO: Document
		///
		inline String operator+(const uint32_t value) const { return String(*this, value); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief TODO: Document
		///
		inline String operator+(const int64_t value) const { return String(*this, value); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief TODO: Document
		///
		inline String operator+(const uint64_t value) const { return String(*this, value); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief TODO: Document
		///
		inline String operator+(const float value) const { return String(*this, value); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief TODO: Document
		///
		inline String operator+(const double value) const { return String(*this, value); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Compound addition operators-->
		/// @brief TODO: Document
		///
		inline void operator+=(const String& other) { this->Concatenate(other); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief TODO: Document
		///
		inline void operator+=(const char* const other) { this->Concatenate(other, strlen(other)); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief TODO: Document
		///
		inline void operator+=(const char c) { this->Concatenate(c); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief TODO: Document
		///
		inline void operator+=(const int16_t value) {
			char buffer[INT16_MAX_CHR_COUNT];
			snprintf(buffer, INT16_MAX_CHR_COUNT, "%hd", value);
			size_t otherLength = strlen(buffer);
			size_t newLength = length_ + otherLength;
			this->CheckSizeAndReallocate(newLength);
			memcpy(data_ + length_, buffer, otherLength + 1);
			length_ = newLength;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief TODO: Document
		///
		inline void operator+=(const uint16_t value) {
			char buffer[UINT16_MAX_CHR_COUNT];
			snprintf(buffer, UINT16_MAX_CHR_COUNT, "%hu", value);
			size_t otherLength = strlen(buffer);
			size_t newLength = length_ + otherLength;
			this->CheckSizeAndReallocate(newLength);
			memcpy(data_ + length_, buffer, otherLength + 1);
			length_ = newLength;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief TODO: Document
		///
		inline void operator+=(const int32_t value) {
			char buffer[INT32_MAX_CHR_COUNT];
			snprintf(buffer, INT32_MAX_CHR_COUNT, "%d", value);
			size_t otherLength = strlen(buffer);
			size_t newLength = length_ + otherLength;
			this->CheckSizeAndReallocate(newLength);
			memcpy(data_ + length_, buffer, otherLength + 1);
			length_ = newLength;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief TODO: Document
		///
		inline void operator+=(const uint32_t value) {
			char buffer[UINT32_MAX_CHR_COUNT];
			snprintf(buffer, UINT32_MAX_CHR_COUNT, "%u", value);
			size_t otherLength = strlen(buffer);
			size_t newLength = length_ + otherLength;
			this->CheckSizeAndReallocate(newLength);
			memcpy(data_ + length_, buffer, otherLength + 1);
			length_ = newLength;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief TODO: Document
		///
		inline void operator+=(const int64_t value) {
			char buffer[INT64_MAX_CHR_COUNT];
			snprintf(buffer, INT64_MAX_CHR_COUNT, "%lld", value);
			size_t otherLength = strlen(buffer);
			size_t newLength = length_ + otherLength;
			this->CheckSizeAndReallocate(newLength);
			memcpy(data_ + length_, buffer, otherLength + 1);
			length_ = newLength;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief TODO: Document
		///
		inline void operator+=(const uint64_t value) {
			char buffer[UINT64_MAX_CHR_COUNT];
			snprintf(buffer, UINT64_MAX_CHR_COUNT, "%llu", value);
			size_t otherLength = strlen(buffer);
			size_t newLength = length_ + otherLength;
			this->CheckSizeAndReallocate(newLength);
			memcpy(data_ + length_, buffer, otherLength + 1);
			length_ = newLength;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief TODO: Document
		///
		inline void operator+=(const float value) {
			char buffer[FLOAT_MAX_CHR_COUNT];
			snprintf(buffer, FLOAT_MAX_CHR_COUNT, "%g", value);
			size_t otherLength = strlen(buffer);
			size_t newLength = length_ + otherLength;
			this->CheckSizeAndReallocate(newLength);
			memcpy(data_ + length_, buffer, otherLength + 1);
			length_ = newLength;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief TODO: Document
		///
		inline void operator+=(const double value) {
			char buffer[DOUBLE_MAX_CHR_COUNT];
			snprintf(buffer, DOUBLE_MAX_CHR_COUNT, "%g", value);
			size_t otherLength = strlen(buffer);
			size_t newLength = length_ + otherLength;
			this->CheckSizeAndReallocate(newLength);
			memcpy(data_ + length_, buffer, otherLength + 1);
			length_ = newLength;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Bitwise left shift operators-->
		/// @brief TODO: Document behaviour when using pointer to self.
		///
		inline String& operator<<(const String& other) { return this->Concatenate(other); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief TODO: Document
		///
		inline String& operator<<(const char* const other) { return this->Concatenate(other, strlen(other)); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief TODO: Document
		///
		inline String& operator<<(const char c) { return this->Concatenate(c); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Subscript operator-->
		/// @brief TODO: Document
		///
		inline char operator[](size_t i) const { return *(data_ + i); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Cast operator-->
		/// @brief TODO: Document
		///
		inline operator const char*() const { return data_; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Comparison equal operators-->
		/// @brief TODO: Document
		///
		inline bool operator==(const String& other) const { return length_ == other.length_ && memcmp(data_, other.data_, other.length_) == 0; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief TODO: Document
		///
		inline bool operator==(const char* const other) const { return strcmp(data_, other) == 0; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief TODO: Document
		///
		inline bool operator==(const char c) const { return length_ == 1 && *data_ == c; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Comparison not equal operators-->
		/// @brief TODO: Document
		///
		inline bool operator!=(const String& other) const { return length_ != other.length_ || memcmp(data_, other.data_, other.length_) != 0; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief TODO: Document
		///
		inline bool operator!=(const char* const other) const { return strcmp(data_, other) != 0; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief TODO: Document
		///
		inline bool operator!=(const char c) const { return length_ > 1 || *data_ != c; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Size-->
		/// @brief Gets the current total number of array elements of the Power::String.
		/// @return The current total number of array elements of the Power::String.
		///
		inline size_t Size() const { return size_; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Capacity-->
		/// @brief Gets the current maximum capacity of the Power::String which is Size() - 1.
		/// @return The current maximum capacity of the Power::String.
		///
		inline size_t Capacity() const { return size_ - 1; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Length-->
		/// @brief Gets the current length excluding the null character of the Power::String.
		/// @return The current length excluding the null character of the Power::String.
		///
		inline size_t Length() const { return length_; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--CString-->
		/// @brief Gets the underlying c-string as a constant.
		/// @return The underlying c-string as a constant.
		///
		inline const char* CString() const { return data_; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--ShrinkToFit-->
		/// @brief Shrinks the capacity of the Power::String to fit the length to conserve memory.
		///
		inline void ShrinkToFit() {
			if (length_ + 1 == size_) return;
			size_ = length_ + 1;
			data_ = static_cast<char*>(realloc(data_, size_ * 2));
			temp_ = data_ + size_;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Concatenate-->
		/// @brief Merges the Power::String with another Power::String.
		/// @param[in] other The Power::String to be merged with.
		/// @return A reference to the current Power::String.
		///
		inline String& Concatenate(const String& other) {
			size_t newLength = length_ + other.length_;
			this->CheckSizeAndReallocate(newLength);
			memcpy(data_ + length_, other.data_, other.length_);
			this->SetNewLength(newLength);
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges the Power::String with a c-string.
		/// @param[in] other The c-string to be merged with.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Concatenate(const char) instead.
		/// @note <b>If the length of the c-string is already known, it is recommend to use Concatenate(const char* const, size_t) instead as it is faser.</b>
		/// @return A reference to the current Power::String.
		///
		inline String& Concatenate(const char* const other) { return this->Concatenate(other, strlen(other)); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges the Power::String with a c-string.
		/// @param[in] other The c-string to be merged with.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Concatenate(const char) instead.
		/// @param[in] length The length of the c-string excluding the null character.
		/// @return A reference to the current Power::String.
		///
		inline String& Concatenate(const char* const other, size_t length) {
			int64_t offset = other - data_;
			size_t newLength = length_ + length;
			this->CheckSizeAndReallocate(newLength);
			if (offset >= 0 && offset < static_cast<int>(length_)) memcpy(data_ + length_, data_ + offset, length);
			else memcpy(data_ + length_, other, length);
			this->SetNewLength(newLength);
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges the Power::String with a character.
		/// @param[in] c The character to be merged with.
		/// @return A reference to the current Power::String.
		///
		inline String& Concatenate(const char c) {
			this->CheckSizeAndReallocate(++length_);
			data_[length_ - 1] = c;
			data_[length_] = '\0';
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Contains-->
		/// @brief Checks the Power::String if it contains the specified Power::String.
		/// @param[in] other The Power::String to be checked for.
		/// @return <span style="color:#30AA00">True</span>, if the Power::String contains the spcified Power::String.
		/// @return <span style="color:#CC3000">False</span>, if it doesn't or if the length of the specified Power::String is greater than the Power::String.
		///
		inline bool Contains(const String& other) const { return this->IndexOf(other) >= 0; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Checks the Power::String if it contains the specified c-string.
		/// @param[in] other The c-string to be checked for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Contains(const char) const instead.
		/// @return <span style="color:#30AA00">True</span>, if the Power::String contains the spcified c-string.
		/// @return <span style="color:#CC3000">False</span>, if it doesn't or if the length of the specified c-string is greater than the Power::String.
		/// @note <b>If the length of the c-string is already known, it is recommended to use Contains(const char* const, size_t) const instead as it is faster.</b>
		///
		inline bool Contains(const char* const other) const { return this->IndexOf(strlen(other), other) >= 0; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Checks the Power::String if it contains the specified c-string.
		/// @param[in] other The c-string to be checked for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Contains(const char) const instead.
		/// @param[in] length The length of the c-string excluding the null character.
		/// @return <span style="color:#30AA00">True</span>, if the Power::String contains the spcified c-string.
		/// @return <span style="color:#CC3000">False</span>, if it doesn't or if the length of the specified c-string is greater than the Power::String.
		///
		inline bool Contains(const char* const other, size_t length) const { return this->IndexOf(length, other) >= 0; }

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
		inline int IndexOf(const String& other) const {
			if (other.length_ > length_) return -1;
			char* p = strstr(data_, other.data_);
			return p ? static_cast<int>(p - data_) : -1;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the first occurance of the specified Power::String starting from the specified index.
		/// @param[in] other The Power::String to look for.
		/// @param[in] begin The index from where to start looking.
		/// @return The start index of the first occurance of the specified Power::String.
		/// @return Or -1 if the specified Power::String does not occur or if the begin index is greater or equal to the length of the Power::String.
		///
		inline int IndexOf(const String& other, size_t begin) const { 
			if (begin >= length_ || other.length_ > length_ - begin) return -1;
			char* p = strstr(data_ + begin, other.data_);
			return p ? static_cast<int>(p - data_) : -1;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the first occurance of the specified Power::String between the specified start and end index.
		/// @param[in] other The Power::String to look for.
		/// @param[in] begin The index from where to start looking.
		/// @param[in] end The index to where to stop looking.
		/// \n This index is clamped to the length of the Power::String.
		/// @return The start index of the first occurance of the specified Power::String.
		/// @return Or -1 if the specified Power::String does not occur or if the begin index is greater or equal to the length of the Power::String
		/// or if the begin index is greater or equal to the end index.
		///
		inline int IndexOf(const String& other, size_t begin, size_t end) const {
			if (end > length_) end = length_;
			if (begin >= end || other.length_ > end - begin) return -1;
			for (size_t i = begin; i < end - other.length_ + 1; ++i) {
				if (memcmp(data_ + i, other.data_, other.length_) == 0) return static_cast<int>(i);
			}
			return -1;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the first occurance of the specified c-string.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use IndexOf(const char) const instead.
		/// @return The start index of the first occurance of the specified c-string.
		/// @return Or -1 if the specified c-string does not occur.
		/// @note <b>If the length of the c-string is already known, it is recommended to use IndexOf(size_t, const char* const) const instead as it is faster.</b>
		///
		inline int IndexOf(const char* const other) const { return this->IndexOf(strlen(other), other); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the first occurance of the specified c-string starting from the specified index.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use IndexOf(const char, size_t) const instead.
		/// @param[in] begin The index from where to start looking.
		/// @return The start index of the first occurance of the specified c-string.
		/// @return Or -1 if the specified c-string does not occur or if the begin index is greater or equal to the length of the Power::String.
		/// @note <b>If the length of the c-string is already known, it is recommended to use IndexOf(size_t, const char* const, size_t) const instead as it is faster.</b>
		///
		inline int IndexOf(const char* const other, size_t begin) const { return this->IndexOf(strlen(other), other, begin); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the first occurance of the specified c-string between the specified start and end index.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use IndexOf(const char, size_t, size_t) const instead.
		/// @param[in] begin The index from where to start looking.
		/// @param[in] end The index to where to stop looking.
		/// \n This index is clamped to the length of the Power::String.
		/// @return The start index of the first occurance of the specified c-string.
		/// @return Or -1 if the specified c-string does not occur or if the begin index is greater or equal to the length of the Power::String
		/// or if the begin index is greater or equal to the end index.
		/// @note <b>If the length of the c-string is already known, it is recommended to use IndexOf(size_t, const char* const, size_t, size_t) const instead as it is faster.</b>
		///
		inline int IndexOf(const char* const other, size_t begin, size_t end) const { return this->IndexOf(strlen(other), other, begin, end); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the first occurance of the specified c-string.
		/// @param[in] length The length of the specified c-string excluding the null character.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use IndexOf(const char) const instead.
		/// @return The start index of the first occurance of the specified c-string.
		/// @return Or -1 if the specified c-string does not occur.
		///
		inline int IndexOf(size_t length, const char* const other) const {
			if (length > length_) return -1;
			char* p = strstr(data_, other);
			return p ? static_cast<int>(p - data_) : -1;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the first occurance of the specified c-string starting from the specified index.
		/// @param[in] length The length of the specified c-string excluding the null character.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use IndexOf(const char, size_t) const instead.
		/// @param[in] begin The index from where to start looking.
		/// @return The start index of the first occurance of the specified c-string.
		/// @return Or -1 if the specified c-string does not occur or if the begin index is greater or equal to the length of the Power::String.
		///
		inline int IndexOf(size_t length, const char* const other, size_t begin) const {
			if (begin >= length_ || length > length_ - begin) return -1;
			char* p = strstr(data_ + begin, other);
			return p ? static_cast<int>(p - data_) : -1;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the first occurance of the specified c-string between the specified start and end index.
		/// @param[in] length The length of the specified c-string excluding the null character.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use IndexOf(const char, size_t, size_t) const instead.
		/// @param[in] begin The index from where to start looking.
		/// @param[in] end The index to where to stop looking.
		/// \n This index is clamped to the length of the Power::String.
		/// @return The start index of the first occurance of the specified c-string.
		/// @return Or -1 if the specified c-string does not occur or if the begin index is greater or equal to the length of the Power::String
		/// or if the begin index is greater or equal to the end index.
		///
		inline int IndexOf(size_t length, const char* const other, size_t begin, size_t end) const {
			if (end > length_) end = length_;
			if (begin >= end || length > end - begin) return -1;
			for (size_t i = begin; i < end - length + 1; ++i) {
				if (memcmp(data_ + i, other, length) == 0) return static_cast<int>(i);
			}
			return -1;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the first occurance of the specified character.
		/// @param[in] c The character to look for.
		/// @return The index of the first occurance of the specified character.
		/// @return Or -1 if the specified character does not occur.
		///
		inline int IndexOf(const char c) const {
			char* p = static_cast<char*>(memchr(data_, c, length_));
			return p ? static_cast<int>(p - data_) : -1;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the first occurance of the specified character starting from the specified index.
		/// @param[in] c The character to look for.
		/// @param[in] begin The index from where to start looking.
		/// @return The index of the first occurance of the specified character.
		/// @return Or -1 if the specified character does not occur or if the begin index is greater or equal to the length of the Power::String.
		///
		inline int IndexOf(const char c, size_t begin) const {
			if (begin >= length_) return -1;
			char* p = static_cast<char*>(memchr(data_ + begin, c, length_ - begin));
			return p ? static_cast<int>(p - data_) : -1;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the first occurance of the specified character between the specified start and end index.
		/// @param[in] c The character to look for.
		/// @param[in] begin The index from where to start looking.
		/// @param[in] end The index to where to stop looking.
		/// \n This index is clamped to the length of the Power::String.
		/// @return The index of the first occurance of the specified character.
		/// @return Or -1 if the specified character does not occur or if the begin index is greater or equal to the length of the Power::String
		/// or if the begin index is greater or equal to the end index.
		///
		inline int IndexOf(const char c, size_t begin, size_t end) const {
			if (end > length_) end = length_;
			if (begin >= end) return -1;
			char* p = static_cast<char*>(memchr(data_ + begin, c, end - begin));
			return p ? static_cast<int>(p - data_) : -1;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--LastIndexOf-->
		/// @brief Finds the last occurance of the specified Power::String.
		/// @param[in] other The Power::String to look for.
		/// @return The start index of the last occurance of the specified Power::String.
		/// @return Or -1 if the spcified Power::String does not occur.
		///
		inline int LastIndexOf(const String& other) const { return this->LastIndexOf(other, length_, 0); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the last occurance of the specified Power::String starting from the specified index.
		/// @param[in] other The Power::String for look for.
		/// @param[in] begin The index from where to start lookin.
		/// @return The start index of the last occurance of the specified Power::String.
		/// @return Or -1 if the spcified Power::String does not occur or if the end index is greater or equal to the length of the Power::String.
		///
		inline int LastIndexOf(const String& other, size_t begin) const { return this->LastIndexOf(other, begin, 0); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the last occurance of the specified Power::String between the specified start and end index.
		/// @param[in] other The Power::String for look for.
		/// @param[in] begin The index from where to start lookin.
		/// \n This index is clamped to the length of the Power::String.
		/// @param[in] end The index to where to stop looking.
		/// @return The start index of the last occurance of the specified Power::String.
		/// @return Or -1 if the spcified Power::String does not occur or if the end index is greater or equal to the length of the Power::String
		/// or if the end index is greater or equal to the begin index.
		///
		inline int LastIndexOf(const String& other, size_t begin, size_t end) const {
			if (begin > length_) begin = length_;
			if (end >= begin || other.length_ > end - begin) return -1;
			for (int i = static_cast<int>(begin); i >= static_cast<int>(end + other.length_) - 1; --i) {
				if (data_[i] != other.data_[other.length_ - 1]) continue;
				int x = i - static_cast<int>(other.length_) + 1;
				if (x < 0) return -1;
				if (memcmp(data_ + x, other.data_, other.length_) == 0) return x;
			}
			return -1;
		}
				
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the last occurance of the specified c-string.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use LastIndexOf(const char) const instead.
		/// @return The start index of the last occurance of the specified c-string.
		/// @return Or -1 if the specified c-string does not occur.
		/// @note <b>If the length of the c-string is already known, it is recommended to use LastIndexOf(size_t, const char* const) const instead as it is faster.</b>
		///
		inline int LastIndexOf(const char* const other) const { return this->LastIndexOf(strlen(other), other, length_, 0);	}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the last occurance of the specified c-string starting from the specified index.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use LastIndexOf(const char, size_t) const instead.
		/// @param[in] begin The index from where to start looking.
		/// \n This index is clamped to the length of the Power::String.
		/// @return The start index of the last occurance of the specified c-string.
		/// @return Or -1 if the specified c-string does not occur.
		/// @note <b>If the length of the c-string is already known, it is recommended to use LastIndexOf(size_t, const char* const, size_t) const instead as it is faster.</b>
		///
		inline int LastIndexOf(const char* const other, size_t begin) const { return this->LastIndexOf(strlen(other), other, begin, 0); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the last occurance of the specified c-string between the specified start and end index.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use LastIndexOf(const char, size_t, size_t) const instead.
		/// @param[in] begin The index from where to start looking.
		/// \n This index is clamped to the length of the Power::String.
		/// @param[in] end The index to where to stop looking.
		/// @return The start index of the last occurance of the specified c-string.
		/// @return Or -1 if the specified c-string does not occur or if the end index is greater or equal to the length of the Power::String
		/// or if the end index is greater or equal to the eegin index.
		/// @note <b>If the length of the c-string is already known, it is recommended to use LastIndexOf(size_t, const char* const, size_t, size_t) const instead as it is faster.</b>
		///
		inline int LastIndexOf(const char* const other, size_t begin, size_t end) const { return this->LastIndexOf(strlen(other), other, begin, end); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the last occurance of the specified c-string.
		/// @param[in] length The length of the specified c-string excluding the null character.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use LastIndexOf(const char) const instead.
		/// @return The start index of the last occurance of the specified c-string.
		/// @return Or -1 if the specified c-string does not occur.
		///
		inline int LastIndexOf(size_t length, const char* const other) const { return this->LastIndexOf(length, other, 0, length_); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the last occurance of the specified c-string starting from the specified index.
		/// @param[in] length The length of the specified c-string excluding the null character.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use LastIndexOf(const char, size_t) const instead.
		/// @param[in] begin The index from where to start looking.
		/// \n This index is clamped to the length of the Power::String.
		/// @return The start index of the last occurance of the specified c-string.
		/// @return Or -1 if the specified c-string does not occur.
		///
		inline int LastIndexOf(size_t length, const char* const other, size_t begin) const { return this->LastIndexOf(length, other, begin, length_); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the last occurance of the specified c-string between the specified start and end index.
		/// @param[in] length The length of the specified c-string excluding the null character.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use LastIndexOf(const char, size_t, size_t) const instead.
		/// @param[in] begin The index from where to start looking.
		/// \n This index is clamped to the length of the Power::String.
		/// @param[in] end The index to where to stop looking.
		/// @return The start index of the last occurance of the specified c-string.
		/// @return Or -1 if the specified c-string does not occur or if the end index is greater or equal to the length of the Power::String
		/// or if the end index is greater or equal to the begin index.
		///
		inline int LastIndexOf(size_t length, const char* const other, size_t begin, size_t end) const {
			if (begin > length_) begin = length_;
			if (end >= begin || length > end - begin) return -1;
			for (int i = static_cast<int>(begin); i >= static_cast<int>(end + length) - 1; --i) {
				if (data_[i] != other[length - 1]) continue;
				int x = i - static_cast<int>(length) + 1;
				if (x < 0) return -1;
				if (memcmp(data_ + x, other, length) == 0) return x;
			}
			return -1;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the last occurance of the specified character.
		/// @param[in] c The character to look for.
		/// @return The index of the last occurance of the specified character.
		/// @return Or -1 if the specified character does not occur.
		///
		inline int LastIndexOf(const char c) const {
			char* p = strrchr(data_, c);
			return p ? static_cast<int>(p - data_) : -1;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the last occurance of the specified character starting from the specified index.
		/// @param[in] c The character to look for.
		/// @param[in] begin The index from where to start looking.
		/// \n This index is clamped to the length of the Power::String.
		/// @return The index of the last occurance of the specified character.
		/// @return Or -1 if the specified character does not occur.
		///
		inline int LastIndexOf(const char c, size_t begin) const { return this->LastIndexOf(c, begin, 0); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the last occurance of the specified character between the specified start and end index.
		/// @param[in] c The character to look for.
		/// @param[in] begin The index from where to start looking.
		/// \n This index is clamped to the length of the Power::String.
		/// @param[in] end The index to where to stop looking.
		/// @return The index of the last occurance of the specified character.
		/// @return Or -1 if the specified character does not occur or if the end index is greater or equal to the length of the Power::String
		/// or if the end index is greater or equal to the begin index.
		///
		inline int LastIndexOf(const char c, size_t begin, size_t end) const {
			if (begin > length_) begin = length_;
			if (end >= begin) return -1;
			for (int i = static_cast<int>(begin); i >= static_cast<int>(end); --i) if (data_[i] == c) return i;
			return -1;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Count-->
		/// @brief Counts how many times the specified Power::String occurs in the Power::String.
		/// @param[in] other The Power::String to look for.
		/// @return How many times the specified Power::String occurs.
		/// @return Or 0 if the specified Power::String does not occur.
		///
		inline int Count(const String& other) const { return this->Count(other, 0, length_); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Counts how many times the specified Power::String occurs in the Power::String from the specified index.
		/// @param[in] other The Power::String to look for.
		/// @param[in] begin The index from where to start looking.
		/// @return How many times the specified Power::String occurs.
		/// @return Or 0 if the specified Power::String does not occur or if the begin index is greater or equal to the length of the Power::String.
		///
		inline int Count(const String& other, size_t begin) const { return this->Count(other, begin, length_); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Counts how many times the specified Power::String occurs in the Power::String from the specified start and end index.
		/// @param[in] other The Power::String to look for.
		/// @param[in] begin The index from where to start looking.
		/// @param[in] end The index to where to stop looking.
		/// \n This index is clamped to the length of the Power::String.
		/// @return How many times the specified Power::String occurs.
		/// @return Or 0 if the specified Power::String does not occur or if the begin index is greater or equal to the length of the Power::String
		/// or if the begin index is greater or equal to the end index.
		///
		inline int Count(const String& other, size_t begin, size_t end) const {
			int count = 0;
			int curIndex = this->IndexOf(other, begin, end);
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
		/// @note <b>If the length of the c-string is already known, it is recommended to use Count(size_t, const char* const) const instead as it is faster.</b>
		///
		inline int Count(const char* const other) const { return this->Count(strlen(other), other, 0, length_); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Counts how many times the specified c-string occurs in the Power::String.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Count(const char, size_t) const instead.
		/// @param[in] begin The index from where to start looking.
		/// @return How many times the specified c-string occurs.
		/// @return Or 0 if the specified c-string does not occur or if the begin index is greater or equal to the length of the Power::String.
		/// @note <b>If the length of the c-string is already known, it is recommended to use Count(size_t, const char* const, size_t) const instead as it is faster.</b>
		///
		inline int Count(const char* const other, size_t begin) const { return this->Count(strlen(other), other, begin, length_); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Counts how many times the specified c-string occurs in the Power::String.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Count(const char, size_t, size_t) const instead.
		/// @param[in] begin The index from where to start looking.
		/// @param[in] end The index to where to stop looking.
		/// \n This index is clamped to the length of the Power::String.
		/// @return How many times the specified c-string occurs.
		/// @return Or 0 if the specified c-string does not occur or if the begin index is greater or equal to the length of the Power::String
		/// or if the begin index is greater or equal to the end index.
		/// @note <b>If the length of the c-string is already known, it is recommended to use Count(size_t, const char* const, size_t, size_t) const instead as it is faster.</b>
		///
		inline int Count(const char* const other, size_t begin, size_t end) const { return this->Count(strlen(other), other, begin, end); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Counts how many times the specified c-string occurs in the Power::String.
		/// @param[in] length The length of the specified c-string excluding the null character.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Count(const char) const instead.
		/// @return How many times the specified c-string occurs.
		/// @return Or 0 if the specified c-string does not occur.
		///
		inline int Count(size_t length, const char* const other) const { return this->Count(length, other, 0, length_); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Counts how many times the specified c-string occurs in the Power::String.
		/// @param[in] length The length of the specified c-string excluding the null character.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Count(const char, size_t) const instead.
		/// @param[in] begin The index from where to start looking.
		/// @return How many times the specified c-string occurs.
		/// @return Or 0 if the specified c-string does not occur or if the begin index is greater or equal to the length of the Power::String.
		///
		inline int Count(size_t length, const char* const other, size_t begin) const { return this->Count(length, other, begin, length_); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Counts how many times the specified c-string occurs in the Power::String.
		/// @param[in] length The length of the specified c-string excluding the null character.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Count(const char, size_t, size_t) const instead.
		/// @param[in] begin The index from where to start looking.
		/// @param[in] end The index to where to stop looking.
		/// \n This index is clamped to the length of the Power::String.
		/// @return How many times the specified c-string occurs.
		/// @return Or 0 if the specified c-string does not occur or if the begin index is greater or equal to the length of the Power::String
		/// or if the begin index is greater or equal to the end index.
		///
		inline int Count(size_t length, const char* const other, size_t begin, size_t end) const {
			int count = 0;
			int curIndex = this->IndexOf(length, other, begin, end);
			while (curIndex != -1) {
				++count;
				curIndex = this->IndexOf(length, other, curIndex + 1, end);
			}
			return count;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Counts how many times the specified character occurs in the Power::String.
		/// @param[in] c The character to look for.
		/// @return How many times the specified character occurs.
		/// @return Or 0 if the specified character does not occur.
		///
		inline int Count(const char c) const { return this->Count(c, 0, length_); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Counts how many times the specified character occurs in the Power::String.
		/// @param[in] c The character to look for.
		/// @param[in] begin The index from where to start looking.
		/// @return How many times the specified character occurs.
		/// @return Or 0 if the specified character does not occur or if the begin index is greater or equal to the length of the Power::String.
		///
		inline int Count(const char c, size_t begin) const { return this->Count(c, begin, length_); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Counts how many times the specified character occurs in the Power::String.
		/// @param[in] c The character to look for.
		/// @param[in] begin The index from where to start looking.
		/// @param[in] end The index to where to stop looking.
		/// \n This index is clamped to the length of the Power::String.
		/// @return How many times the specified character occurs.
		/// @return Or 0 if the specified character does not occur or if the begin index is greater or equal to the length of the Power::String
		/// or if the begin index is greater or equal to the end index.
		///
		inline int Count(const char c, size_t begin, size_t end) const {
			int count = 0;
			int curIndex = this->IndexOf(c, begin, end);
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
		/// @return The returned Power::String will be empty, if the start index is greater than the length of the Power::String.
		///
		inline String Substring(size_t begin) const {
			if (begin > length_) begin = length_;
			return String(data_ + begin, length_ - begin);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Creates a substring from the specified start index to the specified end index.
		/// @param[in] begin The index from where to start.
		/// @param[in] end The index to where to stop.
		/// @return A Power::String containing the substring.
		/// @return The returned Power::String will be empty, if the start index is greater than the end index or the length of the Power::String.
		///
		inline String Substring(size_t begin, size_t end) const {
			if (end > length_) end = length_;
			if (begin > end) begin = end;
			return String(data_ + begin, end - begin);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Insert-->
		/// @brief Inserts the specified Power::String at the specified index.
		/// @param[in] index The index where the specified Power::String will be inserted at.
		/// \n If this index is greater than the length of the Power::String, the method will return and nothing will be inserted.
		/// @param[in] other The Power::String to be inserted.
		/// @return A reference to the current Power::String.
		///
		inline String& Insert(size_t index, const String& other) {
			if (index > length_) return * this;
			size_t newLength = length_ + other.length_;
			this->CheckSizeAndReallocate(newLength);
			memcpy(temp_, other.data_, other.length_);
			memcpy(temp_ + other.length_, data_ + index, length_ - index);
			memcpy(data_ + index, temp_, newLength - index);
			this->SetNewLength(newLength);
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Inserts the specified c-string at the specified index.
		/// @param[in] index The index where the specified c-string will be inserted at.
		/// \n If this index is greater than the length of the Power::String, the method will return and nothing will be inserted.
		/// @param[in] other The c-string to be inserted.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Insert(size_t, const char) instead.
		/// @note <b>If the length of the c-string is already known, it is recommended to use Insert(sizt_t, const char* const, size_t) instead as it is faster.</b>
		/// @return A reference to the current Power::String.
		///
		inline String& Insert(size_t index, const char* const other) { return this->Insert(index, other, strlen(other)); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Inserts the specified c-string at the specified index.
		/// @param[in] index The index where the specified c-string will be inserted at.
		/// \n If this index is greater than the length of the Power::String, the method will return and nothing will be inserted.
		/// @param[in] other The c-string to be inserted.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Insert(size_t, const char) instead.
		/// @param[in] length The length of the c-string excluding the null character.
		/// @return A reference to the current Power::String.
		///
		inline String& Insert(size_t index, const char* const other, size_t length) {
			if (index > length_) return *this;
			size_t newLength = length_ + length;
			this->CheckSizeAndReallocate(newLength);
			memcpy(temp_, other, length);
			memcpy(temp_ + length, data_ + index, length_ - index);
			memcpy(data_ + index, temp_, newLength - index);
			this->SetNewLength(newLength);
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Inserts the specified character at the specified index.
		/// @param[in] index The index where the specified character will be inserted at.
		/// \n If this index is greater than the length of the Power::String, the method will return and nothing will be inserted.
		/// @param[in] c The character to be inserted.
		/// @return A reference to the current Power::String.
		///
		inline String& Insert(size_t index, const char c) {
			if (index > length_) return *this;
			size_t newLength = length_ + 1;
			this->CheckSizeAndReallocate(newLength);
			temp_[index] = c;
			memcpy(temp_ + 1, data_ + index, length_ - index);
			memcpy(data_ + index, temp_, newLength - index);
			this->SetNewLength(newLength);
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Remove-->
		/// @brief Removes all characters in the Power::Strig starting from the specified index.
		/// @param[in] index The index from where to start.
		/// \n If this index is greater or equal to the length of the Power::String, the method will return and nothing will be removed.
		/// @return A reference to the current Power::String.
		///
		inline String& Remove(size_t index) { return this->Remove(index, length_ - index); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Removes a specified amount of characters in the Power::String starting from the specified index.
		/// @param[in] index The index from where to start.
		/// \n If this index is greater or equal to the length of the Power::String, the method will return and nothing will be removed.
		/// @param[in] count How many characters shall be removed.
		/// \n This value gets clamped to the length of the Power::String minus the specified index.
		/// @return A reference to the current Power::String.
		///
		inline String& Remove(size_t index, size_t count) {
			if (index >= length_) return *this;
			if (count > length_ - index) count = length_ - index;
			memcpy(temp_, data_, index);
			memcpy(temp_ + index, data_ + index + count, index - count);
			length_ = length_ - count;
			memcpy(data_, temp_, length_);
			data_[length_] = '\0';
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--RemoveAll-->
		/// @brief Removes all occurances of the specified Power::String.
		/// @param[in] other The Power::String to remove.
		/// @return A reference to the current Power::String.
		///
		inline String& RemoveAll(const String& other) {
			int index = 0;
			int nextIndex = static_cast<int>(this->IndexOf(other.data_));
			if (nextIndex < 0) return *this;
			size_t i = 0;
			char* temp = temp_;
			while (nextIndex >= 0) {
				memcpy(temp, data_ + index, nextIndex - index);
				temp += nextIndex - index;
				index = nextIndex + static_cast<int>(other.length_);
				nextIndex = static_cast<int>(this->IndexOf(other.data_, index));
				++i;
			}
			memcpy(temp, data_ + index, length_ - index);
			length_ = length_ - i * other.length_;
			memcpy(data_, temp_, length_);
			data_[length_] = '\0';
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Removes all occurances of the specified c-string.
		/// @param[in] other The c-string to remove.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use RemoveAll(const char) instead.
		/// @node <b>If the length of the c-string is already known, it is recommended to use RemoveAll(const char* const, size_t) instead as it is faster.</b>
		/// @return A reference to the current Power::String.
		///
		inline String& RemoveAll(const char* const other) { return this->RemoveAll(other, strlen(other)); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Removes all occurances of the specified c-string.
		/// @param[in] other The c-string to remove.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use RemoveAll(const char) instead.
		/// @param[in] length The length of the c-string excluding the null character.
		/// @return A reference to the current Power::String.
		///
		inline String& RemoveAll(const char* const other, size_t length) {
			int index = 0;
			int nextIndex = static_cast<int>(this->IndexOf(other));
			if (nextIndex < 0) return *this;
			size_t i = 0;
			char* temp = temp_;
			while (nextIndex >= 0) {
				memcpy(temp, data_ + index, nextIndex - index);
				temp += nextIndex - index;
				index = nextIndex + static_cast<int>(length);
				nextIndex = static_cast<int>(this->IndexOf(other, index));
				++i;
			}
			memcpy(temp, data_ + index, length_ - index);
			length_ = length_ - i * length;
			memcpy(data_, temp_, length_);
			data_[length_] = '\0';
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Removes all occurances of the specified character.
		/// @param[in] c The character to remove.
		/// @return A reference to the current Power::String.
		///
		inline String& RemoveAll(const char c) {
			size_t count = 0;
			for (size_t i = 0; i < length_; ++i) if (data_[i] == c) ++count;
			if (count == 0) return *this;
			size_t newLength = length_ - count;
			count = 0;
			for (size_t i = 0; i < length_; ++i) {
				if (data_[i] == c) continue;
				temp_[count] = data_[i];
				++count;
			}
			memcpy(data_, temp_, newLength);
			this->SetNewLength(newLength);
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Replace-->
		/// @brief Replaces all characters from the specified start index with the specified Power::String.
		/// @param[in] index The index from where to replace.
		/// \n If this index is greater or equal to the length of the Power::String, the method will return and nothing will be replaced.
		/// @param[in] other The Power::String with which to replace.
		/// @return A reference to the current Power::String.
		///
		inline String& Replace(size_t index, const String& other) { return this->Replace(index, length_ - index, other); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Replaces a specified amount of characters from the specified start index with the specified Power::String.
		/// @param[in] index The index from where to replace.
		/// \n If this index is greater or equal to the length of the Power::String, the method will return and nothing will be replaced.
		/// @param[in] count How many characters will be replaced.
		/// \n This value gets clamped to the length of the Power::String minus the specified index.
		/// @param[in] other The Power::String with which to replace.
		/// @return A reference to the current Power::String.
		///
		inline String& Replace(size_t index, size_t count, const String& other) {
			if (index >= length_) return *this;
			if (count > length_ - index) count = length_ - index;
			size_t newLength = length_ - count + other.length_;
			this->CheckSizeAndReallocate(newLength);
			memcpy(temp_, other.data_, other.length_);
			memcpy(temp_ + other.length_, data_ + index + count, length_ - index - count);
			memcpy(data_ + index, temp_, newLength - index);
			this->SetNewLength(newLength);
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Replaces all characters from the specified start index with the specified c-string.
		/// @param[in] index The index from where to replace.
		/// \n If this index is greater or equal to the length of the Power::String, the method will return and nothing will be replaced.
		/// @param[in] other The c-string with which to replace.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Replace(size_t, const char) instead.
		/// @node <b>If the length of the c-string is already known, it is recommended to use Replace(size_t, const char* const, size_t) instead as it is faster.</b>
		/// @return A reference to the current Power::String.
		///
		inline String& Replace(size_t index, const char* const other) { return this->Replace(index, length_ - index, other, strlen(other)); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Replaces all characters from the specified start index with the specified c-string.
		/// @param[in] index The index from where to replace.
		/// \n If this index is greater or equal to the length of the Power::String, the method will return and nothing will be replaced.
		/// @param[in] count How many characters will be replaced.
		/// \n This value gets clamped to the length of the Power::String minus the specified index.
		/// @param[in] other The c-string with which to replace.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Replace(size_t, size_t, const char) instead.
		/// @node <b>If the length of the c-string is already known, it is recommended to use Replace(size_t, const char* const, size_t) instead as it is faster.</b>
		/// @return A reference to the current Power::String.
		///
		inline String& Replace(size_t index, size_t count, const char* const other) { return this->Replace(index, count, other, strlen(other)); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Replaces all characters from the specified start index with the specified c-string.
		/// @param[in] index The index from where to replace.
		/// \n If this index is greater or equal to the length of the Power::String, the method will return and nothing will be replaced.
		/// @param[in] other The c-string with which to replace.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Replace(size_t, const char) instead.
		/// @param[in] length The length of the c-string excluding the null character.
		/// @return A reference to the current Power::String.
		///
		inline String& Replace(size_t index, const char* const other, size_t length) { return this->Replace(index, length_ - index, other, length); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Replaces all characters from the specified start index with the specified c-string.
		/// @param[in] index The index from where to replace.
		/// \n If this index is greater or equal to the length of the Power::String, the method will return and nothing will be replaced.
		/// @param[in] count How many characters will be replaced.
		/// \n This value gets clamped to the length of the Power::String minus the specified index.
		/// @param[in] other The c-string with which to replace.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Replace(size_t, size_t, const char) instead.
		/// @param[in] length The length of the c-string excluding the null character.
		/// @return A reference to the current Power::String.
		///
		inline String& Replace(size_t index, size_t count, const char* const other, size_t length) {
			if (index >= length_) return *this;
			if (count > length_ - index) count = length_ - index;
			size_t newLength = length_ - count + length;
			this->CheckSizeAndReallocate(newLength);
			memcpy(temp_, other, length);
			memcpy(temp_ + length, data_ + index + count, length_ - index - count);
			memcpy(data_ + index, temp_, newLength - index);
			this->SetNewLength(newLength);
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Replaces all characters from the specified start index with the specified character.
		/// @param[in] index The index from where to replace.
		/// \n If this index is greater or equal to the length of the Power::String, the method will return and nothing will be replaced.
		/// @param[in] c The character with which to replace.
		/// @return A reference to the current Power::String.
		///
		inline String& Replace(size_t index, const char c) { return this->Replace(index, length_ - index, c); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Replaces a specified amount of characters from the specified start index with the specified character.
		/// @param[in] index The index from where to replace.
		/// \n If this index is greater or equal to the length of the Power::String, the method will return and nothing will be replaced.
		/// @param[in] count How many characters will be replaced.
		/// \n This value gets clamped to the length of the Power::String minus the specified index.
		/// @param[in] c The character with which to replace.
		/// @return A reference to the current Power::String.
		///
		inline String& Replace(size_t index, size_t count, const char c) {
			if (index >= length_) return *this;
			if (count > length_ - index) count = length_ - index;
			size_t newLength = length_ - count + 1;
			this->CheckSizeAndReallocate(newLength);
			temp_[index] = c;
			memcpy(temp_ + 1, data_ + index + count, length_ - index - count);
			memcpy(data_ + index, temp_, newLength - index);
			this->SetNewLength(newLength);
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--ReplaceAt-->
		/// @brief Replaces the characters with the specified Power::String at the specified index.
		/// @param[in] index The index from where to replace.
		/// \n If this index is greater or equal to the length of the Power::String, the method will return and nothing will be replaced.
		/// @param[in] other The Power::String with which to replace.
		/// @return A reference to the current Power::String.
		///
		inline String& ReplaceAt(size_t index, const String& other) {
			if (index >= length_) return *this;
			size_t newLength = index + other.length_;
			this->CheckSizeAndReallocate(newLength);
			this->MemCpyCheckData(index, other.data_, other.length_);
			if (newLength > length_) this->SetNewLength(newLength);
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Replaces the characters with the specified c-string at the specified index.
		/// @param[in] index The index from where to replace.
		/// \n If this index is greater or equal to the length of the Power::String, the method will return and nothing will be replaced.
		/// @param[in] other The c-string with which to replace.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use ReplaceAt(size_t, const char) instead.
		/// @node <b>If the length of the c-string is already known, it is recommended to use ReplaceAt(size_t, const char* const, size_t) instead as it is faster.</b>
		/// @return A reference to the current Power::String.
		///
		inline String& ReplaceAt(size_t index, const char* const other) { return  this->ReplaceAt(index, other, strlen(other)); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Replaces the characters with the specified c-string at the specified index.
		/// @param[in] index The index from where to replace.
		/// \n If this index is greater or equal to the length of the Power::String, the method will return and nothing will be replaced.
		/// @param[in] other The c-string with which to replace.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use ReplaceAt(size_t, const char) instead.
		/// @param[in] length The length of the c-string excluding the null character.
		/// @return A reference to the current Power::String.
		///
		inline String& ReplaceAt(size_t index, const char* const other, size_t length) {
			if (index >= length_) return *this;
			size_t newLength = index + length;
			int64_t offset = other - data_;
			this->CheckSizeAndReallocate(newLength);
			if (offset >= 0 && offset < static_cast<int>(length_)) {
				memcpy(temp_, data_ + offset, length);
				memcpy(data_ + index, temp_, length);
			} else
				memcpy(data_ + index, other, length);
			if (newLength > length_) this->SetNewLength(newLength);
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Replaces the character with the specified character at the specified index.
		/// @param[in] index The index at where to replace.
		/// \n If this index is greater or equal to the length of the Power::String, the method will return and nothing will be replaced.
		/// @param[in] c The character with which to replace.
		/// @return A reference to the current Power::String.
		///
		inline String& ReplaceAt(size_t index, const char c) {
			if (index >= length_) return *this;
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
			for (size_t i = 0; i < length_; ++i) {
				if (data_[i] != c) {
					startIndex = i;
					break;
				}
			}
			length_ = length_ - startIndex;
			memcpy(temp_, data_ + startIndex, length_);
			memcpy(data_, temp_, length_);
			data_[length_] = '\0';
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
			for (int i = static_cast<int>(length_) - 1; i >= 0; --i) {
				if (data_[i] != c) {
					length_ = static_cast<size_t>(i + 1);
					data_[length_] = '\0';
					break;
				}
			}
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--PadLeft-->
		/// @brief Right-aligns the Power::String by filling it to the left with whitespaces to the specified total length.
		/// @param[in] length The total length the Power::String should be including the current length of the Power::String.
		/// \n If this value is less or equal to the length of the Power::String, this method will return without padding.
		/// @return A reference to the current Power::String.
		///
		inline String& PadLeft(size_t length) { return this->PadLeft(length, ' '); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Right-aligns the Power::String by filling it to the left with the specified character to the specified total length.
		/// @param[in] length The total length the Power::String should be including the current length of the Power::String.
		/// \n If this value is less or equal to the length of the Power::String, this method will return without padding.
		/// @param[in] c The character with which to fill.
		/// @return A reference to the current Power::String.
		///
		inline String& PadLeft(size_t length, char c) {
			if (length_ >= length) return *this;
			this->CheckSizeAndReallocate(length);
			memset(temp_, c, length - length_);
			memcpy(temp_ + length - length_, data_, length_);
			length_ = length;
			memcpy(data_, temp_, length);
			data_[length] = '\0';
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--PadRight-->
		/// @brief Left-aligns the Power::String by filling it to the right with whitespaces to the specified total length.
		/// @param[in] length The total length the Power::String should be including the current length of the Power::String.
		/// \n If this value is less or equal to the length of the Power::String, this method will return without padding.
		/// @return A reference to the current Power::String.
		///
		inline String& PadRight(size_t length) { return this->PadRight(length, ' '); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Left-aligns the Power::String by filling it to the right with the specified character to the specified total length.
		/// @param[in] length The total length the Power::String should be including the current length of the Power::String.
		/// \n If this value is less or equal to the length of the Power::String, this method will return without padding.
		/// @param[in] c The character with which to fill.
		/// @return A reference to the current Power::String.
		///
		inline String& PadRight(size_t length, char c) {
			if (length_ >= length) return *this;
			this->CheckSizeAndReallocate(length);
			memset(temp_ + length_, c, length - length_);
			memcpy(temp_, data_, length_);
			length_ = length;
			memcpy(data_, temp_, length);
			data_[length] = '\0';
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--StartsWith-->
		/// @brief Checks if the Power::String starts with the specified Power::String.
		/// @param[in] other The Power::String to check for.
		/// @return <span style="color:#30AA00">True</span>, if the Power::String starts with the specified Power::String.
		/// @return <span style="color:#CC3000">False</span>, if it doesn't, or if the length of the specified Power::String is greater than the length of the Power::String.
		///
		inline bool StartsWith(const String& other) const {
			if (other.length_ > length_) return false;
			return memcmp(data_, other.data_, other.length_) == 0;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Checks if the c-string starts with the specified Power::String.
		/// @param[in] other The c-string to check for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use StartsWith(const char) const instead.
		/// @return <span style="color:#30AA00">True</span>, if the Power::String starts with the specified c-string.
		/// @return <span style="color:#CC3000">False</span>, if it doesn't, or if the length of the specified c-string is greater than the length of the Power::String.
		/// @node <b>If the length of the c-string is already known, it is recommended to use StartsWith(const char* const, size_t) const instead as it is faster.</b>
		///
		inline bool StartsWith(const char* const other) const { return this->StartsWith(other, strlen(other)); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Checks if the c-string starts with the specified Power::String.
		/// @param[in] other The c-string to check for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use StartsWith(const char) const instead.
		/// @param[in] length The length of the c-string excluding the null character.
		/// @return <span style="color:#30AA00">True</span>, if the Power::String starts with the specified c-string.
		/// @return <span style="color:#CC3000">False</span>, if it doesn't, or if the length of the specified c-string is greater than the length of the Power::String.
		///
		inline bool StartsWith(const char* const other, size_t length) const {
			if (length > length_) return false;
			return memcmp(data_, other, length) == 0;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Checks if the character starts with the specified Power::String.
		/// @param[in] c The character to check for.
		/// @return <span style="color:#30AA00">True</span>, if the Power::String starts with the specified character.
		/// @return <span style="color:#CC3000">False</span>, if it doesn't, or if the length of the specified character is greater than the length of the Power::String.
		///
		inline bool StartsWith(const char c) const { return *data_ == c; }


		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--EndsWith-->
		/// @brief Checks if the Power::String ends with the specified Power::String.
		/// @param[in] other The Power::String to check for.
		/// @return <span style="color:#30AA00">True</span>, if the Power::String ends with the specified Power::String.
		/// @return <span style="color:#CC3000">False</span>, if it doesn't, or if the length of the specified Power::String is greater than the length of the Power::String.
		///
		inline bool EndsWith(const String& other) const {
			if (other.length_ > length_) return false;
			return memcmp(data_ + length_ - other.length_, other.data_, other.length_) == 0;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Checks if the c-string ends with the specified Power::String.
		/// @param[in] other The c-string to check for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use EndsWith(const char) const instead.
		/// @return <span style="color:#30AA00">True</span>, if the Power::String ends with the specified c-string.
		/// @return <span style="color:#CC3000">False</span>, if it doesn't, or if the length of the specified c-string is greater than the length of the Power::String.
		/// @node <b>If the length of the c-string is already known, it is recommended to use EndsWith(const char* const, size_t) const instead as it is faster.</b>
		///
		inline bool EndsWith(const char* const other) const { return this->EndsWith(other, strlen(other)); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Checks if the c-string ends with the specified Power::String.
		/// @param[in] other The c-string to check for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use EndsWith(const char) const instead.
		/// @param[in] length The length of the c-string excluding the null character.
		/// @return <span style="color:#30AA00">True</span>, if the Power::String ends with the specified c-string.
		/// @return <span style="color:#CC3000">False</span>, if it doesn't, or if the length of the specified c-string is greater than the length of the Power::String.
		///
		inline bool EndsWith(const char* const other, size_t length) const {
			if (length > length_) return false;
			return memcmp(data_ + length_ - length, other, length) == 0;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Checks if the character ends with the specified Power::String.
		/// @param[in] c The character to check for.
		/// @return <span style="color:#30AA00">True</span>, if the Power::String ends with the specified character.
		/// @return <span style="color:#CC3000">False</span>, if it doesn't, or if the length of the specified character is greater than the length of the Power::String.
		///
		inline bool EndsWith(const char c) const { return data_[length_ - 1] == c; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Fill-->
		/// @brief Fills the Power::String with the specified Power::String.
		/// @param[in] other The Power::String to fill with.
		/// @return A reference to the current Power::String.
		///
		inline String& Fill(const String& other) { return this->Fill(other, 0, length_); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Fills the Power::String with the specified Power::String starting from the specified index.
		/// @param[in] other The Power::String to fill with.
		/// @param[in] begin The index from where to start filling.
		/// \n If this index is greater or equal to the length of the Power::String, the method will return without filling.
		/// @return A reference to the current Power::String.
		///
		inline String& Fill(const String& other, size_t begin) { return this->Fill(other, begin, length_); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Fills the Power::String with the specified Power::String between the specified start and end index.
		/// @param[in] other The Power::String to fill with.
		/// @param[in] begin The index from where to start filling.
		/// \n If this index is greater or equal to the end index or the length of the Power::String, the method will return without filling.
		/// @param[in] end The index to where to stop filling.
		/// \n This index is clamped to the length of the Power::String.
		/// @return A reference to the current Power::String.
		///
		inline String& Fill(const String& other, size_t begin, size_t end) {
			if (end > length_) end = length_;
			if (begin >= end) return *this;
			int count = static_cast<int>((end - begin) / other.length_);
			for (int i = 0; i < count; ++i) memcpy(data_ + begin + i * other.length_, other.data_, other.length_);
			memcpy(data_ + begin + count + other.length_, other.data_, (end - begin) % other.length_);
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Fills the Power::String with the specified c-string.
		/// @param[in] other The c-string to fill with.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Fill(const char) instead.
		/// @node <b>If the length of the c-string is already known, it is recommended to use Fill(size_t, const char* const) const instead as it is faster.</b>
		/// @return A reference to the current Power::String.
		///
		inline String& Fill(const char* const other) { return this->Fill(strlen(other), other, 0, length_); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Fills the Power::String with the specified c-string starting from the specified index.
		/// @param[in] other The c-string to fill with.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Fill(const char, size_t) instead.
		/// @param[in] begin The index from where to start filling.
		/// \n If this index is greater or equal to the length of the Power::String, the method will return without filling.
		/// @node <b>If the length of the c-string is already known, it is recommended to use Fill(size_t, const char* const, size_t) instead as it is faster.</b>
		/// @return A reference to the current Power::String.
		///
		inline String& Fill(const char* const other, size_t begin) { return this->Fill(strlen(other), other, begin, length_); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Fills the Power::String with the specified c-string between the specified start and end index.
		/// @param[in] other The c-string to fill with.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Fill(const char, size_t, size_t) instead.
		/// @param[in] begin The index from where to start filling.
		/// \n If this index is greater or equal to the end index or the length of the Power::String, the method will return without filling.
		/// @param[in] end The index to where to stop filling.
		/// \n This index is clamped to the length of the Power::String.
		/// @node <b>If the length of the c-string is already known, it is recommended to use Fill(size_t, const char* const, size_t, size_t) instead as it is faster.</b>
		/// @return A reference to the current Power::String.
		///
		inline String& Fill(const char* const other, size_t begin, size_t end) { return this->Fill(strlen(other), other, begin, end); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Fills the Power::String with the specified c-string.
		/// @param[in] length The length of the c-string excluding the null character.
		/// @param[in] other The c-string to fill with.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Fill(const char) instead.
		/// @return A reference to the current Power::String.
		///
		inline String& Fill(size_t length, const char* const other) { return this->Fill(length, other, 0, length_); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Fills the Power::String with the specified c-string starting from the specified index.
		/// @param[in] length The length of the c-string excluding the null character.
		/// @param[in] other The c-string to fill with.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Fill(const char, size_t) instead.
		/// @param[in] begin The index from where to start filling.
		/// \n If this index is greater or equal to the length of the Power::String, the method will return without filling.
		/// @return A reference to the current Power::String.
		///
		inline String& Fill(size_t length, const char* const other, size_t begin) { return this->Fill(length, other, begin, length_); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Fills the Power::String with the specified c-string between the specified start and end index.
		/// @param[in] length The length of the c-string excluding the null character.
		/// @param[in] other The c-string to fill with.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Fill(const char, size_t, size_t) instead.
		/// @param[in] begin The index from where to start filling.
		/// \n If this index is greater or equal to the end index or the length of the Power::String, the method will return without filling.
		/// @param[in] end The index to where to stop filling.
		/// \n This index is clamped to the length of the Power::String.
		/// @return A reference to the current Power::String.
		///
		inline String& Fill(size_t length, const char* const other, size_t begin, size_t end) {
			if (end > length_) end = length_;
			if (begin >= end) return *this;
			int count = static_cast<int>((end - begin) / length);
			for (int i = 0; i < count; ++i) this->MemCpyCheckData(begin + i * length, other, length);
			this->MemCpyCheckData(begin + count * length, other, (end - begin) % length);
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Fills the Power::String with the specified character.
		/// @param[in] c The character to fill with.
		/// @return A reference to the current Power::String.
		///
		inline String& Fill(const char c) { memset(data_, c, length_); return *this; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Fills the Power::String with the specified character starting from the specified index.
		/// @param[in] c The character to fill with.
		/// @param[in] begin The index from where to start filling.
		/// \n If this index is greater or equal to the length of the Power::String, the method will return without filling.
		/// @return A reference to the current Power::String.
		///
		inline String& Fill(const char c, size_t begin) {
			if (begin >= length_) return *this;
			memset(data_, c, length_ - begin);
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Fills the Power::String with the specified character between the specified start and end index.
		/// @param[in] c The character to fill with.
		/// @param[in] begin The index from where to start filling.
		/// \n If this index is greater or equal to the end index or the length of the Power::String, the method will return without filling.
		/// @param[in] end The index to where to stop filling.
		/// \n This index is clamped to the length of the Power::String.
		/// @return A reference to the current Power::String.
		///
		inline String& Fill(const char c, size_t begin, size_t end) {
			if (end > length_) end = length_;
			if (begin >= end) return *this;
			memset(data_, c, end - begin);
			return *this;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--SplitAt-->
		/// @brief Splits the Power::String into two substrings at the specified index.
		/// @param[in] index The index at where to split.
		/// \n If this index is greater than the length of the Power::String, the method will return wihout filling lhs and rhs.
		/// @param[out] lhs A Power::String containing the left-hand part from index.
		/// @param[out] rhs A Power::String containing the right-hand part from index.
		///
		inline void SplitAt(size_t index, String& lhs, String& rhs) const {
			if (index > length_) return;
			lhs = String(data_, index);
			rhs = String(data_ + index, length_ - index);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--ToLower-->
		/// @brief Converts all upper case characters to lower case.
		/// @return A reference to the current Power::String.
		///
		inline String& ToLower() { _strlwr_s(data_, length_ + 1); return *this; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--ToUpper-->
		/// @brief Converts all lower case characters to upper case.
		/// @return A reference to the current Power::String.
		///
		inline String& ToUpper() { _strupr_s(data_, length_ + 1); return *this; }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Destructor-->
		/// @brief TODO: Document
		///
		~String() {
			free(data_);
			--s_instanceCounter_;
		}

	private:
		String(const String& lhs, const String& rhs) :
			size_(lhs.length_ + rhs.length_ + 1),
			length_(lhs.length_ + rhs.length_),
			data_(static_cast<char*>(malloc(size_ * 2))),
			temp_(data_ + size_)
		{
			memcpy(data_, lhs.data_, lhs.length_);
			memcpy(data_ + lhs.length_, rhs.data_, rhs.length_);
			data_[length_] = '\0';
			this->IncInstCounter();
		}
		String(const String& lhs, const char* const rhs) :
			size_(0),
			length_(0),
			data_(nullptr),
			temp_(nullptr)
		{
			size_t rhsLength = strlen(rhs);
			length_ = lhs.length_ + rhsLength;
			size_ = length_ + 1;
			data_ = static_cast<char*>(malloc(size_ * 2));
			this->IncInstCounter();
			temp_ = data_ + size_;
			memcpy(data_, lhs.data_, lhs.length_);
			memcpy(data_ + lhs.length_, rhs, rhsLength);
			data_[length_] = '\0';
		}
		String(const String& lhs, const char rhs) :
			size_(lhs.length_ + 2),
			length_(lhs.length_ + 1),
			data_(static_cast<char*>(malloc(size_ * 2))),
			temp_(data_ + size_)
		{
			memcpy(data_, lhs.data_, lhs.length_);
			data_[lhs.length_] = rhs;
			data_[length_] = '\0';
			this->IncInstCounter();
		}
		String(const String& lhs, const int16_t rhs) :
			size_(0),
			length_(0),
			data_(nullptr),
			temp_(nullptr)
		{
			char buffer[INT16_MAX_CHR_COUNT];
			snprintf(buffer, INT16_MAX_CHR_COUNT, "%hd", rhs);
			size_t rhsLength = strlen(buffer);
			length_ = lhs.length_ + rhsLength;
			size_ = length_ + 1;
			data_ = static_cast<char*>(malloc(size_ * 2));
			temp_ = data_ + size_;
			memcpy(data_, lhs.data_, lhs.length_);
			memcpy(data_ + lhs.length_, buffer, rhsLength);
			data_[length_] = '\0';
			this->IncInstCounter();
		}
		String(const String& lhs, const uint16_t rhs) :
			size_(0),
			length_(0),
			data_(nullptr),
			temp_(nullptr)
		{
			char buffer[UINT16_MAX_CHR_COUNT];
			snprintf(buffer, UINT16_MAX_CHR_COUNT, "%hu", rhs);
			size_t rhsLength = strlen(buffer);
			length_ = lhs.length_ + rhsLength;
			size_ = length_ + 1;
			data_ = static_cast<char*>(malloc(size_ * 2));
			temp_ = data_ + size_;
			memcpy(data_, lhs.data_, lhs.length_);
			memcpy(data_ + lhs.length_, buffer, rhsLength);
			data_[length_] = '\0';
			this->IncInstCounter();
		}
		String(const String& lhs, const int32_t rhs) :
			size_(0),
			length_(0),
			data_(nullptr),
			temp_(nullptr)
		{
			char buffer[INT32_MAX_CHR_COUNT];
			snprintf(buffer, INT32_MAX_CHR_COUNT, "%d", rhs);
			size_t rhsLength = strlen(buffer);
			length_ = lhs.length_ + rhsLength;
			size_ = length_ + 1;
			data_ = static_cast<char*>(malloc(size_ * 2));
			temp_ = data_ + size_;
			memcpy(data_, lhs.data_, lhs.length_);
			memcpy(data_ + lhs.length_, buffer, rhsLength);
			data_[length_] = '\0';
			this->IncInstCounter();
		}
		String(const String& lhs, const uint32_t rhs) :
			size_(0),
			length_(0),
			data_(nullptr),
			temp_(nullptr)
		{
			char buffer[UINT32_MAX_CHR_COUNT];
			snprintf(buffer, UINT32_MAX_CHR_COUNT, "%u", rhs);
			size_t rhsLength = strlen(buffer);
			length_ = lhs.length_ + rhsLength;
			size_ = length_ + 1;
			data_ = static_cast<char*>(malloc(size_ * 2));
			temp_ = data_ + size_;
			memcpy(data_, lhs.data_, lhs.length_);
			memcpy(data_ + lhs.length_, buffer, rhsLength);
			data_[length_] = '\0';
			this->IncInstCounter();
		}
		String(const String& lhs, const int64_t rhs) :
			size_(0),
			length_(0),
			data_(nullptr),
			temp_(nullptr)
		{
			char buffer[INT64_MAX_CHR_COUNT];
			snprintf(buffer, INT64_MAX_CHR_COUNT, "%lld", rhs);
			size_t rhsLength = strlen(buffer);
			length_ = lhs.length_ + rhsLength;
			size_ = length_ + 1;
			data_ = static_cast<char*>(malloc(size_ * 2));
			temp_ = data_ + size_;
			memcpy(data_, lhs.data_, lhs.length_);
			memcpy(data_ + lhs.length_, buffer, rhsLength);
			data_[length_] = '\0';
			this->IncInstCounter();
		}
		String(const String& lhs, const uint64_t rhs) :
			size_(0),
			length_(0),
			data_(nullptr),
			temp_(nullptr)
		{
			char buffer[UINT64_MAX_CHR_COUNT];
			snprintf(buffer, UINT64_MAX_CHR_COUNT, "%llu", rhs);
			size_t rhsLength = strlen(buffer);
			length_ = lhs.length_ + rhsLength;
			size_ = length_ + 1;
			data_ = static_cast<char*>(malloc(size_ * 2));
			temp_ = data_ + size_;
			memcpy(data_, lhs.data_, lhs.length_);
			memcpy(data_ + lhs.length_, buffer, rhsLength);
			data_[length_] = '\0';
			this->IncInstCounter();
		}
		String(const String& lhs, const float rhs) :
			size_(0),
			length_(0),
			data_(nullptr),
			temp_(nullptr)
		{
			char buffer[FLOAT_MAX_CHR_COUNT];
			snprintf(buffer, FLOAT_MAX_CHR_COUNT, "%g", rhs);
			size_t rhsLength = strlen(buffer);
			length_ = lhs.length_ + rhsLength;
			size_ = length_ + 1;
			data_ = static_cast<char*>(malloc(size_ * 2));
			temp_ = data_ + size_;
			memcpy(data_, lhs.data_, lhs.length_);
			memcpy(data_ + lhs.length_, buffer, rhsLength);
			data_[length_] = '\0';
			this->IncInstCounter();
		}
		String(const String& lhs, const double rhs) :
			size_(0),
			length_(0),
			data_(nullptr),
			temp_(nullptr)
		{
			char buffer[DOUBLE_MAX_CHR_COUNT];
			snprintf(buffer, DOUBLE_MAX_CHR_COUNT, "%g", rhs);
			size_t rhsLength = strlen(buffer);
			length_ = lhs.length_ + rhsLength;
			size_ = length_ + 1;
			data_ = static_cast<char*>(malloc(size_ * 2));
			temp_ = data_ + size_;
			memcpy(data_, lhs.data_, lhs.length_);
			memcpy(data_ + lhs.length_, buffer, rhsLength);
			data_[length_] = '\0';
			this->IncInstCounter();
		}

		inline void IncInstCounter() const {
			++s_instanceCounter_;
			++s_totalInstancesCreated_;
		}

		inline void SetNewLength(size_t newLength) {
			data_[newLength] = '\0';
			length_ = newLength;
		}

		inline void CheckSizeAndReallocate(size_t newLength) {
			if (newLength < size_) return;
			size_ = size_ * 2 + newLength;
			data_ = static_cast<char*>(realloc(data_, size_ * 2));
			temp_ = data_ + size_;
		}

		inline void MemCpyCheckData(size_t index, const char* source, size_t size) const {
			size_t offset = source - data_;
			if (offset < 0 || offset >= static_cast<int>(length_)) memcpy(data_ + index, source, size);
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
		size_t size_;
		size_t length_;
		char* data_;
		char* temp_;
	};
}
