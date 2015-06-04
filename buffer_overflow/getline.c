char *getline() {
  char buf[8];
  char *result;
  gets(buf);
  result = malloc(strlen(buf));
  strcpy(result, buf);
  return result;
}

int main(void) {
  puts("Please enter your string: ");
  char *s = getline();
}
