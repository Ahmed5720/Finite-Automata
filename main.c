#include <stdio.h>
#include <stdlib.h>
#include "dfa.h"
#include "vec.h"
#include "nfa.h"
#include <math.h>

bool TestForDfaStartWith_cat(char *in){
    printf("testing dfa that recognizes dfa starting in cat\n");

    DFAS *dfa = new_DFA(5);
    DFA_set_accepting(dfa, 3, true);
    DFA_set_accepting(dfa, 0, false);
    DFA_set_accepting(dfa, 1, false);
    DFA_set_accepting(dfa, 2, false);
    DFA_set_accepting(dfa,4 , false);


    //sets transitions
    DFA_set_transition(dfa, 0, 'c', 1);
    DFA_set_transition(dfa, 0, 'a', 4);
    DFA_set_transition(dfa, 0, 't', 4);

    DFA_set_transition(dfa, 1, 'c', 4);
    DFA_set_transition(dfa, 1, 'a', 2);
    DFA_set_transition(dfa, 1, 't', 4);

    DFA_set_transition(dfa, 2, 'c', 4);
    DFA_set_transition(dfa, 2, 'a', 4);
    DFA_set_transition(dfa, 2, 't', 3);

    DFA_set_transition(dfa, 3, 'c', 3);
    DFA_set_transition(dfa, 3, 'a', 3);
    DFA_set_transition(dfa, 3, 't', 3);

    for (int i = 35; i < 127; i++)
    {

        if((char)i != 'c' && (char)i != 'a' && (char)i!= 't')
        {
            // set to last state
            DFA_set_transition(dfa, 0, (char)i, 4);
            DFA_set_transition(dfa, 1, (char)i, 4);
            DFA_set_transition(dfa, 2, (char)i, 4);
            DFA_set_transition(dfa, 3, (char)i, 3);

        }

    }
    bool result = DFA_execute(dfa, in, 0);
    return result;
    //DFA_free(dfa);
}
bool TestForBinaryInputEvenZeroOddOne(char *in)
{
    printf("testing dfa that recognizes dfa starting with even num of zeros and odd number of ones\n");

    DFAS *dfa = new_DFA(6);
    DFA_set_accepting(dfa, 0, false);
    DFA_set_accepting(dfa, 1, false);
    DFA_set_accepting(dfa, 2, false);
    DFA_set_accepting(dfa, 3, false);
    DFA_set_accepting(dfa, 4, true);
    DFA_set_accepting(dfa, 5, false);


    //sets transitions
    DFA_set_transition(dfa, 0, '0', 2);
    DFA_set_transition(dfa, 0, '1', 4);

    DFA_set_transition(dfa, 1, '0', 1);
    DFA_set_transition(dfa, 1, '1', 1);

    DFA_set_transition(dfa, 2, '0', 3);
    DFA_set_transition(dfa, 2, '1', 5);

    DFA_set_transition(dfa, 3, '0', 2);
    DFA_set_transition(dfa, 3, '1', 4);

    DFA_set_transition(dfa, 4, '0', 5);
    DFA_set_transition(dfa, 4, '1', 3);

    DFA_set_transition(dfa, 5, '0', 4);
    DFA_set_transition(dfa, 5, '1', 2);


    // goes over all other alphabets and numbers and sets them to state two which is the state where u get any input that is not 1 or 0
    for (int i = 35; i < 127; i++)
    {

        if((char)i!= '1' && (char)i != '0')
        {
            // set to last state
            DFA_set_transition(dfa, 0, (char)i, 2);
            DFA_set_transition(dfa, 1, (char)i, 2);
            DFA_set_transition(dfa, 2, (char)i, 2);
            DFA_set_transition(dfa, 3, (char)i, 2);
            DFA_set_transition(dfa, 2, (char)i, 2);
            DFA_set_transition(dfa, 3, (char)i, 2);

        }

    }
    bool result = DFA_execute(dfa, in, 0);
    return result; // printf("After careful examination, the given DFA is declared: %s\n", result ? "true" : "false");
    //DFA_free(dfa);

}
bool TestForStringWithExactlyTwo2s(char *in){

    printf("testing dfa that recognizes strings with exactly two 2s\n");

    DFAS *dfa = new_DFA(4);
    DFA_set_accepting(dfa, 2, true);
    DFA_set_accepting(dfa, 0, false);
    DFA_set_accepting(dfa, 1, false);
    DFA_set_accepting(dfa, 3, false);


    //sets transitions
    DFA_set_transition(dfa, 0, '2', 1);
    DFA_set_transition(dfa, 1, '2', 2);
    DFA_set_transition(dfa, 2, '2', 3);



    for (int i = 35; i < 127; i++)
    {
        if((char)i != '2')
        {
            // set to last state
            DFA_set_transition(dfa, 0, (char)i, 0);
            DFA_set_transition(dfa, 1, (char)i, 1);
            DFA_set_transition(dfa, 2, (char)i, 2);


        }

    }
    bool result = DFA_execute(dfa, in, 0);
    return result;
    //printf("After careful examination, the given DFA is declared: %s\n", result ? "true" : "false");
    //DFA_free(dfa);
}
bool TestForDfaWithExactly_dfa(char *in)
{
    printf("testing dfa that recognized exactly dfa\n");

    DFAS *dfa = new_DFA(5);
    DFA_set_accepting(dfa, 3, true);
    DFA_set_accepting(dfa, 0, false);
    DFA_set_accepting(dfa, 1, false);
    DFA_set_accepting(dfa, 2, false);
    DFA_set_accepting(dfa,4 , false);

    //sets transitions
    DFA_set_transition(dfa, 0, 'd', 1);
    DFA_set_transition(dfa, 0, 'f', 4);
    DFA_set_transition(dfa, 0, 'a', 4);

    DFA_set_transition(dfa, 1, 'd', 4);
    DFA_set_transition(dfa, 1, 'f', 2);
    DFA_set_transition(dfa, 1, 'a', 4);

    DFA_set_transition(dfa, 2, 'd', 4);
    DFA_set_transition(dfa, 2, 'f', 4);
    DFA_set_transition(dfa, 2, 'a', 3);

    DFA_set_transition(dfa, 3, 'd', 4);
    DFA_set_transition(dfa, 3, 'f', 4);
    DFA_set_transition(dfa, 3, 'a', 4);

  //  DFA_set_transition_all(dfa, 0 , "211131114555", 3);

    for (int i = 35; i < 127; i++)
    {

        if((char)i != 'd' && (char)i != 'f' && (char)i != 'a')
        {
                // set to last state
                DFA_set_transition(dfa, 0, (char)i, 4);
                DFA_set_transition(dfa, 1, (char)i, 4);
                DFA_set_transition(dfa, 2, (char)i, 4);
                DFA_set_transition(dfa, 3, (char)i, 4);

        }

    }



    bool result = DFA_execute(dfa, in, 0);
    return result;
    //printf("After careful examination, the given DFA is declared: %s\n", result ? "true" : "false");
    //DFA_free(dfa);


}


