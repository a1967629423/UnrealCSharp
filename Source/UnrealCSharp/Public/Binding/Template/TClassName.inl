﻿#pragma once

template <class T>
struct TClassName
{
	static FString Get() { return T::StaticClass()->GetName(); }
};
