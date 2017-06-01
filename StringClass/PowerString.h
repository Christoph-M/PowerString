#pragma once

#include <cstring>
#include <cstdio>
#include <inttypes.h>


#define INT16_MAX_CHR_COUNT		 7
#define UINT16_MAX_CHR_COUNT	 6
#define INT32_MAX_CHR_COUNT		12
#define UINT32_MAX_CHR_COUNT	11
#define INT64_MAX_CHR_COUNT		21
#define UINT64_MAX_CHR_COUNT	21
#define FLOAT_MAX_CHR_COUNT		13
#define DOUBLE_MAX_CHR_COUNT	18


namespace Power {
	class String {
	public:
		static String ToString(const char* const other)					{ return String(other);			}
		static String ToString(const char* const other, size_t length)	{ return String(other, length); }
		static String ToString(const char c)							{ return String(c);				}
		static String ToString(const int16_t value) {
			char buffer[INT16_MAX_CHR_COUNT];
			snprintf(buffer, INT16_MAX_CHR_COUNT, "%hd", value);
			return String(buffer, static_cast<size_t>(INT16_MAX_CHR_COUNT));
		}
		static String ToString(const uint16_t value) {
			char buffer[UINT16_MAX_CHR_COUNT];
			snprintf(buffer, UINT16_MAX_CHR_COUNT, "%hu", value);
			return String(buffer, static_cast<size_t>(UINT16_MAX_CHR_COUNT));
		}
		static String ToString(const int32_t value) {
			char buffer[INT32_MAX_CHR_COUNT];
			snprintf(buffer, INT32_MAX_CHR_COUNT, "%d", value);
			return String(buffer, static_cast<size_t>(INT32_MAX_CHR_COUNT));
		}
		static String ToString(const uint32_t value) {
			char buffer[UINT32_MAX_CHR_COUNT];
			snprintf(buffer, UINT32_MAX_CHR_COUNT, "%u", value);
			return String(buffer, static_cast<size_t>(UINT32_MAX_CHR_COUNT));
		}
		static String ToString(const int64_t value) {
			char buffer[INT64_MAX_CHR_COUNT];
			snprintf(buffer, INT64_MAX_CHR_COUNT, "%lld", value);
			return String(buffer, static_cast<size_t>(INT64_MAX_CHR_COUNT));
		}
		static String ToString(const uint64_t value) {
			char buffer[UINT64_MAX_CHR_COUNT];
			snprintf(buffer, UINT64_MAX_CHR_COUNT, "%llu", value);
			return String(buffer, static_cast<size_t>(UINT64_MAX_CHR_COUNT));
		}
		static String ToString(const float value) {
			char buffer[FLOAT_MAX_CHR_COUNT];
			snprintf(buffer, FLOAT_MAX_CHR_COUNT, "%g", value);
			return String(buffer, static_cast<size_t>(FLOAT_MAX_CHR_COUNT));
		}
		static String ToString(const double value) {
			char buffer[DOUBLE_MAX_CHR_COUNT];
			snprintf(buffer, DOUBLE_MAX_CHR_COUNT, "%g", value);
			return String(buffer, static_cast<size_t>(DOUBLE_MAX_CHR_COUNT));
		}

		inline static String Merge(const String& rhs, const String& lhs)		{ return String(rhs, lhs); }
		inline static String Merge(const String& rhs, const char* const lhs)	{ return String(rhs, lhs); }
		inline static String Merge(const String& rhs, const char lhs)			{ return String(rhs, lhs); }

