#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(2 <= c.value && c.value <= 14);
  assert(SPADES <= c.suit && c.suit < NUM_SUITS);
}

const char * ranking_to_string(hand_ranking_t r) {
  switch (r) {
  case STRAIGHT_FLUSH: return "STRAIGHT_FLUSH"; break;
  case FOUR_OF_A_KIND: return "FOUR_OF_A_KIND"; break;
  case FULL_HOUSE: return "FULL_HOUSE"; break;
  case FLUSH: return "FLUSH"; break;
  case STRAIGHT: return "STRAIGHT"; break;
  case THREE_OF_A_KIND: return "THREE_OF_A_KIND"; break;
  case TWO_PAIR: return "TWO_PAIR"; break;
  case PAIR: return "PAIR"; break;
  case NOTHING: return "NOTHING"; break;
  }
  return "";
}

char value_letter(card_t c) {
  if (2 <= c.value && c.value <= 9){
    return '0' + c.value;
  }
  else{
  switch (c.value) {
  case 10: return '0'; break;
  case VALUE_JACK: return 'J'; break;
  case VALUE_QUEEN: return 'Q'; break;
  case VALUE_KING: return 'K'; break;
  case VALUE_ACE: return 'A'; break;
  default: break;
    }
  }
  return 'x';
}


char suit_letter(card_t c) {
  switch (c.suit) {
  case SPADES: return 's'; break;
  case HEARTS: return 'h'; break;
  case DIAMONDS: return 'd'; break;
  case CLUBS: return 'c'; break;
  default: break;
  }
  return 'x';
}

void print_card(card_t c) {
  printf("%c%c", value_letter(c), suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp;
  
  int valueR1 = (value_let >= '0' + 2 && value_let <= '0' + 9);
  int valueR2 = (value_let == '0' ||  value_let == 'J' || value_let == 'Q' || value_let == 'K' || value_let == 'A');
  int valueR3 = (value_let != '0' + 1);
  assert ( (valueR1 && valueR3) || valueR2 );
  assert ( suit_let == 's' || suit_let == 'h' || suit_let == 'd' || suit_let == 'c');

  if (value_let >= '0' + 2 && value_let <= '0' + 9) {
    temp.value = value_let - '0'; 
  } else {
    switch(value_let){
    case '0': temp.value = 10; break;
    case 'J': temp.value = 11; break;
    case 'Q': temp.value = 12; break;
    case 'K': temp.value = 13; break;
    case 'A': temp.value = 14; break;
    default: break;
    }
  }

  switch (suit_let) {
  case 's': temp.suit = SPADES; break;
  case 'h': temp.suit = HEARTS; break;
  case 'd': temp.suit = DIAMONDS; break;
  case 'c': temp.suit = CLUBS; break;
  default: break;
  }
 
  return temp;
}

card_t card_from_num(unsigned c) {
  card_t temp;
  assert(c < 52);
  temp.value = c % 13 + 2;
  temp.suit =  c % 4;
  return temp;
}
