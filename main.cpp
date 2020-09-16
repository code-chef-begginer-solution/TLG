#include <bits/stdc++.h>

/* a function to obtain the absolute value of a number */
template <typename T>
size_t absolute_value(T number) {
    return (number >= 0)? number: -number;
}

int main(int argc, char* argv[]) {
    
    /* fast input-output */
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    /* get the total_round in the game */
    size_t total_round;
    std::cin >> total_round;

    /* define first_score and second_score corresponding to scores
     * earned by the first_player and second_player in each round */
    size_t first_score{0}, second_score{0};

    /* initialize cumulative score of first_player and second_player */
    size_t first_cumulative{0}, second_cumulative{0};

    const size_t first_player{1}, second_player{2};
    size_t maximum_lead{0}, winner{0};

    /* process the score obtained
     * in each round of the game */
    while (total_round--) {

        /* get the first_score and second_score corresponding to
         * the scores of first and second player respectively */
        std::cin >> first_score;
        std::cin >> second_score;

        /* obtain cumulative score of first
         * and second player respectively */
        first_cumulative += first_score;
        second_cumulative += second_score;

        /* get the current lead value */
        ssize_t difference_of_score=first_cumulative-second_cumulative;
        size_t current_lead={absolute_value(difference_of_score)};
        
        /* if first player is leading and have greater
         * leading score than maximum obtained lead */
        if (current_lead > maximum_lead) {
            maximum_lead = current_lead;

            /* compute winner based on cumulative scores pf first_player and
             * second_player after completion of current round in the game */
            if (first_cumulative > second_cumulative) {
                winner = first_player;
            } else {
                winner = second_player;
            }
        }
    }

    /* print the winner and maximum lead obtained */
    std::cout << winner << " " << maximum_lead << std::endl;

    return 0;
}