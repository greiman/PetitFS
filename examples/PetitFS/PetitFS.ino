// Petit FS test.   

#include "PetitFS.h"

// The SD chip select pin is currently defined as 10
// in pffArduino.h.  Edit pffArduino.h to change the CS pin.

FATFS fs;     /* File system object */
//------------------------------------------------------------------------------
void errorHalt(char* msg) {
  Serial.print("Error: ");
  Serial.println(msg);
  while(1);
}
//------------------------------------------------------------------------------
void test() {
  uint8_t buf[32];
  
  // Initialize SD and file system.
  if (pf_mount(&fs)) errorHalt("pf_mount ");
  
  // Open test file.
  if (pf_open("TEST.TXT")) errorHalt("pf_open ");
  
  // Dump test file to Serial.
  while (1) {
    UINT nr;
    if (pf_read(buf, sizeof(buf), &nr)) errorHalt("pf_read");
    if (nr == 0) break;
    Serial.write(buf, nr);
  }
}
//------------------------------------------------------------------------------
void setup() {
  Serial.begin(9600);
  test();
  Serial.println("\nDone!");
}
void loop() {}