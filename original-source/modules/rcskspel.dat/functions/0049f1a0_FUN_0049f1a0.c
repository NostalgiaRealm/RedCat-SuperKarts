/*
 * FUN_0049f1a0 at 0049f1a0
 * undefined FUN_0049f1a0(void)
 * Address ranges: 0049f1a0-0049f212
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0049f1a0(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  
  *param_1 = &PTR_FUN_004d3078;
  iVar2 = param_1[0xb];
  if (iVar2 != 0) {
    cVar1 = *(char *)(iVar2 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150((char *)(iVar2 + -1));
    }
    else {
      *(char *)(iVar2 + -1) = cVar1 + -1;
    }
  }
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  iVar2 = param_1[7];
  if (iVar2 != 0) {
    cVar1 = *(char *)(iVar2 + -1);
    if ((cVar1 != '\0') && (cVar1 != -1)) {
      *(char *)(iVar2 + -1) = cVar1 + -1;
      param_1[7] = 0;
      param_1[8] = 0;
      param_1[9] = 0;
      return;
    }
    FUN_004bc150((char *)(iVar2 + -1));
  }
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  return;
}

