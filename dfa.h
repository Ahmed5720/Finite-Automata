#ifndef DFAS_H
#define DFAS_H

#include <stdbool.h>

typedef struct {
    int* num_states;
    int *accept_states;
    int **transition;
    int start_state;
} DFAS;

DFAS* new_DFA(int nstates);
void DFA_free(DFAS* dfa);
int DFA_get_transition(DFAS *dfa, int src, char sym);
void DFA_set_transition(DFAS *dfa, int src, char sym, int dst);
void DFA_set_accepting(DFAS *dfa, int state, bool val);
bool DFA_get_accepting(DFAS *dfa, int state);
//void DFA_set_transition_all(DFAS *dfa, int src, char *dstrng, int dfalength);
bool DFA_execute(DFAS *dfa, char *input,int start);
#endif /* DFAS_H */