bool TestForPartialAnagramOfConference(char *in)
{
    printf("testing NFA with strings that are not anagrams of conference\n");

    NFAS *nfa = new_NFA(17);
    NFA_set_accepting(nfa, 2, true);
    NFA_set_accepting(nfa, 4, true);
    NFA_set_accepting(nfa, 6, true);
    NFA_set_accepting(nfa, 9, true);
    NFA_set_accepting(nfa, 12, true);
    NFA_set_accepting(nfa, 16, true);

    //sets transitions
    NFA_add_transition(nfa, 0, 'o', 1);
    NFA_add_transition(nfa, 1, 'o', 2);
    NFA_add_transition(nfa, 0, 'f', 3);
    NFA_add_transition(nfa, 3, 'f', 4);

    NFA_add_transition(nfa, 0, 'r', 5);
    NFA_add_transition(nfa, 5, 'r', 6);

    NFA_add_transition(nfa, 0, 'c', 7);
    NFA_add_transition(nfa, 7, 'c', 8);
    NFA_add_transition(nfa, 8, 'c', 9);

    NFA_add_transition(nfa, 0, 'n', 10);
    NFA_add_transition(nfa, 10, 'n', 11);
    NFA_add_transition(nfa, 11, 'n', 12);

    NFA_add_transition(nfa, 0, 'e', 13);
    NFA_add_transition(nfa, 13, 'e', 14);
    NFA_add_transition(nfa, 14, 'e', 15);
    NFA_add_transition(nfa, 15, 'e', 16);


    // we no longer have to define a transition from every state because we can now simply  return an empty state
    for (int i = 35; i < 127; i++)
    {
            NFA_add_transition(nfa, 0, (char)i, 0);
            NFA_add_transition(nfa, 1, (char)i, 1);
            NFA_add_transition(nfa, 3, (char)i, 3);
            NFA_add_transition(nfa, 5, (char)i, 5);
            NFA_add_transition(nfa, 7, (char)i, 7);
            NFA_add_transition(nfa, 8, (char)i, 8);
            NFA_add_transition(nfa, 10, (char)i, 10);
            NFA_add_transition(nfa, 11, (char)i, 11);
            NFA_add_transition(nfa, 13, (char)i, 13);
            NFA_add_transition(nfa, 14, (char)i, 14);
            NFA_add_transition(nfa, 15, (char)i, 15);

            NFA_add_transition(nfa, 2, (char)i, 2);
            NFA_add_transition(nfa, 4, (char)i, 4);
            NFA_add_transition(nfa, 6, (char)i, 6);
            NFA_add_transition(nfa, 9, (char)i, 9);
            NFA_add_transition(nfa, 12, (char)i, 12);
            NFA_add_transition(nfa, 16, (char)i, 16);



    }

    vec_int start_states = vector_create();
    vector_add(&start_states,0);
    bool result = NFA_Recursive_Execute(nfa, in, 0, start_states);
    return result;
    //NFA_Recursive_Execute(NFAS *nfa, char *input, int index, vec_int current_states)
    // printf("After careful examination, the given NFA is declared: %s\n", result ? "true" : "false");
    //DFA_free(dfa);
}
bool TestForNFAContaining_ath(char *in)
{
    printf("testing nfa that determines whether it contains within it _ath\n");

    NFAS *nfa = new_NFA(4);
    NFA_set_accepting(nfa, 3, true);
    NFA_set_accepting(nfa, 0, false);
    NFA_set_accepting(nfa, 1, false);
    NFA_set_accepting(nfa, 2, false);
    //sets transitions
    NFA_add_transition(nfa, 0, 'a', 1);
    NFA_add_transition(nfa, 0, 'a', 0);
    NFA_add_transition(nfa, 0, 't', 0);
    NFA_add_transition(nfa, 0, 'h', 0);


    NFA_add_transition(nfa, 1, 't', 2);



    NFA_add_transition(nfa, 2, 'h', 3);

    NFA_add_transition(nfa, 3, 'a', 3);
    NFA_add_transition(nfa, 3, 't', 3);
    NFA_add_transition(nfa, 3, 'h', 3);




    // we no longer have to define a transition from every state because we can now simply  return an empty state
    for (int i = 35; i < 127; i++)
    {

      //  if((char)i != 'a' && (char)i != 't' && (char)i != 'h')
        {

            NFA_add_transition(nfa, 0, (char)i, 0);
            NFA_add_transition(nfa, 3, (char)i, 3);
        }

    }

    vec_int start_states = vector_create();
    vector_add(&start_states,0);
    bool result = NFA_Recursive_Execute(nfa, in, 0, start_states);
    //NFA_Recursive_Execute(NFAS *nfa, char *input, int index, vec_int current_states)
 //   printf("After careful examination, the given NFA is declared: %s\n", result ? "true" : "false");
    return result;
 //   return *nfa;
    //DFA_free(dfa);
}

