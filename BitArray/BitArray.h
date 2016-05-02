#pragma once

#ifndef bitArray_h
#define bitArray_h

#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
class BitArray
{

public:
	enum ENDIAN { BIG_ENDIAN, LITTLE_ENDIAN };
	BitArray(int bitSize);

	//store
	~BitArray();
	int StoreByteArray(int nbits, int fromStartingBit, int atStartingBit, unsigned char from[], int length, ENDIAN endian);
	int SetBit(int atBitPos, bool b);
	int ToggleBit(int atBitPos, bool *b);
	int StoreInt(int nbits, int atBitPos, int from);
	int StoreUInt(int nbits, int atBitPos, unsigned int from);
	int StoreChar(int nbits, int atBitPos, unsigned char from);
	int StoreULong(int nbits, int atBitPos, unsigned long from);
	int StoreLong(int nbits, int atBitPos, long from);
	int StoreFloat(int atBitPos, float from);
	int StoreDouble(int atBitPos, double from);

	// retrieve
	int Bit(int atBitPos, bool* b);
	int RetrieveByteArray(int nbits, int atBitPos, unsigned char *buffer, int len, ENDIAN endian);
	int RetrieveInt(int nbits, int atBitPos, int* toInt);
	int RetrieveChar(int nbits, int atBitPos, unsigned char* toChar);
	int RetrieveUInt(int nbits, int atBitPos, unsigned int* toUint);
	int RetrieveULong(int nbits, int atBitPos, unsigned long* toUlong);
	int RetrieveLong(int nbits, int atBitPos, long* toLong);
	int RetrieveFloat(int atBitPos, float* toFloat);
	int RetrieveDouble(int atBitPos, double* toDouble);

	unsigned char* GetEntireBitArray(ENDIAN endian);
	int GetBitArraySizeByte();
	bool IsBigEndian(void);
private:
	void Initialize();
	unsigned char* ReverseByteArray(unsigned char byteArray[]);
	unsigned char* ReverseByteArray(unsigned char *byteArray, int len);
	void InsertBitsFromByteToByte(unsigned char sourceByte, int sourceBitStartIndex, int targetByteIndex, int targetBitStartIndex, int nbits);
	int GetBit(int atPos);

	// Byte array hold the bit set - it is LITTLE ENDIAN - ex FA021BC7:?
	// b[0] = C7; b[1] = 1B; b[2] = 02; b[3] = FA
	unsigned char *byteArray;
	int byteArrayCount;
	unsigned char OneByteMask(int from, int to);

	void IntToByteArray(unsigned int n);
	void LongToByteArray(unsigned int n);
	void CharToByteArray(unsigned char n);

	unsigned char _baChar[sizeof(char)];
	unsigned char _baInt[sizeof(int)];
	unsigned char _baLong[sizeof(long)];
};

#endif