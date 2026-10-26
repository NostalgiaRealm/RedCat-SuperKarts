/*
 * FUN_00473400 at 00473400
 * undefined FUN_00473400(void)
 * Address ranges: 00473400-00473444
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00473400(void)

{
  char cVar1;
  
  if (DAT_00544d9c != 0) {
    cVar1 = *(char *)(DAT_00544d9c + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(DAT_00544d9c + -1);
    }
    else {
      *(char *)(DAT_00544d9c + -1) = cVar1 + -1;
    }
  }
  DAT_00544d9c = 0;
  _DAT_00544da0 = 0;
  DAT_00544da4 = 0;
  return;
}

