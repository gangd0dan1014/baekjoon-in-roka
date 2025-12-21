#define MAX 501
#define COL_NUM 5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char alpha;
  int number;
} ticket;

ticket stack[MAX];
ticket wating[MAX];
ticket sorted[MAX];
int top = -1;

ticket parsing_ticket_info(char *ticket_info) {
  ticket info;
  info.alpha = ticket_info[0];

  switch (strlen(ticket_info)) {
  case 3:
    info.number = ticket_info[2] - '0';
    break;
  case 4:
    info.number = (ticket_info[2] - '0') * 10 + (ticket_info[3] - '0');
    break;
  case 5:
    info.number = (ticket_info[2] - '0') * 100 +
                  (ticket_info[3] - '0') * 10 +
                  (ticket_info[4] - '0');
    break;
  }
  return info;
}

int compare(const void* a, const void* b) {
  ticket* t1 = (ticket*)a;
  ticket* t2 = (ticket*)b;

  if (t1->alpha != t2->alpha) {
    return t1->alpha - t2->alpha;
  }

  return t1->number - t2->number;
}

void push(ticket t) {
  stack[++top] = t;
}

ticket pop() {
  return stack[top--];
}

int same_check(ticket a, ticket b) {
  if ((a.alpha == b.alpha) && (a.number == b.number)) {
    return 1;
  }
  return 0;
}

int main() {
  int line_count, people_count = 0, finish = 0, idx = 0;
  char ticket_info[6];

  scanf("%d", &line_count);

  for (int i = 0; i < line_count; i++) {
    for (int j = 0; j < COL_NUM; j++) {
      scanf("%s", ticket_info);
      wating[people_count] = parsing_ticket_info(ticket_info);
      sorted[people_count++] = parsing_ticket_info(ticket_info);
    }
  }

  qsort(sorted, people_count, sizeof(ticket), compare);

  for (int i = 0; i < people_count; i++) {

    while(top != -1 && same_check(stack[top], sorted[idx])) {
      pop();
      idx++;
    }
    
    if (same_check(wating[i], sorted[idx])) {
      idx++;
    }
    else {
      push(wating[i]);
    }
  }

  while (top != -1 && same_check(stack[top], sorted[idx])) {
    pop();
    idx++;
  }

  if (idx == people_count) {
    printf("GOOD");
  }
  else {
    printf("BAD");
  }
}
