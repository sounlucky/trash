
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

// const
const int max_string_sz = 256;

// input a single number
int input_int() {
	int res;
	printf("\t");
	scanf("%d", &res);
	return res;
}

char* input_str() {
	char* res = (char*)malloc(sizeof(char) * max_string_sz);
	printf("\t");
	scanf("%s", res);
	return res;
}

int main() {
	// input keywords
	printf("input number of keywords : \n");
	int keywords_sz = input_int();
	char** keywords = (char**)malloc(sizeof(char*) * keywords_sz);
	printf("input keywords : \n");
	for (int i = 0; i != keywords_sz; ++i) {
		keywords[i] = input_str();
	}
	// input divider
	printf("input divider string : \n");
	char* divider = input_str();
	int divider_sz = strlen(divider);
	// remember if we ever used ith keyword
	bool* used = (bool*)malloc(sizeof(bool) * keywords_sz);
	memset(used, false, sizeof(bool) * keywords_sz); // defaults to false
	// input text
	printf("input text: \n");
	char** text = 0;
	int text_sz = 0;
	for (int text_i = 0; memchr(used, false, keywords_sz); ++text_i) {
		text = (char**)realloc(text, sizeof(char*) * (text_sz = text_i + 1));
		text[text_i] = input_str();
		// check for keywords
		bool keywords_here = 0;
		for (int i = 0; text[text_i][i] != 0; ++i) {
			// check if its a keyword
			char* p = text[text_i] + i; // pointer to current line position
			// skip dividers
			while (*p != 0 && memchr(divider, *p, divider_sz)) {
				++i;
				p = text[text_i] + i;
			}
			for (int k_i = 0; k_i != keywords_sz; ++k_i) {
				if (strlen(p) < strlen(keywords[k_i])) {
					continue;
				}
				// memory matches
				bool res = memcmp(p, keywords[k_i], strlen(keywords[k_i])) == 0;
				//ending is good as well
				res &= *(p + strlen(keywords[k_i])) == 0 || (bool)memchr(divider, *(p + strlen(keywords[k_i])), divider_sz);
				used[k_i] |= res;
				keywords_here |= res;
			}
			// skip the rest of the word
			while (*p != 0 && !memchr(divider, *p, divider_sz)) {
				++i;
				p = text[text_i] + i;
			}
		}
		// remove longest word if any keywords found
		if (keywords_here) {
			int max_len = 0;
			int curr_len = 0;
			for (char* p = text[text_i]; *p != 0; ++p) {
				curr_len = memchr(divider, *p, divider_sz) ? 0 : curr_len + 1;
				if (curr_len > max_len) {
					max_len = curr_len;
				}
			}
			// if at least one found, delete all the words 1 yt . so..yt..po.pl
			curr_len = 0;
			if (max_len > 0) {
				for (char* p = text[text_i]; *p != 0; ++p) {
					curr_len = memchr(divider, *p, divider_sz) ? 0 : curr_len + 1;
					if (curr_len == max_len) {
						p -= max_len - 1;
						memmove(p, p + max_len, strlen(p + max_len) + 1);
						curr_len = 0;
					}
				}
			}
		}
	}
	printf("\nresult :\n");
	for (int i = 0; i != text_sz; ++i)
		printf("\t%s\n", text[i]);
	system("pause");
	// delete all the stuff
	free(used);
	free(divider);
	if (text) {
		for (int i = 0; i != text_sz; ++i)
			free(text[i]);
	}
	free(text);
	if (keywords) {
		for (int i = 0; i != keywords_sz; ++i)
			free(keywords[i]);
	}
	free(keywords);
}