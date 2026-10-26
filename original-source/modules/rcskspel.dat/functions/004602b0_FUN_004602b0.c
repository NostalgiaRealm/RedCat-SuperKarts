/*
 * FUN_004602b0 at 004602b0
 * undefined FUN_004602b0(void)
 * Address ranges: 004602b0-004602f3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004602b0(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = param_1[3];
  if (iVar2 != 0) {
    cVar1 = *(char *)(iVar2 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150((char *)(iVar2 + -1));
    }
    else {
      *(char *)(iVar2 + -1) = cVar1 + -1;
    }
  }
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  *param_1 = &PTR_FUN_004d28c0;
  return;
}