		inline static String Join(const String& space, const String* const others, size_t size) {
			size_t totalLength = (size - 1) * space.length_;
			for (size_t i = 0; i < size; ++i)
				totalLength += others[i].length_;
			String newString = String("", totalLength);
			char* data = newString.data_;
			for (size_t i = 0; i < size; ++i) {
				memcpy(data, others[i].data_, others[i].length_);
				memcpy(data + others[i].length_, space.data_, space.length_);
				data += others[i].length_ + space.length_;
			}
			return newString;
		}
		inline static String Join(const char* const space, const String* const others, size_t size) {
			size_t spaceLength = strlen(space);
			size_t totalLength = (size - 1) * spaceLength;
			for (size_t i = 0; i < size; ++i) totalLength += others[i].length_;
			String newString = String("", totalLength);
			char* data = newString.data_;
			for (size_t i = 0; i < size; ++i) {
				memcpy(data, others[i].data_, others[i].length_);
				memcpy(data + others[i].length_, space, spaceLength);
				data += others[i].length_ + spaceLength;
			}
			return newString;
		}
		inline static String Join(const char* const space, size_t spaceLength, const String* const others, size_t size) {
			size_t totalLength = (size - 1) * spaceLength;
			for (size_t i = 0; i < size; ++i) totalLength += others[i].length_;
			String newString = String("", totalLength);
			char* data = newString.data_;
			for (size_t i = 0; i < size; ++i) {
				memcpy(data, others[i].data_, others[i].length_);
				memcpy(data + others[i].length_, space, spaceLength);
				data += others[i].length_ + spaceLength;
			}
			return newString;
		}
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

		inline static String Join(const String& space, const char* const* const others, size_t size) {
			size_t totalLength = (size - 1) * space.length_;
			for (size_t i = 0; i < size; ++i) totalLength += strlen(others[i]);
			String newString = String("", totalLength);
			char* data = newString.data_;
			for (size_t i = 0; i < size; ++i) {
				size_t otherLength = strlen(others[i]);
				memcpy(data, others[i], otherLength);
				memcpy(data + otherLength, space.data_, space.length_);
				data += otherLength + space.length_;
			}
			return newString;
		}
		inline static String Join(const char* const space, const char* const* const others, size_t size) {
			size_t spaceLength = strlen(space);
			size_t totalLength = (size - 1) * spaceLength;
			for (size_t i = 0; i < size; ++i) totalLength += strlen(others[i]);
			String newString = String("", totalLength);
			char* data = newString.data_;
			for (size_t i = 0; i < size; ++i) {
				size_t otherLength = strlen(others[i]);
				memcpy(data, others[i], otherLength);
				memcpy(data + otherLength, space, spaceLength);
				data += otherLength + spaceLength;
			}
			return newString;
		}
		inline static String Join(const char* const space, size_t spaceLength, const char* const* const others, size_t size) {
			size_t totalLength = (size - 1) * spaceLength;
			for (size_t i = 0; i < size; ++i) totalLength += strlen(others[i]);
			String newString = String("", totalLength);
			char* data = newString.data_;
			for (size_t i = 0; i < size; ++i) {
				size_t otherLength = strlen(others[i]);
				memcpy(data, others[i], otherLength);
				memcpy(data + otherLength, space, spaceLength);
				data += otherLength + spaceLength;
			}
			return newString;
		}
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

		inline static void SplitStringAt(const String& source, size_t index, String& lhs, String& rhs) {
			if (index > source.length_) return;
			lhs = String(source.data_, index);
			rhs = String(source.data_ + index, source.length_ - index);
		}

	public:
		String();
		explicit String(size_t);
		String(const char* const);
		String(const char);
		String(const char* const, size_t);
		String(const char, size_t);
		String(const String&);

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
		inline operator char*() const { return data_; }

		inline bool operator==(const String& other)		const	{ return length_ == other.length_ && memcmp(data_, other.data_, other.length_) == 0;	}
		inline bool operator==(const char* const other) const	{ return strcmp(data_, other) == 0;														}
		inline bool operator==(const char c)			const	{ return length_ == 1 && *data_ == c;													}
		inline bool operator!=(const String& other)		const	{ return length_ != other.length_ || memcmp(data_, other.data_, other.length_) != 0;	}
		inline bool operator!=(const char* const other) const	{ return strcmp(data_, other) != 0;														}
		inline bool operator!=(const char c)			const	{ return length_ > 1 || *data_ != c;													}

