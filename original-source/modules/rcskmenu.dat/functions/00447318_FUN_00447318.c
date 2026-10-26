/*
 * FUN_00447318 at 00447318
 * int __register FUN_00447318(int param_1, char param_2)
 * Address ranges: 00447318-004473be
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00447318(int param_1,char param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  
  if ((param_1 == *(int *)(*(int *)(param_1 + 0x1c) + 100)) ||
     (((iVar3 = *(int *)(*(int *)(param_1 + 0x1c) + 100), iVar2 = param_1,
       iVar3 == *(int *)(param_1 + 0x14) && (*(int *)(param_1 + 4) != 0)) &&
      (iVar3 = FUN_00447208(iVar3), iVar3 == 1)))) {
    piVar1 = *(int **)(*(int *)(param_1 + 0x1c) + 0x14);
    (**(code **)(*piVar1 + 0x40))(piVar1,&iStack_1c);
    piVar1 = *(int **)(*(int *)(param_1 + 0x1c) + 0x14);
    (**(code **)(*piVar1 + 0x84))(piVar1,&iStack_1c);
    if (param_2 == '\x01') {
      iStack_10 = iStack_10 - iStack_18;
    }
    else {
      iStack_10 = iStack_14 - iStack_1c;
    }
  }
  else {
    do {
      iVar3 = iVar2;
      if (iVar3 == *(int *)(*(int *)(param_1 + 0x1c) + 100)) {
        iVar3 = *(int *)(*(int *)(param_1 + 0x1c) + 100);
        if (param_2 == *(char *)(iVar3 + 0x10)) {
          return *(int *)(*(int *)(param_1 + 0x1c) + 0x68);
        }
        return *(int *)(iVar3 + 0x20);
      }
      iVar2 = *(int *)(iVar3 + 0x14);
    } while (param_2 != *(char *)(*(int *)(iVar3 + 0x14) + 0x10));
    iStack_10 = FUN_0044721c(iVar3);
    iStack_10 = *(int *)(iVar3 + 0x20) - iStack_10;
  }
  return iStack_10;
}

