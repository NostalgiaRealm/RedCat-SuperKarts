/*
 * FUN_004b4130 at 004b4130
 * undefined FUN_004b4130(void)
 * Address ranges: 004b4130-004b41aa
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b4130(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (DAT_006ab7b4 != 0) {
    FUN_004b40e0();
    iVar4 = 0;
    if (0 < DAT_006ab78c) {
      iVar3 = 0;
      iVar2 = DAT_006ab798;
      do {
        if (*(int *)(iVar3 + 0x30 + iVar2) != 0) {
          if (*(int *)(iVar3 + 0x34 + iVar2) == 1) {
            piVar1 = *(int **)(iVar3 + 0x2c + iVar2);
            (**(code **)(*piVar1 + 8))(piVar1);
            iVar2 = DAT_006ab798;
          }
          piVar1 = *(int **)(iVar3 + 0x28 + iVar2);
          (**(code **)(*piVar1 + 8))(piVar1);
          *(undefined4 *)(iVar3 + 0x30 + DAT_006ab798) = 0;
          *(undefined4 *)(iVar3 + 0x38 + DAT_006ab798) = 0;
          iVar2 = DAT_006ab798;
        }
        iVar4 = iVar4 + 1;
        iVar3 = iVar3 + 0x44;
      } while (iVar4 < DAT_006ab78c);
    }
    return 0;
  }
  return 0;
}