		inline size_t		Size()		const { return size_;	}
		inline size_t		Length()	const { return length_;	}
		inline const char*	CString()	const { return data_;	}

		inline void ShrinkToFit() {
			if (length_ + 1 == size_) return;
			size_ = length_ + 1;
			delete[](temp_);
			temp_ = new char[size_] { '\0' };
			char* newData = new char[size_] { '\0' };
			this->IncInstCounter();
			memcpy(newData, data_, length_);
			delete[](data_);
			--s_instanceCounter_;
			data_ = newData;
		}

		inline void Concatenate(const String& other) {
			size_t newLength = length_ + other.length_;
			this->CheckSizeAndReallocate(newLength);
			memcpy(data_ + length_, other.data_, other.length_ + 1);
			length_ = newLength;
		}
		inline void Concatenate(const char* const other) {
			size_t otherLength = strlen(other);
			size_t newLength = length_ + otherLength;
			this->CheckSizeAndReallocate(newLength);
			memcpy(data_ + length_, other, otherLength + 1);
			length_ = newLength;
		}
		inline void Concatenate(const char* const other, size_t length) {
			size_t newLength = length_ + length;
			this->CheckSizeAndReallocate(newLength);
			memcpy(data_ + length_, other, length + 1);
			length_ = newLength;
		}
		inline void Concatenate(const char c) {
			this->CheckSizeAndReallocate(++length_);
			data_[length_ - 1] = c;
			data_[length_] = '\0';
		}

		inline bool Contains(const String& other) const {
			if (other.length_ > length_) return false;
			for (size_t i = 0; i < length_ - other.length_; ++i) {
				if (data_[i] != other.data_[0]) continue;
				if (memcmp(data_ + i, other.data_, other.length_) == 0) return true;
			}
			return false;
		}
		inline bool Contains(const char* const other) const {
			size_t otherLength = strlen(other);
			if (otherLength > length_) return false;
			for (size_t i = 0; i < length_ - otherLength; ++i) {
				if (data_[i] != other[0]) continue;
				if (memcmp(data_ + i, other, otherLength) == 0) return true;
			}
			return false;
		}
		inline bool Contains(const char* const other, size_t length) const {
			if (length > length_) return false;
			for (size_t i = 0; i < length_ - length; ++i) {
				if (data_[i] != other[0]) continue;
				if (memcmp(data_ + i, other, length) == 0) return true;
			}
			return false;
		}
		inline bool Contains(const char c) const { return strchr(data_, c) != nullptr; }

		inline int IndexOf(const String& other) const {
			if (other.length_ > length_) return -1;
			char* p = strstr(data_, other.data_);
			return p ? static_cast<int>(p - data_) : -1;
		}
		inline int IndexOf(const String& other, size_t begin) const { 
			if (begin >= length_ || other.length_ > length_) return -1;
			char* p = strstr(data_ + begin, other.data_);
			return p ? static_cast<int>(p - data_) : -1;
		}
		int IndexOf(const String& other, size_t begin, size_t end) const;

		inline int IndexOf(const char* const other) const {
			char* p = strstr(data_, other);
			return p ? static_cast<int>(p - data_) : -1;
		}
		inline int IndexOf(const char* const other, size_t begin) const {
			if (begin >= length_) return -1;
			char* p = strstr(data_ + begin, other);
			return p ? static_cast<int>(p - data_) : -1;
		}
		int IndexOf(const char* const other, size_t begin, size_t end) const;

		inline int IndexOf(size_t length, const char* const other) const {
			if (length > length_) return -1;
			char* p = strstr(data_, other);
			return p ? static_cast<int>(p - data_) : -1;
		}
		inline int IndexOf(size_t length, const char* const other, size_t begin) const {
			if (begin >= length_ || length > length_) return -1;
			char* p = strstr(data_ + begin, other);
			return p ? static_cast<int>(p - data_) : -1;
		}
		int IndexOf(size_t length, const char* const other, size_t begin, size_t end) const;

