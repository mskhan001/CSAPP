/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/* Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
	// xor is different from or only in the case of 1,1
	// (x xor y) = (x or y) - (x and y)
	// (x xor y) = (x or y) & ~(x and y)
	//
	// express 'or' using ~&
	return ~(~x&~y) & ~(x&y);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1 << 31;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
	// adding 1 Tmax will give Tmin
	// inverting digits of Tmax will give Tmin
	//
	// this property will only be exhibited by Tmax and -1
	int is_neg_1 = !(~x^0);
	return !((x+1)^~x) & !is_neg_1;
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
	// if the number was 8 bits,
	// we want a7 & a5 & a3 & a1
	// we can get this using the below trick
	
	x = (x>>16) & x;
	x = (x>>8) & x;
	x = (x>>4) & x;
	x = (x>>2) & x;
	x = x>>1;

	return x & 1;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
	int within_bounds = !((x&~0xff)^0);
	int starts_with_3 = !((x&0xF0)^(0x30));
	int ends_below_10 = !(((x+0x06)&0xF0)^(0x30));
  return within_bounds & starts_with_3 & ends_below_10;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
	int neg_x;
	x = !(x); // convert x to either 0 or 1
	x = !(x);
	neg_x = (~x+1);
	return (neg_x&y)+((~neg_x)&z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
	int x_minus_y = x + (~y+1);
	int is_zero = !(x_minus_y^0);
	int x_greater_than_y = !((x_minus_y>>31)^0);
	return (!(x_greater_than_y)) | is_zero;
	//return 2;
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
	int is_negative = (x>>31)&1;
	int is_positive = ((~x+1)>>31)&1;
	return (is_negative | is_positive)^1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
	int is_neg, c16, c8, c4, c2, c1, ans;
	int c16_cond, c8_cond, c4_cond, c2_cond, c1_cond;

	is_neg = (x>>31)&1; // is x negative 
	x = ((~is_neg+1)&(~x)) + ((~(~is_neg+1))&x); // if x is negative, invert the bits of x
	
	c16 = !((x>>16)^0); // are the upper 16 bits of x zeros
	c16_cond = ~(~c16+1);
	x = ((~c16+1)&x) + ((c16_cond)&(x>>16));

	c8 = !((x>>8)^0); // are the upper 8 bits of x zero
	c8_cond = ~(~c8+1);
	x = ((~c8+1)&x) + ((c8_cond)&(x>>8));

	c4 = !((x>>4)^0); // are the upper 4 bits of x zero
	c4_cond = ~(~c4+1);
	x = ((~c4+1)&x) + ((c4_cond)&(x>>4));

	c2 = !((x>>2)^0); // are the upper 2 bits of x zero
	c2_cond = ~(~c2+1);
	x = ((~c2+1)&x) + ((c2_cond)&(x>>2));

	c1 = !((x>>1)^0); // is x zero 
	c1_cond = ~(~c1+1);
	x = ((~c1+1)&x) + ((c1_cond)&(x>>1));

	ans = (c16_cond&16) + (c8_cond&8) + (c4_cond&4) + (c2_cond&2) + (c1_cond&1) + (x&1) + 1;
	return ans;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
	int exp, frac ;

	exp = uf & 0x7F800000;
	frac = uf & 0x7FFFFF;

	// zero
	if(0==uf || (1<<31)==uf)
		return uf;


	// inifinity
	if((exp>>23) == 255)
		return uf;


	// denormalized
	if(exp==0){
		frac = uf & 0x7FFFFF;
		return uf + frac;
	}

	uf = uf + (1<<23);
	return uf;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
	int sign, frac, exp;

	sign = (uf>>31)&1;
	exp = ((uf & 0x7F800000) >> 23) - 127;
	frac = uf & 0x7FFFFF;

	if(exp < 0)
		return 0;

	frac = frac | (1<<23);

	if(exp<=23){
		frac = frac >> (23-exp);

		if(sign)
			frac = -frac;
		return frac;
	}

	if(exp<=30){
		frac = frac << (exp-23);
		if(sign)
			frac = -frac;
		return frac;
	}

	return 0x80000000;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
	if(x<-149)
		return 0;

	if(x<=-127){
		x = x + 149;
		return 1 << x;
	}

	if(x<=127){
		x = x + 127;
		return x << 23;
	}

	return 255 << 23;
}
