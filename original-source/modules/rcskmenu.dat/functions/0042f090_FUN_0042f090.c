/*
 * FUN_0042f090 at 0042f090
 * undefined FUN_0042f090(void)
 * Address ranges: 0042f090-0042f0f6
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042f090(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if (((*(byte *)(param_1 + 8) & 0x10) == 0) && ((char)param_1[0x5a] != '\0')) {
    (**(code **)(*param_1 + 0x70))();
    if (param_1[0x8c] != 0) {
      iVar1 = FUN_00438084(*(int *)(param_1[0x8c] + 0x28));
      if (-1 < iVar1 + -1) {
        iVar3 = 0;
        do {
          piVar2 = (int *)FUN_00438094(*(int *)(param_1[0x8c] + 0x28),iVar3);
          if (*(char *)((int)piVar2 + 0x32) != '\0') {
            (**(code **)(*piVar2 + 0x3c))();
          }
          iVar3 = iVar3 + 1;
          iVar1 = iVar1 + -1;
        } while (iVar1 != 0);
      }
    }
    FUN_0042f020((int)param_1);
  }
  return;
}