		inline int IndexOf(const char c) const {
			char* p = static_cast<char*>(memchr(data_, c, length_));
			return p ? static_cast<int>(p - data_) : -1;
		}
		inline int IndexOf(const char c, size_t begin) const {
			if (begin >= length_) return -1;
			char* p = static_cast<char*>(memchr(data_ + begin, c, length_ - begin));
			return p ? static_cast<int>(p - data_) : -1;
		}
		inline int IndexOf(const char c, size_t begin, size_t end) const {
			if (begin >= length_ || end > length_ || begin > end) return -1;
			char* p = static_cast<char*>(memchr(data_ + begin, c, end - begin));
			return p ? static_cast<int>(p - data_) : -1;
		}

		inline	int LastIndexOf(const String& other)							const { return this->LastIndexOf(other, 0, length_);		}
		inline	int LastIndexOf(const String& other, size_t begin)				const { return this->LastIndexOf(other, begin, length_);	}
				int LastIndexOf(const String& other, size_t begin, size_t end)	const;

		inline	int LastIndexOf(const char* const other)							const { return this->LastIndexOf(other, 0, length_);		}
		inline	int LastIndexOf(const char* const other, size_t begin)				const { return this->LastIndexOf(other, begin, length_);	}
				int LastIndexOf(const char* const other, size_t begin, size_t end)	const;

		inline	int LastIndexOf(size_t length, const char* const other)								const { return this->LastIndexOf(length, other, 0, length_);		}
		inline	int LastIndexOf(size_t length, const char* const other, size_t begin)				const { return this->LastIndexOf(length, other, begin, length_);	}
				int LastIndexOf(size_t length, const char* const other, size_t begin, size_t end)	const;

		inline int LastIndexOf(const char c) const {
			char* p = strrchr(data_, c);
			return p ? static_cast<int>(p - data_) : -1;
		}
		inline int LastIndexOf(const char c, size_t begin) const {
			if (begin >= length_) return -1;
			char* p = strrchr(data_ + begin, c);
			return p ? static_cast<int>(p - data_) : -1;
		}
		inline int LastIndexOf(const char c, size_t begin, size_t end) const {
			if (begin >= length_ || end > length_ || begin > end) return -1;
			for (size_t i = end; i >= begin; --i) if (data_[i] == c) return static_cast<int>(i);
			return -1;
		}

		inline String Substring(size_t begin) const {
			if (begin > length_) begin = length_;
			return String(data_ + begin, length_ - begin);
		}
		inline String Substring(size_t begin, size_t end) const {
			if (end > length_) end = length_;
			if (begin > end) begin = end;
			return String(data_ + begin, end - begin);
		}

		void Insert(size_t index, const String& other);
		void Insert(size_t index, const char* const other);
		void Insert(size_t index, const char* const other, size_t length);
		void Insert(size_t index, const char c);

		inline	void Remove(size_t index) { this->Remove(index, length_ - 1); }
				void Remove(size_t index, size_t count);

		void RemoveAll(const String& other);
		void RemoveAll(const char* const other);
		void RemoveAll(const char* const other, size_t length);
		void RemoveAll(const char c);

		inline	void Replace(size_t index, const String& other)						{ this->Replace(index, length_ - 1, other);			}
				void Replace(size_t index, size_t count, const String& other);
		inline	void Replace(size_t index, const char* const other)					{ this->Replace(index, length_ - 1, other);			}
				void Replace(size_t index, size_t count, const char* const other);
		inline	void Replace(size_t index, const char* const other, size_t length)	{ this->Replace(index, length_ - 1, other, length);	}
				void Replace(size_t index, size_t count, const char* const other, size_t length);
		inline	void Replace(size_t index, const char c)							{ this->Replace(index, length_ - 1, c);				}
				void Replace(size_t index, size_t count, const char c);

