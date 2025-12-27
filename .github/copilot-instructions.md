# Copilot Instructions for this repo

- **Repo shape**: Tiny C++ training repo. Files: `CONCEPTS.md` (exercise notes), `ex00.cpp` (currently empty placeholder).
- **Scope**: C++ Module 00 topics only (meant for 42-style training). Expect simple console programs; no external deps.

## Patterns to follow
- Stay within **C++98**-era features and standard library only (matches Module 00 expectations).
- Prefer **std::string** operations; avoid C-style strings unless required.
- For character case handling, use `std::toupper` on `unsigned char` conversions to avoid UB.
- Handle edge cases explicitly: empty input, missing CLI args, input truncation for fixed-width displays.

## Exercise expectations from `CONCEPTS.md`
- **Exercise 00 (Megaphone)**: iterate command-line args, uppercase chars, print via `std::cout`. Provide a sensible fallback when no args are passed (e.g., note the absence rather than crashing).
- **Exercise 01 (PhoneBook)**: implement `Contact` and `PhoneBook` classes with fixed array of 8 contacts, circular replacement when full. Use formatted output (`std::setw(10)`, right-aligned) and truncate displayed fields to width 10 with a trailing dot when longer.
- Keep class declarations in headers with include guards; place method definitions in `.cpp` files.

## Build/run workflow
- No build tooling present. Compile individual programs directly, e.g. `g++ -std=c++98 ex00.cpp -o ex00` (add `-Wall -Wextra -Werror` if desired). Run resulting binaries from repo root.

## Coding conventions
- Favor small, readable functions; keep IO and logic straightforward for console apps.
- Validate user input: reject empty fields for PhoneBook entries; keep the prompt loop until `EXIT` is entered (per Module 00 norms).
- Avoid dynamic allocation; use fixed-size arrays where concepts specify.
- Keep outputs deterministic and minimal; no extra prompts beyond what the exercises need.

## If adding files
- Mirror exercise names (`ex01.cpp`, `PhoneBook.hpp`, etc.) and keep each exercise self-contained.
- Update `CONCEPTS.md` alongside new exercises to document expectations the code implements.
