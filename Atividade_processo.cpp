#include <iostream>
#include <math.h>
#include <stdio.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

using namespace std;

int main() {
  int i = 0;
  pid_t pid;
  int filho1, filho2, neto1, neto2, pai;
  string morreu;

  while (i <= 60) {
    if (i == 0) {
      pid = fork();
      if (pid == 0) {
        pai = getpid();
        cout << ("pid do pai: ") << getpid() << endl;
      }
    }
    if (i == 14) {

      if (getpid() == pai) {
        pid = fork();
        if (pid == 0) {

          filho1 = getpid();
          cout << ("pid do filho 1: ") << getpid() << " Pai: " << pai << endl;
        }
      }
    }

    if (i == 16) {
      if (getpid() == pai) {
        pid = fork();
        if (pid == 0) {

          filho2 = getpid();
          cout << ("pid do filho 2: ") << getpid() << " Pai: " << pai << endl;
        }
      }
    }

    if (i == 24) {
      if (getpid() == filho1) {
        pid = fork();
        if (pid == 0) {

          neto1 = getpid();
          cout << ("pid do neto: ") << getpid() << " Pai: " << filho1
               << " Avô: " << pai << endl;
        }
      }
    }

    if (i == 26) {
      if (getpid() == filho2) {
        pid = fork();
        if (pid == 0) {

          neto2 = getpid();
          cout << ("pid do neto 2: ") << getpid() << " Pai: " << filho2
               << " Avô: " << pai << endl;
        }
      }
    }
    if (i == 44) {
      if (getpid() == filho1) {
        cout << ("Filho 1 morreu: ") << filho1 << endl;
        morreu = "kill -9 " + to_string(filho1);
      }
    }
    if (i == 46) {
      if (getpid() == filho2) {
        cout << ("Filho 2 morreu: ") << filho2 << endl;
        morreu = "kill -9 " + to_string(filho2);
      }
    }

    if (i == 46) {
      if (getpid() == neto1) {
        cout << ("Neto 1 morreu: ") << neto1 << endl;
        morreu = "kill -9 " + to_string(neto1);
      }
    }
    if (i == 48) {
      if (getpid() == neto2) {
        cout << ("Neto 2 morreu: ") << neto2 << endl;
        morreu = "kill -9 " + to_string(neto2);
      }
    }
    if (i == 60) {
      if (getpid() == pai) {
        cout << ("O pai morreu: ") << pai << endl;
        morreu = "kill -9 " + to_string(pai);
      }
    }
    sleep(1);
    i++;
  }
}

