**English** | [العربية](README.ar.md)

# C++ Date Library

An educational, class-based C++ library for representing dates and practicing calendar calculations. It exposes both static helpers and instance methods through the `clsDate` type.

## Implemented Features

- Construct a date from the system date, `day/month/year` text, numeric parts, or a day order within a year
- Read and update day, month, and year values
- Detect leap years and calculate days, hours, minutes, and seconds per year or month
- Convert dates to and from strings
- Print a month calendar or a complete year calendar
- Calculate day-of-week order and compare two dates
- Increase or decrease dates by days, weeks, months, years, decades, centuries, or millennia
- Calculate differences, age in days, business days, vacation days, and vacation return dates
- Validate date values and calculate the day order within a year

## Tech Stack

- C++
- Object-oriented programming
- Static and instance methods
- Microsoft-specific property syntax with `__declspec(property)`
- Visual Studio / Microsoft Visual C++

## Project Structure

```text
Date_Library/
├── Date Library.vcxproj
├── Date Library.cpp  # Small usage example
└── clsDate.h         # Date representation and calendar operations
```

## Build Setup

The project is configured for the Visual Studio 2019 `v142` toolset and does not include a solution file.

1. Open `Date Library.vcxproj` in Visual Studio.
2. Install v142 or retarget the project to an installed C++ toolset.
3. Select `Release | x64` and build.

```powershell
msbuild "Date Library.vcxproj" /p:Configuration=Release /p:Platform=x64
```

## Current Build Status

The current source does **not** complete compilation. `clsDate.h` defines both of these overloads:

```cpp
IncreaseDateByOneDay(clsDate Date)
IncreaseDateByOneDay(clsDate& Date)
```

Calls with an lvalue are ambiguous, producing compiler error `C2668` at several locations. One overload should be removed or renamed, or the API should clearly separate mutating and value-returning operations. The source also reports warnings for an extra semicolon after an `#include` directive and a `size_t`-to-`short` conversion.

## Current Scope

- String construction expects a valid `day/month/year` value and does not safely handle malformed input.
- Several counters use `short`, which limits the supported ranges.
- Weekend and business-day rules are fixed in code rather than configurable.
- The implementation is educational and is not a timezone, locale, or production scheduling library.

## Possible Improvements

- Resolve the ambiguous `IncreaseDateByOneDay` API and restore a clean build
- Replace narrow counters with appropriate integer and size types
- Validate parsing before indexing date components
- Add immutable operations, const-correctness, and clear naming for mutating methods
- Add automated tests for leap years, month boundaries, invalid dates, and date differences
- Consider the C++ `<chrono>` calendar types for modern implementations

## Author

[Mohammad Abdelfattah](https://github.com/mohammadimad)
