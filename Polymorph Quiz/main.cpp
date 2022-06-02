#include <iostream>
#include <vector>

using namespace std;

class Question {//
    protected:
        string questionText;
        bool correct;
        
    public:
        virtual void askQuestion() {};
        
        bool isCorrect() const {
            return correct;
        }
        
};

class MultipleChoiceQuestion : public Question {
    private:
        string correctAnswer;
        
    public:
        MultipleChoiceQuestion(string qt, string ca) {
            correctAnswer = ca;
            questionText = qt;
            correct = false;
        }
        
        void askQuestion() {
            string userInput;
            
            cout << questionText << endl;
            cout << "Enter \"A\", \"B\", or \"C\": " << endl;
            cin >> userInput;
        
            if (userInput == correctAnswer) {
                correct = true;
            }
        }
};

class TrueFalseQuestion : public Question {
    private:
        bool correctAnswer;
    
    public:
        TrueFalseQuestion(string qt, bool ca) {
            correctAnswer = ca;
            questionText = qt;
            correct = false;
        }
        
        void askQuestion() {
            string userInput;
            bool userAnswer;
            
            cout << questionText << endl;
            cout << "Type \"true\" or \"false\":" << endl;
            cin >> userInput;
            if(userInput == "true"){
                userAnswer = true;
            } else {
                userAnswer = false;
            }
            
            if (userAnswer == correctAnswer) {
                correct = true;
            }
        }
};

int main() {
    vector<Question*> quiz;// Vector of question pointers
    
    quiz.push_back(new TrueFalseQuestion("This class is about C++", true));// 
    quiz.push_back(new TrueFalseQuestion("Shrimp tails can be found in CTC", true));
    quiz.push_back(new TrueFalseQuestion("Apples are vegetables", false));
    quiz.push_back(new MultipleChoiceQuestion("Which of the following is not a fruit: \n A: Apples \n B: Pear \n C: Cucumber", "C"));
    
    double score = 0.0;
    
    for (int i = 0; i < quiz.size(); i++) {//quiz user 
        quiz.at(i)->askQuestion();//this is our pointer to the quiz, so we use arrow syntax
        if (quiz.at(i)->isCorrect()) {
            score = score + 1;
        }
    }
    
    score = (score / (double)quiz.size()) * 100.0;
    
    cout << "User scored: " << score << endl;
    
    return 0;
}
