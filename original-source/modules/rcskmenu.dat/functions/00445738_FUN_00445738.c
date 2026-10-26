/*
 * FUN_00445738 at 00445738
 * undefined FUN_00445738(void)
 * Address ranges: 00445738-004457ca
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00445738(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_0040ebe8(0x7fffffff,0x7fffffff,0,param_2,0);
  iVar1 = FUN_0044268c(param_1);
  if (-1 < iVar1 + -1) {
    iVar3 = 0;
    do {
      iVar2 = FUN_00442650(param_1,iVar3);
      if ((*(char *)(iVar2 + 0x47) != '\0') ||
         (((*(byte *)(iVar2 + 0x20) & 0x10) != 0 && ((*(byte *)(iVar2 + 0x41) & 4) == 0)))) {
        if (*(int *)(iVar2 + 0x30) < *param_2) {
          *param_2 = *(int *)(iVar2 + 0x30);
        }
        if (*(int *)(iVar2 + 0x34) < param_2[1]) {
          param_2[1] = *(int *)(iVar2 + 0x34);
        }
        if (param_2[2] < *(int *)(iVar2 + 0x30) + *(int *)(iVar2 + 0x38)) {
          param_2[2] = *(int *)(iVar2 + 0x30) + *(int *)(iVar2 + 0x38);
        }
        if (param_2[3] < *(int *)(iVar2 + 0x34) + *(int *)(iVar2 + 0x3c)) {
          param_2[3] = *(int *)(iVar2 + 0x34) + *(int *)(iVar2 + 0x3c);
        }
      }
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}

