#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096 // 4kb chunk

int main(int argc, char *argv[]) {
  // 1. validate cli arguments
  if (argc != 3) {
    fprintf(stderr, "usage: %s <source_file> <destination_file>\n", argv[0]);
    return 1;
  }

  const char *src_path = argv[1];
  const char *dst_path = argv[2];

  // 2. open source file for reading in binary mode
  FILE *src = fopen(src_path, "rb");
  if (src == NULL) {
    perror("error opening source file");
    return 1;
  }

  // 3. open / create destination_file for writing in binary mode
  FILE *dst = fopen(dst_path, "wb");
  if (dst == NULL) {
    perror("error opening destination_file");
    fclose(src);
    return 1;
  }

  // 4 copy in 4kb chunks until eof
  unsigned char buffer[BUFFER_SIZE];
  size_t bytes_read;

  while ((bytes_read = fread(buffer, 1, sizeof(buffer), src)) > 0) {
    size_t bytes_written = fwrite(buffer, 1, bytes_read, dst);
    if (bytes_written != bytes_read) {
      perror("error writing to destination_file");
      fclose(src);
      fclose(dst);
      return 1;
    }
  }

  // 5 check if the lop stopped due to disk read error rather than normal eof
  if (ferror(src)) {
    perror("error reading source file");
    fclose(src);
    fclose(dst);
    return 1;
  }

  // 6 close both file handles
  fclose(src);
  fclose(dst);

  printf("copied '%s' ->'%s' successfully \n", src_path, dst_path);
  return 0;
}
