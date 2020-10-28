
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_INPUT_SIZE 1048576 // 1048576 = 1024*1024 = 1 MB input file
#define ASCII_RANGE 128

typedef struct node {
	char ch;
	int freq;
	struct node *left;
	struct node *right;
} node;

typedef node** node_pointers;
typedef char** ascii_code_mappings;

void swap(node_pointers nodes, int i, int j){
	node *temp;
	temp = nodes[i];
	nodes[i] = nodes[j];
	nodes[j] = temp; 
}

void sort(node_pointers nodes, int start, int length){

	for(int i=length-1; i>=start; i--){
		for(int j=start; j<i; j++){
			if(nodes[j]->freq > nodes[j+1]->freq){
				swap(nodes, j, j+1);
			}
		}
	}
}

node* make_node(char ch, unsigned int frequency){
	node *n = (node*)calloc(1, sizeof(node));
	n->ch = ch;
	n->freq = frequency;
	n->left = NULL;
	n->right = NULL;
	return n;
}

node* generate_huffman_tree(node_pointers unique_character_nodes, int unique_characters_count){

	sort(unique_character_nodes, 0, unique_characters_count);

	// logs
	// for(int i=0; i<unique_characters_count; i++){
	// 	printf("%d ", unique_character_nodes[i]->freq);
	// }
	// printf("\n");

	int start = 0;
	int remaining_characters = unique_characters_count;
	int leaves_freq_sum = -1;

	node *root, *temp;

	leaves_freq_sum = unique_character_nodes[start]->freq + unique_character_nodes[start+1]->freq;
	root = make_node(-1, leaves_freq_sum);
	root->left = unique_character_nodes[start];
	root->right = unique_character_nodes[start+1];

	start += 2;
	remaining_characters -= 2;

	while(remaining_characters >= 2){
		//
		start -= 1;
		remaining_characters += 1;
		unique_character_nodes[start] = root; // Add the sub tree root back to array
		sort(unique_character_nodes, start, unique_characters_count);
		//
		leaves_freq_sum = unique_character_nodes[start]->freq + unique_character_nodes[start+1]->freq;
		root = make_node(-1, leaves_freq_sum);
		root->left = unique_character_nodes[start];
		root->right = unique_character_nodes[start+1];
		//
		start += 2;
		remaining_characters -= 2;	
	}

	if(remaining_characters == 1){
		leaves_freq_sum = unique_character_nodes[start]->freq + root->freq;
		temp = root;
		root = make_node(-1, leaves_freq_sum);
		//
		if(unique_character_nodes[start]->freq > root->freq){
			root->left = temp;
			root->right = unique_character_nodes[start];
		} else {
			root->right = unique_character_nodes[start];
			root->left = temp;
		}
	}

	return root;
}

void generate_huffman_codes(node* root, ascii_code_mappings map, char *code, int code_length){

	if(root->left == NULL && root->right == NULL){ // leaf node
		char *new_code = (char*)calloc(code_length, sizeof(char));
		for(int i=0; i<=code_length; i++) new_code[i] = code[i];
		map[root->ch] = new_code;
		// logs
		// printf("'%c', %3d, %s\n", root->ch, root->ch, new_code);
	} else {
		if(root->left != NULL){
			code[code_length] = '0';
			generate_huffman_codes(root->left, map, code, code_length+1);	
		}
		if(root->right != NULL){
			code[code_length] = '1';
			generate_huffman_codes(root->right, map, code, code_length+1);
		}
	}

}

int main(int argc, char* argv[]){

	if(argc != 2){
		printf("\nPlease run with a filename argument\n");
		printf("Like: \n\t$ ./a.out dummy_text.txt\n\n"); 
		return -1;
	}

	char buffer[MAX_INPUT_SIZE];
	FILE * handler = fopen(argv[1], "r");
	int input_size = 0;
	char c;

	while((c=fgetc(handler))!=EOF){
		buffer[input_size] = c;
		input_size++;
	}

	// Collect character frequencies
	int* frequencies = (int*)calloc(ASCII_RANGE, sizeof(int));
	int  unique_characters_count = 0;
	for(int i=0; i<input_size; i++){
		if( frequencies[ buffer[i] ] == 0 ) unique_characters_count++;
		frequencies[ buffer[i] ]++;
	}

	node_pointers unique_character_nodes = (node_pointers)calloc(unique_characters_count, sizeof(node*));
	int unique_character_nodes_size = 0;
	for(int i=0; i<128; i++){
		if(frequencies[i] != 0){
			unique_character_nodes[unique_character_nodes_size] = make_node(i, frequencies[i]);
			unique_character_nodes_size++;
		}
	}

	// logs
	// printf("%d %d", unique_characters_count, char_frequency_map_size);
	// for(int i=0; i<char_frequency_map_size; i++) 
		// printf("'%c' %3d\n", char_frequency_map[i].ch, char_frequency_map[i].freq);

	node* huffman_tree_root = generate_huffman_tree(unique_character_nodes, unique_characters_count);
	//
	// Generate Huffman codes as string
	char* code = (char*)calloc(unique_characters_count, sizeof(char));
	int code_size = 0;
	ascii_code_mappings code_map = (ascii_code_mappings)calloc(ASCII_RANGE, sizeof(char*));
	for(int i=0; i<ASCII_RANGE; i++) code_map[i] = NULL;
	generate_huffman_codes(huffman_tree_root, code_map, code, code_size);

	// logs
	// int counted_nodes = 0;
	// for(int i=0; i<ASCII_RANGE; i++){
	// 	if( code_map[ i ] != NULL ){
	// 		counted_nodes++;
	// 		printf("CHAR: '%c',\tFREQ: %3d\tCODE: %s\n", i, frequencies[i], code_map[i]);
	// 	}
	// }
	// if(unique_characters_count != counted_nodes){
	// 	printf("Nodes we lost in making of the tree!");
	// 	return -1;
	// }

	// Calculate the new length of the data
	int total_binary_length = 0;
	for(int i=0; i<input_size; i++) total_binary_length += strlen( code_map[ buffer[i] ] );
	int new_size = total_binary_length/8 + 1;

	printf("Old Length:  %d bytes\n", input_size);
	printf("New Length: ~%d bytes (%d bits)\n", new_size, total_binary_length);

	// Additional data for maps
	{
		typedef struct char_code {
			char c;
			unsigned short code_length;
			char* code;
		} char_code;

		int map_size = sizeof(char_code) * unique_characters_count;
		// suppose the first 'sizeof(void*)' bytes in out 'new_data' indicate the starting
		// point of the map
		int single_address_size = sizeof(void*);

		int new_size_final = new_size + map_size + single_address_size;
		printf("New Length (with all mapping info): ~%d bytes\n", new_size_final);
		//
		float sizes_ratio = (float)new_size_final / (float)input_size;
		printf("Compressed file will be %.3f%% of original file.\n", sizes_ratio*100);
	}

	return 0;
}
