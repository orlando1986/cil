
int buffer[50];
int *buffp, *buffa, *buffb;
int separator(int);
int bar(int);

int foo(void) {
  // Both MSVC and GCC do the ++ after the assignment !
  *buffp = buffer[(*buffa) ++];
  separator(1);
  // Both MSVC and GCC do the ++ before the call to bar !
  // buffb is incremented first in both compilers
  *buffp = bar(buffer[(*buffa) ++] + buffer[(*buffb) ++]);
  separator(2);
  // The +7 must be done before the assignment
  *buffp = buffer[(*buffa) += 7];
  separator(3);
  bar((*buffa) ++) + bar((*buffb) ++);
  return *buffp;
}