		inline void ReplaceAt(size_t index, const String& other) {
			if (index + other.length_ >= length_) return;
			this->CheckSizeAndReallocate(index + other.size_);
			memcpy(data_ + index, other.data_, other.size_);
		}
		inline void ReplaceAt(size_t index, const char* const other) {
			size_t otherLength = strlen(other);
			if (index + otherLength >= length_) return;
			this->CheckSizeAndReallocate(index + otherLength);
			memcpy(data_ + index, other, otherLength);
		}
		inline void ReplaceAt(size_t index, const char* const other, size_t length) {
			if (index + length >= length_) return;
			this->CheckSizeAndReallocate(index + length);
			memcpy(data_ + index, other, length);
		}
		inline void ReplaceAt(size_t index, const char c) const {
			if (index >= length_) return;
			data_[index] = c;
		}

		inline void Trim() { this->Trim(' '); }
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

		inline void TrimStart() { this->TrimStart(' '); }
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

		inline void TrimEnd() { this->TrimEnd(' '); }
		inline void TrimEnd(const char c) {
			for (int i = static_cast<int>(length_) - 1; i >= 0; --i) {
				if (data_[i] != c) {
					length_ = static_cast<size_t>(i + 1);
					data_[length_] = '\0';
					break;
				}
			}
		}

		inline void PadLeft(size_t length) { this->PadLeft(length, ' '); }
		inline void PadLeft(size_t length, char c) {
			if (length_ >= length) return;
			this->CheckSizeAndReallocate(length);
			memset(temp_, c, length - length_);
			memcpy(temp_ + length - length_, data_, length_);
			length_ = length;
			memcpy(data_, temp_, length);
			data_[length] = '\0';
		}

		inline void PadRight(size_t length) { this->PadRight(length, ' '); }
		inline void PadRight(size_t length, char c) {
			if (length_ >= length) return;
			this->CheckSizeAndReallocate(length);
			memset(temp_ + length_, c, length - length_);
			memcpy(temp_, data_, length_);
			length_ = length;
			memcpy(data_, temp_, length);
			data_[length] = '\0';
		}

		inline bool StartsWith(const String& other) const {
			if (other.length_ > length_) return false;
			return memcmp(data_, other.data_, other.length_) == 0;
		}
		inline bool StartsWith(const char* const other) const {
			size_t otherLength = strlen(other);
			if (otherLength > length_) return false;
			return memcmp(data_, other, otherLength) == 0;
		}
		inline bool StartsWith(const char* const other, size_t length) const {
			if (length > length_) return false;
			return memcmp(data_, other, length) == 0;
		}
		inline bool StartsWith(const char c) const { return *data_ == c; }

		inline bool EndsWith(const String& other) const {
			if (other.length_ > length_) return false;
			return memcmp(data_ + length_ - other.length_, other.data_, other.length_) == 0;
		}
		inline bool EndsWith(const char* const other) const {
			size_t otherLength = strlen(other);
			if (otherLength > length_) return false;
			return memcmp(data_ + length_ - otherLength, other, otherLength) == 0;
		}
		inline bool EndsWith(const char* const other, size_t length) const {
			if (length > length_) return false;
			return memcmp(data_ + length_ - length, other, length) == 0;
		}
		inline bool EndsWith(const char c) const { return data_[length_ - 1] == c; }

