/*
 * Do *NOT* edit this file
 */
#ifndef PA08_H
#define PA08_H

// 4x4 puzzle
#define SIDELENGTH 4
#define FINAL_STATE "123456789ABCDEF-"

#define MAX_SEARCH_DEPTH 9

/**
 * Prints the puzzle-state as a 2d matrix. 
 *
 * This function is supplied to you.
 */
void printPuzzle(const char * state);

// --------------------------------------------------------------------- Stage 0
/** 
 * Return TRUE iff 'state' is a valid puzzle state.
 *
 * This function is supplied to you.
 *
 * The function works by checking:
 * strlen(state) == 16
 * That 'state' only contains characters from "123456789ABCDEF-"
 * That 'state' contains no repeated characters
 */
int isValidState(const char * state);

/** 
 * Return TRUE iff all characters in 'moves' are in "RLUD"
 *
 * This function is supplied to you.
 *
 * The function iterates over the string, and check that
 * each character is one of { 'R', 'L', 'U', 'D' }
 */
int isValidMoveList(const char * movelist);

// --------------------------------------------------------------------- Stage 1
/**
 * Apply move 'm' to puzzle-state 'state'. Return TRUE iff success.
 *
 * This function is supplied to you.
 *
 * It is assumed that 'm' is one of { 'U', 'D', 'L', 'R' }, and 
 * that 'state' is a valid state, which means it contains a '-' 
 * character.
 *
 * The function works as follows:
 * (1) Find the row and column of the space character '-'
 *     (1.a) Search 'state' for the 'position' of the '-' character
 *     (1.b) The 'row' will be 'position / SIDELENGTH'
 *     (1.c) The 'col' will be 'position % SIDELENGTH'
 * (2) Look at the move 'm', and calculate the _new_ row and col
 *     (2.a) If 'm' == 'U', then 'new_row = row-1' and 'new_col = col'
 *     etc.
 * (3) Check that 'new_row' and 'new_col' are in bounds. They must
 *     be >= 0 and < SIDE_LENGTH. If they are _not_ in bounds, then
 *     return FALSE
 * (4) Calculate the 'target_position' for the '-' character. It will
 *     be 'new_row * SIDELENGTH + new_col'
 * (5) Swap the characters at 'position' and 'target_position'
 */
int move(char * state, char m);

/**
 * Apply the moves in 'movelist' to state. 
 *
 * This function is supplied to you
 *
 * If the sequence is invalid, then the function prints "I" on a single line.
 * Otherwise, prints the new state after moves have been applied.
 *
 */
void processMoveList(char * state, const char * movelist);


//The functions below (except solve for stage 3) are the ones you need to implement


// --------------------------------------------------------------------- Stage 2
// Generating all possible states in up to the given number of moves

// No two nodes in a MoveTree have the same 'state'
typedef struct move_tree_st {
    char * state;
    char * moves;
    struct move_tree_st * left;
    struct move_tree_st * right;
} MoveTree;

/**
 * Initialise a new MoveTree.
 * Allocate heap memory for the node, as well as the state and moves attributes
 */
MoveTree * MoveTree_create(const char * state, const char * moves);


/**
 * Destroy a tree -- must be safe to call MoveTree_destroy(NULL)
 */
void MoveTree_destroy(MoveTree * node);


/**
 * Nodes in the tree are sorted by state, so you can use strcmp to compare the states
 * Traverse the left subtree if the returned value is less than 0, traverse the right subtree if
 * the returned value is greater than 0. If the return value is 0 follow the folliwing rules:
 * (1) We do not allow duplicate states in the actual tree.
 * (2) If we attempt to insert a duplicate state, then we keep the
 *     node with the shortest move sequence (compare the move sequence lengths).
 * 
 * 
 */
MoveTree * MoveTree_insert(MoveTree * node, 
			   const char * state, 
			   const char * moves);

/**
 * Search the tree (rooted at 'node') for a node whose state is 'state'
 */
MoveTree * MoveTree_find(MoveTree * node, const char * state);

/**
 * Print the moves in a move-tree.
 * This function is supplied to you.
 */
void MoveTree_print(MoveTree * node);

/**
 * Generate all possible states from 'state' after 0 to 'n_moves'.
 * Returns a 'MoveTree' which contains all of the unique states
 * reachable from 'state' after '0..n_moves' (inclusive). If the same
 * state can be reached by different move sequences, then prefer the
 * shorter of the two sequences.
 * 
 * To write this function you need to create a list of unique states.
 * To do this, you must store the states in a tree, so that when you
 * insert a new state, you can _quickly_ check if it already exists.
 *
 * You will need to create a 'helper' function:
 * 
 * void generateAllHelper(MoveTree * root, // Root of the tree
 *         int n_moves,        // maximum length of a movelist
 *         const char * state, // the current state of the puzzle
 * 	   char * movelist,    // the current movelist
 *         int ind)            // the next index to write in movelist
 *
 * This recursive helper function works as follows:
 * (1) The base case: ind == n_moves. Do _nothing_ and return
 * (2) The recursive case:
 *    (2.a) Iterate over the possible moves { 'U', 'D', 'L', 'R'}
 *        (2.a.i) Duplicate 'state' and store it in 'dup_state'
 *                You do this because you don't want to corrupt 
 *                'state' for any other move sequences.
 *        (2.a.ii) Try to apply move 'm' to 'dup_state'. If it doesn't
 *                 work, then do nothing and free 'dup_state'
 *        (2.a.iii) If the move was applied, then insert 'dup_state'
 *                  and 'movelist' into the tree 'root'. Be careful...
 *                  MoveTree_insert(...) expects 'movelist' to be a 
 *                  valid c-string, so you _must_ make sure that the
 *                  null-byte is correctly set.
 *        (2.a.iv) Recursively call generateAllHelper(...) with the
 *                 duplicated state, mutated movelist, and updated ind
 *        (2.a.v) Free 'dup_state'
 *
 * Once you have your helper function written, then you can:
 * (1) Create a 'movelist' buffer that can hold a string of length 
 *     n_moves. (Don't forget the null byte.)
 * (2) Create a MoveTree, with 'state' and an empty move list.
 * (3) Call your helper function.
 * (4) Return the tree.
 *
 * This is the most complex function to write... make sure you break
 * it down, and TEST EACH PART.
 */
MoveTree * generateAll(char * state, int n_moves);

// --------------------------------------------------------------------- Stage 3

/**
 *
 * Solves the puzzle
 * This function is supplied to you
 *
 * To solve the puzzle:
 * (1) Generate all the possible states up to MAX_SEARCH_DEPTH
 * (2) Search the possibilities for FINAL_STATE
 * (3) If FINAL_STATE isn't found, return NULL
 * (4) If FINAL_STATE is found, then return a copy of the moves.
 */
char * solve(char * state);

#endif


