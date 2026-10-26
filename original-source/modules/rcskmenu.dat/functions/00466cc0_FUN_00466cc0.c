/*
 * FUN_00466cc0 at 00466cc0
 * int __register FUN_00466cc0(int param_1)
 * Address ranges: 00466cc0-00466d0c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00466cc0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  if (*(char *)(param_1 + 0x1f9) == '\0') {
    iVar3 = -1;
  }
  else {
    iVar1 = FUN_00466ca4(param_1);
    if (-1 < iVar1 + -1) {
      iVar4 = 0;
      do {
        iVar2 = FUN_0040f6b0(*(undefined4 **)(*(int *)(param_1 + 500) + 0x240),iVar4);
        if (*(char *)(iVar2 + 0x1f9) != '\0') {
          iVar3 = iVar3 + 1;
        }
        iVar4 = iVar4 + 1;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
  }
  return iVar3;
}