		inline void Fill(const String& other) const {
			int count = static_cast<int>(length_ / other.length_);
			for (int i = 0; i < count; ++i) memcpy(data_ + i * other.length_, other.data_, other.length_);
			memcpy(data_ + count * other.length_, other.data_, length_ % other.length_);
		}
		inline void Fill(const String& other, size_t begin) const {
			if (begin > length_) return;
			int count = static_cast<int>((length_ - begin) / other.length_);
			for (int i = 0; i < count; ++i) memcpy(data_ + begin + i * other.length_, other.data_, other.length_);
			memcpy(data_ + begin + count * other.length_, other.data_, (length_ - begin) % other.length_);
		}
		inline void Fill(const String& other, size_t begin, size_t end) const {
			if (end > length_) end = length_;
			if (begin > end) return;
			int count = static_cast<int>((end - begin) / other.length_);
			for (int i = 0; i < count; ++i) memcpy(data_ + begin + i * other.length_, other.data_, other.length_);
			memcpy(data_ + begin + count + other.length_, other.data_, (end - begin) % other.length_);
		}

		inline void Fill(const char* const other) const {
			size_t otherLength = strlen(other);
			int count = static_cast<int>(length_ / otherLength);
			for (int i = 0; i < count; ++i) memcpy(data_ + i * otherLength, other, otherLength);
			memcpy(data_ + count * otherLength, other, length_ % otherLength);
		}
		inline void Fill(const char* const other, size_t begin) const {
			if (begin > length_) return;
			size_t otherLength = strlen(other);
			int count = static_cast<int>((length_ - begin) / otherLength);
			for (int i = 0; i < count; ++i) memcpy(data_ + begin + i * otherLength, other, otherLength);
			memcpy(data_ + begin + count * otherLength, other, (length_ - begin) % otherLength);
		}
		inline void Fill(const char* const other, size_t begin, size_t end) const {
			if (end > length_) end = length_;
			if (begin > end) return;
			size_t otherLength = strlen(other);
			int count = static_cast<int>((end - begin) / otherLength);
			for (int i = 0; i < count; ++i) memcpy(data_ + begin + i * otherLength, other, otherLength);
			memcpy(data_ + begin + count * otherLength, other, (end - begin) % otherLength);
		}

		inline void Fill(size_t length, const char* const other) const {
			int count = static_cast<int>(length_ / length);
			for (int i = 0; i < count; ++i) memcpy(data_ + i * length, other, length);
			memcpy(data_ + count * length, other, length_ % length);
		}
		inline void Fill(size_t length, const char* const other, size_t begin) const {
			if (begin > length_) return;
			int count = static_cast<int>((length_ - begin) / length);
			for (int i = 0; i < count; ++i) memcpy(data_ + begin + i * length, other, length);
			memcpy(data_ + begin + count * length, other, (length_ - begin) % length);
		}
		inline void Fill(size_t length, const char* const other, size_t begin, size_t end) const {
			if (end > length_) end = length_;
			if (begin > end) return;
			int count = static_cast<int>((end - begin) / length);
			for (int i = 0; i < count; ++i) memcpy(data_ + begin + i * length, other, length);
			memcpy(data_ + begin + count * length, other, (end - begin) % length);
		}

		inline void Fill(const char c) const { memset(data_, c, length_); }
		inline void Fill(const char c, size_t begin) const {
			if (begin > length_) return;
			memset(data_, c, length_ - begin);
		}
		inline void Fill(const char c, size_t begin, size_t end) const {
			if (end > length_) end = length_;
			if (begin > end) return;
			memset(data_, c, end - begin);
		}

		inline void SplitAt(size_t index, String& lhs, String& rhs) const {
			if (index > length_) return;
			lhs = String(data_, index);
			rhs = String(data_ + index, length_ - index);
		}

		inline void ToLower() const { _strlwr_s(data_, length_ + 1); }
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
			delete[](temp_);
			temp_ = new char[size_] { '\0' };
			char* newData = new char[size_] { '\0' };
			this->IncInstCounter();
			memcpy(newData, data_, length_);
			delete[](data_);
			--s_instanceCounter_;
			data_ = newData;
		}

	public:
		static size_t s_instanceCounter_;
		static size_t s_totalInstancesCreated_;

	private:
		size_t size_;
		size_t length_;
		char* data_;
		char* temp_;
	};
}