NFAS TestForNFAContaining_athReturnsNFA(char *in)
{
    printf("testing nfa that determines whether it contains within it _ath\n");

    NFAS *nfa = new_NFA(4);
    NFA_set_accepting(nfa, 3, true);
    NFA_set_accepting(nfa, 0, false);
    NFA_set_accepting(nfa, 1, false);
    NFA_set_accepting(nfa, 2, false);
    //sets transitions
    NFA_add_transition(nfa, 0, 'a', 1);
    NFA_add_transition(nfa, 0, 'a', 0);
    NFA_add_transition(nfa, 0, 't', 0);
    NFA_add_transition(nfa, 0, 'h', 0);


    NFA_add_transition(nfa, 1, 't', 2);



    NFA_add_transition(nfa, 2, 'h', 3);

    NFA_add_transition(nfa, 3, 'a', 3);
    NFA_add_transition(nfa, 3, 't', 3);
    NFA_add_transition(nfa, 3, 'h', 3);




    // we no longer have to define a transition from every state because we can now simply  return an empty state
    for (int i = 35; i < 127; i++)
    {

        //  if((char)i != 'a' && (char)i != 't' && (char)i != 'h')
        {

            NFA_add_transition(nfa, 0, (char)i, 0);
            NFA_add_transition(nfa, 3, (char)i, 3);
        }

    }

    vec_int start_states = vector_create();
    vector_add(&start_states,0);
    bool result = NFA_Recursive_Execute(nfa, in, 0, start_states);
    //NFA_Recursive_Execute(NFAS *nfa, char *input, int index, vec_int current_states)
    //   printf("After careful examination, the given NFA is declared: %s\n", result ? "true" : "false");
    return *nfa;
    //   return *nfa;
    //DFA_free(dfa);
}
bool TestForNFAEndingIn_ked(char *in)
{
    printf("testing nfa that recognizes strings ending in ked\n");

    NFAS *nfa = new_NFA(4);
    NFA_set_accepting(nfa, 3, true);
    NFA_set_accepting(nfa, 0, false);
    NFA_set_accepting(nfa, 1, false);
    NFA_set_accepting(nfa, 2, false);
    //sets transitions
    NFA_add_transition(nfa, 0, 'k', 1);
    NFA_add_transition(nfa, 0, 'k', 0);
    NFA_add_transition(nfa, 0, 'e', 0);
    NFA_add_transition(nfa, 0, 'd', 0);

    NFA_add_transition(nfa, 1, 'e', 2);



    NFA_add_transition(nfa, 2, 'd', 3);






 // we no longer have to define a transition from every state because we can now simply  return an empty state
    for (int i = 0; i < 128; i++)
    {
            NFA_add_transition(nfa, 0, (char)i, 0);
    }

    vec_int start_states = vector_create();
    vector_add(&start_states,0);
    bool result = NFA_Recursive_Execute(nfa, in, 0, start_states);
  //  printf("After careful examination, the given NFA is declared: %s\n", result ? "true" : "false");
    //DFA_free(dfa);
  return result;
   // return *nfa;
}
NFAS TestForNFAEndingIn_kedReturnsNFA(char *in)
{
    printf("testing nfa that recognizes strings ending in ked\n");

    NFAS *nfa = new_NFA(4);
    NFA_set_accepting(nfa, 3, true);
    NFA_set_accepting(nfa, 0, false);
    NFA_set_accepting(nfa, 1, false);
    NFA_set_accepting(nfa, 2, false);
    //sets transitions
    NFA_add_transition(nfa, 0, 'k', 1);
    NFA_add_transition(nfa, 0, 'k', 0);
    NFA_add_transition(nfa, 0, 'e', 0);
    NFA_add_transition(nfa, 0, 'd', 0);

    NFA_add_transition(nfa, 1, 'e', 2);



    NFA_add_transition(nfa, 2, 'd', 3);






    // we no longer have to define a transition from every state because we can now simply  return an empty state
    for (int i = 0; i < 128; i++)
    {
        NFA_add_transition(nfa, 0, (char)i, 0);
    }

    vec_int start_states = vector_create();
    vector_add(&start_states,0);
    bool result = NFA_Recursive_Execute(nfa, in, 0, start_states);
    //  printf("After careful examination, the given NFA is declared: %s\n", result ? "true" : "false");
    //DFA_free(dfa);
    // return result;
     return *nfa;
}



