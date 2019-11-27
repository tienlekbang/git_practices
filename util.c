// put the implementation of utility functions here
#include "util.h"

/*Function to create a new object of struct Word*/
struct Word* create_word(const char *w, unsigned long off) {
	struct Word *point_word;
	point_word = (struct Word*)malloc(sizeof(struct Word));
	point_word->word = (unsigned char)*w;
	point_word->offset = (unsigned long)off;
	point_word->next = NULL;
}
int hash_word(unsigned char *w) {
	int hash_code = 0;
	int first_letter = *w;

	if (first_letter > 47 && first_letter < 58) {
		hash_code = first_letter - 48;
	}else{
		if (first_letter > 64 && first_letter < 91) {
			hash_code = first_letter - 55;
		}
		else {
			if(first_letter > 96 && first_letter < 123){
				hash_code = first_letter - 61;
			}
			else {
				hash_code = 62;
			}
		}
	}
	return hash_code;
	
}
// int insert_word(struct Word **hd, struct Word *wobject) {
	// int hash_code = 0;
	int flag = 0;
	struct Word *word_add;
	struct Word *temp;
	word_add = (struct Word*)malloc(sizeof(struct Word));
	word_add->word = wobject->word;
	word_add->offset = wobject->offset;
	hash_code = hash_word(word_add->word);
	temp = hd[hash_code];
	if (temp == NULL) {
		hd[hash_code] = (struct Word*)malloc(sizeof(struct Word));
		hd[hash_code]->word = word_add->word;
		hd[hash_code]->offset = word_add->offset;
		hd[hash_code]->next = NULL;
	}
	else {
		while (temp->next =! NULL)
		{
			if (strcmp((char*)temp->word, (char*)word_add->word) == 0)
			flag = 1;
			temp = temp->next;	
		}
	}	if (flag != 1) {
		temp->word = word_add;
		word_add->next = NULL;
	}
	return flag;
}
void set_hashdict(struct Word* *hd) {
	int i;
	for (i = 0; i < HASH_SIZE; i++) {
		hd[i] = NULL;
	}
}
struct Word* search_word(struct Word **hd, unsigned char *word) {
	int hash_code = 0;
	struct Word *temp;
	hash_code = hash_word(word);
	temp = hd[hash_code];
	if (temp->next == NULL) {
		return NULL;
	}
	else {
		while (temp->next != NULL) {
			if (strcmp((char*)temp->word, (unsigned char*)word) == 0) {
				return temp;
				temp = temp->next;
			}
		}
	}
	return NULL;
}
void shift_buff(char *buf)
{
	int i;

	for (i = 0; buf[i + 1] != '\0'; i++)
		buf[i] = buf[i + 1];
		buf[i - 1] = '\0';
}
int get_meaning(unsigned char *buf, struct Word* wobject, FILE *dict_file) {
	unsigned char *buff_meaning;
	buff_meaning = (unsigned char*)malloc(sizeof(char) * 500);
	fseek(dict_file, wobject->word, SEEK_SET);
	buf[0] = '\0';
	buff_meaning[0] = '\0';
	while (buff_meaning[0] != '#' && (!feof(dict_file))) {
		strcat((char *)buf, (char *)buff_meaning);
		fgets((char*)buff_meaning, 500, dict_file);
	}
	free(buff_meaning);

	if (buf[0] != '\0')
		return 1;
	else
		return 0;
}
void delete_hashdict(struct Word **hd) 
{
	int i;
	struct Word *temp = NULL;
	struct Word *del = NULL;
	for (i = 0; i<63; i++)
	{
		temp = hd[i];
		if (NULL != temp)
		{
			delete_branch(temp);
		}
	}
}
void delete_branch(struct Word *root)
{
	int i;
	struct Word *del = NULL;

	while (NULL != root->next)
	{
		del = root;
		root = root->next;
		free(del);
	}
	free(root);
}