
// put the interface of utility functions here
#include "hashtable.h"
struct Word* create_word(const char *w, unsigned long off);
int insert_word(struct Word **hd, struct Word *wobject);
int hash_word(unsigned char *w);
struct Word* search_word(struct Word **hd, unsigned char *word);
void set_hashdict(struct Word* *hd);
void shift_buff(char *buf);
int get_meaning(unsigned char *buf, struct Word* wobject, FILE *dict_file);
void delete_branch(struct Word *root);
void delete_hashdict(struct Word **hd);