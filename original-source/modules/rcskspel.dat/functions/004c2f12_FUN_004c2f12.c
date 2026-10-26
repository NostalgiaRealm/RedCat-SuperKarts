/*
 * FUN_004c2f12 at 004c2f12
 * undefined FUN_004c2f12(void)
 * Address ranges: 004c2f12-004c2f6e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004c2f12(byte *param_1,byte *param_2,uint *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || (*(char *)(iVar1 + 8) == '\0')) {
LAB_004c2f69:
    uVar2 = 1;
  }
  else {
    if (iVar1 == *(int *)(param_2 + 4)) {
LAB_004c2f43:
      if (((((*param_2 & 2) == 0) || ((*param_1 & 8) != 0)) &&
          (((*param_3 & 1) == 0 || ((*param_1 & 1) != 0)))) &&
         (((*param_3 & 2) == 0 || ((*param_1 & 2) != 0)))) goto LAB_004c2f69;
    }
    else {
      iVar1 = _strcmp((char *)(iVar1 + 8),(char *)(*(int *)(param_2 + 4) + 8));
      if (iVar1 == 0) goto LAB_004c2f43;
    }
    uVar2 = 0;
  }
  return uVar2;
}

