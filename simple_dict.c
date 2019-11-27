// put the source code of main program here.
// reading file
// saving to link list list
// get command from user, and display the result
#include "util.h"
void main() {
	FILE *dict = NULL;
	FILE *output = NULL;
	char* temp_buff = "0";
	char* buff_result;
	char* word_searching;
	struct Word* word_result;
	struct Word* new_word;
	int position = 0;
	int flag;
	dict = fopen("dictionary.txt", "rt");
	output = fopen("output.txt","wt");
	if (dict == NULL) {
		printf("Not content in file");
	}
	/*Set value for hashtable*/
	set_hashdict(hashdict);
	while (!feof(dict)) {
		temp_buff = (char*)malloc(sizeof(char) * 100);
		fgets(temp_buff,200,dict);
		if (temp_buff[0] == '#') {
			shift_buff(temp_buff);
			position = ftell(dict) + 1;

			new_word = create_word(temp_buff, position);
			fprintf(output, "%s", new_word->word);
			flag = insert_word(hashdict, new_word);
			if (flag == 0) {
				printf("can not insert word");
			}
		}
	}
	/*Search word*/
	word_searching = (char*)malloc(sizeof(char) * 63);
	printf("Search: ");
	gets(word_searching);
	word_result = search_word(hashdict, word_searching);
	buff_result = (char*)malloc(sizeof(char) * 2048);
	if (word_result == NULL) {
		printf("cant find word %s", word_searching);
	}
	else {
		get_meaning((unsigned char*)buff_result,word_result,dict);
		printf("%s",buff_result);
	}
	free(temp_buff);
	free(word_searching);
	/*Delete hashdict*/
	delete_hashdict(hashdict);
}