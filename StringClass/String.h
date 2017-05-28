#pragma once

#include <cstring>


namespace Power {
	class String {
		public:
		String() = delete;
		String(const char* const);
		String(const char* const, size_t);
		String(const String&);

		inline void operator=(const String& other) {
			delete[](data_);
			--s_instanceCounter_;
			length_ = other.length_;
			data_ = new char[other.length_ + 1]{ '\0' };
			this->IncInstCounter();
			memcpy(data_, other.data_, other.length_);
		}

		inline void operator=(const char* const data) {
			delete[](data_);
			--s_instanceCounter_;
			length_ = strlen(data);
			data_ = new char[length_ + 1]{ '\0' };
			this->IncInstCounter();
			memcpy(data_, data, length_);
		}

		inline void operator=(const char c) {
			delete[](data_);
			--s_instanceCounter_;
			length_ = 1;
			data_ = new char[2]{ '\0' };
			this->IncInstCounter();
			*data_ = c;
		}

		inline String operator+(const String& other) const {
			String newString = String("", length_ + other.length_ + 1);
			memcpy(newString.data_, data_, length_);
			memcpy(newString.data_ + length_, other.data_, other.length_);
			return newString;
		}

		inline String operator+(const char* const other) const {
			const size_t otherLength = strlen(other);
			String newString = String("", length_ + otherLength + 1);
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

		inline void operator+=(const String& other) {
			const size_t newLength = length_ + other.length_;
			char* newData = new char[newLength + 1]{ '\0' };
			this->IncInstCounter();
			memcpy(newData, data_, length_);
			memcpy(newData + length_, other.data_, other.length_);
			delete[](data_);
			--s_instanceCounter_;
			data_ = newData;
			length_ = newLength;
		}

		inline void operator+=(const char* const other) {
			const size_t otherLength = strlen(other);
			const size_t newLength = length_ + otherLength;
			char* newData = new char[newLength + 1]{ '\0' };
			this->IncInstCounter();
			memcpy(newData, data_, length_);
			memcpy(newData + length_, other, otherLength);
			delete[](data_);
			--s_instanceCounter_;
			data_ = newData;
			length_ = newLength;
		}

		inline void operator+=(const char c) {
			const size_t newLength = length_ + 1;
			char* newData = new char[newLength + 1]{ '\0' };
			this->IncInstCounter();
			memcpy(newData, data_, length_);
			*(newData + length_) = c;
			delete[](data_);
			--s_instanceCounter_;
			data_ = newData;
			length_ = newLength;
		}

		inline bool operator==(const String& other)		const	{ return strcmp(data_, other.data_) == 0;	}
		inline bool operator==(const char* const other) const	{ return strcmp(data_, other) == 0;			}
		inline bool operator!=(const String& other)		const	{ return strcmp(data_, other.data_) != 0;	}
		inline bool operator!=(const char* const other) const	{ return strcmp(data_, other) != 0;			}

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
			String substring = String("", end - begin + 1);
			memcpy(substring.data_, data_ + begin, substring.length_);
			return substring;
		}

		String Insert(size_t index, const String& other)		const;
		String Insert(size_t index, const char* const other)	const;

		String Remove(size_t index)					const { return this->Remove(index, length_ - 1); }
		String Remove(size_t index, size_t count)	const;
		String RemoveAll(const char c)				const;

		inline String PadLeft(size_t length)			const { return this->PadLeft(length, ' '); }
		inline String PadLeft(size_t length, char c)	const {
			if (length_ >= length) return *this;
			String newString = String("", length + 1);
			memset(newString.data_, c, length - length_);
			memcpy(newString.data_ + length - length_, data_, length_);
			return newString;
		}

		inline String PadRight(size_t length)			const { return this->PadRight(length, ' '); }
		inline String PadRight(size_t length, char c)	const {
			if (length_ >= length) return *this;
			String newString = String("", length + 1);
			memset(newString.data_ + length_, c, length - length_);
			memcpy(newString.data_, data_, length_);
			return newString;
		}

		~String();

	private:
		inline void IncInstCounter() {
			++s_instanceCounter_;
			++s_totalInstancesCreated_;
		}
		
		inline void SetValuesInRange(size_t& a, size_t& b) const {
			if (b >= length_) b = length_ - 1;
			if (a > b) a = b;
		}

	public:
		static size_t s_instanceCounter_;
		static size_t s_totalInstancesCreated_;

	private:
		size_t length_;
		char* data_;
	};
}
