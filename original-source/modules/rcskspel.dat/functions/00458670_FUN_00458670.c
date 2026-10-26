/*
 * FUN_00458670 at 00458670
 * undefined FUN_00458670(void)
 * Address ranges: 00458670-00458754
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_00458670(undefined4 *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_004cdf15;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *param_1 = &PTR_FUN_004d2834;
  local_4 = 1;
  iVar3 = (**(code **)param_1[0x1d])();
  iVar4 = 0;
  if (0 < iVar3) {
    do {
      piVar2 = *(int **)(*(int *)(param_1[0x1e] + 4) + iVar4 * 4);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 4))(1);
      }
      iVar4 = iVar4 + 1;
      *(undefined4 *)(*(int *)(param_1[0x1e] + 4) + -4 + iVar4 * 4) = 0;
    } while (iVar4 < iVar3);
  }
  iVar3 = param_1[0x1e];
  param_1[0x1d] = &PTR_FUN_004d2878;
  if (iVar3 != 0) {
    FUN_004bc150(*(undefined4 *)(iVar3 + 4));
    *(undefined4 *)(iVar3 + 4) = 0;
    *(undefined4 *)(iVar3 + 8) = 0;
    *(undefined4 *)(iVar3 + 0xc) = 0;
    FUN_004bc150(iVar3);
  }
  param_1[0x1e] = 0;
  *param_1 = &PTR_FUN_004d2804;
  iVar3 = param_1[0xe];
  if (iVar3 != 0) {
    cVar1 = *(char *)(iVar3 + -1);
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150((char *)(iVar3 + -1));
    }
    else {
      *(char *)(iVar3 + -1) = cVar1 + -1;
    }
  }
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  ExceptionList = pvStack_c;
  return;
}

