#pragma once

#include <cstring>
#include <cstdio>


namespace Power {
	class String {
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

		inline String operator+(const String& other) const {
			String newString = String("", length_ + other.length_);
			memcpy(newString.data_, data_, length_);
			memcpy(newString.data_ + length_, other.data_, other.length_);
			return newString;
		}
		inline String operator+(const char* const other) const {
			const size_t otherLength = strlen(other);
			String newString = String("", length_ + otherLength);
			memcpy(newString.data_, data_, length_);
			memcpy(newString.data_ + length_, other, otherLength);
			return newString;
		}
		inline String operator+(const char c) const {
			String newString = String("", length_ + 1);
			memcpy(newString.data_, data_, length_);
			*(newString.data_ + length_) = c;
			return newString;
		}
		inline String operator+(const int value) const {
			char buffer[50];
			snprintf(buffer, 50, "%d", value);
			size_t otherLength = strlen(buffer);
			String newString = String("", length_ + otherLength);
			memcpy(newString.data_, data_, length_);
			memcpy(newString.data_ + length_, buffer, otherLength);
			return newString;
		}
		inline String operator+(const float value) const {
			char buffer[50];
			snprintf(buffer, 50, "%g", value);
			size_t otherLength = strlen(buffer);
			String newString = String("", length_ + otherLength);
			memcpy(newString.data_, data_, length_);
			memcpy(newString.data_ + length_, buffer, otherLength);
			return newString;
		}
		inline String operator+(const double value) const {
			char buffer[50];
			snprintf(buffer, 50, "%g", value);
			size_t otherLength = strlen(buffer);
			String newString = String("", length_ + otherLength);
			memcpy(newString.data_, data_, length_);
			memcpy(newString.data_ + length_, buffer, otherLength);
			return newString;
		}

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
			this->CheckSizeAndReallocate(length_ + 1);
			data_[length_] = c;
			data_[length_ + 1] = '\0';
			++length_;
		}
		inline void operator+=(const int value) {
			char buffer[50];
			snprintf(buffer, 50, "%d", value);
			size_t otherLength = strlen(buffer);
			size_t newLength = length_ + otherLength;
			this->CheckSizeAndReallocate(newLength);
			memcpy(data_ + length_, buffer, otherLength + 1);
			length_ = newLength;
		}
		inline void operator+=(const float value) {
			char buffer[50];
			snprintf(buffer, 50, "%g", value);
			size_t otherLength = strlen(buffer);
			size_t newLength = length_ + otherLength;
			this->CheckSizeAndReallocate(newLength);
			memcpy(data_ + length_, buffer, otherLength + 1);
			length_ = newLength;
		}
		inline void operator+=(const double value) {
			char buffer[50];
			snprintf(buffer, 50, "%g", value);
			size_t otherLength = strlen(buffer);
			size_t newLength = length_ + otherLength;
			this->CheckSizeAndReallocate(newLength);
			memcpy(data_ + length_, buffer, otherLength + 1);
			length_ = newLength;
		}

		inline char operator[](size_t i) const { return *(data_ + i); }

		inline bool operator==(const String& other)		const	{ return strcmp(data_, other.data_) == 0;	}
		inline bool operator==(const char* const other) const	{ return strcmp(data_, other) == 0;			}
		inline bool operator==(const char c)			const	{ return length_ == 1 && *data_ == c;		}
		inline bool operator!=(const String& other)		const	{ return strcmp(data_, other.data_) != 0;	}
		inline bool operator!=(const char* const other) const	{ return strcmp(data_, other) != 0;			}
		inline bool operator!=(const char c)			const	{ return length_ > 1 || *data_ != c;		}

		inline size_t		Size()		const { return size_;	}
		inline size_t		Length()	const { return length_;	}
		inline const char*	CString()	const { return data_;	}

		inline	int IndexOf(const String& other)							const { return this->IndexOf(other, 0, length_ - 1);		}
		inline	int IndexOf(const String& other, size_t begin)				const { return this->IndexOf(other, begin, length_ - 1);	}
				int IndexOf(const String& other, size_t begin, size_t end)	const;

		inline	int IndexOf(const char* const other)							const { return this->IndexOf(other, 0, length_ - 1);		}
		inline	int IndexOf(const char* const other, size_t begin)				const { return this->IndexOf(other, begin, length_ - 1);	}
				int IndexOf(const char* const other, size_t begin, size_t end)	const;

