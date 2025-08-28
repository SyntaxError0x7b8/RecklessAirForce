//
// Created by qos on 8/26/25.
//



int raflib();
int all_tests();

bool EXECUTE_TESTS {true};

int main() {
  if (EXECUTE_TESTS) {
    all_tests();
  }

  raflib();

  return 0;
}

