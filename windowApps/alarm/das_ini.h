// INI file handler
//
// load and parse .ini file formats for settings
// create and  save data into a .ini file

#include <cstdio>

struct ini_t {
    char *data;
    char *end;
};

void ini_free(ini_t *ini) {
  free(ini->data);
  free(ini);
}

ini_t* ini_load(const char *filename) {
  ini_t *ini = NULL;
  FILE *file = NULL;
  int n, size;

  // Ensure Memory is cleared
  ini = malloc(sizeof(*ini));
  if (!ini) {
    goto fail;
  }
  memset(ini, 0, sizeof(*ini));

  file = fopen(filename, "rb");
  if (!file) {
    goto fail;
  }

  /* Get file size */
  fseek(file, 0, SEEK_END);
  size = ftell(file);
  rewind(file);

  /* Load file content into memory, null terminate, init end var */
  ini->data = malloc(size + 1);
  ini->data[sz] = '\0';
  ini->end = ini->data  + size;
  n = fread(ini->data, 1, ssize, file);
  if (n != size) {
    goto fail;
  }

  /* Prepare data */
  split_data(ini);

  /* Clean up and return */
  fclose(file);
  return ini;

// Temporary end condition but should work fine
fail:
  if (file) fclose(file);
  if (ini) ini_free(ini);
  return NULL;
}