// given an nfa, get all subsets of all states
vec_int* subset_Constructor(NFAS nfa) {
    //  printf("%d", *nfa.num_states);
    vec_int *subsets = vector_create();
    vec_int set = vector_create();
    for (int i = 0; i < *nfa.num_states; i++) {
        vector_add(&set, i);
    }
    for (int i = 0; i < *nfa.num_states; i++) {
        //      printf("teez");
    }
    unsigned int pow_set_size = pow(2, *nfa.num_states);
    int counter, j;

    /*Run from counter 000..0 to 111..1*/
    for (counter = 0; counter < pow_set_size; counter++) {
        vec_int v = vector_create();

        for (j = 0; j < *nfa.num_states; j++) {
            /* Check if jth bit in the counter is set
               If set then print jth element from set */
            if (counter & (1 << j)) {
                //   printf("%d", set[j]);
                vector_add(&v, set[j]);

            }
        }

        vector_add(&subsets, v);

    }


//
//    for (int i = 0; i < vector_size(subsets); i++) {
//        for (int j = 0; j < vector_size(subsets[i]); j++) {
//            printf("%d ", subsets[i][j]);
//        }
//        printf("\n");
//
//    }

    return subsets;
}

int compare1 (const void *a, const void *b)
{
    const int *ia = (const int *)a; // casting pointer types
    const int *ib = (const int *)b;
    return *ia  - *ib;
}
// returns the number of the state
int get_state_num(vec_int state, vec_int* subsets)
{
    for (int i = 0; i < vector_size(subsets); i++)
    {

        if(vector_size(subsets[i]) == vector_size(state))
        {
            qsort(subsets[i], vector_size(subsets[i]), sizeof(int), compare1);
            qsort(state, vector_size(state), sizeof(int), compare1);
            bool match = true;
            for (int j = 0; j < vector_size(subsets[i]); j++)
            {
                if(subsets[i][j] != state[j])
                    match = false;
            }
            if (match)
                return i;
        }
    }
}

