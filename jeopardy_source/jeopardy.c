/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <Mostafa Abedi, Nathaniel Manoj, Calvin Reveredo>
 * All rights reserved.
 *
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

#define BUFFER_LEN 256

// Function to tokenize the input string and extract tokens
void tokenize(char *input, char tokens[4][BUFFER_LEN]);

// Function to display the final results of the game
void show_results(player *players);

// Function to run the main game loop
void run_game(char tokens[4][BUFFER_LEN], player *players);

int main(void) {
    // Array to hold player information
    player players[4];
    
    // Input buffer
    char buffer[BUFFER_LEN];

    // Display game introduction and prompt for player names
    printf("Welcome to Jeopardy! Please Enter your Names:\n");
    for(int i = 0; i < 4; i++) {
        scanf("%s", players[i].name);
    }
    printf("Thank you.\n");

    // Tokens array to hold tokenized input
    char token[4][BUFFER_LEN] = {{0}};

    // Initialize the game and run the main game loop
    initialize_game();
    run_game(token, players);

    return 0;
}

// Function to display the final results of the game
void show_results(player *players) {
    // Loop through each player and display their name and score
    for(int i = 0; i < 4; i++) {
        printf("Name: %s\tScore:%d\n", players[i].name, players[i].score);
    }
}

// Function to tokenize the input string and extract tokens
void tokenize(char *input, char tokens[4][BUFFER_LEN]) {
    // Tokenize the input string based on spaces
    char *token1 = strtok(input, " ");

    // Loop through each token and copy it to the tokens array
    for(int i = 0; token1 != NULL; i++) {
        strcpy(tokens[i], token1);
        token1 = strtok(NULL, " ");
    }       
}

// Function to run the main game loop
void run_game(char tokens[4][BUFFER_LEN], player *players) {
    // Calculate the total number of questions
    int questions_remaining = sizeof(questions) / sizeof(questions[0]);
    bool correct;
    char category[BUFFER_LEN];
    int value;
    char response[BUFFER_LEN] = {0};

    // Main game loop
    while(questions_remaining > 0) {
        // Loop through each player for their turn
        for(int i = 0; i < 4; i++) {
            // Prompt the player to choose a question category and value
            printf("%s's Turn\nPlease choose from the following questions\n(hint: first enter category and hit enter, then enter the dollar amount and hit enter):\n\n", players[i].name);
            display_categories();
            printf("\n\n");
            scanf("%s", category);
            scanf("%d", &value);
            printf("\n");
            
            // Check if the question has already been answered
            if(already_answered(category, value)) {
                printf("Question has already been answered. Please choose another");
                i--;
            }
            else {
                // Display the selected question and get the player's response
                display_question(category, value);
                scanf("%s", response);                                  
                tokenize(response, tokens);                               
                correct = valid_answer(category, value, tokens[2]);
                if(correct) {
                    printf("Correct! You may now choose another question.\n\n");
                    players[i].score += value;
                    i--;
                }
                else {
                    printf("Unfortunately, that is incorrect, or you forgot to say \"What is/Who is\".\n\n");
                }
                // Mark the question as answered and update remaining questions count
                question_answered(category, value);
                questions_remaining--;
                if(questions_remaining <= 0) {
                    break;
                }
            }                
        }
    }
    
    // Display the final results of the game
    show_results(players);
}