		inline int IndexOf(const char c) const {
			char* p = strchr(data_, c);
			return p ? p - data_ : -1;
		}
		inline int IndexOf(const char c, size_t begin) const {
			if (begin >= length_) return -1;
			char* p = strchr(data_ + begin, c);
			return p ? p - data_ : -1;
		}
		inline int IndexOf(const char c, size_t begin, size_t end) const {
			if (begin >= length_ || end >= length_) return -1;
			for (size_t i = begin; i < end; ++i) if (data_[i] == c) return i;
			return -1;
		}

		inline	int LastIndexOf(const String& other)							const { return this->LastIndexOf(other, 0, length_ - 1);		}
		inline	int LastIndexOf(const String& other, size_t begin)				const { return this->LastIndexOf(other, begin, length_ - 1);	}
				int LastIndexOf(const String& other, size_t begin, size_t end)	const;

		inline	int LastIndexOf(const char* const other)							const { return this->LastIndexOf(other, 0, length_ - 1);		}
		inline	int LastIndexOf(const char* const other, size_t begin)				const { return this->LastIndexOf(other, begin, length_ - 1);	}
				int LastIndexOf(const char* const other, size_t begin, size_t end)	const;

		inline int LastIndexOf(const char c) const {
			char* p = strrchr(data_, c);
			return p ? p - data_ : -1;
		}
		inline int LastIndexOf(const char c, size_t begin) const {
			if (begin >= length_) return -1;
			char* p = strrchr(data_ + begin, c);
			return p ? p - data_ : -1;
		}
		inline int LastIndexOf(const char c, size_t begin, size_t end) const {
			if (begin >= length_ || end >= length_) return -1;
			for (size_t i = end; i >= begin; --i) if (data_[i] == c) return i;
			return -1;
		}

		inline String Substring(size_t begin) const {
			if (begin >= length_) begin = length_ - 1;
			String substring = String("", length_ - begin);
			memcpy(substring.data_, data_ + begin, substring.length_);
			return substring;
		}
		inline String Substring(size_t begin, size_t end) const {
			this->SetValuesInRange(begin, end);
			String substring = String("", end - begin);
			memcpy(substring.data_, data_ + begin, substring.length_);
			return substring;
		}

		void Insert(size_t index, const String& other);
		void Insert(size_t index, const char* const other);

		inline	void Remove(size_t index) { this->Remove(index, length_ - 1); }
				void Remove(size_t index, size_t count);

		void RemoveAll(const String& other);
		void RemoveAll(const char* const other);
		void RemoveAll(const char c);

		inline	void Replace(size_t index, const String& other)		{ this->Replace(index, length_ - 1, other); }
				void Replace(size_t index, size_t count, const String& other);
		inline	void Replace(size_t index, const char* const other) { this->Replace(index, length_ - 1, other); }
				void Replace(size_t index, size_t count, const char* const other);
		inline	void Replace(size_t index, const char c)			{ this->Replace(index, length_ - 1, c);		}
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
		inline void ReplaceAt(size_t index, const char c) const {
			if (index >= length_) return;
			data_[index] = c;
		}

		inline void PadLeft(size_t length) { this->PadLeft(length, ' '); }
		inline void PadLeft(size_t length, char c) {
			if (length_ >= length) return;
			this->CheckSizeAndReallocate(length);
			temp_[length] = '\0';
			memset(temp_, c, length - length_);
			memcpy(temp_ + length - length_, data_, length_);
			length_ = length;
			memcpy(data_, temp_, length + 1);
		}

		inline void PadRight(size_t length) { this->PadRight(length, ' '); }
		inline void PadRight(size_t length, char c) {
			if (length_ >= length) return;
			this->CheckSizeAndReallocate(length);
			temp_[length] = '\0';
			memset(temp_ + length_, c, length - length_);
			memcpy(temp_, data_, length_);
			length_ = length;
			memcpy(data_, temp_, length + 1);
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
		inline bool EndsWith(const char c) const { return data_[length_ - 1] == c; }

		~String();

	private:
		inline void IncInstCounter() const {
			++s_instanceCounter_;
			++s_totalInstancesCreated_;
		}
		
		inline void SetValuesInRange(size_t& a, size_t& b) const {
			if (b >= length_) b = length_ - 1;
			if (a > b) a = b;
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
