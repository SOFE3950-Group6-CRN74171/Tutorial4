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
#include "questions.h"

// Array of Questions
question questions[NUM_QUESTIONS] = {
    {"Science", "It's the two gases that make up the majority of Earth's atmosphere.", "What are Nitrogen and Oxygen?", 100, false},
    {"Geography", "This mountain range holds the title for the longest in the world.", "What are the Andes?", 100, false},
    {"History", "This ancient civilization constructed the Great Pyramids of Giza.", "Who were the Ancient Egyptians?", 100, false},
    
    {"Science", "Plants use this process to make their own food.", "What is Photosynthesis?", 200, false},
    {"Geography", "Name the country that is both an island and a continent.", "What is Australia?", 200, false},
    {"History", "She was the first female Prime Minister of the United Kingdom.", "Who was Margaret Thatcher?", 200, false},
    
    {"Science", "This is the smallest bone found in the human body.", "What is the Stapes (in the ear)?", 300, false},
    {"Geography", "Identify the largest ocean by surface area.", "What is the Pacific Ocean?", 300, false},
    {"History", "This British monarch holds the record for the longest reign.", "Who was Queen Victoria?", 300, false},
    
    {"Science", "The process by which liquid water turns into water vapor.", "What is Evaporation?", 400, false},
    {"Geography", "Name the capital city of Brazil.", "What is Brasília?", 400, false},
    {"History", "He led the first expedition to successfully circumnavigate the globe.", "Who was Ferdinand Magellan?", 400, false},
    
    {"Science", "This scientific field studies fossils.", "What is Paleontology?", 500, false},
    {"Geography", "Identify the sea that doesn't have any coastlines.", "What is the Sargasso Sea?", 500, false},
    {"History", "This global conflict lasted from 1939 to 1945.", "What is World War II?", 500, false},
};

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void){
    printf("\t| Science   |   Geography   |   History |\n");
    for(int i=0; i <NUM_QUESTIONS; i++){
        if((questions[i].answered == false)){
            printf("\t   %i\t", questions[i].value);
        }
        else {
            printf("\t   ---\t");
        }
        if ((i+1) % 3==0) {
            printf("\n");
        }
    }
}

// Displays the question for the category and dollar value
void display_question(char *category, int value){
    for(int i=0; i < NUM_QUESTIONS; i++){
        if(strcmp(questions[i].category, category) == 0 && questions[i].value == value){
            printf("%s\n", questions[i].question);
        }
    }
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer){
    // Look into string comparison functions
    for(int i=0; i < NUM_QUESTIONS; i++){
        if(strcmp(questions[i].category, category) == 0 && questions[i].value == value){
            if(strcmp(questions[i].answer, answer) == 0){
                return true;
            }
        }
    }
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value){
    // lookup the question and see if it's already been marked as answered
    for(int i=0; i < NUM_QUESTIONS; i++){
        if(strcmp(questions[i].category, category) == 0 && questions[i].value == value){
            return questions[i].answered;
        }
    }
    
    return true;
}

bool remove_question(char *category, int value){
    for(int i=0; i < NUM_QUESTIONS; i++){
        if(strcmp(questions[i].category, category) == 0 && questions[i].value == value){
            questions[i].answered = true;
            break;
        }
    }
}

bool check_if_finished(){
    for(int i=0; i < NUM_QUESTIONS; i++){
        if(questions[i].answered == false){
            return false;
        }
    }
    return true;
}
