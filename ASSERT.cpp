﻿#include "pch.h"
#include <cassert>
#include <iostream>
#include <string>


#define ASSERT_EQUAL(a, b)    if (a != b){                                                                                           \
					  std::cout << "Что-то не то, они не равны, первое = " << a << ", второе = " << b << "\n";   \
					  assert(a == b);                                                                            \
					  }

#define ASSERT_NEQUAL(a, b)    if (a == b){                                                                                          \
					  std::cout << "Что-то не то, они равны, первое = " << a << ", второе = " << b << "\n";      \
					  assert(a != b);                                                                            \
					  }

#define ASSERT_FALSE(a)    if (a){                                                                                                   \
				  std::cout << "Что-то не то, значение = " << a << "\n";                                             \
				  assert(!a);                                                                                        \
				 }

#define ASSERT_TRUE(a)    if (!a){                                                                                                   \
				  std::cout << "Что-то не то, значение FALSE"<< "\n";                                                \
			          assert(a);                                                                                         \
				 }
						   
						   
