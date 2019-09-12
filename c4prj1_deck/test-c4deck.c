#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cards.h"
#include "deck.h"
#include "eval.h"

int main(int argc, char ** argv) {
  deck_t * deck = malloc(sizeof(*deck));
  deck->n_cards = 0;
  deck->cards = malloc(sizeof(*deck->cards));
  for (unsigned i = 6; i < 13; i++) {
    card_t c = card_from_num(i);
    print_card(c);
    printf("\t");
    add_card_to(deck, c);
    deck->cards[deck->n_cards-1]->value = c.value;
    deck->cards[deck->n_cards-1]->suit = c.suit;
  }
  printf("\n");
  print_hand(deck);
  free_deck(deck);
  return EXIT_SUCCESS;
}
