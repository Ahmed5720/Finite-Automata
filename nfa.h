/*
 * File: nfa.h
 * Creator: George Ferguson
 * Created: Thu Sep  1 17:54:41 2016
 */

#ifndef _nfa_h
#define _nfa_h

#include <stdbool.h>
//#include "Set.h"

/**
 * The data structure used to represent a nondeterministic finite automaton.
 * @see FOCS Section 10.3
 * @see Comments for DFA in dfa.h
 */
typedef struct {
    int* num_states;
    int *accept_states;
    int **transition;
    int start_state;
} NFAS;

/**
 * Allocate and return a new NFA containing the given number of states.
 */
extern NFAS* new_NFA(int nstates);

/**
 * Free the given NFA.
 */
extern void NFA_free(NFAS* nfa);

/**
 * Return the number of states in the given NFA.
 */
// extern int NFA_get_size(NFA nfa);

/**
 * Return the set of next states specified by the given NFA's transition
 * function from the given state on input symbol sym.
 */
extern vec_int NFA_get_transitions(NFAS *nfa, int state, char sym);

/**
 * For the given NFA, add the state dst to the set of next states from
 * state src on input symbol sym.
 */
extern void NFA_add_transition(NFAS *nfa, int src, char sym, int dst);
bool NFA_Recursive_Execute(NFAS *nfa, char *input, int index, vec_int current_states);
/**
 * Add a transition for the given NFA for each symbol in the given str.
 */
//extern void NFA_add_transition_str(NFA nfa, int src, char *str, int dst);

/**
 * Add a transition for the given NFA for each input symbol.
 */
// extern void NFA_add_transition_all(NFA nfa, int src, int dst);

/**
 * Set whether the given NFA's state is accepting or not.
 */
extern void NFA_set_accepting(NFAS *nfa, int state, bool value);

/**
 * Return true if the given NFA's state is an accepting state.
 */
extern bool NFA_get_accepting(NFAS *nfa, int state);

/**
 * Run the given NFA on the given input string, and return true if it accepts
 * the input, otherwise false.
 */
extern bool NFA_execute(NFAS *nfa, char *input, int start);

/**
 * Print the given NFA to System.out.
 */
//extern void NFA_print(NFA nfa);

#endif
