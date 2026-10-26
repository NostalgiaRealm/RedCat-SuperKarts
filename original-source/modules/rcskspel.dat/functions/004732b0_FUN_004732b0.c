/*
 * FUN_004732b0 at 004732b0
 * undefined FUN_004732b0(void)
 * Address ranges: 004732b0-004732f4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004732b0(void)

{
  char cVar1;
  
  if (DAT_00544dac != 0) {
    cVar1 = *(char *)(DAT_00544dac + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(DAT_00544dac + -1);
    }
    else {
      *(char *)(DAT_00544dac + -1) = cVar1 + -1;
    }
  }
  DAT_00544dac = 0;
  _DAT_00544db0 = 0;
  DAT_00544db4 = 0;
  return;
}

