.PHONY: format
format:
	@find src -type f \( -name '*.cpp' -o -name '*.hpp' \) -print0 | xargs -0 clang-format -i