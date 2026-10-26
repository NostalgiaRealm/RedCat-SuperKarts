/*
 * FUN_00459d70 at 00459d70
 * undefined FUN_00459d70(void)
 * Address ranges: 00459d70-00459db3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00459d70(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  
  *param_1 = &PTR_FUN_004d2804;
  iVar2 = param_1[0xe];
  if (iVar2 != 0) {
    cVar1 = *(char *)(iVar2 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150((char *)(iVar2 + -1));
    }
    else {
      *(char *)(iVar2 + -1) = cVar1 + -1;
    }
  }
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  return;
}

