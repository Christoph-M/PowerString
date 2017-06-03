#pragma once

#include <cstring>
#include <cstdio>
#include <inttypes.h>


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
		static String ToString(const char* const other)					{ return String(other);			}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Converts a c-string to a Power::String.
		/// @param[in] other The c-string to be converted.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use ToString(const char) instead.
		/// @param[in] length The length of the c-string excluding the null character.
		/// @return A Power::String with the content of other.
		///
		static String ToString(const char* const other, size_t length)	{ return String(other, length); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Converts a character to a Power::String
		/// @param[in] c The character to be converted.
		/// @return A Power::String with the single character c.
		///
		static String ToString(const char c)							{ return String(c);				}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Converts a signed short value to a Power::String.
		/// @param[in] value The signed short value to be converted.
		/// @return A Power::String containing the signed short value.
		///
		static String ToString(const int16_t value) {
			char buffer[INT16_MAX_CHR_COUNT];
			snprintf(buffer, INT16_MAX_CHR_COUNT, "%hd", value);
			return String(buffer, static_cast<size_t>(INT16_MAX_CHR_COUNT));
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Converts an unsigned short value to a Power::String.
		/// @param[in] value The unsigned short value to be converted.
		/// @return A Power::String containing the unsigned short value.
		///
		static String ToString(const uint16_t value) {
			char buffer[UINT16_MAX_CHR_COUNT];
			snprintf(buffer, UINT16_MAX_CHR_COUNT, "%hu", value);
			return String(buffer, static_cast<size_t>(UINT16_MAX_CHR_COUNT));
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Converts a signed integer value to a Power::String.
		/// @param[in] value The signed integer value to be converted.
		/// @return A Power::String containing the signed integer value.
		///
		static String ToString(const int32_t value) {
			char buffer[INT32_MAX_CHR_COUNT];
			snprintf(buffer, INT32_MAX_CHR_COUNT, "%d", value);
			return String(buffer, static_cast<size_t>(INT32_MAX_CHR_COUNT));
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Converts an unsigned integer value to a Power::String.
		/// @param[in] value The unsigned integer value to be converted.
		/// @return A Power::String containing the unsigned integer value.
		///
		static String ToString(const uint32_t value) {
			char buffer[UINT32_MAX_CHR_COUNT];
			snprintf(buffer, UINT32_MAX_CHR_COUNT, "%u", value);
			return String(buffer, static_cast<size_t>(UINT32_MAX_CHR_COUNT));
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Converts a signed long long value to a Power::String.
		/// @param[in] value The signed long long value to be converted.
		/// @return A Power::String containing the signed long long value.
		///
		static String ToString(const int64_t value) {
			char buffer[INT64_MAX_CHR_COUNT];
			snprintf(buffer, INT64_MAX_CHR_COUNT, "%lld", value);
			return String(buffer, static_cast<size_t>(INT64_MAX_CHR_COUNT));
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Converts an unsigned long long value to a Power::String.
		/// @param[in] value The unsigned long long value to be converted.
		/// @return A Power::String containing the unsigned long long value.
		///
		static String ToString(const uint64_t value) {
			char buffer[UINT64_MAX_CHR_COUNT];
			snprintf(buffer, UINT64_MAX_CHR_COUNT, "%llu", value);
			return String(buffer, static_cast<size_t>(UINT64_MAX_CHR_COUNT));
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Converts a float value to a Power::String.
		/// @param[in] value The float value to be converted.
		/// @return A Power::String containing the float value.
		///
		static String ToString(const float value) {
			char buffer[FLOAT_MAX_CHR_COUNT];
			snprintf(buffer, FLOAT_MAX_CHR_COUNT, "%g", value);
			return String(buffer, static_cast<size_t>(FLOAT_MAX_CHR_COUNT));
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Converts a double value to a Power::String.
		/// @param[in] value The double value to be converted.
		/// @return A Power::String containing the double value.
		///
		static String ToString(const double value) {
			char buffer[DOUBLE_MAX_CHR_COUNT];
			snprintf(buffer, DOUBLE_MAX_CHR_COUNT, "%g", value);
			return String(buffer, static_cast<size_t>(DOUBLE_MAX_CHR_COUNT));
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Merge-->
		/// @brief Merges two Power::Strings into one.
		/// @param[in] lhs Left-hand side of the merged Power::String.
		/// @param[in] rhs Right-hand side of the merged Power::String.
		/// @return A Power::String containing lhs+rhs.
		///
		inline static String Merge(const String& lhs, const String& rhs)		{ return String(lhs, rhs); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges a Power::String with a c-string.
		/// @param[in] lhs Left-hand side of the merged Power::String.
		/// @param[in] rhs Right-Hand side of the merged Power::String.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Merge(const String&, const char) instead.
		/// @return A Power::String containing lhs+rhs.
		///
		inline static String Merge(const String& lhs, const char* const rhs)	{ return String(lhs, rhs); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges a Power::String with a character.
		/// @param[in] lhs Left-hand side of the merged Power::String.
		/// @param[in] rhs Right-hand side of the merged Power::String.
		/// @return A Power::String containing lhs+rhs.
		///
		inline static String Merge(const String& lhs, const char rhs)			{ return String(lhs, rhs); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Join-->
		/// @brief Merges multiple Power::Strings with the specified seperator between each Power::String.
		/// @param[in] space The seperator which will be placed between each Power::String.
		/// @param[in] others A pointer to an array of Power::Strings to be merged.
		/// @param[in] size The size of the specified Power::String array.
		/// @return A Power::String containing the merged Power::Strings.
		///
		inline static String Join(const String& space, const String* const others, size_t size) {
			size_t totalLength = (size - 1) * space.length_;
			for (size_t i = 0; i < size; ++i)
				totalLength += others[i].length_;
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
		inline static String Join(const char* const space, const String* const others, size_t size) {
			size_t spaceLength = strlen(space);
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
		inline static String Join(const char* const space, const char* const* const others, size_t size) {
			size_t spaceLength = strlen(space);
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
		String();

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Initializes a new Power::String with the specified capacity.
		/// @param[in] size The capacity the new Power::String shall have.
		///
		explicit String(size_t size);

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Initializes a new Power::String containing the specified c-string.
		/// @param[in] data The c-string with the data.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use String(const char) instead.
		/// @note Implicit conversion constructor. Direct assignment of c-string possible.
		/// @note <b>If the length of the c-string is already known, it is recommended to use String(const char* const, size_t) instead as it is faster</b>
		///
		String(const char* const data);

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Initializes a new Power::String containing the specified character.
		/// @param[in] c The character.
		/// @note Implicit conversion constructor. Direct assignment of character possible.
		///
		String(const char c);

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Initializes a new Power::String containing the specified c-string.
		/// @param[in] data The c-string with the data.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use String(const char) instead.
		/// @param[in] length The length of the c-string excluding the null character.
		///
		String(const char* const data, size_t length);

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Initializes a new Power::String and fills it to the specified length with the specified character.
		/// @param[in] c The character to fill with.
		/// @param[in] length The length of the new Power::String.
		///
		String(const char c, size_t length);

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Initializes a copy of the specified Power::String.
		/// @param[in] other The Power::String to copy.
		///
		String(const String& other);

		inline void operator=(const String& other) {
			this->CheckSizeAndReallocate(other.length_);
			memcpy(data_, other.data_, other.length_ + 1);
			length_ = other.length_;
		}
		inline void operator=(const char* const data) {
			size_t newLength = strlen(data);
			this->CheckSizeAndReallocate(newLength);
			memcpy(data_, data, newLength + 1);
			length_ = newLength;
		}
		inline void operator=(const char c) {
			this->CheckSizeAndReallocate(1);
			*data_ = c;
			data_[1] = '\0';
			length_ = 1;
		}

		inline String operator+(const String& other)		const { return String(*this, other); }
		inline String operator+(const char* const other)	const { return String(*this, other); }
		inline String operator+(const char c)				const { return String(*this, c);	 }
		inline String operator+(const int16_t value)		const { return String(*this, value); }
		inline String operator+(const uint16_t value)		const { return String(*this, value); }
		inline String operator+(const int32_t value)		const { return String(*this, value); }
		inline String operator+(const uint32_t value)		const { return String(*this, value); }
		inline String operator+(const int64_t value)		const { return String(*this, value); }
		inline String operator+(const uint64_t value)		const { return String(*this, value); }
		inline String operator+(const float value)			const { return String(*this, value); }
		inline String operator+(const double value)			const { return String(*this, value); }

		inline void operator+=(const String& other) {
			size_t newLength = length_ + other.length_;
			this->CheckSizeAndReallocate(newLength);
			memcpy(data_ + length_, other.data_, other.length_ + 1);
			length_ = newLength;
		}
		inline void operator+=(const char* const other) {
			size_t otherLength = strlen(other);
			size_t newLength = length_ + otherLength;
			this->CheckSizeAndReallocate(newLength);
			memcpy(data_ + length_, other, otherLength + 1);
			length_ = newLength;
		}
		inline void operator+=(const char c) {
			this->CheckSizeAndReallocate(++length_);
			data_[length_ - 1] = c;
			data_[length_] = '\0';
		}
		inline void operator+=(const int16_t value) {
			char buffer[INT16_MAX_CHR_COUNT];
			snprintf(buffer, INT16_MAX_CHR_COUNT, "%hd", value);
			size_t otherLength = strlen(buffer);
			size_t newLength = length_ + otherLength;
			this->CheckSizeAndReallocate(newLength);
			memcpy(data_ + length_, buffer, otherLength + 1);
			length_ = newLength;
		}
		inline void operator+=(const uint16_t value) {
			char buffer[UINT16_MAX_CHR_COUNT];
			snprintf(buffer, UINT16_MAX_CHR_COUNT, "%hu", value);
			size_t otherLength = strlen(buffer);
			size_t newLength = length_ + otherLength;
			this->CheckSizeAndReallocate(newLength);
			memcpy(data_ + length_, buffer, otherLength + 1);
			length_ = newLength;
		}
		inline void operator+=(const int32_t value) {
			char buffer[INT32_MAX_CHR_COUNT];
			snprintf(buffer, INT32_MAX_CHR_COUNT, "%d", value);
			size_t otherLength = strlen(buffer);
			size_t newLength = length_ + otherLength;
			this->CheckSizeAndReallocate(newLength);
			memcpy(data_ + length_, buffer, otherLength + 1);
			length_ = newLength;
		}
		inline void operator+=(const uint32_t value) {
			char buffer[UINT32_MAX_CHR_COUNT];
			snprintf(buffer, UINT32_MAX_CHR_COUNT, "%u", value);
			size_t otherLength = strlen(buffer);
			size_t newLength = length_ + otherLength;
			this->CheckSizeAndReallocate(newLength);
			memcpy(data_ + length_, buffer, otherLength + 1);
			length_ = newLength;
		}
		inline void operator+=(const int64_t value) {
			char buffer[INT64_MAX_CHR_COUNT];
			snprintf(buffer, INT64_MAX_CHR_COUNT, "%lld", value);
			size_t otherLength = strlen(buffer);
			size_t newLength = length_ + otherLength;
			this->CheckSizeAndReallocate(newLength);
			memcpy(data_ + length_, buffer, otherLength + 1);
			length_ = newLength;
		}
		inline void operator+=(const uint64_t value) {
			char buffer[UINT64_MAX_CHR_COUNT];
			snprintf(buffer, UINT64_MAX_CHR_COUNT, "%llu", value);
			size_t otherLength = strlen(buffer);
			size_t newLength = length_ + otherLength;
			this->CheckSizeAndReallocate(newLength);
			memcpy(data_ + length_, buffer, otherLength + 1);
			length_ = newLength;
		}
		inline void operator+=(const float value) {
			char buffer[FLOAT_MAX_CHR_COUNT];
			snprintf(buffer, FLOAT_MAX_CHR_COUNT, "%g", value);
			size_t otherLength = strlen(buffer);
			size_t newLength = length_ + otherLength;
			this->CheckSizeAndReallocate(newLength);
			memcpy(data_ + length_, buffer, otherLength + 1);
			length_ = newLength;
		}
		inline void operator+=(const double value) {
			char buffer[DOUBLE_MAX_CHR_COUNT];
			snprintf(buffer, DOUBLE_MAX_CHR_COUNT, "%g", value);
			size_t otherLength = strlen(buffer);
			size_t newLength = length_ + otherLength;
			this->CheckSizeAndReallocate(newLength);
			memcpy(data_ + length_, buffer, otherLength + 1);
			length_ = newLength;
		}

		inline char operator[](size_t i) const { return *(data_ + i); }
		inline operator const char*() const { return data_; }

		inline bool operator==(const String& other)		const	{ return length_ == other.length_ && memcmp(data_, other.data_, other.length_) == 0;	}
		inline bool operator==(const char* const other) const	{ return strcmp(data_, other) == 0;														}
		inline bool operator==(const char c)			const	{ return length_ == 1 && *data_ == c;													}
		inline bool operator!=(const String& other)		const	{ return length_ != other.length_ || memcmp(data_, other.data_, other.length_) != 0;	}
		inline bool operator!=(const char* const other) const	{ return strcmp(data_, other) != 0;														}
		inline bool operator!=(const char c)			const	{ return length_ > 1 || *data_ != c;													}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Size-->
		/// @brief Gets the current capacity of the Power::String.
		/// @return The current capacity of the Power::String.
		///
		inline size_t		Size()		const { return size_;	}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Length-->
		/// @brief Gets the current length excluding the null character of the Power::String.
		/// @return The current length excluding the null character of the Power::String.
		///
		inline size_t		Length()	const { return length_;	}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--CString-->
		/// @brief Gets the underlying c-string as a constant.
		/// @return The underlying c-string as a constant.
		///
		inline const char*	CString()	const { return data_;	}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--ShrinkToFit-->
		/// @brief Shrinks the capacity of the Power::String to fit the length to conserve memory.
		///
		inline void ShrinkToFit() {
			if (length_ + 1 == size_) return;
			size_ = length_ + 1;
			char* newData = new char[size_ * 2] { '\0' };
			this->IncInstCounter();
			memcpy(newData, data_, length_);
			delete[](data_);
			--s_instanceCounter_;
			data_ = newData;
			temp_ = data_ + size_;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Concatenate-->
		/// @brief Merges the Power::String with another Power::String.
		/// @param[in] other The Power::String to be merged with.
		///
		inline void Concatenate(const String& other) {
			size_t newLength = length_ + other.length_;
			this->CheckSizeAndReallocate(newLength);
			memcpy(data_ + length_, other.data_, other.length_ + 1);
			length_ = newLength;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges the Power::String with a c-string.
		/// @param[in] other The c-string to be merged with.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Concatenate(const char) instead.
		/// @note <b>If the length of the c-string is already known, it is recommend to use Concatenate(const char* const, size_t) instead as it is faser.</b>
		///
		inline void Concatenate(const char* const other) {
			size_t otherLength = strlen(other);
			size_t newLength = length_ + otherLength;
			this->CheckSizeAndReallocate(newLength);
			memcpy(data_ + length_, other, otherLength + 1);
			length_ = newLength;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges the Power::String with a c-string.
		/// @param[in] other The c-string to be merged with.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Concatenate(const char) instead.
		/// @param[in] length The length of the c-string excluding the null character.
		///
		inline void Concatenate(const char* const other, size_t length) {
			size_t newLength = length_ + length;
			this->CheckSizeAndReallocate(newLength);
			memcpy(data_ + length_, other, length + 1);
			length_ = newLength;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Merges the Power::String with a character.
		/// @param[in] c The character to be merged with.
		///
		inline void Concatenate(const char c) {
			this->CheckSizeAndReallocate(++length_);
			data_[length_ - 1] = c;
			data_[length_] = '\0';
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Contains-->
		/// @brief Checks the Power::String if it contains the specified Power::String.
		/// @param[in] other The Power::String to be checked for.
		/// @return <span style="color:#30AA00">True</span>, if the Power::String contains the spcified Power::String.
		/// @return <span style="color:#CC3000">False</span>, if it doesn't or if the length of the specified Power::String is greater than the Power::String.
		///
		inline bool Contains(const String& other) const {
			if (other.length_ > length_) return false;
			for (size_t i = 0; i < length_ - other.length_; ++i) {
				if (memcmp(data_ + i, other.data_, other.length_) == 0) return true;
			}
			return false;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Checks the Power::String if it contains the specified c-string.
		/// @param[in] other The c-string to be checked for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Contains(const char) const instead.
		/// @return <span style="color:#30AA00">True</span>, if the Power::String contains the spcified c-string.
		/// @return <span style="color:#CC3000">False</span>, if it doesn't or if the length of the specified c-string is greater than the Power::String.
		/// @note <b>If the length of the c-string is already known, it is recommended to use Contains(const char* const, size_t) const instead as it is faster.</b>
		///
		inline bool Contains(const char* const other) const {
			size_t otherLength = strlen(other);
			if (otherLength > length_) return false;
			for (size_t i = 0; i < length_ - otherLength; ++i) {
				if (memcmp(data_ + i, other, otherLength) == 0) return true;
			}
			return false;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Checks the Power::String if it contains the specified c-string.
		/// @param[in] other The c-string to be checked for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Contains(const char) const instead.
		/// @param[in] length The length of the c-string excluding the null character.
		/// @return <span style="color:#30AA00">True</span>, if the Power::String contains the spcified c-string.
		/// @return <span style="color:#CC3000">False</span>, if it doesn't or if the length of the specified c-string is greater than the Power::String.
		///
		inline bool Contains(const char* const other, size_t length) const {
			if (length > length_) return false;
			for (size_t i = 0; i < length_ - length; ++i) {
				if (memcmp(data_ + i, other, length) == 0) return true;
			}
			return false;
		}

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
		/// @return Or -1 if the specified Power::String does not occur.
		///
		inline int IndexOf(const String& other, size_t begin) const { 
			if (begin >= length_ || other.length_ > length_) return -1;
			char* p = strstr(data_ + begin, other.data_);
			return p ? static_cast<int>(p - data_) : -1;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the first occurance of the specified Power::String between the specified start and end index.
		/// @param[in] other The Power::String to look for.
		/// @param[in] begin The index from where to start looking.
		/// @param[in] end The index to where to stop looking.
		/// @return The start index of the first occurance of the specified Power::String.
		/// @return Or -1 if the specified Power::String does not occur.
		///
		int IndexOf(const String& other, size_t begin, size_t end) const;

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the first occurance of the specified c-string.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use IndexOf(const char) const instead.
		/// @return The start index of the first occurance of the specified c-string.
		/// @return Or -1 if the specified c-string does not occur.
		/// @note <b>If the length of the c-string is already known, it is recommended to use IndexOf(size_t, const char* const) const instead as it is faster.</b>
		///
		inline int IndexOf(const char* const other) const {
			char* p = strstr(data_, other);
			return p ? static_cast<int>(p - data_) : -1;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the first occurance of the specified c-string starting from the specified index.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use IndexOf(const char, size_t) const instead.
		/// @param[in] begin The index from where to start looking.
		/// @return The start index of the first occurance of the specified c-string.
		/// @return Or -1 if the specified c-string does not occur.
		/// @note <b>If the length of the c-string is already known, it is recommended to use IndexOf(size_t, const char* const, size_t) const instead as it is faster.</b>
		///
		inline int IndexOf(const char* const other, size_t begin) const {
			if (begin >= length_) return -1;
			char* p = strstr(data_ + begin, other);
			return p ? static_cast<int>(p - data_) : -1;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the first occurance of the specified c-string between the specified start and end index.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use IndexOf(const char, size_t, size_t) const instead.
		/// @param[in] begin The index from where to start looking.
		/// @param[in] end The index to where to stop looking.
		/// @return The start index of the first occurance of the specified c-string.
		/// @return Or -1 if the specified c-string does not occur.
		/// @note <b>If the length of the c-string is already known, it is recommended to use IndexOf(size_t, const char* const, size_t, size_t) const instead as it is faster.</b>
		///
		int IndexOf(const char* const other, size_t begin, size_t end) const;

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
		/// @return Or -1 if the specified c-string does not occur.
		///
		inline int IndexOf(size_t length, const char* const other, size_t begin) const {
			if (begin >= length_ || length > length_) return -1;
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
		/// @return The start index of the first occurance of the specified c-string.
		/// @return Or -1 if the specified c-string does not occur.
		///
		int IndexOf(size_t length, const char* const other, size_t begin, size_t end) const;

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
		/// @return Or -1 if the specified character does not occur.
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
		/// @return The index of the first occurance of the specified character.
		/// @return Or -1 if the specified character does not occur.
		///
		inline int IndexOf(const char c, size_t begin, size_t end) const {
			if (begin >= length_ || end > length_ || begin > end) return -1;
			char* p = static_cast<char*>(memchr(data_ + begin, c, end - begin));
			return p ? static_cast<int>(p - data_) : -1;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--LastIndexOf-->
		/// @brief Finds the last occurance of the specified Power::String.
		/// @param[in] other The Power::String to look for.
		/// @return The start index of the last occurance of the specified Power::String.
		/// @return Or -1 if the spcified Power::String does not occur.
		///
		inline	int LastIndexOf(const String& other)							const { return this->LastIndexOf(other, 0, length_);		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the last occurance of the specified Power::String starting from the specified index.
		/// @param[in] other The Power::String for look for.
		/// @param[in] begin The index from where to start lookin.
		/// @return The start index of the last occurance of the specified Power::String.
		/// @return Or -1 if the spcified Power::String does not occur.
		///
		inline	int LastIndexOf(const String& other, size_t begin)				const { return this->LastIndexOf(other, begin, length_);	}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the last occurance of the specified Power::String between the specified start and end index.
		/// @param[in] other The Power::String for look for.
		/// @param[in] begin The index from where to start lookin.
		/// @param[in] end The index to where to stop looking.
		/// @return The start index of the last occurance of the specified Power::String.
		/// @return Or -1 if the spcified Power::String does not occur.
		///
				int LastIndexOf(const String& other, size_t begin, size_t end)	const;
				
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the last occurance of the specified c-string.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use LastIndexOf(const char) const instead.
		/// @return The start index of the last occurance of the specified c-string.
		/// @return Or -1 if the specified c-string does not occur.
		/// @note <b>If the length of the c-string is already known, it is recommended to use LastIndexOf(size_t, const char* const) const instead as it is faster.</b>
		///
		inline	int LastIndexOf(const char* const other)							const { return this->LastIndexOf(other, 0, length_);		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the last occurance of the specified c-string starting from the specified index.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use LastIndexOf(const char, size_t) const instead.
		/// @param[in] begin The index from where to start looking.
		/// @return The start index of the last occurance of the specified c-string.
		/// @return Or -1 if the specified c-string does not occur.
		/// @note <b>If the length of the c-string is already known, it is recommended to use LastIndexOf(size_t, const char* const, size_t) const instead as it is faster.</b>
		///
		inline	int LastIndexOf(const char* const other, size_t begin)				const { return this->LastIndexOf(other, begin, length_);	}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the last occurance of the specified c-string between the specified start and end index.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use LastIndexOf(const char, size_t, size_t) const instead.
		/// @param[in] begin The index from where to start looking.
		/// @param[in] end The index to where to stop looking.
		/// @return The start index of the last occurance of the specified c-string.
		/// @return Or -1 if the specified c-string does not occur.
		/// @note <b>If the length of the c-string is already known, it is recommended to use LastIndexOf(size_t, const char* const, size_t, size_t) const instead as it is faster.</b>
		///
				int LastIndexOf(const char* const other, size_t begin, size_t end)	const;

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the last occurance of the specified c-string.
		/// @param[in] length The length of the specified c-string excluding the null character.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use LastIndexOf(const char) const instead.
		/// @return The start index of the last occurance of the specified c-string.
		/// @return Or -1 if the specified c-string does not occur.
		///
		inline	int LastIndexOf(size_t length, const char* const other)								const { return this->LastIndexOf(length, other, 0, length_);		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the last occurance of the specified c-string starting from the specified index.
		/// @param[in] length The length of the specified c-string excluding the null character.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use LastIndexOf(const char, size_t) const instead.
		/// @param[in] begin The index from where to start looking.
		/// @return The start index of the last occurance of the specified c-string.
		/// @return Or -1 if the specified c-string does not occur.
		///
		inline	int LastIndexOf(size_t length, const char* const other, size_t begin)				const { return this->LastIndexOf(length, other, begin, length_);	}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the last occurance of the specified c-string between the specified start and end index.
		/// @param[in] length The length of the specified c-string excluding the null character.
		/// @param[in] other The c-string to look for.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use LastIndexOf(const char, size_t, size_t) const instead.
		/// @param[in] begin The index from where to start looking.
		/// @param[in] end The index to where to stop looking.
		/// @return The start index of the last occurance of the specified c-string.
		/// @return Or -1 if the specified c-string does not occur.
		///
				int LastIndexOf(size_t length, const char* const other, size_t begin, size_t end)	const;

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
		/// @return The index of the last occurance of the specified character.
		/// @return Or -1 if the specified character does not occur.
		///
		inline int LastIndexOf(const char c, size_t begin) const {
			if (begin >= length_) return -1;
			char* p = strrchr(data_ + begin, c);
			return p ? static_cast<int>(p - data_) : -1;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Finds the last occurance of the specified character between the specified start and end index.
		/// @param[in] c The character to look for.
		/// @param[in] begin The index from where to start looking.
		/// @param[in] end The index to where to stop looking.
		/// @return The index of the last occurance of the specified character.
		/// @return Or -1 if the specified character does not occur.
		///
		inline int LastIndexOf(const char c, size_t begin, size_t end) const {
			if (begin >= length_ || end > length_ || begin > end) return -1;
			for (size_t i = end; i >= begin; --i) if (data_[i] == c) return static_cast<int>(i);
			return -1;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Count-->
		/// @brief TODO: Document
		///
		inline size_t Count(const String& other, size_t begin, size_t end) const {
			size_t count = 0;
			int curIndex = this->IndexOf(other, begin, end);
			while (curIndex != -1) {
				++count;
				curIndex = this->IndexOf(other, curIndex + 1, end);
			}
			return count;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief TODO: Document
		///
		inline size_t Count(const char* const other, size_t begin, size_t end) const {
			size_t count = 0;
			int curIndex = this->IndexOf(other, begin, end);
			while (curIndex != -1) {
				++count;
				curIndex = this->IndexOf(other, curIndex + 1, end);
			}
			return count;
		}
		
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief TODO: Document
		///
		inline size_t Count(size_t length, const char* const other, size_t begin, size_t end) const {
			size_t count = 0;
			int curIndex = this->IndexOf(length, other, begin, end);
			while (curIndex != -1) {
				++count;
				curIndex = this->IndexOf(length, other, curIndex + 1, end);
			}
			return count;
		}
		
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief TODO: Document
		///
		inline size_t Count(const char c, size_t begin, size_t end) const {
			size_t count = 0;
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
		/// @param[in] other The Power::String to be inserted.
		///
		void Insert(size_t index, const String& other);

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Inserts the specified c-string at the specified index.
		/// @param[in] index The index where the specified c-string will be inserted at.
		/// @param[in] other The c-string to be inserted.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Insert(size_t, const char) instead.
		/// @note <b>If the length of the c-string is already known, it is recommended to use Insert(sizt_t, const char* const, size_t) instead as it is faster.</b>
		///
		void Insert(size_t index, const char* const other);

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Inserts the specified c-string at the specified index.
		/// @param[in] index The index where the specified c-string will be inserted at.
		/// @param[in] other The c-string to be inserted.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Insert(size_t, const char) instead.
		/// @param[in] length The length of the c-string excluding the null character.
		///
		void Insert(size_t index, const char* const other, size_t length);

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Inserts the specified character at the specified index.
		/// @param[in] index The index where the specified character will be inserted at.
		/// @param[in] c The character to be inserted.
		///
		void Insert(size_t index, const char c);

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Remove-->
		/// @brief Removes all characters in the Power::Strig starting from the specified index.
		/// @param[in] index The index from where to start.
		///
		inline	void Remove(size_t index) { this->Remove(index, length_ - 1); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Removed a specified amount of characters in the Power::String starting from the specified index.
		/// @param[in] index The index from where to start.
		/// @param[in] count How many characters shall be removed.
		///
				void Remove(size_t index, size_t count);

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--RemoveAll-->
		/// @brief Removes all occurances of the specified Power::String.
		/// @param[in] other The Power::String to remove.
		///
		void RemoveAll(const String& other);

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Removes all occurances of the specified c-string.
		/// @param[in] other The c-string to remove.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use RemoveAll(const char) instead.
		/// @node <b>If the length of the c-string is already known, it is recommended to use RemoveAll(const char* const, size_t) instead as it is faster.</b>
		///
		void RemoveAll(const char* const other);

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Removes all occurances of the specified c-string.
		/// @param[in] other The c-string to remove.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use RemoveAll(const char) instead.
		/// @param[in] length The length of the c-string excluding the null character.
		///
		void RemoveAll(const char* const other, size_t length);

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Removes all occurances of the specified character.
		/// @param[in] c The character to remove.
		///
		void RemoveAll(const char c);

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Replace-->
		/// @brief Replaces all characters from the specified start index with the specified Power::String.
		/// @param[in] index The index from where to replace.
		/// @param[in] other The Power::String with which to replace.
		///
		inline	void Replace(size_t index, const String& other)						{ this->Replace(index, length_ - 1, other);			}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Replaces a specified amount of characters from the specified start index with the specified Power::String.
		/// @param[in] index The index from where to replace.
		/// @param[in] count How many characters will be replaced.
		/// @param[in] other The Power::String with which to replace.
		///
				void Replace(size_t index, size_t count, const String& other);

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Replaces all characters from the specified start index with the specified c-string.
		/// @param[in] index The index from where to replace.
		/// @param[in] other The c-string with which to replace.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Replace(size_t, const char) instead.
		/// @node <b>If the length of the c-string is already known, it is recommended to use Replace(size_t, const char* const, size_t) instead as it is faster.</b>
		///
		inline	void Replace(size_t index, const char* const other)					{ this->Replace(index, length_ - 1, other);			}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Replaces all characters from the specified start index with the specified c-string.
		/// @param[in] index The index from where to replace.
		/// @param[in] count How many characters will be replaced.
		/// @param[in] other The c-string with which to replace.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Replace(size_t, size_t, const char) instead.
		/// @node <b>If the length of the c-string is already known, it is recommended to use Replace(size_t, const char* const, size_t) instead as it is faster.</b>
		///
				void Replace(size_t index, size_t count, const char* const other);

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Replaces all characters from the specified start index with the specified c-string.
		/// @param[in] index The index from where to replace.
		/// @param[in] other The c-string with which to replace.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Replace(size_t, const char) instead.
		/// @param[in] length The length of the c-string excluding the null character.
		///
		inline	void Replace(size_t index, const char* const other, size_t length)	{ this->Replace(index, length_ - 1, other, length);	}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Replaces all characters from the specified start index with the specified c-string.
		/// @param[in] index The index from where to replace.
		/// @param[in] count How many characters will be replaced.
		/// @param[in] other The c-string with which to replace.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Replace(size_t, size_t, const char) instead.
		/// @param[in] length The length of the c-string excluding the null character.
		///
				void Replace(size_t index, size_t count, const char* const other, size_t length);

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Replaces all characters from the specified start index with the specified character.
		/// @param[in] index The index from where to replace.
		/// @param[in] c The character with which to replace.
		///
		inline	void Replace(size_t index, const char c)							{ this->Replace(index, length_ - 1, c);				}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Replaces a specified amount of characters from the specified start index with the specified character.
		/// @param[in] index The index from where to replace.
		/// @param[in] count How many characters will be replaced.
		/// @param[in] c The character with which to replace.
		///
				void Replace(size_t index, size_t count, const char c);

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--ReplaceAt-->
		/// @brief Replaces the characters with the specified Power::String at the specified index.
		/// @param[in] index The index from where to replace.
		/// @param[in] other The Power::String with which to replace.
		///
		inline void ReplaceAt(size_t index, const String& other) {
			if (index >= length_) return;
			this->CheckSizeAndReallocate(index + other.length_);
			memcpy(data_ + index, other.data_, other.length_);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Replaces the characters with the specified c-string at the specified index.
		/// @param[in] index The index from where to replace.
		/// @param[in] other The c-string with which to replace.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use ReplaceAt(size_t, const char) instead.
		/// @node <b>If the length of the c-string is already known, it is recommended to use ReplaceAt(size_t, const char* const, size_t) instead as it is faster.</b>
		///
		inline void ReplaceAt(size_t index, const char* const other) {
			if (index >= length_) return;
			size_t otherLength = strlen(other);
			this->CheckSizeAndReallocate(index + otherLength);
			memcpy(data_ + index, other, otherLength);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Replaces the characters with the specified c-string at the specified index.
		/// @param[in] index The index from where to replace.
		/// @param[in] other The c-string with which to replace.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use ReplaceAt(size_t, const char) const instead.
		/// @param[in] length The length of the c-string excluding the null character.
		///
		inline void ReplaceAt(size_t index, const char* const other, size_t length) {
			if (index >= length_) return;
			this->CheckSizeAndReallocate(index + length);
			memcpy(data_ + index, other, length);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Replaces the character with the specified character at the specified index.
		/// @param[in] index The index at where to replace.
		/// @param[in] c The character with which to replace.
		///
		inline void ReplaceAt(size_t index, const char c) const {
			if (index >= length_) return;
			data_[index] = c;
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--Trim-->
		/// @brief Removes all leading and trailing whitespaces.
		///
		inline void Trim() { this->Trim(' '); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Removes all leading and trailing occurances of the specified character.
		/// @param[in] c The character to be trimmed.
		///
		inline void Trim(const char c) {
			size_t startIndex = 0;
			size_t endIndex = 0;
			for (size_t i = 0; i < length_; ++i) {
				if (data_[i] != c) {
					startIndex = i;
					break;
				}
			}
			for (size_t i = length_ - 1; i > startIndex; --i) {
				if (data_[i] != c) {
					endIndex = i + 1;
					break;
				}
			}
			length_ = endIndex - startIndex;
			memcpy(temp_, data_ + startIndex, length_);
			memcpy(data_, temp_, length_);
			data_[length_] = '\0';
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--TrimStart-->
		/// @brief Removes all leading whitespaces.
		///
		inline void TrimStart() { this->TrimStart(' '); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Removes all leading occurances of the specified character.
		/// @param[in] c The character to be trimmed.
		///
		inline void TrimStart(const char c) {
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
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--TrimEnd-->
		/// @brief Removes all trailing whitespaces.
		///
		inline void TrimEnd() { this->TrimEnd(' '); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Removes all trailing occurances of the specified character.
		/// @param[in] c The character to be trimmed.
		///
		inline void TrimEnd(const char c) {
			for (int i = static_cast<int>(length_) - 1; i >= 0; --i) {
				if (data_[i] != c) {
					length_ = static_cast<size_t>(i + 1);
					data_[length_] = '\0';
					break;
				}
			}
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--PadLeft-->
		/// @brief Right-aligns the Power::String by filling it to the left with whitespaces to the specified total length.
		/// @param[in] length The total length the Power::String should be including the current length of the Power::String.
		///
		inline void PadLeft(size_t length) { this->PadLeft(length, ' '); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Right-aligns the Power::String by filling it to the left with the specified character to the specified total length.
		/// @param[in] length The total length the Power::String should be including the current length of the Power::String.
		/// @param[in] c The character with which to fill.
		///
		inline void PadLeft(size_t length, char c) {
			if (length_ >= length) return;
			this->CheckSizeAndReallocate(length);
			memset(temp_, c, length - length_);
			memcpy(temp_ + length - length_, data_, length_);
			length_ = length;
			memcpy(data_, temp_, length);
			data_[length] = '\0';
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--PadRight-->
		/// @brief Left-aligns the Power::String by filling it to the right with whitespaces to the specified total length.
		/// @param[in] length The total length the Power::String should be including the current length of the Power::String.
		///
		inline void PadRight(size_t length) { this->PadRight(length, ' '); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Left-aligns the Power::String by filling it to the right with the specified character to the specified total length.
		/// @param[in] length The total length the Power::String should be including the current length of the Power::String.
		/// @param[in] c The character with which to fill.
		///
		inline void PadRight(size_t length, char c) {
			if (length_ >= length) return;
			this->CheckSizeAndReallocate(length);
			memset(temp_ + length_, c, length - length_);
			memcpy(temp_, data_, length_);
			length_ = length;
			memcpy(data_, temp_, length);
			data_[length] = '\0';
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
		inline bool StartsWith(const char* const other) const {
			size_t otherLength = strlen(other);
			if (otherLength > length_) return false;
			return memcmp(data_, other, otherLength) == 0;
		}

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
		inline bool EndsWith(const char* const other) const {
			size_t otherLength = strlen(other);
			if (otherLength > length_) return false;
			return memcmp(data_ + length_ - otherLength, other, otherLength) == 0;
		}

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
		///
		inline void Fill(const String& other) const {
			int count = static_cast<int>(length_ / other.length_);
			for (int i = 0; i < count; ++i) memcpy(data_ + i * other.length_, other.data_, other.length_);
			memcpy(data_ + count * other.length_, other.data_, length_ % other.length_);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Fills the Power::String with the specified Power::String starting from the specified index.
		/// @param[in] other The Power::String to fill with.
		/// @param[in] begin The index from where to start filling.
		///
		inline void Fill(const String& other, size_t begin) const {
			if (begin > length_) return;
			int count = static_cast<int>((length_ - begin) / other.length_);
			for (int i = 0; i < count; ++i) memcpy(data_ + begin + i * other.length_, other.data_, other.length_);
			memcpy(data_ + begin + count * other.length_, other.data_, (length_ - begin) % other.length_);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Fills the Power::String with the specified Power::String between the specified start and end index.
		/// @param[in] other The Power::String to fill with.
		/// @param[in] begin The index from where to start filling.
		/// @param[in] end The index to where to stop filling.
		///
		inline void Fill(const String& other, size_t begin, size_t end) const {
			if (end > length_) end = length_;
			if (begin > end) return;
			int count = static_cast<int>((end - begin) / other.length_);
			for (int i = 0; i < count; ++i) memcpy(data_ + begin + i * other.length_, other.data_, other.length_);
			memcpy(data_ + begin + count + other.length_, other.data_, (end - begin) % other.length_);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Fills the Power::String with the specified c-string.
		/// @param[in] other The c-string to fill with.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Fill(const char) const instead.
		/// @node <b>If the length of the c-string is already known, it is recommended to use Fill(size_t, const char* const) const instead as it is faster.</b>
		///
		inline void Fill(const char* const other) const {
			size_t otherLength = strlen(other);
			int count = static_cast<int>(length_ / otherLength);
			for (int i = 0; i < count; ++i) memcpy(data_ + i * otherLength, other, otherLength);
			memcpy(data_ + count * otherLength, other, length_ % otherLength);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Fills the Power::String with the specified c-string starting from the specified index.
		/// @param[in] other The c-string to fill with.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Fill(const char, size_t) const instead.
		/// @param[in] begin The index from where to start filling.
		/// @node <b>If the length of the c-string is already known, it is recommended to use Fill(size_t, const char* const, size_t) const instead as it is faster.</b>
		///
		inline void Fill(const char* const other, size_t begin) const {
			if (begin > length_) return;
			size_t otherLength = strlen(other);
			int count = static_cast<int>((length_ - begin) / otherLength);
			for (int i = 0; i < count; ++i) memcpy(data_ + begin + i * otherLength, other, otherLength);
			memcpy(data_ + begin + count * otherLength, other, (length_ - begin) % otherLength);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Fills the Power::String with the specified c-string between the specified start and end index.
		/// @param[in] other The c-string to fill with.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Fill(const char, size_t, size_t) const instead.
		/// @param[in] begin The index from where to start filling.
		/// @param[in] end The index to where to stop filling.
		/// @node <b>If the length of the c-string is already known, it is recommended to use Fill(size_t, const char* const, size_t, size_t) const instead as it is faster.</b>
		///
		inline void Fill(const char* const other, size_t begin, size_t end) const {
			if (end > length_) end = length_;
			if (begin > end) return;
			size_t otherLength = strlen(other);
			int count = static_cast<int>((end - begin) / otherLength);
			for (int i = 0; i < count; ++i) memcpy(data_ + begin + i * otherLength, other, otherLength);
			memcpy(data_ + begin + count * otherLength, other, (end - begin) % otherLength);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Fills the Power::String with the specified c-string.
		/// @param[in] length The length of the c-string excluding the null character.
		/// @param[in] other The c-string to fill with.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Fill(const char) const instead.
		///
		inline void Fill(size_t length, const char* const other) const {
			int count = static_cast<int>(length_ / length);
			for (int i = 0; i < count; ++i) memcpy(data_ + i * length, other, length);
			memcpy(data_ + count * length, other, length_ % length);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Fills the Power::String with the specified c-string starting from the specified index.
		/// @param[in] length The length of the c-string excluding the null character.
		/// @param[in] other The c-string to fill with.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Fill(const char, size_t) const instead.
		/// @param[in] begin The index from where to start filling.
		///
		inline void Fill(size_t length, const char* const other, size_t begin) const {
			if (begin > length_) return;
			int count = static_cast<int>((length_ - begin) / length);
			for (int i = 0; i < count; ++i) memcpy(data_ + begin + i * length, other, length);
			memcpy(data_ + begin + count * length, other, (length_ - begin) % length);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Fills the Power::String with the specified c-string between the specified start and end index.
		/// @param[in] length The length of the c-string excluding the null character.
		/// @param[in] other The c-string to fill with.
		/// \n <span style="color:#FF0000"><b>Warning</b></span>: If a pointer to a char variable is passed, the behaviour is undefined. Use Fill(const char, size_t, size_t) const instead.
		/// @param[in] begin The index from where to start filling.
		/// @param[in] end The index to where to stop filling.
		///
		inline void Fill(size_t length, const char* const other, size_t begin, size_t end) const {
			if (end > length_) end = length_;
			if (begin > end) return;
			int count = static_cast<int>((end - begin) / length);
			for (int i = 0; i < count; ++i) memcpy(data_ + begin + i * length, other, length);
			memcpy(data_ + begin + count * length, other, (end - begin) % length);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Fills the Power::String with the specified character.
		/// @param[in] c The character to fill with.
		///
		inline void Fill(const char c) const { memset(data_, c, length_); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Fills the Power::String with the specified character starting from the specified index.
		/// @param[in] c The character to fill with.
		/// @param[in] begin The index from where to start filling.
		///
		inline void Fill(const char c, size_t begin) const {
			if (begin > length_) return;
			memset(data_, c, length_ - begin);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/// @brief Fills the Power::String with the specified character between the specified start and end index.
		/// @param[in] c The character to fill with.
		/// @param[in] begin The index from where to start filling.
		/// @param[in] end The index to where to stop filling.
		///
		inline void Fill(const char c, size_t begin, size_t end) const {
			if (end > length_) end = length_;
			if (begin > end) return;
			memset(data_, c, end - begin);
		}

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--SplitAt-->
		/// @brief Splits the Power::String into two substrings at the specified index.
		/// @param[in] index The index at where to split.
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
		///
		inline void ToLower() const { _strlwr_s(data_, length_ + 1); }

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	<!--ToUpper-->
		/// @brief Converts all lower case characters to upper case.
		///
		inline void ToUpper() const { _strupr_s(data_, length_ + 1); }

		~String();

	private:
		String(const String& lhs, const String& rhs);
		String(const String& lhs, const char* const rhs);
		String(const String& lhs, const char rhs);
		String(const String& lhs, const int16_t rhs);
		String(const String& lhs, const uint16_t rhs);
		String(const String& lhs, const int32_t rhs);
		String(const String& lhs, const uint32_t rhs);
		String(const String& lhs, const int64_t rhs);
		String(const String& lhs, const uint64_t rhs);
		String(const String& lhs, const float rhs);
		String(const String& lhs, const double rhs);

		inline void IncInstCounter() const {
			++s_instanceCounter_;
			++s_totalInstancesCreated_;
		}

		inline void CheckSizeAndReallocate(size_t newLength) {
			if (newLength < size_) return;
			size_ = size_ * 2 + newLength;
			char* newData = new char[size_ * 2] { '\0' };
			this->IncInstCounter();
			memcpy(newData, data_, length_);
			delete[](data_);
			--s_instanceCounter_;
			data_ = newData;
			temp_ = data_ + size_;
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
