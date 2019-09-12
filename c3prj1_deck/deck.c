#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"


void print_hand(deck_t * hand){
  for (int i = 0; i < hand -> n_cards; i++){
    card_t **temp_cards = hand -> cards;
    card_t *temp_card = temp_cards[i];
    print_card(*temp_card);
    printf(" ");
  }
}

int deck_contains(deck_t * d, card_t c) {
  for (int i = 0; i < d -> n_cards; i++){ 
    card_t **temp_cards = d -> cards;
    card_t *temp_card = temp_cards[i];
    
    if ( temp_card -> value == c.value && temp_card -> suit == c.suit ){
      return 1;
    }
  }
  return 0;
}

void shuffle(deck_t * d){
  /* for (size_t i = 0; i < d -> n_cards; i++){ */
  /*   card_t **temp_cards = d -> cards; */
  /*   card_t *temp_card_i = temp_cards[i]; */

  /*   size_t j = rand () % (d -> n_cards - 1);  */
  /*   card_t *temp_card_j = temp_cards[j]; */

  /*   card_t temp = *temp_card_i;  */
  /*   *temp_card_i = *temp_card_j;  */
  /*   *temp_card_j = temp; */
  /* } */

  card_t ** card =d -> cards ;
  card_t * temp;
  size_t n=d ->n_cards;
  int randarry;
  for (size_t i=0 ;i< n/2 ;i++){
    randarry= random()%(n-i)+i;
    temp=card[i];
    card[i]=card[randarry];
    card[randarry]=temp;
  }  
}

void assert_full_deck(deck_t * d) {
  card_t **currentCards = d -> cards;
 
  for (size_t i = 0; i < d -> n_cards; i++){
    card_t *currentCard = currentCards[i]; 
    assert(deck_contains(d, *currentCard));
  }
}

void add_card_to(deck_t * deck, card_t c) {
  deck->n_cards++;
  deck->cards = realloc(deck->cards, deck->n_cards * sizeof(*deck->cards));
  deck->cards[deck->n_cards - 1] = malloc(sizeof(*deck->cards[deck->n_cards - 1]));
  *deck->cards[deck->n_cards - 1] = c;
}

card_t * add_empty_card(deck_t * deck) {
  card_t c;
  c.value = 0;
  c.suit = 0;
  add_card_to(deck, c);
  return deck->cards[deck->n_cards - 1];
}

deck_t * make_deck_exclude(deck_t * excluded_cards) {
  deck_t *d = malloc(sizeof(*d));
  d->cards = malloc(sizeof(*d->cards));
  d->n_cards = 0;
  for (int i = 0; i < 52; i++) {
    card_t c = card_from_num(i);
    if (!deck_contains(excluded_cards, c)) {
      add_card_to(d, c);
    }
  }
  return d;
}

deck_t * build_remaining_deck(deck_t ** hands, size_t n_hands) {
  deck_t *d = malloc(sizeof(*d));
  d->cards =  malloc(sizeof(*d->cards));
  d->n_cards = 0;
  for (size_t i = 0; i < n_hands; i++) {
    for ( size_t j = 0; j < hands[i]->n_cards; j++) {
      add_card_to(d, *hands[i]->cards[j]);
    }
  }
 
  deck_t *deck = make_deck_exclude(d);
  free_deck(d);
  return deck;
}

void free_deck(deck_t * deck) {
  for (size_t i = 0; i < deck->n_cards; i++) {
    free(deck->cards[i]);
  }
  free(deck->cards);
  free(deck);
}