// returns the state
// goes over all newly creates subsets and and goes over each element in them, and then uses get nfa plugging in that element as set, and for every input
// gets the result out of that stores it in a new vec
// then unions all those together

// symbols take in all symbols in the table, not the symbols of the test word
// takes in nfa produces dfa
// might fail if subset constructor does not produce empty set as a state
DFAS* NFAtoDFA(NFAS *nfa, char *symbols)
{

    vec_int* subsets = subset_Constructor(*nfa);
    DFAS *dfa = new_DFA(vector_size(subsets));
    for (int i = 0; i < vector_size(subsets); i++) {
        for (int k = 0; k < 3; k++) {

        //    vec_int new_trans = vector_create();

            for (int j = 0; j < vector_size(subsets[i]); j++) {

                vec_int new_trans = vector_create();
                new_trans = vec_union(new_trans, NFA_get_transitions(nfa, subsets[i][j], symbols[k]));



                DFA_set_accepting(dfa, i, false);
                if(NFA_get_accepting(nfa,subsets[i][j]))
                    DFA_set_accepting(dfa, i, true);
                DFA_set_transition(dfa,i, symbols[k],get_state_num(new_trans, subsets));
            }
           // DFA_set_transition(dfa,i, symbols[k],get_state_num(new_trans, subsets));



        }
    }

    return dfa;
}

