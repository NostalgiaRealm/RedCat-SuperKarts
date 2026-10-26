/*
 * FUN_00447d64 at 00447d64
 * undefined __register FUN_00447d64(int param_1, int param_2, int param_3, char param_4)
 * Address ranges: 00447d64-00447dd0
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00447d64(int param_1,int param_2,int param_3,char param_4)

{
  int iVar1;
  
  if ((param_3 == 0) &&
     (param_3 = *(int *)(*(int *)(param_1 + 100) + 8), iVar1 = param_3, param_4 != '\0')) {
    do {
      param_3 = iVar1;
      iVar1 = *(int *)(param_3 + 0xc);
    } while (*(int *)(param_3 + 0xc) != 0);
  }
  if (param_4 == '\0') {
    *(int *)(param_2 + 0xc) = param_3;
    iVar1 = *(int *)(param_3 + 0x18);
    *(int *)(param_2 + 0x18) = iVar1;
    if (iVar1 != 0) {
      *(int *)(iVar1 + 0xc) = param_2;
    }
    *(int *)(param_3 + 0x18) = param_2;
    iVar1 = *(int *)(param_3 + 0x14);
    *(int *)(param_2 + 0x14) = iVar1;
    if (param_3 == *(int *)(iVar1 + 8)) {
      *(int *)(iVar1 + 8) = param_2;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(param_3 + 0x14);
    *(int *)(param_2 + 0x18) = param_3;
    iVar1 = *(int *)(param_3 + 0xc);
    *(int *)(param_2 + 0xc) = iVar1;
    if (iVar1 != 0) {
      *(int *)(iVar1 + 0x18) = param_2;
    }
    *(int *)(param_3 + 0xc) = param_2;
  }
  FUN_004473c0(*(int *)(param_3 + 0x14));
  return;
}

