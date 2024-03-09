
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
/**
 * The data structure used to represent a deterministic finite automaton.
 * @see FOCS Section 10.2
 * Note that YOU must specify this data structure, although you can hide
 * (encapsulate) its implementation behind the declared API functions and
 * only provide a partial declaration in the header file.
 */
typedef struct {
    int* num_states;
    int *accept_states;
    int **transition;
    int start_state;
} DFAS;

/**
 * Allocate and return a new DFA containing the given number of states.
 */
 DFAS* new_DFA(int nstates)
{
    DFAS* dfa = (DFAS*)malloc(sizeof(DFAS));
    if(dfa == NULL)
    {
        return NULL; // out of memory
    }

    dfa->num_states = (int*)malloc(sizeof (int)); // might not be allowed and may need to allocate mem first
    if (dfa->num_states == NULL) {
        free(dfa);
        return NULL; // Failed to allocate memory
    }
    *dfa->num_states = nstates;

    dfa->accept_states = (int*)calloc(*dfa->num_states , sizeof(int));
    if (dfa->accept_states == NULL) {
        free(dfa->num_states);
        free(dfa);
        return NULL; // Failed to allocate memory
    }

    // Allocate memory for transition table
    dfa->transition = (int*)calloc(*dfa->num_states, sizeof(int *));
    if (dfa->transition == NULL) {
        free(dfa->accept_states);
        free(dfa);
        return NULL; // Failed to allocate memory
    }

    for (int i = 0; i < *dfa->num_states; i++) {
        dfa->transition[i] = (int*)calloc(255, sizeof(int));
        if (dfa->transition[i] == NULL) {
            // Free previously allocated memory
            for (int j = 0; j < i; j++) {
                free(dfa->transition[j]);
            }
            free(dfa->transition);
            free(dfa->accept_states);
            free(dfa);
            return NULL; // Failed to allocate memory
        }
    }

    return dfa;

}

/**
 * Free the given DFA.
 */
void DFA_free(DFAS* dfa)
{
    // Free each row of the transition table
    for (int i = 0; i < dfa->num_states; i++) {
        free(dfa->transition[i]);
    }

    // Free the transition table itself
    free(dfa->transition);

    // Free the accept states array
    free(dfa->accept_states);

    // Finally, free the DFA itself
    free(dfa);
    dfa = NULL;
}

/**
 * Return the number of states in the given DFA.
 */
// extern int DFA_get_size(DFA dfa);

/**
 * Return the state specified by the given DFA's transition function from
 * state src on input symbol sym.
 */
int DFA_get_transition(DFAS *dfa, int src, char sym)
{
    return  dfa->transition[src][sym];
}

/**
 * For the given DFA, set the transition from state src on input symbol
 * sym to be the state dst.
 */
void DFA_set_transition(DFAS *dfa, int src, char sym, int dst)
{
    //src are states, and symbols represent inputs such as when an input a is given while in a state s the destination state is d
    if (src >= 0 && src < dfa->num_states && dst >= 0 && dst < dfa->num_states) {
        dfa->transition[src][sym] = dst;
    } else {
        printf("invalid destination state, state out of bound\n");
    }
}





/**
 * Set whether the given DFA's state is accepting or not.
 */

// set the list of accepting states
void  DFA_set_accepting(DFAS *dfa, int state, bool val)
{
    if (state < 0 || state >= dfa->num_states) {
        printf("Error: state %d out of bounds\n", state);
    }
    dfa->accept_states[state] = val;
}

/**
 * Return true if the given DFA's state is an accepting state.
 */

// check if that state is from the list of accepting states
bool DFA_get_accepting(DFAS *dfa, int state)
{
    if (state < 0 || state >= dfa->num_states) {
        printf("Error: state %d out of bounds\n", state);
        return false;
    }
    return dfa->accept_states[state];

}

/**
 * Run the given DFA on the given input string, and return true if it accepts
 * the input, otherwise false.
 */
bool DFA_execute(DFAS *dfa, char *input, int start)
{
    dfa->start_state = start;
    if(DFA_get_accepting(dfa, dfa->start_state))
        return true;
    // start state, then loop
    int current_state = dfa->start_state;
    for (int i = 0; i < input[i] != '\0'; i++)
    {
        current_state = DFA_get_transition(dfa, current_state, input[i]);


    }
    if(DFA_get_accepting(dfa, current_state))
    {
        return true;
    }
    return false;
}

/**
 * Print the given DFA to System.out.
 */
// extern void DFA_print(DFA dfa);
//
// Created by 15854 on 2/4/2024.
//