void nfaANDdfa()
{
    while (1) {

        printf("Test 1: DFA with exactly string DFA\n");
        printf("Test 2: DFA Starting in sequence cat\n");
        printf("Test 3: DFA with string containing exactly two 2s\n");
        printf("Test 4: DFA with Binary input where there are an even number of 0s and an odd number of 1s\n");
        printf("Test 5: NFA ending in ked\n");
        printf("Test 6: NFA with strings containing ath \n");
        printf("Test 7: NFA with strings that are not anagrams of conference\n");
        printf("Choose a test from 1 to 7 or enter quit to quit: ");
        char choice[10];
        scanf("%s", choice);

        int i = 0;
        while (choice[i] != '\0' && "quit"[i] != '\0') {
            if (choice[i] != "quit"[i]) {
                break;
            }
            i++;
        }

        if (choice[i] == '\0' && "quit"[i] == '\0') {
            break;
        }
        int testIndex = atoi(choice);
        bool (*testFunc)(char*);

        switch (testIndex) {
            case 1:
                testFunc = TestForDfaWithExactly_dfa;
                //printf("Testing for dfa that accepts sentence starting in cat\n");
                break;
            case 2:
                testFunc = TestForDfaStartWith_cat;
                break;
            case 3:
                testFunc = TestForStringWithExactlyTwo2s;
                break;
            case 4:
                testFunc = TestForBinaryInputEvenZeroOddOne;
                break;
            case 5:
                testFunc = TestForNFAEndingIn_ked;
                break;
            case 6:
                testFunc = TestForNFAContaining_ath;
                break;
            case 7:
                testFunc = TestForPartialAnagramOfConference;
                break;
            default:
                printf("Invalid test number. Please try again.\n");
                continue;
        }

        while (1) {
            printf("Enter an input or enter quit to choose another test: ");
            char input[100];
            scanf("%s", input);

            i = 0;
            while (input[i] != '\0' && "quit"[i] != '\0') {
                if (input[i] != "quit"[i]) {
                    break;
                }
                i++;
            }

            if (input[i] == '\0' && "quit"[i] == '\0') {
                break;
            }


            bool result = testFunc(input);

            printf("The result for input: %s is: %s\n", input, result ? "true" : "false");

        }





    }

}
void nfatodfa()
{
    printf("This test is for Part 3");
    printf("choose between running test 1 (strings ending in ked) or running test2 (strings containing ath\n");
//
//    int choice;
//    scanf(" %d", &choice);  // The space before %c is to skip any whitespace characters
//
//    switch(choice) {
//        case 1:
//            x
//            break;
//        case 2:
//            y
//            break;
//        default:
//            printf("Invalid choice. Please choose either 1 or 2.\n");
//    }
    int choice;
    char input[100];

    do {
        printf("Please choose between two choices 1 and 2: ");
        scanf("%d", &choice);

        printf("Please enter your input (or type 'quit' to exit): ");
        scanf("%s", input);

        int i = 0;
        while (input[i] != '\0' && "quit"[i] != '\0') {
            if (input[i] != "quit"[i]) {
                break;
            }
            i++;
        }

        switch(choice) {
            case 1:
                printf("Testing dfa obtained from nfa");
                NFAS nfa2 = TestForNFAEndingIn_kedReturnsNFA(input);
                DFAS* dfa2 = NFAtoDFA(&nfa2,"ked");
                bool test2 = DFA_execute(dfa2,input, 0);
                printf("the number of states of the newly created dfa is ");
                printf("%d", *dfa2->num_states);
                printf("\nThe result for input: %s is: %s\n", input, test2 ? "true" : "false");

                break;
            case 2:
                printf("Testing dfa obtained from nfa");
                NFAS nfa1 = TestForNFAContaining_athReturnsNFA(input);
                DFAS* dfa1 = NFAtoDFA(&nfa1,"ath");
                bool test1 = DFA_execute(dfa1,input, 0);
                printf("the number of states of the newly created dfa is ");
                printf("%d", *dfa1->num_states);
                printf("\nThe result for input: %s is: %s\n", input, test1 ? "true" : "false");
                break;
            default:
                printf("Invalid choice. Please choose either 1 or 2.\n");
        }
    }while (true);




}
int main() {


    char choice;

    printf("Please choose between two choices A for part 1 or part 2 and B for part 3: ");
    scanf(" %c", &choice);  // The space before %c is to skip any whitespace characters

    switch(choice) {
        case 'A':
        case 'a':
            nfaANDdfa();
            break;
        case 'B':
        case 'b':
            nfatodfa();
            break;
        default:
            printf("Invalid choice. Please choose either A or B.\n");
    }

    return 0;


}




