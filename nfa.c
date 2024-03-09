
#include <stdlib.h>
#include <stdbool.h>
//#include "include/IntHashSet.h"
#include <stdio.h>
#include "vec.h"
/**
 * The data structure used to represent a none-deterministic finite automaton.
 * @see FOCS Section 10.2
 * Note that YOU must specify this data structure, although you can hide
 * (encapsulate) its implementation behind the declared API functions and
 * only provide a partial declaration in the header file.
 */



typedef struct {
    int* num_states;
    int *accept_states;
    vec_int** transition;
    int start_state;
} NFAS;

/**
 * Allocate and return a new nfa containing the given number of states.
 */
NFAS* new_NFA(int nstates)
{
    NFAS* nfa = (NFAS*)malloc(sizeof(NFAS));
    if(nfa == NULL)
    {
        return NULL; // out of memory
    }

    nfa->num_states = (int*)malloc(sizeof (int)); // might not be allowed and may need to allocate mem first
    if (nfa->num_states == NULL) {
        free(nfa);
        return NULL; // Failed to allocate memory
    }
    *nfa->num_states = nstates;

    nfa->accept_states = (int*)calloc(*nfa->num_states , sizeof(int));
    if (nfa->accept_states == NULL) {
        free(nfa->num_states);
        free(nfa);
        return NULL; // Failed to allocate memory
    }

    // Allocate memory for transition table
    nfa->transition = (vec_int**)calloc(*nfa->num_states, sizeof(vec_int*));
    if (nfa->transition == NULL) {
        free(nfa->accept_states);
        printf( "Memory allocation for row w failed.\n");
        free(nfa);
        return NULL; // Failed to allocate memory
    }
// for nfa we allocate in each cell the size of a hashset with all num of states, we will see how that goes
    for (int i = 0; i < *nfa->num_states; i++) {
        nfa->transition[i] = (vec_int*)calloc(130,  sizeof(vec_int));
        if (nfa->transition[i] == NULL) {
            fprintf(stderr, "Memory allocation for row %zu failed.\n", i);
            return 0 ;
        }
        // Initialize each IntHashSet

       // int* num_vec = vector_create();
      //  nfa->transition[i] = num_vec;
        for (int j = 0; j < 130; j++) {
            nfa->transition[i][j] = vector_create();
         //   vector_add(&nfa->transition[i][j], 69);
        //    printf("%d", nfa->transition[i][j][0]);
        }

        if (nfa->transition[i] == NULL) {
            // Free previously allocated memory
            for (int j = 0; j < i; j++) {
                free(nfa->transition[j]);
            }
            free(nfa->transition);
            free(nfa->accept_states);
            free(nfa);
            return NULL; // Failed to allocate memory
        }
    }

    return nfa;

}

/**
 * Free the given nfa.
 */
void NFA_free(NFAS* nfa)
{
    // Free each row of the transition table
    for (int i = 0; i < nfa->num_states; i++) {
        free(nfa->transition[i]);
    }

    // Free the transition table itself
    free(nfa->transition);

    // Free the accept states array
    free(nfa->accept_states);

    // Finally, free the nfa itself
    free(nfa);
    nfa = NULL;
}

/**
 * Return the number of states in the given nfa.
 */
// extern int nfa_get_size(nfa nfa);

/**
 * Return the state specified by the given nfa's transition function from
 * state src on input symbol sym.
 */

//same as DFA get transition but we now return a vector
// if a state doesn't have a transition to other state for a given input, then an empty set is returned.
vec_int NFA_get_transitions(NFAS *nfa, int src, char sym)
 {
    if(nfa->transition[src][sym] != NULL)
        return  nfa->transition[src][sym];
    else
    {
        vec_int empty = vector_create();
        vector_add(&empty, 69);
        return empty;
    }
 }

/**
 * For the given nfa, set the transition from state src on input symbol
 * sym to be the state dst.
 */
void NFA_add_transition(NFAS *nfa, int src, char sym, int dst)
{
    //src are states, and symbols represent inputs such as when an input a is given while in a state s the destination state is d
    if (src >= 0 && src < nfa->num_states && dst >= 0 && dst < nfa->num_states) {
         vector_add(&nfa->transition[src][sym], dst);


    } else {
        printf("invalid destination state, state out of bound\n");
    }
}





/**
 * Set whether the given nfa's state is accepting or not.
 */

// set the list of accepting states
void  NFA_set_accepting(NFAS *nfa, int state, bool val)
{
    if (state < 0 || state >= nfa->num_states) {
        printf("Error: state %d out of bounds\n", state);
    }
    nfa->accept_states[state] = val;
}

/**
 * Return true if the given nfa's state is an accepting state.
 */

// check if that state is from the list of accepting states
bool NFA_get_accepting(NFAS *nfa, int state)
{
    if (state < 0 || state >= nfa->num_states) {
        printf("Error: state %d out of bounds\n", state);
        return false;
    }
    return nfa->accept_states[state];

}



// turns out, its easier to do it recursively
bool NFA_Recursive_Execute(NFAS *nfa, char *input, int index, vec_int current_states)
{
    // Base case: If we've reached the end of the input
    if (input[index] == '\0')
    {
        // Check if any of the current states are accepting
        for (int i = 0; i < vector_size(current_states); i++)
        {
            if (NFA_get_accepting(nfa, current_states[i]))
                return true;
        }
        // If none of the current states are accepting, return false
        return false;
    }

    // Recursive case: For each current state, follow all transitions for the current input symbol
    for (int i = 0; i < vector_size(current_states); i++)
    {
        vec_int next_states = NFA_get_transitions(nfa, current_states[i], input[index]);
      //  for (int j = 0; j < vector_size(next_states); j++)
      //      printf("%d",next_states[j]);
        if (NFA_Recursive_Execute(nfa, input, index + 1, next_states))
            return true;
    }

    // If no accepting state is reachable, return false
    return false;
}



/**
 * Run the given nfa on the given input string, and return true if it accepts
 * the input, otherwise false.
 */
bool NFA_execute(NFAS *nfa, char *input, int start)
{
    nfa->start_state = start;
    if(NFA_get_accepting(nfa, nfa->start_state))
        return true;
    // start state, then loop
    // int current_state = nfa->start_state;
    int* current_states = vector_create();
    vector_add(&current_states, start);



    for (int i = 0;  input[i] != '\0'; i++)
    {
        int* next_states = vector_create();
     //   current_states = NFA_get_transitions(nfa, current_state, input[i]);

        // here, we will go over the vector and go over each current state produced by it, then we can put that in another vector of all end states basically then go check
        //if any of them are accepting

        for (int j = 0; j < vector_size(current_states); j++)
        {
            int current_state = current_states[j];
            int* transitions = NFA_get_transitions(nfa, current_state, input[i]);
            vec_union(next_states, transitions);
        }

        vec_clear(current_states);
        current_states= _vector_copy(next_states,sizeof (int));
        vec_clear(next_states);

        for (int j = 0; j < vector_size(current_states); j++)
        {
            if(NFA_get_accepting(nfa, current_states[j]))
            {
                return true;
            }
        }

    }



    return false;




}



/**
 * Print the given nfa to System.out.
 */
// extern void nfa_print(nfa nfa);
//
// Created by 15854 on 2/4/2024.
//
