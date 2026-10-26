/*
 * FUN_004746d0 at 004746d0
 * undefined FUN_004746d0(void)
 * Address ranges: 004746d0-00474752
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004746d0(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  
  *param_1 = &PTR_FUN_004d2e44;
  if (param_1[10] != 0) {
    FUN_004bc150(param_1[10]);
  }
  iVar2 = param_1[7];
  if (iVar2 != 0) {
    cVar1 = *(char *)(iVar2 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150((char *)(iVar2 + -1));
    }
    else {
      *(char *)(iVar2 + -1) = cVar1 + -1;
    }
  }
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  iVar2 = param_1[3];
  if (iVar2 != 0) {
    cVar1 = *(char *)(iVar2 + -1);
    if ((cVar1 != '\0') && (cVar1 != -1)) {
      *(char *)(iVar2 + -1) = cVar1 + -1;
      param_1[3] = 0;
      param_1[4] = 0;
      param_1[5] = 0;
      return;
    }
    FUN_004bc150((char *)(iVar2 + -1));
  }
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  return;
}

